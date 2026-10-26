/*
 * main/npc: range (2 files, 0015B690-0015B7A0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "msg_clone.h"
#pragma pop
#include "types.h"

/* merge_units: begin func_0015B690 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" char D_004D9340[];
extern "C" char D_004DFD80[];
MSG_CLONE_BEGIN(cAIMessage_Clone, 0x30, "ai.hh", 0x191)
    p->vt = D_004DFD80;
    F(int, 0x4) = S(int, 0x4);
    F(int, 0x8) = S(int, 0x8);
    F(int, 0xC) = S(int, 0xC);
    F(int, 0x10) = S(int, 0x10);
    F(int, 0x14) = S(int, 0x14);
    F(int, 0x18) = S(int, 0x18);
    F(int, 0x1C) = S(int, 0x1C);
    F(char, 0x20) = S(char, 0x20);
    p->vt = D_004D9340;
    F(char, 0x24) = S(char, 0x24);
    F(int, 0x28) = S(int, 0x28);
    F(int, 0x2C) = S(int, 0x2C);
MSG_CLONE_END
#pragma pop /* merge_units */
/* merge_units: end func_0015B690 */

/* merge_units: begin func_0015B7A0 */
#pragma push /* merge_units */
typedef struct { int pad[3]; int key; } Tgt_B7A0;
typedef struct { char pad[0x40]; Tgt_B7A0* node; int key; } Ai_B7A0;
typedef struct { char pad[0x1AC]; Ai_B7A0* ai; } NPC_B7A0;
Tgt_B7A0* cNPC_v2C(NPC_B7A0* self)
{
    Ai_B7A0* o = self->ai;
    Tgt_B7A0* n = o->node;
    unsigned char ok = 1;
    int z = (n != 0) ^ 1;
    if (!z && n->key != o->key) ok = 0;
    return ok ? n : 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0015B7A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0015B7A0 */
