/*
 * main/character: 2 files, 003E55B0-003E5630
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003E55B0 */
#pragma push /* merge_units */
#include "types.h"

extern int NetRegisterMessageStart(void);
extern int cCharActionMsg_RegisterFields(void);
extern int NetMessageField(void* buf, void* end, int size, int count);
extern int NetRegisterApplicationMessage(void* obj, void* callback);
extern char D_0055A220[];
extern void cCharActionMsg_Int_NetCharActionIntReq();

/* Runs the setup sequence; returns 1 only if every step succeeds. */
unsigned char cCharActionMsg_Int_InitNet(void) {
    unsigned char ok = 0;
    char buf[0xC];
    if (!NetRegisterMessageStart() && cCharActionMsg_RegisterFields() && !NetMessageField(buf, buf + 0xC, 4, 1)
        && !NetRegisterApplicationMessage(D_0055A220, cCharActionMsg_Int_NetCharActionIntReq)) {
        ok = 1;
    }
    return ok;
}
#pragma pop /* merge_units */
/* merge_units: end func_003E55B0 */

/* merge_units: begin func_003E5630 */
#pragma push /* merge_units */
#include "message_pack.h"
#define MP_F(p, off) (*(float*)((char*)(p) + (off)))
#define Event_PackHeader cCharActionMsg_Pack
#define PACK_BODY(e, b) MP_I(b, 0xC) = MP_I(e, 0x30); MP_I(b, 0x10) = MP_I(e, 0x34); \
    MP_F(b, 0x14) = MP_F(e, 0x40); MP_F(b, 0x18) = MP_F(e, 0x44); MP_F(b, 0x1C) = MP_F(e, 0x48); \
    MP_F(b, 0x20) = MP_F(e, 0x4C); MP_F(b, 0x24) = MP_F(e, 0x50); MP_F(b, 0x28) = MP_F(e, 0x54); \
    MP_F(b, 0x2C) = MP_F(e, 0x58);
DEFINE_MESSAGE_PACK_NOTYPE(cCharActionMsg_InteractParams_Pack, 0x30, D_0055A218, PACK_BODY)
#pragma pop /* merge_units */
/* merge_units: end func_003E5630 */
