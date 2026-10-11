#include "types.h"
extern char D_004A4090[];
extern char D_004A40A0[];
extern char D_004A40B0[];
extern char D_004A40C0[];
extern char D_004F53B8[];
extern char D_004F53C8[];
extern char D_004F53D8[];
extern char D_004F53E8[];
void func_004CCA30(void)
{
    *(int*)D_004F53B8 = (int)D_004A4090;
    *(int*)D_004F53C8 = (int)D_004A40A0;
    *(int*)D_004F53D8 = (int)D_004A40B0;
    *(int*)D_004F53E8 = (int)D_004A40C0;
}
