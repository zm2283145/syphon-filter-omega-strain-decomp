#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_003D88E0(int, char *, int, int);                
extern int D_00493888;
extern int D_00493890;
extern char D_004A64E0;
extern char D_004A64E8;
extern char D_004A64F8;
extern char D_004A6508;
extern char D_004A6518;
extern char D_004A6528;
extern char D_004A6538;
extern char D_004A6548;
extern char D_004A6558;
extern char D_004A6568;
extern char D_004A6578;
extern char D_004A6588;
extern char D_004A6598;
extern char D_004A65A8;
extern char D_004A65B8;
extern int D_004F78F0;

void ScriptType_TargSettings_Init(int arg0) {
    func_003D88E0(D_004F78F0, &D_004A64E0, arg0, D_00493890);
    func_003D88E0(D_004F78F0, &D_004A64E8, arg0 + 4, D_00493890);
    func_003D88E0(D_004F78F0, &D_004A64F8, arg0 + 8, D_00493890);
    func_003D88E0(D_004F78F0, &D_004A6508, arg0 + 0xC, D_00493890);
    func_003D88E0(D_004F78F0, &D_004A6518, arg0 + 0x10, D_00493890);
    func_003D88E0(D_004F78F0, &D_004A6528, arg0 + 0x14, D_00493890);
    func_003D88E0(D_004F78F0, &D_004A6538, arg0 + 0x18, D_00493890);
    func_003D88E0(D_004F78F0, &D_004A6548, arg0 + 0x1C, D_00493890);
    func_003D88E0(D_004F78F0, &D_004A6558, arg0 + 0x20, D_00493890);
    func_003D88E0(D_004F78F0, &D_004A6568, arg0 + 0x24, D_00493890);
    func_003D88E0(D_004F78F0, &D_004A6578, arg0 + 0x28, D_00493888);
    func_003D88E0(D_004F78F0, &D_004A6588, arg0 + 0x2C, D_00493890);
    func_003D88E0(D_004F78F0, &D_004A6598, arg0 + 0x30, D_00493890);
    func_003D88E0(D_004F78F0, &D_004A65A8, arg0 + 0x34, D_00493890);
    func_003D88E0(D_004F78F0, &D_004A65B8, arg0 + 0x38, D_00493888);
}
