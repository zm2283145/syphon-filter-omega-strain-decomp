/*
 * main/character: 2 files, 003E53F0-003E5470
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003E53F0 */
#pragma push /* merge_units */
#include "types.h"

extern int NetRegisterMessageStart(void);
extern int cCharActionMsg_RegisterFields(void);
extern int NetMessageField(void* buf, void* end, int size, int count);
extern int NetRegisterApplicationMessage(void* obj, void* callback);
extern char D_0055A1F0[];
extern void cCharActionMsg_ObjectId_NetCharActionNetObjectIDReq();

/* Runs the setup sequence; returns 1 only if every step succeeds. */
unsigned char cCharActionMsg_ObjectId_InitNet(void) {
    unsigned char ok = 0;
    char buf[0xC];
    int err;
    if (!NetRegisterMessageStart() && cCharActionMsg_RegisterFields() && !(err = NetMessageField(buf, buf + 0xC, 4, 1)) && !err
        && !NetRegisterApplicationMessage(D_0055A1F0, cCharActionMsg_ObjectId_NetCharActionNetObjectIDReq)) {
        ok = 1;
    }
    return ok;
}
#pragma pop /* merge_units */
/* merge_units: end func_003E53F0 */

/* merge_units: begin func_003E5470 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; int a; int b; int c; int d; } Hdr;
extern char D_0055A1E8[];
#if 0 /* merge_units */
extern int NetMessageField(Hdr* h, void* dst, int size, int count);
#endif /* merge_units */
#define NetMessageField(a0, a1, a2, a3) (NetMessageField((void *)(a0), (a1), (a2), (a3))) /* merge_units */

#if 0 /* merge_units */
extern int NetRegisterApplicationMessage(void* table, void* fn);
#endif /* merge_units */
#define NetRegisterApplicationMessage(a0, a1) (NetRegisterApplicationMessage((a0), (a1))) /* merge_units */

extern void cCharActionMsg_Vector_NetCharActionVectorReq(void);
/* Reads four header words and registers the handler; returns 1 on success. */
unsigned char cCharActionMsg_Vector_InitNet(void)
{
    Hdr h;
    unsigned char ok = 0;
    if (NetRegisterMessageStart() == 0 && cCharActionMsg_RegisterFields() != 0 &&
        NetMessageField(&h, &h.a, 4, 1) == 0 &&
        NetMessageField(&h, &h.b, 4, 1) == 0 &&
        NetMessageField(&h, &h.c, 4, 1) == 0 &&
        NetMessageField(&h, &h.d, 4, 1) == 0 &&
        NetRegisterApplicationMessage(D_0055A1E8, cCharActionMsg_Vector_NetCharActionVectorReq) == 0)
        ok = 1;
    return ok;
}
#undef NetMessageField /* merge_units */
#undef NetRegisterApplicationMessage /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E5470 */
