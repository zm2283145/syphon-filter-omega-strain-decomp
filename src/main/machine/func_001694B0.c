#include "types.h"
typedef struct { char pad[0x278]; unsigned char b278; } O169;
extern unsigned char D_0048A010;
extern char D_00555070[];
extern char D_0048B2F8[];
extern char D_004FFC90[];
extern char D_004FFB8C[];
extern char D_0055DDA0[];
extern void func_003A64F0(void);
extern void func_00165DC0(O169*);
extern int ScriptMgr_ExportSymbols(char*, char*, char*);
extern int sprintf(char*, const char*, ...);
extern int Archive_Open(char*, char*, int, int);
extern void func_003E2140(char*, int);
extern void ScriptMgr_InitClient(char*);
extern void func_003302A0(int);
extern void func_003F9530(char*, char*);
extern void ManUtils_LoadSKL(char*);
extern void func_0036B3B0(int, int, int);
extern void func_0042C1E0(void);
#pragma opt_propagation off
void func_001694B0(O169* o) {
    char buf[0x40];
    if (!D_0048A010) return;
    D_0048A010 = 0;
    func_003A64F0();
    func_00165DC0(o);
    if (ScriptMgr_ExportSymbols(D_00555070, D_0048B2F8, D_004FFC90)) {
        char* arc;
        int h;
        sprintf(buf, "%s\\COMMON\\SCRIPTS.HOG", D_0048B2F8);
        arc = D_004FFB8C;
        h = Archive_Open(arc, buf, 0, 0);
        func_003E2140(D_00555070, h);
        ScriptMgr_InitClient(D_00555070);
        func_003302A0(h);
        func_003F9530(arc, buf);
    }
    ManUtils_LoadSKL(D_0055DDA0);
    func_0036B3B0(2, 0xC1C00, 16);
    func_0042C1E0();
    o->b278 = 1;
}
