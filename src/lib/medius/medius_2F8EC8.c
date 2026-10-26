/*
 * lib/medius: 2 files, 002F8EC8-002F8F70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002F8EC8 */
extern int IsNullRCKey(unsigned char *);
extern int KM_GetSymmetricKey(int, int, unsigned char *);
int KM_CompareSymmetricKey(int a, int b, unsigned char *n)
{
    unsigned char buf[0x40];
    int i;
    if (IsNullRCKey(n)) return -1;
    if (KM_GetSymmetricKey(a, b, buf)) return 1;
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
extern int GetKeyMaster(int);
extern char *GetKeyChain(int, int);
void KM_DeleteSymmetricKey(int a, int b)
{
    char *s;
    int h = GetKeyMaster(a);
    if (h == 0) return;
    s = GetKeyChain(h, b);
    if (s == 0) return;
    if (*(void **)(s + 0x18)) memset(*(void **)(s + 0x18), 0, 0x40);
    if (*(void **)(s + 0x10)) memset(*(void **)(s + 0x10), 0, 0x10C);
    if (*(void **)(s + 0x14) == 0) memset(*(void **)(s + 0x14), 0, 0x10C);
}
/* merge_units: end func_002F8F70 */
