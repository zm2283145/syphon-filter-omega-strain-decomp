/*
 * Libs/SFOLib/Source/character: 3 files, 003E55B0-003E56F0
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
static inline void merge_flush_func_003E55B0(void) {} /* merge_units */
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
static inline void merge_flush_func_003E5630(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E5630 */

/* merge_units: begin func_003E56F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
}
class O3E56F0 { public: virtual void Destroy(int flags); };
extern "C" O3E56F0* D_0055A228;
extern "C" void cCharActionMsg_DestinationParams_ClearPrevMsg(void)
{
    O3E56F0* p = D_0055A228;
    if (p) {
        {
            AllocGuard g;
            p->Destroy(-1);
            cMemMan_Deallocate(0, p, "character.cc", 0x37B);
        }
        D_0055A228 = 0;
    }
}
static inline void merge_flush_func_003E56F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E56F0 */
