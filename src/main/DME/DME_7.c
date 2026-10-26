/*
 * main/DME: 4 files, 0042A960-0042ACD0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0042A960 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "DME.h"

extern char g_DmeConnectRetries[];
extern char g_DmeConnectMaxRetries[];
extern int Net_StartSession(int);

/* Net_StartSession without retries. */
int Net_StartSessionSingleTry(int join) {
    *(int*)g_DmeConnectRetries = 0;
    *(int*)g_DmeConnectMaxRetries = 1;
    return Net_StartSession(join);
}
#pragma pop /* merge_units */
/* merge_units: end func_0042A960 */

/* merge_units: begin func_0042A980 */
#pragma push /* merge_units */
typedef struct NetHostGameCfg {
    int unk00;
    void* onConnectResult;
    int unk08;
    void* onClientConnect;
    int unk10;
    void* onClientDisconnect;
    int unk18;
    int port;
    DmeSessionCfg sess;
} NetHostGameCfg;
unsigned int D_00494180[2] = { 0x4, 0x0 }; /* game port */
extern int D_00494198;
extern int D_005721A8;
extern unsigned char D_005721C0;
extern unsigned char D_005724B0;
extern void DME_OnConnectResult(void);
extern void DME_OnClientConnect(void);
extern void DME_OnClientDisconnect(void);
extern void cHeadSet_AudioRecordCallback(void);
extern void cHeadSet_AudioPlayCallback(void);
extern void NetSetSendAggregationInterval(int a, int b, int c);
extern int NetSetDefaultHostPeerToPeerParams(NetHostGameCfg* cfg);
extern int NetGame_Create(NetHostGameCfg* cfg, DmeGameOut* out);
static inline void MemClear_h5(void* d0, int n0) { int n = n0; void* dst = d0;
    asm {
        .set noreorder
        blez n, done
        nop
        andi $a1, dst, 0xF
        andi $a0, n, 0xF
        or $a1, $a1, $a0
        nop
        bgtz $a1, bytes
        srl $a0, n, 4
        nop
        blez $a0, bytes
        nop
        nop
    quads:
        addi $a0, $a0, -1
        sq $zero, 0(dst)
        bgtz $a0, quads
        addiu dst, dst, 0x10
        b done
        nop
    bytes:
        addi n, n, -1
        sb $zero, 0(dst)
        bgtz n, bytes
        addiu dst, dst, 1
    done:
        .set reorder
    }
}
/* Hosts a new game; on success this machine becomes the host (D_005721C0). */
void Net_CreateGame(void)
{
    DmeGameOut out;
    NetHostGameCfg cfg;
    int err;
    if (D_00494198 == 0x10) {
        NetSetSendAggregationInterval(0, 0x5A, 0x5A);
    } else {
        NetSetSendAggregationInterval(0, 0x3C, 0x3C);
    }
    err = NetSetDefaultHostPeerToPeerParams(&cfg);
    cfg.onConnectResult = DME_OnConnectResult;
    cfg.port = (*(int*)D_00494180);
    cfg.onClientConnect = DME_OnClientConnect;
    cfg.onClientDisconnect = DME_OnClientDisconnect;
    MemClear_h5(&cfg.sess, 0x54);
    cfg.sess.cb34 = cHeadSet_AudioPlayCallback;
    cfg.sess.unk10 = 1;
    cfg.sess.unk04 = 1;
    cfg.sess.cb2C = cHeadSet_AudioRecordCallback;
    cfg.sess.unk0C = 1;
    cfg.sess.unk14 = 1;
    cfg.sess.unk08 = 2;
    cfg.sess.unk20 = 2;
    cfg.sess.unk18 = 0x10;
    cfg.sess.unk24 = 0x10;
    cfg.sess.unk1C = 0x1F40;
    cfg.sess.unk28 = 0x1F40;
    if (err == 0) {
        if (NetGame_Create(&cfg, &out) == 0) {
            D_005721C0 = 1;
        } else {
            D_005721A8 = out.handle;
            D_005724B0 = DME_STATE_DISCONNECTED;
        }
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0042A980 */

/* merge_units: begin func_0042AB00 */
#pragma push /* merge_units */
typedef struct NetJoinCfg {
    int unk00;
    int mode;
    char addr[0x9C];
    void* onConnectResult;
    int unkA8;
    int unkAC;
    int unkB0;
    void* onClientConnect;
    int unkB8;
    void* onClientDisconnect;
    int unkC0;
    void* onHostDisconnect;
    int unkC8;
    DmeSessionCfg sess;
    int tail[4];
} NetJoinCfg;
extern char D_004BF9B8[]; /* "F_TO_CONNECT" */
extern void DME_OnHostDisconnect(void);
extern int NetSetDefaultConnectParams(NetJoinCfg* cfg);
extern int NetConnect(NetJoinCfg* cfg, DmeGameOut* out);
extern void* memcpy(void* d, const void* s, unsigned int n);
extern int Gui_GetScreenStack(void);
extern void GuiWidget_SendEvent(int a, int b, int c, int d, int e);
static inline void MemClear_n1(void* d0, int n0) { int n = n0; void* dst = d0;
    asm {
        .set noreorder
        blez n, done
        nop
        andi $a0, dst, 0xF
        andi $v1, n, 0xF
        or $a0, $a0, $v1
        nop
        bgtz $a0, bytes
        srl $v1, n, 4
        nop
        blez $v1, bytes
        nop
        nop
    quads:
        addi $v1, $v1, -1
        sq $zero, 0(dst)
        bgtz $v1, quads
        addiu dst, dst, 0x10
        b done
        nop
    bytes:
        addi n, n, -1
        sb $zero, 0(dst)
        bgtz n, bytes
        addiu dst, dst, 1
    done:
        .set reorder
    }
}
/* Joins the game at `addr` (0x9C-byte address block). Returns nonzero on failure. */
int Net_ConnectGame(void* addr)
{
    DmeGameOut out;
    NetJoinCfg cfg;
    int err;
    if (D_00494198 == 0x10) {
        NetSetSendAggregationInterval(0, 0x5A, 0x5A);
    } else {
        NetSetSendAggregationInterval(0, 0x3C, 0x3C);
    }
    NetSetDefaultConnectParams(&cfg);
    cfg.mode = 4;
    memcpy(cfg.addr, addr, 0x9C);
    cfg.onConnectResult = DME_OnConnectResult;
    cfg.onClientConnect = DME_OnClientConnect;
    cfg.onClientDisconnect = DME_OnClientDisconnect;
    cfg.onHostDisconnect = DME_OnHostDisconnect;
    MemClear_n1(&cfg.sess, 0x54);
    cfg.sess.cb34 = cHeadSet_AudioPlayCallback;
    cfg.sess.unk10 = 1;
    cfg.sess.unk04 = 1;
    cfg.sess.cb2C = cHeadSet_AudioRecordCallback;
    cfg.sess.unk0C = 1;
    cfg.sess.unk14 = 1;
    cfg.sess.unk08 = 2;
    cfg.sess.unk20 = 2;
    cfg.sess.unk18 = 0x10;
    cfg.sess.unk24 = 0x10;
    cfg.sess.unk1C = 0x1F40;
    cfg.sess.unk28 = 0x1F40;
    err = NetConnect(&cfg, &out);
    if (err) {
        D_005721A8 = out.handle;
        D_005724B0 = DME_STATE_DISCONNECTED;
        if (Gui_GetScreenStack()) {
            GuiWidget_SendEvent(Gui_GetScreenStack(), Gui_GetScreenStack(), 0x1E, 0, (int)D_004BF9B8);
        }
    }
    return err;
}
#pragma pop /* merge_units */
/* merge_units: end func_0042AB00 */

/* merge_units: begin func_0042ACD0 */
#pragma push /* merge_units */
typedef struct NetJoinByNameCfg {
    int unk00;
    int mode;
    int unk08;
    int unk0C;
    char name[0x10];
    int unk20;
    char addr[0x80];
    void* onConnectResult;
    int unkA8;
    int unkAC;
    int unkB0;
    void* onClientConnect;
    int unkB8;
    void* onClientDisconnect;
    int unkC0;
    void* onHostDisconnect;
    int unkC8;
    DmeSessionCfg sess;
    int tail[4];
} NetJoinByNameCfg;
#if 0 /* merge_units */
extern int NetSetDefaultConnectParams(NetJoinByNameCfg* cfg);
#endif /* merge_units */
#define NetSetDefaultConnectParams(a0) (NetSetDefaultConnectParams((NetJoinCfg *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int NetConnect(NetJoinByNameCfg* cfg, DmeGameOut* out);
#endif /* merge_units */
#define NetConnect(a0, a1) (NetConnect((NetJoinCfg *)(a0), (a1))) /* merge_units */

extern char* strncpy(char* d, const char* s, unsigned int n);
/* same layout as NetworkGameAddress */
typedef struct DmeGameAddress { char name[0x10]; int value; } DmeGameAddress;
static inline void MemClear_n1_0042ACD0(void* d0, int n0) { int n = n0; void* dst = d0;
    asm {
        .set noreorder
        blez n, done
        nop
        andi $v1, dst, 0xF
        andi $v0, n, 0xF
        or $v1, $v1, $v0
        nop
        bgtz $v1, bytes
        srl $v0, n, 4
        nop
        blez $v0, bytes
        nop
        nop
    quads:
        addi $v0, $v0, -1
        sq $zero, 0(dst)
        bgtz $v0, quads
        addiu dst, dst, 0x10
        b done
        nop
    bytes:
        addi n, n, -1
        sb $zero, 0(dst)
        bgtz n, bytes
        addiu dst, dst, 1
    done:
        .set reorder
    }
}
/* Joins the game named by `host` (see DME_NextGameAddress). Returns nonzero on failure. */
int Net_ConnectGameByName(DmeGameAddress* host)
{
    DmeGameOut out;
    NetJoinByNameCfg cfg;
    int err;
    if (D_00494198 == 0x10) {
        NetSetSendAggregationInterval(0, 0x5A, 0x5A);
    } else {
        NetSetSendAggregationInterval(0, 0x3C, 0x3C);
    }
    NetSetDefaultConnectParams(&cfg);
    cfg.mode = 4;
    cfg.unk08 = 2;
    cfg.unk0C = 1;
    strncpy(cfg.name, host->name, 0x10);
    cfg.unk20 = host->value;
    cfg.onConnectResult = DME_OnConnectResult;
    cfg.onClientConnect = DME_OnClientConnect;
    cfg.onClientDisconnect = DME_OnClientDisconnect;
    cfg.onHostDisconnect = DME_OnHostDisconnect;
    MemClear_n1_0042ACD0(&cfg.sess, 0x54);
    cfg.sess.cb34 = cHeadSet_AudioPlayCallback;
    cfg.sess.unk10 = 1;
    cfg.sess.unk04 = 1;
    cfg.sess.cb2C = cHeadSet_AudioRecordCallback;
    cfg.sess.unk0C = 1;
    cfg.sess.unk14 = 1;
    cfg.sess.unk08 = 2;
    cfg.sess.unk20 = 2;
    cfg.sess.unk18 = 0x10;
    cfg.sess.unk24 = 0x10;
    cfg.sess.unk1C = 0x1F40;
    cfg.sess.unk28 = 0x1F40;
    err = NetConnect(&cfg, &out);
    if (err) {
        D_005721A8 = out.handle;
        D_005724B0 = DME_STATE_DISCONNECTED;
        if (Gui_GetScreenStack()) {
            GuiWidget_SendEvent(Gui_GetScreenStack(), Gui_GetScreenStack(), 0x1E, 0, (int)D_004BF9B8);
        }
    }
    return err;
}
#undef NetSetDefaultConnectParams /* merge_units */
#undef NetConnect /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0042ACD0 */
