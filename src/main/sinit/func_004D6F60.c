#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_003D8F60(char *, char *, int);                     
extern char D_00493BA0;
extern char D_00493BE0;
extern int D_00571730;
extern int D_00571738;

void func_004D6F60(void) {
    D_00571730 = func_003D8F60("cMaterialProperties::eMatPropName", &D_00493BA0, 5);
    D_00571738 = func_003D8F60("cMaterialProperties::eDecalBlendMode", &D_00493BE0, 3);
}
