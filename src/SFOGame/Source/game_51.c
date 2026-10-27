/*
 * SFOGame/Source/game: 5 files, 001383B0-001385B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001383B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Rel* std_vector_tVUMNamePairPtr_ctor(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}

int cSystem_IsNetworked(void) {
    return 0;
}
static inline void merge_flush_func_001383B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001383B0 */

/* merge_units: begin func_001383E0 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
#include "message_clone.h"
#pragma pop

#pragma cplusplus on

extern "C" char D_004D90E0[];

struct Msg_0022ED30 : ClonedMessageBase {
};

#define CLONE_BODY(p, s) p->vtable = D_004D90E0;

extern "C" {
char D_0049AEB0[] = "player_msg.hh";
}
DEFINE_MESSAGE_CLONE(func_001383E0, Msg_0022ED30, 0x24, D_0049AEB0, 0x23, CLONE_BODY)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001383E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001383E0 */

/* merge_units: begin func_001384E0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct O_001384E0 { void* vt; char pad[0x1C]; char m20[0x10]; char m30[0xC]; char m3C[4]; };
extern "C" {
extern char D_004D9100[];
extern char D_004D90A0[];
void std_vector_deleter_cLosRequest_cCollisionModelList_Game_dtor(void* m, short f);
void func_00135FB0(void* m, short f);
void cSystem_dtor(void* p, short f);
void operator_delete(void* p);
}
extern "C" O_001384E0* func_001384E0(O_001384E0* self, short del)
{
    if (self) {
        self->vt = D_004D9100;
        if (self) {
            self->vt = D_004D90A0;
            std_vector_deleter_cLosRequest_cCollisionModelList_Game_dtor(self->m3C, -1);
            std_vector_deleter_cLosRequest_cCollisionModelList_Game_dtor(self->m30, -1);
            func_00135FB0(self->m20, -1);
            cSystem_dtor(self, 0);
        }
        if (del > 0) operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001384E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001384E0 */

/* merge_units: begin func_00138580 */
#pragma push /* merge_units */
void* cCollisionModelList_GetList(char* self) {
    return self + 4;
}

void cCollisionModelList_SetCenterOfActivation(void) {
}

void cCollisionModelList_Prepare(void) {
}
static inline void merge_flush_func_00138580(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00138580 */

/* merge_units: begin func_001385B0 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" char D_004D9160[];

struct Msg_0020E560 : ClonedMessageBase {
};

#undef CLONE_BODY /* merge_units */
#define CLONE_BODY(p, s) p->vtable = D_004D9160;

extern "C" { char D_0049AEC0[] = "lib_msg.hh"; }
DEFINE_MESSAGE_CLONE(cNextFrameMsg_Clone, Msg_0020E560, 0x24, D_0049AEC0, 0x26, CLONE_BODY)
static inline void merge_flush_func_001385B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001385B0 */
