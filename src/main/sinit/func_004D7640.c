#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int ScalarCollection_Init();                       
int __construct_array();                
int __register_global_object();          
int std_tree_pair_tNPCInfoPtr_value_compare_ctor();                     
extern char D_00582820;
extern char D_00582AA0;
extern char D_00582AB0;
extern char D_00582AC0;
extern char D_00582AD0;
extern char D_00582AE0;
extern char D_00582AF0;
extern char D_00582B00;
extern char D_00582B10;
extern char D_00582B20;
extern char D_00582B30;
extern char D_00582B40;
extern char D_00582B50;
extern char cAssocArray_tNPCInfoPtr_bool_dtor;
extern char cLList_tNPCInfoPtr_dtor;
extern char cNPCInfoObject_tBoolStruct_ctor;

void StaticInit_NPCInfoObject(void) {
    int sp1C;
    int sp18;

    __construct_array(&D_00582820, &cNPCInfoObject_tBoolStruct_ctor, 0, 4, 145);
    ScalarCollection_Init(&D_00582AB0);
    __register_global_object(&D_00582AB0, &cLList_tNPCInfoPtr_dtor, &D_00582AA0);
    ScalarCollection_Init(&D_00582AD0);
    __register_global_object(&D_00582AD0, &cLList_tNPCInfoPtr_dtor, &D_00582AC0);
    ScalarCollection_Init(&D_00582AF0);
    __register_global_object(&D_00582AF0, &cLList_tNPCInfoPtr_dtor, &D_00582AE0);
    ScalarCollection_Init(&D_00582B10);
    __register_global_object(&D_00582B10, &cLList_tNPCInfoPtr_dtor, &D_00582B00);
    ScalarCollection_Init(&D_00582B30);
    __register_global_object(&D_00582B30, &cLList_tNPCInfoPtr_dtor, &D_00582B20);
    std_tree_pair_tNPCInfoPtr_value_compare_ctor(&D_00582B50, &sp1C, &sp18);
    __register_global_object(&D_00582B50, &cAssocArray_tNPCInfoPtr_bool_dtor, &D_00582B40);
}
