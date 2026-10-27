/*
 * SFOGame/Source/NetObjectiveMsg: 2 files, 002D74A0-002D7580
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002D74A0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { int h0; int h4; unsigned char b8; int iC; int i10; char name[16]; } F6ObjNet;
extern int NetRegisterMessageStart(void);
extern int cMessage_RegisterFields(F6ObjNet*);
extern int NetMessageField(F6ObjNet*, void*, int, int);
extern int NetRegisterMessage(void*, int, void*);
extern char D_0051F0B8[];
extern void cNetObjectiveMsg_ObjectiveMsgCallback(void);
unsigned char cNetObjectiveMsg_InitNet(void)
{
    F6ObjNet s;
    int err;
    unsigned char ok = 0;
    err = NetRegisterMessageStart();
    if (err == 0 && cMessage_RegisterFields(&s) && err == 0
        && NetMessageField(&s, &s.iC, 4, 1) == 0
        && NetMessageField(&s, &s.b8, 1, 1) == 0
        && NetMessageField(&s, &s.i10, 4, 1) == 0
        && NetMessageField(&s, s.name, 1, 16) == 0
        && NetRegisterMessage(D_0051F0B8, 2, cNetObjectiveMsg_ObjectiveMsgCallback) == 0) {
        ok = 1;
    }
    return ok;
}
static inline void merge_flush_func_002D74A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D74A0 */

/* merge_units: begin func_002D7580 */
#pragma push /* merge_units */
typedef struct { char pad[0x2C]; signed char type; char pad2d[3]; int id; int value; char name[0x10]; } ObjEvt_e1;
typedef struct { char pad[8]; signed char type; char pad9[3]; int id; int value; char name[0x10]; } ObjPkt_e1;
#if 0 /* merge_units */
extern int D_0051F0B8;
#endif /* merge_units */
#define D_0051F0B8 (*(int*)&D_0051F0B8) /* merge_units */

extern int Event_PackHeader(ObjEvt_e1*, int, int*, int, int, unsigned int, char*);
extern char* strncpy(char*, const char*, unsigned int);
int cNetObjectiveMsg_Pack(ObjEvt_e1* self, int recv, int* outSize, int a3, int a4, unsigned int cap, char* buf)
{
    int ret = -1;
    ObjPkt_e1* p;
    if (cap >= 0x24 && buf != 0) {
        p = (ObjPkt_e1*)buf;
        Event_PackHeader(self, recv, outSize, a3, a4, cap, buf);
        p->id = self->id;
        p->type = self->type;
        p->value = self->value;
        strncpy(p->name, self->name, 0x10);
        if (outSize != 0) {
            ret = 0x24;
            *outSize = D_0051F0B8;
        }
    }
    return ret;
}
#undef D_0051F0B8 /* merge_units */
static inline void merge_flush_func_002D7580(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D7580 */
