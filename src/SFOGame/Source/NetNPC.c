/*
 * SFOGame/Source/NetNPC: 3 files, 002D2C20-002D2CA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002D2C20 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

int func_002D2C20(Controller2D* self) {
    return self->unk210;
}

void func_002D2C30(void) {
}

void func_002D2C40(void) {
}

void cNetNPC_SetViewConeRadius(void) {
}

void cNetNPC_SetViewConeAngle(void) {
}

void cNetNPC_DropWeapon(void) {
}

int cNetNPC_GetDarkness(Controller2D* self) {
    return self->owner->unk44;
}
static inline void merge_flush_func_002D2C20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D2C20 */

/* merge_units: begin func_002D2C90 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#pragma exceptions off

struct VObj {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E(); virtual void v2F();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v3A(); virtual void v3B();
    virtual void v3C(); virtual void v3D(); virtual void v3E(); virtual void v3F(); virtual void v40(); virtual void v41();
    virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v4A(); virtual void v4B(); virtual void v4C(); virtual void v4D();
    virtual void v4E(); virtual void v4F(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53();
    virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v5A(); virtual void v5B(); virtual void v5C(); virtual void v5D(); virtual void v5E(); virtual void v5F();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65();
    virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v6A(); virtual void v6B();
    virtual void v6C(); virtual void v6D(); virtual void v6E(); virtual void v6F(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75(); virtual void v76();
    virtual void Method1E4(); /* +0x1E4 */
};

/* Forwards to the object's virtual method at vtable +0x1E4. */
extern "C" void cNetNPC_GetAimPercent(VObj* obj)
{
    obj->Method1E4();
}
static inline void merge_flush_func_002D2C90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D2C90 */

/* merge_units: begin func_002D2CA0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Bits2CA0 { unsigned char f0 : 1; };
struct Npc2CA0 { char pad[0x214]; Bits2CA0 bits; };
struct Ev2CA0 { void* vtable; char pad[0x20]; unsigned char b24; char pad2[3]; int i28; char pad3[4]; };
extern "C" {
extern char D_004EE550[];
extern char D_004D9340[];
void cNPC_Follow_cGOBJP_float_float(Npc2CA0* o);
void cMessage_ctor_cMessageNameR(Ev2CA0* e, void* type);
void cNPC_Follow_cMessageR(Npc2CA0* o, Ev2CA0* e);
void cMessage_dtor(void* self, int flags);
}
extern "C" void cNetNPC_NetFollow(Npc2CA0* o, bool on)
{
    if (on) {
        Ev2CA0 ev;
        cNPC_Follow_cGOBJP_float_float(o);
        cMessage_ctor_cMessageNameR(&ev, D_004EE550);
        ev.vtable = D_004D9340;
        ev.b24 = 0;
        ev.i28 = -1;
        cNPC_Follow_cMessageR(o, &ev);
        ev.vtable = D_004D9340;
        cMessage_dtor(&ev, 0);
        o->bits.f0 = 1;
    } else {
        o->bits.f0 = 0;
    }
}
static inline void merge_flush_func_002D2CA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D2CA0 */
