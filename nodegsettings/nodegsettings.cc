#include <node.h>
#include <v8.h>

#include <config.h>
#include <gio/gio.h>

using namespace v8;

Handle<Value> Method(const Arguments& args) {
  HandleScope scope;
  GSettings *settings;
  settings = g_settings_new ("apps.gpiisettings");
  gboolean hc_status = g_settings_get_boolean(settings,"highcontrast");
  gchar *status;
  if (hc_status) { 
    status = "true";
  }
  else {
    status = "false";
  }

  return scope.Close(String::New(status));
}

Handle<Value> setHighContrastOn(const Arguments& args) {
  HandleScope scope;
  GSettings *settings;
  settings = g_settings_new ("apps.gpiisettings");
  g_settings_set_boolean(settings, "highcontrast", TRUE);
  return scope.Close(String::New("ok"));
}

Handle<Value> setHighContrastOff(const Arguments& args) {
  HandleScope scope;
  GSettings *settings;
  settings = g_settings_new ("apps.gpiisettings");
  g_settings_set_boolean(settings, "highcontrast", FALSE);
  return scope.Close(String::New("ok"));
}


void init(Handle<Object> target) {
  g_type_init(); // Initialize gobject system
  target->Set(String::NewSymbol("hello"),
      FunctionTemplate::New(Method)->GetFunction());
  target->Set(String::NewSymbol("setHighContrastOn"),
      FunctionTemplate::New(setHighContrastOn)->GetFunction());
  target->Set(String::NewSymbol("setHighContrastOff"),
      FunctionTemplate::New(setHighContrastOff)->GetFunction());
}
NODE_MODULE(nodegsettings, init)

