/*
 * main/gameSound: range (2 files, 001C6D00-001C6EA0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_001C6D00 */
#pragma push /* merge_units */
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

extern char D_004FFB50[];
extern char D_004DAE10[];
extern char D_004DAE30[];
extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
extern void SoundRequest_Ctor(SndReq* req, signed char kind, int a, int b, int c);
extern void SoundMsg_WrapAction(SndMsg* msg, SndReq* req);
extern void EffectMsg_WrapRequest(SndMsg* msg, SndReq* req);
extern void Event_Send(SndMsg* msg, void* target, int flags);
extern void FileMan_Release(void* part, int flags);
extern void cMessage_dtor(SndMsg* msg, int flags);

static inline int Snd_Allowed(void) { return D_005721C8 ? D_005721C0 : 1; }

void Global_PlaySnd_2(int channel, int a, int b) {
    SndMsg msg1;
    SndMsg msg2;
    SndReq req1;
    SndReq req2;
    if ((signed char)channel == 4) {
        SoundRequest_Ctor(&req1, (signed char)channel, a, b, 0);
        SoundMsg_WrapAction(&msg1, &req1);
        FileMan_Release(req1.partB, -1);
        FileMan_Release(req1.partA, -1);
        if (!D_005721C8 || !Snd_Allowed()) msg1.immediate = 1;
        Event_Send(&msg1, D_004FFB50, 0);
        msg1.vtbl = D_004DAE10;
        FileMan_Release(msg1.partB, -1);
        FileMan_Release(msg1.partA, -1);
        cMessage_dtor(&msg1, 0);
    } else {
        SoundRequest_Ctor(&req2, (signed char)channel, a, b, 0);
        EffectMsg_WrapRequest(&msg2, &req2);
        FileMan_Release(req2.partB, -1);
        FileMan_Release(req2.partA, -1);
        if (!D_005721C8 || !Snd_Allowed()) msg2.immediate = 1;
        Event_Send(&msg2, D_004FFB50, 0);
        msg2.vtbl = D_004DAE30;
        FileMan_Release(msg2.partB, -1);
        FileMan_Release(msg2.partA, -1);
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
        SoundRequest_Ctor(&req1, channel, a, 0, 0);
        SoundMsg_WrapAction(&msg1, &req1);
        FileMan_Release(req1.partB, -1);
        FileMan_Release(req1.partA, -1);
        msg1.immediate = 1;
        SoundRequest_Ctor(&req2, channel, a, 0, 0);
        SoundMsg_WrapAction(&msg2, &req2);
        Event_Send(&msg2, D_004FFB50, 0);
        msg2.vtbl = D_004DAE10;
        FileMan_Release(msg2.partB, -1);
        FileMan_Release(msg2.partA, -1);
        cMessage_dtor(&msg2, 0);
        FileMan_Release(req2.partB, -1);
        FileMan_Release(req2.partA, -1);
        msg1.vtbl = D_004DAE10;
        FileMan_Release(msg1.partB, -1);
        FileMan_Release(msg1.partA, -1);
        cMessage_dtor(&msg1, 0);
    } else {
        SoundRequest_Ctor(&req3, channel, a, 0, 0);
        EffectMsg_WrapRequest(&msg3, &req3);
        FileMan_Release(req3.partB, -1);
        FileMan_Release(req3.partA, -1);
        msg3.immediate = 1;
        SoundRequest_Ctor(&req4, channel, a, 0, 0);
        EffectMsg_WrapRequest(&msg4, &req4);
        Event_Send(&msg4, D_004FFB50, 0);
        msg4.vtbl = D_004DAE30;
        FileMan_Release(msg4.partB, -1);
        FileMan_Release(msg4.partA, -1);
        cMessage_dtor(&msg4, 0);
        FileMan_Release(req4.partB, -1);
        FileMan_Release(req4.partA, -1);
        msg3.vtbl = D_004DAE30;
        FileMan_Release(msg3.partB, -1);
        FileMan_Release(msg3.partA, -1);
        cMessage_dtor(&msg3, 0);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001C6EA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001C6EA0 */
