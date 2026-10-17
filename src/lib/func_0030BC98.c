typedef struct {
    int status;
    int maxage;
    int clen;
} SsdpRespHdr;

typedef struct {
    int h;
    int h2;
    char pad8[0x10 - 0x8];
    char timer[0x1024 - 0x10];
    SsdpRespHdr resp;
    char pad1030[0x2031 - 0x1030];
    unsigned char hdrDone;
    char pad2032[0x2038 - 0x2032];
    int total;
    char pad203C[0x2070 - 0x203C];
    char buf[0x2C70 - 0x2070];
    char hdr[0x200];
} SsdpCtx;

typedef struct {
    char pad[0x58];
    SsdpCtx* ctx;
} SsdpObj;

extern char D_004AFAA0[];
extern char D_004AFAA8[];
int func_002F6090(int a, char* b, unsigned short c, unsigned short* out);
char* strstr(char* s, char* pat);
char* strncpy(char* d, const char* s, unsigned int n);
int func_0030B760(char* buf, SsdpRespHdr* r);
int func_00310C90(int h, char* p, unsigned short n, int z);
int func_00310CC0(int h, unsigned char* done, SsdpCtx* c);
void func_003060F0(void* timer, unsigned int* out);

int func_0030BC98(SsdpObj* o, unsigned char* done)
{
    unsigned short n;
    unsigned int t;
    int r;
    char* p;
    SsdpCtx* c;

    {
        register int e asm("$3");
        e = func_002F6090(o->ctx->h, o->ctx->buf, 0x800, &n);
        if (e != 0) {
            { register int d asm("$4"); d = 1; *done = d; }
            if (e == 0xD)
                goto ok;
            return 9;
        }
    }
    if (n != 0) {
        o->ctx->buf[n] = 0;
        if (o->ctx->hdrDone) {
            p = o->ctx->buf;
        } else {
            p = strstr(o->ctx->buf, D_004AFAA0);
            if (p == 0) {
                p = strstr(o->ctx->buf, D_004AFAA8);
                if (p == 0)
                    return 0xB;
            }
            *p = 0;
            p += 4;
            n -= (unsigned short)(p - o->ctx->buf);
            strncpy(o->ctx->hdr, o->ctx->buf, 0x200);
            func_0030B760(o->ctx->hdr, &o->ctx->resp);
            if (o->ctx->resp.status != 200)
                return 0xB;
            o->ctx->hdrDone = 1;
        }
        r = func_00310C90(o->ctx->h2, p, n, 0);
        if (r != 0)
            return 4;
        c = o->ctx;
        c->total += n;
        if (c->total == c->resp.clen && c->total > 0) {
            *done = 1;
            return r;
        }
        if (func_00310CC0(c->h2, done, c) != 0)
            return 4;
    } else {
        func_003060F0(o->ctx->timer, &t);
        if (t > 30000)
            return 6;
    }
ok:
    return 0;
}

