typedef struct { int a; int b; int c; char pad[0x38-0xC]; } E002232C0;
typedef struct { int count; E002232C0* tbl; } T002232C0;
extern T002232C0 D_004F5780;
int func_002232C0(int i, unsigned int v)
{
    if (i >= D_004F5780.count) return -11;
    if (v < 2) {
        int off = i * sizeof(E002232C0);
        ((E002232C0*)(off + (int)D_004F5780.tbl))->b = v;
        return 0;
    }
    return -12;
}