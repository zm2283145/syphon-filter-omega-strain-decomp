#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int __construct_array(char *, char *, int, int, int);                
int __register_global_object(char *, char *, char *);          
int func_003FCC80(char *, char *, char *);                     
int std_tree_pair_int_value_compare_ctor_valuecompareR_cAllocatorR_2(char *, char *, char *);                     
extern char D_0055C758;
extern char D_0055C770;
extern char D_0055C788;
extern char D_0055C7A0;
extern char D_0055C7C0;
extern char cNetObj_tPingInfo_ctor;
extern char cAssocArray_int_netSystemField_dtor;
extern char cAssocArray_int_cSafePtr_cGOBJ_dtor;

void StaticInit_NetObj(void) {
    int sp1C;
    int sp18;
    int sp14;
    int sp10;

    func_003FCC80(&D_0055C770, &sp1C, &sp18);
    __register_global_object(&D_0055C770, &cAssocArray_int_cSafePtr_cGOBJ_dtor, &D_0055C758);
    std_tree_pair_int_value_compare_ctor_valuecompareR_cAllocatorR_2(&D_0055C7A0, &sp14, &sp10);
    __register_global_object(&D_0055C7A0, &cAssocArray_int_netSystemField_dtor, &D_0055C788);
    __construct_array(&D_0055C7C0, &cNetObj_tPingInfo_ctor, 0, 0x98, 3);
}
