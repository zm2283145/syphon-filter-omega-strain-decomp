typedef struct { char d[0x40]; } Blob2E1248;
typedef struct {
    int kind;
    char name[0x10];
    unsigned short port;
    char pad[2];
} Ent2E1248;
typedef struct {
    int type;
    Ent2E1248 e[2];
    Blob2E1248 b;
} In2E1248;
typedef struct {
    int done;
    int code;
} Res2E1248;
typedef struct {
    Blob2E1248 b;
    char name2[0x10];
    char name1[0x10];
    unsigned short port2;
    unsigned short port1;
} Req2E1248;
extern int D_0048C458;
extern unsigned char D_0048C4AC;
extern int D_0048C4B0;
extern void *memset(void *p, int c, unsigned int n);
extern char *strncpy(char *d, const char *s, unsigned int n);
extern int func_00303130(int h, Req2E1248 *req);

int func_002E1248(In2E1248 *in, Res2E1248 *r)
{
    Req2E1248 req;
    unsigned int i;

    if (r == 0)
        return 0x17;
    r->code = 0x1E;
    r->done = 1;
    if (in == 0) {
        r->code = 0x17;
        return 0x17;
    }
    if (D_0048C458 != 1) {
        r->code = 0x11;
        return 0x11;
    }
    if (in->type != D_0048C458) {
        r->code = 0x26;
        return 0x26;
    }
    if (D_0048C4AC != in->type) {
        r->code = 0x1A;
        return 0x1A;
    }
    memset(&req, 0, sizeof(req));
    req.b = in->b;
    for (i = 0; i < 2; i++) {
        if (in->e[i].kind == 2) {
            strncpy(req.name2, in->e[i].name, 0x10);
            req.port2 = in->e[i].port;
        } else if (in->e[i].kind == 1) {
            strncpy(req.name1, in->e[i].name, 0x10);
            req.port1 = in->e[i].port;
        }
    }
    if (func_00303130(D_0048C4B0, &req))
        r->code = 0x25;
    else
        r->code = 0;
    return r->code;
}
