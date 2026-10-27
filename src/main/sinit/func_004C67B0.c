#include "types.h"
int Script_cEnvSettings_SkyOn();
int Script_cEnvSettings_SkyOff();
int cEnvSettings_SOBJ_init();
int cScriptBase_registerFunc_int_intPintPint_intP_charP_etc();
int cScriptBase_addClass();
extern char D_00493880;
extern int D_004EE860;
extern int D_004EE868;
extern int D_004EE870;
extern int D_004EE878;
void StaticInit_Env(void) {
    D_004EE860 = cScriptBase_addClass("cEnvSettings", cEnvSettings_SOBJ_init, 0, 1);
    D_004EE868 = D_004EE860;
    D_004EE870 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(D_004EE860, Script_cEnvSettings_SkyOff, &D_00493880, "SkyOff", 1, &D_004EE860);
    D_004EE878 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(D_004EE860, Script_cEnvSettings_SkyOn, &D_00493880, "SkyOn", 1, &D_004EE860);
}
