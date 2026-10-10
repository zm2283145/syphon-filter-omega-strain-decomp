#include "types.h"
typedef struct { int obj; unsigned char flag; char pad[3]; } E236F;
typedef struct { char pad[0xD0]; E236F e[15]; } G236F;
extern G236F D_004F7A50;
extern int D_00539248;
extern void func_003813A0(int a, int b, int c);
void func_00236F80(void)
{
    int i;
    for (i = 0; i < 15; i++) {
        if (D_004F7A50.e[i].flag) {
            func_003813A0(D_00539248, D_004F7A50.e[i].obj, 1);
            D_004F7A50.e[i].flag = 0;
        }
    }
}