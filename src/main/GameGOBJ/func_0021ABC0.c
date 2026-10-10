/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

/* Virtual-call view of Path: only the slots used here are named (vtable offset in comments). */
struct Path {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void Method60(); /* +0x60 */
};

typedef struct cPathedGOBJ { char pad[0x64]; Path* path; /* +0x64 */ } cPathedGOBJ;

extern char D_004F77C0[];
extern "C" void func_003CE790(cPathedGOBJ* self, void* arg);
extern "C" void func_0022C720(void* list, cPathedGOBJ* obj);

/* Notifies the path (virtual +0x60), runs the base handler, then func_0022C720(D_004F77C0, self). */
extern "C" void func_0021ABC0(cPathedGOBJ* self, void* arg)
{
    if (self->path)
        self->path->Method60();
    func_003CE790(self, arg);
    func_0022C720(D_004F77C0, self);
}
