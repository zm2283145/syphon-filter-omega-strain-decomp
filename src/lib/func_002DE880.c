extern int Net_SendTyped(signed char, int, int, int, unsigned int, int, int);
int func_002DE880(signed char a, int b, int c, unsigned int d, int e, int f)
{
    if (d >= 0x100) return 0x17;
    if (e <= 0) return 0x17;
    if (f == 0) return 0x17;
    return Net_SendTyped(a, b, c, 0, d, e, f);
}
