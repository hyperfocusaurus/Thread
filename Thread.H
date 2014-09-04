#ifndef THREAD_H
#define THREAD_H

#include <uv.h>

class Thread {
public:
    Thread(const FunctionCallbackInfo<Value>& args);
    ~Thread();
private:

}

#endif // THREAD_H