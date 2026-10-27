/*
 * Libs/SFOLib/Source/interface_manager: 2 files, 00413880-004138F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00413880 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int std_basic_string_char_char_traits_char_ctor_charP();                      
int String_Dtor();                            
int std_vector_imp_cString_insert();               

#pragma opt_common_subs off
void func_00413880(char * arg0) {
    int sp20[4];
    char * temp_a0;

    if (F_(arg0, 0x1E4, int) != NULL) {
        std_basic_string_char_char_traits_char_ctor_charP(sp20);
        temp_a0 = (char *)(F_(arg0, 0x1E4, int));
        std_vector_imp_cString_insert(temp_a0, F_(temp_a0, 0x8, int) + (F_(temp_a0, 0x4, int) * 0xC), 1, sp20);
        String_Dtor(sp20, 0);
    }
}
static inline void merge_flush_func_00413880(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00413880 */

/* merge_units: begin func_004138F0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * interface_manager.cc
 */

#include "interface_manager_types.h"

/* Setter for unk1E0. */
void cInterfaceManager_SetHogList(IfManager* mgr, int value) {
    mgr->unk1E0 = value;
}
static inline void merge_flush_func_004138F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004138F0 */
