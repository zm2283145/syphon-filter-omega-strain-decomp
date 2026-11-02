/*
 * Libs/SFOLib/Source/character: 4 files, 003E5530-003E55B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin character_3E5530 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { int words[3]; } Reader;
extern char D_0055A1E0[];
extern void cCharActionMsg_Scalar_NetCharActionScalarReq();
extern int NetRegisterMessageStart(void);
extern unsigned char cCharActionMsg_RegisterFields(void);
#if 0 /* merge_units */
extern int NetMessageField(Reader* r, void* out, int size, int count);
#endif /* merge_units */
int NetMessageField(void* buf, void* end, int size, int count); /* merge_units */
#define NetMessageField(a0, a1, a2, a3) (NetMessageField((void *)(a0), (a1), (a2), (a3))) /* merge_units */

extern int NetRegisterApplicationMessage(void* table, void (*cb)());

/* Startup check chain; returns 1 when every step succeeds. */
unsigned char cCharActionMsg_Scalar_InitNet(void)
{
    Reader r;
    int value;
    unsigned char ok = 0;
    if (NetRegisterMessageStart() == 0 && cCharActionMsg_RegisterFields() && NetMessageField(&r, &value, 4, 1) == 0
        && NetRegisterApplicationMessage(D_0055A1E0, cCharActionMsg_Scalar_NetCharActionScalarReq) == 0)
        ok = 1;
    return ok;
}
#undef NetMessageField /* merge_units */
static inline void merge_flush_character_3E5530(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end character_3E5530 */

/* merge_units: begin func_003E55B0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern int cCharActionMsg_RegisterFields(void);
#endif /* merge_units */
#define cCharActionMsg_RegisterFields() ((int)cCharActionMsg_RegisterFields()) /* merge_units */

extern int NetMessageField(void* buf, void* end, int size, int count);
#if 0 /* merge_units */
extern int NetRegisterApplicationMessage(void* obj, void* callback);
#endif /* merge_units */

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
#undef cCharActionMsg_RegisterFields /* merge_units */
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
