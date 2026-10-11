#include "types.h"
typedef union ScriptArg {
    int i;
    float f;
    void* p;
    unsigned char uc;
    signed char c;
} ScriptArg;
extern int Global_AddMaterialProperties(int, unsigned char, int, signed char, int, int, unsigned char, float);
unsigned char Script_AddMaterialProperties_3(ScriptArg* args) {
    int id[1];
    int a[1];
    int b[1];
    int c[1];
    int scale[1];
    unsigned char x;
    signed char kind;
    unsigned char flag;
    x = args[7].uc;
    scale[0] = args[6].i;
    c[0] = args[5].i;
    b[0] = args[4].i;
    kind = args[3].c;
    a[0] = args[2].i;
    flag = args[1].uc;
    id[0] = args[0].i;
    return Global_AddMaterialProperties(*(int*)id, flag, *(int*)a, kind, *(int*)b, *(int*)c, x, *(float*)scale);
}