#include "types.h"

/* Library code: matches with EE-GCC 2.95 -O2 (check.py --gcc), not Metrowerks. */

typedef struct { int value; int code; } Request;
extern void func_0010D590(int kind, Request* req);

/* Sends request kind 3 with (value, sign-extended byte code). */
void func_0010E320(int value, char code)
{
    Request req;
    req.value = value;
    req.code = code;
    func_0010D590(3, &req);
}
