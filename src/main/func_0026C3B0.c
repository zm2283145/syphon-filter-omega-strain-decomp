#include "types.h"

typedef struct LNode { struct LNode* prev; struct LNode* next; int data; } LNode;
typedef struct LIt { LNode* node; } LIt;
typedef struct LList { int count; LNode* last; LNode* first; } LList;
typedef struct Obj { char pad[0x24]; LList list; } Obj;

extern int cHudTargetManager_GetObjectiveTarget(Obj* o);
extern void cHudTargetManager_SetObjectiveTarget(Obj* o, int v);
extern void std_list_deleter_voidPtr_begin_void_2(LIt* out, LList* l);
extern LIt* std_list_cHudTargetInfoPtr_generic_iterator_1_ctor(LIt* out, LNode* n);
extern void std_list_cHudTargetInfoPtr_end_void(LIt* out, LList* l);
extern LIt* cConstLListIterator_cHudTargetInfoPtr_ctor(LIt* dst, LIt* src);
extern void cMap_ObjectiveSelected(Obj** self);

int cMap_NextObjective(Obj** self) {
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
    if (!cHudTargetManager_GetObjectiveTarget(*self)) {
        a.node = l->first;
        b = a;
        cHudTargetManager_SetObjectiveTarget(*self, b.node->data);
    } else {
        if (l->count > 1) {
        std_list_deleter_voidPtr_begin_void_2(&t, l);
        std_list_cHudTargetInfoPtr_generic_iterator_1_ctor(&r, t.node);
        n = r.node;
        while (std_list_cHudTargetInfoPtr_end_void(&es, l), cConstLListIterator_cHudTargetInfoPtr_ctor(&ec, &es), n != ec.node) {
            if (n->data == cHudTargetManager_GetObjectiveTarget(*self)) {
                LNode* nx = n->next;
                std_list_cHudTargetInfoPtr_end_void(&bs, l);
                cConstLListIterator_cHudTargetInfoPtr_ctor(&bc, &bs);
                if (nx == bc.node) {
                    a2.node = l->first;
                    b2 = a2;
                    cHudTargetManager_SetObjectiveTarget(*self, b2.node->data);
                } else {
                    cHudTargetManager_SetObjectiveTarget(*self, nx->data);
                }
                break;
            }
            n = n->next;
        }
        } else {
            return 0;
        }
    }
    cMap_ObjectiveSelected(self);
    return 1;
}
