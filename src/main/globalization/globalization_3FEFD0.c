/*
 * main/globalization: 3 files, 003FEFD0-003FF140
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003FEFD0 */
#pragma push /* merge_units */
#include "types.h"
extern void func_003FDEE0(void* self, short del);
extern void operator_delete(void* p);
void* func_003FEFD0(void* self, short del)
{
    if (self) {
        if (self)
            func_003FDEE0(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_003FEFD0 */

/* merge_units: begin func_003FF030 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "message_clone.h"

extern "C" char D_004E0840[];

struct Msg_0021C830 : ClonedMessageBase {
    int a24;
    char b28;
};

#define CLONE_BODY(p, s) p->vtable = D_004E0840; p->a24 = s->a24; p->b28 = s->b28;

extern "C" { char D_004BE550[] = "charActionMsg.hh"; }
DEFINE_MESSAGE_CLONE(func_003FF030, Msg_0021C830, 0x2C, D_004BE550, 0x98, CLONE_BODY)
#pragma pop /* merge_units */
/* merge_units: end func_003FF030 */

/* merge_units: begin func_003FF140 */
#pragma push /* merge_units */
#pragma push
#pragma opt_propagation off
#pragma opt_common_subs off
typedef struct PkFF140 { int kind, id; unsigned char action, on; } PkFF140;
typedef struct MsgFF140 { void* vt; char p4[0x20]; int action; unsigned char on; char p29[3]; } MsgFF140;
extern unsigned char D_005723C8, D_005721D0;
extern char D_0055D480[], D_004E0840[];
void cMessage_ctor5(MsgFF140*, void*, PkFF140*);
void** NetMap_Lookup(int);
void MsgQueue_QueueClone(MsgFF140*, void*, int, int);
void cMessage_dtor(MsgFF140*, int);
int func_003FF140(int a, int b, int c, PkFF140* p0) {
    MsgFF140 msg;
    PkFF140* p;
    if (!D_005723C8) D_005723C8 = 1;
    p = p0;
    if (D_005721D0) {
        void** obj;
        cMessage_ctor5(&msg, D_0055D480, p);
        msg.vt = D_004E0840;
        msg.action = p->action;
        msg.on = p->on;
        obj = NetMap_Lookup(p->id);
        if (obj) MsgQueue_QueueClone(&msg, *obj, 0, 0);
        msg.vt = D_004E0840;
        cMessage_dtor(&msg, 0);
    }
    D_005723C8 = 0;
    return 0xC;
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_003FF140 */
