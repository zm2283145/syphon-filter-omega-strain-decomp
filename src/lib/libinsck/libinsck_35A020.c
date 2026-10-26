#define F(p,o,T) (*(T *)((char *)(p)+(o)))
typedef struct { int fd; short events; short revents; } PollFd;
extern void *Insck_GetThreadContext(int), *Insck_FindSocket(int);
extern void unblock(void);
extern int func_00358158(void), Insck_SetErrno(void *, int), Insck_MapLibnetError(int), connect_check(void *, void *);
extern void *my_malloc(int);
extern void my_free(void *);
extern int sceInetPoll(void *, int, PollFd *, int, int);

int Insck_Poll(PollFd *fds, int nfds, int timeout)
{
    void *ctx, *sock;
    int *save;
    PollFd *p;
    int i, r, id;
    ctx = Insck_GetThreadContext(0);
    if (!ctx) return -1;
    if (fds == 0 || nfds <= 0) return Insck_SetErrno(ctx, 0x16);
    save = my_malloc(nfds * 4);
    if (!save) return Insck_SetErrno(ctx, 0xC);
    for (i = 0; i < nfds; i++) save[i] = fds[i].fd;
    p = fds;
    for (i = 0; i < nfds; i++, p++) {
        sock = Insck_FindSocket(p->fd);
        if (!sock) {
            p->fd = 0;
            continue;
        }
        if (F(sock,16,int) == 2 && F(sock,0x50,void *)) {
            id = F(F(sock,0x50,void *),12,int);
        } else {
            if (connect_check(ctx, sock)) {
                p->fd = 0;
                continue;
            }
            id = F(sock,12,int);
        }
        p->fd = id;
    }
    unblock();
    r = sceInetPoll((char *)ctx + 0x14, F(ctx,0x54,int), fds, nfds, timeout);
    if (func_00358158() < 0) {
        my_free(save);
        return Insck_SetErrno(ctx, -1);
    }
    for (i = 0; i < nfds; i++) fds[i].fd = save[i];
    my_free(save);
    if (r < 0) return Insck_SetErrno(ctx, Insck_MapLibnetError(r));
    Insck_SetErrno(ctx, 0);
    return r;
}

