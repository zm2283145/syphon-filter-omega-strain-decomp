/*
 * SFOGame/Source/tank: 4 files, 002863E0-00286570
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002863E0 */
#pragma push /* merge_units */
#include "types.h"
#include "vslot_pad.h"
#include "net_local_id.h"

#pragma cplusplus on
#pragma inline_depth(10)
extern "C" {}
struct Obj_63E0 {
    VPAD16(a) VPAD4(b) VPAD1(c)
    virtual void activate(int on);
    char pad4[8]; int idC; int id10; unsigned char b14; char pad15[0x4B]; int f60; int f64; int f68; int f6C; unsigned char b70; char pad71[3]; int f74;
};
extern "C" {
extern char g_TargetVisMgr[];
void cTargetManager_AddGobj(void* list);
void nGobjManager_AddGOBJ(Obj_63E0* o);
int cNetObj_AddSystem(int id, int owner, Obj_63E0* o);
}
static inline int NetHostOk_63E0(void) { return g_IsMultiplayer ? D_005721C0 : 1; }
extern "C" void cTank_init(Obj_63E0* o, int arg1)
{
    o->f60 = arg1;
    o->f6C = 0;
    o->f68 = 0;
    o->f64 = 0;
    o->b70 = 1;
    cTargetManager_AddGobj(g_TargetVisMgr);
    nGobjManager_AddGOBJ(o);
    o->activate(1);
    o->f74 = 0;
    if (g_IsMultiplayer) {
        o->id10 = o->idC;
        if (!NetHostOk_63E0()) o->b14 = 0;
        {
            int t = o->id10;
            cNetObj_AddSystem(t, NetObjId(), o);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002863E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002863E0 */

/* merge_units: begin func_00286520 */
#pragma push /* merge_units */
void cTurret_SetEnemy(int a0, int a1) {
    int loc[1];
    int v1;
    int cond;

    cond = a1 == 0;
    *(int*)((char*)a0 + 92) = a1;
    if (cond) goto L00286538;
    v1 = a1 + 12;
    goto L00286548;
L00286538:;
    v1 = 0 + -1;
    *(int*)(char*)loc = v1;
    v1 = (int)loc;
L00286548:;
    v1 = *(int*)(char*)v1;
    *(int*)((char*)a0 + 96) = v1;
    goto ret;
ret:;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00286520(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00286520 */

/* merge_units: begin func_00286560 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cTank script class: script natives, type registration and turret helpers.
 */

#include "tank_types.h"

void cTurret_Reset(cTankTurret* self) {
    self->unk64 = 0;
}
static inline void merge_flush_func_00286560(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00286560 */

/* merge_units: begin func_00286570 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma exceptions off
extern "C" {
typedef struct { char pad[0xC]; int id; } Target_286570;
typedef struct { char pad[0xA4]; float f; } Aux_286570;
typedef struct {
    char pad0[0x10];
    float cooldown;
    char pad14[0x40];
    unsigned char busy;
    char pad55[7];
    Target_286570* target;
    int targetId;
    char pad64[4];
    Aux_286570* aux;
} Turret_286570;
extern unsigned char D_005721C0;
extern unsigned char g_IsMultiplayer;
extern unsigned char cTurret_Aim(Turret_286570* t, float dt);
extern void cTurret_Fire(Turret_286570* t, Target_286570* tgt, unsigned char valid, unsigned char r);
}
struct Obj_286570 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54();
    virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64();
    virtual void v65(); virtual void v66(); virtual void v67();
    virtual int Set(int on);
};
struct Own_286570 { Obj_286570* obj; };
static inline bool Null_286570(void* p) { return !p; }
static inline int Flag_286570(void) { return g_IsMultiplayer ? D_005721C0 : 1; }

extern "C" int cTurret_Stop(Own_286570* self)
{
    return self->obj->Set(1);
}

extern "C" void cTurret_NextFrame(Turret_286570* t, float dt)
{
    Target_286570* tgt;
    unsigned char r;
    unsigned char valid;
    if (!(t->cooldown <= 0.0f)) t->cooldown -= dt;
    r = cTurret_Aim(t, dt);
    tgt = t->target;
    valid = 1;
    if (!Null_286570(tgt) && tgt->id != t->targetId) valid = 0;
    tgt = valid ? tgt : 0;
    if (tgt && !t->busy && r && t->cooldown <= 0.0f) {
        if (!g_IsMultiplayer || Flag_286570() || !(t->aux->f <= 1.0f))
            cTurret_Fire(t, tgt, valid, r);
    }
}
static inline void merge_flush_func_00286570(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00286570 */
