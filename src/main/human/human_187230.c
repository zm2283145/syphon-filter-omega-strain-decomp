/*
 * main/human: range (2 files, 00187230-001872F0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00187230 */
#pragma push /* merge_units */
typedef struct { void* vtable; char base[0x20]; int id; unsigned char a; signed char b; char pad2A[6]; } Msg_187230;
extern char D_004EF008[];
extern char D_004DA990[];
extern char D_004DCF10[];
extern signed char* D_005061D0;
extern void Event_Construct(Msg_187230* msg, void* name);
extern void cMessage_dtor(Msg_187230* msg, int flags);
extern void NetStream_ReadObject(int* out);
extern void Actor_RecordDeathStats(void* self, int id, int a, int b);
static inline void ReadU8_187230(unsigned char* out) { signed char v = *D_005061D0; D_005061D0++; *out = v; }
static inline void ReadS8_187230(signed char* out) { signed char v = *D_005061D0; D_005061D0++; *out = v; }
void cNetUpdateStatsMsg_NetReceive(void* self)
{
    Msg_187230 msg;
    Event_Construct(&msg, D_004EF008);
    msg.vtable = D_004DA990;
    NetStream_ReadObject(&msg.id);
    ReadU8_187230(&msg.a);
    ReadS8_187230(&msg.b);
    Actor_RecordDeathStats(self, msg.id, msg.a, msg.b);
    msg.vtable = D_004DCF10;
    cMessage_dtor(&msg, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00187230(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00187230 */

/* merge_units: begin func_001872F0 */
#pragma push /* merge_units */
typedef struct {
    char p0[0x40];
    float f40;
    char p44[0x320C - 0x44];
    int state;
    char p3210[0x33A5 - 0x3210];
    unsigned char b33A5;
} S_1872F0;
int Actor_GetLifeState(S_1872F0* p) {
    if (p->b33A5 || p->state == 0x1F)
        return 3;
    if (p->state == 0x1B)
        return 2;
    return (int)p->f40 ? 0 : 3;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001872F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001872F0 */
