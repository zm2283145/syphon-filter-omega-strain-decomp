/*
 * lib/medius: 2 files, 002D0658-002D0728
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002D0658 */
extern void *memset(void *, int, unsigned int);
extern char *strncpy(char *, const char *, unsigned int);
extern char *strstr(char *, const char *);
extern int atoi(const char *);
extern char D_004AD3C8[];
extern char D_004AD3D0[];
int MGCLIPStringToBinary(unsigned char *out, const char *s)
{
    char buf[16];
    char *p;
    int i = 0;
    buf[0] = D_004AD3C8[0];
    memset(buf + 1, 0, 15);
    p = buf;
    if (s != 0 && out != 0) {
        strncpy(buf, s, 16);
        for (; i < 3; i++) {
            char *q = strstr(p, D_004AD3D0);
            *q = 0;
            out[i] = atoi(p);
            p = q + 1;
        }
        out[3] = atoi(p);
        return 0;
    }
    return -6;
}
/* merge_units: end func_002D0658 */

/* merge_units: begin func_002D0728 */
typedef struct { char c[0x26]; } M00468708;
static const M00468708 months_init = { "JanFebMarAprMayJunJulAugSepOctNovDec" };
extern int sprintf(char *, const char *, ...);
#if 0 /* merge_units */
extern char *strstr(const char *, const char *);
#endif /* merge_units */
#define strstr(a0, a1) (strstr((char *)(a0), (a1))) /* merge_units */

int MGCLGetMGCLBuildTimeStamp(char *out)
{
    M00468708 months = months_init;
    char mon[16];
    int n;
    char *date = "Nov 25 2003";
    char *tm = "16:14:00";
    sprintf(mon, "%.3s", date);
    n = (strstr(months.c, mon) - months.c) / 3 + 1;
    sprintf(out, "%.2d.%.2d.%.4s.%.2s.%.2s.%.2s", n, atoi(date + 4), date + 7, tm, tm + 3, tm + 6);
    return 0;
}
#undef strstr /* merge_units */
/* merge_units: end func_002D0728 */
