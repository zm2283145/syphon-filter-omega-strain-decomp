/*
 * main/hud_netlobby: 2 files, 0027B900-0027B9C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0027B900 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern char D_00504040;
extern int D_00504058;
extern void std_list_deleter_voidPtr_ctor_void(ScalarCollection*);
extern int* LoadInterface_charP_cHogFileR(int, int);
extern int cInterfaceModel_Activate(int, int, int);

/* Constructor: init embedded collection, acquire a handle and clear all fields. */
Unk27B900* cHudNetLobby_ctor(Unk27B900* self, int a1, int a2) {
    std_list_deleter_voidPtr_ctor_void(&self->list);
    self->unk50 = 3658;
    self->handle = LoadInterface_charP_cHogFileR(a2, a1);
    cInterfaceModel_Activate(*self->handle, 0, 1);
    self->unk38 = 0;
    self->unk3C = 0;
    self->unk04 = 0;
    self->unk0C = 0;
    self->unk18 = 0;
    self->unk1C = 0;
    self->unk20 = 0;
    self->unk14 = 0;
    self->unk28 = 0;
    self->unk54 = 0;
    self->unk55 = 0;
    self->unk56 = 0;
    D_00504040 = 0;
    return self;
}

int cNetTaserMsg_GetMsgId(void) {
    return D_00504058;
}
#pragma pop /* merge_units */
/* merge_units: end func_0027B900 */

/* merge_units: begin func_0027B9C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "net_msg_clone.h"
#include "v4_asm_copy.h"

/* Clone a network message (payload ends with a 16-byte vector at 0x40). */
#define NMC_UB(off) (*(unsigned char*)((char*)p + (off)) = *(unsigned char*)((char*)self + (off)))
extern "C" { char D_004A92A8[] = "netTaserMsg.hh"; }
DEFINE_NET_MSG_CLONE(cNetTaserMsg_Clone, 0x50, D_004A92A8, 0x22, D_004DCDA0,
                     NMC_B(0x24); NMC_W(0x28); NMC_W(0x2C); NMC_UB(0x30); NMC_W(0x34);
                     { char* d = (char*)p + 0x40; char* s = (char*)self + 0x40; V4Copy(d, s); })
#pragma pop /* merge_units */
/* merge_units: end func_0027B9C0 */
