/*
 * SFOGame/Source/NetQuickChatMsg: 3 files, 00323D40-00323F00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00323D40 */
#pragma push /* merge_units */
#include "types.h"

extern unsigned char* D_005061D0; /* network write cursor */

static inline void write16(int v)
{
    short s = v;
    *D_005061D0++ = s;
    *D_005061D0++ = s >> 8;
}

static inline void write32(int v)
{
    write16((unsigned short)v);
    write16(v >> 16);
}

typedef struct { char pad[0x1C]; int size; char pad2[4]; int a; int b; } cNetQuickChatMsg;

/* cNetQuickChatMsg virtual 4: writes two 32-bit values and sets the message size to 0x40. */
void cNetQuickChatMsg_Pack(cNetQuickChatMsg* self)
{
    write32(self->a);
    write32(self->b);
    self->size = 0x40;
}
static inline void merge_flush_func_00323D40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00323D40 */

/* merge_units: begin func_00323EA0 */
#pragma push /* merge_units */
/* Stack message object: vtable followed by the base message data. */
typedef struct Msg {
    void* vtable;
    char data[0x2C];
} Msg;

extern char D_0052ACD8[];
extern char D_004DE630[];        /* derived message vtable */
extern char D_004DCF10[]; /* base message vtable */
extern void cMessage_ctor_cMessageNameR(Msg* msg, void* name);
extern void cNetQuickChatMsg_UnpackAndProcess(Msg* msg, void* target);
extern void cMessage_dtor(Msg* msg, int flags);

/* Builds a temporary message, sends it to target, then destroys it. */
void func_00323EA0(void* target) {
    Msg msg;
    cMessage_ctor_cMessageNameR(&msg, D_0052ACD8);
    msg.vtable = D_004DE630;
    cNetQuickChatMsg_UnpackAndProcess(&msg, target);
    msg.vtable = D_004DCF10;
    cMessage_dtor(&msg, 0);
}
static inline void merge_flush_func_00323EA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00323EA0 */

/* merge_units: begin func_00323F00 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "msg_clone_inline28.h"

extern "C" { char D_004B7CE0[] = "NetRemoveHudObjectiveMsg.hh"; }
DEFINE_MSG_CLONE_INLINE28(cNetRemoveHudObjectiveMsg_Clone, 0x28, D_004B7CE0, 0x16, D_004DFD80, D_004DE650)
static inline void merge_flush_func_00323F00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00323F00 */
