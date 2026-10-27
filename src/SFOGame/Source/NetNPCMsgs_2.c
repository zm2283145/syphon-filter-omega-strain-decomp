/*
 * SFOGame/Source/NetNPCMsgs: 1 file, 002D7020
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002D7020 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { int h0; int h4; unsigned char b8; int iC; int i10; char name[1]; } F6ObjNet;
extern int NetRegisterMessageStart(void);
extern int cMessage_RegisterFields(F6ObjNet*);
extern int NetMessageField(F6ObjNet*, void*, int, int);
extern int NetRegisterMessage(void*, int, void*);
extern char D_0051F0A0[];
extern void cNetNPCMsgs_NetNPCMsgsCallback(void);
unsigned char cNetNPCMsgs_InitNet(void)
{
    F6ObjNet s;
    int err;
    unsigned char ok = 0;
    err = NetRegisterMessageStart();
    if (err == 0 && cMessage_RegisterFields(&s) && err == 0
        && NetMessageField(&s, &s.b8, 1, 1) == 0 && NetMessageField(&s, &s.iC, 4, 1) == 0 && NetMessageField(&s, &s.i10, 4, 1) == 0 && NetMessageField(&s, s.name, 4, 1) == 0
        && NetRegisterMessage(D_0051F0A0, 2, cNetNPCMsgs_NetNPCMsgsCallback) == 0) {
        ok = 1;
    }
    return ok;
}
static inline void merge_flush_func_002D7020(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D7020 */
