/*
 * main/ai: range (3 files, 0016A0A0-0016A550)
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
int Mem_Free();

/* merge_units: begin func_0016A0A0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct P_A0A0 { char pad[0x1C]; void* data; };
extern "C" {
extern void* D_004EE620;
extern unsigned char D_004EE628;
extern int D_004EE618;
extern int D_004EE610;
extern unsigned char D_005721C0;
extern unsigned char D_005721C8;
extern unsigned char D_005721D0;
extern char D_0049C800[];
extern char D_0049C650[];
extern char D_0049C648[];
void* Mem_Alloc(int pool, int size, char* file, int line);
int func_002EAF28(int* out, int a, int b, int c, int d, int e, int f, void* g, char* h, int i);
int func_002EB650(P_A0A0** out, int id);
}
/* 0x100-byte relation matrix, allocated through a class operator new
   (lock/unlock written out rather than AllocGuard). The non-POD
   new-expression ends the allocation in its own block, which gives the
   retail nop and the empty delay slot after it. */
struct Blk_A0A0 {
    char d[0x100];
    Blk_A0A0() {}
    static void* operator new(unsigned int sz, int line)
    {
        void* p;
        if (D_00533880) Alloc_Lock(9);
        D_00533888++;
        p = Mem_Alloc(0, sz, D_0049C650, line);
        if (D_00533880) Alloc_Unlock(9);
        D_00533888--;
        return p;
    }
};
static inline void* Alloc_A0A0(int line) { return new (line) Blk_A0A0; }
static inline void Set_A0A0(void* nv)
{
    void* old = D_004EE620;
    if (old && !D_004EE628)
    {
        AllocGuard g;
        Mem_Free(0, old, D_0049C800, 0x1FE);
    }
    D_004EE620 = nv;
}
extern "C" void TeamRelations_CreateMultiplayer(void)
{
    
    if (D_005721C8 ? D_005721C0 : 1) {
        if (D_005721D0 && !D_004EE618) {
            int id;
            P_A0A0* p;
            if (!func_002EAF28(&id, 1, 4, 0, 0, 0, 0, D_004EE620, D_0049C648, D_004EE610)
                && !func_002EB650(&p, id)) {
                void* old = D_004EE620;
                void* nv = p->data;
                if (old && !D_004EE628) {
                    AllocGuard g;
                    Mem_Free(0, old, D_0049C800, 0x1FE);
                }
                D_004EE620 = nv;
                D_004EE628 = 1;
            }
        } else if (!D_005721D0) {
            { void* nv = Alloc_A0A0(0x806); Set_A0A0(nv); }
        }
    } else {
        { void* nv = Alloc_A0A0(0x80B); Set_A0A0(nv); }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016A0A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0016A0A0 */

/* merge_units: begin func_0016A450 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
unsigned int D_0048A100[4] = { 0x1, 0x0, 0x0, 0x0 };
extern unsigned char D_005723C8;
}
extern "C" void func_0016A450(void)
{
    if (!D_005723C8)
        D_005723C8 = 1;
    {
    void* p = D_004EE620;
    if (p && !D_004EE628) {
        AllocGuard g;
        Mem_Free(0, p, D_0049C650, 0x6FE);
    }
    D_004EE620 = 0;
    D_004EE628 = 0;
    (*(signed char*)D_0048A100) = 1;
    }
    D_005723C8 = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016A450(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0016A450 */

/* merge_units: begin func_0016A550 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern char D_005723C8[];
#endif /* merge_units */
#define D_005723C8 ((char*)&D_005723C8) /* merge_units */


void func_0016A550(void) {
    int v1;
    int cond;

    v1 = *(unsigned char*)(char*)D_005723C8;
    cond = v1 != 0;
    v1 = 0 + 1;
    if (cond) goto L0016A568;
    *(char*)(char*)D_005723C8 = v1;
L0016A568:;
    *(char*)(char*)D_005723C8 = 0;
    goto ret;
ret:;
}
#undef D_005723C8 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016A550(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0016A550 */
