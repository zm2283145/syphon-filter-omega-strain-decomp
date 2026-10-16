/*
 * main/hud_netlobby: 2 files, 0027AC70-0027AC90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0027AC70 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

Word* func_0027AC70(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void func_0027AC80(Iter* out, Tree* t) {
    out->p = &t->header;
}
#pragma pop /* merge_units */
/* merge_units: end func_0027AC70 */

/* merge_units: begin func_0027AC90 */
#pragma push /* merge_units */
typedef struct { char pad[0x14]; void* widget; } Item27A;
typedef struct ListNode27A { struct ListNode27A* prev; struct ListNode27A* next; Item27A* item; } ListNode27A;
typedef struct { ListNode27A* node; } Iter27A;
typedef struct { void* head; } List27A;
typedef struct {
    int unk0;
    void* w4;
    void* w8;
    void* wC;
    void* w10;
    char pad[0x14];
    void* w28;
    List27A items;
} Panel27A;
extern void IeElement_SetShown(void* widget, int visible);
extern void IeElement_EvaluateAt(void* widget, float alpha);
extern void List_Begin(Iter27A* out, List27A* list);
extern void func_0027AA80(Iter27A* out, Iter27A* in);
#if 0 /* merge_units */
extern void func_0027AC80(Iter27A* out, List27A* list);
#endif /* merge_units */
#define func_0027AC80(a0, a1) (func_0027AC80((Iter *)(a0), (Tree *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void func_0027AC70(Iter27A* out, Iter27A* in);
#endif /* merge_units */
#define func_0027AC70(a0, a1) ((void)func_0027AC70((Word *)(a0), (Word *)(a1))) /* merge_units */


static inline ListNode27A* List_End(List27A* list, Iter27A* raw, Iter27A* end)
{
    func_0027AC80(raw, list);
    func_0027AC70(end, raw);
    return end->node;
}

/* Hides all of the panel's widgets (and fades some to 0), including every item widget in its list. */
void func_0027AC90(Panel27A* p)
{
    Iter27A endRaw;
    Iter27A beginRaw;
    Iter27A it;
    Iter27A end;
    ListNode27A* node;
    IeElement_SetShown(p->w4, 0);
    IeElement_SetShown(p->wC, 0);
    IeElement_SetShown(p->w8, 0);
    IeElement_EvaluateAt(p->w8, 0.0f);
    IeElement_SetShown(p->w10, 0);
    IeElement_EvaluateAt(p->w10, 0.0f);
    IeElement_SetShown(p->w28, 0);
    List_Begin(&beginRaw, &p->items);
    func_0027AA80(&it, &beginRaw);
    node = it.node;
    if (node != List_End(&p->items, &endRaw, &end)) {
        do {
            IeElement_SetShown(node->item->widget, 0);
            IeElement_EvaluateAt(node->item->widget, 0.0f);
            node = node->next;
        } while (node != List_End(&p->items, &endRaw, &end));
    }
}
#undef func_0027AC80 /* merge_units */
#undef func_0027AC70 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0027AC90 */
