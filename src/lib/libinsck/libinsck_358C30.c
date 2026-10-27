/*
 * lib/libinsck: 3 files, 00358C30-00358E60
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00358C30 */
typedef struct N81E0 { struct N81E0 *next; struct N81E0 *prev; int tid; int err; int x10; char x14[0x3C]; void *x50; } N81E0;
extern N81E0 *D_00492CD0;
extern N81E0 *D_00492CD4;
extern int D_00492CCC;
extern int D_00492CC8;
extern void sceLibnetTerminate(void *);
extern void my_free(void *);
extern int unblock(void);
extern int func_00358158(void);
extern int GetThreadId(void);
extern int DeleteSema(int);
extern void thread_terminate(N81E0 *);

int sceInsockTerminate(int tid)
{
    N81E0 *n;
    if (tid == 0) tid = GetThreadId();
    if (func_00358158() < 0) return -1;
    if (tid == -1) {
        while ((n = D_00492CD0) != 0) thread_terminate(n);
    } else {
        for (n = D_00492CD0; n; n = n->next) {
            if (tid == n->tid) {
                thread_terminate(n);
                break;
            }
        }
    }
    if (D_00492CCC <= 0) {
        DeleteSema(D_00492CC8);
        D_00492CC8 = -1;
        return 0;
    }
    unblock();
    return 0;
}
/* merge_units: end func_00358C30 */

/* merge_units: begin func_00358D18 */
typedef struct S8D18 { struct S8D18 *next; struct S8D18 *prev; int id; int xC; int type; char pad[0x4C]; int x60; int x64; int x68; } S8D18;
extern void *thread_enter(int);
extern int thread_leave(void *, int);
extern int unused_socket_id(void);
extern void *my_malloc(int);
extern void *memset(void *, int, unsigned int);
extern S8D18 *D_00492CD8;
S8D18 *D_00492CDC = 0;

int sceInsockSocket(int domain, int type)
{
    void *lk = thread_enter(0);
    int id;
    S8D18 *s;
    if (!lk) return -1;
    if (domain != 2) return thread_leave(lk, 0x60);
    id = unused_socket_id();
    switch (type) {
    case 2:
        type = 0;
        break;
    case 1:
    case 3:
        break;
    default:
        return thread_leave(lk, 0x6B);
    }
    s = my_malloc(0x6C);
    if (!s) return thread_leave(lk, 0xC);
    memset(s, 0, 0x6C);
    s->type = type;
    s->id = id;
    s->x60 = -1;
    s->x64 = -1;
    s->x68 = -1;
    s->next = D_00492CD8;
    if (D_00492CD8) D_00492CD8->prev = s;
    else D_00492CDC = s;
    D_00492CD8 = s;
    s->prev = 0;
    thread_leave(lk, 0);
    return id;
}
/* merge_units: end func_00358D18 */

/* merge_units: begin func_00358E60 */
typedef struct N8E60 { struct N8E60 *next; int x4; int x8; int xC; int x10; int port; } N8E60;
typedef struct { unsigned char len; unsigned char family; unsigned short port; } Addr8E60;
extern N8E60 *socket_info(int);
extern int conv_port_to_inet(int);
#if 0 /* merge_units */
extern N8E60 *D_00492CD8;
#endif /* merge_units */
#define D_00492CD8 (*(N8E60 **)&D_00492CD8) /* merge_units */


int sceInsockBind(int s, Addr8E60 *a, int len)
{
    void *lk = thread_enter(0);
    N8E60 *n, *p;
    int port;
    if (!lk) return -1;
    n = socket_info(s);
    if (!n) return thread_leave(lk, 9);
    if (len != 16) return thread_leave(lk, 0x16);
    if (a->family != 2) return thread_leave(lk, 0x6A);
    port = conv_port_to_inet(a->port);
    for (p = D_00492CD8; p; p = p->next) {
        if (port == p->port) return thread_leave(lk, 0x70);
    }
    n->port = port;
    return thread_leave(lk, 0);
}
#undef D_00492CD8 /* merge_units */
/* merge_units: end func_00358E60 */
