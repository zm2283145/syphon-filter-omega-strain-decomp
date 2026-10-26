typedef struct C {
    char pad0[0x34];
    int x34;
    char pad38[0x84C - 0x38];
    void *x84C;
} C;
typedef struct S S;
typedef void (*CB)(S *, int, int, char *, int);
struct S {
    char pad0[0x4C];
    CB cb4C;
};
extern int GetCodecType(void *);
/* weak never-linked stub (.dtors_drop is discarded at link): steers reorg delay-slot choice */
void * __attribute__((weak, section(".dtors_drop"))) GetResourceManager(S *p0) { return 0; }
extern void ReleaseCodec(void *, void *);
extern void *RequestDecoder(void *, int);
extern int DecodeData(void *, int, int, char *, int);
extern int GetPlayerStatus(C *);
extern void ResetPlayerStatus(C *, int);

int StreamOutput(S *o, C *c, int x, int y, int flag)
{
    char buf[0x800];
    int r = 0;
    int n;
    if (c->x84C) {
        if (flag) {
            if (GetCodecType(c->x84C) != x) {
                ReleaseCodec(GetResourceManager(o), c->x84C);
                c->x84C = 0;
            }
        } else {
            x = GetCodecType(c->x84C);
        }
    }
    if (c->x84C == 0) {
        c->x84C = RequestDecoder(GetResourceManager(o), x);
        if (c->x84C == 0)
            return r;
    }
    n = DecodeData(c->x84C, y, flag, buf, 0x800);
    if (n) {
        r = n;
        if (o->cb4C)
            o->cb4C(o, x, c->x34, buf, r);
    } else if (!flag && (GetPlayerStatus(c) & 0x1000)) {
        ReleaseCodec(GetResourceManager(o), c->x84C);
        c->x84C = 0;
        ResetPlayerStatus(c, 0x1000);
        if (o->cb4C)
            o->cb4C(o, x, c->x34, buf, 0);
    }
    return r;
}

