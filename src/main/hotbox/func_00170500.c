/*
 * Matched functions (byte-identical with the retail executable).
 * cHotbox interaction volumes, cHotboxMsg and the script natives that use them.
 */

#include "types.h"
#include "hotbox_types.h"

extern PtrVec g_RuntimeHotboxes;  /* list of created hotboxes */
extern void* g_HotboxTracker;
extern int PtrVec_Insert(PtrVec* v, int* pos, int n, int* value);
extern int Hotbox_CreateRuntime(void* owner, void* gobj, int a2, int a3);

/* push_back on a pointer vector. */
int HotboxList_PushBack(PtrVec* v, int* value) {
    return PtrVec_Insert(v, v->data + v->count, 1, value);
}

/* Creates a hotbox for a game object and records it in g_RuntimeHotboxes. */
int Global_MakeGOBJInteractable(void* gobj) {
    int hotbox = Hotbox_CreateRuntime(g_HotboxTracker, gobj, 0, 0);

    HotboxList_PushBack(&g_RuntimeHotboxes, &hotbox);
    return hotbox;
}
