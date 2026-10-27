/*
 * Libs/SFOLib/Source/NetActivateAndControlMsg: 3 files, 0042CAA0-0042CC40
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0042CAA0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "msg_clone.h"
struct V2CAA0 { union { struct { unsigned int a, b; char* c; } l; struct { unsigned char f : 1; unsigned char n : 7; char buf[11]; } s; } u; };
extern "C" char D_004DFD80[];
extern "C" char D_004E0EA0[];
MSG_CLONE_BEGIN(cNetActivateAndControlMsg_Clone, 0x30, "NetActivateAndControlMsg.hh", 0x1C)
    p->vt = D_004DFD80;
    F(int, 0x4) = S(int, 0x4);
    F(int, 0x8) = S(int, 0x8);
    F(int, 0xC) = S(int, 0xC);
    F(int, 0x10) = S(int, 0x10);
    F(int, 0x14) = S(int, 0x14);
    F(int, 0x18) = S(int, 0x18);
    F(int, 0x1C) = S(int, 0x1C);
    F(char, 0x20) = S(char, 0x20);
    p->vt = D_004E0EA0;
    F(V2CAA0, 0x24) = S(V2CAA0, 0x24);
MSG_CLONE_END
static inline void merge_flush_func_0042CAA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0042CAA0 */

/* merge_units: begin func_0042CBB0 */
#pragma push /* merge_units */
#include "types.h"
extern int NetRegisterMessageStart(void);
extern int cMessage_RegisterFields(void* p);
extern int NetMessageField(void* a, void* b, int c, int d);
extern int NetRegisterMessage(void* t, int id, void* fn);
extern int D_00582688;
extern int cNetActivateAndControlMsg_ActivateAndControlCallback();
unsigned char cNetActivateAndControlMsg_InitNet(void) {
    int a[2];
    int buf[2];
    int busy;
    unsigned char r = 0;
    busy = NetRegisterMessageStart();
    if (!busy && cMessage_RegisterFields(buf) && !busy && NetMessageField(buf, a, 4, 1) == 0 && NetRegisterMessage(&D_00582688, 2, cNetActivateAndControlMsg_ActivateAndControlCallback) == 0) {
        r = 1;
    }
    return r;
}
static inline void merge_flush_func_0042CBB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0042CBB0 */

/* merge_units: begin func_0042CC40 */
#pragma push /* merge_units */
#include "message_pack.h"

#define PACK_PRE(e)
#define PACK_BODY(e, b) MP_I(b, 8) = MP_I(e, 0x2C);

DEFINE_MESSAGE_PACK_PRE(cNetActivateAndControlMsg_Pack, 12, D_00582688, PACK_PRE, PACK_BODY)
static inline void merge_flush_func_0042CC40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0042CC40 */
