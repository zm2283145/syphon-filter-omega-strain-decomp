/*
 * lib/medius: 2 files, 002F8EC8-002F8F70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002F8EC8 */
extern int func_002F7D28(unsigned char *);
extern int func_002F8DC8(int, int, unsigned char *);
int func_002F8EC8(int a, int b, unsigned char *n)
{
    unsigned char buf[0x40];
    int i;
    if (func_002F7D28(n)) return -1;
    if (func_002F8DC8(a, b, buf)) return 1;
    i = 0x3F;
    do {
        if (n[i] > buf[i]) return 1;
        if (n[i] < buf[i]) return -1;
    } while (i-- > 0);
    return 0;
}
/* merge_units: end func_002F8EC8 */

/* merge_units: begin func_002F8F70 */
extern void *memset(void *, int, unsigned int);
extern int func_002F7D68(int);
extern char *func_002F7ED8(int, int);
void func_002F8F70(int a, int b)
{
    char *s;
    int h = func_002F7D68(a);
    if (h == 0) return;
    s = func_002F7ED8(h, b);
    if (s == 0) return;
    if (*(void **)(s + 0x18)) memset(*(void **)(s + 0x18), 0, 0x40);
    if (*(void **)(s + 0x10)) memset(*(void **)(s + 0x10), 0, 0x10C);
    if (*(void **)(s + 0x14) == 0) memset(*(void **)(s + 0x14), 0, 0x10C);
}
/* merge_units: end func_002F8F70 */
