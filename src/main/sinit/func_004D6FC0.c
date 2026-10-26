#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int __register_global_object(char *, char *, char *);          
int std_tree_pair_cObjectId_value_compare_ctor(char *, char *, char *);                     
extern int D_00571770;
extern int D_00571774;
extern char D_00571C00;
extern char D_00571C10;
extern char cAssocArray_cObjectId_cSystemPtr_dtor;

void StaticInit_GobjMan(void) {
    int sp1C;
    int sp18;

    D_00571770 = 0;
    D_00571774 = -2;
    std_tree_pair_cObjectId_value_compare_ctor(&D_00571C10, &sp1C, &sp18);
    __register_global_object(&D_00571C10, &cAssocArray_cObjectId_cSystemPtr_dtor, &D_00571C00);
}
