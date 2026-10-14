/*
 * main/ska: range (2 files, 003ACDD0-003ACEA0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_003ACDD0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct C4Anim3AC { char pad[0x31]; unsigned char complete; };
struct C4It3AC { void* p; C4It3AC() {} C4It3AC(const C4It3AC& o) : p(o.p) {} };
extern "C" {
C4It3AC func_00198B90(void* list);
C4It3AC func_00198B60(void* list);
bool func_001989E0(C4It3AC* a, C4It3AC* b);
void func_00198A00(C4It3AC* it);
C4Anim3AC** func_00198B50(C4It3AC* it);
bool func_00198A20(C4Anim3AC* a, int id);
}
extern "C" unsigned char AnimGroup_IsComplete(void* list, int id) {
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
    if (found) return found->complete;
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003ACDD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003ACDD0 */

/* merge_units: begin func_003ACEA0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* For every phase overlapping the given one, run its handler. */
typedef struct { unsigned char pad[0xC]; unsigned char sub[8]; } Phase_3ACEA0;
typedef struct { int pad0; int count; } Vec_3ACEA0;
typedef struct { unsigned char enabled; unsigned char pad[0x3B]; Vec_3ACEA0 phases; } Obj_3ACEA0;

extern "C" {
Phase_3ACEA0** func_003AD1D0(Vec_3ACEA0* v);
int Phase_Overlaps(void* a, Phase_3ACEA0* b);
void func_003ACF60(void* p);
}

static inline bool Ne_3ACEA0(Phase_3ACEA0* a, Phase_3ACEA0* b) { return !(a == b); }

extern "C" void func_003ACEA0(Obj_3ACEA0* o, void* phase)
{
    if (o->enabled) {
        Phase_3ACEA0* it;
        Phase_3ACEA0* end;
        it = *func_003AD1D0(&o->phases);
        end = *func_003AD1D0(&o->phases) + o->phases.count;
        for (; Ne_3ACEA0(it, end); it++) {
            if (Phase_Overlaps(phase, it))
                func_003ACF60(it->sub);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003ACEA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003ACEA0 */
