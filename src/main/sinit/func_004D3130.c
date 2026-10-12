#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int FreeList_Push(char **);                              
int String_CtorCStr_13B480(char *, char *);                 
int __register_global_object(char *, char *, char *);          
extern char D_004AB0C0;
extern char D_004AB0D0;
extern char D_004DD9B0;
extern char *D_00506540;
extern char *D_00506548;
extern char D_00506558;
extern char D_00506568;
extern char func_00138350;

void func_004D3130(void) {
    D_00506548 = &D_004DD9B0;
    D_00506540 = "GuiEquipmentSetup";
    FreeList_Push(&D_00506540);
    String_CtorCStr_13B480(&D_004AB0C0, "FEMALE.SKAS");
    __register_global_object(&D_004AB0C0, &func_00138350, &D_00506558);
    String_CtorCStr_13B480(&D_004AB0D0, "MALE.SKAS");
    __register_global_object(&D_004AB0D0, &func_00138350, &D_00506568);
}
