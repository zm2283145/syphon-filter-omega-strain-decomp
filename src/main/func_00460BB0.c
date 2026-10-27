#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#include "gui_traversal_types.h"

struct W460BB0 { VPAD16(a) VPAD4(b) virtual int IsA(const char* type); };
struct Slot460BB0 { W460BB0* w; char pad[0x14]; };
struct S460BB0 { char pad[0x48]; Slot460BB0 slots[15]; TraversalWidget* border; };

extern "C" {
extern void* D_004FFC04;
extern char D_004C24E8[];
extern char D_004C24F8[];
extern char D_004B88F0[];
void GuiWidget_onAdd(S460BB0*);
int cGameFrontEnd_OpenZeusHog(void*);
TraversalWidget* GuiWidget_FindChild_charP(void*, const char*);
void std_list_deleter_voidPtr_begin_void(ChildIterator* result, ChildList* list);
void std_list_GuiWidgetPtr_generic_iterator_ctor(ChildIterator* result, const ChildIterator* source);
void std_list_GuiWidgetPtr_end(ChildIterator* result, ChildList* list);
void cLListIterator_GuiWidgetPtr_ctor_listR(ChildIterator* result, const ChildIterator* source);
void GuiEndGameAwards_onAdd(S460BB0* self);
}

void GuiEndGameAwards_onAdd(S460BB0* self)
{
    W460BB0* w;
    ChildNode* node;
    GuiWidget_onAdd(self);
    if (cGameFrontEnd_OpenZeusHog(D_004FFC04)) {
        TraversalWidget* grp = GuiWidget_FindChild_charP(self, D_004C24E8);
        if (grp) {
            ChildList* list = &grp->children;
            if (list->count == 15) {
                ChildIterator end;
                ChildIterator begin;
                ChildIterator rawBegin;
                ChildIterator rawEnd;
                int i;
                std_list_deleter_voidPtr_begin_void(&rawBegin, list);
                std_list_GuiWidgetPtr_generic_iterator_ctor(&begin, &rawBegin);
                node = begin.node;
                std_list_GuiWidgetPtr_end(&rawEnd, list);
                cLListIterator_GuiWidgetPtr_ctor_listR(&end, &rawEnd);
                i = 0;
                while (node != end.node) {
                    w = (W460BB0*)node->widget;
                    self->slots[i].w = (w && w->IsA(D_004B88F0)) ? w : 0;
                    node = node->next;
                    i++;
                    std_list_GuiWidgetPtr_end(&rawEnd, list);
                    cLListIterator_GuiWidgetPtr_ctor_listR(&end, &rawEnd);
                }
            }
        }
    }
    self->border = GuiWidget_FindChild_charP(self, D_004C24F8);
}




