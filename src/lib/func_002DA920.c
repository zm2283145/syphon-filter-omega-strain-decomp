typedef struct { char b[32]; } B2DA920;
extern int func_002D9E88(char *, int);
int func_002DA920(char *s, int b, B2DA920 *out)
{
    if (!func_002D9E88(s, b)) return -1;
    *out = *(B2DA920 *)(*(char **)(s + 0x68) + 0x20);
    return 0;
}
