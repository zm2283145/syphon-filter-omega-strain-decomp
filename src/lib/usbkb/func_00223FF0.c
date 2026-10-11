typedef struct { int f0; int f4; int f8; int mode; int f10; int f14; int f18; int f1c; unsigned short s20; unsigned short buf[4]; char pad2[2]; int wr; int rd; int count; } E223FF0;
typedef struct { unsigned int count; E223FF0* tbl; } G223FF0;
extern G223FF0 D_004F5780;
extern int D_0048AB18;
extern unsigned char D_004F5880[];
extern char D_004F5820[];
extern char D_004F58C0[];
extern char D_004A4D80[];
extern void func_00223400(void* p);
extern void func_0010D1A0(int s);
extern int func_00110528(void* cd, int fno, int mode, void* send, int ssize, void* recv, int rsize, void (*end)(void*), void* param);
extern int func_0010F388(char* fmt, ...);
int func_00223FF0(unsigned int port)
{
    E223FF0* e;
    int r;
    if (D_0048AB18 == -1) return -1;
    if (port >= D_004F5780.count) return -11;
    D_004F5880[0] = port;
    func_0010D1A0(D_0048AB18);
    r = func_00110528(D_004F5820, 6, 1, D_004F5880, 0x10, D_004F58C0, 0, func_00223400, 0);
    if (r != 0) {
        func_0010F388(D_004A4D80, r);
        return -2;
    }
    e = &D_004F5780.tbl[port];
    e->f10 = 0;
    e->f14 = 0;
    e->s20 = 0;
    e->wr = 0;
    e->rd = 0;
    e->count = 0;
    return 0;
}