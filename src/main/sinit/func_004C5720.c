#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Script_RegisterType(char *, char *, int, int);            
int __register_global_object(char **, char *, char *);         
int func_003D84F0(int, char *, char *, char *, int, char *, char *);              
int func_003D8F60(char *, char *, int);                     
extern char D_00489F80;
extern char D_00493878;
extern char D_004EA760;
extern char *D_004EA770;
extern int D_004EA778;
extern int D_004EA780;
extern int D_004EA788;
extern int D_004EA790;
extern char ScriptType_cNode_Init;
extern char Script_cNode_IsType;
extern char func_00144930;

void func_004C5720(void) {
    D_004EA770 = "NODE";
    __register_global_object(&D_004EA770, &func_00144930, &D_004EA760);
    D_004EA778 = Script_RegisterType("cNode", &ScriptType_cNode_Init, 0, 1);
    D_004EA780 = D_004EA778;
    D_004EA788 = func_003D8F60("cNode::TYPES", &D_00489F80, 0xA);
    D_004EA790 = func_003D84F0(D_004EA778, &Script_cNode_IsType, &D_00493878, "IsType", 2, &D_004EA778, &D_004EA788);
}
