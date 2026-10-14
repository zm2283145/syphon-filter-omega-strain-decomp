/*
 * main/NPCInfoObject: range (2 files, 004344C0-00434600)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "npc_auth.h"
#include "npc_info_rec.h"

/* merge_units: begin func_004344C0 */
#pragma push /* merge_units */
void func_00434D10(int self, NpcInfoMsg* m);

void func_004344C0(int self, int key, int v)
{
    int h;
    NpcInfoMsg m;
    NpcInfoRec* r;
    if (D_005721C8) {
        func_004355D0(self);
        if (NpcAuth_IsLocal()) {
            r = func_004361C0(key, &h);
            v = v >= 0 ? v : 0xFF;
            if (r && r->state != v) {
                NPC_INFO_COPY(m, r)
                m.state = v;
                m.b4 = r->b4;
                m.f10 = h;
                r->state = v;
                func_00434D10(self, &m);
                func_00434920(self, h);
            }
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004344C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004344C0 */

/* merge_units: begin func_00434600 */
#pragma push /* merge_units */
void func_00434600(int self, int key, int v)
{
    int h;
    NpcInfoMsg m;
    NpcInfoRec* r;
    if (D_005721C8) {
        func_004355D0(self);
        if (NpcAuth_IsLocal()) {
            r = func_004361C0(key, &h);
            v = v >= 0 ? v : 0xFF;
            if (r && r->b4 != v) {
                NPC_INFO_COPY(m, r)
                m.state = r->b4;
                m.b4 = v;
                m.f10 = h;
                r->state = r->b4;
                r->b4 = v;
                func_00434D10(self, &m);
                func_00434920(self, h);
            }
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00434600(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00434600 */
