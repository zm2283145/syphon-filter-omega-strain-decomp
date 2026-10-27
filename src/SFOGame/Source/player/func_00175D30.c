/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

typedef union ScriptArg { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg;

/* Virtual-call view of cPlayer: only the slots used here are named (vtable offset in comments). */
struct cPlayer {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual int Team(); /* +0x68 */
};

/* Script native: returns cPlayer::Team() of args[0]. */
extern "C" int Script_cPlayer_Team(ScriptArg* args)
{
    cPlayer* obj = (cPlayer*)args[0].p;
    volatile int result = obj->Team(); /* returned through a stack temporary */
    return result;
}
