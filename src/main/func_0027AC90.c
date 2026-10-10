#include "types.h"

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
extern void func_003E8DE0(void* widget, int visible);
extern void func_003F45A0(void* widget, float alpha);
extern void func_0013B180(Iter27A* out, List27A* list);
extern void func_0027AA80(Iter27A* out, Iter27A* in);
extern void func_0027AC80(Iter27A* out, List27A* list);
extern void func_0027AC70(Iter27A* out, Iter27A* in);

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
    func_003E8DE0(p->w4, 0);
    func_003E8DE0(p->wC, 0);
    func_003E8DE0(p->w8, 0);
    func_003F45A0(p->w8, 0.0f);
    func_003E8DE0(p->w10, 0);
    func_003F45A0(p->w10, 0.0f);
    func_003E8DE0(p->w28, 0);
    func_0013B180(&beginRaw, &p->items);
    func_0027AA80(&it, &beginRaw);
    node = it.node;
    if (node != List_End(&p->items, &endRaw, &end)) {
        do {
            func_003E8DE0(node->item->widget, 0);
            func_003F45A0(node->item->widget, 0.0f);
            node = node->next;
        } while (node != List_End(&p->items, &endRaw, &end));
    }
}
