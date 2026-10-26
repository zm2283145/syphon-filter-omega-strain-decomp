typedef struct { unsigned char b[16]; } N26B298;
typedef struct { int f0; int f4; int f8; int fc; N26B298 name; } P26B298;
typedef struct { int f0; int f4; int f8; int fc; int f10; N26B298 name; } S26B298;
typedef struct { int used; char pad[0xC]; void* buf; char pad2[0x334 - 0x14]; } E26B298;
extern E26B298 D_004FBB88[];
extern int sceDbcCreateSocket(S26B298* p, void* rbuf, void* sbuf);
extern int scePrintf(const char* fmt, ...);
extern void scePad2InitDmaDBuff(int i);
int scePad2CreateSocket(P26B298* p, void* buf)
{
    S26B298 s;
    int r;
    if ((int)buf & 0x3F) {
        scePrintf("libpad2: buffer addr is not 64 byte align. %08x\n", buf);
        return -1;
    }
    if (p) {
        s.f0 = p->f0;
        s.f8 = p->f4;
        s.fc = p->f8;
        s.f10 = p->fc;
        s.name = p->name;
    } else {
        s.f0 = 0;
        s.f8 = 0;
        s.fc = 0;
        s.f10 = 0;
        s.name.b[0] = 0;
    }
    s.f4 = 1;
    s.f0 |= 1;
    r = sceDbcCreateSocket(&s, buf, (char*)buf + 0x80);
    if (r < 0) return r;
    D_004FBB88[r].used = 1;
    D_004FBB88[r].buf = buf;
    scePad2InitDmaDBuff(r);
    return r;
}

