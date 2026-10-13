typedef struct { int w[32]; } B_002F4A38;
extern void *memset(void *, int, unsigned int);
extern void *memcpy(void *, const void *, unsigned int);
extern void func_002F14E8(B_002F4A38 *, B_002F4A38 *, B_002F4A38 *, B_002F4A38 *);
void func_002F4A38(void *m, void *x, void *y, void *out)
{
    B_002F4A38 a;
    B_002F4A38 b;
    B_002F4A38 c;
    B_002F4A38 r;
    memcpy(&a, x, 0x40);
    memset(&a.w[16], 0, 0x40);
    memcpy(&b, m, 0x40);
    memset(&b.w[16], 0, 0x40);
    memcpy(&c, y, 0x40);
    memset(&c.w[16], 0, 0x40);
    func_002F14E8(&r, &c, &a, &b);
    memcpy(out, &r, 0x40);
}
