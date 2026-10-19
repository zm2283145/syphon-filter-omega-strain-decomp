/*
 * main/DME: 4 files, 00429380-00429500
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00429380 */
#pragma push /* merge_units */
#include "types.h"
#include "DME.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int CreateThread(int *);
int StartThread(int, int);
int ChangeThreadPriority(int, int);
extern char D_004E9B70; /* _gp */
extern signed char g_ProfileLockEnabled; /* allocator must lock Timer0 (DME thread may preempt) */
extern int g_DmeThreadId;
extern int g_DmeMainThreadId;
extern unsigned char D_00572528; /* DME thread running */
extern char g_DmeThreadStack; /* 0x10000 bytes */

/* Starts the DME worker thread at `entry`; g_DmeThreadId holds the caller's
   thread id until it is replaced by the new thread. */
int DME_CreateThread(int entry) {
    /* kernel ThreadParam; the array members keep retail's stack layout */
    struct { int status; int entry; char * stack; int stackSize; char * gp; int prio[4]; int wait[2]; int wakeupCount; } param;

    if (D_00572528 == 0) {
        param.entry = entry;
        param.status = 0x10;
        param.stack = &g_DmeThreadStack;
        param.wait[0] = 0;
        param.stackSize = 0x10000;
        param.wakeupCount = 0;
        param.gp = &D_004E9B70;
        g_DmeMainThreadId = g_DmeThreadId;
        param.prio[0] = 5; /* initPriority */
        ChangeThreadPriority(g_DmeThreadId, 0xA);
        g_DmeThreadId = CreateThread(&param.status);
        StartThread(g_DmeThreadId, 0);
        g_ProfileLockEnabled = 1;
        D_00572528 = 1;
    }
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_00429380 */

/* merge_units: begin func_00429430 */
#pragma push /* merge_units */
#pragma mpwc_relax on
int Alloc_Unlock(int);
int AddIntcHandler(int, char *, int);
extern int g_DmeTimerHandlerId;
extern char DME_TimerHandler;

/* Programs EE Timer 0 and installs DME_TimerHandler on its interrupt line. */
unsigned char DME_InstallTimer(void) {
    unsigned char installed = 0;

    T0_MODE = 0xC00; /* clear EQUF/OVFF */
    T0_COMP = 0x24A;
    T0_COUNT = 0;
    T0_MODE = 0x382; /* BUSCLK/256, CUE, CMPE, OVFE */
    g_DmeTimerHandlerId = AddIntcHandler(INTC_TIM0, &DME_TimerHandler, 0);
    if (g_DmeTimerHandlerId != -1) {
        Alloc_Unlock(INTC_TIM0); /* enables the interrupt */
        installed = 1;
    }
    return installed;
}
#pragma pop /* merge_units */
/* merge_units: end func_00429430 */

/* merge_units: begin func_004294C0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern int g_DmeLobby;
extern unsigned char g_DmeLobbyActive;
/* The SFOLobby instance, or 0 when lobby updates are disabled. */
extern "C" int DME_GetLobby(void)
{
    unsigned char ok = 0; if (g_DmeLobby && g_DmeLobbyActive) ok = 1; return ok ? g_DmeLobby : 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_004294C0 */

/* merge_units: begin func_00429500 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


#if 0 /* merge_units */
extern char g_DmeLobbyActive[];
#endif /* merge_units */
#define g_DmeLobbyActive ((char*)&g_DmeLobbyActive) /* merge_units */


void DME_SetLobbyActive(int a0) {
    *(char*)g_DmeLobbyActive = a0;
}
#undef g_DmeLobbyActive /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00429500 */
