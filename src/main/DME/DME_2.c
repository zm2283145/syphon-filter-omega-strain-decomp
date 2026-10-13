/*
 * main/DME: 2 files, 00429510-004295E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00429510 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
int Mem_Alloc(int, int, char *, int);
int func_00453E20(int); /* SFOLobby constructor ("MediusLobby") */
extern unsigned char D_00533880;
extern int g_DmeLobby;
extern signed char g_DmeLobbyActive;
}
/* Allocates the SFOLobby (0x26B0 bytes) on first use and enables its updates. */
extern "C" void DME_CreateLobby(void) {
    int lobby;

    if (g_DmeLobby == 0) {
        {
            AllocGuard g;
        lobby = Mem_Alloc(0, 0x26B0, "DME.cc", 0x75D);
        }
        if (lobby != 0) {
            lobby = func_00453E20(lobby);
        }
        g_DmeLobby = lobby;
    }
    g_DmeLobbyActive = 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_00429510 */

/* merge_units: begin func_004295E0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
void ExitDeleteThread(void);
void SleepThread(void);
void func_001161A0(void);
void func_001161F8(void);
void DME_Update(void);
extern signed char g_DmeThreadExited;
extern unsigned char g_DmeThreadStopRequest;
}
static inline int StopRequested() { return g_DmeThreadStopRequest != 0; }
#pragma bool off
/* DME worker thread: polls the network, then sleeps until DME_TimerHandler wakes it. */
extern "C" void DME_ThreadMain(void) {
    while (StopRequested() ^ 1) {
        DME_Update();
        func_001161F8();
        SleepThread();
        func_001161A0();
    }
    func_001161F8();
    g_DmeThreadExited = 1;
    ExitDeleteThread();
}
#pragma pop /* merge_units */
/* merge_units: end func_004295E0 */
