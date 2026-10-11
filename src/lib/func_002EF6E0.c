extern void func_002ED620(char *);
void func_002EF6E0(char *o)
{
    int i;
    for (i = 0; i < *(int *)(o + 0x5C); i++)
        func_002ED620(*(char **)(o + 0x60) + i * 0x14);
}