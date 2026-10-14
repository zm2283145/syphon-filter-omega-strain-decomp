typedef struct { unsigned char b0, b1, b2, b3; int f4; char pad[0x14]; unsigned char name[0x20]; char pad2[0x7C - 0x3C]; int f7c; } R26B7C0;
typedef struct { char pad[0x10]; R26B7C0* recs; char pad2[0x334 - 0x14]; } E26B7C0;
extern E26B7C0 D_004FBB88[];
extern void* memset(void* d, int c, unsigned int n);
void func_0026B7C0(int i)
{
    R26B7C0* r = D_004FBB88[i].recs;
    int n;
    for (n = 1; n >= 0; n--) {
        r->b0 = 0;
        r->f7c = 0;
        r->b1 = 0;
        r->b3 = 0;
        r->b2 = 0;
        r->f4 = 0;
        memset(r->name, 0xFF, 0x20);
        r++;
    }
}