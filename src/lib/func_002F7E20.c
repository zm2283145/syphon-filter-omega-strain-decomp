extern void func_002FB3C0(void *);
void func_002F7E20(char *s)
{
    if (s == 0) return;
    if (*(int *)(s + 0xC)) func_002FB3C0(s + 0xC);
    if (*(int *)(s + 0x18)) func_002FB3C0(s + 0x18);
    if (*(int *)(s + 0x10)) func_002FB3C0(s + 0x10);
    if (*(int *)(s + 0x14)) func_002FB3C0(s + 0x14);
    func_002FB3C0(&s);
}
