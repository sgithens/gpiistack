function checkSettings() {
    $.getJSON('/highcontrast', function(data) {
        if (data.highcontrast === "true") {
            $("#highcontrast").attr('checked',true);
        } 
        else {
            $("#highcontrast").removeAttr('checked');
        }
    });
    setTimeout("checkSettings()",250);
}

$(document).ready(function() {
    $("#highcontrast").click(function(e) {
        var hc_val = "off"; 
        if ($(this).attr('checked') === "checked") {
            hc_val = "on";
        }
        $.ajax({
            url: "/highcontrast/"+hc_val,
            type: "POST"
        });
    });

    checkSettings();

});