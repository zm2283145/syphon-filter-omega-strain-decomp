#include "types.h"

typedef struct LNode { struct LNode* prev; struct LNode* next; int data; } LNode;
typedef struct LIt { LNode* node; } LIt;
typedef struct LList { int count; LNode* last; LNode* first; } LList;
typedef struct Obj { char pad[0x24]; LList list; } Obj;

extern int HudMarkers_GetHighlight(Obj* o);
extern void HudMarkers_SetHighlight(Obj* o, int v);
extern void List_Begin_16E880(LIt* out, LList* l);
extern LIt* std_list_cHudTargetInfoPtr_generic_iterator_1_ctor(LIt* out, LNode* n);
extern void std_list_cHudTargetInfoPtr_end_void(LIt* out, LList* l);
extern LIt* cConstLListIterator_cHudTargetInfoPtr_ctor(LIt* dst, LIt* src);
extern void std_list_cHudTargetInfoPtr_begin_void(LIt* out, LList* l);
extern void HudMap_Commit(Obj** self);

int HudMap_PrevMarker(Obj** self) {
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
    if (!HudMarkers_GetHighlight(*self)) {
        a.node = l->first;
        b = a;
        HudMarkers_SetHighlight(*self, b.node->data);
    } else {
        if (l->count > 1) {
        List_Begin_16E880(&t, l);
        std_list_cHudTargetInfoPtr_generic_iterator_1_ctor(&r, t.node);
        n = r.node;
        while (std_list_cHudTargetInfoPtr_end_void(&es, l), cConstLListIterator_cHudTargetInfoPtr_ctor(&ec, &es), n != ec.node) {
            if (n->data == HudMarkers_GetHighlight(*self)) {
                std_list_cHudTargetInfoPtr_begin_void(&bs, l);
                cConstLListIterator_cHudTargetInfoPtr_ctor(&bc, &bs);
                if (n == bc.node) {
                    HudMarkers_SetHighlight(*self, l->last->data);
                } else {
                    HudMarkers_SetHighlight(*self, n->prev->data);
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
