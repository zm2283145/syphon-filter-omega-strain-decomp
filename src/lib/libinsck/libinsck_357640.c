/*
 * lib/libinsck: 3 files, 00357640-00357840
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00357640 */
extern unsigned int func_00357150(void);

unsigned int sceInsockInetNetof(void)
{
    unsigned int v = func_00357150();
    if ((v & 0x80000000) == 0) return v >> 24;
    if ((v & 0xC0000000) != 0x80000000) return v >> 8;
    return v >> 16;
}
/* merge_units: end func_00357640 */

/* merge_units: begin func_00357680 */
static inline int is_space(unsigned char c)
{
    int r = 0;
    if ((unsigned int)(c - 9) < 5 || c == ' ')
        r = 1;
    return r;
}

static inline int is_xdigit(char c)
{
    int r = 0;
    unsigned char u;
    if ((unsigned char)(u - '0') < 10 || (unsigned int)((unsigned char)c - 'a') < 6 ||
        (unsigned int)((unsigned char)c - 'A') < 6)
        r = 1;
    return r;
}

unsigned int sceInsockInetNetwork(char *cp)
{
    int val; unsigned int base;
    unsigned int n, i;
    char c;
    unsigned char u;
    unsigned int parts[4], *pp = parts;

again:
    val = 0;
    base = 10;
    if (*cp == '0') {
        cp++;
        base = 8;
    }
    if (*cp == 'x' || *cp == 'X') {
        cp++;
        base = 16;
    }
    while ((c = *cp)) {
        if ((unsigned int)((unsigned char)c - '0') < 10) {
            val = (val * base) + (c - '0');
            cp++;
            continue;
        }
        if (base == 16 && is_xdigit(c)) {
            { int d = (val << 4) + (c + 10 - ((unsigned int)((unsigned char)c - 'a') < 26 ? 'a' : 'A')); val = d; }
            cp++;
            continue;
        }
        break;
    }
    if (*cp == '.') {
        if (pp >= parts + 3)
            return 0xFFFFFFFF;
        *pp++ = val, cp++;
        goto again;
    }
    if (*cp && !is_space(*cp))
        return 0xFFFFFFFF;
    *pp++ = val;
    n = pp - parts;
    val = 0;
    for (i = 0; i < n; i++)
    {
        val <<= 8;
        val |= parts[i] & 0xff;
    }
    return val;
}
/* merge_units: end func_00357680 */

/* merge_units: begin func_00357840 */
typedef struct { unsigned long long a,b; unsigned short c; } S7840;
extern S7840 D_005335C0;
extern int sceInsockInetNtop(int,int*,S7840*,int);
S7840 *sceInsockInetNtoa(int x) {
 int v[1];
 __builtin_memcpy(&D_005335C0,((S7840*)"[inet_ntoa error]"),18);
 v[0]=x;
 sceInsockInetNtop(2,v,&D_005335C0,0x12);
 return &D_005335C0;
}
/* merge_units: end func_00357840 */
