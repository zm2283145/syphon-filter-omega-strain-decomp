#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

struct LNode { LNode* prev; LNode* next; void* data; };
struct LHead { LNode* prev; LNode* next; };
struct LSelf { int count; LHead header; int unkC; int unk10; };

extern "C" {
void cMemMan_Deallocate(int, void*, char*, int);
void std_list_deleter_voidPtr_erase_listdeleter_listdeleter(int*, void*, LNode**, LNode**);
void cFSData_FreeStream(void*, int);
void std_list_cFSDataPtr_begin(LNode** it, LSelf* self);
void std_advance_listR_int(LNode** it, int n);
void** std_list_cFSDataPtr_generic_iterator_opMul(LNode** it);
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
    std_list_cFSDataPtr_begin(&it, s);
    std_advance_listR_int(&it, i);
    return *std_list_cFSDataPtr_generic_iterator_opMul(&it);
}

extern "C" void cFileStreamMan_Purge(LSelf* self) {
    int n = self->count;
    int i;
    for (i = 0; i < n; i++) {
        void* p;
        cFSData_FreeStream(ListAt(self, i), 0);
        p = At(self, i);
        {
            AllocGuard g;
            cMemMan_Deallocate(0, p, D_004BE010, 0x1B9);
        }
    }
    {
        int res;
        LNode* first;
        LNode* last;
        last = (LNode*)&self->header;
        first = self->header.next;
        std_list_deleter_voidPtr_erase_listdeleter_listdeleter(&res, self, &first, &last);
    }
    self->unkC = 0;
    D_00493990 = 0;
    self->unk10 = 0;
}