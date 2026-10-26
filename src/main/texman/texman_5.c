/*
 * main/texman: 5 files, 00382190-00382C30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00382190 */
#pragma push /* merge_units */
#pragma cplusplus on

struct TexInfo {
    char pad[0xE];
    unsigned short hE;
    char pad10[0xA];
    unsigned short h1A;
};

struct TexEntry {
    char pad[0x44];
    TexInfo* info;
    char pad48[8];
    unsigned long tex0;
    char pad58[8];
    unsigned char u60;
    unsigned char u61;
    unsigned char u62;
};

struct TexCache {
    unsigned int base;
    unsigned int size;
    TexEntry** entries;
    int cap;
    int count;
    unsigned char u14;
    unsigned char u15;
    unsigned char u16;
    int u18;
    short list[(0x41C - 0x1C) / 2];
    char m41C[0xC];
    char m428[0xC];
    char m434[0xC];
    char zero440[0x40];
    int u480;
    int u484;
    unsigned char u488;
    unsigned char u489;
    unsigned int u48C;
    int handler;
};

struct DmaBuf {
    char pad[0x10];
    int cur;
};

extern "C" {
extern char D_00537F80[];
extern DmaBuf* D_00537F88;
extern int D_00539330;
extern int D_00539340[][1024];
long* DmaPacket_Reserve(void* q, int i, int id, int qwc, int addr, int flag);
void cTexture_UploadBoth(TexEntry* e, unsigned int lo, unsigned int hi);
}

static inline void TexCache_Reset(TexCache* self)
{
    TexEntry** p = self->entries;
    int n = self->count;
    while (n > 0) {
        TexEntry* e = *p++;
        if (e && !e->u62 && (unsigned int)(int)(e->tex0 & 0x3FFF) >= self->base) {
            e->u60 = 0;
            e->u61 = 0;
        }
        n--;
    }
    self->u48C = self->base;
}

extern "C" void cTexMan_EndLockedBatch(TexCache* self)
{
    bool dirty = false;
    unsigned int addr;
    int i;
    long* p;

    self->u16 = 1;
    addr = self->size;
    for (i = 0; i < self->u18; i++) {
        TexEntry* e = *(TexEntry**)((int)self->entries + self->list[i]*4);
        if (self->u14 && e && (e->u60 & e->u61) && ((int)(e->tex0 & 0x3FFF) & 0x1F)) {
            e->u60 = 0;
            e->u61 = 0;
        }
        if (e && !(e->u60 & e->u61)) {
            if (self->u14) addr -= 0x20;
            addr -= e->info->hE + e->info->h1A;
            dirty = 1;
            if (addr < self->u48C) self->u488 = 1;
        }
    }
    if (self->u488) {
        TexCache_Reset(self);
        dirty = 1;
    }
    if (dirty) {
        D_00539340[!D_00539330][self->u480] = D_00537F88->cur;
        int j;
        for (j = 0; j < self->u18; j++) {
            TexEntry* e = self->entries[self->list[j]];
            if (e && !(e->u60 & e->u61)) {
                if (self->u14) self->size = (self->size - 0x20) & ~0x1F;
                self->size -= e->info->hE + e->info->h1A;
                cTexture_UploadBoth(e, self->size, self->size + (e->info->hE + e->info->h1A) - 4);
            }
        }
        p = DmaPacket_Reserve(D_00537F80, 2, 7, 2, 0, 0);
        *p++ = 0x1000000000008001;
        *p++ = 0xE;
        *p++ = 0;
        *p++ = 0x3F;
        p = DmaPacket_Reserve(D_00537F80, 1, 1, 1, 0, 1);
        p[0] = 0;
        if (self->u488 || !self->u480) {
            p[1] = 0x93000000;
            p[2] = 0x93000000;
            if (self->u484) {
                if (self->u489) *(int*)(self->u484 + 8) = 0x13000000;
                else *(int*)self->u484 = 0x13000000;
            }
            self->u488 = 0;
            self->u489 = 1;
        } else {
            p[1] = 0x93000000;
            p[2] = 0;
            self->u489 = 0;
        }
        self->u484 = (int)(p + 1);
        self->u480++;
    }
    self->u14 = 0;
    self->u15 = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00382190(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00382190 */

/* merge_units: begin func_00382540 */
#pragma push /* merge_units */
#pragma cplusplus on


extern "C" {
}

extern "C" void cTexMan_EndLockedBatch(TexCache* self);

extern "C" void TexMan_UploadSlots(TexCache* self)
{
    bool dirty;
    unsigned int addr;
    int i;
    long* p;

    if (self->u15) {
        cTexMan_EndLockedBatch(self);
        return;
    }
    self->u16 = 1;
    dirty = false;
    addr = self->u48C;
    for (i = 0; i < self->u18; i++) {
        TexEntry* e = *(TexEntry**)((int)self->entries + self->list[i]*4);
        if (self->u14 && e && (e->u60 & e->u61) && ((int)(e->tex0 & 0x3FFF) & 0x1F)) {
            e->u60 = 0;
            e->u61 = 0;
        }
        if (e && !(e->u60 & e->u61)) {
            if (self->u14) addr += 0x20;
            addr += e->info->hE + e->info->h1A;
            dirty = 1;
            if (addr >= self->size) self->u488 = 1;
        }
    }
    if (self->u488) {
        TexCache_Reset(self);
        dirty = 1;
    }
    if (dirty) {
        D_00539340[!D_00539330][self->u480] = D_00537F88->cur;
        int j;
        for (j = 0; j < self->u18; j++) {
            TexEntry* e = self->entries[self->list[j]];
            if (e && !(e->u60 & e->u61)) {
                if (self->u14) self->u48C = (self->u48C + 0x20) & ~0x1F;
                cTexture_UploadBoth(e, self->u48C, self->u48C + (e->info->hE + e->info->h1A) - 4);
                self->u48C += e->info->hE + e->info->h1A;
            }
        }
        p = DmaPacket_Reserve(D_00537F80, 2, 7, 2, 0, 0);
        *p++ = 0x1000000000008001;
        *p++ = 0xE;
        *p++ = 0;
        *p++ = 0x3F;
        p = DmaPacket_Reserve(D_00537F80, 1, 1, 1, 0, 1);
        p[0] = 0;
        if (self->u488 || !self->u480) {
            p[1] = 0x93000000;
            p[2] = 0x93000000;
            if (self->u484) {
                if (self->u489) *(int*)(self->u484 + 8) = 0x13000000;
                else *(int*)self->u484 = 0x13000000;
            }
            self->u488 = 0;
            self->u489 = 1;
        } else {
            p[1] = 0x93000000;
            p[2] = 0;
            self->u489 = 0;
        }
        self->u484 = (int)(p + 1);
        self->u480++;
    }
    self->u14 = 0;
    self->u15 = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00382540(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00382540 */

/* merge_units: begin func_00382910 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on


extern "C" {
}

extern "C" void cTexMan_EndBatch(TexCache* self)
{
    /* declaration order chosen to reproduce the original register allocation */
    short* lp;
    bool dirty;
    int n2;
    TexEntry* e2;
    long* p;
    unsigned int addr;
    int n;
    short* lp2;

    self->u16 = 1;
    dirty = false;
    addr = self->u48C;
    {
        lp = self->list;
        n = self->u18;
        while (n > 0) {
            TexEntry* e = *(TexEntry**)((int)self->entries + *lp++ * 4);
            if (e && !(e->u60 & e->u61)) {
                addr += e->info->hE + e->info->h1A;
                dirty = 1;
                if (addr >= self->size) {
                    self->u488 = 1;
                    break;
                }
            }
            n--;
        }
    }
    if (self->u488) {
        TexCache_Reset(self);
        dirty = 1;
    }
    if (dirty) {
        D_00539340[!D_00539330][self->u480] = D_00537F88->cur;
        {
            lp2 = self->list;
            n2 = self->u18;
            while (n2 > 0) {
                e2 = self->entries[*lp2++];
                if (e2 && !(e2->u60 & e2->u61)) {
                    cTexture_UploadBoth(e2, self->u48C, self->u48C + (e2->info->hE + e2->info->h1A) - 4);
                    self->u48C += e2->info->hE + e2->info->h1A;
                }
                n2--;
            }
        }
        p = DmaPacket_Reserve(D_00537F80, 2, 7, 2, 0, 0);
        *p++ = 0x1000000000008001;
        *p++ = 0xE;
        *p++ = 0;
        *p++ = 0x3F;
        p = DmaPacket_Reserve(D_00537F80, 1, 1, 1, 0, 1);
        p[0] = 0;
        if (self->u488 || !self->u480) {
            p[1] = 0x93000000;
            p[2] = 0x93000000;
            if (self->u484) {
                if (self->u489) *(int*)(self->u484 + 8) = 0x13000000;
                else *(int*)self->u484 = 0x13000000;
            }
            self->u488 = 0;
            self->u489 = 1;
        } else {
            p[1] = 0x93000000;
            p[2] = 0;
            self->u489 = 0;
        }
        self->u484 = (int)(p + 1);
        self->u480++;
    }
    self->u14 = 0;
    self->u15 = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00382910 */

/* merge_units: begin func_00382C30 */
#pragma push /* merge_units */
typedef struct { char p0[0x60]; signed char f60; signed char f61; unsigned char active; } E382C30;
typedef struct N382C30 { int p0; struct N382C30* next; int key; } N382C30;
typedef struct { char p0[4]; int state; E382C30** items; char pC[0x410]; int count; char list420[4]; } M382C30;
extern void std_list_deleter_int_generic_iterator_ctor_nodebaseP(N382C30** out, int it);
extern int std_list_deleter_int_tail(void* list);
extern N382C30* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_10(void* list, int off);
extern void List_Erase_383560(int* out, void* list, N382C30** it);
#pragma push
#pragma opt_common_subs off
void TexMan_ReleaseSlot(M382C30* m, int idx)
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
        n = details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_10(m->list420, off)->next;
        std_list_deleter_int_generic_iterator_ctor_nodebaseP(end, std_list_deleter_int_tail(&m->count));
        if (n != end[0]) {
loop:
            if (idx == n->key) {
                it[0] = n;
                List_Erase_383560(r, &m->count, it);
            } else {
                n = n->next;
                std_list_deleter_int_generic_iterator_ctor_nodebaseP(end, std_list_deleter_int_tail(&m->count));
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

struct TexEntry_00382D30 {
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

struct TexCache_00382D30 {
    char pad0[8];
    TexEntry_00382D30** entries;
    char padC[0x41C - 0xC];
    IntList list;
};

extern "C" {
#if 0 /* merge_units */
ListNode* std_list_deleter_int_tail(IntList* list);
#endif /* merge_units */
#define std_list_deleter_int_tail(a0) ((ListNode *)std_list_deleter_int_tail((void *)(a0))) /* merge_units */


ListIter* std_list_deleter_int_generic_iterator_ctor_nodeP(ListIter* it, ListNode* node);
void std_list_deleter_int_end(ListIter* out, IntList* list);
ListIter* cLListIterator_int_ctor(ListIter* dst, ListIter* src);
ListIter* std_list_deleter_int_insert(ListIter* result, IntList* list, ListIter* pos, int* value);
}

static inline void List_End(IntList* list, ListIter* out)
{
    ListIter tmp;
    std_list_deleter_int_end(&tmp, list);
    cLListIterator_int_ctor(out, &tmp);
}

static inline bool List_Contains(IntList* list, int value)
{
    ListIter end;
    ListIter it;
    ListNode* n;

    std_list_deleter_int_generic_iterator_ctor_nodeP(&it, std_list_deleter_int_tail(list)->next);
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
    std_list_deleter_int_insert(&result, list, &pos, v);
}

#pragma opt_common_subs off
extern "C" void cTexMan_LockVram(TexCache_00382D30* self, int idx)
{
    int i;
    int off = (i = idx) * 4;

    if (!(*(TexEntry_00382D30**)((char*)self->entries + off))->u62) {
        TexEntry_00382D30* e = *(TexEntry_00382D30**)((char*)self->entries + off);
        if ((e->u60 & e->u61) && !List_Contains(&self->list, i)) {
            self->entries[idx]->u60 = 0;
            self->entries[idx]->u61 = 0;
        }
        self->entries[idx]->u62 = 1;
        List_PushFront(&self->list, &idx);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00382D30(void) {}
#undef std_list_deleter_int_tail /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00382D30 */
