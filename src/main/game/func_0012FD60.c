#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void Mem_Free(int, void*, char*, int);
float World_GetElapsedTime(void);
int func_003F8220(void*, float);
void func_003F9300(void*, int);
void func_0036B250(int);
void* Service_Lookup(void*, void*);
void func_001C9540(void*, int, int);
void func_00130520(void*, void*, int);
extern char D_0049A890;
extern char D_004F2CC0[];
extern int D_004EA048;
}
class Q_12FD60 {
public:
    char e[0x10][0x80];
    int cur;
    int count;
    bool AtEnd() { return cur == count; }
    char* Next() {
        char* r = 0;
        int i;
        cur++;
        i = cur;
        if (i <= count) r = e[i - 1];
        return r;
    }
};
typedef struct {
    char pad[0xAC];
    Q_12FD60* q;
    void* b0;
} S_12FD60;

#pragma opt_common_subs off
extern "C" void func_0012FD60(S_12FD60* self)
{
    if (self->b0) {
        bool done = !func_003F8220(self->b0, World_GetElapsedTime());
        if (done) {
            void* p = self->b0;
            {
                AllocGuard g;
                func_003F9300(p, -1);
                Mem_Free(0, p, &D_0049A890, 0xAE2);
            }
            self->b0 = 0;
            func_0036B250(1);
            func_001C9540(Service_Lookup(self, D_004F2CC0), 2, D_004EA048);
        }
    }
    if (!self->b0) {
        Q_12FD60* q = self->q;
        if (q) {
            if (!q->AtEnd()) {
                func_00130520(self, q->Next(), 1);
            } else {
                {
                    AllocGuard g;
                    Mem_Free(0, q, &D_0049A890, 0xAF7);
                }
                self->q = 0;
            }
        }
    }
}
