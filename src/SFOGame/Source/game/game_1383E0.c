/*
 * main/game: range (2 files, 001383E0-001384E0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "message_clone.h"
#pragma pop

/* merge_units: begin func_001383E0 */
#pragma push /* merge_units */
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
