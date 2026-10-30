extern unsigned char D_004912E8[];
extern unsigned int D_004912F0[];
extern unsigned int* D_004912F4[];
extern unsigned int D_0052980C[];
extern unsigned int D_00529808[];
int rt_parse_register(unsigned int* out, unsigned int type, int value)
{
    unsigned int n; unsigned int c;
    if (D_004912E8[0] != 1) return 3;
    if (D_004912F0[0] == 0) return 3;
    if (D_004912F4[0] == 0) return 3;
    if (out == 0) return 2;
    if (type >= D_0052980C[0]) return 2;
    c = D_004912F4[0][type];
    if (c > D_00529808[0]) return 5;
    n = c;
    c = 0; /* kills c's CSE equivalence so n + 1 is computed from n */
    D_004912F4[0][type] = n + 1;
    {
        int* p = (int*)D_004912F0[0];
        unsigned int idx = type * D_00529808[0] + n;
        *out = n;
        p[idx] = value;
    }
    return 0;
}

