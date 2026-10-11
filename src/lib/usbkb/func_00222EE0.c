typedef struct { unsigned int max; char pad[0x8C]; int x90; int x94; void *x98; } KbState;
extern int D_0048AB18;
extern char D_004F5820[];
extern unsigned char D_004F5880[];
extern char D_004F58C0[];
extern KbState D_004F5780;
extern char D_004A4D80[];
extern int func_0010D1A0(int);
extern int func_0010F388(const char *, ...);
extern void func_00223400(void *);
extern int func_00110528(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *endf, void *endp);

int sceUsbKbRead(unsigned int port, void *data)
{
    KbState *st;
    int r;
    if (D_0048AB18 == -1) return -1;
    st = &D_004F5780;
    if (port >= (unsigned int)st->max) return -0xB;
    D_004F5880[0] = port;
    func_0010D1A0(D_0048AB18);
    r = func_00110528(D_004F5820, 2, 1, D_004F5880, 0x10, D_004F58C0, 0x50, func_00223400, 0);
    if (r != 0) {
        func_0010F388(D_004A4D80, r);
        return -2;
    }
    st->x98 = data;
    st->x94 = port;
    st->x90 = 2;
    return 0;
}
