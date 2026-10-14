typedef struct { int d[0x110]; } __attribute__((aligned(16))) Big;
typedef struct { char pad[0x9A4]; Big* buf; unsigned char arr[0x100]; } Obj;
extern void* func_004073C0(Big* b, int* len);
extern void* memset(void* d, int c, unsigned int n);
extern void* memcpy(void* d, const void* s, unsigned int n);
static inline void QMove(void* d, void* s) {
    int n = 0x44; __int128 t;
    asm {
        .set noreorder
    lp:
        lq t, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq t, -0x10(d)
        .set reorder
    }
}
static inline int Mn(int a, int b) { int r; if (a < b) { r = a; asm { .set reorder } } else r = b; return r; }

void func_00334000(Obj* o, Big* src)
{
    int len;
    void* data;
    QMove(o->buf, src);
    len = 0;
    data = func_004073C0(o->buf, &len);
    len = Mn(len, 0x100);
    memset(o->arr, 0, 0x100);
    memcpy(o->arr, data, len);
}




