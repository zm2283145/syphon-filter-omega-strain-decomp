/*
 * SFOGame/Source/gameSound: 5 files, 001C6D00-001C7120
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001C6D00 */
#pragma push /* merge_units */
#include "types.h"

typedef struct SndReq {
    char pad000[0x48];
    char partA[0x9C];
    char partB[0xAC];
} SndReq;

typedef struct SndMsg {
    void* vtbl;
    char pad004[0x1C];
    unsigned char immediate;
    char pad021[0x57];
    char partA[0x9C];
    char partB[0xAC];
} __attribute__((aligned(16))) SndMsg;

extern char g_Game[];
extern char D_004DAE10[];
extern char D_004DAE30[];
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721C0;
extern void cSndFx_ctor_int_charP_cGOBJP_int(SndReq* req, signed char kind, int a, int b, int c);
extern void SoundMsg_WrapAction(SndMsg* msg, SndReq* req);
extern void EffectMsg_WrapRequest(SndMsg* msg, SndReq* req);
extern void QueueMessage_cMessageR_cSystemP_int(SndMsg* msg, void* target, int flags);
extern void cFileMan_dtor(void* part, int flags);
extern void cMessage_dtor(SndMsg* msg, int flags);

static inline int Snd_Allowed(void) { return g_IsMultiplayer ? D_005721C0 : 1; }

void Global_PlaySnd_2(int channel, int a, int b) {
    SndMsg msg1;
    SndMsg msg2;
    SndReq req1;
    SndReq req2;
    if ((signed char)channel == 4) {
        cSndFx_ctor_int_charP_cGOBJP_int(&req1, (signed char)channel, a, b, 0);
        SoundMsg_WrapAction(&msg1, &req1);
        cFileMan_dtor(req1.partB, -1);
        cFileMan_dtor(req1.partA, -1);
        if (!g_IsMultiplayer || !Snd_Allowed()) msg1.immediate = 1;
        QueueMessage_cMessageR_cSystemP_int(&msg1, g_Game, 0);
        msg1.vtbl = D_004DAE10;
        cFileMan_dtor(msg1.partB, -1);
        cFileMan_dtor(msg1.partA, -1);
        cMessage_dtor(&msg1, 0);
    } else {
        cSndFx_ctor_int_charP_cGOBJP_int(&req2, (signed char)channel, a, b, 0);
        EffectMsg_WrapRequest(&msg2, &req2);
        cFileMan_dtor(req2.partB, -1);
        cFileMan_dtor(req2.partA, -1);
        if (!g_IsMultiplayer || !Snd_Allowed()) msg2.immediate = 1;
        QueueMessage_cMessageR_cSystemP_int(&msg2, g_Game, 0);
        msg2.vtbl = D_004DAE30;
        cFileMan_dtor(msg2.partB, -1);
        cFileMan_dtor(msg2.partA, -1);
        cMessage_dtor(&msg2, 0);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C6D00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C6D00 */

/* merge_units: begin func_001C6EA0 */
#pragma push /* merge_units */
void Global_PlaySnd(int chan, int a) {
    signed char channel = chan;
    SndMsg msg1;
    SndMsg msg3;
    SndReq req1;
    SndReq req2;
    SndMsg msg2;
    SndReq req3;
    SndReq req4;
    SndMsg msg4;
    if (channel == 4) {
        cSndFx_ctor_int_charP_cGOBJP_int(&req1, channel, a, 0, 0);
        SoundMsg_WrapAction(&msg1, &req1);
        cFileMan_dtor(req1.partB, -1);
        cFileMan_dtor(req1.partA, -1);
        msg1.immediate = 1;
        cSndFx_ctor_int_charP_cGOBJP_int(&req2, channel, a, 0, 0);
        SoundMsg_WrapAction(&msg2, &req2);
        QueueMessage_cMessageR_cSystemP_int(&msg2, g_Game, 0);
        msg2.vtbl = D_004DAE10;
        cFileMan_dtor(msg2.partB, -1);
        cFileMan_dtor(msg2.partA, -1);
        cMessage_dtor(&msg2, 0);
        cFileMan_dtor(req2.partB, -1);
        cFileMan_dtor(req2.partA, -1);
        msg1.vtbl = D_004DAE10;
        cFileMan_dtor(msg1.partB, -1);
        cFileMan_dtor(msg1.partA, -1);
        cMessage_dtor(&msg1, 0);
    } else {
        cSndFx_ctor_int_charP_cGOBJP_int(&req3, channel, a, 0, 0);
        EffectMsg_WrapRequest(&msg3, &req3);
        cFileMan_dtor(req3.partB, -1);
        cFileMan_dtor(req3.partA, -1);
        msg3.immediate = 1;
        cSndFx_ctor_int_charP_cGOBJP_int(&req4, channel, a, 0, 0);
        EffectMsg_WrapRequest(&msg4, &req4);
        QueueMessage_cMessageR_cSystemP_int(&msg4, g_Game, 0);
        msg4.vtbl = D_004DAE30;
        cFileMan_dtor(msg4.partB, -1);
        cFileMan_dtor(msg4.partA, -1);
        cMessage_dtor(&msg4, 0);
        cFileMan_dtor(req4.partB, -1);
        cFileMan_dtor(req4.partA, -1);
        msg3.vtbl = D_004DAE30;
        cFileMan_dtor(msg3.partB, -1);
        cFileMan_dtor(msg3.partA, -1);
        cMessage_dtor(&msg3, 0);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C6EA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C6EA0 */

/* merge_units: begin func_001C70D0 */
#pragma push /* merge_units */
#include "gameSound_types.h"

/*
 * Matched functions (byte-identical with the retail executable).
 * SetReverb script native.
 */


extern void snd_SetReverbDepth(int unk0, int level1, int level2);

/* SetReverb(level): passes the level in both value slots. */
int Script_SetReverb(SoundScriptArg* args) {
    volatile int arg = args[0].i; /* original stack temporary */
    int level = arg;
    snd_SetReverbDepth(1, level, level);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C70D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C70D0 */

/* merge_units: begin func_001C7100 */
#pragma push /* merge_units */
extern void nGameSound_StopAllQuips(int);

/* Script native: stops all quips. */
int Script_StopAllQuips(void) {
    nGameSound_StopAllQuips(0);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C7100(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C7100 */

/* merge_units: begin func_001C7120 */
#pragma push /* merge_units */
#pragma global_optimizer off
extern int cGOBJ_SOBJ_convert(void* p);
extern void nGameSound_PlayQuip_charP_cGOBJP_int(int a, int b, int c);
static inline void d6_quip(int c, void* o, int a) { int id = cGOBJ_SOBJ_convert(o); nGameSound_PlayQuip_charP_cGOBJP_int(a, id, c); }
int Script_PlayQuip_2(int* args)
{
    int a[1];
    int c[1];
    c[0] = args[2];
    a[0] = args[0];
    d6_quip(*(int*)c, (void*)args[1], *(int*)a);
    return 0;
}
static inline void merge_flush_func_001C7120(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C7120 */
