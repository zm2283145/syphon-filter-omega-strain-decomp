/* same-unit callee stub: weak, in a section the link discards (the real function is defined elsewhere); restores retail delay-slot choices */
int __attribute__((weak, section(".dtors_drop"))) func_002F7CE8(char * a0) { return 0; }
extern int func_002F7D68(int);
extern char *func_002F7ED8(int, int);
extern int func_002F7D28(int);
extern void Sha1_Digest(int, int, int, int);
extern int func_002F4D00(char *, char *, int, int, int);
int func_002F9278(int a, int b, char *c, char *d, int e)
{
    int h;
    char *s;
    if (e) {
        if (func_002F7CE8(c)) return -1;
        if (!func_002F7CE8(d)) {
            h = func_002F7D68(a);
            if (h == 0) return -1;
            s = func_002F7ED8(h, b);
            if (s == 0) return -1;
            if (!func_002F7D28(*(int *)(s + 0x18))) goto ok;
        }
    }
    return -1;
ok:
    Sha1_Digest(*(int *)(s + 0x18), 4, e, 0x40);
    func_002F4D00(c, d, e, e, 0x40);
    return 0;
}
