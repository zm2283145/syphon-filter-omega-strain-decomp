/*
 * main/npc: range (2 files, 0015B470-0015B570)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "message_clone.h"
#pragma pop
#pragma push
#pragma cplusplus on
#include "msg_clone.h"
#pragma pop

/* merge_units: begin func_0015B470 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" char D_004D9300[];

struct Msg_0023FF50 : ClonedMessageBase {
    char b24;
};

#define CLONE_BODY(p, s) p->vtable = D_004D9300; p->b24 = s->b24;

extern "C" {
char D_0049C050[] = "NetObjectMgr.hh";
}
DEFINE_MESSAGE_CLONE(func_0015B470, Msg_0023FF50, 0x28, D_0049C050, 0xE, CLONE_BODY)
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0015B470(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0015B470 */

/* merge_units: begin func_0015B570 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" char D_004D9320[];
extern "C" char D_004DFD80[];
extern "C" char D_004E0840[];
MSG_CLONE_BEGIN(func_0015B570, 0x30, "character.hh", 0x1C5)
    p->vt = D_004DFD80;
    F(int, 0x4) = S(int, 0x4);
    F(int, 0x8) = S(int, 0x8);
    F(int, 0xC) = S(int, 0xC);
    F(int, 0x10) = S(int, 0x10);
    F(int, 0x14) = S(int, 0x14);
    F(int, 0x18) = S(int, 0x18);
    F(int, 0x1C) = S(int, 0x1C);
    F(char, 0x20) = S(char, 0x20);
    p->vt = D_004E0840;
    F(int, 0x24) = S(int, 0x24);
    F(char, 0x28) = S(char, 0x28);
    p->vt = D_004D9320;
    F(unsigned char, 0x2C) = S(unsigned char, 0x2C);
MSG_CLONE_END
#pragma pop /* merge_units */
/* merge_units: end func_0015B570 */
