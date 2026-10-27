/*
 * SFOGame/Source/hotbox: 2 files, 00170500-00170570
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00170500 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cHotbox interaction volumes, cHotboxMsg and the script natives that use them.
 */

#include "types.h"
#include "hotbox_types.h"

extern PtrVec g_RuntimeHotboxes;  /* list of created hotboxes */
extern void* g_HotboxTracker;
extern int std_vector_pod_int_insert(PtrVec* v, int* pos, int n, int* value);
extern int cHotboxMan_CreateInteractBox(void* owner, void* gobj, int a2, int a3);

/* push_back on a pointer vector. */
int std_vector_cHotboxPtr_push_back(PtrVec* v, int* value) {
    return std_vector_pod_int_insert(v, v->data + v->count, 1, value);
}

/* Creates a hotbox for a game object and records it in g_RuntimeHotboxes. */
int Global_MakeGOBJInteractable(void* gobj) {
    int hotbox = cHotboxMan_CreateInteractBox(g_HotboxTracker, gobj, 0, 0);

    std_vector_cHotboxPtr_push_back(&g_RuntimeHotboxes, &hotbox);
    return hotbox;
}
static inline void merge_flush_func_00170500(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00170500 */

/* merge_units: begin func_00170570 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Eq_0570 {};
struct Pred_0570 { Eq_0570 op; int* ref; Pred_0570(const Eq_0570& e, int* r) : op(e), ref(r) {} };
struct M_0570 { char pad[0x28]; char list[4]; };
extern "C" {
extern char g_HotboxList[];
#if 0 /* merge_units */
extern char g_RuntimeHotboxes[];
#endif /* merge_units */
#define g_RuntimeHotboxes ((char*)&g_RuntimeHotboxes) /* merge_units */

extern int D_004EE6E4;
#if 0 /* merge_units */
extern M_0570* g_HotboxTracker;
#endif /* merge_units */
#define g_HotboxTracker (*(M_0570 **)&g_HotboxTracker) /* merge_units */

void std_list_imp_voidPtr_remove_if(void* list, Pred_0570 p);
int* func_00170650(void* v, int i);
}
extern "C" void ResetInteractBoxes(void)
{
    int key;
    Eq_0570 e1;
    Eq_0570 e2;
    M_0570* mgr = g_HotboxTracker;
    int i;
    for (i = 0; i < D_004EE6E4; i++) {
        key = *func_00170650(g_RuntimeHotboxes, i);
        std_list_imp_voidPtr_remove_if(g_HotboxList, Pred_0570(e1, &key));
        std_list_imp_voidPtr_remove_if(mgr->list, Pred_0570(e2, &key));
    }
    D_004EE6E4 = 0;
}
#undef g_RuntimeHotboxes /* merge_units */
#undef g_HotboxTracker /* merge_units */
static inline void merge_flush_func_00170570(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00170570 */
