#include "types.h"

typedef struct LNode { struct LNode* prev; struct LNode* next; int data; } LNode;
typedef struct LIt { LNode* node; } LIt;
typedef struct LList { int count; LNode* last; LNode* first; } LList;
typedef struct Obj { char pad[0x24]; LList list; } Obj;

extern int HudMarkers_GetHighlight(Obj* o);
extern void HudMarkers_SetHighlight(Obj* o, int v);
extern void List_Begin_16E880(LIt* out, LList* l);
extern LIt* func_0026C390(LIt* out, LNode* n);
extern void func_0026C320(LIt* out, LList* l);
extern LIt* func_0026C350(LIt* dst, LIt* src);
extern void HudMap_Commit(Obj** self);

int HudMap_NextMarker(Obj** self) {
    LIt bc;
    LIt ec;
    LIt r;
    LIt a;
    LIt a2;
    LIt b;
    LIt b2;
    LIt t;
    LIt bs;
    LIt es;
    LList* l = &(*self)->list;
    LNode* n;
    if ((*self)->list.count == 0) return 0;
    if (!HudMarkers_GetHighlight(*self)) {
        a.node = l->first;
        b = a;
        HudMarkers_SetHighlight(*self, b.node->data);
    } else {
        if (l->count > 1) {
        List_Begin_16E880(&t, l);
        func_0026C390(&r, t.node);
        n = r.node;
        while (func_0026C320(&es, l), func_0026C350(&ec, &es), n != ec.node) {
            if (n->data == HudMarkers_GetHighlight(*self)) {
                LNode* nx = n->next;
                func_0026C320(&bs, l);
                func_0026C350(&bc, &bs);
                if (nx == bc.node) {
                    a2.node = l->first;
                    b2 = a2;
                    HudMarkers_SetHighlight(*self, b2.node->data);
                } else {
                    HudMarkers_SetHighlight(*self, nx->data);
                }
                break;
            }
            n = n->next;
        }
        } else {
            return 0;
        }
    }
    HudMap_Commit(self);
    return 1;
}
