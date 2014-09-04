#include <node.h>
#include <v8.h>
#include <thread>
#include <iostream>

#define PRINT_DONE (std::cout << "done" << std::endl)

using namespace v8;

Handle<Value> ThreadStart(const Arguments* args) {
    std::cout << "Calling function in second thread...";
    HandleScope scope;

    Local<Function> cb = Local<Function>::Cast((*args)[0]);
    const unsigned argc = 0;
    cb->Call(Context::GetCurrent()->Global(), argc, new Local<Value>());
    std::cout << "Callback returned" << std::endl;

    return scope.Close(Undefined());
}

Handle<Value> RunCallback(const Arguments& args) {
    std::cout << "Creating thread...";
    std::thread thread(ThreadStart, &args);
    thread.join();
    PRINT_DONE;
    return Handle<Value>();
}

void Init(Handle<Object> exports, Handle<Object> module) {
    std::cout << "Exporting callback...";
    module->Set(String::NewSymbol("exports"),
      FunctionTemplate::New(RunCallback)->GetFunction());
    PRINT_DONE;
}

NODE_MODULE(Thread, Init);