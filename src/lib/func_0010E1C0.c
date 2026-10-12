typedef struct { int count; int max_count; int init_count; int wait_threads; unsigned int attr; void *option; } SemaParamE1C0;
extern char D_00498918[];
extern int CreateSema(SemaParamE1C0 *);
extern int func_00117C68(int, int);
extern int func_00117E18(int, int (*)(int, int, int, int), int);
extern int func_0010E288(int, int, int, int);
extern int func_0010D170(int);
extern int func_0010D1A0(int);
int func_0010E1C0(int a)
{
    SemaParamE1C0 sp;
    int s, sema, r;
    __asm__ volatile("mfc0 %0, $12" : "=r"(s));
    if (!(s & 0x10000)) return 0x80008008;
    sp.max_count = 1;
    sp.option = D_00498918;
    sp.init_count = 0;
    sema = CreateSema(&sp);
    if (sema < 0) return 0x80008003;
    r = func_00117E18(func_00117C68(0, a), func_0010E288, sema);
    if (r < 0) {
        func_0010D170(sema);
        return r;
    }
    func_0010D1A0(sema);
    func_0010D170(sema);
    return 0;
}
