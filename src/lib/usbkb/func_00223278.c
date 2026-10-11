typedef struct { char pad[0x14]; int f14; int f18; int f1c; char pad2[0x18]; } E223278;
extern E223278* D_004F5784;
int func_00223278(int i, int a, int b)
{
    E223278* e;
    int off;
    if (a < 0) return -11;
    if (b < 0) return -12;
    off = i * sizeof(E223278);
    e = (E223278*)(off + (int)D_004F5784);
    e->f1c = b;
    e->f18 = a;
    e->f14 = 0;
    return 0;
}