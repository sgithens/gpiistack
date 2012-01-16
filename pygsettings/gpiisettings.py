from gi.repository import Gio, Gtk

class App(object):
    BASE_KEY = "apps.gpiisettings"
    def __init__(self):
        # setup a check button and associate it with a GSettings key
        settings = Gio.Settings.new(self.BASE_KEY)
        check_button = Gtk.CheckButton("Use High Contrast Display Settings")
        check_button.set_active(settings.get_boolean("highcontrast"))
        settings.connect("changed::highcontrast", self.on_my_setting_changed, check_button)
        check_button.connect('toggled', self.on_check_button_toggled, settings)
        
        # main window
        window = Gtk.Window(type=Gtk.WindowType.TOPLEVEL)
        window.set_title('GPII gsettings prototyping')
        window.set_border_width(24)
        window.connect_after('destroy', self.on_window_destroy)
        window.add(check_button)
        window.show_all()
        Gtk.main()
    
    def on_my_setting_changed(self, settings, key, check_button):
        check_button.set_active(settings.get_boolean("highcontrast"))
        
    def on_check_button_toggled(self, button, settings):
        settings.set_boolean("highcontrast", button.get_active())
                                  
    def on_window_destroy(self, widget, data=None):
        Gtk.main_quit()

if __name__ == "__main__":
    app = App()
