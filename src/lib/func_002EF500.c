extern void func_002DA900(void *, int *);
extern void func_002EDD08(char *, char *, int, int);
extern int func_002ED940(char *, int, char *, int, int);
extern void func_002F3450(char *);
extern void func_002ED620(char *);
void func_002EF500(char *s)
{
    char buf[16];
    int h = 0xFFFF;
    int i;
    func_002DA900(*(void **)(s + 8), &h);
    func_002EDD08(s, buf, 0x10, 0);
    func_002ED940(s, h, buf, 0, 0);
    func_002F3450(s + 0x50);
    for (i = 0; i < *(int *)(s + 0x5C); i++)
        func_002ED620(*(char **)(s + 0x60) + i * 0x14);
}

