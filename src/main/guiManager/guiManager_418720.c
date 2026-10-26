/*
 * main/guiManager: 4 files, 00418720-00418840
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00418720 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(std_pair_cString_cFontPtr_dtor, String_Dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00418720 */

/* merge_units: begin func_00418780 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose04_types.h"

extern int String_CopyCtor(L4WordVec*, int);

int std_make_pair_cString_cFontP(L4WordVec* v, int a1, int value) {
    int ret = String_CopyCtor(v, a1);

    v->unk0C = value;
    return ret;
}
#pragma pop /* merge_units */
/* merge_units: end func_00418780 */

/* merge_units: begin func_004187C0 */
#pragma push /* merge_units */
extern int GuiFactory_CreateWidget(void* b);
extern void* GuiManager_LoadGui(void* a, void* c, int r);
void* GuiManager_CreateRoot(void* a, void* b, void* c) {
    int r = GuiFactory_CreateWidget(b);
    if (!r) return 0;
    /* .set reorder barrier keeps the empty then-arm */
    return GuiManager_LoadGui(a, c ? c : b, r);
}
#pragma pop /* merge_units */
/* merge_units: end func_004187C0 */

/* merge_units: begin func_00418840 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
/*fc*/
int cLListIterator_GuiWidgetPtr_ctor_listR();                        
int std_list_GuiWidgetPtr_end();                          
int opNe_cLListIteratorR_cLListIteratorR_6();                        
int cLList_GuiWidgetPtr_End();                          
int cLListIterator_GuiWidgetPtr_ctor_cLListIteratorR();                      
int cLListIterator_GuiWidgetPtr_opInc();                               
int *cLListIterator_GuiWidgetPtr_opMul();                            
int cLListIterator_GuiWidgetPtr_opAssign();                          
int cLList_GuiWidgetPtr_Begin();                          
int cLListIterator_GuiWidgetPtr_ctor_void();                               
int GuiManager_UnloadRoot();                    

typedef struct { char pad[0x18]; unsigned short cnt; } N418;
int GuiManager_ReleaseRoot(char *arg0, char *arg1) {
    char * sp4C;
    int sp48;
    int sp44;
    int sp40;
    int sp3C;
    int sp38;
    unsigned short temp_v0;
    N418 * temp_a1;

    cLListIterator_GuiWidgetPtr_ctor_void(&sp44);
    cLList_GuiWidgetPtr_Begin(&sp40, arg0 + 0x14);
    cLListIterator_GuiWidgetPtr_opAssign(&sp44, &sp40);
    cLList_GuiWidgetPtr_End(&sp3C, arg0 + 0x14);
    if (opNe_cLListIteratorR_cLListIteratorR_6(&sp44, &sp3C) != 0) {
loop_1:
        if ((void *)(*cLListIterator_GuiWidgetPtr_opMul(&sp44)) != (void *)(arg1)) {
            cLListIterator_GuiWidgetPtr_opInc(&sp44);
            cLList_GuiWidgetPtr_End(&sp3C, arg0 + 0x14);
            if (opNe_cLListIteratorR_cLListIteratorR_6(&sp44, &sp3C) == 0) {

            } else {
                goto loop_1;
            }
        }
    }
    cLListIterator_GuiWidgetPtr_ctor_cLListIteratorR(&sp4C, &sp44);
    std_list_GuiWidgetPtr_end(&sp38, arg0 + 0x14);
    cLListIterator_GuiWidgetPtr_ctor_listR(&sp48, &sp38);
    if ((int)sp4C == (int)sp48) {
        return 0;
    }
    temp_a1 = (N418 *)(F_(sp4C, 0x8, int));
    if (temp_a1->cnt == 0) {
        return 0;
    }
    if ((int)temp_a1->cnt > 0) {
        temp_a1->cnt--;
    }
    if (temp_a1->cnt == 0) {
        GuiManager_UnloadRoot(arg0, temp_a1, 0);
    }
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_00418840 */
