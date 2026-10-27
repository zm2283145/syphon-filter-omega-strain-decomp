/*
 * SFOGame/Source/Checkpoint: 6 files, 0022DED0-0022E240
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0022DED0 */
#pragma push /* merge_units */
#include "types.h"
#pragma mpwc_relax on
int Alloc_Lock(int);
int EnableIntc(int);
int cMessage_ctor_cMessageNameR(char **, char *);
int QueueMessage_cMessageR_cSystemP_int(char **, int, int);
int cMemMan_Allocate(int, int, char *, int);
int Libc_Strcpy(int, int);
int cMessage_dtor(char **, int);
int strlen(int);
int cNetObj_GetPlayer(int);
extern char D_004A6698;
extern char D_004DB8D0;
extern char D_004F7930;
extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;

void Global_SetPlayersCheckpoint(int arg1, int arg2) {
    struct { char * f50[9]; int f74; int f78[2]; } sl;
    int i;
    int p;
    int len;
    int buf;

    for (i = 0; i < 4; i++) {
        p = cNetObj_GetPlayer(i);
        if (p != 0) {
            len = strlen(arg2) + 1;
            if (g_ProfileLockEnabled != 0) {
                Alloc_Lock(9);
            }
            g_ProfileLockDepth += 1;
            buf = cMemMan_Allocate(0, len, &D_004A6698, 0x1E6);
            if (g_ProfileLockEnabled != 0) {
                EnableIntc(9);
            }
            g_ProfileLockDepth -= 1;
            Libc_Strcpy(buf, arg2);
            cMessage_ctor_cMessageNameR(sl.f50, &D_004F7930);
            sl.f50[0] = &D_004DB8D0;
            sl.f74 = arg1;
            sl.f78[0] = buf;
            QueueMessage_cMessageR_cSystemP_int(sl.f50, p, 0);
            sl.f50[0] = &D_004DB8D0;
            cMessage_dtor(sl.f50, 0);
        }
    }
}
static inline void merge_flush_func_0022DED0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0022DED0 */

/* merge_units: begin func_0022E030 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * SetCheckpoint script native.
 */

#include "Checkpoint_types.h"

#if 0 /* merge_units */
extern int Global_SetCheckpoint(int checkpoint, int object, int value);
#endif /* merge_units */
void Global_SetCheckpoint(); /* merge_units */


/* SetCheckpoint(checkpoint, object, value) */
int Script_SetCheckpoint(CheckpointScriptArg* args) {
    volatile int value = args[2].i; /* original stack temporary */
    int checkpoint = cPlayer_SOBJ_convert(args[0].i);
    int object = cGOBJ_SOBJ_convert(args[1].i);
    Global_SetCheckpoint(checkpoint, object, value);
    return 0;
}
static inline void merge_flush_func_0022E030(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0022E030 */

/* merge_units: begin func_0022E080 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


void Global_SetCheckpoint(char * arg0, int arg1, int arg2) {
    struct { char * f50[9]; int f74; int f78[2]; } sl;
    int temp_s0;
    int temp_s0_2;

    temp_s0 = strlen(arg2) + 1;
    if (g_ProfileLockEnabled != 0) {
        Alloc_Lock(9);
    }
    g_ProfileLockDepth += 1;
    temp_s0_2 = cMemMan_Allocate(0, temp_s0, &D_004A6698, 0x1D6);
    if (g_ProfileLockEnabled != 0) {
        EnableIntc(9);
    }
    g_ProfileLockDepth -= 1;
    Libc_Strcpy(temp_s0_2, arg2);
    cMessage_ctor_cMessageNameR(sl.f50, &D_004F7930);
    sl.f74 = arg1;
    sl.f78[0] = temp_s0_2;
    sl.f50[0] = &D_004DB8D0;
    QueueMessage_cMessageR_cSystemP_int(sl.f50, F_(arg0, 0x30, int), 0);
    sl.f50[0] = &D_004DB8D0;
    cMessage_dtor(sl.f50, 0);
}
static inline void merge_flush_func_0022E080(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0022E080 */

/* merge_units: begin func_0022E1A0 */
#pragma push /* merge_units */
typedef struct { char pad[0x30]; void* target; } S;
#if 0 /* merge_units */
void Global_ReSpawn(S* s); /* gsynth: defined below */
#endif /* merge_units */
void Global_ReSpawn(); /* merge_units */

/*
 * Matched functions (byte-identical with the retail executable).
 * ReSpawn script native.
 */


#if 0 /* merge_units */
extern int Global_ReSpawn(int checkpoint);
#endif /* merge_units */
void Global_ReSpawn(); /* merge_units */



/* ReSpawn(checkpoint) */
int Script_ReSpawn(CheckpointScriptArg* args) {
    Global_ReSpawn(cPlayer_SOBJ_convert(args[0].i));
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0022E1A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0022E1A0 */

/* merge_units: begin func_0022E1D0 */
#pragma push /* merge_units */
typedef struct { void* vtable; char pad[0x18]; int flags; char pad2[4]; int value; char pad3[8]; } Msg;

extern char D_004F7940[];
extern char D_004DB890[];
#if 0 /* merge_units */
extern void cMessage_ctor_cMessageNameR(Msg* m, void* type);
#endif /* merge_units */
#define cMessage_ctor_cMessageNameR(a0, a1) ((void)cMessage_ctor_cMessageNameR((char * *)(a0), (char *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void QueueMessage_cMessageR_cSystemP_int(Msg* m, void* target, int immediate);
#endif /* merge_units */
#define QueueMessage_cMessageR_cSystemP_int(a0, a1, a2) ((void)QueueMessage_cMessageR_cSystemP_int((char * *)(a0), (int)(a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(Msg* m, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) ((void)cMessage_dtor((char * *)(a0), (a1))) /* merge_units */

/* Sends a respawn message to the object's target. */
void Global_ReSpawn(S* s)
{
    Msg msg;
    cMessage_ctor_cMessageNameR(&msg, D_004F7940);
    msg.value = 0;
    msg.vtable = D_004DB890;
    msg.flags = 0x40;
    QueueMessage_cMessageR_cSystemP_int(&msg, s->target, 0);
    msg.vtable = D_004DB890;
    cMessage_dtor(&msg, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0022E1D0(void) {}
#undef cMessage_ctor_cMessageNameR /* merge_units */
#undef QueueMessage_cMessageR_cSystemP_int /* merge_units */
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0022E1D0 */

/* merge_units: begin func_0022E240 */
#pragma push /* merge_units */
#include "net_register_type.h"

typedef struct { int a; } Proto_0022E240;
extern char D_004F7958[];
extern void cRespawnMsg_RespawnMsgCallback(void);

NETREG_BEGIN(cRespawnMsg_InitNet, Proto_0022E240)
NETREG_FIELD(a, 4, 1)
NETREG_END(D_004F7958, cRespawnMsg_RespawnMsgCallback)
static inline void merge_flush_func_0022E240(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0022E240 */
