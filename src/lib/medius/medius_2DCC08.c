/*
 * lib/medius: 2 files, 002DCC08-002DCD00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002DCC08 */
extern unsigned int D_0048C450;
extern int NetGetConnInfo(unsigned int, char **);
extern int NetIGetObject(unsigned char **, unsigned int);
int NetGetMyPersistantObjectCount(unsigned short *out)
{
    char *p = 0;
    unsigned char *e = 0;
    unsigned int i = 0;
    int r;
    if (out == 0) return 0x17;
    *out = 0;
    if (D_0048C450 == 4) return 0;
    if (D_0048C450 >= 4) return 8;
    r = NetGetConnInfo(D_0048C450, &p);
    if (r) return r;
    if (p == 0) return r;
    if (*(unsigned int *)(p + 0x400) >= 0x100) return 8;
    for (; i < 0x1000; i++) {
        r = NetIGetObject(&e, i);
        if (r) return r;
        if (e && (e[2] == 3 || e[2] == 4) && *(int *)(p + 0x400) == *(int *)(e + 8)) (*out)++;
    }
    return 0;
}
/* merge_units: end func_002DCC08 */

/* merge_units: begin func_002DCD00 */
unsigned short DmeToRtMsgConnectionIndex(int a)
{
    if (a < 5)
        return a - 1;
    return a;
}
/* merge_units: end func_002DCD00 */
