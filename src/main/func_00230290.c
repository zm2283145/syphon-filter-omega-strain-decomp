#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int cScriptBase_registerField(int, char *, int, int);                
extern int D_00493890;
extern int D_004F79E8;

void ToHitSettings_SOBJ_init(int arg0) {
    cScriptBase_registerField(D_004F79E8, "runAccFactor", arg0, D_00493890);
    cScriptBase_registerField(D_004F79E8, "runAimFactor", arg0 + 4, D_00493890);
    cScriptBase_registerField(D_004F79E8, "kneelAccFactor", arg0 + 8, D_00493890);
    cScriptBase_registerField(D_004F79E8, "kneelAimFactor", arg0 + 0xC, D_00493890);
    cScriptBase_registerField(D_004F79E8, "movingTargAccFactor", arg0 + 0x10, D_00493890);
    cScriptBase_registerField(D_004F79E8, "crouchTargAccFactor", arg0 + 0x14, D_00493890);
    cScriptBase_registerField(D_004F79E8, "rollTargAccFactor", arg0 + 0x18, D_00493890);
    cScriptBase_registerField(D_004F79E8, "maxVelocity", arg0 + 0x1C, D_00493890);
    cScriptBase_registerField(D_004F79E8, "npcExtraAimTime", arg0 + 0x20, D_00493890);
    cScriptBase_registerField(D_004F79E8, "npcMovingTargVal", arg0 + 0x24, D_00493890);
    cScriptBase_registerField(D_004F79E8, "npcRollingTargVal", arg0 + 0x28, D_00493890);
    cScriptBase_registerField(D_004F79E8, "reloadAimLoss", arg0 + 0x2C, D_00493890);
    cScriptBase_registerField(D_004F79E8, "npcNearDist", arg0 + 0x30, D_00493890);
    cScriptBase_registerField(D_004F79E8, "npcNearMul", arg0 + 0x34, D_00493890);
}
