/* same-unit callee stub: weak, in a section the link discards (the real function is defined elsewhere); restores retail delay-slot choices */
typedef struct { char b[64]; } B64;
typedef struct { char pad[0x2c]; B64 *p; } S;
extern S *GetKeyMaster(int, int);
int __attribute__((weak, section(".dtors_drop"))) IsNullRCKey(B64 * a0) { return 0; }
extern void *memset(void *, int, unsigned int);
int KM_GetGameSessionKey(int a, int b, B64 *out)
{
    S *s = GetKeyMaster(a, b);
    int r;    if (out != 0) {
        if (s != 0 && (r = IsNullRCKey(s->p)) == 0) { *out = *s->p; return r; }
        memset(out, 0, 64);
    }
    return -1;
}
