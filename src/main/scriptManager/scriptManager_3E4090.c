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
DEFINE_TREE_NODE_FREE(func_003E4090, D_004BDBF8)
#pragma pop /* merge_units */
/* merge_units: end func_003E4090 */

/* merge_units: begin func_003E4170 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "payload_message_clone_latevt_p.h"

extern "C" { char D_004BDDD8[] = "character.hh"; }
DEFINE_PAYLOAD_MESSAGE_CLONE_LATEVT_P(func_003E4170, 0x60, D_004BDDD8, 0x4D8, D_004E00E0, func_001AD710, cMessage_ctor3)
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
void func_003E43D0(Msg_4240*, Src_4240*);
V4_4240* func_003E43B0(V4_4240*, float, float, float, float);
V4_4240* Vec4_Set(V4_4240*, float, float, float, float);
Pl_4240* Placement_GetIdentity(Pl_4240*, V4_4240*, V4_4240*);
Id_4240* func_0015AC90(Id_4240*, int);
void func_003E4370(void*, int, Pl_4240*, Id_4240*);
void** NetMap_Lookup(int);
void MsgQueue_QueueClone(Msg_4240*, void*, int, int);
void cMessage_dtor(Msg_4240*, int);

int func_003E4240(int a, int b, int c, Src_4240* p0)
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
        func_003E43D0(m, p);
        r = func_003E43B0(&rot, p->qx, p->qy, p->qz, p->qw);
        pp = Placement_GetIdentity(&pl, r, Vec4_Set(&pos, p->px, p->py, p->pz, 1.0f));
        func_003E4370(m->sub30, p->unkC, pp, func_0015AC90(&idv, p->unk10));
        m->vt = D_004E00E0;
        obj = NetMap_Lookup(p->id);
        if (obj) MsgQueue_QueueClone(m, *obj, 0, 0);
        msg.vt = D_004E0840;
        cMessage_dtor(&msg, 0);
    }
    D_005723C8 = 0;
    return 0x30;
}
#pragma pop /* merge_units */
/* merge_units: end func_003E4240 */
