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
extern int func_001111B0(int);
extern void func_001111E0(void);
extern void func_001112E0(void);
extern int func_001114E8(void);
extern Fd *func_00110CB0(void);
extern int CreateSema(Sema *);
extern int func_0010D170(int);
extern int func_0010D1A0(int);
extern int func_0010D180(int);
extern int func_00110528(void *, int, int, void *, int, void *, int, void *, void *);
int func_001115B0(const char *name, int flags, ...)
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
    func_001111B0(0);
    if (D_0048623C == 0)
        func_001112E0();
    if (func_001114E8()) {
        func_001111E0();
        return 0xFFFEFFFC;
    }
    fd = func_00110CB0();
    if (!fd) {
        func_001111E0();
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
    if (func_00110528(D_004E5F00, 0, 0, &D_004E4800, 0x418, D_004E5440, 4, 0, 0) < 0) {
        func_0010D170(sid);
        func_001111E0();
        return -11;
    }
    ok = *(int *)((int)D_004E5440 | 0x20000000);
    func_001111E0();
    if (!ok) {
        func_0010D170(sid);
        return -11;
    }
    func_0010D1A0(sid);
    func_0010D170(sid);
    if (ret < 0) {
        func_0010D1A0(D_00486248);
        fd->flags = 0;
        func_0010D180(D_00486248);
        return ret;
    }
    ok = idx;
    func_0010D1A0(D_00486248);
    fd->x0 = ret;
    fd->flags |= flags;
    func_0010D180(D_00486248);
    return ok;
}