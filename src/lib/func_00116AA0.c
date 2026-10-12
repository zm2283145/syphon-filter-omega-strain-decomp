typedef struct { long long a; int id; int pad; int cnt; void *buf; } TimCtl;
typedef struct TimBlk { struct TimBlk *next; char pad[0x3C]; } TimBlk;
unsigned int D_00487848[2] = { 0x0, 0x0 };
extern TimBlk D_004E76C0[];
extern void *memset(void *, int, unsigned int);
extern void func_00117D68(void);
extern void func_00117040(void);
extern int func_0010CE50(int, void *, int, int);
extern int func_0010CE60(int, int);
extern int func_001161A0(void);
extern void func_001161F8(void);
extern void func_00116A70(int);
extern void func_00116A80(unsigned int);
extern void func_00116A90(int);
extern int Alloc_Lock(int);
extern int Alloc_Unlock(int);
int func_00116AA0(unsigned int mode)
{
    int i, id, s;
    unsigned int v;
    if ((*(TimCtl*)D_00487848).id >= 0) return 0x80008001;
    (*(TimCtl*)D_00487848).a = 0;
    (*(TimCtl*)D_00487848).cnt = 0;
    memset(D_004E76C0, 0, 0x2000);
    (*(TimCtl*)D_00487848).buf = D_004E76C0;
    for (i = 0x7F; i >= 0; i--) D_004E76C0[i].next = &D_004E76C0[i + 1];
    D_004E76C0[0x7F].next = 0;
    func_00117D68();
    id = func_0010CE50(11, func_00117040, 0, 0);
    if (id < 0) return 0x80009021;
    (*(TimCtl*)D_00487848).id = id;
    s = func_001161A0();
    v = *(volatile unsigned int *)0x10001010;
    v = (v & ~3) | mode;
    v |= 0x300;
    if (!(v & 0x80)) {
        func_00116A70(0);
        v |= 0xC80;
        func_00116A90(0xFFFF);
    }
    func_00116A80(v);
    Alloc_Unlock(11);
    if (s) func_001161F8();
    return 0;
}