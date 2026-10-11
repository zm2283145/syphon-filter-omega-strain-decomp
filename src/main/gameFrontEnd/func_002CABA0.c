#include "types.h"
typedef struct NodeABA0 { struct NodeABA0* prev; struct NodeABA0* next; int key; } NodeABA0;
typedef struct { char pad[0x2FC]; char list[4]; char hdr[4]; } ObjABA0;
extern NodeABA0* func_002CAC70(void* p);
extern NodeABA0* func_002CAC60(void* p);
extern void func_002CAC50(NodeABA0** it, NodeABA0* n);
int* func_002CABA0(ObjABA0* o, int key)
{
    NodeABA0* n = func_002CAC70(o->hdr)->next;
    NodeABA0* e;
    func_002CAC50(&e, func_002CAC60(o->list));
    while (n != e) {
        if (key == n->key)
            return &n->key;
        n = n->next;
        func_002CAC50(&e, func_002CAC60(o->list));
    }
    return 0;
}