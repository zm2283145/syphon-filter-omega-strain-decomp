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
