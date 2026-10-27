/*
 * SFOGame/Source/map: 3 files, 0026C360-0026C3B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0026C360 */
#pragma push /* merge_units */
#include "types.h"
#include "iter_return_copy.h"

/* Return the begin iterator. */
DEFINE_ITER_BEGIN(std_list_cHudTargetInfoPtr_begin_void)
static inline void merge_flush_func_0026C360(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0026C360 */

/* merge_units: begin func_0026C390 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose01_types.h"

Word* std_list_cHudTargetInfoPtr_generic_iterator_1_ctor(Word* dst, int value) {
    volatile int tmp = value; /* stored to the stack and reloaded */

    dst->value = tmp;
    return dst;
}
static inline void merge_flush_func_0026C390(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0026C390 */

/* merge_units: begin func_0026C3B0 */
#pragma push /* merge_units */
typedef struct LNode { struct LNode* prev; struct LNode* next; int data; } LNode;
typedef struct LIt { LNode* node; } LIt;
typedef struct LList { int count; LNode* last; LNode* first; } LList;
typedef struct Obj { char pad[0x24]; LList list; } Obj;

extern int cHudTargetManager_GetObjectiveTarget(Obj* o);
extern void cHudTargetManager_SetObjectiveTarget(Obj* o, int v);
extern void std_list_deleter_voidPtr_begin_void_2(LIt* out, LList* l);
#if 0 /* merge_units */
extern LIt* std_list_cHudTargetInfoPtr_generic_iterator_1_ctor(LIt* out, LNode* n);
#endif /* merge_units */
#define std_list_cHudTargetInfoPtr_generic_iterator_1_ctor(a0, a1) ((LIt *)std_list_cHudTargetInfoPtr_generic_iterator_1_ctor((Word *)(a0), (int)(a1))) /* merge_units */

extern void std_list_cHudTargetInfoPtr_end_void(LIt* out, LList* l);
extern LIt* cConstLListIterator_cHudTargetInfoPtr_ctor(LIt* dst, LIt* src);
extern void cMap_ObjectiveSelected(Obj** self);

int cMap_NextObjective(Obj** self) {
    LIt bc;
    LIt ec;
    LIt r;
    LIt a;
    LIt a2;
    LIt b;
    LIt b2;
    LIt t;
    LIt bs;
    LIt es;
    LList* l = &(*self)->list;
    LNode* n;
    if ((*self)->list.count == 0) return 0;
    if (!cHudTargetManager_GetObjectiveTarget(*self)) {
        a.node = l->first;
        b = a;
        cHudTargetManager_SetObjectiveTarget(*self, b.node->data);
    } else {
        if (l->count > 1) {
        std_list_deleter_voidPtr_begin_void_2(&t, l);
        std_list_cHudTargetInfoPtr_generic_iterator_1_ctor(&r, t.node);
        n = r.node;
        while (std_list_cHudTargetInfoPtr_end_void(&es, l), cConstLListIterator_cHudTargetInfoPtr_ctor(&ec, &es), n != ec.node) {
            if (n->data == cHudTargetManager_GetObjectiveTarget(*self)) {
                LNode* nx = n->next;
                std_list_cHudTargetInfoPtr_end_void(&bs, l);
                cConstLListIterator_cHudTargetInfoPtr_ctor(&bc, &bs);
                if (nx == bc.node) {
                    a2.node = l->first;
                    b2 = a2;
                    cHudTargetManager_SetObjectiveTarget(*self, b2.node->data);
                } else {
                    cHudTargetManager_SetObjectiveTarget(*self, nx->data);
                }
                break;
            }
            n = n->next;
        }
        } else {
            return 0;
        }
    }
    cMap_ObjectiveSelected(self);
    return 1;
}
#undef std_list_cHudTargetInfoPtr_generic_iterator_1_ctor /* merge_units */
static inline void merge_flush_func_0026C3B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0026C3B0 */
