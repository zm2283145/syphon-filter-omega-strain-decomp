/*
 * main/ai: range (3 files, 0016C6A0-0016C770)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0016C6A0 */
#pragma push /* merge_units */
typedef struct { char pad[0x24]; float f24; } B7_6A0Val;
typedef struct { char pad[8]; B7_6A0Val* val; } B7_6A0Node;
typedef struct { char pad[0x30]; char map[1]; } B7_6A0Owner;
extern void NpcPerception_FindRecord(B7_6A0Node** out, void* map, int key);
extern void func_0016BB80(B7_6A0Node** out, void* map);
extern void func_0016BB90(B7_6A0Node** out, B7_6A0Node** in);
B7_6A0Val* NpcPerception_SensedRecord(B7_6A0Owner* p, int key)
{
    B7_6A0Val* r = 0;
    B7_6A0Node* it;
    B7_6A0Node* end;
    B7_6A0Node* tmp;
    B7_6A0Node* n;
    NpcPerception_FindRecord(&it, p->map, key);
    n = it;
    func_0016BB80(&tmp, p->map);
    func_0016BB90(&end, &tmp);
    if (n != end) {
        B7_6A0Val* v = n->val;
        if (!(v->f24 < 0.0f)) {
            r = v;
        }
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016C6A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0016C6A0 */

/* merge_units: begin func_0016C730 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern int NpcPerception_SensedRecord(int, int);
#endif /* merge_units */
#define NpcPerception_SensedRecord(a0, a1) ((int)NpcPerception_SensedRecord((void *)(a0), (a1))) /* merge_units */


float NpcPerception_IsEnemy(void) {
    int a0, a1, v0;
    float f0, f20;
    int cond;

    f20 = 0.0f;
    v0 = NpcPerception_SensedRecord(a0, a1);
    cond = v0 == 0;
    if (cond) goto L0016C758;
    f20 = *(float*)((char*)v0 + 48);
L0016C758:;
    f0 = f20;
    goto ret;
ret:
    return f0;
}
#undef NpcPerception_SensedRecord /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016C730(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0016C730 */

/* merge_units: begin func_0016C770 */
#pragma push /* merge_units */
typedef struct { char pad[0x20]; unsigned char f20; char p21[3]; float f24; char p28[0x10]; unsigned char f38; unsigned char f39; unsigned char f3A; char p3B; unsigned char f3C; } Rec_770;
typedef struct { char pad[8]; Rec_770* val; } Node_770;
typedef struct { char pad[0x30]; char map[1]; } Owner_770;
#if 0 /* merge_units */
extern void NpcPerception_FindRecord(Node_770** out, void* map, int key);
#endif /* merge_units */
#define NpcPerception_FindRecord(a0, a1, a2) (NpcPerception_FindRecord((void *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern void func_0016BB80(Node_770** out, void* map);
#endif /* merge_units */
#define func_0016BB80(a0, a1) (func_0016BB80((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void func_0016BB90(Node_770** out, Node_770** in);
#endif /* merge_units */
#define func_0016BB90(a0, a1) (func_0016BB90((void *)(a0), (void *)(a1))) /* merge_units */

extern void NpcPerception_AddAwareness(Owner_770* p, int key, int kind, float amt);
void NpcPerception_RegisterSighting(Owner_770* p, int key, unsigned char a, unsigned char b)
{
    int both = (a & b) != 0;
    Node_770* it;
    Node_770* end;
    Node_770* tmp;
    NpcPerception_FindRecord(&it, p->map, key);
    func_0016BB80(&tmp, p->map);
    func_0016BB90(&end, &tmp);
    if (it != end) {
        if (both && !it->val->f3C) {
            NpcPerception_AddAwareness(p, key, 6, 0.0f);
        } else {
            it->val->f38 = b;
            it->val->f39 = a;
            if (a) {
                if (b) {
                    it->val->f24 = 0.0f;
                    it->val->f3A = 1;
                    it->val->f20 = 6;
                } else if (it->val->f24 < 10.0f) {
                    it->val->f24 = 0.0f;
                }
            }
        }
    } else if (both) {
        NpcPerception_AddAwareness(p, key, 6, 0.0f);
    }
}
#undef NpcPerception_FindRecord /* merge_units */
#undef func_0016BB80 /* merge_units */
#undef func_0016BB90 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016C770(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0016C770 */
