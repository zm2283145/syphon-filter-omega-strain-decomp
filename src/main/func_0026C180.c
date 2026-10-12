#include "types.h"

typedef struct LNode { struct LNode* prev; struct LNode* next; int data; } LNode;
typedef struct LIt { LNode* node; } LIt;
typedef struct LList { int count; LNode* last; LNode* first; } LList;
typedef struct Obj { char pad[0x24]; LList list; } Obj;

extern int func_00272AC0(Obj* o);
extern void func_00272AD0(Obj* o, int v);
extern void func_0016E880(LIt* out, LList* l);
extern LIt* func_0026C390(LIt* out, LNode* n);
extern void func_0026C320(LIt* out, LList* l);
extern LIt* func_0026C350(LIt* dst, LIt* src);
extern void func_0026C360(LIt* out, LList* l);
extern void func_0026C570(Obj** self);

int func_0026C180(Obj** self) {
    LIt bc;
    LIt ec;
    LIt r;
    LIt a;
    LIt b;
    LIt t;
    LIt bs;
    LIt es;
    LList* l = &(*self)->list;
    LNode* n;
    if ((*self)->list.count == 0) return 0;
    if (!func_00272AC0(*self)) {
        a.node = l->first;
        b = a;
        func_00272AD0(*self, b.node->data);
    } else {
        if (l->count > 1) {
        func_0016E880(&t, l);
        func_0026C390(&r, t.node);
        n = r.node;
        while (func_0026C320(&es, l), func_0026C350(&ec, &es), n != ec.node) {
            if (n->data == func_00272AC0(*self)) {
                func_0026C360(&bs, l);
                func_0026C350(&bc, &bs);
                if (n == bc.node) {
                    func_00272AD0(*self, l->last->data);
                } else {
                    func_00272AD0(*self, n->prev->data);
                }
                break;
            }
            n = n->next;
        }
        } else {
            return 0;
        }
    }
    func_0026C570(self);
    return 1;
}
