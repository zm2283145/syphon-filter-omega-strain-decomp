extern char D_00489400[];
extern int D_00488A80[];
extern int D_004878AC;
extern int func_00119010(int);
extern int func_00110528(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *endf, void *endp);
extern int func_0010D180(int);
#define UNCACHED(p) (*(int *)((unsigned int)(p) | 0x20000000))
typedef struct { unsigned char b[8]; } Clock9E60;
extern int D_00487890;
extern int func_0010F388(const char *, ...);

int sceCdReadClock(Clock9E60 *out)
{
    int r;
    if (!func_00119010(0xF)) return 0;
    if (D_00487890 > 0) func_0010F388("Libcdvd call Clock read 1
");
    if (func_00110528(D_00489400, 1, 0, 0, 0, D_00488A80, 0x10, 0, 0) < 0) {
        func_0010D180(D_004878AC);
        return 0;
    }
    *out = *(Clock9E60 *)((unsigned int)&D_00488A80[1] | 0x20000000);
    if (D_00487890 > 0) func_0010F388("Libcdvd call Clock read 2
");
    r = UNCACHED(D_00488A80);
    func_0010D180(D_004878AC);
    return r;
}