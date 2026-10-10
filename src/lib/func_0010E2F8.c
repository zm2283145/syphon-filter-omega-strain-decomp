#include "types.h"

/* Library code: matches with EE-GCC 2.95 -O2 (check.py --gcc). */

typedef struct { int value; int pad; } Request;
extern void func_0010D590(int kind, Request* req);

/* Sends request kind 2 carrying one value. */
void func_0010E2F8(int value)
{
    Request req;
    req.value = value;
    func_0010D590(2, &req);
}
