/*
 * lib/medius: 6 files, 002F2FA8-002F3198
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002F2FA8 */
typedef struct N2FA8 { int pad; struct N2FA8 *next; char pad2[0x2C]; int id; } N2FA8;
N2FA8 *GetPlayerFromGroup(N2FA8 *head, int id)
{
    N2FA8 *n = head;
    while (n && n->id != id) {
        n = n->next;
        if (n == head) n = 0;
    }
    return n;
}
/* merge_units: end func_002F2FA8 */

/* merge_units: begin func_002F2FD8 */
typedef struct N2FD8 { int pad; struct N2FD8 *next; } N2FD8;
int GetPlayerCountInGroup(N2FD8 *head)
{
    N2FD8 *n;
    int c = 0;
    for (n = head; n; c++) {
        n = n->next;
        if (n == head) n = 0;
    }
    return c;
}
/* merge_units: end func_002F2FD8 */

/* merge_units: begin func_002F3010 */
typedef struct S3010 { struct S3010 *a, *b; int c; int d[3]; int x18; } S3010;
extern void rt_memory_allocate_init_zero(void *, int);
S3010 *CreatePlayer(int c)
{
    S3010 *p = 0;
    rt_memory_allocate_init_zero(&p, 0x860);
    if (p) {
        p->b = p->a = p;
        p->c = c;
        p->x18 = 0;
    }
    return p;
}
/* merge_units: end func_002F3010 */

/* merge_units: begin func_002F3068 */
typedef struct { char b[32]; } Blk2F3068;
typedef struct S2F3068 { struct S2F3068 *a, *b; int c; int d; int pad[4]; Blk2F3068 key; } S2F3068;
#if 0 /* merge_units */
extern S2F3068 *CreatePlayer(int c);
#endif /* merge_units */
#define CreatePlayer(a0) ((S2F3068 *)CreatePlayer((a0))) /* merge_units */

S2F3068 *CreatePlayerSpecific(int c, Blk2F3068 *key)
{
    S2F3068 *p = CreatePlayer(c);
    if (p) {
        p->key = *key;
        p->d = 0;
    }
    return p;
}
#undef CreatePlayer /* merge_units */
/* merge_units: end func_002F3068 */

/* merge_units: begin func_002F30E0 */
extern void DestroyRGBArray(int);
extern void DestroyVSequence(int);
extern int GetResourceManager(int);
extern void ReleaseSequencer(int, int);
extern void ReleaseCodec(int, int);
extern void rt_memory_free(void *);
void DestroyPlayer(char *s)
{
    if (s == 0) return;
    if (*(int *)(s + 0x840)) {
        DestroyRGBArray(*(int *)(s + 0x840));
        *(int *)(s + 0x840) = 0;
    }
    if (*(int *)(s + 0x844)) {
        DestroyVSequence(*(int *)(s + 0x844));
        *(int *)(s + 0x844) = 0;
    }
    if (*(int *)(s + 0x848)) {
        ReleaseSequencer(GetResourceManager(*(int *)(s + 8)), *(int *)(s + 0x848));
        *(int *)(s + 0x848) = 0;
    }
    if (*(int *)(s + 0x84C)) {
        ReleaseCodec(GetResourceManager(*(int *)(s + 8)), *(int *)(s + 0x84C));
        *(int *)(s + 0x84C) = 0;
    }
    rt_memory_free(&s);
}
/* merge_units: end func_002F30E0 */

/* merge_units: begin func_002F3198 */
extern char *GetGrid(int, int);
extern void GridRemovePlayer(char *, int);
extern void GridAddPlayer(char *, char *);
void SetPlayerCurChannel(char *s, int v)
{
    if (*(int *)(s + 0x30) == v) return;
    if (*(int *)(s + 0x30) > 0) GridRemovePlayer(GetGrid(*(int *)(s + 8), *(int *)(s + 0x30)), *(int *)(s + 0x34));
    *(int *)(s + 0x30) = v;
    if (v <= 0) return;
    GridAddPlayer(GetGrid(*(int *)(s + 8), v), s);
}
/* merge_units: end func_002F3198 */
