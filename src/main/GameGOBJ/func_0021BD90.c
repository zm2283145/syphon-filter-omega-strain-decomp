/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

struct Target;

/* Virtual-call view of Target: only the slots used here are named (vtable offset in comments). */
struct Target {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B();
    virtual int MethodB8(); /* +0xB8 */
};

/* Owner of a target object, called only while enabled. */
typedef struct Holder {
    char pad[0x60];
    unsigned char enabled; /* +0x60 */
    char pad61[3];
    Target* target; /* +0x64 */
} Holder;

/* Returns the target's virtual +0xB8 result while enabled, else 0. */
extern "C" int func_0021BD90(Holder* self)
{
    if (!self->enabled)
        return 0;
    return self->target->MethodB8();
}
