#include "types.h"
#define NULL 0
#pragma mpwc_relax on
int Mem_Free(int, int, char *, int);
int func_0012F530(char *, int);                     /* scope object dtor */
int func_00136DA0(char *);                          /* scope object ctor */
int MotionManager_Dtor(int, int);                        /* MotionManager dtor */
extern int g_MotionManager;                              /* MotionManager* */

/* Destroy and free the motion manager. */
void MotionManager_Shutdown(void) {
    int scope;
    int mgr;

    mgr = g_MotionManager;
    if (mgr != 0) {
        func_00136DA0((char *)&scope);
        MotionManager_Dtor(mgr, -1);
        Mem_Free(0, mgr, "motionManager.cc", 0x2B);
        func_0012F530((char *)&scope, -1);
        g_MotionManager = 0;
    }
}