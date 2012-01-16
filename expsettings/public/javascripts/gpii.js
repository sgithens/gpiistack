$(document).ready(function() {
    $("#highcontrast").change(function(e) {
        alert($(this).attr('checked'));
    });
});