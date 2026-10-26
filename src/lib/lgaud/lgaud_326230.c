/*
 * lib/lgaud: 4 files, 00326230-00326350
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00326230 */
extern void GetOsdConfigParam(void *);
extern int IsT10K(void);
extern short D_004914A0;
int sceScfGetTimeZone(void)
{
    int c;
    int r;
    if (IsT10K()) {
        r = D_004914A0;
    } else {
        GetOsdConfigParam(&c);
        r = c >> 21; if (!(((unsigned int)c >> 13) & 7)) r = 0x21C;
    }
    return r;
}
/* merge_units: end func_00326230 */

/* merge_units: begin func_00326280 */
extern int GetOsdConfigParam2(void *, int, int);
typedef struct { unsigned char lo:4; unsigned char b4:1; unsigned char b5:1; unsigned char top:2; } Cfg6280;
extern unsigned char D_004914A3;
int sceScfGetDateNotation(void)
{
    struct { unsigned int c; unsigned char b[4]; } s;
    int r;
    if (IsT10K()) {
        r = D_004914A3;
    } else {
        GetOsdConfigParam(&s.c);
        if (((s.c >> 13) & 7) == 0) r = 0;
        else {
            GetOsdConfigParam2(s.b, 1, 1);
            r = ((Cfg6280 *)s.b)->top;
        }
    }
    return r;
}
/* merge_units: end func_00326280 */

/* merge_units: begin func_003262E8 */
extern unsigned char D_004914A6;
int sceScfGetSummerTime(void)
{
    struct { unsigned int c; unsigned char b[4]; } s;
    int r;
    if (IsT10K()) {
        r = D_004914A6;
    } else {
        GetOsdConfigParam(&s.c);
        if (((s.c >> 13) & 7) == 0) r = 0;
        else {
            GetOsdConfigParam2(s.b, 1, 1);
            r = ((Cfg6280 *)s.b)->b4;
        }
    }
    return r;
}
/* merge_units: end func_003262E8 */

/* merge_units: begin func_00326350 */
extern unsigned char D_004914A7;
int sceScfGetTimeNotation(void)
{
    struct { unsigned int c; unsigned char b[4]; } s;
    int r;
    if (IsT10K()) {
        r = D_004914A7;
    } else {
        GetOsdConfigParam(&s.c);
        if (((s.c >> 13) & 7) == 0) r = 0;
        else {
            GetOsdConfigParam2(s.b, 1, 1);
            r = ((Cfg6280 *)s.b)->b5;
        }
    }
    return r;
}
/* merge_units: end func_00326350 */
