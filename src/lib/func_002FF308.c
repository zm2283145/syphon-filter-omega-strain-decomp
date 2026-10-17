typedef struct { unsigned short id; char pad[6]; int f8; } O;
typedef struct { char pad[5]; unsigned char f5; unsigned short f6; char pad2[0x48]; char ring[4]; } P;
typedef struct { unsigned char type; char p1; unsigned short len; } H;
extern int D_004908F8[];
extern int func_002FE720(O *);
extern int func_002FE8B0(P *);
extern int func_002F59F8(void *, unsigned char *);
extern int func_002F5748(void *, int, int);
extern int func_002F5840(void *, unsigned int *);
extern int func_002FF4D8(O *, P *, unsigned char, unsigned int, unsigned short);
extern int func_002F53B8(void *, unsigned int);
extern int func_002F5918(void *, unsigned int *);
extern int func_00300A58(unsigned int, H *, unsigned short *);
int func_002FF308(O *o, P *p)
{
    H h;
    unsigned char full;
    unsigned short len;
    unsigned int avail;
    unsigned int data;
    int r;
    int one;
    void *q;
    int st;
    unsigned int n;
    data = 0;
    avail = 0;
    len = 0;
    one = func_002FE720(o);
    if (one != 1) return 2;
    if (func_002FE8B0(p) != one) return 2;
    if (p->f5 != 1) return 2;
    if (o->id != p->f6) return 2;
    q = p->ring;
    if (func_002F59F8(q, &full)) return 0x15;
    if (full == 1) {
        if (func_002F5748(q, 1, D_004908F8[0])) return 0x15;
    }
    if (func_002F5840(q, &avail) == 0) goto ok1;
err:
    return 0x15;
ok1:
    if (avail < 3) goto done;
    st = o->f8;
    goto next;
loop:
    data += len;
    r = func_002FF4D8(o, p, h.type, data, h.len);
    if (r) return r;
    if (func_002F53B8(q, n)) goto err;
    if (func_002F5840(q, &avail)) goto err;
    if (avail < 3) goto done;
    if (st != o->f8) goto done;
next:
    if (func_002F5918(q, &data)) goto err;
    r = func_00300A58(data, &h, &len);
    if (r) return r;
    n = len + h.len;
    if (h.len != 0 && (h.type & 0x80)) n += 4;
    if (avail >= n) goto loop;
done:
    return 0;
}
