typedef char *va_list;
#define va_start(v,l) (v = (va_list)__builtin_next_arg(l) - 0x30)
typedef struct { int count; int max_count; int init_count; int wait_threads; unsigned int attr; unsigned int option; } Sema;
typedef struct { int sema; int *ret; int x8; int flags; int mode; char name[0x400]; int fd; } OpenPkt;
typedef struct { int x0; int flags; int x8; int xC; } Fd;
extern OpenPkt D_004E4800;
extern Fd D_004E5D00[];
extern char D_004E5F00[];
extern int D_004E5440[];
extern int D_0048623C;
extern int D_00486248;
extern int _sceFsWaitS(int);
extern void _sceFsSigSema(void);
extern void func_001112E0(void);
extern int _fs_version(void);
extern Fd *new_iob(void);
extern int CreateSema(Sema *);
extern int DeleteSema(int);
extern int WaitSema(int);
extern int SignalSema(int);
extern int sceSifCallRpc(void *, int, int, void *, int, void *, int, void *, void *);
int sceOpen(const char *name, int flags, ...)
{
    va_list ap;
    Sema sema;
    int ret;
    int mode;
    Fd *fd;
    int i;
    int sid;
    int idx;
    int ok;
    OpenPkt *p;

    p = &D_004E4800;
    va_start(ap, flags);
    _sceFsWaitS(0);
    if (D_0048623C == 0)
        func_001112E0();
    if (_fs_version()) {
        _sceFsSigSema();
        return 0xFFFEFFFC;
    }
    fd = new_iob();
    if (!fd) {
        _sceFsSigSema();
        return -19;
    }
    mode = *(int *)ap;
    for (i = 0; i < 0x400; i++) {
        if ((p->name[i] = name[i]) == 0)
            break;
    }
    if (i == 0x400)
        p->name[0x3FF] = 0;
    idx = fd - D_004E5D00;
    p->flags = flags & 0x7FFFFFFF;
    p->mode = mode;
    sema.max_count = 1;
    p->fd = idx;
    sema.init_count = 0;
    sema.option = 0;
    sid = CreateSema(&sema);
    p->ret = &ret;
    p->sema = sid;
    p->x8 = 4;
    if (sceSifCallRpc(D_004E5F00, 0, 0, &D_004E4800, 0x418, D_004E5440, 4, 0, 0) < 0) {
        DeleteSema(sid);
        _sceFsSigSema();
        return -11;
    }
    ok = *(int *)((int)D_004E5440 | 0x20000000);
    _sceFsSigSema();
    if (!ok) {
        DeleteSema(sid);
        return -11;
    }
    WaitSema(sid);
    DeleteSema(sid);
    if (ret < 0) {
        WaitSema(D_00486248);
        fd->flags = 0;
        SignalSema(D_00486248);
        return ret;
    }
    ok = idx;
    WaitSema(D_00486248);
    fd->x0 = ret;
    fd->flags |= flags;
    SignalSema(D_00486248);
    return ok;
}