typedef struct { unsigned int type; int f4; char name[16]; unsigned short port; char pad[0x5A]; int f74; char pad3[0x18]; } ScfPeer;
typedef struct { int sock; ScfPeer *ents; char pad[0x24]; unsigned int count; } ScfSock;
typedef struct { int f0; int f4; } ScfPkt;
extern int String_CompareN(const char *a, const char *b, int n);

int func_0030A9D8(ScfSock *s, ScfPkt *p, const char *name, unsigned short port, int *out)
{
    unsigned int i;
    int fallback = -1;
    ScfPeer *e;
    int ret = 2;
    if (s == 0) return ret;
    ret = 1;
    if (p == 0) return ret;
    if (name == 0) return ret;
    if (out == 0) return ret;
    *out = -1;
    for (i = 0; i < s->count; i++) {
        e = &s->ents[i];
        if (e->type == 0) continue;
        if (String_CompareN(name, e->name, 16) != 0) continue;
        if (port != e->port) continue;
        if (p->f4 == e->f74) {
            *out = i;
            break;
        }
        if (e->type - 8 < 2) {
            if (p->f4 == 0 || e->f74 == 0) fallback = i;
        }
    }
    if (*out == -1 && fallback != -1) *out = fallback;
    return 0;
}
