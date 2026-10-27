/*
 * SFOGame/Source/gameFrontEnd: 1 file, 002C99F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002C99F0 */
#pragma push /* merge_units */
#include "types.h"

typedef struct FlagMsg {
    void* vtbl;
    char pad04[0x1C];
    unsigned char flag;  /* 0x20 */
    char pad21[0xF];
} FlagMsg;

extern char g_Game[];
extern char D_004D97F0[];
extern void cPauseMusicMsg_ctor(FlagMsg* msg);
extern void QueueMessage_cMessageR_cSystemP_int(FlagMsg* msg, void* target, int flags);
extern void cMessage_dtor(FlagMsg* msg, int flags);

/* Broadcasts a flagged message. */
void cGameFrontEnd_PauseMusic(void) {
    FlagMsg msg;
    cPauseMusicMsg_ctor(&msg);
    msg.flag = 1;
    QueueMessage_cMessageR_cSystemP_int(&msg, g_Game, 1);
    msg.vtbl = D_004D97F0;
    cMessage_dtor(&msg, 0);
}
static inline void merge_flush_func_002C99F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002C99F0 */
