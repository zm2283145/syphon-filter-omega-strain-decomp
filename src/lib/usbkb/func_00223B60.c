typedef struct { int f0; int f4; char pad[0x14]; int f1c; int f20; int f24; } Q223B60;
typedef struct { char pad[0x10]; Q223B60 q; } E223B60;
extern E223B60* D_004F5784;
int func_00223B60(int i)
{
    Q223B60* q = &D_004F5784[i].q;
    q->f24 = 0;
    q->f1c = 0;
    q->f20 = 0;
    q->f4 = 0;
    return 0;
}