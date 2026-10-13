typedef struct { char b[64]; } B64;
typedef struct { char pad[0x1C]; B64 *k0; B64 *k1; } S8730;
extern S8730 *func_002F7D68(int, B64 *);
extern int func_002F7CE8(B64 *);
extern void func_002FB2D8(void *, int);
extern void *memset(void *, int, unsigned int);
int func_002F8730(int a, B64 *k)
{
    S8730 *s;
    int r = -1;
    s = func_002F7D68(a, k);
    if (s != 0) {
        if (func_002F7CE8(&k[0]) != 0 || func_002F7CE8(&k[1]) != 0) {
            if (s->k0) memset(s->k0, 0, 64);
            if (s->k1) memset(s->k1, 0, 64);
        } else {
            if (s->k0 == 0) func_002FB2D8(&s->k0, 64);
            if (s->k1 == 0) func_002FB2D8(&s->k1, 64);
            *s->k0 = k[0];
            *s->k1 = k[1];
        }
        r = 0;
    }
    return r;
}
