#include "types.h"
extern char D_005435B0[];
extern char D_005435C0[];
extern char D_005435D0[];
extern char D_005435E0[];
extern char D_005435F0[];
extern char D_00543600[];
extern int D_00543610;
extern int D_00543618;
extern void std_list_deleter_tQueuedMessage_ctor(void*);
extern void std_tree_pair_int_value_compare_cAllocator_pair_ctor_valuecompareR_cAllocatorR(void*, int*, int*);
extern void cLList_tQueuedMessage_dtor(void*, int);
extern void cAssocArray_int_cLList_tQueuedMessage_dtor(void*, int);
extern int cMessage_SOBJ_init(void);
extern void __register_global_object(void*, void*, void*);
extern int Script_RegisterType(void*, void*, int, int);
void StaticInit_RegisterMessageType(void)
{
    int a;
    int b;
    std_list_deleter_tQueuedMessage_ctor(D_005435C0);
    __register_global_object(D_005435C0, cLList_tQueuedMessage_dtor, D_005435B0);
    std_list_deleter_tQueuedMessage_ctor(D_005435E0);
    __register_global_object(D_005435E0, cLList_tQueuedMessage_dtor, D_005435D0);
    std_tree_pair_int_value_compare_cAllocator_pair_ctor_valuecompareR_cAllocatorR(D_00543600, &a, &b);
    __register_global_object(D_00543600, cAssocArray_int_cLList_tQueuedMessage_dtor, D_005435F0);
    D_00543610 = Script_RegisterType("cMessage", cMessage_SOBJ_init, 1, 0);
    D_00543618 = D_00543610;
}