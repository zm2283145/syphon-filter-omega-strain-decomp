/*
 * lib/medius: UPnP IGD SOAP response handlers, 0030C780-0030D1E8 (one retail unit, three functions).
 * Each handler parses one SOAP response (GetStatusInfo, GetExternalIPAddress,
 * GetGenericPortMappingEntry), frees the request, then either retries or reports
 * the result through the request's callback. Each callback arm has its own call and
 * cleanup tail: jump2 cross-jumps them after scheduling, which gives retail's shared jalr.
 * Built with gcc 2.96 -G0 (with -G8 the "UDP" literal would go to .sdata).
 */
typedef struct {
    void* p0;
    void* h;
    int flags;
    int pad0C;
    char x10[0x1024 - 0x10];
    int status;
    char pad1028[0x2030 - 0x1028];
    unsigned char b2030;
    char pad2031[0x2050 - 0x2031];
    void (*cb)(void* c, int r, int flags, int state);
} Req_30C780;

typedef struct {
    char pad[0x50];
    int f50;
    int pad54;
    Req_30C780* req;
} Conn_30C780;

typedef struct {
    char keys[12][256];
    char vals[12][256];
    unsigned int count;
} List_30C780;

typedef struct {
    void* p0;
    void* h;
    int flags;
    int pad0C;
    char x10[0x1024 - 0x10];
    int status;
    char pad1028[0x2030 - 0x1028];
    unsigned char b2030;
    char pad2031[0x2054 - 0x2031];
    void (*cb)(void* c, int r, int flags, char* name);
} Req_30CA90;

typedef struct {
    char pad[0x14];
    char name[16];
    char pad24[0x50 - 0x24];
    int f50;
    int pad54;
    Req_30CA90* req;
} Conn_30CA90;

typedef struct {
    char keys[12][256];
    char vals[12][256];
    unsigned int count;
} List_30CA90;

typedef struct {
    void* p0;
    void* h;
    int flags;
    int pad0C;
    char x10[0x1024 - 0x10];
    int status;
    char pad1028[0x2030 - 0x1028];
    unsigned char b2030;
    unsigned char pad2031;
    unsigned char found;
    char pad2033[0x203C - 0x2033];
    unsigned int count;
    unsigned int idx;
    char pad2044[0x2058 - 0x2044];
    void (*cb)(void* c, int r, int flags, int port);
    char pad205C[0x2A70 - 0x205C];
    char buf[0x100];
} Req_30CD00;

typedef struct {
    int f0;
    char host[0x20];
    unsigned short port;
    unsigned short ext;
    char pad28[0x50 - 0x28];
    int f50;
    int pad54;
    Req_30CD00* req;
} Conn_30CD00;

typedef struct {
    char keys[12][256];
    char vals[12][256];
    unsigned int count;
} List_30CD00;


extern char D_004AFF28[];

/* Connection-state names, pointed to (in reverse order) by the D_00491360 table in .data.
 * They open this unit's .rodata block: the 30C780 jump table at 0x4AFFC0 is 16-aligned,
 * so the block cannot start at the first function literal (0x4AFF98). */
const char D_004AFF30[] = "Disconnected";
const char D_004AFF40[] = "Disconnecting";
const char D_004AFF50[] = "PendingDisconnect";
const char D_004AFF68[] = "Connected";
const char D_004AFF78[] = "Connecting";
const char D_004AFF88[] = "Unconfigured";
extern char* D_00491360[];
extern char D_00529880[];

int func_0030BC98(void* c, unsigned char* ok);
int func_00310C90(void* h, char* name, int a, int b);
int func_00310D20(void* h, void* out);
int func_00310C30(void* h);
void rt_comm_destroy(void* p);
int UPnP_SendSoapAction(void* c, char* a, char* b);
void rt_time_get_time_stamp(void* p);
int Libc_Strncmp(const char* a, const char* b, int n);
char* strncpy(char* d, const char* s, unsigned int n);
long strtol(const char* s, char** e, int base);
int sprintf(char* d, const char* f, ...);
void* memset(void* d, int c, unsigned int n);

int func_0030C780(Conn_30C780* c)
{
    unsigned char ok;
    int r;
    int e;
    int st;
    Req_30C780* q;

    st = 0;
    ok = 0;
    r = func_0030BC98(c, &ok);
    if (r != 0 || ok != 0) {
    q = c->req;
    if (q->status == 200 && ok) {
        if (!q->b2030) {
            char* v = 0;
            e = func_00310C90(q->h, D_004AFF28, 0, 1);
            if (e == 0) {
                e = func_00310D20(c->req->h, &v);
                if (e == 0)
                    strncpy(D_00529880, v, 256);
            }
        } else {
            List_30C780* l = 0;
            e = func_00310C90(q->h, D_004AFF28, 0, 1);
            if (e == 0) {
                e = func_00310D20(c->req->h, &l);
                if (e == 0) {
                    unsigned int i;
                    for (i = 0; i < l->count; i++) {
                        if (Libc_Strncmp("NewConnectionStatus", l->keys[i], 256) == 0)
                            strncpy(D_00529880, l->vals[i], 256);
                    }
                }
            }
        }
        if (e == 0) {
            unsigned int i;
            for (i = 0; D_00491360[i] && Libc_Strncmp(D_00529880, D_00491360[i], 256); i++)
                ;
            switch (i) {
            case 0: st = 0; break;
            case 1: st = 1; break;
            case 2: st = 2; break;
            case 3: st = 3; break;
            case 4: st = 4; break;
            case 5: st = 5; break;
            }
        } else
            r = 4;
    }
    func_00310C30(c->req->h);
    c->req->h = 0;
    rt_comm_destroy(c->req->p0);
    c->req->p0 = 0;
    memset(&c->req->status, 0, 0x100C);
    { Req_30C780* q = c->req;
    if (!q->b2030) {
        if (r != 0) {
            r = UPnP_SendSoapAction(c, "GetStatusInfo", D_004AFF28);
            if (r == 0) {
                rt_time_get_time_stamp(c->req->x10);
                goto out;
            }
            { Req_30C780* q2 = c->req; q2->cb(c, r, q2->flags, st); }
            { Req_30C780* qq = c->req; c->f50 = 0; qq->cb = 0; }
        } else {
            q->cb(c, 0, q->flags, st);
            { Req_30C780* qq = c->req; c->f50 = 0; qq->cb = 0; }
        }
    } else {
        q->cb(c, r, q->flags, st);
        { Req_30C780* qq = c->req; c->f50 = 0; qq->cb = 0; }
    }
    }
    }
out:
    return r;
}

int func_0030CA90(Conn_30CA90* c)
{
    unsigned char ok;
    int r;
    int e;
    Req_30CA90* q;

    ok = 0;
    r = func_0030BC98(c, &ok);
    if (r != 0 || ok != 0) {
    q = c->req;
    if (q->status == 200 && ok) {
        if (!q->b2030) {
            char* v = 0;
            e = func_00310C90(q->h, D_004AFF28, 0, 1);
            if (e == 0) {
                e = func_00310D20(c->req->h, &v);
                if (e == 0)
                    strncpy(c->name, v, 16);
            }
        } else {
            List_30CA90* l = 0;
            e = func_00310C90(q->h, D_004AFF28, 0, 1);
            if (e == 0) {
                e = func_00310D20(c->req->h, &l);
                if (e == 0) {
                    unsigned int i;
                    for (i = 0; i < l->count; i++) {
                        if (Libc_Strncmp("NewExternalIPAddress", l->keys[i], 256) == 0)
                            strncpy(c->name, l->vals[i], 16);
                    }
                }
            }
        }
        if (e != 0)
            r = 4;
    }
    func_00310C30(c->req->h);
    c->req->h = 0;
    rt_comm_destroy(c->req->p0);
    c->req->p0 = 0;
    memset(&c->req->status, 0, 0x100C);
    { Req_30CA90* q = c->req;
    if (!q->b2030) {
        if (r != 0) {
            r = UPnP_SendSoapAction(c, "GetExternalIPAddress", D_004AFF28);
            if (r == 0) {
                rt_time_get_time_stamp(c->req->x10);
                goto out;
            }
            { Req_30CA90* q2 = c->req; q2->cb(c, r, q2->flags, c->name); }
            { Req_30CA90* qq = c->req; c->f50 = 0; qq->cb = 0; }
        } else {
            q->cb(c, 0, q->flags, c->name);
            { Req_30CA90* qq = c->req; c->f50 = 0; qq->cb = 0; }
        }
    } else {
        q->cb(c, r, q->flags, c->name);
        { Req_30CA90* qq = c->req; c->f50 = 0; qq->cb = 0; }
    }
    }
    }
out:
    return r;
}

extern const char D_004B0088[];

int func_0030CD00(Conn_30CD00* c)
{
    unsigned char ok;
    int r;
    int e;

    ok = 0;
    r = func_0030BC98(c, &ok);
    if (r != 0 || ok != 0) {
    if (c->req->status == 200 && ok) {
        if (!c->req->b2030) {
            char* v = 0;
            if (func_00310C90(c->req->h, D_004AFF28, 0, 1) != 0)
                goto fail;
            e = func_00310D20(c->req->h, &v);
            if (e != 0)
                goto fail;
            {
                int n = strtol(v, 0, 10);
                Req_30CD00* q1 = c->req;
                c->ext = 0;
                q1->found = 0;
                q1->count = n;
                q1->idx = 0;
                c->req->b2030 = 1;
            }
        } else {
            List_30CD00* l = 0;
            unsigned char hit, proto, pmatch;
            unsigned short port;
            unsigned int i;
            if (func_00310C90(c->req->h, D_004AFF28, 0, 1) != 0)
                goto fail;
            e = func_00310D20(c->req->h, &l);
            if (e != 0)
                goto fail;
            hit = 0;
            proto = 0;
            pmatch = 0;
            port = 0;
            for (i = 0; i < l->count; i++) {
                if (Libc_Strncmp(l->keys[i], "NewInternalClient", 256) == 0 && Libc_Strncmp(l->vals[i], c->host, 256) == 0) {
                    hit = 1;
                } else if (Libc_Strncmp(l->keys[i], "NewInternalPort", 256) == 0) {
                    if (c->port == (unsigned short)strtol(l->vals[i], 0, 10))
                        pmatch = 1;
                } else if (Libc_Strncmp(l->keys[i], "NewProtocol", 256) == 0 && Libc_Strncmp(l->vals[i], "UDP", 256) == 0) {
                    proto = 1;
                } else if (Libc_Strncmp(l->keys[i], "NewExternalPort", 256) == 0) {
                    port = strtol(l->vals[i], 0, 10);
                }
            }
            if (hit && proto && pmatch) {
                c->ext = port;
                c->req->found = 1;
            } else if (!c->req->found) {
                if (c->ext < port)
                    c->ext = port;
            }
        }
        if (e == 0)
            goto done;
    fail:
        { Req_30CD00* q3 = c->req;
        if (!q3->b2030) {
            c->ext = 0;
            q3->found = 0;
            q3->count = 32;
            q3->idx = 0;
            c->req->b2030 = 1;
        } else {
            q3->idx = q3->count;
        }
        }
        r = 0;
    } else {
        { Req_30CD00* q4 = c->req;
        if (!q4->b2030) {
            c->ext = 0;
            q4->found = 0;
            q4->count = 32;
            q4->idx = 0;
            c->req->b2030 = 1;
        } else {
            q4->idx = q4->count;
        }
        }
    }
done:
    func_00310C30(c->req->h);
    c->req->h = 0;
    rt_comm_destroy(c->req->p0);
    c->req->p0 = 0;
    memset(&c->req->status, 0, 0x100C);
    { Req_30CD00* q5 = c->req;
    if (q5->b2030) {
        if (q5->idx < q5->count) {
            sprintf(q5->buf, "<NewPortMappingIndex>%d</NewPortMappingIndex>", q5->idx);
            { Req_30CD00* q6 = c->req; q6->idx++; r = UPnP_SendSoapAction(c, (char *)D_004B0088, q6->buf); }
            if (r == 0) {
                rt_time_get_time_stamp(c->req->x10);
                goto out;
            }
            { Req_30CD00* q7 = c->req;
            if (!q7->found) {
                if (c->ext < c->port)
                    c->ext = c->port;
                else
                    c->ext = c->ext + 1;
            }
            q7->cb(c, r, q7->flags, c->ext);
            { Req_30CD00* qq = c->req; c->f50 = 0; qq->cb = 0; } }
        } else {
            if (!q5->found) {
                if (c->ext < c->port)
                    c->ext = c->port;
                else
                    c->ext = c->ext + 1;
            }
            if (r == 11) r = 0;
            q5->cb(c, r, q5->flags, c->ext);
            { Req_30CD00* qq = c->req; c->f50 = 0; qq->cb = 0; }
        }
    } }
    }
out:
    return r;
}

/* Last literal of the block, defined after func_0030CD00 so it is still emitted last. Sized 28
 * (27 bytes + the retail zero pad) so the .rodata block ends on a 4-byte boundary
 * (0x4AFF30 + 0x174): tools/data_obj.py pads an odd-sized block with objcopy
 * --update-section, which drops the block's relocations (the 30C780 jump table). */
const char D_004B0088[28] = "GetGenericPortMappingEntry";
