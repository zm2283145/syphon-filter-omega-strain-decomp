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
extern void cAITarget_cAwareList_Find(B7_6A0Node** out, void* map, int key);
extern void std_list_cTargetAwarenessPtr_end_void(B7_6A0Node** out, void* map);
extern void cLListIterator_cTargetAwarenessPtr_ctor(B7_6A0Node** out, B7_6A0Node** in);
B7_6A0Val* cAITarget_GetAwareness(B7_6A0Owner* p, int key)
{
    B7_6A0Val* r = 0;
    B7_6A0Node* it;
    B7_6A0Node* end;
    B7_6A0Node* tmp;
    B7_6A0Node* n;
    cAITarget_cAwareList_Find(&it, p->map, key);
    n = it;
    std_list_cTargetAwarenessPtr_end_void(&tmp, p->map);
    cLListIterator_cTargetAwarenessPtr_ctor(&end, &tmp);
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
extern int cAITarget_GetAwareness(int, int);
#endif /* merge_units */
#define cAITarget_GetAwareness(a0, a1) ((int)cAITarget_GetAwareness((void *)(a0), (a1))) /* merge_units */


float cAITarget_GetAwarenessThreat(void) {
    int a0, a1, v0;
    float f0, f20;
    int cond;

    f20 = 0.0f;
    v0 = cAITarget_GetAwareness(a0, a1);
    cond = v0 == 0;
    if (cond) goto L0016C758;
    f20 = *(float*)((char*)v0 + 48);
L0016C758:;
    f0 = f20;
    goto ret;
ret:
    return f0;
}
#undef cAITarget_GetAwareness /* merge_units */
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
extern void cAITarget_cAwareList_Find(Node_770** out, void* map, int key);
#endif /* merge_units */
#define cAITarget_cAwareList_Find(a0, a1, a2) (cAITarget_cAwareList_Find((void *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern void std_list_cTargetAwarenessPtr_end_void(Node_770** out, void* map);
#endif /* merge_units */
#define std_list_cTargetAwarenessPtr_end_void(a0, a1) (std_list_cTargetAwarenessPtr_end_void((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void cLListIterator_cTargetAwarenessPtr_ctor(Node_770** out, Node_770** in);
#endif /* merge_units */
#define cLListIterator_cTargetAwarenessPtr_ctor(a0, a1) (cLListIterator_cTargetAwarenessPtr_ctor((void *)(a0), (void *)(a1))) /* merge_units */

extern void cAITarget_AddAwareness(Owner_770* p, int key, int kind, float amt);
void cAITarget_SetAwarenessVisible(Owner_770* p, int key, unsigned char a, unsigned char b)
{
    int both = (a & b) != 0;
    Node_770* it;
    Node_770* end;
    Node_770* tmp;
    cAITarget_cAwareList_Find(&it, p->map, key);
    std_list_cTargetAwarenessPtr_end_void(&tmp, p->map);
    cLListIterator_cTargetAwarenessPtr_ctor(&end, &tmp);
    if (it != end) {
        if (both && !it->val->f3C) {
            cAITarget_AddAwareness(p, key, 6, 0.0f);
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
        cAITarget_AddAwareness(p, key, 6, 0.0f);
    }
}
#undef cAITarget_cAwareList_Find /* merge_units */
#undef std_list_cTargetAwarenessPtr_end_void /* merge_units */
#undef cLListIterator_cTargetAwarenessPtr_ctor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0016C770(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0016C770 */
