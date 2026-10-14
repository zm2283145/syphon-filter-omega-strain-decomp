/*
 * main/npc: range (2 files, 0014FC40-0014FC60)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"

/* merge_units: begin func_0014FC40 */
#pragma push /* merge_units */
#pragma cplusplus on
struct CxNpcThunk { VPAD32(a) VPAD8(b) VPAD4(c) VPAD1(d)
virtual void Target(int,int);
};
extern "C" { static inline void CxNpcThunk_Call(CxNpcThunk* self,int arg) { self->Target(arg,100); } }
#pragma cplusplus off
void cNPC_v43(struct CxNpcThunk* self,int arg) { CxNpcThunk_Call(self,arg); }
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014FC40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014FC40 */

/* merge_units: begin func_0014FC60 */
#pragma push /* merge_units */
typedef struct CxBurstActor { char pad0[0xC]; int serial; char pad10[0x3524-0x10]; void* weapons; } CxBurstActor;
typedef struct CxBurstNpc { char pad0[0x30]; CxBurstActor* actor; char pad34[0xA4-0x34]; int burst; int shots; } CxBurstNpc;
extern int Actor_IsArmed(CxBurstActor*);
extern int Random_Next(void);
extern int WeaponInv_GetClipSize(void*,int);
void func_0014FC60(CxBurstNpc* self) {
    CxBurstActor* actor=self->actor;
    if(Actor_IsArmed(actor)) {
        void* weapons=actor->weapons;
        self->burst=(self->actor->serial&7)+3;
        if(Random_Next()&1)self->burst++;
        if(self->burst>WeaponInv_GetClipSize(weapons,6)) {
            int n=WeaponInv_GetClipSize(weapons,6)/2;
            if(n<=0)n=1;
            self->burst=n;
        }
    } else self->burst=0;
    self->shots=0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014FC60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014FC60 */
