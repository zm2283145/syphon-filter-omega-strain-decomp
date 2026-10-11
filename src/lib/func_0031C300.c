#include "types.h"
typedef struct {
    long magic;
    char pad08[0x10];
    unsigned char state;
    char pad19[3];
    void* inner;
} Handle_0031C300;
extern void func_003183D0(void* p);
int func_0031C300(Handle_0031C300* h)
{
    if (h == 0 || h->magic != 0xFACE) return 0x17D4;
    if (h->state != 10) return 0x17DE;
    func_003183D0(h->inner);
    return 0;
}