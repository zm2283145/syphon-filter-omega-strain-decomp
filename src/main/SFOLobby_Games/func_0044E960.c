#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
extern int sprintf(char*, const char*, ...);
extern int memset(void*, int, int);
extern int func_00476998(void);
extern int func_004441D0(char*, char*, int, int);
extern void func_00451B00(char*, int, char*, int);
extern void Net_StartSession(int);
extern int func_00444460(char*, char*, char*, int, int, int, int, int, int, int, int, int, int);
extern void func_00452F30(char*, int, char*);
extern int func_00443020(char*);
extern int func_004452D0(void);
extern int func_004505E0(char*, char*);
extern void func_00444050(int);
extern void func_00444020(int);
extern char D_004C0F00[];
extern char D_004C0F18[];
extern char D_004C0F20[];
extern char D_004C0F30[];
extern int D_00494180;
extern int D_005721A8;
extern int D_00584520;
extern int D_00585E70;
extern int D_00585E74;
extern int D_00585E78;
extern int D_00585E7C;
extern int D_00585E80;
extern int D_00585E84;
extern char D_00585E90[];
extern int D_00585F78;
extern int D_00585F7C;
extern int D_00585F80;
extern int D_00585F84;
extern char D_00585F88;
extern char D_00585F89;

#pragma opt_common_subs off
int func_0044E960(char* self, int a1, int a2, int a3)
{
    char buf[0x48];
    char id[8];
    sprintf(id, D_004C0F18, (unsigned int)F_(self, 0x207C, int));
    if (func_004441D0(self + 0x1FFC, id, F_(self, 0x1EAC, int), func_00476998())) {
        func_00451B00(self, 0x31, D_004C0F00, 0xF2);
        return 0;
    }
    F_(self, 0x26A0, char) = 0;
    D_00494180 = a2;
    Net_StartSession(0);
    D_00584520 = D_005721A8;
    sprintf(buf, D_004C0F20, self + 0x243D, a2, a1, a3, F_(self, 0x2480, int));
    if (!func_00444460(buf, (char*)&D_00585E70, D_004C0F30, F_(self, 0x1EA8, int), a2, 1, a1, 0, 0, 0, 0, 0, 2)) {
        func_00451B00(self, 0x32, D_004C0F00, 0x152);
        return 0;
    }
    func_00452F30(self, 1, D_00585E90);
    D_00585F78 = F_(self, 0x2484, int);
    D_00585F84 = func_00443020(self + 0x2429);
    D_00585F7C = F_(self, 0x2480, int);
    D_00585F89 = a1;
    D_00585F80 = func_004452D0();
    D_00585F88 = a3;
    memset(&D_00585E70, 0, 0x18);
    D_00585E70 = F_(self, 0x2480, int);
    D_00585E78 = func_004452D0();
    D_00585E74 = a1;
    D_00585E7C = a3;
    D_00585E80 = 0;
    D_00585E84 = func_00443020(self + 0x2429);
    if (!func_004505E0(self, D_00585E90)) {
        func_00451B00(self, 1, D_004C0F00, 0x176);
        return 0;
    }
    func_00444050(1);
    func_00444020(1);
    F_(self, 0x255C, int) = 10;
    func_00451B00(self, 0, D_004C0F00, 0x17F);
    return 1;
}

