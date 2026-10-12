typedef struct { unsigned char kind; unsigned char id; unsigned short len; int val; int seq; } ScfHdr;
typedef struct { int type; char pad[0x48]; int f4C; char pad2[0x24]; int f74; char pad3[0x18]; } ScfPeer;
typedef struct { int sock; ScfPeer *ents; char pad[0x40]; unsigned char b48; } ScfSock;
extern void *memset(void *d, int c, unsigned int n);
extern int Name_Compare48(const void *a, const void *b, int n);
extern void func_003060D8(int *t);

int func_0030A368(ScfSock *s, void *key, int idx)
{
    ScfHdr hdr;
    ScfPeer *e;
    int ret = 0;
    if (idx == -1) return 7;
    e = &s->ents[idx];
    memset(&hdr, 0, 12);
    hdr.val = e->f74;
    hdr.id = s->b48;
    if (Name_Compare48(&hdr, key, 12) == 0 && e->type == 12) {
        func_003060D8(&e->f4C);
    } else {
        ret = 4;
        if (e->type != 12) ret = 5;
    }
    return ret;
}
