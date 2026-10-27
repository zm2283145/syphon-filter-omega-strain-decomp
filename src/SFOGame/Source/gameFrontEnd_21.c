/*
 * SFOGame/Source/gameFrontEnd: 4 files, 002CC980-002CCCA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002CC980 */
#pragma push /* merge_units */
#include "types.h"
extern char* D_0048C160[];
extern int D_0051EEC0[];
extern int D_0051EF10[];
extern int nGlobalization_GetStringIndex(const char* key);
extern int sprintf(char* buf, const char* fmt, ...);
void SFOLevels_SetupMissionInfo(void)
{
    char buf[0x10];
    int i;
    for (i = 0; i < 0x12; i++) {
        D_0051EEC0[i] = nGlobalization_GetStringIndex(D_0048C160[i]);
        sprintf(buf, "SHORT_LEVEL%d", i);
        D_0051EF10[i] = nGlobalization_GetStringIndex(buf);
    }
}
static inline void merge_flush_func_002CC980(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002CC980 */

/* merge_units: begin func_002CCA20 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "gameFrontEnd_types.h"

extern char D_005723D0;     /* setup guard byte */
extern int nGlobalization_GetLanguageName_void(void);

void FrontEnd_SetOnlineMode(FeItem* item, int value) {
    D_005723D0 = 0;
    item->unk30 = value;
}

int Loc_GetCurrentLanguageName_Thunk(void) {
    return nGlobalization_GetLanguageName_void();
}
static inline void merge_flush_func_002CCA20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002CCA20 */

/* merge_units: begin func_002CCA40 */
#pragma push /* merge_units */
/* Re-sends an event to every widget of the screen stack's list that is still present in its set. */
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
static inline void merge_flush_func_002CCA40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002CCA40 */

/* merge_units: begin func_002CCCA0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(GuiWidgetList_dtor, std_list_GuiWidgetPtr_dtor)
static inline void merge_flush_func_002CCCA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002CCCA0 */
