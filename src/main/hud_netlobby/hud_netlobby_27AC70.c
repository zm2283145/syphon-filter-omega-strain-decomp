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

Word* cLListIterator_GameInfoPtr_ctor(Word* dst, Word* src) {
    dst->value = src->value;
    return dst;
}

void std_list_GameInfoPtr_end(Iter* out, Tree* t) {
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
extern void cInterfaceElement_Activate(void* widget, int visible);
extern void viBufGetTs(void* widget, float alpha);
extern void std_list_deleter_voidPtr_begin_void(Iter27A* out, List27A* list);
extern void std_list_GameInfoPtr_generic_iterator_ctor(Iter27A* out, Iter27A* in);
#if 0 /* merge_units */
extern void std_list_GameInfoPtr_end(Iter27A* out, List27A* list);
#endif /* merge_units */
#define std_list_GameInfoPtr_end(a0, a1) (std_list_GameInfoPtr_end((Iter *)(a0), (Tree *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern void cLListIterator_GameInfoPtr_ctor(Iter27A* out, Iter27A* in);
#endif /* merge_units */
#define cLListIterator_GameInfoPtr_ctor(a0, a1) ((void)cLListIterator_GameInfoPtr_ctor((Word *)(a0), (Word *)(a1))) /* merge_units */


static inline ListNode27A* std_list_cCBDataPtr_push_back(List27A* list, Iter27A* raw, Iter27A* end)
{
    std_list_GameInfoPtr_end(raw, list);
    cLListIterator_GameInfoPtr_ctor(end, raw);
    return end->node;
}

/* Hides all of the panel's widgets (and fades some to 0), including every item widget in its list. */
void cHudNetLobby_DeactivateControls(Panel27A* p)
{
    Iter27A endRaw;
    Iter27A beginRaw;
    Iter27A it;
    Iter27A end;
    ListNode27A* node;
    cInterfaceElement_Activate(p->w4, 0);
    cInterfaceElement_Activate(p->wC, 0);
    cInterfaceElement_Activate(p->w8, 0);
    viBufGetTs(p->w8, 0.0f);
    cInterfaceElement_Activate(p->w10, 0);
    viBufGetTs(p->w10, 0.0f);
    cInterfaceElement_Activate(p->w28, 0);
    std_list_deleter_voidPtr_begin_void(&beginRaw, &p->items);
    std_list_GameInfoPtr_generic_iterator_ctor(&it, &beginRaw);
    node = it.node;
    if (node != std_list_cCBDataPtr_push_back(&p->items, &endRaw, &end)) {
        do {
            cInterfaceElement_Activate(node->item->widget, 0);
            viBufGetTs(node->item->widget, 0.0f);
            node = node->next;
        } while (node != std_list_cCBDataPtr_push_back(&p->items, &endRaw, &end));
    }
}
#undef std_list_GameInfoPtr_end /* merge_units */
#undef cLListIterator_GameInfoPtr_ctor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0027AC90 */
