extern int func_002F7CE8(char *);
extern int func_002F7D68(int);
extern char *func_002F7ED8(int, int);
extern int func_002F7D28(int);
extern void func_002F7FB0(int, int, int *, int);
extern void func_002F4CD0(char *, int, int *, int);
int func_002F9368(int a, int b, char *c, int d)
{
    int buf[16];
    int buf2[16];
    int h;
    char *s;
    unsigned int i;
    if (d == 0) goto fail;
    if (func_002F7CE8(c)) return -1;
    h = func_002F7D68(a);
    if (h == 0) return -1;
    s = func_002F7ED8(h, b);
    if (s == 0) return -1;
    if (func_002F7D28(*(int *)(s + 0x18))) {
fail:
        return -1;
    }
    func_002F7FB0(*(int *)(s + 0x18), 4, buf, 0x40);
    func_002F4CD0(c, d, buf2, 0x40);
    i = 0;
    do {
        if (buf[i] != buf2[i]) goto fail;
    } while (++i < 16);
    return 0;
}
