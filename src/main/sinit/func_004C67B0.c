#include "types.h"
int Script_cEnvSettings_SkyOn();
int Script_cEnvSettings_SkyOff();
int ScriptType_cEnvSettings_Init();
int Script_RegisterNative();
int Script_RegisterType();
extern char D_00493880;
extern int D_004EE860;
extern int D_004EE868;
extern int D_004EE870;
extern int D_004EE878;
void StaticInit_RegisterEnvSettings(void) {
    D_004EE860 = Script_RegisterType("cEnvSettings", ScriptType_cEnvSettings_Init, 0, 1);
    D_004EE868 = D_004EE860;
    D_004EE870 = Script_RegisterNative(D_004EE860, Script_cEnvSettings_SkyOff, &D_00493880, "SkyOff", 1, &D_004EE860);
    D_004EE878 = Script_RegisterNative(D_004EE860, Script_cEnvSettings_SkyOn, &D_00493880, "SkyOn", 1, &D_004EE860);
}
