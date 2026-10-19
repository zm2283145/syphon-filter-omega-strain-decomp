typedef struct { char pad[0x14]; char x14[0x40]; int x54; } SADE0;
extern SADE0 *Insck_GetThreadContext(int);
extern void func_003581C0(void);
extern void func_0034B138(void *, int, int, int);
extern int func_00358158(void);
extern int Insck_SetErrno(SADE0 *, int);
int func_0035ADE0(void)
{
    SADE0 *s = Insck_GetThreadContext(0);
    int e;
    if (s == 0) return -1;
    func_003581C0();
    func_0034B138(s->x14, s->x54, 0, 0x52534C56);
    if (func_00358158() < 0) return Insck_SetErrno(s, -1);
    return Insck_SetErrno(s, 0);
}