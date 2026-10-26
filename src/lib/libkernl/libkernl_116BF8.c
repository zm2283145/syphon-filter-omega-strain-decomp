typedef struct { long long a; int id; int pad; volatile int cnt; void *buf; } TimCtl;
typedef struct TimBlk { struct TimBlk *next; char pad[0x3C]; } TimBlk;
extern TimCtl D_00487848;
extern TimBlk D_004E76C0[];
extern void *memset(void *, int, unsigned int);
extern void _InitAlarm(void);
extern void cbTimerHandler(void);
extern int AddIntcHandler2(int, void *, int, int);
extern int RemoveIntcHandler(int, int);
extern int DIntr(void);
extern void EIntr(void);
extern void SetT2_COUNT(int);
extern void SetT2_MODE(unsigned int);
extern void SetT2_COMP(int);
extern int Alloc_Lock(int);
extern int Alloc_Unlock(int);
int EndTimer(void)
{
    int s;
    if (D_00487848.id < 0) return 0x80008001;
    if (D_00487848.cnt != 0) return 0x80000010;
    s = DIntr();
    if (RemoveIntcHandler(11, D_00487848.id) == 0) {
        Alloc_Lock(11);
        SetT2_MODE(0xC00);
        SetT2_COUNT(0);
    }
    D_00487848.a = 0;
    D_00487848.id = -1;
    if (s) EIntr();
    return 0;
}