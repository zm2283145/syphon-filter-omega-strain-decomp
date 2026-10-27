/*
 * SFOGame/Source/gameSound: 1 file, 001C7340
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001C7340 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { void* vt; char pad[0x20]; int id; int arg; char pad2c[4]; } Msg_7340;
int cMessage_ctor_cMessageNameR(Msg_7340*, void*);
int cNetMsg_GetInt(int*);
int cMessage_dtor(Msg_7340*, int);
void* nGlobalization_GetStringTag(int);
int Voice_PlayQuip(void*, int, int);
extern char D_004DCF10[];
extern char D_004DAC70[];
extern char D_004F2D00[];

/* net message handler: read quip id and argument, play the quip if it resolves */
void cPlayQuipMsg_NetReceive(void)
{
    Msg_7340 m;
    void* p;
    cMessage_ctor_cMessageNameR(&m, D_004F2D00);
    m.vt = D_004DAC70;
    cNetMsg_GetInt(&m.id);
    cNetMsg_GetInt(&m.arg);
    p = (m.id != -1) ? nGlobalization_GetStringTag(m.id) : 0;
    if (p) Voice_PlayQuip(p, m.arg, 1);
    m.vt = D_004DCF10;
    cMessage_dtor(&m, 0);
}
static inline void merge_flush_func_001C7340(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001C7340 */
