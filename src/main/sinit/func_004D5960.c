#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Script_RegisterType(char *, char *, int, int);            
int __register_global_object(char *, char *, char *);          
int func_003CB5A0(char *, char *, char *);                     
extern char D_00543620;
extern char D_00543630;
extern int g_cSystemScriptTypeKey;
extern int D_00543648;
extern char *D_00543650;
extern char cSystem_ScriptFactory;
extern char func_003CB5C0;

void StaticInit_RegisterSystem(void) {
    int sp1C;
    int sp18;

    func_003CB5A0(&D_00543630, &sp1C, &sp18);
    __register_global_object(&D_00543630, &func_003CB5C0, &D_00543620);
    g_cSystemScriptTypeKey = Script_RegisterType("cSystem", &cSystem_ScriptFactory, 0, 1);
    D_00543650 = "GameSys Container";
    D_00543648 = g_cSystemScriptTypeKey;
}
