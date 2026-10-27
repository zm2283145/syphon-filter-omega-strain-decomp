#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
int nGlobalization_GetString_charP(signed char *);                           
signed char *std_basic_string_char_char_traits_char_c_str(int);                             
int cHudTargetInfo_GetObjectiveString();                                
int sprintf(int, int *, int, int);                      

int cHudTargetInfo_GetObjectiveLocationString(int arg0, int arg1) {
    int temp_v0;
    int var_a3;
    signed char *temp_v0_2;

    if (arg1 == 0) {
        return 0;
    }
    temp_v0 = cHudTargetInfo_GetObjectiveString();
    if (temp_v0 == 0) {
        return 0;
    }
    temp_v0_2 = std_basic_string_char_char_traits_char_c_str(arg0 + 0x28);
    var_a3 = 0;
    if ((temp_v0_2 != NULL) && (*temp_v0_2 != 0)) {
        var_a3 = nGlobalization_GetString_charP(temp_v0_2);
    }
    if (var_a3 != 0) {
        sprintf(arg1, ((int*)"%s %s"), temp_v0, var_a3);
        return arg1;
    }
    return temp_v0;
}
