typedef struct { unsigned short id; char pad[6]; int f8; char pad2[0x78]; void (*cb)(int, int, int, int, int); } O;
typedef struct { char pad[5]; unsigned char f5; unsigned short f6; char pad2[0x34]; short f3c; } P;
extern int func_002FE720(O *);
int __attribute__((weak, section(".dtors_drop"))) func_002FE8B0(P *p0) { return 0; } /* stub: defined in same original TU; fixes first bne (non-likely) */
extern void func_00301AB8(unsigned char *, unsigned int *);
extern int func_002FB5C8(void);
extern void func_003019B0(unsigned char *, unsigned short *);
extern void func_002F9C80(int, int, unsigned int, unsigned char *, int);
extern int func_002FFD70(O *, int, unsigned char *, int);
extern int func_002FF868(O *, int, unsigned char *, int);
extern int func_00301038(O *, int);
extern int func_002FE7C0(int);
extern int func_00300330(O *, int, unsigned char *, int);
extern int func_002FFB48(O *, int, unsigned char *, int);
extern int func_002FFE80(O *, int, unsigned char *, int);
extern int func_00300068(O *, int, unsigned char *, int);
extern int func_00300168(O *, int, unsigned char *, int);
extern int func_00300248(O *, int, unsigned char *, int);
extern void func_002F8A28(int, int, unsigned char *);
extern int func_00300450(O *, int, unsigned char *, int);
extern int func_00300528(O *, P *, int, unsigned char *, int);
extern int func_00300918(O *, P *, int, unsigned char *, int);

int func_002FF4D8(O *o, P *p, int type, unsigned char *data, int len)
{
    unsigned short tmp;
    unsigned int out;
    int sub;
    int r;
    int x;
    r = 1;
    sub = (type >> 7) & 1;
    type &= 0x7F;
    out = 0;
    if (func_002FE720(o) != r) return 2;
    if (func_002FE8B0(p) != r) return 2;
    if (p->f5 != r) return 2;
    if (o->id != p->f6) return 2;
    if (data == 0) return 2;
    if (sub && len != 0) {
        func_00301AB8(data, &out);
        data += 4;
        if (func_002FB5C8() != r) return 0x1B;
        if (out == 0) return 0x1C;
        if (type == 3 || type == 0x1B) {
            tmp = 0;
            func_003019B0(data, &tmp);
            tmp = 0xFFFF;
            func_002F9C80(o->id, 0xFFFF, out, data + 2, len - 2);
        } else {
            func_002F9C80(o->id, 0xFFFF, out, data, len);
        }
    }
    switch (type) {
    case 26:
        r = func_002FFD70(o, type, data, len);
        break;
    case 6:
    case 7:
        r = func_002FF868(o, type, data, len);
        if (r == 0x10) {
            x = func_00301038(o, 0xB);
            if (x != 0) return x;
            if (o->cb == 0) goto nocb;
            {
                int id = o->id;
                o->cb(id, 0, 0, 0, 3);
                if (func_002FE7C0(id) != 0) goto nocb;
                return 0xB;
            }
        }
        break;
    case 24:
        r = func_00300330(o, type, data, len);
        break;
    case 25:
        if (o->f8 != 6) goto nocb;
        r = func_002FFB48(o, type, data, len);
        break;
    case 8:
    case 9:
        r = func_002FFE80(o, type, data, len);
        break;
    case 2:
    case 3:
    case 10:
        r = 0;
        if (o->f8 == 8) r = func_00300068(o, type, data, len);
        break;
    nocb:
        r = 0;
        break;
    case 5:
        r = 0;
        p->f3c--;
        break;
    case 17:
        r = func_00300168(o, type, data, len);
        break;
    case 19:
    case 27:
        r = func_00300248(o, type, data, len);
        break;
    case 20:
        r = 0;
        func_002F8A28(o->id, o->id, data);
        break;
    case 28:
        r = func_00300450(o, type, data, len);
        break;
    case 29:
        r = func_00300528(o, p, type, data, len);
        break;
    case 30:
        r = func_00300918(o, p, type, data, len);
        break;
    default:
        r = 3;
        break;
    }
    return r;
}

