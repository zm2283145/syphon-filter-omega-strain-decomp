/*
 * main/playerControls: range (4 files, 002492A0-00249420)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "curve_count_down.h"

/* merge_units: begin func_002492A0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Obj2492A0 { char p[0xC]; int id; };
struct T2492A0 { char p[0x3C]; int flags; char p40[0x7C]; unsigned char bBC; char pBD[3]; Obj2492A0* tgt; int tid; Obj2492A0* lk; int lid; char pD0[0x14]; int fE4; };
extern "C" {
extern void* g_Hud;
void cHud_ClearTarget(void* p);
}
static inline Obj2492A0* Get2492A0(T2492A0* s) {
    bool isNull;
bool ok;
Obj2492A0* t;
    t = s->tgt;
    isNull = !t;
    ok = true;
    if (!isNull) if (t->id != s->tid) ok = false;
    return ok ? t : 0;
}
static inline void Set2492A0(T2492A0* s, Obj2492A0* p) {
    int none;
    s->lk = p;
    s->lid = *(p ? &p->id : (none = -1, &none));
}
extern "C" void cPlayerControls_Untarget(T2492A0* t, Obj2492A0* o)
{
    if (Get2492A0(t) == o) {
        t->fE4 = -1;
        Set2492A0(t, 0);
        t->bBC = 1;
        if ((t->flags >> 5) & 1) cHud_ClearTarget(g_Hud);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002492A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002492A0 */

/* merge_units: begin func_00249330 */
#pragma push /* merge_units */
#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
extern "C" int std_list_deleter_cSafePtr_cGOBJ_erase_listdeleter_listdeleter(int *, char *, int *, char **);
typedef struct { int v; } H;
typedef struct { char pad[0xC8]; int c8; H cc; char padD0[0xE4-0xD0]; CurveCountDown cd; char list[4]; char* sent; int first; } T;
/* .word 0x46000006 is mov.s $f0,$f0: CW deletes the self-move of the max.s idiom after a branch. */
static inline float Max3_(float a, float b) { float r; asm { .word 0x46000006
 max.s r, b, a } return r; }
static inline int CD(CurveCountDown* p, float dt) { float old = p->remaining; p->remaining -= dt; p->remaining = Max3_(p->remaining, 0.0f); return old > 0.0f && p->remaining == 0.0f; }
static inline char* Identity(char*a){return a;}
static inline void clr0(char*a){int r;int f;char*l;l=Identity(a+0xF0);f=F_(a,0xF4,int);std_list_deleter_cSafePtr_cGOBJ_erase_listdeleter_listdeleter(&r,a+0xEC,&f,&l);}
static inline void setH(H* d, int v) { H h; H* hp; h.v = v; hp = &h; *d = *hp; }
#pragma push
#pragma opt_propagation off
extern "C" void cPlayerControls_DecrementTargetFrameTimer_AndClearStickyTargetedObjectIfNecessary(T* o, float dt)
{
    if (o->cd.remaining > 0.0f) {
        CD(&o->cd, dt);
    } else {
        clr0((char*)o);
        o->c8 = 0;
        setH(&o->cc, -1);
        o->cd.pad0 = -1;
    }
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00249330(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00249330 */

/* merge_units: begin func_002493C0 */
#pragma push /* merge_units */
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
typedef struct { char p0[316]; int f13C; } PS0_002493C0;
typedef struct { char p0[13604]; int f3524; char p3528[92]; int f3584; } PS1_002493C0;
void cPlayerControls_NetSelectNextWeapon(PS0_002493C0 *arg0, PS1_002493C0 *arg1) {
    int var_v1_2;
    unsigned char temp_a0;
    char * temp_a1;
    char * temp_a2;
    char * var_v1;

    if (arg0->f13C == NULL) {
        var_v1 = (char *)(arg1->f3584);
        if (var_v1 != NULL) {
            var_v1 += 0x1C;
        }
        arg0->f13C = (int)(var_v1);
    }
    temp_a2 = (char *)(arg0->f13C);
    if (temp_a2 != NULL) {
        temp_a1 = (char *)(arg1->f3524);
        temp_a0 = F_(temp_a1, 0x84, unsigned char);
        var_v1_2 = (temp_a0 != 6) ? F_(((char *)(temp_a0 * 0x10) + (int)(temp_a1)), 0x8, int) : -1;
        F_(temp_a2, 0x6, short) = (short) var_v1_2;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002493C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002493C0 */

/* merge_units: begin func_00249420 */
#pragma push /* merge_units */
typedef struct { char pad[5]; char b5; } Sub49;
typedef struct { char pad[0x13C]; Sub49* p13C; void* p140; } Owner49;
typedef struct { char pad[0x3584]; char* p3584; } Ctx49;
extern void cPlayerControls_NetDisableManualAim(Owner49* self, Ctx49* ctx);
void cPlayerControls_NetAimWeapon(Owner49* self, Ctx49* ctx, int a2, char a3) {
    if (!self->p13C) {
        char* q = ctx->p3584;
        if (q) q += 0x1C;
        self->p13C = (Sub49*)q;
    }
    if (self->p13C) self->p13C->b5 = a3;
    cPlayerControls_NetDisableManualAim(self, ctx);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00249420(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00249420 */
