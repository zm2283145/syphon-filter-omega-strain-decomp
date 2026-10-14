/*
 * main/human: range (2 files, 001B97F0-001B9900)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "message_clone.h"
#pragma pop
#include "net_write_two_words.h"

/* merge_units: begin func_001B97F0 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" char D_004DCF10[];
extern "C" char D_004DA8B0[];

struct Msg_0020FEC0 : ClonedMessageBase {
    char b24;
};

#define CLONE_BODY(p, s) p->vtable = D_004DCF10; p->vtable = D_004DA8B0; p->b24 = s->b24;

extern "C" {
char D_0049EDA8[] = "human.cc";
}
DEFINE_MESSAGE_CLONE(cEquipGogglesMsg_v01, Msg_0020FEC0, 0x28, D_0049EDA8, 0x2F89, CLONE_BODY)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B97F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001B97F0 */

/* merge_units: begin func_001B9900 */
#pragma push /* merge_units */
typedef struct { char pad[0x24]; int a; char pad28[8]; float x, y, z; } TS_1B9900;
extern void func_001B99E0(float f);
void cNetThrowStarMsg_v04(TS_1B9900* self)
{
    NetW2_write32(self->a);
    func_001B99E0(self->x);
    func_001B99E0(self->y);
    func_001B99E0(self->z);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B9900(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001B9900 */
