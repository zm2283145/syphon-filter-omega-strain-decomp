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
DEFINE_BASE_DTOR_CHAIN(func_00418720, String_Dtor)
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

extern int func_0013BCB0(L4WordVec*, int);

int func_00418780(L4WordVec* v, int a1, int value) {
    int ret = func_0013BCB0(v, a1);

    v->unk0C = value;
    return ret;
}
#pragma pop /* merge_units */
/* merge_units: end func_00418780 */

/* merge_units: begin func_004187C0 */
#pragma push /* merge_units */
extern int func_0041F960(void* b);
extern void* GuiManager_LoadGui(void* a, void* c, int r);
void* func_004187C0(void* a, void* b, void* c) {
    int r = func_0041F960(b);
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
int func_0028C090();                        
int func_0028C0A0();                          
int func_002A8890();                        
int func_002A88B0();                          
int func_002CCDE0();                      
int func_002CCDF0();                               
int *func_002CCE10();                            
int func_002CCE20();                          
int func_002CCE30();                          
int func_002CCE40();                               
int func_00418E00();                    

typedef struct { char pad[0x18]; unsigned short cnt; } N418;
int func_00418840(char *arg0, char *arg1) {
    char * sp4C;
    int sp48;
    int sp44;
    int sp40;
    int sp3C;
    int sp38;
    unsigned short temp_v0;
    N418 * temp_a1;

    func_002CCE40(&sp44);
    func_002CCE30(&sp40, arg0 + 0x14);
    func_002CCE20(&sp44, &sp40);
    func_002A88B0(&sp3C, arg0 + 0x14);
    if (func_002A8890(&sp44, &sp3C) != 0) {
loop_1:
        if ((void *)(*func_002CCE10(&sp44)) != (void *)(arg1)) {
            func_002CCDF0(&sp44);
            func_002A88B0(&sp3C, arg0 + 0x14);
            if (func_002A8890(&sp44, &sp3C) == 0) {

            } else {
                goto loop_1;
            }
        }
    }
    func_002CCDE0(&sp4C, &sp44);
    func_0028C0A0(&sp38, arg0 + 0x14);
    func_0028C090(&sp48, &sp38);
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
        func_00418E00(arg0, temp_a1, 0);
    }
    return 1;
}
#pragma pop /* merge_units */
/* merge_units: end func_00418840 */
