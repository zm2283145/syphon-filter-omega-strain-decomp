typedef struct { unsigned char b[64]; } Blk64;
extern Blk64 D_004FBAC0;
extern Blk64 D_004FBB40;
extern void func_0010DA58(void *, void *);
extern int func_001161A0(void);
extern int func_001161F8(void);

int func_0026A8C8(int sock)
{
    func_0010DA58(&D_004FBAC0, (char *)&D_004FBAC0 + 0x80);
    func_001161A0();
    D_004FBB40 = D_004FBAC0;
    func_001161F8();
    return ((int *)&D_004FBB40)[sock] == 1 ? 1 : 3;
}