typedef struct { unsigned char type, f1, cb, f3, f4, pad5; unsigned short size; unsigned short f8; unsigned short len; } H;
typedef struct { H h; char payload[4]; } Out;
extern int func_002DD9F8(unsigned int, char **);
extern int func_002F59F8(void *, unsigned char *);
extern int func_002F56F8(void *, int);
extern int func_002F5918(void *, char **);
extern void *memcpy(void *, const void *, unsigned int);

int func_002E3F20(Out *out, unsigned int id, int len)
{
    char *e = 0;
    char *data = 0;
    unsigned char flag = 0;
    int base, sz, f8;
    H h;

    if (out == 0) return 0;
    if (len <= 0) return 0;
    if (id >= 0x800) return 0;
    if (func_002DD9F8(id, &e) != 0 || e == 0) return 0;
    h.type = id;
    h.f1 = e[5];
    h.cb = e[3];
    h.f3 = e[1];
    h.f4 = e[2];
    h.len = len;
    base = *(unsigned short *)(e + 0x10);
    sz = *(unsigned short *)(e + 0x14) - base;
    f8 = *(unsigned short *)(e + 0x18) - base;
    h.size = sz;
    h.f8 = f8;
    out->h = h;
    if (func_002F59F8(e + 0x2C, &flag)) return 0;
    if (flag) {
        if (func_002F56F8(e + 0x2C, 1)) return 0;
        memcpy(*(void **)(e + 0x10), *(void **)(e + 0x3C), *(int *)(e + 0x34));
    }
    if (func_002F5918(e + 0x2C, &data)) return 0;
    memcpy(out->payload, data, len);
    return len + 0xC;
}

