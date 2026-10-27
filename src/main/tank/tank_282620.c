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
DEFINE_BUF_HOLDER_DTOR_SHALLOW(std_vector_imp_void_cSystem_1_dtor)
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

Rel* std_vector_void_cSystem_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

int cBeamMsg_GetMsgId(void) {
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
DEFINE_NET_MSG_CLONE(cBeamMsg_Clone, 0x28, D_004A93C0, 0x19, D_004DCF30,
                     NMC_W(0x24))
#pragma pop /* merge_units */
/* merge_units: end func_00282740 */

/* merge_units: begin func_00282850 */
#pragma push /* merge_units */
#include "loose01_types.h"

extern int D_00506228;
extern int cGOBJ_SOBJ_toInt(void*);

int Script_cBeamMsg_Who(ScriptArg* args) {
    return cGOBJ_SOBJ_toInt(((PtrMsg*)args[0].p)->who);
}

void cBeamMsg_SOBJ_init(void) {
}

int cBeamMsg_getSOBJClassId(void) {
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
void cMessage_ctor_cMessageNameR(Ev_A080* e, void* type);
void cNetMsg_GetGOBJ(void* p);
void QueueMessage_cMessageR_cSystemP_int(Ev_A080* e, void* target, int a);
void cMessage_dtor(Ev_A080* e, int f);
void cBeamMsg_NetReceive(void* target)
{
    Ev_A080 e;
    cMessage_ctor_cMessageNameR(&e, D_00506210);
    e.vt = D_004DCF30;
    cNetMsg_GetGOBJ(e.m24);
    e.flag = 1;
    if (target)
        QueueMessage_cMessageR_cSystemP_int(&e, target, 0);
    e.vt = D_004DCF10;
    cMessage_dtor(&e, 0);
}
#pragma pop /* merge_units */
/* merge_units: end func_00282880 */

/* merge_units: begin func_00282900 */
#pragma push /* merge_units */
extern void cNetMsg_PutGOBJ(void*);

void cBeamMsg_Pack(PtrMsg* self) {
    cNetMsg_PutGOBJ(self->who);
}
#pragma pop /* merge_units */
/* merge_units: end func_00282900 */
