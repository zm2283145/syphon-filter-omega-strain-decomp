/*
 * main/playerControls: range (4 files, 00247320-00247720)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();

/* merge_units: begin func_00247320 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
typedef struct { char pad[0x128]; void* buf; } E4Own;
extern "C" {
void cPickupMenu_dtor(void* p, int n);
}
extern "C" void cPlayerControls_KillPickup(E4Own* o)
{
    void* p = o->buf;
    if (p) {
        {
            AllocGuard g;
            cPickupMenu_dtor(p, -1);
            cMemMan_Deallocate(0, p, "playerControls.cc", 0xF29);
        }
        o->buf = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00247320(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00247320 */

/* merge_units: begin func_002473E0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct C5Zone { int id; };
struct C5Obj2473 { char pad[0x128]; C5Zone* zone; };
extern "C" bool PlayerInput_IsPickupMenuForZone(C5Obj2473* p, int id) { return p->zone != 0 && id == p->zone->id; }
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002473E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002473E0 */

/* merge_units: begin func_00247410 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
struct E247720 { unsigned char used; char p1[3]; int v; };
struct V247720 { int pad; int count; E247720* data; };
extern "C" void cHumanMotionParams_cTargetZRotationStack_Remove_ByIndex_And_CleanUp(V247720* v, int idx); /* gsynth: defined below */
#pragma pop
#pragma cplusplus on
struct St_247410 {
    char pad[0x20]; int id; char pad24[0xC]; int prev; char pad34[4]; int cur;
    bool Entered(int s) { bool np = !(prev == s); return np && cur == s; }
    bool Left(int s) { return prev == s && !(cur == s); }
    bool Involves(int s) { return prev == s || cur == s; }
    bool NotIn(int s) { return !(prev == s) && !(cur == s); }
};
typedef struct { float a; float b; } HEnt_247410;
typedef struct { int x; int y; } Tmp_247410;
extern "C" {
void* cHumanMotionParams_cTargetZRotationStackSlot_ctor(Tmp_247410* t, float f);
void cArray_cTargetZRotationStackSlot_PushBackActual(char* h, void* e);
void cHumanMotionParams_UpdateTargetZRotation_AfterChangeInStack_AndSetNewTransitionDuration(char* h, float f);
int cHumanMotionParams_GetTargetZRotation_TopOfStackId(char* h);
#if 0 /* merge_units */
void cHumanMotionParams_cTargetZRotationStack_Remove_ByIndex_And_CleanUp(char* h, int id);
#endif /* merge_units */
#define cHumanMotionParams_cTargetZRotationStack_Remove_ByIndex_And_CleanUp(a0, a1) (cHumanMotionParams_cTargetZRotationStack_Remove_ByIndex_And_CleanUp((V247720 *)(a0), (a1))) /* merge_units */

HEnt_247410* cArray_cTargetZRotationStackSlot_opIndex(char* h, int id);
}
extern "C" void cPlayerControls_UpdateCharacterZRotation(St_247410* s, char* a, int on, float f)
{
    float spd;
    if ((s->Entered(5) && s->NotIn(8)) || (s->Entered(8) && s->NotIn(5)) || (s->Entered(5) && s->Entered(8))) {
        if (on && s->id == -1) {
            Tmp_247410 t;
            if (s->cur == 8)
                spd = 0.33f;
            else if (s->cur == 5)
                spd = 1.0f;
            cArray_cTargetZRotationStackSlot_PushBackActual(a + 0x3088, cHumanMotionParams_cTargetZRotationStackSlot_ctor(&t, f));
            cHumanMotionParams_UpdateTargetZRotation_AfterChangeInStack_AndSetNewTransitionDuration(a + 0x3030, spd);
            s->id = cHumanMotionParams_GetTargetZRotation_TopOfStackId(a + 0x3030);
        }
    } else if ((s->Left(5) && s->cur != 8) || (s->Left(8) && s->cur != 5) || (s->Left(5) && s->Left(8))) {
        if (s->id != -1) {
            cHumanMotionParams_cTargetZRotationStack_Remove_ByIndex_And_CleanUp(a + 0x3088, s->id);
            cHumanMotionParams_UpdateTargetZRotation_AfterChangeInStack_AndSetNewTransitionDuration(a + 0x3030, -1.0f);
            s->id = -1;
        }
    } else if ((s->cur == 5 || s->cur == 8) && on && s->id != -1) {
        cArray_cTargetZRotationStackSlot_opIndex(a + 0x3088, s->id)->b = f;
        cHumanMotionParams_UpdateTargetZRotation_AfterChangeInStack_AndSetNewTransitionDuration(a + 0x3030, -1.0f);
    }
}
#undef cHumanMotionParams_cTargetZRotationStack_Remove_ByIndex_And_CleanUp /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00247410(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00247410 */

/* merge_units: begin func_00247720 */
#pragma push /* merge_units */
#pragma cplusplus on


extern "C" void std_vector_imp_cTargetZRotationStackSlot_resize(V247720* v, int n, E247720* fill);
static inline int Used247720(E247720* e) { return e->used != 0; }
#pragma push
#pragma bool off
#pragma opt_strength_reduction off
extern "C" void cHumanMotionParams_cTargetZRotationStack_Remove_ByIndex_And_CleanUp(V247720* v, int idx)
{
    int n;
    int i;
    E247720 f;
    v->data[idx].used = 0;
    n = 0;
    for (i = v->count - 1; i >= 0; i--) { if (Used247720(&v->data[i]) ^ 1) continue; n = i + 1; break; }
    f.used = 1;
    f.v = 0;
    std_vector_imp_cTargetZRotationStackSlot_resize(v, n, &f);
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00247720(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00247720 */
