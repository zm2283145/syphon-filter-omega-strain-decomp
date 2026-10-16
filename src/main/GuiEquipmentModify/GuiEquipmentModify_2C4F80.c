/*
 * main/GuiEquipmentModify: 2 files, 002C4F80-002C50E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002C4F80 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
typedef struct { char c[16]; } N2C4;
typedef struct { void* vt; int f4, f8, fc, f10, f14, f18, f1c; signed char b20; char p21[3]; signed char b24; char p25[3]; int f28; float f2c; float f30; N2C4 name; int f44; unsigned char b48; unsigned char b49; char p4a[2]; } M2C4;
extern "C" {
extern void* Mem_Alloc(int, int, char*, int);
extern char D_004DFD80[];
extern char D_004DE0F0[];
}
extern "C" M2C4* func_002C4F80(M2C4* src) {
    M2C4* m;
    {
        AllocGuard g;
        m = (M2C4*)Mem_Alloc(0, 0x4C, "NetCalloutMsg.hh", 0x26);
    }
    if (m) {
        m->vt = D_004DFD80;
        m->f4 = src->f4;
        m->f8 = src->f8;
        m->fc = src->fc;
        m->f10 = src->f10;
        m->f14 = src->f14;
        m->f18 = src->f18;
        m->f1c = src->f1c;
        m->b20 = src->b20;
        m->vt = D_004DE0F0;
        m->b24 = src->b24;
        m->f28 = src->f28;
        m->f2c = src->f2c;
        m->f30 = src->f30;
        m->name = src->name;
        m->f44 = src->f44;
        m->b48 = src->b48;
        m->b49 = src->b49;
    }
    return m;
}
#pragma pop /* merge_units */
/* merge_units: end func_002C4F80 */

/* merge_units: begin func_002C50E0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "net_recv_guard.h"
typedef struct { int f0; int f4; signed char f8; unsigned char f9; unsigned char fA; char pB; int fC; int f10; float f14; float f18; int f1C; } Pk2C50E0;
typedef struct { void* vt; char p4[0x24]; int f28; float f2C; float f30; char name[16]; int f44; unsigned char b48; unsigned char b49; char p4A[2]; } Msg2C50E0;
extern "C" {
extern unsigned char D_005721D0;
extern char D_0051EE48[], D_004DE0F0[];
extern void *D_004FFC2C;
extern void Event_Construct(Msg2C50E0* e, void* type);
extern char *Loc_GetStoredKey(int);
extern char *strncpy(char *, const char *, unsigned int);
extern void Hud_SetCalloutLabel(void *, int *, char *, int, float, float, unsigned char, unsigned char, int);
extern void Hud_ClearCallout(void *, int *, int, unsigned char, int);
extern void cMessage_dtor(Msg2C50E0*, int);
}
#pragma push
#pragma opt_propagation off
extern "C" int func_002C50E0(int a0, int a1, int a2, Pk2C50E0* arg) {
    NetRecvGuard g;
    if (D_005721D0) {
        Msg2C50E0 msg;
        Pk2C50E0* p = arg;
        Msg2C50E0* m = &msg;
        Event_Construct(m, D_0051EE48);
        msg.vt = D_004DE0F0;
        msg.f28 = -1;
        msg.f28 = p->f10;
        msg.f2C = p->f14;
        msg.f30 = p->f18;
        msg.f44 = p->f1C;
        msg.b48 = p->f9;
        msg.b49 = p->fA;
        strncpy(m->name, Loc_GetStoredKey(p->fC), 0x10);
        if (p->f8 == 0) {
            Hud_SetCalloutLabel(D_004FFC2C, &msg.f28, msg.name, msg.f44, msg.f2C, msg.f30, msg.b48, msg.b49, 0);
        } else {
            Hud_ClearCallout(D_004FFC2C, &msg.f28, msg.f44, msg.b48, 0);
        }
        msg.vt = D_004DE0F0;
        cMessage_dtor(&msg, 0);
    }
    return 0x20;
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_002C50E0 */
