/*
 * SFOGame/Source/GuiEndGameObjectives: 3 files, 00462620-00462CA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin GuiGameScreen_462620 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies after GuiGameScreen.cc (ends 0x0045F090).
 */

#include "loose05_types.h"

extern int strncpy(void* dst, int a1, int a2);
extern int std_vector_imp_tQuip_insert(Vec12* v, char* pos, int n, int value);

/* Appends one 12-byte element at the end of the vector. */
int cArray_tQuip_PushBackActual(Vec12* v, int value) {
    char* data;
    int count;

    data = v->data;
    count = v->count;
    return std_vector_imp_tQuip_insert(v, data + count * 12, 1, value);
}

int* cQuipList_tQuip_ctor(int* self, int a1, int a2) {
    strncpy(self, a1, 8);
    self[2] = a2;
    return self;
}
static inline void merge_flush_GuiGameScreen_462620(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiGameScreen_462620 */

/* merge_units: begin func_00462690 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
#include "vector_insert_fill_cnt.h"
#define VIFC_ASSIGN(d, s) ((d)->m0 = (s)->m0, (d)->m1 = (s)->m1)
#define VIFC_COPY(d, s) ((d)->m0 = (s)->m0, (d)->m1 = (s)->m1)
struct B8_00462690 { char a[8]; };
struct E_00462690 { B8_00462690 m0; int m1; };
extern "C" char D_004C26D0[] = "vector::insert length error\n";
DEFINE_VECTOR_INSERT_FILL_CNT(func_00462690, E_00462690, 0x800000, 0x400000, D_004C26D0, D_004C2578, 0x5C, std_swap_vectordeleterR_vectordeleterR_52, extern char D_004C2568[]; void func_00461FA0(func_00462690_V* v);, func_00461FA0(&tmp); { E_00462690* fp_ = tmp.data; if (fp_) { if (fp_) TStr_Free((char*)fp_, D_004C2568, 0x64); } }, VIFC_ASSIGN, VIFC_COPY)
static inline void merge_flush_func_00462690(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00462690 */

/* merge_units: begin func_00462CA0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Not inside a known source-file range: after GuiGameScreen.cc (ends 0x0045F090),
 * before inventory.cc (starts 0x004702A0).
 */


void func_00462CA0(PtrVec* a, PtrVec* b) {
    if (a != b) {
        int t;
        int* p;
        t = a->unk0;
        a->unk0 = b->unk0;
        b->unk0 = t;
        p = a->data;
        a->data = b->data;
        b->data = p;
        t = a->count;
        a->count = b->count;
        b->count = t;
    }
}
static inline void merge_flush_func_00462CA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00462CA0 */
