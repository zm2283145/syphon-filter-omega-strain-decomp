/*
 * main/motionManager: motionManager.cc (3 files, 0040F570-0040F5E0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0040F570 */
#pragma push /* merge_units */
#include "types.h"
#define NULL 0
#pragma mpwc_relax on
int Mem_Free(int, int, char *, int);
int func_0012F530(char *, int);                     /* scope object dtor */
int func_00136DA0(char *);                          /* scope object ctor */
#include "motionManager_types.h"
MotionManager* MotionManager_Dtor(MotionManager*, short); /* MotionManager dtor */
extern int g_MotionManager;                              /* MotionManager* */

/* Destroy and free the motion manager. */
void MotionManager_Shutdown(void) {
    int scope;
    int mgr;

    mgr = g_MotionManager;
    if (mgr != 0) {
        func_00136DA0((char *)&scope);
        MotionManager_Dtor((MotionManager *)mgr, -1);
        Mem_Free(0, mgr, "motionManager.cc", 0x2B);
        func_0012F530((char *)&scope, -1);
        g_MotionManager = 0;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0040F570 */

/* merge_units: begin func_0040F5E0 */
#pragma push /* merge_units */
#include "motionManager_types.h"
extern void World_FreePendingTree(MotionManager* t, void* n);
extern void operator_delete(void* p);
/* Deleting destructor: erase the whole tree from the root, then delete when del > 0. */
MotionManager* MotionManager_Dtor(MotionManager* t, short del)
{
    if (t) {
        if (t) {
            if (t) {
                if (t->root)
                    World_FreePendingTree(t, t->root);
            }
        }
        if (del > 0)
            operator_delete(t);
    }
    return t;
}
#pragma pop /* merge_units */
/* merge_units: end func_0040F5E0 */

/* merge_units: begin func_0040F650 */
#pragma push /* merge_units */
#pragma mpwc_relax on
int Alloc_Lock(int);
int Alloc_Unlock(int);
int Mem_Alloc(int, int, char *, int);
int MotionManager_Ctor(int, char *, char *);             /* MotionManager ctor (compare, allocator) */
extern char D_004BEDD0;                             /* "motionManager.cc" */
extern unsigned char D_00533880;                    /* allocator locking enabled */
extern int D_00533888;                              /* allocation guard depth */

/* Create the motion manager once (an inlined AllocGuard wraps the allocation). */
void MotionManager_Init(void) {
    struct { char pad20[4]; int alloc; int less[2]; } sl; /* empty functor/allocator temporaries */
    int mgr;

    if (g_MotionManager == 0) {
        if (D_00533880 != 0) {
            Alloc_Lock(9);
        }
        D_00533888 += 1;
        mgr = Mem_Alloc(0, sizeof(MotionManager), &D_004BEDD0, 0x20);
        if (D_00533880 != 0) {
            Alloc_Unlock(9);
        }
        D_00533888 -= 1;
        if (mgr != 0) {
            MotionManager_Ctor(mgr, (char *)sl.less, (char *)&sl.alloc);
        }
        g_MotionManager = mgr;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0040F650 */
