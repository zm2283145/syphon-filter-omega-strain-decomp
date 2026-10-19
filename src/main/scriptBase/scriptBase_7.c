/*
 * main/scriptBase: 2 files, 003D7960-003D7E30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003D7960 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#pragma inline_depth(10)

typedef struct { int pad0; int count; void** data; } Pool_3D7960;
typedef struct { void* buf; char m4[0x10]; void* p14; } A_3D7960;
typedef struct { void* buf; char pad4[0x10]; void* p14; } C_3D7960;
struct G_3D7960;
extern "C" {
extern char D_004BD3B0[];
extern Pool_3D7960* volatile D_00554F18;
extern Pool_3D7960* volatile D_00554F20;
extern Pool_3D7960* volatile D_00554F28;
extern Pool_3D7960* volatile D_00554F30;
extern int D_00554F38;
extern int D_00554F40;
extern int D_00554F48;
extern int D_00554F50;
void Mem_Free(int pool, void* p, char* file, int line);
void func_0012F530(G_3D7960* g, int f);
void func_00136DA0(G_3D7960* g);
void func_003D5DD0(void* p, int f);
void func_003D6F40(void* p, int f);
void func_003D95D0(void* p, int f);
}
struct G_3D7960 { char c; G_3D7960() { func_00136DA0(this); } __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~G_3D7960() { func_0012F530(this, -1); } };
static inline void M3_3D7960(void* p) { if (p) func_003D95D0(p, 0); }
static inline void M2_3D7960(void* p) { if (p) M3_3D7960(p); }
static inline void M1_3D7960(void* p) { if (p) M2_3D7960(p); }
static inline void FreeP_3D7960(void* p, int line) { AllocGuard g; Mem_Free(0, p, D_004BD3B0, line); }
static inline void DtorA_3D7960(A_3D7960* a) { FreeP_3D7960(a->buf, 0x1D8); M1_3D7960(a->m4); }
static inline void DtorC_3D7960(C_3D7960* c) { FreeP_3D7960(c->buf, 0x1F9); if (c->p14) FreeP_3D7960(c->p14, 0x1FC); }

static inline void DelA_3D7960(A_3D7960* a) { AllocGuard g; if (a) DtorA_3D7960(a); Mem_Free(0, a, D_004BD3B0, 0xF2); }
static inline void DelC_3D7960(C_3D7960* c) { AllocGuard g; if (c) DtorC_3D7960(c); Mem_Free(0, c, D_004BD3B0, 0xFE); }
static inline void DelB0_3D7960(void* b) { G_3D7960 g; func_003D5DD0(b, -1); Mem_Free(0, b, D_004BD3B0, 0xF8); }
static inline void DelD0_3D7960(void* d) { G_3D7960 g; func_003D6F40(d, -1); Mem_Free(0, d, D_004BD3B0, 0x104); }
/* nested delete helpers (inline depth sets the guard slot order) */
static inline void DelB1_3D7960(void* b) { DelB0_3D7960(b); }
static inline void DelB2_3D7960(void* b) { DelB1_3D7960(b); }
static inline void DelB_3D7960(void* b) { DelB2_3D7960(b); }
static inline void DelD1_3D7960(void* d) { DelD0_3D7960(d); }
static inline void DelD2_3D7960(void* d) { DelD1_3D7960(d); }
static inline void DelD_3D7960(void* d) { DelD2_3D7960(d); }
extern "C" void Script_TrimSymbolsToMarks(void)
{
    while (D_00554F30->count > D_00554F50) {
        Pool_3D7960* p = D_00554F30; A_3D7960* a = (A_3D7960*)p->data[p->count - 1];
        DelA_3D7960(a);
        D_00554F30->count--;
    }
    while (D_00554F20->count > D_00554F40) {
        Pool_3D7960* p = D_00554F20; void* b = p->data[p->count - 1];
        DelB_3D7960(b);
        D_00554F20->count--;
    }
    while (D_00554F18->count > D_00554F38) {
        Pool_3D7960* p = D_00554F18; C_3D7960* c = (C_3D7960*)p->data[p->count - 1];
        DelC_3D7960(c);
        D_00554F18->count--;
    }
    while (D_00554F28->count > D_00554F48) {
        Pool_3D7960* p = D_00554F28; void* d = p->data[p->count - 1];
        DelD_3D7960(d);
        D_00554F28->count--;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_003D7960 */

/* merge_units: begin func_003D7E30 */
#pragma push /* merge_units */
typedef struct Node4 {
    int unk0;
    int next;
} Node4;

#if 0 /* merge_units */
extern Node4* D_00554F18;
#endif /* merge_units */
#define D_00554F18 (*(Node4 **)&D_00554F18) /* merge_units */

#if 0 /* merge_units */
extern Node4* D_00554F20;
#endif /* merge_units */
#define D_00554F20 (*(Node4 **)&D_00554F20) /* merge_units */

#if 0 /* merge_units */
extern Node4* D_00554F28;
#endif /* merge_units */
#define D_00554F28 (*(Node4 **)&D_00554F28) /* merge_units */

#if 0 /* merge_units */
extern Node4* D_00554F30;
#endif /* merge_units */
#define D_00554F30 (*(Node4 **)&D_00554F30) /* merge_units */


/* Caches the second word of four list heads. */
void Script_SaveSymbolMarks(void) {
    D_00554F48 = D_00554F28->next;
    D_00554F50 = D_00554F30->next;
    D_00554F40 = D_00554F20->next;
    D_00554F38 = D_00554F18->next;
}
#undef D_00554F18 /* merge_units */
#undef D_00554F20 /* merge_units */
#undef D_00554F28 /* merge_units */
#undef D_00554F30 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D7E30 */
