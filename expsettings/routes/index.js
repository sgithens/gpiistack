
/*
 * GET home page.
 */

var nodegsettings = require('/home/sgithens/code/gpiistack/nodegsettings/build/Release/nodegsettings.node');

exports.index = function(req, res){

    res.render('index', { title: "GPII Settings" })
};