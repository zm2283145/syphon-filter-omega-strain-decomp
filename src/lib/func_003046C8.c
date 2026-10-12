typedef struct { int type; int f4; int f8; int pad[7]; } UpnpEnt;
typedef struct { char pad[0x180]; int h180; UpnpEnt *ent; int count; int f18C; int f190; } UpnpObj;
typedef struct { int magic; char a4[0x10]; char a14[0x10]; unsigned short p24; unsigned short p26; int peer; unsigned char b2C; char pad[3]; char b30[0x40]; } UpnpRec;
extern void *memset(void *, int, unsigned int);
extern int func_00304578(UpnpObj *o, int *type, int *idx);
extern int func_00302B28(UpnpObj *o, int mode, void *a, void *b);
extern int func_00302A38(UpnpObj *o, int peer, int mode, void *a, void *b);
extern int func_002F8908(int, void *);
extern int func_002F8628(int, int, void *);
int func_003046C8(UpnpObj *o, int peer, UpnpRec *r)
{
    int type;
    int idx;
    int ret;
    idx = -2;
    type = 0;
    if (r == 0) return 2;
    if ((ret = func_00304578(o, &type, &idx)) != 0) return ret;
    memset(r, 0, 0x70);
    r->magic = 0xEFF0CDAB;
    r->peer = peer;    if (peer == idx) {
        r->b2C = 1;
        if ((ret = func_00302B28(o, 0, r->a4, &r->p24)) != 0) return ret;
        ret = func_00302B28(o, 1, r->a14, &r->p26);
        func_002F8908(-1, r->b30);
        if (ret == 0) goto ok;
        return ret;
    }
    if ((ret = func_00302A38(o, peer, 0, r->a4, &r->p24)) != 0) return ret;
    ret = func_00302A38(o, peer, 1, r->a14, &r->p26);
    func_002F8628(-1, peer, r->b30);
    if (ret != 0) return ret;
ok:
    return 0;
}
