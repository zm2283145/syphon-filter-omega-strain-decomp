/*
 * main/texman: range (2 files, 00382C30-00382D30)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00382C30 */
#pragma push /* merge_units */
typedef struct { char p0[0x60]; signed char f60; signed char f61; unsigned char active; } E382C30;
typedef struct N382C30 { int p0; struct N382C30* next; int key; } N382C30;
typedef struct { char p0[4]; int state; E382C30** items; char pC[0x410]; int count; char list420[4]; } M382C30;
extern void func_00380250(N382C30** out, int it);
extern int func_00380260(void* list);
extern N382C30* func_00380270(void* list, int off);
extern void func_00383560(int* out, void* list, N382C30** it);
#pragma push
#pragma opt_common_subs off
void func_00382C30(M382C30* m, int idx)
{
    int r[1];
    N382C30* it[1];
    N382C30* end[1];
    int off;
    E382C30* e;
    N382C30* n;

    off = idx * 4;
    e = *(E382C30**)((char*)m->items + off);
    if (e->active != 0) {
        e->active = 0;
        (*(E382C30**)((char*)m->items + off))->f60 = 0;
        (*(E382C30**)((char*)m->items + off))->f61 = 0;
        n = func_00380270(m->list420, off)->next;
        func_00380250(end, func_00380260(&m->count));
        if (n != end[0]) {
loop:
            if (idx == n->key) {
                it[0] = n;
                func_00383560(r, &m->count, it);
            } else {
                n = n->next;
                func_00380250(end, func_00380260(&m->count));
                if (n != end[0]) goto loop;
            }
        }
        if (m->count == 0) m->state = 0x4000;
    }
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00382C30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00382C30 */

/* merge_units: begin func_00382D30 */
#pragma push /* merge_units */
#pragma cplusplus on

struct TexEntry {
    char pad[0x60];
    unsigned char u60;
    unsigned char u61;
    unsigned char u62;
};

struct ListNode {
    ListNode* prev;
    ListNode* next;
    int value;
};

struct ListIter {
    ListNode* node;
};

struct IntList {
    int count;
    ListNode* prev;
    ListNode* next;
};

struct TexCache {
    char pad0[8];
    TexEntry** entries;
    char padC[0x41C - 0xC];
    IntList list;
};

extern "C" {
#if 0 /* merge_units */
ListNode* func_00380260(IntList* list);
#endif /* merge_units */
#define func_00380260(a0) ((ListNode *)func_00380260((void *)(a0))) /* merge_units */

ListIter* func_00382EC0(ListIter* it, ListNode* node);
void func_00382EB0(ListIter* out, IntList* list);
ListIter* func_00382EA0(ListIter* dst, ListIter* src);
ListIter* func_00164940(ListIter* result, IntList* list, ListIter* pos, int* value);
}

static inline void List_End(IntList* list, ListIter* out)
{
    ListIter tmp;
    func_00382EB0(&tmp, list);
    func_00382EA0(out, &tmp);
}

static inline bool List_Contains(IntList* list, int value)
{
    ListIter end;
    ListIter it;
    ListNode* n;

    func_00382EC0(&it, func_00380260(list)->next);
    n = it.node;
    while (List_End(list, &end), n != end.node) {
        if (value == n->value) return true;
        n = n->next;
    }
    return false;
}

static inline void List_PushFront(IntList* list, int* v)
{
    ListIter result;
    ListIter pos;
    pos.node = list->next;
    func_00164940(&result, list, &pos, v);
}

#pragma opt_common_subs off
extern "C" void func_00382D30(TexCache* self, int idx)
{
    int i;
    int off = (i = idx) * 4;

    if (!(*(TexEntry**)((char*)self->entries + off))->u62) {
        TexEntry* e = *(TexEntry**)((char*)self->entries + off);
        if ((e->u60 & e->u61) && !List_Contains(&self->list, i)) {
            self->entries[idx]->u60 = 0;
            self->entries[idx]->u61 = 0;
        }
        self->entries[idx]->u62 = 1;
        List_PushFront(&self->list, &idx);
    }
}
#undef func_00380260 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00382D30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00382D30 */
