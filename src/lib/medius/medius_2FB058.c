/* same-unit callee stub: weak, in a section the link discards (the real function is defined elsewhere); restores retail delay-slot choices */
extern int func_002FAF80(int, unsigned int *);
extern int func_002FAFB0(int, unsigned int *);
int __attribute__((weak, section(".dtors_drop"))) func_002FB000(int a0, unsigned int * a1) { return 0; }
extern int func_002FAC80(int, int);
int func_002FB058(int s, int b, unsigned int n)
{
    unsigned int y = 0;
    unsigned int x = 0;
    int r;
    r = func_002FAF80(s, &x);
    if (r) return r;
    if (x < n) return 3;
    r = func_002FAFB0(s, &y);
    if (r) return r;
    if (y < n) {
        r = func_002FB000(s, &x);
        if (r) return r;
        if (x - y >= n) {
            ((int *)s)[1] = 0;
        } else {
            r = func_002FAC80(s, b);
            if (r) return r;
        }
    }
    return 0;
}
