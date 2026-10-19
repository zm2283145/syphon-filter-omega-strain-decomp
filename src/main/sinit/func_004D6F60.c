#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int ScriptEnum_Register(char *, char *, int);                     
extern char D_00493BA0;
extern char D_00493BE0;
extern int D_00571730;
extern int D_00571738;

void StaticInit_RegisterMaterialPropertyEnums(void) {
    D_00571730 = ScriptEnum_Register("cMaterialProperties::eMatPropName", &D_00493BA0, 5);
    D_00571738 = ScriptEnum_Register("cMaterialProperties::eDecalBlendMode", &D_00493BE0, 3);
}
