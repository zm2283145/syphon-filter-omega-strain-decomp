#include "types.h"

/* compiler: ee-gcc 2.95 -O2 (check.py --gcc) */

typedef struct { int code; int a; int b; char pad[0x14]; } Request;
extern void func_0010D590(int kind, Request* req);

/* Sends request kind 0x20 with (byte code, a, b). */
void func_0010E378(unsigned char code, int a, int b)
{
    Request req;
    req.a = a;
    req.code = code;
    req.b = b;
    func_0010D590(0x20, &req);
}
