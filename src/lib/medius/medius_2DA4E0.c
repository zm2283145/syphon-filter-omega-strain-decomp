/*
 * lib/medius: 5 files, 002DA4E0-002DA880
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002DA4E0 */
extern void GridSetPackHeader(int, char *, int, int);
extern int GridSendPackage(int, int, char *, unsigned short *, int);
extern char *GetGrid(char *, int);
extern void GridRemovePlayer(char *, int);
extern void GridInvalidateAllConnection(char *);
extern void SetPlayerCurChannel(int, int);
extern void ResetAudioStatus(char *, int);
int QuitChannel(char *s, int id)
{
    char buf[16];
    unsigned short v;
    int r;
    char *n;
    if (id == 0 || id != *(int *)(s + 0x98)) return -1;
    v = id;
    GridSetPackHeader(*(int *)(s + 0x64), buf, 0xA, 2);
    r = GridSendPackage(*(int *)(s + 0x64), *(int *)(s + 0x78), buf, &v, 2);
    n = GetGrid(s, *(int *)(s + 0x98));
    if (n) {
        GridRemovePlayer(n, *(int *)(s + 0x78));
        GridInvalidateAllConnection(n);
    }
    *(int *)(s + 0x98) = 0;
    SetPlayerCurChannel(*(int *)(s + 0x68), 0);
    ResetAudioStatus(s, 4);
    return r;
}
/* merge_units: end func_002DA4E0 */

/* merge_units: begin func_002DA5A8 */
extern void GridGetEnumChannelInfo(char *, char *);
extern char *GridGetNext(char *);
int EnumChannel(char *s, int (*cb)(char *, int, char *), int arg)
{
    char buf[0x40];
    char *n = *(char **)(s + 0x64);
    if (cb == 0) return -1;
    while (n) {
        GridGetEnumChannelInfo(n, buf);
        if (!cb(s, arg, buf)) break;
        n = GridGetNext(n);
        if (n == *(char **)(s + 0x64)) n = 0;
    }
    return 0;
}
/* merge_units: end func_002DA5A8 */

/* merge_units: begin func_002DA640 */
typedef struct { char b[0x18]; unsigned int flags; char c[4]; } I2DA640;
extern int GetPlayerStatus(char *);
int EnumPlayer(char *s, int (*cb)(char *, int, I2DA640 *), int arg)
{
    I2DA640 info;
    char *n, *head;
    if (cb == 0 || *(int *)(s + 0x64) == 0) return -1;
    n = *(char **)(s + 0x6C);
    head = n;
    while (n) {
        info = *(I2DA640 *)(n + 0x20);
        if (GetPlayerStatus(n) & 0x4000) info.flags |= 0x8000;
        else info.flags &= ~0x8000;
        if (!cb(s, arg, &info)) break;
        n = *(char **)(n + 4);
        if (n == head) n = 0;
    }
    return 0;
}
/* merge_units: end func_002DA640 */

/* merge_units: begin func_002DA750 */
typedef struct { unsigned char b[32]; } S2DA750;
typedef struct N2DA750 { int a; struct N2DA750 *next; char *obj; } N2DA750;
#if 0 /* merge_units */
extern int GetGrid(int, int);
#endif /* merge_units */
#define GetGrid(a0, a1) ((int)GetGrid((char *)(a0), (a1))) /* merge_units */

extern N2DA750 *GridGetFirstPlayerRef(int);
int EnumChannelPlayer(int a, int (*cb)(int, int, S2DA750 *), int arg, int key)
{
    int v = GetGrid(a, key);
    N2DA750 *n, *head;
    S2DA750 tmp;
    if (cb == 0 || v == 0) return -1;
    n = head = GridGetFirstPlayerRef(v);
    while (n) {
        tmp = *(S2DA750 *)(n->obj + 0x20);
        if (GetPlayerStatus(n->obj) & 0x4000) ((int *)&tmp)[6] |= 0x8000;
        else ((int *)&tmp)[6] &= ~0x8000;
        if (cb(a, arg, &tmp) == 0) break;
        n = n->next;
        if (n == head) n = 0;
    }
    return 0;
}
#undef GetGrid /* merge_units */
/* merge_units: end func_002DA750 */

/* merge_units: begin func_002DA880 */
#if 0 /* merge_units */
extern int GetGrid(int, int);
#endif /* merge_units */
#define GetGrid(a0, a1) ((int)GetGrid((char *)(a0), (a1))) /* merge_units */

extern int EnumGridConnectedPlayer(int, int, int);
int EnumConnectedPlayer(int a, int b, int c, int d)
{
    int h = GetGrid(a, d);
    if (b == 0 || h == 0) return -1;
    return EnumGridConnectedPlayer(h, b, c);
}
#undef GetGrid /* merge_units */
/* merge_units: end func_002DA880 */
