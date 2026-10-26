#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int ScalarCollection_Init(char *);                       
int __register_global_object(char *, char *, char *);          
int std_tree_pair_tGenInfoPtr_value_compare_ctor(char *, char *, char *);                     
extern char D_005838A8;
extern char D_005838B8;
extern char D_005838C8;
extern char D_005838D8;
extern char D_005838E8;
extern char D_00583900;
extern char cAssocArray_tGenInfoPtr_bool_dtor;
extern char cLList_tGenInfoPtr_dtor;

void StaticInit_GenInfoObject(void) {
    int sp1C;
    int sp18;

    ScalarCollection_Init(&D_005838B8);
    __register_global_object(&D_005838B8, &cLList_tGenInfoPtr_dtor, &D_005838A8);
    ScalarCollection_Init(&D_005838D8);
    __register_global_object(&D_005838D8, &cLList_tGenInfoPtr_dtor, &D_005838C8);
    std_tree_pair_tGenInfoPtr_value_compare_ctor(&D_00583900, &sp1C, &sp18);
    __register_global_object(&D_00583900, &cAssocArray_tGenInfoPtr_bool_dtor, &D_005838E8);
}
