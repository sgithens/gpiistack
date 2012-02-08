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


Handle<Value> setHighContrast(const Arguments& args) {
  HandleScope scope;

  if (args.Length() != 1) {
    ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
    return scope.Close(Undefined());
  }

  if (!args[0]->IsBoolean()) {
    ThrowException(Exception::TypeError(String::New("Wrong argument type")));
    return scope.Close(Undefined());
  }

  GSettings *settings;
  settings = g_settings_new ("apps.gpiisettings");
  g_settings_set_boolean(settings, "highcontrast", args[0]->BooleanValue());
  return scope.Close(String::New("ok"));
}


void init(Handle<Object> target) {
  g_type_init(); // Initialize gobject system
  target->Set(String::NewSymbol("hello"),
      FunctionTemplate::New(Method)->GetFunction());
  target->Set(String::NewSymbol("setHighContrast"),
      FunctionTemplate::New(setHighContrast)->GetFunction());
}
NODE_MODULE(nodegsettings, init)

