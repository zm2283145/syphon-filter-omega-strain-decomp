/*
 * main/tank: range (4 files, 00284750-002852F0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00284750 */
#pragma push /* merge_units */
typedef struct { char pad[0x18]; float a[6]; char pad30[0x20]; float b; char pad54[0x18]; int c; } S_00284D80;
void func_00284D80(S_00284D80* p); /* gsynth: defined below */
#pragma cplusplus on
extern unsigned char* D_005061D0;
static inline void W16_00284750(int v) { short s = v; *D_005061D0++ = s; *D_005061D0++ = s >> 8; }
static inline void W32_00284750(int v) { W16_00284750((unsigned short)v); W16_00284750(v >> 16); }
static inline void WF_00284750(float f) { W32_00284750(*(int*)&f); }
static inline short R16_00284750(void) { unsigned char lo = *D_005061D0++; unsigned char hi = *D_005061D0++; return lo + (hi << 8); }
static inline int R32_00284750(void) { unsigned short lo = R16_00284750(); return lo + ((unsigned short)R16_00284750() << 16); }
static inline float RF_00284750(void) { int i = R32_00284750(); return *(float*)&i; }
typedef struct { void* a; void* b; void* c; } P_00284750;
typedef struct { char pad[0x64]; P_00284750* s0; P_00284750* s1; P_00284750* turret; unsigned char b70; } T_00284750;
extern "C" void func_00282020(void* o);
#if 0 /* merge_units */
extern "C" void func_00284D80(P_00284750* p);
#endif /* merge_units */
#define func_00284D80(a0) (func_00284D80((S_00284D80 *)(a0))) /* merge_units */

extern "C" void func_00284750(T_00284750* t) {
    bool n = t->s0 && t->s1;
    bool tu = t->turret != 0;
    *D_005061D0++ = n;
    *D_005061D0++ = tu;
    *D_005061D0++ = t->b70;
    if (n) {
        func_00282020(t->s0->a);
        func_00282020(t->s0->b);
        func_00282020(t->s1->a);
        func_00282020(t->s1->b);
    }
    if (tu) {
        func_00282020(t->turret->a);
        func_00282020(t->turret->b);
        func_00282020(t->turret->c);
        func_00284D80(t->turret);
    }
}
#undef func_00284D80 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00284750(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00284750 */

/* merge_units: begin func_00284870 */
#pragma push /* merge_units */
extern void* g_WeaponDatabase;
extern void* WeaponDb_Get(void* db, int id);
static inline short R16_00284870(void) { unsigned char lo = *D_005061D0++; unsigned char hi = *D_005061D0++; return lo + (hi << 8); }
static inline int R32_00284870(void) { unsigned short lo = R16_00284870(); return lo + ((unsigned short)R16_00284870() << 16); }
static inline float RF_00284870(void) { int i = R32_00284870(); return *(float*)&i; }
typedef struct { char pad[0x18]; float a[6]; char pad30[0x20]; float b; char pad54[0x14]; void* w; int id; } S_00284870;
static inline void SetW_00284870(S_00284870* p, int id) { void* db = g_WeaponDatabase; p->id = id; p->w = WeaponDb_Get(db, id); }
void func_00284870(S_00284870* p) {
    p->a[0] = RF_00284870();
    p->a[1] = RF_00284870();
    p->a[2] = RF_00284870();
    p->a[3] = RF_00284870();
    p->a[4] = RF_00284870();
    p->a[5] = RF_00284870();
    p->b = RF_00284870();
    p->id = R32_00284870();
    SetW_00284870(p, p->id);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00284870(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00284870 */

/* merge_units: begin func_00284D80 */
#pragma push /* merge_units */
static inline void W16_00284D80(int v) { short s = v; *D_005061D0++ = s; *D_005061D0++ = s >> 8; }
static inline void W32_00284D80(int v) { W16_00284D80((unsigned short)v); W16_00284D80(v >> 16); }
static inline void WF_00284D80(float f) { W32_00284D80(*(int*)&f); }

void func_00284D80(S_00284D80* p) {
    WF_00284D80(p->a[0]);
    WF_00284D80(p->a[1]);
    WF_00284D80(p->a[2]);
    WF_00284D80(p->a[3]);
    WF_00284D80(p->a[4]);
    WF_00284D80(p->a[5]);
    WF_00284D80(p->b);
    W32_00284D80(p->c);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00284D80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00284D80 */

/* merge_units: begin func_002852F0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int func_002852F0(int arg0) {
    return F_(F_(arg0, 0x60, int), 0x40, float);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002852F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002852F0 */
