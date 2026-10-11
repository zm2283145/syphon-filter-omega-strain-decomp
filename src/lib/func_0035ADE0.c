typedef struct { char pad[0x14]; char x14[0x40]; int x54; } SADE0;
extern SADE0 *func_003581E0(int);
extern void func_003581C0(void);
extern void func_0034B138(void *, int, int, int);
extern int func_00358158(void);
extern int func_003583A0(SADE0 *, int);
int func_0035ADE0(void)
{
    SADE0 *s = func_003581E0(0);
    int e;
    if (s == 0) return -1;
    func_003581C0();
    func_0034B138(s->x14, s->x54, 0, 0x52534C56);
    if (func_00358158() < 0) return func_003583A0(s, -1);
    return func_003583A0(s, 0);
}