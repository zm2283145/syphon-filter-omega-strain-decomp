typedef struct Hdr {
    char b[8];
} Hdr;
typedef struct Conn {
    char pad0[0xC];
    unsigned int state;
    char pad10[0x20 - 0x10];
    int h20;
    int h24;
    int cb28;
    int cb2C;
} Conn;
typedef struct Obj {
    char pad0[0x6C];
    int list;
} Obj;
extern void *memcpy(void *, const void *, unsigned int);
extern Conn *func_002F2FA8(int, int);
extern int func_002D9B68(Obj *, char *, int, int, int);
int func_002D9A30(Obj *o, int id, Hdr *hdr, void *data, unsigned int len)
{
    char buf[0x500];
    int ret = 0;
    Conn *c = func_002F2FA8(o->list, id);
    int n;
    if (len + 8 > 0x500)
        return -1;
    if (c == 0)
        return -1;
    n = 8;
    *(Hdr *)buf = *hdr;
    memcpy(buf + n, data, len);
    n = len + n;
    if (c->h24 != 0 && c->state < 2) {
        if (c->cb2C == 0)
            return -1;
        ret = -1;
        if (n == func_002D9B68(o, buf, n, c->h24, c->cb2C))
            ret = 0;
    }
    if (c->h20 != 0) {
        if (c->state == 2 || c->state == 0) {
            if (c->cb28 == 0)
                return -1;
            if (n != func_002D9B68(o, buf, n, c->h20, c->cb28))
                ret = -1;
        }
    }
    return ret;
}

