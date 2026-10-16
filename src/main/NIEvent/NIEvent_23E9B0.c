/*
 * main/NIEvent: range (3 files, 0023E9B0-0023EA50)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "gobj_flag_slot16.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "nievent_v10.h"
#pragma pop

/* merge_units: begin func_0023E9B0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Call slot 16 unless the object is active. */
DEFINE_GOBJ_FLAG_SLOT16(NiEvent_PreLogic)
#pragma pop /* merge_units */
/* merge_units: end func_0023E9B0 */

/* merge_units: begin func_0023EA10 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Event virtual 10: call slot 66 while inactive. */
DEFINE_NIEVENT_V10(func_0023EA10)
#pragma pop /* merge_units */
/* merge_units: end func_0023EA10 */

/* merge_units: begin func_0023EA50 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Msg { void* vt; char pad04[0x20]; int i24; char pad28[8]; };
struct Obj {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59(); virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63(); virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67(); virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71(); virtual void v72(); virtual void v73(); virtual void v74();
    virtual void v75(float);
    char pad04[0x28];
    unsigned char f2C; unsigned char f2D; unsigned char f2E; char pad2F[0x31];
    int i60;
    char pad64[0x78];
    unsigned char bDC;
    char padDD[0x53];
    unsigned char b130;
    char pad131[3];
    float f134;
};
extern "C" {
extern char D_004F7C30[];
extern char D_004DBEB0[];
void Event_Construct(Msg*, void*);
void Event_Send(Msg*, void*, int);
void cMessage_dtor(Msg*, int);
void Actor_BaseLogicUpdate(Obj*, float);
}
/* Active flags: the && chain must materialise as a bool (sltu/xori), hence the inline. */
static inline bool Act(Obj* o) { return o->f2D && o->f2C && !o->f2E; }
extern "C" void func_0023EA50(Obj* o, float dt)
{
    unsigned char b = o->b130;
    if (b || (o->i60 == 3 && o->bDC && Act(o))) {
        float x = dt * o->f134; o->v75(b ? x : 0.0f);
        if (b && !o->b130) {
            Msg m;
            Event_Construct(&m, D_004F7C30);
            m.vt = D_004DBEB0;
            m.i24 = 0;
            Event_Send(&m, o, 0);
            m.vt = D_004DBEB0;
            cMessage_dtor(&m, 0);
        }
    }
    Actor_BaseLogicUpdate(o, dt);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0023EA50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0023EA50 */
