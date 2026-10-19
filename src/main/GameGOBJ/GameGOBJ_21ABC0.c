/*
 * main/GameGOBJ: range (2 files, 0021ABC0-0021AC20)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0021ABC0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

/* Virtual-call view of Path: only the slots used here are named (vtable offset in comments). */
struct Path {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void Method60(); /* +0x60 */
};

typedef struct cPathedGOBJ { char pad[0x64]; Path* path; /* +0x64 */ } cPathedGOBJ;

extern char g_TargetVisMgr[];
extern "C" void Object_Deactivate(cPathedGOBJ* self, void* arg);
extern "C" void TargetVis_Unregister(void* list, cPathedGOBJ* obj);

/* Notifies the path (virtual +0x60), runs the base handler, then TargetVis_Unregister(g_TargetVisMgr, self). */
extern "C" void cGameGOBJ_v16(cPathedGOBJ* self, void* arg)
{
    if (self->path)
        self->path->Method60();
    Object_Deactivate(self, arg);
    TargetVis_Unregister(g_TargetVisMgr, self);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021ABC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0021ABC0 */

/* merge_units: begin func_0021AC20 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

struct Door {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void Method5C(); /* +0x5C */
};

struct cGameGOBJ {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E();
    virtual void MethodC4(); /* +0xC4 */
    char pad04[0x64 - 4];
    Door* door; /* +0x64 */
};

extern "C" void Object_Activate(cGameGOBJ* self, void* arg);

/* Notifies the door object (+0x64, virtual +0x5C), runs Object_Activate and virtual +0xC4. */
extern "C" void cGameGOBJ_v15(cGameGOBJ* self, void* arg)
{
    if (self->door)
    self->door->Method5C();
    Object_Activate(self, arg);
    self->MethodC4();
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021AC20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0021AC20 */
