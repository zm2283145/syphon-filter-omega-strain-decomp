/*
 * SFOGame/Source/npc: 5 files, 0014BE10-0014BEA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0014BE10 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: npc.cc (cNPC script commands and vtable methods).
 */

#include "npc_types.h"

extern int cStateMachine_ChangeState(void* obj, int a1, int a2);

typedef struct NpcMoveGobj {
    char pad00[0xC];
    int id;                         /* 0x0C */
} NpcMoveGobj;

typedef struct NpcMoveNode {
    char pad00[0x78];
    int id;                         /* 0x78 */
} NpcMoveNode;

/* vtable slot 0x3F: MoveToGobj. */
int cNPC_MoveToGobj(cNPC* self, NpcMoveGobj* gobj) {
    self->moveTargetGobj = gobj->id;
    self->moveTargetNode = -1;
    cStateMachine_ChangeState(self->unk044, 7, 100);
    return 1;
}

/* vtable slot 0x3E: MoveToNode. */
int cNPC_MoveToNode(cNPC* self, NpcMoveNode* node) {
    cStateMachine_ChangeState(self->unk044, 7, 100);
    self->moveTargetNode = node->id;
    self->moveTargetGobj = -1;
    return 1;
}
static inline void merge_flush_func_0014BE10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0014BE10 */

/* merge_units: begin func_0014BEA0 */
#pragma push /* merge_units */
#include "types.h"
#include "vslot_pad.h"

#pragma cplusplus on
class NPC_BEA0 {
public:
    VPAD32(a) VPAD32(b) VPAD32(c) VPAD16(d) VPAD8(e) VPAD4(f)
    virtual void OnClear();
    char pad[0xB8];
    int bits[9];
};
extern "C" void cNPC_RestrictMovementToNodeGroup(NPC_BEA0* self, int notify)
{
    int i;
    for (i = 0; i < 9; i++)
        self->bits[i] = 0;
    if (notify)
        self->OnClear();
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014BEA0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014BEA0 */

/* merge_units: begin func_0014BF00 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Bits_0014BF00 {
    int w[8];
    bool test(int n) const { return (w[n / 32] >> (n & 31)) & 1; }
    void set(int n) { w[n / 32] |= 1 << (n & 31); }
    void reset(int n) { w[n / 32] &= ~(1 << (n & 31)); }
};
typedef struct { char pad[0x7C]; int id; } Obj_0014BF00;
typedef struct { char pad[0xBC]; Bits_0014BF00 bits; } NPC_0014BF00;
extern "C" void cNPC_RemoveGroupFromPathRegion(NPC_0014BF00* self, Obj_0014BF00* o)
{
    int id = o->id;
    if (self->bits.test(id)) self->bits.reset(id);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014BF00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014BF00 */

/* merge_units: begin func_0014BF60 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Bits_0014BF60 {
    int w[8];
    bool test(int n) const { return (w[n / 32] >> (n & 31)) & 1; }
    void set(int n) { w[n / 32] |= 1 << (n & 31); }
    void reset(int n) { w[n / 32] &= ~(1 << (n & 31)); }
};
typedef struct { char pad[0x7C]; int id; } Obj_0014BF60;
typedef struct { char pad[0xBC]; Bits_0014BF60 bits; } NPC_0014BF60;
extern "C" void cNPC_AddGroupToPathRegion(NPC_0014BF60* self, Obj_0014BF60* o)
{
    int id = o->id;
    if (!self->bits.test(id)) self->bits.set(id);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014BF60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014BF60 */

/* merge_units: begin func_0014BFB0 */
#pragma push /* merge_units */
typedef struct { char pad[0xBC]; int bits[8]; } S_BFB0;
unsigned char cNPC_GroupInPathRegion(S_BFB0* self, int i)
{
    unsigned char r = 1;
    if (i >= 0)
        r = ((self->bits[i / 32] >> (i & 31)) & 1) != 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014BFB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014BFB0 */
