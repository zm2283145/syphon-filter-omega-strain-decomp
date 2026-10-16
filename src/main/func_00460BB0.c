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
void func_0041F150(S460BB0*);
int func_002C9EE0(void*);
TraversalWidget* GuiWidget_FindChildByName(void*, const char*);
void List_Begin(ChildIterator* result, ChildList* list);
void func_0028C0B0(ChildIterator* result, const ChildIterator* source);
void func_0028C0A0(ChildIterator* result, ChildList* list);
void func_0028C090(ChildIterator* result, const ChildIterator* source);
void func_00460BB0(S460BB0* self);
}

void func_00460BB0(S460BB0* self)
{
    W460BB0* w;
    ChildNode* node;
    func_0041F150(self);
    if (func_002C9EE0(D_004FFC04)) {
        TraversalWidget* grp = GuiWidget_FindChildByName(self, D_004C24E8);
        if (grp) {
            ChildList* list = &grp->children;
            if (list->count == 15) {
                ChildIterator end;
                ChildIterator begin;
                ChildIterator rawBegin;
                ChildIterator rawEnd;
                int i;
                List_Begin(&rawBegin, list);
                func_0028C0B0(&begin, &rawBegin);
                node = begin.node;
                func_0028C0A0(&rawEnd, list);
                func_0028C090(&end, &rawEnd);
                i = 0;
                while (node != end.node) {
                    w = (W460BB0*)node->widget;
                    self->slots[i].w = (w && w->IsA(D_004B88F0)) ? w : 0;
                    node = node->next;
                    i++;
                    func_0028C0A0(&rawEnd, list);
                    func_0028C090(&end, &rawEnd);
                }
            }
        }
    }
    self->border = GuiWidget_FindChildByName(self, D_004C24F8);
}




