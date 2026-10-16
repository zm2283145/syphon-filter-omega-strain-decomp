/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

typedef union ScriptArg { int i; float f; void* p; unsigned char b; signed char c; } ScriptArg;

/* Virtual-call view of cPARTICLE_GOBJ: only the slots used here are named (vtable offset in comments). */
struct cPARTICLE_GOBJ {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20();
    virtual void ScaleBBox(float value); /* +0x8C */
};

/* Script native: cPARTICLE_GOBJ::ScaleBBox((float)args[1]); the argument goes through a stack temporary. Returns 0. */
extern "C" int Script_cPARTICLE_GOBJ_ScaleBBox(ScriptArg* args)
{
    int part[1];
    cPARTICLE_GOBJ* obj;
    part[0] = args[1].i;
    obj = (cPARTICLE_GOBJ*)args[0].p;
    obj->ScaleBBox(*(float*)part);
    return 0;
}
