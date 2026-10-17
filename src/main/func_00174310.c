#include "types.h"
typedef struct { int pad; int size; int* data; } Vec_74310;
typedef struct { Vec_74310 v; unsigned char live; } TmpVec_74310;
typedef struct { char pad[0xC]; char* cur; } Strm_74310;
typedef struct { char pad[0x204]; Vec_74310 keys; char pad210[0x20]; float a[3]; char pad23C[4]; float b[3]; } Ter_74310;
extern int D_0048A138;
extern Vec_74310* func_00173D20(Vec_74310* v, int n, int value);
extern int* func_001744F0(Vec_74310* v, int i);
extern void func_0013A040(void* v, int flag);
extern void KeyVector_Reserve(Vec_74310* v, int n);
extern void KeyVector_PushBack(Vec_74310* v, int* pos, int n, int* key);
void Terrain_ReadActRecord(Ter_74310* self, Strm_74310* s)
{
    int n;
    int i;
    self->a[0] = *(float*)s->cur; s->cur += 4;
    self->a[1] = *(float*)s->cur; s->cur += 4;
    self->a[2] = *(float*)s->cur; s->cur += 4;
    self->b[0] = *(float*)s->cur; s->cur += 4;
    self->b[1] = *(float*)s->cur; s->cur += 4;
    self->b[2] = *(float*)s->cur; s->cur += 4;
    n = *(int*)s->cur; s->cur += 4;
    if (n > 0) {
        TmpVec_74310 t;
        int k;
        func_00173D20(&t.v, n, D_0048A138);
        t.live = 1;
        for (i = 0; i < n; i++) {
            int* p = func_001744F0(&t.v, i);
            *p = *(int*)s->cur; s->cur += 4;
        }
        KeyVector_Reserve(&self->keys, (int)((unsigned int)self->keys.size + n / 2));
        for (i = 0; i < n; i += 2) {
            int lo = *func_001744F0(&t.v, i + 1);
            k = lo | (*func_001744F0(&t.v, i) << 16);
            KeyVector_PushBack(&self->keys, self->keys.data + self->keys.size, 1, &k);
        }
        func_0013A040(&t, -1);
    }
}
