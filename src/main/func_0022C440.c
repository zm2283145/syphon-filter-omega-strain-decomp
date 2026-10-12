#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_003D88E0(int, char *, int, int);                
extern int D_00493888;
extern int D_00493890;
extern int D_004F78F0;

void ScriptType_TargSettings_Init(int arg0) {
    func_003D88E0(D_004F78F0, "maxDist", arg0, D_00493890);
    func_003D88E0(D_004F78F0, "distFactor", arg0 + 4, D_00493890);
    func_003D88E0(D_004F78F0, "freshFactor", arg0 + 8, D_00493890);
    func_003D88E0(D_004F78F0, "angFactor", arg0 + 0xC, D_00493890);
    func_003D88E0(D_004F78F0, "pitchFactor", arg0 + 0x10, D_00493890);
    func_003D88E0(D_004F78F0, "zoneFactor", arg0 + 0x14, D_00493890);
    func_003D88E0(D_004F78F0, "zone1MaxDist", arg0 + 0x18, D_00493890);
    func_003D88E0(D_004F78F0, "zone1MinAng", arg0 + 0x1C, D_00493890);
    func_003D88E0(D_004F78F0, "zone2MinAng", arg0 + 0x20, D_00493890);
    func_003D88E0(D_004F78F0, "zone3MinAng", arg0 + 0x24, D_00493890);
    func_003D88E0(D_004F78F0, "extraLosFrames", arg0 + 0x28, D_00493888);
    func_003D88E0(D_004F78F0, "autoMinAng", arg0 + 0x2C, D_00493890);
    func_003D88E0(D_004F78F0, "autoMaxDist", arg0 + 0x30, D_00493890);
    func_003D88E0(D_004F78F0, "autoPrevClamp", arg0 + 0x34, D_00493890);
    func_003D88E0(D_004F78F0, "debugDisplay", arg0 + 0x38, D_00493888);
}
