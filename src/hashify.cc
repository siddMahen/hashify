#define BUILDING_NODE_EXTENSION
#include <node.h>

using namespace v8;

Handle<Value> hashify(const Arguments& args) {
  HandleScope scope;

  if(args.Length() < 1 || !args[0]->IsObject()){
    ThrowException(Exception::TypeError(String::New("Invalid arguments")));
    return scope.Close(Undefined());
  }

  Local<Object> obj = Local<Object>::Cast(args[0]);
  Local<Number> num = Number::New(obj->GetIdentityHash());

  return scope.Close(num);
}

void init(Handle<Object> target) {
  target->Set(String::NewSymbol("hashify"),
      FunctionTemplate::New(hashify)->GetFunction());
}

NODE_MODULE(hashify, init)
