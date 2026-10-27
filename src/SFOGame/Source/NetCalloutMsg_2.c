/*
 * SFOGame/Source/NetCalloutMsg: 3 files, 002C53A0-002C54C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002C53A0 */
#pragma push /* merge_units */
#include "types.h"
#include "message_pack.h"
#define MP_F(p, off) (*(float*)((char*)(p) + (off)))
extern int nGlobalization_GetStringIndex(void* key);
#define PACK_BODY(e, b) MP_U(b, 0x8) = MP_U(e, 0x24); MP_I(b, 0x10) = MP_I(e, 0x28); MP_F(b, 0x14) = MP_F(e, 0x2C); MP_F(b, 0x18) = MP_F(e, 0x30); MP_I(b, 0x1C) = MP_I(e, 0x44); MP_U(b, 0x9) = MP_U(e, 0x48); MP_U(b, 0xA) = MP_U(e, 0x49); MP_I(b, 0xC) = nGlobalization_GetStringIndex((char*)(e) + 0x34);
DEFINE_MESSAGE_PACK(cNetCalloutMsg_Pack, 0x20, D_0051EE40, PACK_BODY)
static inline void merge_flush_func_002C53A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002C53A0 */

/* merge_units: begin func_002C5460 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

DEFINE_VTABLE_BASE_DTOR(cNetCopyMsg_dtor, D_004DE110, cMessage_dtor)
static inline void merge_flush_func_002C5460(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002C5460 */

/* merge_units: begin func_002C54C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void cMessage_ctor_cMessageR(void* self, void* src);
void cNetworkTransferNpc_ctor_cNetworkTransferNpcR(void* dst, void* src);
extern char D_004DE110[];
}
struct Msg54C0 { void* vtable; char pad[0x20]; int value; char pad2[8]; char payload[0x10]; };
extern "C" Msg54C0* cNetCopyMsg_Clone(Msg54C0* src)
{
    Msg54C0* p;
    {
        AllocGuard guard;
        p = (Msg54C0*)cMemMan_Allocate(0, 0x310, "NetCopyMsg.hh", 0x16);
    }
    if (p) {
        cMessage_ctor_cMessageR(p, src);
        p->vtable = D_004DE110;
        p->value = src->value;
        cNetworkTransferNpc_ctor_cNetworkTransferNpcR(p->payload, src->payload);
    }
    return p;
}
static inline void merge_flush_func_002C54C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002C54C0 */
