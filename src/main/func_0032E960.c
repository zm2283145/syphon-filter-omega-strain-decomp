#include "types.h"
typedef union ScriptArg { int i; float f; void* p; unsigned char b; } ScriptArg;
typedef struct { char data[0x1C]; } RatingReq;
extern char D_00532AD0[];
extern void* func_0032FE00(RatingReq* r, int a, int b, int c, int d, int e, int f);
extern void func_0032E930(void* registry, void* item);int Script_cAgentData__RegisterRating_2(ScriptArg* args)
{
    RatingReq r;
    int b2;
    int p0[1];
    int p1[1];
    int p3[1];
    int p4[1];
    int p5[1];
    p5[0] = args[5].i;
    p4[0] = args[4].i;
    p3[0] = args[3].i;
    b2 = args[2].b;
    p1[0] = args[1].i;
    p0[0] = args[0].i;
    func_0032E930(D_00532AD0, func_0032FE00(&r, *(int*)p0, *(int*)p1, b2, *(int*)p3, *(int*)p4, *(int*)p5));
    return 0;
}