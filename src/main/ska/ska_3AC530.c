/*
 * main/ska: range (2 files, 003AC530-003AC5C0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_003AC530 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
extern "C" float AnimGroup_IsReady(void* list, int id); /* gsynth: defined below */
#pragma pop
typedef struct { char pad[0xE0]; float start; float cur; char grp[4]; } S3AC530;
typedef struct { float a; float b; } R3AC530;
extern int func_003AC6D0(void);
#if 0 /* merge_units */
extern float AnimGroup_IsReady(void* grp, int x);
#endif /* merge_units */
#define AnimGroup_IsReady(a0, a1) (AnimGroup_IsReady((a0), (a1))) /* merge_units */

int func_003AC530(S3AC530* p, R3AC530* r)
{
    float d;
    if (p->start != -1.0f) {
        d = p->start - p->cur;
    } else {
        d = AnimGroup_IsReady(p->grp, func_003AC6D0());
    }
    return d <= 0.5f * (r->a + r->b);
}
#undef AnimGroup_IsReady /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AC530(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003AC530 */

/* merge_units: begin func_003AC5C0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct C4Anim3AC { char pad[0x1C]; float x1C; char p20[4]; float x24; char p28[9]; unsigned char complete; };
struct C4It3AC { void* p; C4It3AC() {} C4It3AC(const C4It3AC& o) : p(o.p) {} };
extern "C" {
C4It3AC func_00198B90(void* list);
C4It3AC func_00198B60(void* list);
bool func_001989E0(C4It3AC* a, C4It3AC* b);
void func_00198A00(C4It3AC* it);
C4Anim3AC** func_00198B50(C4It3AC* it);
bool func_00198A20(C4Anim3AC* a, int id);
}
inline float Ready(C4Anim3AC* a) { if (a->complete) return 0.0f; return a->x1C * (1.0f - a->x24); }
extern "C" float AnimGroup_IsReady(void* list, int id) {
    C4Anim3AC* found = 0;
    C4It3AC it = func_00198B90(list);
    C4It3AC end = func_00198B60(list);
    while (func_001989E0(&it, &end)) {
        if (func_00198A20(*func_00198B50(&it), id)) {
            found = *func_00198B50(&it);
            break;
        }
        func_00198A00(&it);
    }
    return found ? Ready(found) : 0.0f;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003AC5C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003AC5C0 */
