extern int func_002DD968(unsigned char **, unsigned int);
extern void (*D_0058C0F8[])(int, unsigned int, unsigned int);
void func_002DE950(int a, unsigned int b, unsigned int c)
{
    unsigned char *p;
    void (*f)(int, unsigned int, unsigned int);
    if (b >= 0x1000) return;
    if (c < 0x40 || c == -2 || c == -1) {
        func_002DD968(&p, b);
        if (p) {
            f = D_0058C0F8[*p];
            if (f) f(a, b, c);
        }
    }
}
