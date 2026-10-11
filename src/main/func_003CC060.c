#include "types.h"
typedef struct { unsigned char m0; int m4; int m8; int mC; } TC060;
extern int func_0036DEF0(void* src);
extern int func_0036DE50(void* src);
extern void func_0036D990(void* src, int* out, int z);
extern void func_0036DEC0(void* src);
unsigned char func_003CC060(TC060* self, void* src)
{
    if (!(unsigned char)func_0036DEF0(src)) {
        self->mC = func_0036DE50(src);
        self->m8 = 0;
        func_0036D990(src, &self->m8, 0);
        func_0036DEC0(src);
        self->m4 = self->m8;
        self->m0 = 1;
        return 1;
    }
    return 0;
}
