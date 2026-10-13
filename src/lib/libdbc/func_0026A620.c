typedef struct { void* f0; void* f4; void* f8; void* fC; void* f10; } DbcHdr;
typedef struct {
    DbcHdr h;
    char name[16];
    int ret;
    int a;
    int b;
} DbcSock;
extern DbcSock D_004F8640;
extern char D_004F85C8[];
extern int sceSifCallRpc(void* cd, unsigned int fno, int mode, void* send, int ssize, void* recv, int rsize, void* end, void* param);
extern void func_0026B1C8(const char* fmt, ...);
extern int D_0048B238;
int sceDbcCreateSocket(DbcSock* s, int a, int b)
{
    int i;
    DbcSock* p;
    if (D_0048B238 == 0) return 0;
    p = &D_004F8640;
    p->h.f0 = s->h.f0;
    p->a = a;
    p->h.f4 = s->h.f4;
    p->b = b;
    p->h.f8 = s->h.f8;
    p->h.fC = s->h.fC;
    p->h.f10 = s->h.f10;
    for (i = 0; i < 16; i++) p->name[i] = s->name[i];
    if (sceSifCallRpc(D_004F85C8, 0x80001301, 0, &D_004F8640, 0x280, &D_004F8640, 0x280, 0, 0) < 0) {
        func_0026B1C8("sceDbcCreateSocket: rpc error\n");
        return 0;
    }
    return p->ret;
}
