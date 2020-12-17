#include <napi.h>

long int fibSeries[2] = {1, 0};

Napi::Number getNextFib(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  long int nextFib = fibSeries[0] + fibSeries[1];

  fibSeries[0] = fibSeries[1];
  fibSeries[1] = nextFib;

  return Napi::Number::New(env, nextFib);
}

Napi::Object init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "getNextFib"), Napi::Function::New(env, getNextFib));
    
    return exports;
};

NODE_API_MODULE(hello_world, init);