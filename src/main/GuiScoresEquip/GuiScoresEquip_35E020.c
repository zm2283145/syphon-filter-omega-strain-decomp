/*
 * main/GuiScoresEquip: range (8 files, 0035E020-0035E610)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "v4_asm_copy.h"
#pragma push
#pragma cplusplus on
#include "name_tree_find.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "vector_init_range.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "tree_find.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "vector_resize.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "vector_destroy_dtor.h"
#pragma pop
#include "short_string_compare.h"

/* merge_units: begin func_0035E020 */
#pragma push /* merge_units */
#pragma cplusplus on
struct V35E020 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); };
union Q35E020 { __int128 q; struct { float x, y, z, w; } f; };
struct Sub35E020 { char pad[0x10]; Q35E020 pos; };
struct T35E020 { V35E020 v; char pad4[0xC]; Sub35E020 sub; char pad40[0x20]; unsigned char b50; };
struct A35E020 { char pad[0x50]; T35E020* t; char pad54[0x10]; float heading; };
extern "C" {
float Math_Atan2f(float y, float x);
void Actor_BaseLogicUpdate(A35E020* a, float dt);
}
extern "C" void func_0035E020(A35E020* a, float dt)
{
    T35E020* t = a->t;
    Q35E020 p;
    if (t->b50)
        t->v.v20();
    Sub35E020* s = (Sub35E020*)((char*)t + 0x10);
    V4Copy(&p, &s->pos);
    a->heading = Math_Atan2f(p.f.x, *(volatile float*)&p.f.y);
    Actor_BaseLogicUpdate(a, dt);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0035E020(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0035E020 */

/* merge_units: begin func_0035E0A0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Find a name key in a tree; end() when absent. */
DEFINE_NAME_TREE_FIND(Tree_Compare_35E0A0)
#pragma pop /* merge_units */
/* merge_units: end func_0035E0A0 */

/* merge_units: begin func_0035E1C0 */
#pragma push /* merge_units */
#pragma cplusplus on

struct VRElem20 { float a; float b; unsigned char c; int d; int e; };
extern "C" {
char D_004BB660[] = "vector length error\n";
}
DEFINE_VECTOR_INIT_RANGE(Array_CopyRange20_35E1C0, VRElem20, 0x4CCCCC, D_004BB660, D_0049ED58, 0x5C)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0035E1C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0035E1C0 */

/* merge_units: begin func_0035E350 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Find a key in a tree; end() when absent. */
DEFINE_TREE_FIND(func_0035E350, std_basic_string_char_char_traits_char_compare_basicstringR)
#pragma pop /* merge_units */
/* merge_units: end func_0035E350 */

/* merge_units: begin func_0035E420 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Resize a vector of 60-byte elements. */
DEFINE_RESIZE_ELEMENT(Elem60, 60)
#pragma opt_common_subs off
DEFINE_VECTOR_RESIZE(ChannelVector_Resize_35E420, Elem60, AnimChannelVec_Grow, std_vector_imp_cSkaSliderValue_erase)
#pragma opt_common_subs reset
#pragma pop /* merge_units */
/* merge_units: end func_0035E420 */

/* merge_units: begin func_0035E4B0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Resize a vector of 8-byte elements. */
DEFINE_RESIZE_ELEMENT(Elem8, 8)
#pragma opt_common_subs off
DEFINE_VECTOR_RESIZE(func_0035E4B0, Elem8, Vector_Insert_1BF5A0, std_vector_imp_cSkaSwitchValue_erase)
#pragma opt_common_subs reset
#pragma pop /* merge_units */
/* merge_units: end func_0035E4B0 */

/* merge_units: begin func_0035E520 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Destroy a vector: destroy elements, free the buffer, optionally delete. */
DEFINE_VECTOR_DESTROY_DTOR_FILE(func_0035E520, func_001BFA20, D_0049ED38)
#pragma pop /* merge_units */
/* merge_units: end func_0035E520 */

/* merge_units: begin func_0035E610 */
#pragma push /* merge_units */
/* Compare two strings. */
DEFINE_SHORT_STRING_COMPARE(func_0035E610)
#pragma pop /* merge_units */
/* merge_units: end func_0035E610 */
