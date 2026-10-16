#include "types.h"
extern void func_003F8390(void* self);
extern void MoviePlayer_FreeBuffers(void* self);
extern void FileMan_Release(void* p, int del);
extern void operator_delete(void* p);
void* func_003F9300(void* self, short del)
{
    if (self) {
        void* m;
        func_003F8390(self);
        MoviePlayer_FreeBuffers(self);
        FileMan_Release((char*)self + 0x190, -1);
        m = (char*)self + 0x58;
        if (m)
            FileMan_Release((char*)self + 0x6C, -1);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
