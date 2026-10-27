/* Re-sends an event to every widget of the screen stack's list that is still present in its set. */
#include "types.h"
typedef struct LNode {
    struct LNode* prev;
    struct LNode* next;
    int value;
} LNode;
typedef struct LIt { LNode* node; } LIt;
typedef struct LColl { int w[3]; } LColl;
extern int Gui_Canvas(void);
extern void std_list_deleter_voidPtr_ctor_void(void* LColl);
extern void std_list_deleter_voidPtr_begin_void(LIt* out, void* list);
extern void std_list_GuiWidgetPtr_generic_iterator_ctor(LIt* out, LIt* in);
extern void std_list_GuiWidgetPtr_end(LIt* out, void* list);
extern void cLListIterator_GuiWidgetPtr_ctor_listR(LIt* out, LIt* in);
extern void std_list_GuiWidgetPtr_push_back_GuiWidgetPR(void* list, int* value);
extern void cLListIterator_GuiWidgetPtr_ctor_void(LIt* LIt);
extern void cLList_GuiWidgetPtr_Begin(LIt* out, void* v);
extern void cLListIterator_GuiWidgetPtr_opAssign(LIt* dst, LIt* src);
extern void cLList_GuiWidgetPtr_End(LIt* out, void* t);
extern int opNe_cLListIteratorR_cLListIteratorR_6(LIt* a, LIt* b);
extern int* cLListIterator_GuiWidgetPtr_opMul(LIt* LIt);
extern void cLListIterator_GuiWidgetPtr_opInc(LIt* LIt);
extern void cLListIterator_GuiWidgetPtr_ctor_cLListIteratorR(LIt* dst, LIt* src);
extern void GuiWidget_SendMessage(int stack, int widget, unsigned short evt, int a, int b);
extern void cLList_GuiWidgetPtr_dtor(void* LColl, int flag);
void cGameFrontEnd_LobbySendShutdownMessage(int evt, int a, int b)
{
    if (Gui_Canvas()) {
        LIt last1; LIt found; LIt endB; LIt last2; LIt it1; LIt it2; LIt begin1; LIt etmp1;
        LIt begin2; LIt etmp98; LIt fit; LIt btmp; LIt fend; LIt etmp2;
        LColl coll;
        void* list; LNode* node; void* set; int* val;
        std_list_deleter_voidPtr_ctor_void(&coll);
        {
            list = (char*)Gui_Canvas() + 0x28;
            std_list_deleter_voidPtr_begin_void(&begin1, list);
            std_list_GuiWidgetPtr_generic_iterator_ctor(&it1, &begin1);
            node = it1.node;
            std_list_GuiWidgetPtr_end(&etmp1, list);
            cLListIterator_GuiWidgetPtr_ctor_listR(&last1, &etmp1);
            while (node != last1.node) {
                std_list_GuiWidgetPtr_push_back_GuiWidgetPR(&coll, &node->value);
                node = node->next;
                std_list_GuiWidgetPtr_end(&etmp1, list);
                cLListIterator_GuiWidgetPtr_ctor_listR(&last1, &etmp1);
            }
        }
        {
        std_list_deleter_voidPtr_begin_void(&begin2, &coll);
        std_list_GuiWidgetPtr_generic_iterator_ctor(&it2, &begin2);
        node = it2.node;
        std_list_GuiWidgetPtr_end(&etmp2, &coll);
        cLListIterator_GuiWidgetPtr_ctor_listR(&last2, &etmp2);
        while (node != last2.node) {
            std_list_GuiWidgetPtr_end(&etmp98, (char*)Gui_Canvas() + 0x28);
            cLListIterator_GuiWidgetPtr_ctor_listR(&endB, &etmp98);
            {
                val = &node->value;
                set = (char*)Gui_Canvas() + 0x28;
                cLListIterator_GuiWidgetPtr_ctor_void(&fit);
                cLList_GuiWidgetPtr_Begin(&btmp, set);
                cLListIterator_GuiWidgetPtr_opAssign(&fit, &btmp);
                cLList_GuiWidgetPtr_End(&fend, set);
                while (opNe_cLListIteratorR_cLListIteratorR_6(&fit, &fend)) {
                    { int* p = cLListIterator_GuiWidgetPtr_opMul(&fit); if (*p == *val) break; }
                    cLListIterator_GuiWidgetPtr_opInc(&fit);
                    cLList_GuiWidgetPtr_End(&fend, set);
                }
            }
            cLListIterator_GuiWidgetPtr_ctor_cLListIteratorR(&found, &fit);
            if (found.node != endB.node) {
                GuiWidget_SendMessage(Gui_Canvas(), node->value, evt, a, b);
            }
            node = node->next;
            std_list_GuiWidgetPtr_end(&etmp2, &coll);
            cLListIterator_GuiWidgetPtr_ctor_listR(&last2, &etmp2);
        }
        }
        cLList_GuiWidgetPtr_dtor(&coll, 0);
    }
}

