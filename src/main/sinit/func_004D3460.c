#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int AbstractWidgetClassRep_AddClassRep(char **);                              
int std_basic_string_char_char_traits_char_ctor_charP(char *, char *);                 
int __register_global_object(char *, char *, char *);          
extern char D_004AC288;
extern char D_004AC298;
extern char D_004DE0D0;
extern char *D_0051EE00;
extern char *D_0051EE08;
extern char D_0051EE18;
extern char D_0051EE28;
extern char String_Dtor_138350;

void StaticInit_GuiEquipmentModify(void) {
    D_0051EE08 = &D_004DE0D0;
    D_0051EE00 = "GuiEquipmentModify";
    AbstractWidgetClassRep_AddClassRep(&D_0051EE00);
    std_basic_string_char_char_traits_char_ctor_charP(&D_004AC288, "FEMALE.SKAS");
    __register_global_object(&D_004AC288, &String_Dtor_138350, &D_0051EE18);
    std_basic_string_char_char_traits_char_ctor_charP(&D_004AC298, "MALE.SKAS");
    __register_global_object(&D_004AC298, &String_Dtor_138350, &D_0051EE28);
}
