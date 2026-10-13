typedef struct { int w[32]; } B_002F0670;
extern unsigned int func_002F1C38(B_002F0670 *);
extern void func_002EFC00(B_002F0670 *, int);
extern void func_002F1FD8(B_002F0670 *, unsigned int);
extern void func_002F1EA0(B_002F0670 *, unsigned int);
extern int func_002F1E20(B_002F0670 *, B_002F0670 *);
extern void func_002F2244(B_002F0670 *, B_002F0670 *);
extern void func_002EFDC8(B_002F0670 *, unsigned int);
void func_002F0670(B_002F0670 *x, B_002F0670 *y, B_002F0670 *q, B_002F0670 *r)
{
    B_002F0670 b;
    unsigned int na;
    unsigned int nb;
    unsigned int ny;
    b = *y;
    *r = *x;
    na = func_002F1C38(r);
    nb = func_002F1C38(&b);
    func_002EFC00(q, 0);
    ny = nb;
    if (nb < na) {
        func_002F1FD8(&b, na - nb);
        nb = na;
    }
    while (na >= ny) {
        if (na < nb) {
            func_002F1EA0(&b, nb - na);
            nb = na;
        }
        if (func_002F1E20(r, &b)) {
            func_002F2244(r, &b);
            na = func_002F1C38(r);
            func_002EFDC8(q, nb - ny);
        } else if (ny < nb) {
            nb--;
            func_002F1EA0(&b, 1);
        } else {
            break;
        }
    }
}
