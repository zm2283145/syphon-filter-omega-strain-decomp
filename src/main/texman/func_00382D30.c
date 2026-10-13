#pragma cplusplus on
#include "types.h"

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
ListNode* func_00380260(IntList* list);
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
