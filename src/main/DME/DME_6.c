/*
 * main/DME: 4 files, 0042A640-0042A780
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0042A640 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void PtrVec_End_42A640(Iter* out, PtrVec* v) {
    out->p = v->data + v->count;
}

Word* Iter_Copy_42A660(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void PtrVec_Begin_42A670(Iter* out, PtrVec* v) {
    out->p = v->data;
}
#pragma pop /* merge_units */
/* merge_units: end func_0042A640 */

/* merge_units: begin func_0042A680 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "DME.h"

extern "C" {
extern int g_DmeThreadId;
extern int g_DmeMainThreadId;
extern unsigned char g_DmeThreadStopRequest;
extern unsigned char g_DmeThreadExited;
extern unsigned char D_00572528;
extern int D_00572508;
extern unsigned char g_ProfileLockEnabled; /* allocator must lock Timer0 */
void ReferThreadStatus(int thread, EeThreadParam* status);
void ChangeThreadPriority(int thread, int priority);
int iWakeupThread(int thread);
void DelayThread(int delay);
}

/* Stop the DME thread: request the stop, wake it and wait until DME_ThreadMain
   exits, then clear the thread and allocator-locking flags. */
extern "C" void DME_StopThread(void)
{
    EeThreadParam worker;
    EeThreadParam current;
    ReferThreadStatus(g_DmeThreadId, &worker);
    ReferThreadStatus(g_DmeMainThreadId, &current);
    if (worker.currentPriority <= current.currentPriority)
        ChangeThreadPriority(g_DmeThreadId, 0);
    g_DmeThreadStopRequest = 1;
    int woken = iWakeupThread(g_DmeThreadId);
    DelayThread(10);
    if (woken == g_DmeThreadId) {
        while ((g_DmeThreadExited != 0) ^ 1)
            DelayThread(10);
    }
    g_DmeThreadStopRequest = 0;
    D_00572528 = 0;
    D_00572508 = 0;
    g_DmeThreadExited = 0;
    g_ProfileLockEnabled = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0042A680 */

/* merge_units: begin func_0042A770 */
#pragma push /* merge_units */
extern int DME_CreateThread(int);
extern int DME_ThreadMain(void);

/* Starts the DME thread running DME_ThreadMain. */
int DME_StartThread(void) {
    return DME_CreateThread((int)DME_ThreadMain);
}
#pragma pop /* merge_units */
/* merge_units: end func_0042A770 */

/* merge_units: begin func_0042A780 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int func_002EBCE0(char *);
int Gui_GetScreenStack();
int GuiWidget_SendEvent(int, int, int, int, int);
int Net_ConnectGameByName();
extern signed char D_005721E0;
extern signed char D_005721F0;
extern signed char D_005723B0;
extern signed char D_00572468;
extern int g_DmeConnectRetries;
extern int g_DmeConnectMaxRetries;
extern signed char D_005724B0;

extern char D_004BF9B8; /* "F_TO_CONNECT" */
/* Retries the connection; after g_DmeConnectMaxRetries failures shows the
   "F_TO_CONNECT" error, otherwise flags another retry (D_00572468). */
void Net_RetryConnect(void) {
    int netTime;
    int retries;
    int screens;

    D_005723B0 = 0;
    D_005721E0 = 0; /* clears the disconnect-reason string */
    D_005724B0 = DME_STATE_CONNECTING;
    D_005721F0 = 0;
    if (Net_ConnectGameByName() == 0) {
        func_002EBCE0(&netTime);
        return;
    }
    retries = g_DmeConnectRetries + 1;
    g_DmeConnectRetries = retries;
    if (retries < g_DmeConnectMaxRetries) {
        D_00572468 = 1;
        return;
    }
    if (Gui_GetScreenStack(retries) != 0) {
        screens = Gui_GetScreenStack();
        GuiWidget_SendEvent(screens, Gui_GetScreenStack(), 0x1E, 0, (int)&D_004BF9B8);
    }
    g_DmeConnectRetries = 0;
    g_DmeConnectMaxRetries = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_0042A780 */
