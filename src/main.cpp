#include <node.h>
#include <v8.h>
#include <iostream>
#include "fsspace.h"

using namespace std;
using namespace v8;
using namespace fsspace;

Handle<Value> status(const Arguments& args) {
    HandleScope scope;
    if (args.Length() < 2) {
        ThrowException(Exception::TypeError(String::New("Usage:  status(<directory>, <callback>);")));
        return scope.Close(Undefined());
    }

    if (!args[0]->IsString()) {
        ThrowException(Exception::TypeError(String::New("Usage status(<directory>, <callback>)")));
        return scope.Close(Undefined());
    }
    Local<Function> cb = Local<Function>::Cast(args[1]);

    // Get the V8 param and convert it to a string.
    String::Utf8Value param1(args[0]->ToString());
    string dir = string(*param1);
    string err;
    long bytesTotal, bytesAvail, bytesUsed;
    float pctUsed;

    FileSystemSpace fsspace;
    if (fsspace.status(dir, err, bytesTotal, bytesAvail, bytesUsed, pctUsed))
    {
        const unsigned argc = 5;
        Local<Value> argv[argc] = { 
            Local<Value>::New(String::New(err.c_str())),
            Local<Value>::New(Number::New(bytesTotal)),
            Local<Value>::New(Number::New(bytesAvail)),
            Local<Value>::New(Number::New(bytesUsed)),
            Local<Value>::New(Number::New(pctUsed))
        }; 

        cb->Call(Context::GetCurrent()->Global(), argc, argv);

    }
    else // fsspace.status() Error
    {
        const unsigned argc = 1;
        Local<Value> argv[argc] = { Local<Value>::New(String::New(err.c_str()))};
        cb->Call(Context::GetCurrent()->Global(), argc, argv);
    }

    return scope.Close(Undefined());
}

void init(Handle<Object> exports) {

    // Export methods and properties 
    exports->Set(String::NewSymbol("status"), FunctionTemplate::New(status)->GetFunction());
}

NODE_MODULE(fsspace, init)
