/* same-unit callee stub: weak, in a section the link discards (the real function is defined elsewhere); restores retail delay-slot choices */
typedef struct { char b[0x40]; } B2F8DC8;
extern int GetKeyMaster(int);
extern char *GetKeyChain(int, int);
int __attribute__((weak, section(".dtors_drop"))) IsNullRCKey(int a0) { return 0; }
extern void *memset(void *, int, unsigned int);
int KM_GetSymmetricKey(int a, int b, B2F8DC8 *out)
{
    char *s;
    int h = GetKeyMaster(a);
    if (h == 0) return -1;
    if (out == 0) return -1;
    s = GetKeyChain(h, b);
    if (s == 0 || IsNullRCKey(*(int *)(s + 0x18))) {
        memset(out, 0, 0x40);
        return -1;
    }
    *out = **(B2F8DC8 **)(s + 0x18);
    return 0;
}
