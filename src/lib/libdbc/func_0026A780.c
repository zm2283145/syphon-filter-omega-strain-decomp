extern char D_004F85C8[];
extern int D_004F8640[];
extern int func_00110528(void *cd, unsigned int fno, int mode, void *send, int ssize, void *recv, int rsize, void *endf, void *endp);
extern int func_0026B1C8(const char *, ...);
typedef struct { unsigned char b[64]; } Blk64;
extern Blk64 D_004FBAC0;
extern Blk64 D_004FBB40;
extern char D_004A8600[];
extern void func_0010DA58(void *, void *);
extern int func_001161A0(void);
extern int func_001161F8(void);

int sceDbcGetDepNumber(int sock)
{
    func_0010DA58(&D_004FBAC0, (char *)&D_004FBAC0 + 0x80);
    func_001161A0();
    D_004FBB40 = D_004FBAC0;
    func_001161F8();
    if (((int *)&D_004FBB40)[sock] != 1) return -12;
    D_004F8640[0] = sock;
    if (func_00110528(D_004F85C8, 0x80001303, 0, D_004F8640, 0x280, D_004F8640, 0x280, 0, 0) < 0) {
        func_0026B1C8(D_004A8600);
        return 0;
    }
    return D_004F8640[1];
}