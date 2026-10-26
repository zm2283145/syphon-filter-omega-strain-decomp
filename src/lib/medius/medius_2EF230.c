/*
 * lib/medius: 2 files, 002EF230-002EF330
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002EF230 */
#define F(p,T,o) (*(T *)((char *)(p) + (o)))
typedef struct { int key; int a; int used; int b; int c; } E2EF230;
extern int GetLocalID(void *, int *);
extern int GetResourceManager(int);
extern int GetResourceLimit(int);
extern int GetUsedSequencerCount(int);
extern int GetPlayerCountInSet(void *);
void GridUpdateSpeakStatus(void *s)
{
    int me = 0xFFFF;
    int h, a, i;
    GetLocalID(F(s, void *, 8), &me);
    for (i = 0; i < F(s, int, 0x5C); i++)
        if (F(s, E2EF230 *, 0x60)[i].used == 2) break;
    if (i < F(s, int, 0x5C)) {
        h = GetResourceManager(F(s, int, 8));
        a = GetResourceLimit(h);
        if (GetUsedSequencerCount(h) < a) goto one;
        if (GetPlayerCountInSet((char *)s + 0x50) <= a + 1) goto one;
    }
    F(s, int, 0x68) = 0;
    return;
one:
    F(s, int, 0x68) = 1;
}
/* merge_units: end func_002EF230 */

/* merge_units: begin func_002EF330 */
typedef struct { short type; short id; unsigned short count; short pad; int self; int pad2; } H2EF330;
typedef struct { int key; int a; int used; int b; int c; } E2EF330;
extern int GetCurChannel(int);
extern void GridSetPackHeader(void *, void *, int, int);
extern int SendPackage(int, int, void *, void *, int);
int GridSendGreeting(void *s, int key, int force)
{
    char buf[16];
    H2EF330 h;
    int me = 0xFFFF;
    int n, c;
    E2EF330 *e;
    GetLocalID(F(s, void *, 8), &me);
    h.self = me;
    h.id = GetCurChannel(F(s, int, 8));
    h.type = 0xC;
    h.count = 0;
    n = F(s, int, 0x5C);
    if (n > 0) {
        e = F(s, E2EF330 *, 0x60);
        c = 0;
        for (; n != 0; n--, e++)
            if (e->used == 0 || e->key == key) c++;
        h.count = c;
    }
    if (h.count == 0 && F(s, int, 0x58) == 0) h.count++;
    if (force != 0 || h.count != 0) {
        GridSetPackHeader(s, buf, 5, 0xC);
        return SendPackage(F(s, int, 8), key, buf, &h, 0xC);
    }
    return 0;
}
/* merge_units: end func_002EF330 */
