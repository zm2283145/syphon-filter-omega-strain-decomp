typedef struct Deq { unsigned int cap; unsigned int size; unsigned int start; int* data; } Deq;

extern void func_00123BE8(int, const char*);
extern void func_00121B60(void);
extern char* D_00489738;
extern unsigned int D_004BCEE8[2];
extern signed char D_00542C90;

static inline unsigned int MaxSize(void) {
    int size[1];
    int ref;
    if (D_00542C90 == 0) {
        ref = (int)size;
        size[0] = 0x1800000;
        ref = *(int*)ref;
        D_00542C90 = 1;
        (*(int*)D_004BCEE8) = ref - 1;
    }
    return (*(int*)D_004BCEE8);
}

unsigned int func_003BA0C0(Deq* self, unsigned int n)
{
    unsigned int m = MaxSize();
    unsigned int c;
    if (m < n) {
        func_00123BE8(*(int*)(D_00489738 + 0xC), "cdeque max_size error");
        func_00121B60();
    }
    c = self->cap ? self->cap - 1 : 1;
    while (n > c) {
        if (c < m / 2) c *= 2; else c = m;
    }
    return c;
}

