#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int AbstractWidgetClassRep_AddClassRep(char **);                              
int std_basic_string_char_char_traits_char_ctor_charP(char *, char *);                 
int __register_global_object(char *, char *, char *);          
extern char D_004BB4B8;
extern char D_004BB4C8;
extern char D_004DF330;
extern char *D_00533750;
extern char *D_00533758;
extern char D_00533768;
extern char D_00533778;
extern char String_Dtor_138350;

void StaticInit_GuiScoresEquip(void) {
    D_00533758 = &D_004DF330;
    D_00533750 = "GuiScoresEquip";
    AbstractWidgetClassRep_AddClassRep(&D_00533750);
    std_basic_string_char_char_traits_char_ctor_charP(&D_004BB4B8, "FEMALE.SKAS");
    __register_global_object(&D_004BB4B8, &String_Dtor_138350, &D_00533768);
    std_basic_string_char_char_traits_char_ctor_charP(&D_004BB4C8, "MALE.SKAS");
    __register_global_object(&D_004BB4C8, &String_Dtor_138350, &D_00533778);
}
