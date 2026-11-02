/*
 * Libs/SFOLib/Source/DME: 4 files, 00429BA0-00429D30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00429BA0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

DEFINE_VTABLE_BASE_DTOR(cNetPlayGameMsg_dtor, D_004E0EC0, cMessage_dtor)
static inline void merge_flush_func_00429BA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00429BA0 */

/* merge_units: begin func_00429C00 */
#pragma push /* merge_units */
#include "types.h"
#include "DME.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
extern unsigned char D_005721C0;
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005723C8;
extern unsigned char D_005724B0;

/* Join callback (cDME_JoinGame): a client needs two successful results
   (JOIN_WAIT, then JOINED); the host is joined after the first. */
void cDME_LocalJoinCallback(int *result) {
    int isHost;

    if (D_005723C8 == 0) {
        D_005723C8 = 1;
    }
    if (*result == 0) {
        isHost = g_IsMultiplayer ? D_005721C0 : 1;
        if (isHost != 0) {
            D_005724B0 = DME_STATE_JOINED;
        } else if (D_005724B0 == DME_STATE_JOIN_WAIT) {
            D_005724B0 = DME_STATE_JOINED;
        } else {
            D_005724B0 = DME_STATE_JOIN_WAIT;
        }
    } else {
        D_005724B0 = DME_STATE_JOIN_FAILED;
    }
    D_005723C8 = 0;
}
static inline void merge_flush_func_00429C00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00429C00 */

/* merge_units: begin func_00429CB0 */
#pragma push /* merge_units */
#pragma mpwc_relax on
extern float g_DmeLatencyAvg;
extern float g_DmeLatencySum;
extern int g_DmeLatencyCount;

/* Accumulates a round-trip sample in ms (0..999) into a running average in seconds. */
void cDME_AddToAvgLatency(int ms) {
    if (ms < 0x3E8 && 0 <= ms) {
        g_DmeLatencyCount += 1;
        g_DmeLatencySum += 0.001f * (float) ms;
        g_DmeLatencyAvg = g_DmeLatencySum / (float) g_DmeLatencyCount;
    }
}
static inline void merge_flush_func_00429CB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00429CB0 */

/* merge_units: begin func_00429D30 */
#pragma push /* merge_units */
#include "net_local_id.h"

typedef struct { void* vt; char base[0x18]; int size; char pad20[4]; int value; char rest[0x30 - 0x28]; } NetLevelInfoMsg;
extern char D_004E1180[]; /* NetLevelInfoMsg vtable */
extern char D_005839A0[]; /* message type key "NetLevelInfoMsg" */
extern char D_004BF9B0[]; /* "DME.cc" */
extern char D_005721E0[];
extern char D_00572408[];
extern int D_00494198;
extern int D_00572428[3];          /* level-info state of clients 1..3 */
extern int D_00572270[4][20];      /* per-player ping history (ring buffer) */
extern int g_DmePingHistoryPos[4];
extern unsigned char D_005723D0;
extern unsigned char D_005721D0;
extern unsigned char D_00572420;
extern int D_005724E0;
extern int D_005724D8;
extern unsigned char D_005724D0;
extern unsigned char D_005723B8;
extern unsigned char D_005721D8;
extern unsigned char D_00572528;
extern int g_DmeLobby;
extern unsigned char g_DmeLobbyActive;
void cMessage_ctor_cMessageNameR(NetLevelInfoMsg* m, void* type);
#if 0 /* merge_units */
void cMessage_dtor(NetLevelInfoMsg* m, int f);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((void *)(a0), (short)(a1))) /* merge_units */

int NetLevelInfoMsg_Send(NetLevelInfoMsg* m, int a, int* out, int b, int c, int size, char* buf);
int NetSendMessage(int kind, int net, int dst, int ch, unsigned int len, int n, void* buf);
void printf(char* fmt, char* file, int line, int err); /* debug printf */
int NetGetTime(int* out);
void func_003FBEB0(void);
void cGenInfoObject_ReleasePrivate(void);
void cNPCInfoObject_ctor(int* o);
void cNPCInfoObject_CheckForPendingRelease(int* o);
void cNPCInfoObject_dtor(int* o, int v);
int NetUpdate(void);
void NetGetClientStatus(unsigned int* out, int net, int i);
void NetGetClientBufferStatus(int net, int i, int* a, int* b, int* c, int* d);
void NetGetNetUpdateErrors(int* arr);
int snprintf(char* s, int n, const char* fmt, ...);
void cNetObj_Update(char* p);
void SFOLobby_Intel(int v);

#pragma opt_dead_assignments off
static inline void NetBusyEnter(void) { if (!D_005723C8) D_005723C8 = 1; }
static inline void NetBusyLeave(void) { D_005723C8 = 0; }
/* Called from the DME thread: sends pending NetLevelInfoMsgs, records pings,
   pumps the network and checks for dropped connections; also updates the lobby. */
int DME_Update(void)
{
    int obj;
    int ping; int e4; int e0; int dc;
    int g1; int g2;
    int out;
    int netTime;
    unsigned int peerState;
    int connStates[6]; /* [0] = byte size, [1..4] = per-player state */
    NetLevelInfoMsg m;
    char buf[0x20];
    int i;
    int ret;
    for (i = 0; i < 3; i++) {
        if (D_00572428[i] == DME_LEVELINFO_PENDING) {
            int v = D_00494198;
            int r;
            cMessage_ctor_cMessageNameR(&m, D_005839A0);
            m.vt = D_004E1180;
            m.value = v;
            m.size = 0x40;
            r = NetLevelInfoMsg_Send(&m, 0, &out, 0, 0, 0x20, buf);
            if (r > -1) {
                int e = NetSendMessage((signed char)m.size, D_005721A8, i + 1, 2, out, r, buf);
                if (e) printf("%s : %d SHIT - %d\n", D_004BF9B0, 0x528, e);
            }
            D_00572428[i] = -1;
            m.vt = D_004E1180;
            cMessage_dtor(&m, 0);
        }
    }
    { int* p1 = &g1; int* p2 = &g2; } /* two unused frame slots in retail */
    ret = 0xFFFFFF;
    if (D_005723D0) {
        if (!D_005723C8) {
            NetBusyEnter();
            NetBusyLeave();
            if (D_005721D0 && D_00572420) D_005724E0 = 0;
            D_005724D8 = NetGetTime(&netTime) == 0 ? netTime : -1;
            if (D_005724D0) func_003FBEB0();
            if (D_005721D0) {
                cGenInfoObject_ReleasePrivate();
                cNPCInfoObject_ctor(&obj);
                cNPCInfoObject_CheckForPendingRelease(&obj);
                cNPCInfoObject_dtor(&obj, -1);
            }
            ret = NetUpdate();
            if (D_005721D0) {
                int j;
                for (j = 0; j < 4; j++) {
                    if (j != NetLocalId()) {
                        NetGetClientStatus(&peerState, D_005721A8, j);
                        if (peerState > 1) {
                            NetGetClientBufferStatus(D_005721A8, j, &ping, &e0, &e4, &dc);
                            D_00572270[j][g_DmePingHistoryPos[j]] = ping;
                            g_DmePingHistoryPos[j]++;
                            if (g_DmePingHistoryPos[j] >= 0x14) g_DmePingHistoryPos[j] = 0;
                        }
                    }
                }
            }
            if (ret) {
                int k;
                connStates[0] = 0x18;
                NetGetNetUpdateErrors(connStates);
                for (k = 0; k < 4; k++) {
                    int v = connStates[k + 1];
                    if (v) {
                        if (k != D_005721A8) {
                            if (v != 2) D_005723B8 = 1;
                        } else if (v != 0xC) {
                            D_005721D8 = 1;
                            snprintf(D_005721E0, 0x10, "GAME_DISCONNECT");
                        }
                    }
                }
            }
        }
        cNetObj_Update(D_00572408);
    }
    if (D_00572528 && g_DmeLobby && g_DmeLobbyActive && !D_005723C8) {
        NetBusyEnter();
        NetBusyLeave();
        SFOLobby_Intel(g_DmeLobby);
    }
    return ret;
}
#undef cMessage_dtor /* merge_units */
static inline void merge_flush_func_00429D30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00429D30 */
