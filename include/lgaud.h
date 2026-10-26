#ifndef LGAUD_H
#define LGAUD_H

/*
 * liblgaud: EE-side client of lgaud.irx (USB headset audio, used for voice
 * chat). Every API call takes the library semaphore, fills the shared RPC
 * packet (lgAud_pkt), calls the IRX through sceSifCallRpc and returns the
 * result the IRX wrote to pkt->ret, or one of the LGAUD_ERR_* codes below.
 * The A* variants (lgAudARead/AWrite/AWriteVag) are asynchronous: they keep
 * the semaphore and release it from their completion callback; lgAudSync
 * waits for / polls that.
 * Plain C for ee-gcc.
 */

#include "sif_rpc_types.h"

/* return codes */
#define LGAUD_ERR_RPC_FAILED        0x80000000 /* sceSifCallRpc failed */
#define LGAUD_ERR_INVALID_PARAMETER 0x80000004
#define LGAUD_ERR_BUSY              0x80000008 /* another async call is in progress */
#define LGAUD_ERR_NOT_INITIALIZED   0x8000000A /* lgAudInit not called (lgAud_sema == -1) */

/* lgaud.irx RPC function numbers (sceSifCallRpc rpc_number) */
enum {
    LGAUD_RPC_ENUMERATE = 1,
    LGAUD_RPC_OPEN = 2,
    LGAUD_RPC_CLOSE = 3,
    LGAUD_RPC_START_RECORDING = 4,
    LGAUD_RPC_STOP_RECORDING = 5,
    LGAUD_RPC_START_PLAYBACK = 6,
    LGAUD_RPC_STOP_PLAYBACK = 7,
    LGAUD_RPC_READ = 8,
    LGAUD_RPC_WRITE = 9,
    LGAUD_RPC_GET_MIXER = 0xB,
    LGAUD_RPC_SET_MIXER = 0xC,
    LGAUD_RPC_SET_LEVEL_0D = 0xD,
    LGAUD_RPC_SET_LEVEL_0E = 0xE,
    LGAUD_RPC_RESUME_PLAYBACK = 0x11,
    LGAUD_RPC_GET_AVAILABLE_RECORDING_BYTES = 0x12,
    LGAUD_RPC_GET_REMAINING_PLAYBACK_BYTES = 0x13,
    LGAUD_RPC_PREPARE_FOR_REBOOT = 0x14,
    LGAUD_RPC_WRITE_VAG = 0x15,
    LGAUD_RPC_DEINIT = 0x16
};

/* sceSifCallRpc mode */
#define LGAUD_RPC_SYNC  0
#define LGAUD_RPC_ASYNC 1 /* SIF_RPC_M_NOWAIT */

/* Read/write RPCs receive/send 0x30 header bytes plus the data, rounded up to 16 */
#define LGAUD_XFER_SIZE(len) ((((len) + 0x3F) >> 4) << 4)

/*
 * Stream format for one direction. Field meanings follow the values the game
 * passes (cHeadSet_DetectAndSetupUSB: 1/16/8000/200 and 2/16/8000/400).
 */
typedef struct lgAudFormat {
    unsigned char channels;       /* +0x00 (1, 2) */
    unsigned char bits;           /* +0x01 (16) */
    unsigned short sampleRate;    /* +0x02 (8000) */
    unsigned short bufferMs;      /* +0x04 (200, 400) - probably buffer length */
} lgAudFormat; /* 0x06 */

typedef struct lgAudOpenParam {
    unsigned char Mode;           /* +0x00 must be nonzero (game: 3) */
    char pad01;                   /* +0x01 */
    lgAudFormat recording;        /* +0x02 */
    lgAudFormat playback;         /* +0x08 */
} lgAudOpenParam; /* 0x0E */

/* Mixer settings exchanged by lgAudGetMixer/SetMixer; only v[6] is read back. */
typedef struct lgAudMixer {
    short v[8];                   /* +0x00 */
} lgAudMixer; /* 0x10 */

/* Device description returned by lgAudEnumerate. */
typedef struct lgAudInfo {
    int w[83];                    /* +0x00 */
} lgAudInfo; /* 0x14C */

/* The shared RPC packet (send and receive buffer), lgAud_pkt. */
typedef struct lgAudRpcPkt {
    int ret;                      /* +0x00 IRX result */
    int unk04;                    /* +0x04 */
    int arg;                      /* +0x08 lgAudOpen: type, lgAudEnumerate: index */
    int device;                   /* +0x0C */
    unsigned char param0;         /* +0x10 lgAudSetLevel0D/0E */
    unsigned char param1;         /* +0x11 lgAudSetLevel0D/0E */
    unsigned char flag;           /* +0x12 read/write flag */
    char pad13;                   /* +0x13 */
    int unk14[3];                 /* +0x14 */
    union {
        int size;                 /* +0x20 read/write length; returned byte counts */
        lgAudOpenParam open;      /* +0x20 lgAudOpen */
        lgAudMixer mixer;         /* +0x20 lgAudGetMixer/SetMixer */
        lgAudInfo info;           /* +0x20 lgAudEnumerate result */
        int i[4];
    } u;
    /* +0x30 read/write data (LGAUD_PKT_DATA) */
} lgAudRpcPkt; /* 0x30 header + data (enumerate replies use 0x170) */

#define LGAUD_PKT_DATA(pkt) ((char *)(pkt) + 0x30)

/* Async read/write bookkeeping filled before the call, completed by the callback. */
typedef struct lgAudAsyncReq {
    void *buf;                    /* +0x00 read: destination, write: source */
    int *len;                     /* +0x04 receives the transferred length */
    int ret;                      /* +0x08 receives pkt->ret; read by lgAudSync */
} lgAudAsyncReq;

/*
 * Library globals. They keep their splat names (they are defined by the
 * generated src/data files / the linker), these aliases name them.
 */
extern int D_0049146C;
extern int D_00491470;
extern lgAudRpcPkt *D_00491474;
extern int *D_00491478;
extern int D_0049147C;
extern void (*D_00491484)(int);
extern SifRpcClientData D_0052AD00;
extern char D_0052AD40[];
extern lgAudAsyncReq D_0052AEB0;

#define lgAud_maxDataSize D_0049146C /* "lgAudInit: max streaming data size: %d" */
#define lgAud_heapBuf     D_00491470 /* buffer allocated by lgAudInit, freed by lgAudDeInit */
#define lgAud_pkt         D_00491474
#define lgAud_enumHint    D_00491478 /* device-change hint, read and cleared by lgAudEnumHint */
#define lgAud_sema        D_0049147C /* -1 until lgAudInit */
#define lgAud_freeFunc    D_00491484 /* free callback passed to lgAudInit */
#define lgAud_cd          D_0052AD00
#define lgAud_deinitPkt   D_0052AD40
#define lgAud_asyncReq    D_0052AEB0

/* SDK calls used by the library */
extern int DeleteSema(int sema);
extern int SignalSema(int sema);
extern int iSignalSema(int sema);
extern int WaitSema(int sema);
extern int sceSifCallRpc(void *cd, int rpc, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *param);
extern int sceSifCheckStatRpc(void *cd);
extern int printf(const char *fmt, ...);
extern void *memcpy(void *, const void *, unsigned int);

/* API */
int lgAudEnumHint(int *hint);
int lgAudEnumerate(int idx, lgAudInfo *info);
int lgAudOpen(int type, lgAudOpenParam *openparam, int *device);
int lgAudClose(int device);
int lgAudStartRecording(int device);
int lgAudStopRecording(int device);
int lgAudStartPlayback(int device);
int lgAudStopPlayback(int device);
int lgAudResumePlayback(int device);
int lgAudRead(int device, int flag, void *dest, int *len);
int lgAudWrite(int device, int flag, void *src, int *len);
int lgAudWriteVag(int device, int flag, void *src, int *len);
int lgAudARead(int device, int flag, void *dest, int *len);
int lgAudAWrite(int device, int flag, void *src, int *len);
int lgAudAWriteVag(int device, int flag, void *src, int *len);
int lgAudGetMixer(int device, lgAudMixer *mr);
int lgAudSetMixer(int device, lgAudMixer *mr);
int lgAudSetLevel0D(int device, unsigned char a, unsigned char b);
int lgAudSetLevel0E(int device, unsigned char a, unsigned char b);
int lgAudGetAvailableRecordingBytes(int device, int *bytes);
int lgAudGetRemainingPlaybackBytes(int device, int *bytes);
int lgAudPrepareForReboot(void);
int lgAudSync(int poll, int *result);
int lgAudDeInit(void);
void lgAudAReadCallback(lgAudAsyncReq *req);
void lgAudAWriteCallback(lgAudAsyncReq *req);

#endif /* LGAUD_H */
