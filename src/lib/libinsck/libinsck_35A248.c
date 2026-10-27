typedef struct { char pad[0x14]; char x14[0x40]; int x54; } SA248;
typedef struct { char pad[0xC]; int xC; } TA248;
extern SA248 *thread_enter(int);
extern TA248 *socket_info(int);
extern void unblock(void);
extern int sceInetControl(void *, int, int, int, void *, int);
extern int func_00358158(void);
extern int conv_errno(int);
extern int thread_leave(SA248 *, int);
int sceInsockSendFin(int a, int b)
{
    int v[1];
    SA248 *s;
    TA248 *t;
    int r;
    v[0] = b;
    s = thread_enter(0);
    if (s == 0) return -1;
    t = socket_info(a);
    if (t == 0) return thread_leave(s, 9);
    unblock();
    r = sceInetControl(s->x14, s->x54, t->xC, 0x10, v, 4);
    if (func_00358158() < 0) return thread_leave(s, -1);
    if (r >= 0) return thread_leave(s, 0);
    return thread_leave(s, conv_errno(r));
}