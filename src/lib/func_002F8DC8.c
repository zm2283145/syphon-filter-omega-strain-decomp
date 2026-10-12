/* same-unit callee stub: weak, in a section the link discards (the real function is defined elsewhere); restores retail delay-slot choices */
typedef struct { char b[0x40]; } B2F8DC8;
extern int func_002F7D68(int);
extern char *func_002F7ED8(int, int);
int __attribute__((weak, section(".dtors_drop"))) func_002F7D28(int a0) { return 0; }
extern void *memset(void *, int, unsigned int);
int func_002F8DC8(int a, int b, B2F8DC8 *out)
{
    char *s;
    int h = func_002F7D68(a);
    if (h == 0) return -1;
    if (out == 0) return -1;
    s = func_002F7ED8(h, b);
    if (s == 0 || func_002F7D28(*(int *)(s + 0x18))) {
        memset(out, 0, 0x40);
        return -1;
    }
    *out = **(B2F8DC8 **)(s + 0x18);
    return 0;
}
