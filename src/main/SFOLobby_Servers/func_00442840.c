#pragma opt_loop_invariants off
#pragma opt_common_subs off
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))

typedef struct {
    char name[0x15];
    char host[0x13];
    int id;
} Login442840;

extern int D_00497890;
extern char D_004C05C8[];
extern char D_004C05D0[];
void* memset(void*, int, unsigned int);
void String_Copy(char*, char*);
int func_00443E70(void);
int* func_0044F290(int, int);
void func_00451B00(char*, int, char*, int);
void func_00452F70(char*, int, int);
int func_004534A0(char*, int, int, int);
int func_0046B280(void*, void*);
void func_00446E50();

int func_00442840(char* self, int index) {
    Login442840 l;
    int* e;

    memset(&l, 0, sizeof(l));
    String_Copy(l.name, D_004C05C8);
    String_Copy(l.host, self + 0x2418);
    e = func_0044F290(F_(self, 0x23E0, int), index);
    l.id = *e;
    F_(self, 0x1F38, int) = 0;
    F_(self, 0x26A8, int) = 0;
    F_(self, 0x2410, int) = func_00443E70();
    F_(self, 0x1B0, int) = 0;
    F_(self, 0x24C, int) = func_0046B280(&l, func_00446E50);
    while (F_(self, 0x1B0, int) == 0) {
        func_00452F70(self, 0, 0);
        if (func_004534A0(self, F_(self, 0x2410, int), D_00497890, 0) == 0) {
            func_00451B00(self, 2, D_004C05D0, 0x153);
            return 0;
        }
    }
    F_(self, 0x1F38, int) = *e;
    func_00451B00(self, 0, D_004C05D0, 0x162);
    return 1;
}
