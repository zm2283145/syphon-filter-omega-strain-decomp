/*
 * main/scriptManager: 4 files, 003E3DF0-003E3FF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003E3DF0 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
#include "tree_insert_v8.h"

extern "C" { char D_004BDBC8[] = "allocator.hh"; }
DEFINE_TREE_INSERT_V8(func_003E3DF0, TIValueII, D_004BDA80, D_004BDBC8, 0x5C, func_0013CD40)
#pragma pop /* merge_units */
/* merge_units: end func_003E3DF0 */

/* merge_units: begin func_003E3F60 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


Map* func_003E3F60(Map* m, unsigned char* cmp) {
    m->count = 0;
    m->head = 0;
    m->cmp = *cmp;
    m->hp = &m->head;
    return m;
}
#pragma pop /* merge_units */
/* merge_units: end func_003E3F60 */

/* merge_units: begin func_003E3F80 */
#pragma push /* merge_units */
typedef struct { int m0; void* m4; } T3F80;
extern void func_003E4090(T3F80* t, void* n);
extern void operator_delete(void* p);
T3F80* func_003E3F80(T3F80* t, short del)
{
    if (t) {
        if (t) {
            if (t) {
                if (t->m4)
                    func_003E4090(t, t->m4);
            }
        }
        if (del > 0)
            operator_delete(t);
    }
    return t;
}
#pragma pop /* merge_units */
/* merge_units: end func_003E3F80 */

/* merge_units: begin func_003E3FF0 */
#pragma push /* merge_units */
extern void func_003E2A40(void* self, short del);
extern void func_003E2B30(void* self, short del);
extern void func_003E2C20(void* self, short del);
extern void func_003E2CA0(void* self, short del);
void* func_003E3FF0(void* self, short del)
{
    if (self) {
        void* a = (char*)self + 0x4E4C;
        void* b;
        void* c;
        if (a)
            func_003E2A40(a, -1);
        b = (char*)self + 0x18;
        if (b)
            func_003E2B30(b, -1);
        c = (char*)self + 0xC;
        if (c)
            func_003E2C20(c, 0);
        if (self)
            func_003E2CA0(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_003E3FF0 */
