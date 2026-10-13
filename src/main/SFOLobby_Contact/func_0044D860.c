#include "types.h"
typedef struct {
    char p0[0xE0]; char fE0[0x24C - 0xE0]; int f24C; char p250[0xC28 - 0x250];
    char fC28[0x1C]; int fC44; char pC48[0xCF4 - 0xC48]; signed char fCF4;
    char pCF5[0x2408 - 0xCF5]; signed char busy; char p2409[7]; int f2410;
    char p2414[0x257C - 0x2414]; int f257C;
} S44D860;
extern void String_Copy(char*, char*);
extern int func_00443E70(void);
extern void func_00451B00(S44D860*, int, char*, int);
extern void func_00452F70(S44D860*, int, int);
extern int func_004534A0(S44D860*, int, int, int);
extern int func_0046C170(void*, void*);
extern void func_0044F7E0(void*);
extern void func_0044F160(void*, int);
extern void* memset(void*, int, int);
extern int D_00497890;
extern char D_004C0EC0[];
extern char D_004C0ED0[];
extern char func_00446830[];
int func_0044D860(S44D860* s, int wait)
{
    char req[0x15];

    memset(s->fC28, 0, 0xD0);
    s->fC44 = -1;
    memset(req, 0, sizeof(req));
    String_Copy(req, D_004C0EC0);
    s->f24C = func_0046C170(req, func_00446830);
    if (s->f24C != 0) {
        return 0;
    }
    func_0044F7E0(s->fE0);
    func_0044F160(s->fE0, 1);
    if (wait) {
        while (s->fCF4 != 1) {
            func_00452F70(s, 0, 0);
            if (s->f24C != 0) {
                func_00451B00(s, 1, D_004C0ED0, 0x1A7);
                s->busy = 0;
                return 0;
            }
            if (func_004534A0(s, s->f2410, D_00497890, 0) == 0) {
                func_00451B00(s, 2, D_004C0ED0, 0x1AF);
                s->busy = 0;
                return 0;
            }
        }
    }
    s->f257C = func_00443E70();
    return 1;
}
