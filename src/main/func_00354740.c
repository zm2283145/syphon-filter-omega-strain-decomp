#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct E354740 { char c[0x14]; };
struct O354740 { int x0; int count; E354740* data; };
extern "C" {
extern char D_004AA5B8[];
void func_00354880(O354740* v);
void Mem_Free(int pool, void* p, char* file, int line);
void operator_delete(void* p);
}
extern "C" O354740* func_00354740(O354740* self, short del)
{
    if (self) {
        if (self) {
            if (self) {
                E354740* b = self->data;
                E354740* e = b + self->count;
                E354740* p;
                while (b < e) {
                    e--;
                    func_00354880(self);
                }
                self->count = 0;
                p = self->data;
                if (p) {
                    if (p) {
                        AllocGuard g;
                        Mem_Free(0, p, D_004AA5B8, 0x64);
                    }
                }
            }
        }
        if (del > 0)
            operator_delete(self);
    }
    return self;
}