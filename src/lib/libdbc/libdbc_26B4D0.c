typedef struct { unsigned char b0, b1, b2, b3; int f4; char pad[0x14]; unsigned char name[0x20]; } R26B4D0;
typedef struct { int f0; int f4; char pad[0xC]; unsigned char f14[0x334 - 0x14]; } E26B4D0;
extern E26B4D0 D_004FBB88[];
extern void* memcpy(void* d, const void* s, unsigned int n);
extern void scePad2GetState();
extern int scePad2LinkDriver(int port);
extern R26B4D0* scePad2GetSide2(int port);
extern void scePad2SetButtonOrder(unsigned char* p, unsigned char* q);
int scePad2GetButtonProfile(int port, unsigned char* dst)
{
    R26B4D0* r;
    scePad2GetState(port);
    if (D_004FBB88[port].f4 == 0) {
        if (scePad2LinkDriver(port) < 0) return -1;
    }
    r = scePad2GetSide2(port);
    if (r->b3 && r->name) {
        memcpy(dst, r->name + r->b2, r->b3);
        scePad2SetButtonOrder(r->name + r->b2, D_004FBB88[port].f14);
    }
    if (r->f4 == 0) return -1;
    return r->b3;
}