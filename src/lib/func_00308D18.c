typedef struct {
    unsigned char flags;
    unsigned char b1;
    unsigned short off;
    unsigned char rest[8];
} Hdr8d18;

typedef struct {
    char pad[0x1C];
    int list;
} Obj8d18;

extern void *memcpy(void *, const void *, unsigned int);
extern void *memset(void *, int, unsigned int);
extern int func_00308F58(void *pkt, Hdr8d18 *out);
extern int func_00308FB8(void *pkt, Hdr8d18 *in);
extern int func_002FA930(int *list, void *pkt, void *data, int size);
extern int func_002FABD0(int *list, void **pkt);
extern void *func_002FAF00(void *pkt);
extern char *func_002FAED0(void *pkt);
extern int func_002FAEE8(void *pkt);
extern int Name_Compare48(const char *a, const char *b, int n);

int func_00308D18(int unused, Obj8d18 *o, unsigned char flags, void *pkt, void *data, int len)
{
    Hdr8d18 hd, cur;
    char *p;

    if (pkt == 0) return 1;
    if (data == 0) return 1;
    if (len == 0) return 1;
    func_00308F58(pkt, &hd);
    if (func_002FA930(&o->list, pkt, data, len) != 0) return 10;
    func_002FABD0(&o->list, &pkt);
    while (pkt != 0) {
        func_00308F58(pkt, &cur);
        if (Name_Compare48((char *)&hd, (char *)&cur, 12) == 0) {
            memcpy(func_002FAED0(pkt) + hd.off + 0x18, data, len);
            p = func_002FAED0(pkt);
            p += func_002FAEE8(pkt);
            memset(p - 4, 0, 4);
            hd.off += len;
            hd.flags |= flags & 7;
            func_00308FB8(pkt, &hd);
            pkt = 0;
            break;
        }
        pkt = func_002FAF00(pkt);
    }
    return 0;
}
