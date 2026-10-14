/*
 * main/ai: range (3 files, 00169A60-00169B70)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "vtable_base_dtor.h"
#pragma pop
#include "types.h"
#include "vslot_pad.h"

/* merge_units: begin func_00169A60 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" {
extern "C" void NpcAlert_SoundEvent();
extern "C" void func_0012ECE0();
extern "C" void func_0012ECF0();
extern "C" void func_0012ED00();
extern "C" void func_0012ED10();
extern "C" void func_0012ED20();
extern "C" void func_0012ED30();
extern "C" void func_0012ED40();
extern "C" void func_0012ED50();
extern "C" void func_001383D0();
extern "C" void Receiver_GetScriptTypeKey();
extern "C" void Receiver_ScriptDispatch();
extern void * const D_004D9810[];
void* Receiver_Destruct(void* self, short deleteFlag);
}
extern "C" VtableObject* func_00169A60(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004D9810);
        Receiver_Destruct(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004D9810[16] = { (void*)0x0, (void*)0x0, (void*)func_00169A60, (void*)NpcAlert_SoundEvent, (void*)func_0012ECE0, (void*)func_0012ECF0, (void*)func_001383D0, (void*)func_0012ED00, (void*)func_0012ED10, (void*)func_0012ED20, (void*)func_0012ED30, (void*)func_0012ED40, (void*)func_0012ED50, (void*)Receiver_GetScriptTypeKey, (void*)Receiver_ScriptDispatch, (void*)0x0 };
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00169A60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00169A60 */

/* merge_units: begin func_00169AC0 */
#pragma push /* merge_units */
#pragma cplusplus on
class Ai_9AC0 { public: VPAD16(a) VPAD4(b) virtual int IsA(); virtual int IsB(); };
typedef struct { char pad[0x58]; Ai_9AC0* ai; } Obj_9AC0;
extern "C" Obj_9AC0* GObj_IdentityB(int id);
extern "C" void func_0014A670(Ai_9AC0* ai);
static inline unsigned char TestA(Obj_9AC0* o) { unsigned char r = 0; if (o->ai && o->ai->IsA()) r = 1; return r; }
static inline unsigned char TestB(Obj_9AC0* o) { unsigned char r = 0; if (o->ai && o->ai->IsB()) r = 1; return r; }
extern "C" void Script_CastNPC(int* args)
{
    Obj_9AC0* o = GObj_IdentityB(*args);
    Ai_9AC0* ai = 0;
    if (TestA(o) || TestB(o))
        ai = o->ai;
    func_0014A670(ai);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00169AC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00169AC0 */

/* merge_units: begin func_00169B70 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Snd_9B70 { VPAD16(a) VPAD2(b) VPAD1(c) virtual int IsA(); virtual int IsB(); };
struct Obj_9B70 { char pad[0x58]; Snd_9B70* snd; char pad5c[0x31F8 - 0x5C]; float radius; };
union Arg_9B70 { int i; float f; };
#if 0 /* merge_units */
extern "C" Obj_9B70* GObj_IdentityB(int);
#endif /* merge_units */
#define GObj_IdentityB(a0) ((Obj_9B70 *)GObj_IdentityB((a0))) /* merge_units */

/* script: set the footstep sound radius (float argument staged via the stack) */
extern "C" int Script_SetFootstepSoundRadius(Arg_9B70* args)
{
    volatile int w[1];
    float r;
    Obj_9B70* g;
    w[0] = args[1].i;
    r = *(volatile float*)w;
    g = GObj_IdentityB(args[0].i);
    if (g->snd && (g->snd->IsA() || g->snd->IsB())) g->radius = r;
    return 0;
}
#undef GObj_IdentityB /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00169B70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00169B70 */
