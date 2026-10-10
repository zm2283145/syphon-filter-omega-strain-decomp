#include "types.h"
typedef struct { char data[0x20]; } Rating0032E850;
extern char D_00532A70[];
extern void* func_0032FFD0(Rating0032E850* out, int a, int b, int c, int d, int e);
extern void func_00147600(void* list, void* rating);
/* Script: cAgentData::RegisterSpecialRating(a, b, c, d). */
int Script_cAgentData__RegisterSpecialRating(int* args)
{
    Rating0032E850 rating;
    int d[1]; /* staged through the stack */
    int c[1];
    int b[1];
    int a[1];
    d[0] = args[3];
    c[0] = args[2];
    b[0] = args[1];
    a[0] = args[0];
    func_00147600(D_00532A70, func_0032FFD0(&rating, *(int*)a, *(int*)b, *(int*)c, *(int*)d, 0));
    return 0;
}
