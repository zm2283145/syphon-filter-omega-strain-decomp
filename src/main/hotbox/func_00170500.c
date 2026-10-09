/*
 * Matched functions (byte-identical with the retail executable).
 * cHotbox interaction volumes, cHotboxMsg and the script natives that use them.
 */

#include "types.h"
#include "hotbox_types.h"

extern PtrVec D_004EE6E0;  /* list of created hotboxes */
extern void* D_004FFBD0;
extern int PtrVec_Insert(PtrVec* v, int* pos, int n, int* value);
extern int func_00170E20(void* owner, void* gobj, int a2, int a3);

/* push_back on a pointer vector. */
int func_00170500(PtrVec* v, int* value) {
    return PtrVec_Insert(v, v->data + v->count, 1, value);
}

/* Creates a hotbox for a game object and records it in D_004EE6E0. */
int Global_MakeGOBJInteractable(void* gobj) {
    int hotbox = func_00170E20(D_004FFBD0, gobj, 0, 0);

    func_00170500(&D_004EE6E0, &hotbox);
    return hotbox;
}
