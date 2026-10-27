/*
 * main/NetMsgThrottle: 3 files, 00476620-00476740
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00476620 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cActivateBodyTossMsg method; address lies after NetMsgThrottle.cc (ends 0x00472370).
 */

#include "types.h"

extern int D_00588040;

int cActivateBodyTossMsg_v05(void) {
    return D_00588040;
}
#pragma pop /* merge_units */
/* merge_units: end func_00476620 */

/* merge_units: begin func_00476630 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "net_msg_clone.h"
#define NMC_UB(off) (*(unsigned char*)((char*)p + (off)) = *(unsigned char*)((char*)self + (off)))
#define NMC_F(off) (*(float*)((char*)p + (off)) = *(float*)((char*)self + (off)))
extern "C" { char D_004C36D0[] = "activateBodyTossMsg.hh"; }
DEFINE_NET_MSG_CLONE(cActivateBodyTossMsg_v01, 0x28, D_004C36D0, 0x23, D_004E1AE0, NMC_UB(0x24))
#pragma pop /* merge_units */
/* merge_units: end func_00476630 */

/* merge_units: begin func_00476740 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Msg476740 { void* vtable; char base[0x18]; int f1C; unsigned char b20; char p21[3]; unsigned char b24; char p25[0xB]; };
union Arg476740 { int i; float f; void* p; };
extern "C" {
extern char D_00588038[];
extern char D_004E1AE0[];
extern char D_004DCF10[];
void* cGOBJ_SOBJ_convert(void* id);
void cMessage_ctor_cMessageNameR(void* m, void* type);
void QueueMessage_cMessageR_cSystemP_int(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
}
extern "C" int Script_ActivateBodyToss_2(Arg476740* args) {
    bool on;
void* target;
Msg476740 t;
Msg476740 m;
    on = args[1].i != 0;
    target = cGOBJ_SOBJ_convert(args[0].p);
    cMessage_ctor_cMessageNameR(&t, D_00588038);
    t.vtable = D_004E1AE0;
    t.b24 = on;
    t.b20 = 8;
    t.f1C = 0x40;
    cMessage_ctor_cMessageNameR(&m, D_00588038);
    m.vtable = D_004E1AE0;
    m.b24 = on;
    QueueMessage_cMessageR_cSystemP_int(&m, target, 0);
    m.vtable = D_004DCF10;
    cMessage_dtor(&m, 0);
    t.vtable = D_004DCF10;
    cMessage_dtor(&t, 0);
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00476740 */
