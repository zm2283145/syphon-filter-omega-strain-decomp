#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int __register_global_object(char *, char *, char *);          
int func_00431320(char *, char *, char *);                     
int std_tree_pair_int_value_compare_ctor_valuecompareR_cAllocatorR_3(char *, char *, char *);                     
int std_tree_pair_short_value_compare_ctor(char *, char *, char *);                     
int std_tree_pair_int_value_compare_ctor_valuecompareR_cAllocatorR_4(char *, char *, char *);                     
int std_tree_pair_int_value_compare_ctor_valuecompareR_cAllocatorR_5(char *, char *, char *);                     
extern char D_00582690;
extern char D_005826A0;
extern char D_005826B0;
extern char D_005826C0;
extern char D_005826D0;
extern char D_005826E0;
extern char D_005826F0;
extern char D_00582700;
extern char D_00582710;
extern char D_00582720;
extern char *D_00582730;
extern char cAssocArray_int_netActivationList_dtor;
extern char cAssocArray_int_tNetActivateTerrainObjectPtr_dtor;
extern char cAssocArray_int_cMessagePtr_dtor;
extern char std_multimap_short_tNetObjectPtr_dtor;
extern char cAssocArray_int_tNetObjectPtr_dtor;

void StaticInit_RegisterSwitchControllersMsg(void) {
    int sp3C;
    int sp38;
    int sp34;
    int sp30;
    int sp2C;
    int sp28;
    int sp24;
    int sp20;
    int sp1C;
    int sp18;

    func_00431320(&D_005826A0, &sp34, &sp30);
    __register_global_object(&D_005826A0, &cAssocArray_int_tNetObjectPtr_dtor, &D_00582690);
    std_tree_pair_int_value_compare_ctor_valuecompareR_cAllocatorR_3(&D_005826C0, &sp3C, &sp38);
    __register_global_object(&D_005826C0, &std_multimap_short_tNetObjectPtr_dtor, &D_005826B0);
    std_tree_pair_short_value_compare_ctor(&D_005826E0, &sp2C, &sp28);
    __register_global_object(&D_005826E0, &cAssocArray_int_cMessagePtr_dtor, &D_005826D0);
    std_tree_pair_int_value_compare_ctor_valuecompareR_cAllocatorR_4(&D_00582700, &sp24, &sp20);
    __register_global_object(&D_00582700, &cAssocArray_int_tNetActivateTerrainObjectPtr_dtor, &D_005826F0);
    std_tree_pair_int_value_compare_ctor_valuecompareR_cAllocatorR_5(&D_00582720, &sp1C, &sp18);
    __register_global_object(&D_00582720, &cAssocArray_int_netActivationList_dtor, &D_00582710);
    D_00582730 = "cSwitchControllersMsg";
}
