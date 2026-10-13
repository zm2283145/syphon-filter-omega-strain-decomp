#include "types.h"

typedef struct { float re; float im; } Cx319910;

extern float func_00319D08(int idx, Cx319910* tab, int n, Cx319910* out);
extern void func_00319B68(Cx319910* a, Cx319910* tab, int idx, Cx319910* out);
extern int func_00319BE0(int* a, int n, int v);

void func_00319910(int* in, Cx319910* pos, int nA, Cx319910* tabA, Cx319910* tabB,
                   int nC, Cx319910* ptsA, Cx319910* ptsB, int nList, int* list)
{
    Cx319910 rot;
    Cx319910 diff;
    Cx319910* pts;

    func_00319D08(in[0], tabA, nA, pos);
    pts = func_00319BE0(list, nList, in[0]) == 1 ? ptsB : ptsA;
    func_00319D08(in[1], pts, nC, &rot);
    func_00319B68(&rot, tabB, in[0], &diff);
    pos->re += diff.re;
    pos->im += diff.im;
}
