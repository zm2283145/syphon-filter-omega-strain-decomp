typedef struct { char pad[0x14]; char x14[0x40]; int x54; } SA248;
typedef struct { char pad[0xC]; int xC; } TA248;
extern SA248 *func_003581E0(int);
extern TA248 *func_00358480(int);
extern void func_003581C0(void);
extern int func_0034B180(void *, int, int, int, void *, int);
extern int func_00358158(void);
extern int func_00358578(int);
extern int func_003583A0(SA248 *, int);
int func_0035A248(int a, int b)
{
    int v[1];
    SA248 *s;
    TA248 *t;
    int r;
    v[0] = b;
    s = func_003581E0(0);
    if (s == 0) return -1;
    t = func_00358480(a);
    if (t == 0) return func_003583A0(s, 9);
    func_003581C0();
    r = func_0034B180(s->x14, s->x54, t->xC, 0x10, v, 4);
    if (func_00358158() < 0) return func_003583A0(s, -1);
    if (r >= 0) return func_003583A0(s, 0);
    return func_003583A0(s, func_00358578(r));
}