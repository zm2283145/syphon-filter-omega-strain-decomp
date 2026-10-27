/* same-unit callee stub: weak, in a section the link discards (the real function is defined elsewhere); restores retail delay-slot choices */
int __attribute__((weak, section(".dtors_drop"))) IsNullRSAKey(char * a0) { return 0; }
extern int GetKeyMaster(int);
extern char *GetKeyChain(int, int);
extern int IsNullRCKey(int);
extern void KM_SHA1(int, int, int, int);
extern int RSADecrypt(char *, char *, int, int, int);
int KM_DigiSign(int a, int b, char *c, char *d, int e)
{
    int h;
    char *s;
    if (e) {
        if (IsNullRSAKey(c)) return -1;
        if (!IsNullRSAKey(d)) {
            h = GetKeyMaster(a);
            if (h == 0) return -1;
            s = GetKeyChain(h, b);
            if (s == 0) return -1;
            if (!IsNullRCKey(*(int *)(s + 0x18))) goto ok;
        }
    }
    return -1;
ok:
    KM_SHA1(*(int *)(s + 0x18), 4, e, 0x40);
    RSADecrypt(c, d, e, e, 0x40);
    return 0;
}
