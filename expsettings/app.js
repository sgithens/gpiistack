
/**
 * Module dependencies.
 */

var express = require('express')
, routes = require('./routes');

var exec = require('child_process').exec;
var sys = require('sys');

var app = module.exports = express.createServer();

var nodegsettings = require('/home/sgithens/code/gpiistack/nodegsettings/build/Release/nodegsettings.node');

// Configuration

app.configure(function(){
  app.set('views', __dirname + '/views');
  app.set('view engine', 'jade');
  app.use(express.bodyParser());
  app.use(express.methodOverride());
  app.use(app.router);
  app.use(express.static(__dirname + '/public'));
});

app.configure('development', function(){
  app.use(express.errorHandler({ dumpExceptions: true, showStack: true })); 
});

app.configure('production', function(){
  app.use(express.errorHandler()); 
});

// Routes

app.get('/highcontrast', function(req,res) {
//  res.contentType('application/json');
    value = nodegsettings.hello();
    var togo = {
        highcontrast: value
    };
    res.send(togo);
});

app.post('/highcontrast/:val', function(req,res) {
    value = req.param("val","off");
    if (value === "on") {
        nodegsettings.setHighContrast(true);
    }
    else {
        nodegsettings.setHighContrast(false);
    }
});

app.put('/magsettings', function(req,res) {
    var data = "";
    req.addListener('data', function(chunk) {data+=chunk;});
    req.addListener('end', function() {
        var jsonData = JSON.parse(data);
        var magFactor = jsonData["Display"]["screen enhancement"]["magnification"];
        var child = exec('gsettings set org.gnome.desktop.a11y.magnifier mag-factor '+magFactor, function(error, stdout, stderr) {
            res.send('');
         });
        
    });
});

app.get('/', routes.index);

app.listen(3000);
console.log("Express server listening on port %d in %s mode", app.address().port, app.settings.env);
