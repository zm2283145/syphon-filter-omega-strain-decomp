/*
 * main/GuiMissionStatList: 2 files, 00351EE0-00351F40
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00351EE0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char unused; } Alloc00351EE0; /* empty allocator object passed by value */
typedef struct { char data[20]; } Elem00351EE0;
typedef struct { int unk0; int count; Elem00351EE0* items; } Src00351EE0;
typedef struct { int begin; int end; int cap; } Vec00351EE0;
extern void std_vector_imp_StatsRequirement_init(Vec00351EE0* v, Elem00351EE0* first, Elem00351EE0* last, Alloc00351EE0 alloc);
/* Construct an empty vector and fill it from src's items. */
Vec00351EE0* std_vector_StatsRequirement_ctor(Vec00351EE0* v, Src00351EE0* src)
{
    Alloc00351EE0 alloc;
    v->begin = 0;
    v->end = 0;
    v->cap = 0;
    std_vector_imp_StatsRequirement_init(v, src->items, src->items + src->count, alloc);
    return v;
}
#pragma pop /* merge_units */
/* merge_units: end func_00351EE0 */

/* merge_units: begin func_00351F40 */
#pragma push /* merge_units */
extern void MissionStats_StatsRequirement_dtor(void*, int);
typedef struct { char d[0x14]; } G6E35;
typedef struct { int x; int count; G6E35* arr; } G6C35;
void std_vector_deleter_StatsRequirement_clear(G6C35* c)
{
    G6E35* arr = c->arr;
    G6E35* e = arr + c->count;
    while (arr < e) {
        --e;
        MissionStats_StatsRequirement_dtor(e, -1);
    }
    c->count = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00351F40 */
