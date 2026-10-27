/*
 * main/scriptManager: 3 files, 003E4090-003E4240
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003E4090 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "tree_node_free.h"
DEFINE_TREE_NODE_FREE(std_tree_pair_int_value_compare_destroy_nodeP, D_004BDBF8)
#pragma pop /* merge_units */
/* merge_units: end func_003E4090 */

/* merge_units: begin func_003E4170 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "payload_message_clone_latevt_p.h"

extern "C" { char D_004BDDD8[] = "character.hh"; }
DEFINE_PAYLOAD_MESSAGE_CLONE_LATEVT_P(cCharActionMsg_InteractParams_Clone, 0x60, D_004BDDD8, 0x4D8, D_004E00E0, cInteractParams_ctor_cInteractParamsR, cCharActionMsg_ctor_cCharActionMsgR)
#pragma pop /* merge_units */
/* merge_units: end func_003E4170 */

/* merge_units: begin func_003E4240 */
#pragma push /* merge_units */
#pragma opt_propagation off
typedef struct V4_4240 { float x, y, z, w; } V4_4240;
typedef struct Pl_4240 { char pad[0x20]; } Pl_4240;
typedef struct Id_4240 { int a, b; } Id_4240;
typedef struct Src_4240 {
    int kind;
    int id;
    char pad08[4];
    int unkC;
    int unk10;
    float qx, qy, qz, qw;
    float px, py, pz;
} Src_4240;
typedef struct Msg_4240 {
    void* vt;
    char pad04[0x2C];
    char sub30[0x38];
} Msg_4240;
extern unsigned char D_005723C8, D_005721D0;
extern char D_004E00E0[], D_004E0840[];
void cCharActionMsg_ctor_netcharactionreqR(Msg_4240*, Src_4240*);
V4_4240* cQuaternion_ctor_float_float_float_float(V4_4240*, float, float, float, float);
V4_4240* cVector_ctor_float_float_float_float(V4_4240*, float, float, float, float);
Pl_4240* cQuatVec_ctor_cQuaternionR_cVectorR(Pl_4240*, V4_4240*, V4_4240*);
Id_4240* cObjectId_ctor_uint(Id_4240*, int);
void cInteractParams_ctor_int_cQuatVecR_cObjectIdR(void*, int, Pl_4240*, Id_4240*);
void** cNetObj_GetNetSystem(int);
void QueueMessage_cMessageR_cSystemP_int_int(Msg_4240*, void*, int, int);
void cMessage_dtor(Msg_4240*, int);

int cCharActionMsg_InteractParams_NetCharActionInteractParamsReq(int a, int b, int c, Src_4240* p0)
{
    Msg_4240 msg;
    Pl_4240 pl;
    V4_4240 rot;
    V4_4240 pos;
    Id_4240 idv;
    if (!D_005723C8) D_005723C8 = 1;
    if (D_005721D0) {
        Src_4240* p = p0;
        V4_4240* r;
        void** obj;
        Msg_4240* m = &msg;
        Pl_4240* pp;
        cCharActionMsg_ctor_netcharactionreqR(m, p);
        r = cQuaternion_ctor_float_float_float_float(&rot, p->qx, p->qy, p->qz, p->qw);
        pp = cQuatVec_ctor_cQuaternionR_cVectorR(&pl, r, cVector_ctor_float_float_float_float(&pos, p->px, p->py, p->pz, 1.0f));
        cInteractParams_ctor_int_cQuatVecR_cObjectIdR(m->sub30, p->unkC, pp, cObjectId_ctor_uint(&idv, p->unk10));
        m->vt = D_004E00E0;
        obj = cNetObj_GetNetSystem(p->id);
        if (obj) QueueMessage_cMessageR_cSystemP_int_int(m, *obj, 0, 0);
        msg.vt = D_004E0840;
        cMessage_dtor(&msg, 0);
    }
    D_005723C8 = 0;
    return 0x30;
}
#pragma pop /* merge_units */
/* merge_units: end func_003E4240 */
