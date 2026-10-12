#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

struct LNode { LNode* prev; LNode* next; void* data; };
struct LHead { LNode* prev; LNode* next; };
struct LSelf { int count; LHead header; int unkC; int unk10; };

extern "C" {
void Mem_Free(int, void*, char*, int);
void ObjectList_EraseRange(int*, void*, LNode**, LNode**);
void func_003EBAD0(void*, int);
void func_003EB950(LNode** it, LSelf* self);
void func_003EB8F0(LNode** it, int n);
void** func_003EB8E0(LNode** it);
extern char D_004BE010[];
extern char D_00493990;
}

static inline void* ListAt(LSelf* s, int n) {
    LNode* p = s->header.next;
    if (n >= 0) {
        while (n > 0) { p = p->next; n--; }
    } else {
        while (n < 0) { p = p->prev; n++; }
    }
    return p->data;
}
static inline void* At(LSelf* s, int i) {
    LNode* it;
    func_003EB950(&it, s);
    func_003EB8F0(&it, i);
    return *func_003EB8E0(&it);
}

extern "C" void func_003EB750(LSelf* self) {
    int n = self->count;
    int i;
    for (i = 0; i < n; i++) {
        void* p;
        func_003EBAD0(ListAt(self, i), 0);
        p = At(self, i);
        {
            AllocGuard g;
            Mem_Free(0, p, D_004BE010, 0x1B9);
        }
    }
    {
        int res;
        LNode* first;
        LNode* last;
        last = (LNode*)&self->header;
        first = self->header.next;
        ObjectList_EraseRange(&res, self, &first, &last);
    }
    self->unkC = 0;
    D_00493990 = 0;
    self->unk10 = 0;
}