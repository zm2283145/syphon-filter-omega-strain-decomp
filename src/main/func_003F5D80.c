#include "types.h"
typedef struct { char pad[0x48]; char sub[0x60]; int mA8; } T5D80;
extern void func_0010AFF8(T5D80* t, int a, int b);
extern void func_0010B450(T5D80* t, int id, void* cb, int z);
extern void func_003F5650(void* sub, int a, int b, int c, int d, int e);
extern void func_003F57B0(void);
extern void func_003F5780(void);
extern void func_003F5750(void);
extern void func_003F5720(void);
extern void func_003F56D0(void);
int func_003F5D80(T5D80* t, int a, int b, int c, int d, int e, int f, int g)
{
    func_0010AFF8(t, a, b);
    func_0010B450(t, 0, (void*)func_003F57B0, 0);
    func_0010B450(t, 1, (void*)func_003F5780, 0);
    func_0010B450(t, 2, (void*)func_003F5750, 0);
    func_0010B450(t, 3, (void*)func_003F5720, 0);
    func_0010B450(t, 5, (void*)func_003F56D0, 0);
    t->mA8 = 0;
    func_003F5650(t->sub, c, d, e, f, g);
    return 1;
}
