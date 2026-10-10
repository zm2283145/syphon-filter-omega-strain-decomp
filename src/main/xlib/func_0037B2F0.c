#include "types.h"

typedef struct { int a; int b; int kind; } Request3;
extern void func_0037FCA0(int* out, void* list, void** slot, Request3* req);

/* Builds a kind-2 request (a, b) and submits it to the list at +0x1108 with slot +0x110C. */
void func_0037B2F0(char* self, int a, int b)
{
    void* slot;
    int result;
    Request3 req;
    req.a = a;
    req.b = b;
    req.kind = 2;
    slot = self + 0x110C;
    func_0037FCA0(&result, self + 0x1108, &slot, &req);
}
