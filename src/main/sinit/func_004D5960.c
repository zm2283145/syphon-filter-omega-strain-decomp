#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int cScriptBase_addClass(char *, char *, int, int);            
int __register_global_object(char *, char *, char *);          
int std_tree_pair_cSystemPtr_value_compare_ctor(char *, char *, char *);                     
extern char D_00543620;
extern char D_00543630;
extern int g_cSystemScriptTypeKey;
extern int D_00543648;
extern char *D_00543650;
extern char cSystem_SOBJ_init;
extern char cAssocArray_cSystemPtr_int_dtor;

void StaticInit_system(void) {
    int sp1C;
    int sp18;

    std_tree_pair_cSystemPtr_value_compare_ctor(&D_00543630, &sp1C, &sp18);
    __register_global_object(&D_00543630, &cAssocArray_cSystemPtr_int_dtor, &D_00543620);
    g_cSystemScriptTypeKey = cScriptBase_addClass("cSystem", &cSystem_SOBJ_init, 0, 1);
    D_00543650 = "GameSys Container";
    D_00543648 = g_cSystemScriptTypeKey;
}
