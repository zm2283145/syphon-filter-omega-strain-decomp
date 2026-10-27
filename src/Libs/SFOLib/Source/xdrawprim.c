/*
 * Libs/SFOLib/Source/xdrawprim: 5 files, 00370080-003701A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00370080 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cXform_GetNode_void_2 and cXform_SetParent are Obj370000 virtuals (vtable D_004DF6A0
 * slots 14 and 16).
 */

#include "loose03_types.h"

int cXform_GetNode_void_2(void) {
    return 0;
}

void cXform_SetParent(void) {
}

void cXform_RemoveParent(void) {
}

void cXform_AddChild(void) {
}

void cXform_RemoveChild(void) {
}

/* table[index] with tag 0x14000000 or-ed in. */
int cVU1Man_GetMSCAL(int* table, int index) {
    return table[index] | 0x14000000;
}
static inline void merge_flush_func_00370080(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00370080 */

/* merge_units: begin func_003700F0 */
#pragma push /* merge_units */
#include "types.h"
long long DMATAG3(long long a, int b, long long c)
{
    long long r = c << 32; r |= b << 28; r |= a; return r;
}
static inline void merge_flush_func_003700F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003700F0 */

/* merge_units: begin func_00370110 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void cDmaMan_RegisterModel(void) {
}
static inline void merge_flush_func_00370110(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00370110 */

/* merge_units: begin func_00370120 */
#pragma push /* merge_units */
typedef struct { char pad[0x78]; int prog[30]; int cur; char pad2[0x50]; int uploads; } D2_Vu1Ctx;
extern char D_00477AF0[];
extern char D_0047BA70[];
extern char D_0047DB00[];
extern char D_0047DBA0[];
extern char D_00481030[];
extern char D_00482110[];
extern char D_00482BC0[];
extern char D_00485E50[];
void * const D_004932C0[8] = { (void*)D_00477AF0, (void*)D_0047BA70, (void*)D_0047DBA0, (void*)D_00482110, (void*)D_00482BC0, (void*)0x0, (void*)0x0, (void*)0x0 };
void * const D_004932E0[8] = { (void*)D_0047BA70, (void*)D_0047DB00, (void*)D_00481030, (void*)D_00482BC0, (void*)D_00485E50, (void*)0x0, (void*)0x0, (void*)0x0 };
extern char D_00537F80[];
extern void cDmaMan_InsertChain(void* dma, int n, int start, int end);
void cVU1Man_RequestProg(D2_Vu1Ctx* c, int slot) {
    int p = c->prog[slot];
    if (p != c->cur) {
        cDmaMan_InsertChain(D_00537F80, 1, ((int*)D_004932C0)[p], ((int*)D_004932E0)[p]);
        c->cur = p;
    }
    c->uploads++;
}
static inline void merge_flush_func_00370120(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00370120 */

/* merge_units: begin func_003701A0 */
#pragma push /* merge_units */
void cVU1Man_NewProgBatch(char* self) {
    *(int*)(self + 324) = 0;
}
static inline void merge_flush_func_003701A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003701A0 */
