#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int cScriptBase_addClass(char *, char *, int, int);            
int __register_global_object(char **, char *, char *);         
int cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(int, char *, char *, char *, int, char *, char *);              
int cScriptBase_registerEnum(char *, char *, int);                     
extern char D_00489F80;
extern char D_00493878;
extern char D_004EA760;
extern char *D_004EA770;
extern int D_004EA778;
extern int D_004EA780;
extern int D_004EA788;
extern int D_004EA790;
extern char cNode_SOBJ_init;
extern char Script_cNode_IsType;
extern char cSubclassId_dtor;

void StaticInit_Node(void) {
    D_004EA770 = "NODE";
    __register_global_object(&D_004EA770, &cSubclassId_dtor, &D_004EA760);
    D_004EA778 = cScriptBase_addClass("cNode", &cNode_SOBJ_init, 0, 1);
    D_004EA780 = D_004EA778;
    D_004EA788 = cScriptBase_registerEnum("cNode::TYPES", &D_00489F80, 0xA);
    D_004EA790 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(D_004EA778, &Script_cNode_IsType, &D_00493878, "IsType", 2, &D_004EA778, &D_004EA788);
}
