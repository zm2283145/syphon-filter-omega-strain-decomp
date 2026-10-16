/*
 * main/message: 3 files, 003CA2B0-003CA360
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003CA2B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void* func_003CA2B0(char* self) {
    return self + 4;
}

Map* func_003CA2C0(Map* m, unsigned char* cmp) {
    m->count = 0;
    m->head = 0;
    m->cmp = *cmp;
    m->hp = &m->head;
    return m;
}

List* func_003CA2E0(List* l) {
    l->count = 0;
    l->first = l->last = &l->first;
    return l;
}
#pragma pop /* merge_units */
/* merge_units: end func_003CA2B0 */

/* merge_units: begin func_003CA300 */
#pragma push /* merge_units */
extern void func_003CA3F0(void* self, short del);
extern void operator_delete(void* p);
void* func_003CA300(void* self, short del)
{
    if (self) {
        if (self)
            func_003CA3F0(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_003CA300 */

/* merge_units: begin func_003CA360 */
#pragma push /* merge_units */
extern void func_003C9340(int* out, void* self);
extern void func_003CA3E0(int* out, void* self);
extern void func_003C9EA0(int* out, void* self, int* first, int* last);
void* func_003CA360(void* self, short del)
{
    if (self) {
        if (self) {
            int r;
            int first;
            int last;
            func_003C9340(&first, self);
            func_003CA3E0(&last, self);
            func_003C9EA0(&r, self, &first, &last);
        }
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_003CA360 */
