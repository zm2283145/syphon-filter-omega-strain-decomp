#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int FreeList_Push(char **);                              
int String_CtorCStr_13B480(char *, char *);                 
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
    FreeList_Push(&D_0051EE00);
    String_CtorCStr_13B480(&D_004AC288, "FEMALE.SKAS");
    __register_global_object(&D_004AC288, &String_Dtor_138350, &D_0051EE18);
    String_CtorCStr_13B480(&D_004AC298, "MALE.SKAS");
    __register_global_object(&D_004AC298, &String_Dtor_138350, &D_0051EE28);
}
