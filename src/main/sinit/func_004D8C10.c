#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int __register_global_object(char *, char *, char *);          
int std_tree_pair_int_value_compare_ctor_valuecompareR_cAllocatorR_6(char *, char *, char *);                     
extern char D_00588008;
extern char D_00588020;
extern char cAssocArray_int_sMsgTypeInfo_dtor;

void StaticInit_NetMsgThrottle(void) {
    int sp1C;
    int sp18;

    std_tree_pair_int_value_compare_ctor_valuecompareR_cAllocatorR_6(&D_00588020, &sp1C, &sp18);
    __register_global_object(&D_00588020, &cAssocArray_int_sMsgTypeInfo_dtor, &D_00588008);
}
