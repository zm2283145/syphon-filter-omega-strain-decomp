/*
 * SFOGame/Source/gameSound: 1 file, 001C6720
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001C6720 */
#pragma push /* merge_units */
#include "types.h"

typedef struct SoundRequest {
    char pad000[0x48];
    char partA[0x9C];   /* 0x048 */
    char partB[0xAC];   /* 0x0E4 */
} SoundRequest; /* size 0x190 */

typedef struct SoundMsg {
    void* vtbl;
    char pad004[0x74];
    char partA[0x9C];   /* 0x078 */
    char partB[0xAC];   /* 0x114 */
} SoundMsg; /* size 0x1C0 */

extern char g_Game[];
extern char D_004DAE10[];
extern void cSndFx_ctor_int_charP_cGOBJP_int(SoundRequest* req, int kind, int a, int b, int c);
extern void SoundMsg_WrapAction(SoundMsg* msg, SoundRequest* req);
extern void QueueMessage_cMessageR_cSystemP_int(SoundMsg* msg, void* target, int flags);
extern void cFileMan_dtor(void* part, int flags);
extern void cMessage_dtor(SoundMsg* msg, int flags);

/* Builds a quip sound request and broadcasts it as a sound message. */
void nGameSound_PlayQuip_charP_cGOBJP_int(int a, int b, int c) {
    SoundMsg msg;
    SoundRequest req;
    cSndFx_ctor_int_charP_cGOBJP_int(&req, 4, a, b, c);
    SoundMsg_WrapAction(&msg, &req);
    QueueMessage_cMessageR_cSystemP_int(&msg, g_Game, 0);
    msg.vtbl = D_004DAE10;
    cFileMan_dtor(msg.partB, -1);
    cFileMan_dtor(msg.partA, -1);
    cMessage_dtor(&msg, 0);
    cFileMan_dtor(req.partB, -1);
    cFileMan_dtor(req.partA, -1);
}
static inline void merge_flush_func_001C6720(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C6720 */
