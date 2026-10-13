#include "types.h"
#include "net_local_id.h"
#include "DME.h"

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
extern unsigned char D_005723C8;
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
void Event_Construct(NetLevelInfoMsg* m, void* type);
void cMessage_dtor(NetLevelInfoMsg* m, int f);
int NetLevelInfoMsg_Send(NetLevelInfoMsg* m, int a, int* out, int b, int c, int size, char* buf);
int Net_SendLocked(int kind, int net, int dst, int ch, unsigned int len, int n, void* buf);
void printf(char* fmt, char* file, int line, int err); /* debug printf */
int func_002EBCE0(int* out);
void func_003FBEB0(void);
void func_0043A810(void);
void func_00436C00(int* o);
void func_004352C0(int* o);
void func_00436BA0(int* o, int v);
int func_002EC4F8(void);
void func_002EB7A0(unsigned int* out, int net, int i);
void func_002ECF08(int net, int i, int* a, int* b, int* c, int* d);
void func_002EC580(int* arr);
int snprintf(char* s, int n, const char* fmt, ...);
void func_003FAC40(char* p);
void func_004536B0(int v);

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
            Event_Construct(&m, D_005839A0);
            m.vt = D_004E1180;
            m.value = v;
            m.size = 0x40;
            r = NetLevelInfoMsg_Send(&m, 0, &out, 0, 0, 0x20, buf);
            if (r > -1) {
                int e = Net_SendLocked((signed char)m.size, D_005721A8, i + 1, 2, out, r, buf);
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
            D_005724D8 = func_002EBCE0(&netTime) == 0 ? netTime : -1;
            if (D_005724D0) func_003FBEB0();
            if (D_005721D0) {
                func_0043A810();
                func_00436C00(&obj);
                func_004352C0(&obj);
                func_00436BA0(&obj, -1);
            }
            ret = func_002EC4F8();
            if (D_005721D0) {
                int j;
                for (j = 0; j < 4; j++) {
                    if (j != NetLocalId()) {
                        func_002EB7A0(&peerState, D_005721A8, j);
                        if (peerState > 1) {
                            func_002ECF08(D_005721A8, j, &ping, &e0, &e4, &dc);
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
                func_002EC580(connStates);
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
        func_003FAC40(D_00572408);
    }
    if (D_00572528 && g_DmeLobby && g_DmeLobbyActive && !D_005723C8) {
        NetBusyEnter();
        NetBusyLeave();
        func_004536B0(g_DmeLobby);
    }
    return ret;
}