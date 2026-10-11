extern char *func_002D9E18(int, int);
extern void func_002EF878(char *, int);
extern void func_002EF748(char *, char *);
void func_002F3198(char *s, int v)
{
    if (*(int *)(s + 0x30) == v) return;
    if (*(int *)(s + 0x30) > 0) func_002EF878(func_002D9E18(*(int *)(s + 8), *(int *)(s + 0x30)), *(int *)(s + 0x34));
    *(int *)(s + 0x30) = v;
    if (v <= 0) return;
    func_002EF748(func_002D9E18(*(int *)(s + 8), v), s);
}
