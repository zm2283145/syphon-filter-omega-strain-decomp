#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int FreeList_Push(char **);                              
int String_CtorCStr_13B480(char *, char *);                 
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
    FreeList_Push(&D_00533750);
    String_CtorCStr_13B480(&D_004BB4B8, "FEMALE.SKAS");
    __register_global_object(&D_004BB4B8, &String_Dtor_138350, &D_00533768);
    String_CtorCStr_13B480(&D_004BB4C8, "MALE.SKAS");
    __register_global_object(&D_004BB4C8, &String_Dtor_138350, &D_00533778);
}
