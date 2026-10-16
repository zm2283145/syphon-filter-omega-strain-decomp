/*
 * main/tank: 6 files, 00282620-00282900
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00282620 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "buf_holder_dtor.h"

/* Destroy a buffer holder: free its buffer, optionally delete. */
DEFINE_BUF_HOLDER_DTOR_SHALLOW(func_00282620)
#pragma pop /* merge_units */
/* merge_units: end func_00282620 */

/* merge_units: begin func_00282710 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int D_00506218;

Rel* func_00282710(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

int cBeamMsg_v05(void) {
    return D_00506218;
}
#pragma pop /* merge_units */
/* merge_units: end func_00282710 */

/* merge_units: begin func_00282740 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "net_msg_clone.h"

/* Clone a network message. */
extern "C" { char D_004A93C0[] = "BeamMsg.hh"; }
DEFINE_NET_MSG_CLONE(cBeamMsg_v01, 0x28, D_004A93C0, 0x19, D_004DCF30,
                     NMC_W(0x24))
#pragma pop /* merge_units */
/* merge_units: end func_00282740 */

/* merge_units: begin func_00282850 */
#pragma push /* merge_units */
#include "loose01_types.h"

extern int D_00506228;
extern int GObj_IdentityA(void*);

int Script_cBeamMsg_Who(ScriptArg* args) {
    return GObj_IdentityA(((PtrMsg*)args[0].p)->who);
}

void func_00282860(void) {
}

int cBeamMsg_v03(void) {
    return D_00506228;
}
#pragma pop /* merge_units */
/* merge_units: end func_00282850 */

/* merge_units: begin func_00282880 */
#pragma push /* merge_units */
typedef struct { void* vt; char pad[0x1C]; unsigned char flag; char pad21[3]; char m24[0xC]; } Ev_A080;
extern char D_00506210[];
extern char D_004DCF30[];
extern char D_004DCF10[];
void Event_Construct(Ev_A080* e, void* type);
void func_00282160(void* p);
void Event_Send(Ev_A080* e, void* target, int a);
void cMessage_dtor(Ev_A080* e, int f);
void func_00282880(void* target)
{
    Ev_A080 e;
    Event_Construct(&e, D_00506210);
    e.vt = D_004DCF30;
    func_00282160(e.m24);
    e.flag = 1;
    if (target)
        Event_Send(&e, target, 0);
    e.vt = D_004DCF10;
    cMessage_dtor(&e, 0);
}
#pragma pop /* merge_units */
/* merge_units: end func_00282880 */

/* merge_units: begin func_00282900 */
#pragma push /* merge_units */
extern void func_00282020(void*);

void cBeamMsg_v04(PtrMsg* self) {
    func_00282020(self->who);
}
#pragma pop /* merge_units */
/* merge_units: end func_00282900 */
