/*
 * lib/libkernl: 7 files, 00117D68-00118158
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00117D68 */
typedef struct N7D68 { struct N7D68 *next; int p[3]; } N7D68;
extern N7D68 D_004E96C0[];
extern N7D68 *D_004E9AC0;

int _InitAlarm(void)
{
    int i;
    D_004E9AC0 = D_004E96C0;
    for (i = 0x3F; i >= 0; i--) D_004E96C0[i].next = &D_004E96C0[i + 1];
    D_004E96C0[0x3F].next = 0;
    return 0;
}
/* merge_units: end func_00117D68 */

/* merge_units: begin func_00117DB8 */
typedef struct N7DB8 {
    struct N7DB8 *next;
    volatile int id;
    int (*func)(int, int, int, void *);
    void *arg;
} N7DB8;

#if 0 /* merge_units */
extern N7DB8 *volatile D_004E9AC0;
#endif /* merge_units */
#define D_004E9AC0 (*(N7DB8 * volatile*)&D_004E9AC0) /* merge_units */


int AlarmHandler(int id, int b, int c, N7DB8 *n)
{
    int ret = n->func(((int)n << 4) | (id & 0xFE) | 1, b, c, n->arg);
    if (ret == 0) {
        n->next = D_004E9AC0;
        D_004E9AC0 = n;
        n->id = 0;
        return -1;
    }
    return ret;
}
#undef D_004E9AC0 /* merge_units */
/* merge_units: end func_00117DB8 */

/* merge_units: begin func_00117E18 */
typedef struct N7E18 { struct N7E18 *next; volatile int id; void *func; void *arg; } N7E18;
#if 0 /* merge_units */
extern N7E18 *volatile D_004E9AC0;
#endif /* merge_units */
#define D_004E9AC0 (*(N7E18 * volatile*)&D_004E9AC0) /* merge_units */

extern int DIntr(void);
extern void EIntr(void);
extern int AlarmHandler();
static inline N7E18 *node_alloc(void) { N7E18 *n = D_004E9AC0; if (n) D_004E9AC0 = n->next; return n; }
extern int AllocTimerCounter(void);
extern int SetTimerHandler(int, long, void *, void *);
extern int StartTimerCounter(int);

int SetTimerAlarm(long t, void *h, void *arg)
{
    int s, id;
    N7E18 *n;
    if (h == 0) return 0x80000016;
    s = DIntr();
    n = node_alloc();
    if (n == 0) {
        if (s) EIntr();
        return 0x80008005;
    }
    id = AllocTimerCounter();
    if (id < 0) {
        n->next = D_004E9AC0;
        D_004E9AC0 = n;
        n->id = 0;
        if (s) EIntr();
        return id;
    }
    n->func = h;
    n->arg = arg;
    n->id = id;
    SetTimerHandler(id, t, AlarmHandler, n);
    StartTimerCounter(id);
    if (s) EIntr();
    return ((int)n << 4) | (id & 0xFE) | 1;
}
#undef D_004E9AC0 /* merge_units */
/* merge_units: end func_00117E18 */

/* merge_units: begin func_00117F48 */
#if 0 /* merge_units */
extern N7E18 *volatile D_004E9AC0;
#endif /* merge_units */
#define D_004E9AC0 (*(N7E18 * volatile*)&D_004E9AC0) /* merge_units */

extern int iAllocTimerCounter(void);
extern int iSetTimerHandler(int, long, void *, void *);
extern int iStartTimerCounter(int);

int iSetTimerAlarm(long t, void *h, void *arg)
{
    int id;
    N7E18 *n;
    if (h == 0) return 0x80000016;
    n = node_alloc();
    if (n == 0) return 0x80008005;
    id = iAllocTimerCounter();
    if (id < 0) {
        n->next = D_004E9AC0;
        D_004E9AC0 = n;
        n->id = 0;
        return id;
    }
    n->func = h;
    n->arg = arg;
    n->id = id;
    iSetTimerHandler(id, t, AlarmHandler, n);
    iStartTimerCounter(id);
    return ((int)n << 4) | (id & 0xFE) | 1;
}
#undef D_004E9AC0 /* merge_units */
/* merge_units: end func_00117F48 */

/* merge_units: begin func_00118038 */
#if 0 /* merge_units */
extern N7E18 *volatile D_004E9AC0;
#endif /* merge_units */
#define D_004E9AC0 (*(N7E18 * volatile*)&D_004E9AC0) /* merge_units */

extern int FreeTimerCounter(int);

int ReleaseTimerAlarm(int id)
{
    N7E18 *n = (N7E18 *)(((unsigned int)id >> 8) << 4);
    int s = DIntr();
    if (id < 0 || ((id ^ n->id) & 0xFF)) {
        if (s) EIntr();
        return 0x80008002;
    }
    FreeTimerCounter(n->id);
    n->next = D_004E9AC0;
    D_004E9AC0 = n;
    n->id = 0;
    if (s) EIntr();
    return 0;
}
#undef D_004E9AC0 /* merge_units */
/* merge_units: end func_00118038 */

/* merge_units: begin func_001180E0 */
#if 0 /* merge_units */
extern N7E18 *volatile D_004E9AC0;
#endif /* merge_units */
#define D_004E9AC0 (*(N7E18 * volatile*)&D_004E9AC0) /* merge_units */

extern int iFreeTimerCounter(int);

int iReleaseTimerAlarm(int id)
{
    N7E18 *n = (N7E18 *)(((unsigned int)id >> 8) << 4);
    int r;
    if (id < 0 || ((id ^ n->id) & 0xFF)) return 0x80008002;
    r = iFreeTimerCounter(n->id);
    if (r == 0) {
        n->next = D_004E9AC0;
        D_004E9AC0 = n;
        n->id = 0;
    }
    return r;
}
#undef D_004E9AC0 /* merge_units */
/* merge_units: end func_001180E0 */

/* merge_units: begin func_00118158 */
int D_00487868 = 0;
int D_0048786C = 0;
extern char D_004E9AC8[];
extern void* memset(void* p, int c, unsigned int n);
void sceSifInitRebootNotify(void)
{
    D_00487868 = 0;
    D_0048786C = 0;
    memset(D_004E9AC8, 0, 0x200);
}
/* merge_units: end func_00118158 */
