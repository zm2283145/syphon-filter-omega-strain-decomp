#pragma cplusplus on
#include "types.h"

union Key {
    __int128 q;
    unsigned long long d[2];
};

struct Entry {
    Key key;
    unsigned int num;
    float times[0x23];
    char extra[0xE0 - 0xA0];
};

struct Def {
    char pad[0x170];
    Key key;
    int count;
    char pad184[0xC];
    Entry entries[1];
};

struct Self {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Def* GetDef();
    char pad[0x60];
    float f64;
    char pad68[0x10];
    unsigned char idx[8];
    int mask;
};

extern char D_0053B540[];
extern "C" {
int func_003A3430(void*, void*);
Self* func_003A26A0(float, int, Self*, int, void*);
}

/* Fires each pending timed entry whose next time has been reached, marking linked peers. */
extern "C" void func_003A1450(Self* self, float t, int arg)
{
    int k = 0;
    int i;
    for (i = 0; i < self->GetDef()->count; k++, i++) {
        int bit = 1 << k;
        if (!(self->mask & bit) && self->GetDef()->entries[i].num != 0) {
            float tm = self->GetDef()->entries[i].times[self->idx[i]];
            if (tm >= 0.0f) {
                while (t >= tm) {
                    int r = func_003A3430(D_0053B540, &self->GetDef()->entries[i]);
                    Self* o = func_003A26A0(tm + self->f64, arg, self, r, self->GetDef()->entries[i].extra);
                    if (o && self->GetDef() == o->GetDef()) {
                        int j;
                        for (j = 0; j < self->GetDef()->count; j++) {
                            if ((unsigned long long)self->GetDef()->key.q == (unsigned long long)self->GetDef()->entries[j].key.q &&
                                self->GetDef()->key.d[1] == self->GetDef()->entries[j].key.d[1])
                                o->mask |= 1 << j;
                        }
                    }
                    self->idx[i]++;
                    if (self->idx[i] >= self->GetDef()->entries[i].num) {
                        self->mask |= bit;
                        break;
                    }
                }
            }
        }
    }
}
