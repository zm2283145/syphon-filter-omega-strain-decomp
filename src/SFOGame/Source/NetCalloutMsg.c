/*
 * SFOGame/Source/NetCalloutMsg: 1 file, 002C5270
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin GuiEquipmentModify_2C5270 */
#pragma push /* merge_units */
#include "types.h"
typedef struct {
    unsigned char a, b, c;
    int d;
    int e;
    int f;
    int g;
    int h;
} Cfg5270;
extern int NetRegisterMessageStart(void);
extern int cMessage_RegisterFields(void* f);
extern int NetMessageField(void* f, void* buf, int size, int count);
extern int NetRegisterMessage(void* t, int id, void* fn);
extern char D_0051EE40[];
extern void cNetCalloutMsg_NetCalloutMsgCallback(void);
unsigned char cNetCalloutMsg_InitNet(void)
{
    struct { long long file; Cfg5270 cfg; } L;
    unsigned char ok = 0;
    if (NetRegisterMessageStart() == 0 && cMessage_RegisterFields(&L.file) &&
        NetMessageField(&L.file, &L.cfg.a, 1, 1) == 0 &&
        NetMessageField(&L.file, &L.cfg.e, 4, 1) == 0 &&
        NetMessageField(&L.file, &L.cfg.f, 4, 1) == 0 &&
        NetMessageField(&L.file, &L.cfg.h, 4, 1) == 0 &&
        NetMessageField(&L.file, &L.cfg.g, 4, 1) == 0 &&
        NetMessageField(&L.file, &L.cfg.b, 1, 1) == 0 &&
        NetMessageField(&L.file, &L.cfg.c, 1, 1) == 0 &&
        NetMessageField(&L.file, &L.cfg.d, 4, 1) == 0 &&
        NetRegisterMessage(D_0051EE40, 2, cNetCalloutMsg_NetCalloutMsgCallback) == 0)
        ok = 1;
    return ok;
}
static inline void merge_flush_GuiEquipmentModify_2C5270(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiEquipmentModify_2C5270 */
