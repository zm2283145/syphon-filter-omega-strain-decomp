/* Re-sends an event to every widget of the screen stack's list that is still present in its set. */
#include "types.h"
typedef struct LNode {
    struct LNode* prev;
    struct LNode* next;
    int value;
} LNode;
typedef struct LIt { LNode* node; } LIt;
typedef struct LColl { int w[3]; } LColl;
extern int Gui_GetScreenStack(void);
extern void ScalarCollection_Init(void* LColl);
extern void List_Begin(LIt* out, void* list);
extern void func_0028C0B0(LIt* out, LIt* in);
extern void func_0028C0A0(LIt* out, void* list);
extern void func_0028C090(LIt* out, LIt* in);
extern void func_002CCE50(void* list, int* value);
extern void func_002CCE40(LIt* LIt);
extern void func_002CCE30(LIt* out, void* v);
extern void func_002CCE20(LIt* dst, LIt* src);
extern void func_002A88B0(LIt* out, void* t);
extern int func_002A8890(LIt* a, LIt* b);
extern int* func_002CCE10(LIt* LIt);
extern void func_002CCDF0(LIt* LIt);
extern void func_002CCDE0(LIt* dst, LIt* src);
extern void GuiWidget_SendEvent(int stack, int widget, unsigned short evt, int a, int b);
extern void func_002CCD80(void* LColl, int flag);
void App_Broadcast(int evt, int a, int b)
{
    if (Gui_GetScreenStack()) {
        LIt last1; LIt found; LIt endB; LIt last2; LIt it1; LIt it2; LIt begin1; LIt etmp1;
        LIt begin2; LIt etmp98; LIt fit; LIt btmp; LIt fend; LIt etmp2;
        LColl coll;
        void* list; LNode* node; void* set; int* val;
        ScalarCollection_Init(&coll);
        {
            list = (char*)Gui_GetScreenStack() + 0x28;
            List_Begin(&begin1, list);
            func_0028C0B0(&it1, &begin1);
            node = it1.node;
            func_0028C0A0(&etmp1, list);
            func_0028C090(&last1, &etmp1);
            while (node != last1.node) {
                func_002CCE50(&coll, &node->value);
                node = node->next;
                func_0028C0A0(&etmp1, list);
                func_0028C090(&last1, &etmp1);
            }
        }
        {
        List_Begin(&begin2, &coll);
        func_0028C0B0(&it2, &begin2);
        node = it2.node;
        func_0028C0A0(&etmp2, &coll);
        func_0028C090(&last2, &etmp2);
        while (node != last2.node) {
            func_0028C0A0(&etmp98, (char*)Gui_GetScreenStack() + 0x28);
            func_0028C090(&endB, &etmp98);
            {
                val = &node->value;
                set = (char*)Gui_GetScreenStack() + 0x28;
                func_002CCE40(&fit);
                func_002CCE30(&btmp, set);
                func_002CCE20(&fit, &btmp);
                func_002A88B0(&fend, set);
                while (func_002A8890(&fit, &fend)) {
                    { int* p = func_002CCE10(&fit); if (*p == *val) break; }
                    func_002CCDF0(&fit);
                    func_002A88B0(&fend, set);
                }
            }
            func_002CCDE0(&found, &fit);
            if (found.node != endB.node) {
                GuiWidget_SendEvent(Gui_GetScreenStack(), node->value, evt, a, b);
            }
            node = node->next;
            func_0028C0A0(&etmp2, &coll);
            func_0028C090(&last2, &etmp2);
        }
        }
        func_002CCD80(&coll, 0);
    }
}

