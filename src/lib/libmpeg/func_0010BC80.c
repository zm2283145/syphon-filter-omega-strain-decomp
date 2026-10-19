#define R(a) (*(volatile unsigned int*)(a))
typedef struct { char pad[0x1C8]; int x1C8; char pad2[0x830-0x1CC]; int x830; } O_0010BC80;
extern int DIntr(void);
extern void EIntr(void);
extern void func_0010CA10(int a, int b);
void func_0010BC80(O_0010BC80* o)
{
    int s;
    o->x830 = 1;
    o->x1C8 = 0;
    s = DIntr();
    R(0x1000F590) = R(0x1000F520) | 0x10000;
    R(0x1000B000) = 0;
    R(0x1000B400) = 0;
    R(0x1000D400) = 0;
    R(0x1000F590) = R(0x1000F520) & ~0x10000;
    if (s) EIntr();
    R(0x1000B020) = 0;
    R(0x1000B420) = 0;
    R(0x1000D420) = 0;
    R(0x10002010) = 0x40000000;
    func_0010CA10(0, 0);
}