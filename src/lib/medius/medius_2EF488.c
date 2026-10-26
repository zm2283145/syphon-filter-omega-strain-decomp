/*
 * lib/medius: 4 files, 002EF488-002EF6E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002EF488 */
extern void GetLocalID(int, int *);
extern void GridSetPackHeader(char *, char *, int, int);
extern int GridSendPackage(char *, int, char *, int, int);
int GridInviteConnect(char *s)
{
    char buf[16];
    int h = 0xFFFF;
    if (s == 0 || *(int *)(s + 0xC) == 0) return -1;
    GetLocalID(*(int *)(s + 8), &h);
    GridSetPackHeader(s, buf, 0xF, 0);
    return GridSendPackage(s, h, buf, 0, 0);
}
/* merge_units: end func_002EF488 */

/* merge_units: begin func_002EF500 */
#if 0 /* merge_units */
extern void GetLocalID(void *, int *);
#endif /* merge_units */
#define GetLocalID(a0, a1) (GetLocalID((int)(a0), (a1))) /* merge_units */

extern void CleanupPlayerSet(char *);
extern void InvalidateConnection(char *);
void GridQuit(char *s)
{
    char buf[16];
    int h = 0xFFFF;
    int i;
    GetLocalID(*(void **)(s + 8), &h);
    GridSetPackHeader(s, buf, 0x10, 0);
    GridSendPackage(s, h, buf, 0, 0);
    CleanupPlayerSet(s + 0x50);
    for (i = 0; i < *(int *)(s + 0x5C); i++)
        InvalidateConnection(*(char **)(s + 0x60) + i * 0x14);
}
#undef GetLocalID /* merge_units */
/* merge_units: end func_002EF500 */

/* merge_units: begin func_002EF5B0 */
#define F(p,T,o) (*(T *)((char *)(p) + (o)))
typedef struct { int w[8]; } S2EF5B0;
typedef struct { int key; char *obj; int type; int b; int c; } E2EF5B0;
extern int GetPlayerStatus(char *);
int EnumGridConnectedPlayer(void *s, int (*cb)(void *, int, S2EF5B0 *), int arg)
{
    int i;
    E2EF5B0 *e;
    S2EF5B0 tmp;
    for (i = 0; i < F(s, int, 0x5C); i++) {
        e = &F(s, E2EF5B0 *, 0x60)[i];
        if (e->type != 2) continue;
        if (e->obj == 0) continue;
        tmp = *(S2EF5B0 *)(e->obj + 0x20);
        if (GetPlayerStatus(e->obj) & 0x4000) tmp.w[6] |= 0x8000;
        else tmp.w[6] &= ~0x8000;
        if (cb(F(s, void *, 8), arg, &tmp) == 0) break;
    }
    return 0;
}
/* merge_units: end func_002EF5B0 */

/* merge_units: begin func_002EF6E0 */
void GridInvalidateAllConnection(char *o)
{
    int i;
    for (i = 0; i < *(int *)(o + 0x5C); i++)
        InvalidateConnection(*(char **)(o + 0x60) + i * 0x14);
}
/* merge_units: end func_002EF6E0 */
