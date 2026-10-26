/*
 * lib/medius: 4 files, 002F9368-002F95F8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002F9368 */
extern int IsNullRSAKey(char *);
extern int GetKeyMaster(int);
extern char *GetKeyChain(int, int);
extern int IsNullRCKey(int);
extern void Sha1_Digest(int, int, int *, int);
extern void RSAEncrypt(char *, int, int *, int);
int KM_DigiVerify(int a, int b, char *c, int d)
{
    int buf[16];
    int buf2[16];
    int h;
    char *s;
    unsigned int i;
    if (d == 0) goto fail;
    if (IsNullRSAKey(c)) return -1;
    h = GetKeyMaster(a);
    if (h == 0) return -1;
    s = GetKeyChain(h, b);
    if (s == 0) return -1;
    if (IsNullRCKey(*(int *)(s + 0x18))) {
fail:
        return -1;
    }
    Sha1_Digest(*(int *)(s + 0x18), 4, buf, 0x40);
    RSAEncrypt(c, d, buf2, 0x40);
    i = 0;
    do {
        if (buf[i] != buf2[i]) goto fail;
    } while (++i < 16);
    return 0;
}
/* merge_units: end func_002F9368 */

/* merge_units: begin func_002F9460 */
#if 0 /* merge_units */
extern int GetKeyChain(int, int);
#endif /* merge_units */
#define GetKeyChain(a0, a1) ((int)GetKeyChain((a0), (a1))) /* merge_units */

extern void RemoveKeyChain(int, int);
extern void DeleteKeyChain(int);
void KM_DeleteKeys(int a, int b)
{
    int l = GetKeyMaster(a);
    int n = GetKeyChain(l, b);
    if (n) {
        RemoveKeyChain(l, n);
        DeleteKeyChain(n);
    }
}
#undef GetKeyChain /* merge_units */
/* merge_units: end func_002F9460 */

/* merge_units: begin func_002F94D0 */
typedef struct L2F94D0 { struct L2F94D0 *next; struct L2F94D0 *prev; int a, sub; int b, c, d; void *h1C, *h20, *h24, *h28, *h2C; } L2F94D0;
extern L2F94D0 *D_004908D8;
#if 0 /* merge_units */
extern L2F94D0 *GetKeyMaster(int);
#endif /* merge_units */
#define GetKeyMaster(a0) ((L2F94D0 *)GetKeyMaster((a0))) /* merge_units */

#if 0 /* merge_units */
extern void RemoveKeyChain(L2F94D0 *, int);
#endif /* merge_units */
#define RemoveKeyChain(a0, a1) (RemoveKeyChain((int)(a0), (a1))) /* merge_units */

extern void rt_memory_free(void *);
void KM_Destroy(int id)
{
    L2F94D0 *p;
    int s;
    p = GetKeyMaster(id);
    if (p == 0) return;
    while ((s = p->sub) != 0) {
        RemoveKeyChain(p, s);
        DeleteKeyChain(s);
    }
    if (p->h20) rt_memory_free(&p->h20);
    if (p->h1C) rt_memory_free(&p->h1C);
    if (p->h2C) rt_memory_free(&p->h2C);
    if (p->h24) rt_memory_free(&p->h24);
    if (p->h28) rt_memory_free(&p->h28);
    if (D_004908D8 == p) D_004908D8 = p->prev;
    p->prev->next = p->next;
    p->next->prev = p->prev;
    if (D_004908D8 == p) D_004908D8 = 0;
    rt_memory_free(&p);
}
#undef GetKeyMaster /* merge_units */
#undef RemoveKeyChain /* merge_units */
/* merge_units: end func_002F94D0 */

/* merge_units: begin func_002F95F8 */
typedef struct N2F95F8 { int x0; struct N2F95F8 *next; int p8, pC; int key; } N2F95F8;
#if 0 /* merge_units */
extern N2F95F8 *D_004908D8;
#endif /* merge_units */
#define D_004908D8 (*(N2F95F8 **)&D_004908D8) /* merge_units */

#if 0 /* merge_units */
extern void KM_Destroy(int);
#endif /* merge_units */
#define KM_Destroy(a0) (KM_Destroy((a0))) /* merge_units */

void KM_Cleanup(int key)
{
    N2F95F8 *n = D_004908D8;
    int k;
    if (n == 0) return;
    do {
        k = n->key;
        if ((key == -1 && k == key) || (key == (int)0x80000000 && k == (k & 0x7FFFFFFF) + key) || (key == 0 && k == (k & 0x7FFFFFFF))) {
            KM_Destroy(k);
            n = D_004908D8;
        } else {
            n = n->next;
            if (n == D_004908D8) n = 0;
        }
    } while (n);
}
#undef D_004908D8 /* merge_units */
#undef KM_Destroy /* merge_units */
/* merge_units: end func_002F95F8 */
