extern unsigned int strlen(const char *);
extern unsigned char D_0048C4AC;
extern char D_0058DF80[];
extern int D_0058D17C;
extern int func_002DF708(void);
extern int func_002DD380(char *, char *);
int func_002DF680(char *name, int b)
{
    int r;
    if (name == 0) return 0x17;
    if (strlen(name) == 0) return 0x17;
    if (b == 0) return 0x17;
    if (D_0048C4AC == 0) {
        r = func_002DF708();
        if (r) return r;
    }
    func_002DD380(D_0058DF80, name);
    D_0058D17C = b;
    return 0;
}
