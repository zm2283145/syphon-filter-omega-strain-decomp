/*
 * lib/medius: 5 files, 002F3C00-002F4180
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002F3C00 */
typedef struct S {
    void *h;
    int max;
    int cnt;
    char pad0C[0x14];
    int busy;
    char pad24[0x8];
    void *cur;
} S;
extern int GetCodecType(void *p);
extern void DestroyCodec(void *p);
extern void *CreateCodec(void *h, int id, int n);
extern int InitCodec(void *p);
void *RequestEncoder(S *s, int id, int lim)
{
    void *p;
    if (s->busy) return 0;
    if (s->cnt >= s->max && s->max + 1 < lim) return 0;
    if (s->cur && GetCodecType(s->cur) != id) {
        DestroyCodec(s->cur);
        s->cur = 0;
    }
    if (s->cur == 0) {
        s->cur = CreateCodec(s->h, id, 1);
    }
    p = s->cur;
    if (p) {
        InitCodec(p);
        s->busy = 1;
    }
    return p;
}
/* merge_units: end func_002F3C00 */

/* merge_units: begin func_002F3CD0 */
typedef struct N2F3CD0 { struct N2F3CD0 *next; struct N2F3CD0 *prev; int a; int val; } N2F3CD0;
typedef struct { int owner; int max; char pad8[0x10]; int used; int nfree; int pad20; N2F3CD0 *used_l; N2F3CD0 *free_l; } P2F3CD0;
extern int rt_memory_allocate_init_zero(void *, int);
#if 0 /* merge_units */
extern int CreateCodec(int, int, int);
#endif /* merge_units */
#define CreateCodec(a0, a1, a2) ((int)CreateCodec((void *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern void DestroyCodec(int);
#endif /* merge_units */
#define DestroyCodec(a0) (DestroyCodec((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int InitCodec(int);
#endif /* merge_units */
#define InitCodec(a0) (InitCodec((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int GetCodecType(int);
#endif /* merge_units */
#define GetCodecType(a0) (GetCodecType((void *)(a0))) /* merge_units */

extern void rt_memory_free(void *);
int RequestDecoder(P2F3CD0 *q, int key)
{
    N2F3CD0 *n;
    int r = 0;
    n = q->free_l;
    while (n) {
        if (GetCodecType(n->val) == key)
            break;
        n = n->prev;
        if (n == q->free_l)
            n = 0;
    }
    if (n) {
        n->prev->next = n->next;
        n->next->prev = n->prev;
        if (--q->nfree <= 0)
            q->free_l = 0;
        else if (q->free_l == n)
            q->free_l = n->prev;
    } else {
        while (q->nfree > 0 && q->used + q->nfree >= q->max) {
            N2F3CD0 *e = q->free_l->next;
            q->nfree--;
            e->next->prev = e->prev;
            e->prev->next = e->next;
            if (q->nfree <= 0)
                q->free_l = 0;
            DestroyCodec(e->val);
            rt_memory_free(&e);
        }
        if (q->used < q->max) {
            rt_memory_allocate_init_zero(&n, 0x10);
            if (n != 0) {
                n->val = CreateCodec(q->owner, key, 2);
                if (n->val == 0)
                    rt_memory_free(&n);
            }
        }
    }
    if (n != 0) {
        if (q->used_l == 0) {
            n->next = n->prev = n;
            q->used_l = n;
        } else {
            n->prev = q->used_l;
            n->next = q->used_l->next;
            n->prev->next = n;
            n->next->prev = n;
        }
        r = n->val;
        q->used++;
        InitCodec(r);
    }
    return r;
}
#undef CreateCodec /* merge_units */
#undef DestroyCodec /* merge_units */
#undef InitCodec /* merge_units */
#undef GetCodecType /* merge_units */
/* merge_units: end func_002F3CD0 */

/* merge_units: begin func_002F3F00 */
typedef struct N2F3F00 { struct N2F3F00 *next; struct N2F3F00 *prev; int a; int val; } N2F3F00;
typedef struct { int owner; int max; char pad8[0x10]; int used; int nfree; int busy; N2F3F00 *used_l; N2F3F00 *free_l; int cur; } P2F3F00;
extern int GetCodecMode(int);
void ReleaseCodec(P2F3F00 *q, int val)
{
    N2F3F00 *n, *head;
    if (val == 0) return;
    if (GetCodecMode(val) == 1) {
        if (val == q->cur) q->busy = 0;
        return;
    }
    n = q->used_l;
    if (n && n->val != val) {
        head = n;
        do { n = n->prev; if (n == head) n = 0; } while (n && n->val != val);
    }
    if (n == 0) return;
    n->prev->next = n->next;
    n->next->prev = n->prev;
    if (--q->used <= 0)
        q->used_l = 0;
    else if (n == q->used_l)
        q->used_l = n->prev;
    if (q->free_l == 0) {
        n->next = n->prev = n;
        q->free_l = n;
    } else {
        n->prev = q->free_l;
        n->next = q->free_l->next;
        n->prev->next = n;
        n->next->prev = n;
    }
    q->nfree++;
}
/* merge_units: end func_002F3F00 */

/* merge_units: begin func_002F4030 */
typedef struct N2F4030 { struct N2F4030 *next; struct N2F4030 *prev; int a; int val; } N2F4030;
typedef struct { int a; int max; int used; int nfree; N2F4030 *used_l; N2F4030 *free_l; } P2F4030;
extern int CreateSequence(void);
extern void InitSequence(int);
int RequestSequencer(P2F4030 *q)
{
    N2F4030 *n = 0;
    int r = 0;
    if (q->free_l == 0) {
        if (q->used < q->max) {
            rt_memory_allocate_init_zero(&n, 0x10);
            if (n != 0) {
                n->val = CreateSequence();
                if (n->val == 0) {
                    rt_memory_free(&n);
                    n = 0;
                }
            }
        }
    } else {
        n = q->free_l->next;
        if (n == q->free_l) q->free_l = 0;
        else {
            q->free_l->next = n->next;
            q->free_l->next->prev = q->free_l;
        }
        q->nfree--;
    }
    if (n != 0) {
    if (q->used_l == 0) {
        n->next = n->prev = n;
        q->used_l = n;
    } else {
        n->prev = q->used_l;
        n->next = q->used_l->next;
        n->prev->next = n;
        n->next->prev = n;
    }
    r = n->val;
    q->used++;
    InitSequence(r);
    }
    return r;
}
/* merge_units: end func_002F4030 */

/* merge_units: begin func_002F4180 */
typedef struct Node_002F4180 {
    struct Node_002F4180 *prev;
    struct Node_002F4180 *next;
    int unk8;
    int key;
} Node_002F4180;

typedef struct {
    int unk0;
    int unk4;
    int count;
    int freeCount;
    Node_002F4180 *head;
    Node_002F4180 *freeList;
} List_002F4180;

void ReleaseSequencer(List_002F4180 *l, int key)
{
    Node_002F4180 *n;
    Node_002F4180 *f;
    n = l->head;
    if (key == 0 || n == 0) return;
    if (n->key != key) {
        Node_002F4180 *first = n;
        do {
            n = n->next;
            n = (n == first) ? 0 : n;
            if (n == 0) return;
        } while (n->key != key);
    }
    if (n == 0) return;
    n->next->prev = n->prev;
    n->prev->next = n->next;
    if (n == l->head)
        l->head = (n == n->next) ? 0 : n->next;
    l->count--;
    f = l->freeList; if (f == 0) {
        n->next = n;
        n->prev = n;
        l->freeList = n;
    } else {
        n->next = f; n->prev = l->freeList->prev; f->prev = n;
        n->prev->next = n;
    }
    l->freeCount++;
}
/* merge_units: end func_002F4180 */
