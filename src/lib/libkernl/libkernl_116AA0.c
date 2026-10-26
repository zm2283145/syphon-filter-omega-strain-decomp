typedef struct { long long a; int id; int pad; int cnt; void *buf; } TimCtl;
typedef struct TimBlk { struct TimBlk *next; char pad[0x3C]; } TimBlk;
unsigned int D_00487848[2] = { 0x0, 0x0 };
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
int InitTimer(unsigned int mode)
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
    _InitAlarm();
    id = AddIntcHandler2(11, cbTimerHandler, 0, 0);
    if (id < 0) return 0x80009021;
    (*(TimCtl*)D_00487848).id = id;
    s = DIntr();
    v = *(volatile unsigned int *)0x10001010;
    v = (v & ~3) | mode;
    v |= 0x300;
    if (!(v & 0x80)) {
        SetT2_COUNT(0);
        v |= 0xC80;
        SetT2_COMP(0xFFFF);
    }
    SetT2_MODE(v);
    Alloc_Unlock(11);
    if (s) EIntr();
    return 0;
}