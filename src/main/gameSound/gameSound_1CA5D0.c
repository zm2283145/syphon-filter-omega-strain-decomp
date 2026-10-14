/*
 * main/gameSound: range (3 files, 001CA5D0-001CA750)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "net_msg_clone.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "vt8_chain_dtor.h"
#pragma pop

/* merge_units: begin func_001CA5D0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Clone a network message. */
extern "C" {
char D_0049F6F8[] = "gameSound.cc";
}
DEFINE_NET_MSG_CLONE(cPlayQuipMsg_v01, 0x2C, D_0049F6F8, 0x6F0, D_004DAC70, NMC_W(0x24); NMC_W(0x28))
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001CA5D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001CA5D0 */

/* merge_units: begin func_001CA6F0 */
#pragma push /* merge_units */
#pragma cplusplus on
DEFINE_VT8_CHAIN_DTOR(func_001CA6F0, D_004DAC90, D_004D9DE0)
#pragma pop /* merge_units */
/* merge_units: end func_001CA6F0 */

/* merge_units: begin func_001CA750 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
extern char D_004DACB0[];
void __destroy_array(void* p, void* dtor, int size, int n);
void* func_001C9F10(void* self, short deleteFlag);
void Receiver_Destruct(void* self, int flags);
#if 0 /* merge_units */
void operator_delete(void* p);
#endif /* merge_units */
#define operator_delete(a0) ((void)operator_delete((a0))) /* merge_units */

}
struct O1CA750 { void* vtable; char pad[0x2C]; char items[0x32][0x1B0]; };
extern "C" O1CA750* func_001CA750(O1CA750* self, short deleteFlag)
{
    if (self) {
        self->vtable = D_004DACB0;
        __destroy_array(self->items, (void*)func_001C9F10, 0x1B0, 0x32);
        Receiver_Destruct(self, 0);
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}
#undef operator_delete /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001CA750(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001CA750 */
