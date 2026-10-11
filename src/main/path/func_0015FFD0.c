#include "types.h"
typedef struct { char pad[0x20]; int* ids; int pad24; int n; } T_FFD0;
typedef struct {
    char pad[0x48];
    int idx;
    int other;
    int cur;
    char pad54[0xC];
    unsigned char b0 : 3;
    unsigned char flag : 1;
    unsigned char b4 : 4;
    char pad61[0x13];
    T_FFD0* t;
} S_FFD0;
int func_00160A00(S_FFD0* self, int i);
void func_00160C40(S_FFD0* self, int id);
void func_0015FFD0(S_FFD0* self, int id)
{
    if (!self->flag && id != self->cur && id != self->other) {
        T_FFD0* t = self->t;
        int n = t->n;
        int i;
        for (i = 0; i < n; i++) {
            if (id == t->ids[i]) {
                self->idx = i;
                self->cur = id;
                self->flag = !func_00160A00(self, i);
                break;
            }
        }
    }
    func_00160C40(self, id);
}