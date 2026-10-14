/*
 * main/AgentData: range (2 files, 003334C0-00333600)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_003334C0 */
#pragma push /* merge_units */
#pragma opt_strength_reduction off

typedef struct RangeDef4C0 {
    int key;
    int unk04;
    int start;
    int len;
    int value;
    int unk14;
} RangeDef4C0;

typedef struct RangeTable4C0 {
    int unk00;
    int count;
    RangeDef4C0* data;
    int unk0C;
} RangeTable4C0;

typedef struct RangeRec4C0 {
    signed char flag;
    char pad01[0x13];
} RangeRec4C0;

typedef struct RangeRecVec4C0 {
    int unk00;
    int count;
    RangeRec4C0* data;
    int unk0C;
} RangeRecVec4C0;

typedef struct Agent4C0 {
    char pad00[0xAA8];
    RangeRecVec4C0 recs[5];
} Agent4C0;

typedef struct Out4C0 {
    int text;
    int key;
    signed char flag;
    int value;
    int unk10;
} Out4C0;

typedef struct OutVec4C0 {
    int unk00;
    int count;
    Out4C0* data;
} OutVec4C0;

extern RangeTable4C0 D_00532A70[5];
extern void func_00299510(OutVec4C0* v);
extern int Loc_GetTextById(int id);
extern int func_00339270(OutVec4C0* v, Out4C0* pos, int n, Out4C0* value);

void func_003334C0(Agent4C0* self, unsigned char type, OutVec4C0* out)
{
    RangeRecVec4C0* recs = &self->recs[type];
    int i;
    func_00299510(out);
    for (i = 0; i < recs->count; i++) {
        Out4C0 e;
        RangeDef4C0* d = &D_00532A70[type].data[i];
        signed char flag;
        int value;
        int key;
        value = d->value;
        key = d->key;
        flag = recs->data[i].flag;
        e.text = Loc_GetTextById(key);
        e.key = key;
        e.flag = flag;
        e.value = value;
        e.unk10 = 0;
        func_00339270(out, &out->data[out->count], 1, &e);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003334C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003334C0 */

/* merge_units: begin func_00333600 */
#pragma push /* merge_units */
#pragma opt_strength_reduction off

typedef struct Rating600 {
    int key;
    int unk04;
    unsigned char stat;
    char pad09[3];
    int min;
    int need;
    int value;
} Rating600;

typedef struct RatingVec600 {
    int unk00;
    int count;
    Rating600* data;
} RatingVec600;

typedef struct Agent600 {
    char pad00[0x08];
    int stats[1];
} Agent600;

typedef struct Out600 {
    int text;
    int key;
    signed char flag;
    int value;
    int pct;
} Out600;

typedef struct OutVec600 {
    int unk00;
    int count;
    Out600* data;
} OutVec600;

extern RatingVec600 D_00532AD0;
#if 0 /* merge_units */
extern void func_00299510(OutVec600* v);
#endif /* merge_units */
#define func_00299510(a0) (func_00299510((void *)(a0))) /* merge_units */

extern signed char* func_00333790(void* bits, int i);
#if 0 /* merge_units */
extern int func_00339270(OutVec600* v, Out600* pos, int n, Out600* value);
#endif /* merge_units */
#define func_00339270(a0, a1, a2, a3) (func_00339270((void *)(a0), (void *)(a1), (a2), (void *)(a3))) /* merge_units */


void func_00333600(Agent600* self, OutVec600* out)
{
    int i;
    func_00299510(out);
    for (i = 0; i < D_00532AD0.count; i++) {
        Out600 e;
        int pct;
        signed char flag;
        int value;
        int key;
        Rating600* r = &D_00532AD0.data[i];
        int v = self->stats[r->stat];
        int need = r->need;
        pct = 0;
        if (v >= need) {
            pct = 100;
        } else if (r->min < v) {
            pct = (v - r->min) * 100 / (need - r->min);
        }
        value = r->value;
        flag = *func_00333790(&self->stats[700], i);
        key = r->key;
        e.text = Loc_GetTextById(key);
        e.key = key;
        e.flag = flag;
        e.value = value;
        e.pct = pct;
        func_00339270(out, &out->data[out->count], 1, &e);
    }
}
#undef func_00299510 /* merge_units */
#undef func_00339270 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00333600(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00333600 */
