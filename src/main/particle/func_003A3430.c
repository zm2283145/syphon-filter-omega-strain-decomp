#include "types.h"

typedef union Key3430 {
    __int128 q;
    long l[2];
} Key3430;

static inline int KeyEq(Key3430* a, Key3430* b) { return (long)a->q == (long)b->q && a->l[1] == b->l[1]; }

typedef struct Item3430 {
    char pad[0x170];
    Key3430 key;               /* 0x170 */
} Item3430;

typedef struct Node3430 {
    struct Node3430* prev;
    struct Node3430* next;      /* 0x04 */
    Item3430* item;             /* 0x08 */
} Node3430;

typedef struct It3430 {
    Node3430* node;
} It3430;

typedef struct Mgr3430 {
    int unk0;
    char list[0xC];             /* 0x04 */
} Mgr3430;

extern void func_003A3590(It3430* out, void* list);
extern void func_003A3550(It3430* out, void* list);
extern It3430* func_003A3580(It3430* dst, It3430* src);

int ParticleDefs_FindByName(Mgr3430* m, Key3430* key)
{
    It3430 it;
    It3430 cb;
    It3430 ce;
    It3430 b;
    It3430 e;
    int found = -1;
    int i = 0;
    long* khi;

    func_003A3590(&b, m->list);
    func_003A3580(&cb, &b);
    it = cb;
    func_003A3550(&e, m->list);
    func_003A3580(&ce, &e);
    khi = &key->l[1];
    while (it.node != ce.node) {
        Key3430* k = &it.node->item->key;
        if ((long)key->q == (long)k->q && *khi == k->l[1]) {
            found = i;
            break;
        }
        i++;
        it.node = it.node->next;
        func_003A3550(&e, m->list);
        func_003A3580(&ce, &e);
    }
    return found;
}






