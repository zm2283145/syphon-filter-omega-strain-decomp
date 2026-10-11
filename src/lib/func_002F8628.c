typedef struct { char b[64]; } B64;
typedef struct { char pad[0xC]; B64 *p; } X;
extern void *func_002F7D68(int, int);
extern X *func_002F7ED8(void *, int);
extern int func_002F7CE8(B64 *);
extern void *memset(void *, int, unsigned int);
int func_002F8628(int a, int b, B64 *out)
{
    void *s;
    X *x;
    int r;    s = func_002F7D68(a, b);
    if (s != 0) {
        x = func_002F7ED8(s, b);
        if (x != 0) {
            r = func_002F7CE8(x->p);
            if (r == 0) {
                *out = *x->p;
                return r;
            }
        }
    }
    if (out) memset(out, 0, 64);
    return -1;
}
