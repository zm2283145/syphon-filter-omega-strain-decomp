#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_003D88E0(int, char *, int, int);                
extern int D_00493890;
extern char D_004A67F8;
extern char D_004A6808;
extern char D_004A6818;
extern char D_004A6828;
extern char D_004A6840;
extern char D_004A6860;
extern char D_004A6880;
extern char D_004A6898;
extern char D_004A68B0;
extern char D_004A68C0;
extern char D_004A68E0;
extern char D_004A68F8;
extern char D_004A6908;
extern char D_004A6918;
extern int D_004F79E8;

void ScriptType_ToHitSettings_Init(int arg0) {
    func_003D88E0(D_004F79E8, &D_004A67F8, arg0, D_00493890);
    func_003D88E0(D_004F79E8, &D_004A6808, arg0 + 4, D_00493890);
    func_003D88E0(D_004F79E8, &D_004A6818, arg0 + 8, D_00493890);
    func_003D88E0(D_004F79E8, &D_004A6828, arg0 + 0xC, D_00493890);
    func_003D88E0(D_004F79E8, &D_004A6840, arg0 + 0x10, D_00493890);
    func_003D88E0(D_004F79E8, &D_004A6860, arg0 + 0x14, D_00493890);
    func_003D88E0(D_004F79E8, &D_004A6880, arg0 + 0x18, D_00493890);
    func_003D88E0(D_004F79E8, &D_004A6898, arg0 + 0x1C, D_00493890);
    func_003D88E0(D_004F79E8, &D_004A68B0, arg0 + 0x20, D_00493890);
    func_003D88E0(D_004F79E8, &D_004A68C0, arg0 + 0x24, D_00493890);
    func_003D88E0(D_004F79E8, &D_004A68E0, arg0 + 0x28, D_00493890);
    func_003D88E0(D_004F79E8, &D_004A68F8, arg0 + 0x2C, D_00493890);
    func_003D88E0(D_004F79E8, &D_004A6908, arg0 + 0x30, D_00493890);
    func_003D88E0(D_004F79E8, &D_004A6918, arg0 + 0x34, D_00493890);
}
