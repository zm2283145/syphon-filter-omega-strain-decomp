extern int func_002DD9B0(unsigned char **, unsigned int);
int func_002E69B8(int n)
{
    unsigned char *b;
    int i, j, ok;
    if ((unsigned int)n >= 0x800) return -1;
    for (i = 0; i < 0x800 - n; i++) {
        func_002DD9B0(&b, i);
        if (*b == 0) {
            ok = 1;
            for (j = i + 1; j < i + n; j++) {
                func_002DD9B0(&b, j);
                if (*b) { ok = 0; break; }
            }
            if (ok) return i;
        }
    }
    return -1;
}

