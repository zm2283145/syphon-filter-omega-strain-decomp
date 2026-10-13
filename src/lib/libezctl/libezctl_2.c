/*
 * lib/libezctl: 5 files, 00353070-003532F8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin ezNetCtlPreloadModemCnf */
extern int D_00492C34;
extern char D_005332C0[];
extern char D_00533280[];
extern char D_004BADB8[];
extern char D_004BADC0[];
extern char D_004BAE08[];
extern int func_0010F388(const char *, ...);
extern int func_00110528(char *, int, int, void *, int, void *, int, void *, void *);
extern void String_Copy(char *, char *);
int ezNetCtlPreloadModemCnf(char *name)
{
    char *res = D_005332C0;
    if (!D_00492C34) {
        func_0010F388(D_004BADB8, D_004BADC0);
        func_0010F388(D_004BAE08);
        return -1;
    }
    String_Copy(res + 0x10, name);
    func_00110528(D_00533280, 7, 0, res, 0x130, res, 0x130, 0, 0);
    func_0010F388(D_004BADB8, D_004BADC0);
    func_0010F388("ezNetCtlPreloadModemCnf returned %d\n", *(int *)res);
    return *(int *)res;
}
/* merge_units: end ezNetCtlPreloadModemCnf */

/* merge_units: begin func_00353130 */
extern char D_004BADB8[], D_004BADC0[], D_004BAE08[];
int func_00353130(void)
{
    int *res = (int *)D_005332C0;
    if (!D_00492C34) {
        func_0010F388(D_004BADB8, D_004BADC0);
        func_0010F388(D_004BAE08);
        return -1;
    }
    func_00110528(D_00533280, 5, 0, res, 4, res, 4, 0, 0);
    return *res;
}
/* merge_units: end func_00353130 */

/* merge_units: begin func_003531B8 */
int func_003531B8(void)
{
    int *res = (int *)D_005332C0;
    if (!D_00492C34) {
        func_0010F388(D_004BADB8, D_004BADC0);
        func_0010F388(D_004BAE08);
        return -1;
    }
    func_00110528(D_00533280, 6, 0, res, 4, res, 4, 0, 0);
    return *res;
}
/* merge_units: end func_003531B8 */

/* merge_units: begin ezNetCtlGetStatus */
int ezNetCtlGetStatus(int *buf)
{
    if (!D_00492C34) {
        func_0010F388(D_004BADB8, D_004BADC0);
        func_0010F388(D_004BAE08);
        return -1;
    }
    func_00110528(D_00533280, 3, 0, buf, 0x110, buf, 0x110, 0, 0);
    if (*buf) {
        func_0010F388(D_004BADB8, D_004BADC0);
        func_0010F388("ezNetCtlGetStatus returned %d\n", *buf);
    }
    return *buf;
}
/* merge_units: end ezNetCtlGetStatus */

/* merge_units: begin func_003532F8 */
extern int func_0010D520(void *, int);
extern int func_0010D500(int);
int func_003532F8(int a, int b, int size, int wait)
{
    struct { int a, b, size, x; } p;
    int r;
    p.a = a;
    p.b = b;
    p.size = (size + 0xF) & ~0xF;
    p.x = 0;
    if (size & 0xF) {
        func_0010F388(D_004BADB8, D_004BADC0);
        func_0010F388("SIF DMA transfer size %d padded to %d\n", size, p.size);
    }
    do {
        r = func_0010D520(&p, 1);
    } while (r == 0);
    if (!wait)
        while (func_0010D500(r) >= 0)
            ;
    return r;
}
/* merge_units: end func_003532F8 */
