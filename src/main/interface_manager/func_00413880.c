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
