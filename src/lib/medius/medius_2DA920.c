/*
 * lib/medius: 3 files, 002DA920-002DAA50
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002DA920 */
typedef struct { char b[32]; } B2DA920;
extern int GetPlayerByID(char *, int);
int GetClientInfo(char *s, int b, B2DA920 *out)
{
    if (!GetPlayerByID(s, b)) return -1;
    *out = *(B2DA920 *)(*(char **)(s + 0x68) + 0x20);
    return 0;
}
/* merge_units: end func_002DA920 */

/* merge_units: begin func_002DA9A8 */
#if 0 /* merge_units */
extern char *GetPlayerByID(char *, int);
#endif /* merge_units */
#define GetPlayerByID(a0, a1) ((char *)GetPlayerByID((a0), (a1))) /* merge_units */

extern void GridSetPackHeader(int, char *, int, int);
extern void SendPackage(char *, int, char *, int *, int);
int SetIgnoreFlag(char *s, int id, int v)
{
    char buf[16];
    int w;
    char *p;
    if (id == 0xFFFF || id == *(int *)(s + 0x78)) return -1;
    p = GetPlayerByID(s, id);
    if (p == 0) return -1;
    *(int *)(p + 0x38) = v;
    w = v;
    GridSetPackHeader(*(int *)(s + 0x64), buf, 0x11, 4);
    SendPackage(s, id, buf, &w, 4);
    return 0;
}
#undef GetPlayerByID /* merge_units */
/* merge_units: end func_002DA9A8 */

/* merge_units: begin func_002DAA50 */
extern int GetGrid(char *, int);
extern void GridSendRedundancyMessage(int);
int SetRedundancyOff(char *o, int v)
{
    if (*(int *)(o + 0x74) && v == 0) {
        int n = *(int *)(o + 0x98);
        if (n > 0) GridSendRedundancyMessage(GetGrid(o, n));
    }
    *(int *)(o + 0x74) = v;
    return 0;
}
/* merge_units: end func_002DAA50 */
