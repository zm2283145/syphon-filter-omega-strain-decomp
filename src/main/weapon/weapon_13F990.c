/*
 * main/weapon: range (4 files, 0013F990-0013FB50)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "vtable_base_dtor.h"
#pragma pop

/* merge_units: begin func_0013F990 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
void* Mem_Alloc(int pool, int size, char* file, int line);
extern char D_004DFD80[];
extern char D_004D91E0[];
}
struct M1EEDC0 { void* vtable; int w4, w8, wC, w10, w14, w18, w1C; char b20; int w24; };
extern "C" M1EEDC0* cOutOfAmmoMsg_v01(M1EEDC0* self)
{
    M1EEDC0* p;
    {
        AllocGuard guard;
        p = (M1EEDC0*)Mem_Alloc(0, 0x28, "weapon.hh", 0x112);
    }
    if (p) {
        p->vtable = D_004DFD80;
        p->w4 = self->w4;
        p->w8 = self->w8;
        p->wC = self->wC;
        p->w10 = self->w10;
        p->w14 = self->w14;
        p->w18 = self->w18;
        p->w1C = self->w1C;
        p->b20 = self->b20;
        p->vtable = D_004D91E0;
        p->w24 = self->w24;
    }
    return p;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0013F990(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0013F990 */

/* merge_units: begin func_0013FA90 */
#pragma push /* merge_units */
#pragma cplusplus on

DEFINE_VTABLE_BASE_DTOR(cOutOfAmmoMsg_dtor, D_004D91E0, cMessage_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_0013FA90 */

/* merge_units: begin func_0013FAF0 */
#pragma push /* merge_units */
typedef struct { char pad[0x3C]; int range; } WeapEntD4;
typedef struct { int a; int b; int id; int c; } SlotD4;
typedef struct { SlotD4 slots[8]; char pad[4]; unsigned char cur; } LosD4;
extern void* g_WeaponDatabase;
extern WeapEntD4* WeaponDb_Get(void* db, int id);
float Weapon_GetHeldRange(LosD4* p)
{
    float r = 0.0f;
    unsigned char i = p->cur;
    if (i != 6) {
        SlotD4* s = p->slots + i; int id = s->id;
        if (id != -1) {
            r = WeaponDb_Get(g_WeaponDatabase, id)->range;
        }
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0013FAF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0013FAF0 */

/* merge_units: begin func_0013FB50 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern int WeaponDb_Get(int db, int id);
#endif /* merge_units */
#define WeaponDb_Get(a0, a1) ((int)WeaponDb_Get((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int g_WeaponDatabase;
#endif /* merge_units */
#define g_WeaponDatabase (*(int*)&g_WeaponDatabase) /* merge_units */

typedef struct { char pad[0x68]; int weapon; } S_FB50;
int WeaponInv_GetSlot6Record(S_FB50* p)
{
    int r;
    int id = p->weapon;
    if (id != -1) { r = WeaponDb_Get(g_WeaponDatabase, id); asm { .set reorder } /* empty-asm barrier: keeps the call arm's b; nop */ } else r = 0;
    return r;
}
#undef WeaponDb_Get /* merge_units */
#undef g_WeaponDatabase /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0013FB50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0013FB50 */
