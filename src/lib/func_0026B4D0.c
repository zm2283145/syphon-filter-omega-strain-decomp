typedef struct { unsigned char b0, b1, b2, b3; int f4; char pad[0x14]; unsigned char name[0x20]; } R26B4D0;
typedef struct { int f0; int f4; char pad[0xC]; unsigned char f14[0x334 - 0x14]; } E26B4D0;
extern E26B4D0 D_004FBB88[];
extern void* memcpy(void* d, const void* s, unsigned int n);
extern void func_0026B5A0();
extern int func_0026B838(int port);
extern R26B4D0* func_0026B8F8(int port);
extern void func_0026B9C0(unsigned char* p, unsigned char* q);
int func_0026B4D0(int port, unsigned char* dst)
{
    R26B4D0* r;
    func_0026B5A0(port);
    if (D_004FBB88[port].f4 == 0) {
        if (func_0026B838(port) < 0) return -1;
    }
    r = func_0026B8F8(port);
    if (r->b3 && r->name) {
        memcpy(dst, r->name + r->b2, r->b3);
        func_0026B9C0(r->name + r->b2, D_004FBB88[port].f14);
    }
    if (r->f4 == 0) return -1;
    return r->b3;
}