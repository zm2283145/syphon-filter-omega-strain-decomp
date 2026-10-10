#include "types.h"
typedef union { int i; unsigned char uc; } Arg0032E8C0;
typedef struct { char data[0x20]; } Rating0032E8C0;
extern char D_00532AD0[];
extern void* func_0032FD70(Rating0032E8C0* out, int a, int b, unsigned char c, int d, int e, unsigned char f);
extern void func_0032E930(void* list, void* rating);
/* Script: cAgentData::RegisterRating(a, b, c, d, e, f). */
int Script_cAgentData__RegisterRating_3(Arg0032E8C0* args)
{
    Rating0032E8C0 rating;
    unsigned char f;
    int e[1]; /* staged through the stack */
    int d[1];
    unsigned char c;
    int b[1];
    int a[1];
    f = args[5].uc;
    e[0] = args[4].i;
    d[0] = args[3].i;
    c = args[2].uc;
    b[0] = args[1].i;
    a[0] = args[0].i;
    func_0032E930(D_00532AD0, func_0032FD70(&rating, *(int*)a, *(int*)b, c, *(int*)d, *(int*)e, f));
    return 0;
}
