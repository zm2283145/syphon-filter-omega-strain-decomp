/*
 * main/human: range (2 files, 001BD980-001BDA10)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "vector_insert_fill_cnt.h"
#pragma pop

/* merge_units: begin func_001BD980 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma exceptions off
struct Channel_1BD980 { int w[15]; };
struct ChannelVector_1BD980 {
    int f0;
    unsigned int count;
    Channel_1BD980* data;
    unsigned int size() const { return count; }
    Channel_1BD980* begin() { return data; }
    Channel_1BD980* end() { return data + count; }
};
extern "C" void AnimChannelVec_Grow(ChannelVector_1BD980* v, Channel_1BD980* pos, unsigned int n, const Channel_1BD980* fill);
extern "C" void func_001BEB20(ChannelVector_1BD980* v, Channel_1BD980* first, Channel_1BD980* last);
extern "C" void ChannelVector_Resize(ChannelVector_1BD980* v, unsigned int n, const Channel_1BD980* fill) {
    if (v->size() < n)
        AnimChannelVec_Grow(v, v->end(), n - v->size(), fill);
    else if (n < v->size())
        func_001BEB20(v, v->begin() + n, v->end());
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001BD980(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001BD980 */

/* merge_units: begin func_001BDA10 */
#pragma push /* merge_units */
#pragma cplusplus on
#define VIFC_ASSIGN(d, s) ((d)->a.m0 = (s)->a.m0, (d)->a.m1 = (s)->a.m1, (d)->a.m2 = (s)->a.m2)
#define VIFC_COPY(d, s) ((d)->c.m0 = (s)->c.m0, (d)->c.m1 = (s)->c.m1, (d)->c.m2 = (s)->c.m2, (d)->c.m3 = (s)->c.m3, (d)->c.m4 = (s)->c.m4)
struct G3_001BDA10 { int a[3]; };
union E_001BDA10 { struct { float m0; float m1; unsigned char m2; int m3; int m4; } c; struct { G3_001BDA10 m0; int m1; int m2; } a; };
DEFINE_VECTOR_INSERT_FILL_CNT(func_001BDA10, E_001BDA10, 0x4CCCCC, 0x266666, D_0049E980, D_0049ED58, 0x5C, func_001BDFE0, extern char D_0049ED38[]; void func_001BFA20(func_001BDA10_V* v);, func_001BFA20(&tmp); { E_001BDA10* fp_ = tmp.data; if (fp_) { if (fp_) TStr_Free((char*)fp_, D_0049ED38, 0x64); } }, VIFC_ASSIGN, VIFC_COPY)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001BDA10(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001BDA10 */
