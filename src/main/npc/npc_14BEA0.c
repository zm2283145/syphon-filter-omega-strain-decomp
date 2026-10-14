/*
 * main/npc: range (4 files, 0014BEA0-0014BFB0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"

/* merge_units: begin func_0014BEA0 */
#pragma push /* merge_units */
#pragma cplusplus on
class NPC_BEA0 {
public:
    VPAD32(a) VPAD32(b) VPAD32(c) VPAD16(d) VPAD8(e) VPAD4(f)
    virtual void OnClear();
    char pad[0xB8];
    int bits[9];
};
extern "C" void cNPC_v7B(NPC_BEA0* self, int notify)
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
extern "C" void cNPC_v7D(NPC_0014BF00* self, Obj_0014BF00* o)
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
extern "C" void cNPC_v7C(NPC_0014BF60* self, Obj_0014BF60* o)
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
unsigned char NpcAi_IsRegionAllowed(S_BFB0* self, int i)
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
