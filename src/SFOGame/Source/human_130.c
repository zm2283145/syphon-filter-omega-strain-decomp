/*
 * SFOGame/Source/human: 7 files, 001B97F0-001B9C30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001B97F0 */
#pragma push /* merge_units */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "message_clone.h"
#pragma pop
#include "net_write_two_words.h"

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
DEFINE_MESSAGE_CLONE(cEquipGogglesMsg_Clone, Msg_0020FEC0, 0x28, D_0049EDA8, 0x2F89, CLONE_BODY)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B97F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001B97F0 */

/* merge_units: begin func_001B9900 */
#pragma push /* merge_units */
typedef struct { char pad[0x24]; int a; char pad28[8]; float x, y, z; } TS_1B9900;
extern void cNetMsg_PutFloat(float f);
void cNetThrowStarMsg_Pack(TS_1B9900* self)
{
    NetW2_write32(self->a);
    cNetMsg_PutFloat(self->x);
    cNetMsg_PutFloat(self->y);
    cNetMsg_PutFloat(self->z);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B9900(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001B9900 */

/* merge_units: begin func_001B99E0 */
#pragma push /* merge_units */
#include "human_types.h"

extern unsigned char* D_005061D0; /* network write cursor */

static inline void write16(int v)
{
    short s = v;
    *D_005061D0++ = s;
    *D_005061D0++ = s >> 8;
}

/* Writes a float to the network stream as its 32-bit pattern, little-endian. */
void cNetMsg_PutFloat(float f)
{
    int bits = *(int*)&f;
    write16((unsigned short)bits);
    write16(bits >> 16);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B99E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001B99E0 */

/* merge_units: begin func_001B9AA0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern int D_004EEED8;

/* Message type id. */
int cNetThrowStarMsg_GetMsgId(void) {
    return D_004EEED8;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001B9AA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001B9AA0 */

/* merge_units: begin func_001B9AB0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "msg_clone.h"
#include "vc_copy.h"
extern "C" char D_0049D8D0[];
extern "C" char D_004DFD80[];
extern "C" char D_004DA8D0[];
MSG_CLONE_BEGIN(cNetThrowStarMsg_Clone, 0x40, D_0049D8D0, 0x331C)
    p->vt = D_004DFD80;
    F(int, 0x4) = S(int, 0x4);
    F(int, 0x8) = S(int, 0x8);
    F(int, 0xC) = S(int, 0xC);
    F(int, 0x10) = S(int, 0x10);
    F(int, 0x14) = S(int, 0x14);
    F(int, 0x18) = S(int, 0x18);
    F(int, 0x1C) = S(int, 0x1C);
    F(char, 0x20) = S(char, 0x20);
    p->vt = D_004DCF10;
    p->vt = D_004DA8D0;
    F(int, 0x24) = S(int, 0x24);
    {
        char* d = (char*)p + 0x30;
        char* s = (char*)self + 0x30;
        VCopyF(d, s);
    }
MSG_CLONE_END
static inline void merge_flush_func_001B9AB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B9AB0 */

/* merge_units: begin func_001B9BD0 */
#pragma push /* merge_units */
/* Network stream cursor shared by message serializers. */
#if 0 /* merge_units */
extern signed char* D_005061D0;
#endif /* merge_units */
#define D_005061D0 (*(signed char **)&D_005061D0) /* merge_units */

extern int D_004EEEF0;
extern void cNetMsg_PutGOBJ(int);

/* Serialize: write the word argument, then one byte. */
void cNetMeleeAttackMsg_Pack(ArgMsg* msg) {
    cNetMsg_PutGOBJ(msg->arg0);
    *D_005061D0 = msg->arg1;
    D_005061D0 = D_005061D0 + 1;
}

/* Message type id. */
int cNetMeleeAttackMsg_GetMsgId(void) {
    return D_004EEEF0;
}
#undef D_005061D0 /* merge_units */
static inline void merge_flush_func_001B9BD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B9BD0 */

/* merge_units: begin func_001B9C30 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "net_msg_clone.h"
#define NMC_UB(off) (*(unsigned char*)((char*)p + (off)) = *(unsigned char*)((char*)self + (off)))
#define NMC_F(off) (*(float*)((char*)p + (off)) = *(float*)((char*)self + (off)))
DEFINE_NET_MSG_CLONE(cNetMeleeAttackMsg_Clone, 0x2C, D_0049D8D0, 0x3343, D_004DA8F0, NMC_W(0x24); NMC_B(0x28))
static inline void merge_flush_func_001B9C30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001B9C30 */
