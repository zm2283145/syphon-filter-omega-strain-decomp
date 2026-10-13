#include "types.h"
extern void func_003F8390(void* self);
extern void MoviePlayer_FreeBuffers(void* self);
extern void func_0036E220(void* p, int del);
extern void operator_delete(void* p);
void* func_003F9300(void* self, short del)
{
    if (self) {
        void* m;
        func_003F8390(self);
        MoviePlayer_FreeBuffers(self);
        func_0036E220((char*)self + 0x190, -1);
        m = (char*)self + 0x58;
        if (m)
            func_0036E220((char*)self + 0x6C, -1);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
