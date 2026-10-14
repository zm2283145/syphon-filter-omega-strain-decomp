/*
 * main/GuiSubTitleDisplay: range (3 files, 004593A0-00459500)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
#include "SFOLobby_helpers.h"
int Mem_Free();
int strlen(const char *);

/* merge_units: begin func_004593A0 */
#pragma push /* merge_units */
typedef struct { void** data; int count; } Vec_4593A0;
typedef struct { char pad[0x58]; Vec_4593A0 v; char pad60[0x6C - 0x60]; int f6C; } S_4593A0;
extern void*** func_00171EC0(Vec_4593A0*);
extern void func_00136DA0(int*);
extern void func_00459320(void*, int);
extern void func_0012F530(int*, int);
extern char D_004C1EB0[];

#pragma push
#pragma opt_strength_reduction off
void func_004593A0(S_4593A0* s)
{
    int i;
    for (i = 0; i < s->v.count; i++) {
        void* e = (*func_00171EC0(&s->v))[i];
        int guard;
        func_00136DA0(&guard);
        func_00459320(e, -1);
        Mem_Free(0, e, D_004C1EB0, 0x48);
        func_0012F530(&guard, -1);
    }
    s->v.count = 0;
    s->f6C = 0;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004593A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004593A0 */

/* merge_units: begin func_00459450 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
#if 0 /* merge_units */
extern char D_004C1EB0;
#endif /* merge_units */
#define D_004C1EB0 (*(char*)&D_004C1EB0) /* merge_units */

}
typedef struct { char pad[0x50]; int buf; int n; } S_459450;
#pragma opt_common_subs off
extern "C" void func_00459450(S_459450* s)
{
    int p = s->buf;
    if (p != 0) {
        {
            AllocGuard g;
            Mem_Free(0, p, &D_004C1EB0, 0x3F);
        }
        s->buf = 0;
    }
    s->n = 0;
}
#undef D_004C1EB0 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00459450(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00459450 */

/* merge_units: begin func_00459500 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
void* Mem_Alloc(int, int, char*, int);
#if 0 /* merge_units */
extern char D_004C1EB0;
#endif /* merge_units */
#define D_004C1EB0 (*(char*)&D_004C1EB0) /* merge_units */

}
typedef struct { char pad[0x50]; int buf; int n; } S_459500;
extern "C" int func_00458A30(S_459500*);

static inline void Clear_459500(S_459500* s)
{
    int p = s->buf;
    if (p != 0) {
        {
            AllocGuard g;
            Mem_Free(0, p, &D_004C1EB0, 0x3F);
        }
        s->buf = 0;
    }
    s->n = 0;
}

extern "C" int func_00459500(S_459500* s, char* text)
{
    int len;
    int p;
    if (!text || !*text)
        return 0;
    Clear_459500(s);
    len = strlen(text) + 1;
    {
        AllocGuard g;
        p = (int)Mem_Alloc(0, len, &D_004C1EB0, 0x2E);
    }
    s->buf = p;
    String_Copy((char*)s->buf, text);
    s->n = 0;
    if (!func_00458A30(s))
        return 0;
    return 1;
}
#undef D_004C1EB0 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00459500(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00459500 */
