/* same-unit callee stubs: weak, in a section the link discards (the real functions are defined elsewhere); restore retail delay-slot choices */
typedef struct { int w[67]; } N_002F9000;
typedef struct { int x0; int x4; int x8; void *xC; N_002F9000 *x10; N_002F9000 *x14; unsigned char *x18; } S_002F9000;
extern int func_002F7D68(int);
extern S_002F9000 *func_002F7ED8(int, int);
extern S_002F9000 *func_002F7DB8(void);
extern void func_002F7EA0(int, S_002F9000 *);
extern int func_002F7CE8(void *);
int __attribute__((weak, section(".dtors_drop"))) func_002F7D28(unsigned char *a0) { return 0; }
extern void func_002F84D0(int, int, void *);
void __attribute__((weak, section(".dtors_drop"))) func_002F8C50(int a, int b, unsigned char *c) { }
int func_002F9000(int a, int b, int c, int d)
{
    S_002F9000 *s;
    S_002F9000 *t;
    int h;
    h = func_002F7D68(a);
    if (h == 0) return -1;
    s = func_002F7ED8(h, b);
    if (s == 0) return -1;
    h = func_002F7D68(c);
    if (h == 0) return -1;
    t = func_002F7ED8(h, d);
    if (t == 0) {
        t = func_002F7DB8();
        t->x8 = d;
        func_002F7EA0(h, t);
    }
    if (func_002F7CE8(s->xC) == 0) func_002F84D0(c, d, s->xC);
    if (func_002F7D28(s->x18) == 0) {
        func_002F8C50(c, d, s->x18);
        *t->x10 = *s->x10;
        *t->x14 = *s->x14;
    }
    return 0;
}
