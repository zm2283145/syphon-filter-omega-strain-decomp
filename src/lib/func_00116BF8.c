typedef struct { long long a; int id; int pad; volatile int cnt; void *buf; } TimCtl;
typedef struct TimBlk { struct TimBlk *next; char pad[0x3C]; } TimBlk;
extern TimCtl D_00487848;
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
int func_00116BF8(void)
{
    int s;
    if (D_00487848.id < 0) return 0x80008001;
    if (D_00487848.cnt != 0) return 0x80000010;
    s = func_001161A0();
    if (func_0010CE60(11, D_00487848.id) == 0) {
        Alloc_Lock(11);
        func_00116A80(0xC00);
        func_00116A70(0);
    }
    D_00487848.a = 0;
    D_00487848.id = -1;
    if (s) func_001161F8();
    return 0;
}