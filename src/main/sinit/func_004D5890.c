#include "types.h"
extern char D_005435B0[];
extern char D_005435C0[];
extern char D_005435D0[];
extern char D_005435E0[];
extern char D_005435F0[];
extern char D_00543600[];
extern int D_00543610;
extern int D_00543618;
extern char D_004BD168[];
extern void func_003CA2E0(void*);
extern void func_003CA2C0(void*, int*, int*);
extern void func_003CA4D0(void*, int);
extern void func_003CA460(void*, int);
extern int func_003C8C40(void);
extern void __register_global_object(void*, void*, void*);
extern int Script_RegisterType(void*, void*, int, int);
void func_004D5890(void)
{
    int a;
    int b;
    func_003CA2E0(D_005435C0);
    __register_global_object(D_005435C0, func_003CA4D0, D_005435B0);
    func_003CA2E0(D_005435E0);
    __register_global_object(D_005435E0, func_003CA4D0, D_005435D0);
    func_003CA2C0(D_00543600, &a, &b);
    __register_global_object(D_00543600, func_003CA460, D_005435F0);
    D_00543610 = Script_RegisterType(D_004BD168, func_003C8C40, 1, 0);
    D_00543618 = D_00543610;
}