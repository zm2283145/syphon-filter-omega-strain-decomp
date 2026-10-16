/*
 * main/NetMsgThrottle: 2 files, 00472380-004723A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00472380 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Not inside a known source-file range: after NetMsgThrottle.cc (ends 0x00472370).
 */

#include "types.h"

Map* func_00472380(Map* m, unsigned char* cmp) {
    m->count = 0;
    m->head = 0;
    m->cmp = *cmp;
    m->hp = &m->head;
    return m;
}
#pragma pop /* merge_units */
/* merge_units: end func_00472380 */

/* merge_units: begin func_004723A0 */
#pragma push /* merge_units */
typedef struct { int m0; void* m4; } TB5C0;
extern void func_00472410(TB5C0* t, void* n);
extern void operator_delete(void* p);
TB5C0* func_004723A0(TB5C0* t, short del)
{
    if (t) {
        if (t) {
            if (t) {
                if (t->m4)
                    func_00472410(t, t->m4);
            }
        }
        if (del > 0)
            operator_delete(t);
    }
    return t;
}
#pragma pop /* merge_units */
/* merge_units: end func_004723A0 */
