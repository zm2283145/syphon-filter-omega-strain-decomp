#ifndef DME_H
#define DME_H
/*
 * DME ("DME.cc"): network game layer on top of the DME networking library.
 * Runs a worker thread (DME_ThreadMain) that is woken every 100 Timer0 ticks
 * by DME_TimerHandler and polls the network (DME_Update). Connection
 * callbacks (DME_On*) are registered with NetGame_Create / Net_ConnectGame.
 *
 * Shared globals (declared per file because their extern types differ):
 *   D_005724B0  connection state, DmeConnState
 *   D_005721A8  network session handle
 *   D_005721C0  this machine is the host (set when NetGame_Create succeeds)
 *   g_IsMultiplayer  online flag
 *   D_005723C8  network-callback busy byte (set on entry, cleared on exit)
 *   D_005721D8  disconnect pending; reason string in D_005721E0[16]
 *   D_005723F0  connected client count
 *   D_00572418  per-client "disconnected" flags, indexed by client id
 *   D_00572428  per-client level-info send state (== g_DmeClientLevelInfo[1..3])
 *   D_00572528  DME thread running
 *   D_00572538  Timer0 tick counter (incremented by DME_TimerHandler)
 */

/* D_005724B0 */
enum DmeConnState {
    DME_STATE_CONNECTING = 5,
    DME_STATE_CONNECTED = 6,
    DME_STATE_DISCONNECTED = 7, /* connect failed or connection lost */
    DME_STATE_JOINING = 8,
    DME_STATE_JOIN_WAIT = 9,    /* client: waiting for the host to accept */
    DME_STATE_JOINED = 10,
    DME_STATE_JOIN_FAILED = 11
};

/* g_DmeClientLevelInfo / D_00572428: a NetLevelInfoMsg must be sent to this client */
#define DME_LEVELINFO_PENDING 0x0FFFFFFE

/* Interrupt controller line of EE Timer 0 (also passed to Alloc_Lock/Alloc_Unlock). */
#define INTC_TIM0 9

/* EE Timer 0 registers */
#define T0_COUNT (*(volatile int*)0x10000000)
#define T0_MODE (*(volatile int*)0x10000010)
#define T0_COMP (*(volatile int*)0x10000020)
#define T0_MODE_EQUF 0x400 /* compare-match interrupt flag (write 1 to clear) */

/* Kernel ThreadParam, filled by ReferThreadStatus (0x30 bytes). */
typedef struct EeThreadParam {
    /* 0x00 */ int status;
    /* 0x04 */ void* entry;
    /* 0x08 */ void* stack;
    /* 0x0C */ int stackSize;
    /* 0x10 */ void* gp;
    /* 0x14 */ int initPriority;
    /* 0x18 */ int currentPriority;
    /* 0x1C */ char pad1C[0x14];
} EeThreadParam;

/* Session options embedded in the create/join configs (cleared with a 0x54-byte memclear). */
typedef struct DmeSessionCfg {
    /* 0x00 */ int unk00;
    /* 0x04 */ int unk04;
    /* 0x08 */ int unk08;
    /* 0x0C */ int unk0C;
    /* 0x10 */ int unk10;
    /* 0x14 */ int unk14;
    /* 0x18 */ int unk18;
    /* 0x1C */ int unk1C;
    /* 0x20 */ int unk20;
    /* 0x24 */ int unk24;
    /* 0x28 */ int unk28;
    /* 0x2C */ void* cb2C;
    /* 0x30 */ int unk30;
    /* 0x34 */ void* cb34;
    /* 0x38 */ int pad[7];
} DmeSessionCfg;

/* Result of NetGame_Create / the join call; handle is valid on failure too. */
typedef struct DmeGameOut {
    /* 0x0 */ int unk0;
    /* 0x4 */ int unk4;
    /* 0x8 */ int handle;
    /* 0xC */ int unkC;
} DmeGameOut;

#endif
