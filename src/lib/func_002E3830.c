/* EE soft-float double libcalls are aliased to their retail functions. */
__asm__("dpcmp = SoftFloat_UnpackAndCompare\n"
        "dpmul = func_0011C268\n"
        "dpadd = func_0011C1A8\n"
        "dpsub = func_0011C200\n"
        "fptodp = SoftFloat_FloatToDouble");

typedef struct {
    char pad0[0xC];
    unsigned int type;
    int pad10;
    int mode;
    float thr;
} Cmp2E3830;

#define ABS(x) ((x) < 0 ? -(x) : (x))
#define SQ(x) ((x) * (x))

int func_002E3830(Cmp2E3830* c, void* pa, void* pb)
{
    int ret = 0;
    if (c == 0) return ret;
    if (pa == 0) return ret;
    if (pb == 0) return ret;
    switch (c->type) {
    case 0: {
        signed char x = *(signed char*)pa, y = *(signed char*)pb;
        signed char d = x - y < 0 ? y - x : x - y;
        if (c->mode == 1)
            return d != 0;
        return (signed char)c->thr < d;
    }
    case 1: {
        unsigned char x = *(unsigned char*)pa, y = *(unsigned char*)pb;
        unsigned char d = x - y < 0 ? y - x : x - y;
        if (c->mode == 1)
            return d != 0;
        return (unsigned char)c->thr < d;
    }
    case 2: {
        short x = *(short*)pa, y = *(short*)pb;
        short d = x - y < 0 ? y - x : x - y;
        if (c->mode == 1)
            return d != 0;
        return (short)c->thr < d;
    }
    case 3: {
        unsigned short x = *(unsigned short*)pa, y = *(unsigned short*)pb;
        unsigned short d = x - y < 0 ? y - x : x - y;
        if (c->mode == 1)
            return d != 0;
        return (unsigned short)c->thr < d;
    }
    case 4: {
        int d = ABS(*(int*)pa - *(int*)pb);
        if (c->mode == 1)
            return d != 0;
        return (int)c->thr < d;
    }
    case 5: {
        unsigned int d = *(unsigned int*)pa - *(unsigned int*)pb;
        if (c->mode == 1)
            return d != 0;
        return (unsigned int)c->thr < d;
    }
    case 6: {
        float d = ABS(*(float*)pa - *(float*)pb);
        if (c->mode == 1)
            return d != 0.0f;
        return c->thr < d;
    }
    case 7: {
        double d = ABS(*(double*)pa - *(double*)pb);
        if (c->mode == 1)
            return d != 0.0;
        return d > c->thr;
    }
    case 8: {
        short* a = pa; short* b = pb;
        int dx = a[0] - b[0];
        int dy = a[1] - b[1];
        return !((float)(dx * dx + dy * dy) <= c->thr * c->thr);
    }
    case 9: {
        short* a = pa; short* b = pb;
        int dx = a[0] - b[0];
        int dy = a[1] - b[1];
        int dz = a[2] - b[2];
        return !((float)(dx * dx + dy * dy + dz * dz) <= c->thr * c->thr);
    }
    case 10: {
        int* a = pa; int* b = pb;
        int dx = a[0] - b[0];
        int dy = a[1] - b[1];
        return !((float)(dx * dx + dy * dy) <= c->thr * c->thr);
    }
    case 11: {
        int* a = pa; int* b = pb;
        int dx = a[0] - b[0];
        int dy = a[1] - b[1];
        int dz = a[2] - b[2];
        return !((float)(dx * dx + dy * dy + dz * dz) <= c->thr * c->thr);
    }
    case 12: {
        float* a = pa; float* b = pb;
        float dx = a[0] - b[0];
        float dy = a[1] - b[1];
        return !(dx * dx + dy * dy <= c->thr * c->thr);
    }
    case 13: {
        float* a = pa; float* b = pb;
        float dx = a[0] - b[0];
        float dy = a[1] - b[1];
        float dz = a[2] - b[2];
        return !(dx * dx + dy * dy + dz * dz <= c->thr * c->thr);
    }
    case 14: {
        double* a = pa; double* b = pb;
        return !(SQ(a[0] - b[0]) + SQ(a[1] - b[1]) <= (double)(c->thr * c->thr));
    }
    case 15: {
        double* a = pa; double* b = pb;
        return !(SQ(a[0] - b[0]) + SQ(a[1] - b[1]) + SQ(a[2] - b[2]) <= (double)(c->thr * c->thr));
    }
    }
    return ret;
}
