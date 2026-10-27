/*
 * Libs/SFOLib/Source/guiTextEditWidget: 1 file, 0041AE90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin guiManager_41AE90 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
typedef __int128 Q128;
#pragma mpwc_relax on
int std_basic_string_char_char_traits_char_opAddAssign(char *, int);                          
int std_basic_string_char_char_traits_char_reserve(char *);                              
int String_Dtor(char *, int);                            
int std_basic_string_char_char_traits_char_c_str(char *);                             
int cTextArea_SetText(int, int);                          

void MaskTextArea(int arg0, int arg1) {
    Q128 sp40[1];
    int var_s0;

    if (arg0 != 0) {
        { int *sp_ = (int *)sp40; sp_[0] = 0; sp_[1] = 0; sp_[2] = 0; std_basic_string_char_char_traits_char_reserve((char *)sp_); }
        for (var_s0 = 0; var_s0 < arg1; var_s0++) {
                std_basic_string_char_char_traits_char_opAddAssign(&sp40, 0x23);
        }
        cTextArea_SetText(arg0, std_basic_string_char_char_traits_char_c_str(&sp40));
        String_Dtor(&sp40, 0);
    }
}
static inline void merge_flush_guiManager_41AE90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end guiManager_41AE90 */
