#include "types.h"
#pragma cplusplus on
class E7Obj {
public:
    virtual void v0();
    virtual void v1();
    virtual int* Get();
};
struct E7S3 { int a; };
struct E7S2 { E7S3* p; };
struct E7S1 { E7S3* p; };
struct E7Node { char pad[0x10]; E7S1* info; };
extern "C" {
extern int cScriptBase_getClass(int x);
extern int cScriptInterpreter_UseIdInsteadOfPointer(void* ctx, E7Node* n, int t);
extern void cScriptInterpreter_callFunction(void* ctx, E7Node* n, int* args, int count);
void cScriptInterpreter_callEvent_FuncDefP_cSystemP_cMessageP(void* ctx_, E7Node* n_, E7Obj* obj_, int val_) {
    E7Obj* obj = obj_;
    int val = val_;
    void* ctx = ctx_;
    E7Node* n = n_;
    int args[2];
    if (cScriptInterpreter_UseIdInsteadOfPointer(ctx, n, cScriptBase_getClass(n->info->p->a))) {
        args[0] = *obj->Get();
    } else {
        args[0] = (int)obj;
    }
    args[1] = val;
    cScriptInterpreter_callFunction(ctx, n, args, 2);
}
}

