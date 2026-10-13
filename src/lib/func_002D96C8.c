typedef struct { char b[8]; } Raw;
typedef struct {
    unsigned char type;
    unsigned char id;
    unsigned short len;
    unsigned short w4;
    unsigned short w6;
} Hdr;
typedef struct Conn {
    int pad0;
    struct Conn *next;
    int pad8;
    int xC;
    int x10;
    int x14;
    int pad18[2];
    int x20;
    int x24;
    int x28;
    int x2C;
    int x30;
    int x34;
} Conn;
typedef struct {
    char pad0[0x6C];
    Conn *x6C;
    int pad70;
    int x74;
    int x78;
    char pad7C[0x98 - 0x7C];
    int x98;
} S;

extern void *memcpy(void *, const void *, unsigned int);
extern int func_002F5160(void);
extern Conn *func_002F2FA8(Conn *, int);
extern void func_002DB0D0(S *, int);
extern void func_002F3198(Conn *, int);
extern void *func_002D9E18(S *, int);
extern int func_002F3250(Conn *, Hdr *, int);
extern void func_002DB070(S *, int, int, int);
extern int func_002EE1E0(void *, Hdr *, Conn *, Hdr *, unsigned int);
extern int func_002EE4C8(void *, Hdr *, Conn *, Hdr *, unsigned int);
extern int func_002EE798(void *, Hdr *, Conn *, Hdr *, unsigned int);

int func_002D96C8(S *o, int k1, int k2, Hdr *hp, unsigned int len)
{
    Hdr h;
    Conn *c, *head, *d;
    void *e;
    int now = func_002F5160();
    int id34, r;
    if (len < 8)
        return -1;
    memcpy(&h, hp, 8);
    if (h.type & 0x80) {
        h.type &= 0x7F;
        memcpy(hp, &h, 8);
        c = func_002F2FA8(o->x6C, h.w4);
        if (c != 0 && c->xC == 0) {
            if (c->x20 == k1) {
                c->x28 = k2;
                c->xC = 2;
            } else if (c->x24 == k1) {
                c->x2C = k2;
                c->xC = 1;
            } else {
                c = 0;
            }
        }
    } else {
        head = c = o->x6C;
        while (c) {
            if (c->x20 == k1 && c->x28 == k2) {
                if (c->xC == 0)
                    c->xC = 2;
                break;
            }
            if (c->x24 == k1 && c->x2C == k2) {
                if (c->xC == 0)
                    c->xC = 1;
                break;
            }
            c = c->next;
            if (c == head)
                c = 0;
        }
    }
    if (c == 0)
        return 0;
    c->x10 = now;
    c->x14 = 0;
    id34 = c->x34;
    d = func_002F2FA8(o->x6C, h.w4);
    if (d == 0)
        return 0;
    switch (h.type) {
    case 0x20:
    case 0x21:
    case 0x22:
    case 0x23:
    case 0x2F:
    case 0x30:
        if (h.len != len - 12)
            return -1;
        break;
    default:
        if (h.len != len - 8)
            return -1;
        break;
    }
    if (h.w4 == o->x78)
        return 0;
    if (h.id) {
        if (h.id != d->x30 || h.id != o->x98) {
            func_002DB0D0(o, d->x34);
            d->x10 = now;
            d->x14++;
            if (h.id != o->x98)
                return 0;
            func_002F3198(d, h.id);
        }
    }
    e = func_002D9E18(o, h.id);
    if (e == 0)
        return 0;
    r = func_002F3250(d, &h, id34);
    if (r != 0xFFFF && r != id34) {
        if (o->x74)
            func_002DB070(o, h.id, id34, h.w4);
        return 0;
    }
    if (h.id) {
        if ((unsigned char)(h.type - 0x20) < 4 || h.type == 0x2F)
            return func_002EE1E0(e, &h, c, hp, len);
        if (h.type == 0x30)
            return func_002EE4C8(e, &h, c, hp, len);
    }
    return func_002EE798(e, &h, c, hp, len);
}


