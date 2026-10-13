#include "types.h"

void func_0010D3E0(int);
int ezNetCtlSetProperties(int);
int ezNetCtlGetStatus(void*);
void func_00451B00(char*, int, char*, int);
void func_00452F70(char*, int, int);
int func_00443E70(void);
int func_00353130(void);
int func_003A6650(int);
extern char D_004C0D70[];
extern int D_00585D00;
extern char D_00585D40[];
extern int D_00585D4C;

int func_0044BDE0(char* self, int props)
{
    int r;
    int now;

    func_0010D3E0(0);
    r = ezNetCtlSetProperties(props);
    func_0010D3E0(0);
    if (r < 0) {
        func_00451B00(self, 7, D_004C0D70, 0x14A);
        return 0;
    }
    now = func_00443E70();
    if (now < D_00585D00)
        D_00585D00 = now;
    while (now < D_00585D00 + 0x9C4) {
        func_00452F70(self, 0, 0);
        now = func_00443E70();
    }
    D_00585D00 = 0;
    *(int*)(self + 0x2410) = now;
    if (func_00353130() < 0) {
        func_00451B00(self, 0x20, D_004C0D70, 0x163);
        return 0;
    }
    for (;;) {
        func_00452F70(self, 1, 0);
        if (!!func_003A6650(0)) {
            func_00451B00(self, 0x3E, D_004C0D70, 0x16D);
            return 0;
        }
        if (ezNetCtlGetStatus(D_00585D40) >= 0) {
            switch (D_00585D4C) {
            case 1:
                break;
            case 3:
                return 1;
            case 2:
                break;
            case 5:
                func_00451B00(self, 0x21, D_004C0D70, 0x187);
                return 0;
            }
            if (now - *(int*)(self + 0x2410) > 60000) {
                func_00451B00(self, 2, D_004C0D70, 0x190);
                return 0;
            }
            now = func_00443E70();
        } else
            return 1;
    }
}
