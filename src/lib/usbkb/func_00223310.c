typedef struct { int a; int b; int c; char pad[0x38-0xC]; } E00223310;
typedef struct { int count; E00223310* tbl; } T00223310;
extern T00223310 D_004F5780;
int func_00223310(int i, unsigned int v)
{
    if (i >= D_004F5780.count) return -11;
    if (v < 3) {
        int off = i * sizeof(E00223310);
        ((E00223310*)(off + (int)D_004F5780.tbl))->c = v;
        return 0;
    }
    return -12;
}