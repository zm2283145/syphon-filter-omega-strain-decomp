/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

struct Sub {
    virtual void v00(); virtual void v01(); virtual void v02();
    virtual void Method14(void* arg); /* +0x14 */
};

struct Object {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21();
    virtual void Method90(void* p, int n); /* +0x90 */
    char pad04[0x50 - 4];
    Sub* sub;   /* +0x50 */
    char pad54[0x64 - 0x54];
    int unk64;  /* +0x64 */
    int unk68;
    int unk6C;  /* +0x6C */
};

/* Calls virtual +0x90(arg+0x10, 0), passes arg to the +0x50 object (virtual +0x14) and clears +0x64/+0x6C. */
extern "C" void func_00394740(Object* self, char* arg)
{
    self->Method90(arg + 0x10, 0);
    self->sub->Method14(arg);
    self->unk64 = 0;
    self->unk6C = 0;
}
