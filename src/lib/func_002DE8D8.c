extern int func_002DD968(unsigned char **, unsigned int);
extern void (*D_0058C0B8[])(unsigned int, unsigned int);
void func_002DE8D8(unsigned int a, unsigned int b)
{
    unsigned char *p;
    void (*f)(unsigned int, unsigned int);
    if (a < 0x100 && b < 0x1000) {
        func_002DD968(&p, b);
        if (p) {
            f = D_0058C0B8[*p];
            if (f) f(a, b);
        }
    }
}
