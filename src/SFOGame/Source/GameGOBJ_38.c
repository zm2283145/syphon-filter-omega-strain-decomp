/*
 * SFOGame/Source/GameGOBJ: 5 files, 0021AA20-0021ABC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0021AA20 */
#pragma push /* merge_units */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "gobj_v07_register.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "gobj_v06_update.h"
#pragma pop

#pragma cplusplus on
typedef struct { void* vtbl; char pad04[0x18]; int size; char pad20[4]; int id; char pad28[8]; } C1Msg_21A9;
class C1Ch_21A9 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void Reset(int arg);
};
typedef struct { char p0[0x10]; int target; char p14[0x2C - 0x14]; unsigned char flag; char p2d[0x78 - 0x2D]; int n; C1Ch_21A9** ch; } C1Obj_21A9;
extern "C" unsigned char g_IsMultiplayer;
extern "C" char g_cEnableMsgClass[];
extern "C" char D_004E0880[];
extern "C" void cMessage_ctor_cMessageNameR(C1Msg_21A9* m, void* type);
extern "C" void cEnableMsg_SendEnabled(C1Msg_21A9* m, int target);
extern "C" void cMessage_dtor(C1Msg_21A9* m, int flags);
#pragma opt_strength_reduction off
extern "C" void cGameGOBJ_Enable(C1Obj_21A9* o)
{
    int i;
    if (g_IsMultiplayer) {
        C1Msg_21A9 msg;
        cMessage_ctor_cMessageNameR(&msg, g_cEnableMsgClass);
        msg.vtbl = D_004E0880;
        msg.id = -1;
        msg.size = 0x40;
        cEnableMsg_SendEnabled(&msg, o->target);
        msg.vtbl = D_004E0880;
        cMessage_dtor(&msg, 0);
    }
    o->flag = 1;
    for (i = 0; i < o->n; i++)
        o->ch[i]->Reset(-1);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021AA20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0021AA20 */

/* merge_units: begin func_0021AB00 */
#pragma push /* merge_units */
#pragma cplusplus on

/* GOBJ virtual 7: notify attached object, update, register. */
DEFINE_GOBJ_V07_REGISTER(cGameGOBJ_NetDeactivate)
static inline void merge_flush_func_0021AB00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021AB00 */

/* merge_units: begin func_0021AB60 */
#pragma push /* merge_units */
#pragma cplusplus on

/* GOBJ virtual 6: notify attached object, update, call slot 47. */
DEFINE_GOBJ_V06_UPDATE(cGameGOBJ_NetActivate)
static inline void merge_flush_func_0021AB60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0021AB60 */

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
extern "C" void cGOBJ_Deactivate(cPathedGOBJ* self, void* arg);
#if 0 /* merge_units */
extern "C" void cTargetManager_RemoveGobj(void* list, cPathedGOBJ* obj);
#endif /* merge_units */
#define cTargetManager_RemoveGobj(a0, a1) (cTargetManager_RemoveGobj((a0), (GobjV07 *)(a1))) /* merge_units */


/* Notifies the path (virtual +0x60), runs the base handler, then cTargetManager_RemoveGobj(g_TargetVisMgr, self). */
extern "C" void cGameGOBJ_Deactivate(cPathedGOBJ* self, void* arg)
{
    if (self->path)
        self->path->Method60();
    cGOBJ_Deactivate(self, arg);
    cTargetManager_RemoveGobj(g_TargetVisMgr, self);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021ABC0(void) {}
#undef cTargetManager_RemoveGobj /* merge_units */
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

extern "C" void cGOBJ_Activate(cGameGOBJ* self, void* arg);

/* Notifies the door object (+0x64, virtual +0x5C), runs cGOBJ_Activate and virtual +0xC4. */
extern "C" void cGameGOBJ_Activate(cGameGOBJ* self, void* arg)
{
    if (self->door)
    self->door->Method5C();
    cGOBJ_Activate(self, arg);
    self->MethodC4();
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021AC20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0021AC20 */
