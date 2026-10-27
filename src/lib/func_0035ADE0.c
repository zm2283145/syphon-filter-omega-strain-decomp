typedef struct { char pad[0x14]; char x14[0x40]; int x54; } SADE0;
extern SADE0 *thread_enter(int);
extern void unblock(void);
extern void sceInetAbort(void *, int, int, int);
extern int func_00358158(void);
extern int thread_leave(SADE0 *, int);
int sceInsockAbortGethostbyname(void)
{
    SADE0 *s = thread_enter(0);
    int e;
    if (s == 0) return -1;
    unblock();
    sceInetAbort(s->x14, s->x54, 0, 0x52534C56);
    if (func_00358158() < 0) return thread_leave(s, -1);
    return thread_leave(s, 0);
}