/*
 * main/specfx: 2 files, 003EC3E0-003EC4C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003EC3E0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


struct VC003EC3E0 { char vpad[20]; virtual int v0(...); };
extern "C" {
int std_list_deleter_voidPtr_erase_listdeleter(...);                     
int std_list_deleter_voidPtr_begin_void(...);                          
int std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(...);                      
int cLListIterator_cSfxSchedulerPtr_ctor(...);                        
int std_list_cSfxSchedulerPtr_end(...);                          
int std_list_cSfxSchedulerPtr_generic_iterator_ctor(...);                      
extern char D_0055C0A8;
}
extern "C" void nDynamicSfxList_Clear(void) {
    int sp3C;
    char * sp38;
    char * sp34;
    int sp30;
    int sp2C;
    int sp28;
    int sp24;
    char * temp_a0;
    char * temp_v0;
    char * var_s0;

    std_list_deleter_voidPtr_begin_void(&sp28, &D_0055C0A8);
    std_list_cSfxSchedulerPtr_generic_iterator_ctor(&sp38, &sp28);
    var_s0 = sp38;
    std_list_cSfxSchedulerPtr_end(&sp24, &D_0055C0A8);
    cLListIterator_cSfxSchedulerPtr_ctor(&sp3C, &sp24);
    if ((int)(var_s0) != (int)(sp3C)) {
        do {
            temp_a0 = (char *)(F_(var_s0, 0x8, int));
            if (temp_a0 != NULL) {
                ((VC003EC3E0 *)(temp_a0))->v0(1);
            }
            temp_v0 = var_s0;
            var_s0 = (char *)(F_(var_s0, 0x4, int));
            sp34 = temp_v0;
            std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(&sp2C, &sp34);
            std_list_deleter_voidPtr_erase_listdeleter(&sp30, &D_0055C0A8, &sp2C);
            std_list_cSfxSchedulerPtr_end(&sp24, &D_0055C0A8);
            cLListIterator_cSfxSchedulerPtr_ctor(&sp3C, &sp24);
        } while ((int)(var_s0) != (int)(sp3C));
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_003EC3E0 */

/* merge_units: begin func_003EC4C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma mpwc_relax on

struct VC003EC4C0 { char vpad[12]; unsigned char dead; char pad[7]; virtual void v0(int); virtual void v1(float); };
extern "C" {
}
extern "C" void nDynamicSfxList_NextFrame(float dt) {
    int sp5C;
    char * sp58;
    char * sp54;
    int sp50;
    int sp4C;
    int sp48;
    int sp44;
    VC003EC4C0 * obj;
    char * temp_v0;
    char * var_s0;

    std_list_deleter_voidPtr_begin_void(&sp48, &D_0055C0A8);
    std_list_cSfxSchedulerPtr_generic_iterator_ctor(&sp58, &sp48);
    var_s0 = sp58;
    std_list_cSfxSchedulerPtr_end(&sp44, &D_0055C0A8);
    cLListIterator_cSfxSchedulerPtr_ctor(&sp5C, &sp44);
    if ((int)(var_s0) != (int)(sp5C)) {
        do {
            obj = F_(var_s0, 0x8, VC003EC4C0 *);
            obj->v1(dt);
            if (obj->dead) {
                if (obj != 0) {
                    obj->v0(1);
                }
                temp_v0 = var_s0;
                var_s0 = (char *)(F_(var_s0, 0x4, int));
                sp54 = temp_v0;
                std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(&sp4C, &sp54);
                std_list_deleter_voidPtr_erase_listdeleter(&sp50, &D_0055C0A8, &sp4C);
            } else {
                var_s0 = (char *)(F_(var_s0, 0x4, int));
            }
            std_list_cSfxSchedulerPtr_end(&sp44, &D_0055C0A8);
            cLListIterator_cSfxSchedulerPtr_ctor(&sp5C, &sp44);
        } while ((int)(var_s0) != (int)(sp5C));
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_003EC4C0 */
