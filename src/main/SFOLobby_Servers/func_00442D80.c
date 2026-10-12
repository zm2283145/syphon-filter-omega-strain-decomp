#pragma opt_loop_invariants off
#pragma opt_common_subs off
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))

extern int D_00497890;
extern char D_004C05C8[];
extern char D_004C05D0[];
void* memset(void*, int, unsigned int);
void String_Copy(char*, char*);
int func_00443E70(void);
void func_0044F7E0(int);
void func_00451B00(char*, int, char*, int);
void func_00452F70(char*, int, int);
int func_004534A0(char*, int, int, int);
int func_0046B1E0(char*, void*);
void func_00446EA0();

int func_00442D80(char* self) {
    char buf[0x26];

    func_0044F7E0(F_(self, 0x23E0, int));
    memset(buf, 0, sizeof(buf));
    memset(self + 0x39C, 0, 0x64);
    String_Copy(buf, D_004C05C8);
    String_Copy(buf + 0x15, self + 0x2418);
    F_(self, 0x2410, int) = func_00443E70();
    F_(self, 0x24C, int) = func_0046B1E0(buf, func_00446EA0);
    while (F_(self, 0x3FC, signed char) != 1) {
        func_00452F70(self, 0, 0);
        if (func_004534A0(self, F_(self, 0x2410, int), D_00497890, 0) == 0) {
            func_00451B00(self, 2, D_004C05D0, 0x7C);
            return 0;
        }
    }
    return F_(self, 0x3F8, int) >= 0;
}

