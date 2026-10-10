/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

typedef union ScriptArg { int i; float f; void* p; } ScriptArg;

/* Virtual-call view of cNPC: only the slots used here are named (vtable offset in comments). */
struct cNPC {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F();
    virtual void Activate(); /* +0x48 */
};

/* Script native: cNPC::Activate() on args[0]; returns 0. */
extern "C" int Script_cNPC_Activate_2(ScriptArg* args)
{
    cNPC* obj = (cNPC*)args[0].p;
    obj->Activate();
    return 0;
}
