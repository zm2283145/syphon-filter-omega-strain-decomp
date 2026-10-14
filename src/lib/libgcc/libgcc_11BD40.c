#include "types.h"
typedef struct { int a; int b; int c; int d; } ReqBD40;
extern void func_0011BC28(ReqBD40* req);
void func_0011BD40(int a, int b, int c, int d)
{
    ReqBD40 req;
    req.a = a;
    req.b = b;
    req.c = c;
    req.d = d;
    func_0011BC28(&req);
}