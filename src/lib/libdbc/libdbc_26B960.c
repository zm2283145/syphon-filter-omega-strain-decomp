/*
 * lib/libdbc: 5 files, 0026B960-0026BB28
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0026B960 */
typedef struct { int f0; int f4; int f8; int fc; char pad[0x334 - 0x10]; } E26B960;
extern E26B960 D_004FBB88[];
typedef struct { char pad[0x7C]; int f7c; } R26B960;
extern R26B960* scePad2GetSide(int port);
int scePad2CheckDma(int port)
{
    R26B960* r = scePad2GetSide(port);
    int v = r->f7c;
    if (v == 0) return 0;
    if (v == D_004FBB88[port].f8) return 0;
    D_004FBB88[port].f8 = v;
    return 1;
}
/* merge_units: end func_0026B960 */

/* merge_units: begin func_0026B9C0 */
typedef struct { int on; int w; int a; int b; } DbcBit;

int scePad2SetButtonOrder(unsigned char *bits, DbcBit *o)
{
    int i, bit = 0, a = 0, b = 0;
    for (i = 0; i < 40; i++, o++) {
        if ((*bits >> bit) & 1) {
            o->on = 1;
            o->a = a;
            o->b = b;
            if ((unsigned int)(i - 16) < 16 || (unsigned int)(i - 35) < 4) {
                o->w = 8;
                a++;
            } else {
                b++;
                o->w = 1;
                if ((b & 7) == 0) {
                    a++;
                    b = 0;
                }
            }
        } else {
            o->on = 0;
            o->a = 0;
            o->b = 0;
        }
        bit++;
        if ((bit & 7) == 0) {
            bits++;
            bit = 0;
        }
    }
    return 1;
}
/* merge_units: end func_0026B9C0 */

/* merge_units: begin func_0026BA70 */
extern char D_004A87D8[];
extern char D_004A87E0[];
extern char D_004A87E8[];
extern char D_004A87F0[];
static void * const dat_0048B260[4] = { (void*)D_004A87F0, (void*)D_004A87E8, (void*)D_004A87E0, (void*)D_004A87D8 };
extern char D_004A87F8[];
extern void Libc_Strcpy(char* d, char* s);
void scePad2StateIntToStr(unsigned int i, char* dst)
{
    if (i < 4) {
        Libc_Strcpy(dst, ((char**)dat_0048B260)[i]);
        return;
    }
    dst[0] = D_004A87F8[0];
}
/* merge_units: end func_0026BA70 */

/* merge_units: begin func_0026BAA8 */
typedef struct {
    unsigned long cmd : 14;
    unsigned long mode : 2;
    unsigned long len : 8;
    unsigned long dev : 8;
} DbcCmd_baa8;

extern int sceDbcReceiveData(int port, DbcCmd_baa8 cmd, int *len, unsigned char *out);

int sceVibGetProfile(int port, unsigned char *out)
{
    int buf;
    int r;
    DbcCmd_baa8 c;

    c.cmd = 2;
    c.mode = 2;
    c.len = 3;
    c.dev = 1;
    r = sceDbcReceiveData(port, c, &buf, out);
    if (r < 0) return r;
    return buf;
}
/* merge_units: end func_0026BAA8 */

/* merge_units: begin func_0026BB28 */
typedef struct {
    unsigned long cmd : 14;
    unsigned long mode : 2;
    unsigned long len : 8;
    unsigned long dev : 8;
} DbcCmd_bb28;

extern void *memcpy(void *, const void *, unsigned int);
extern int sceDbcSendData2(int port, DbcCmd_bb28 cmd, int *len, void *in);

int sceVibSetActParam(int port, int len2, void *src2, int len1, void *src1)
{
    struct {
        int len2;
        int len1;
        unsigned char data[40];
    } pkt;
    int size;
    DbcCmd_bb28 c;

    c.cmd = 11;
    c.mode = 1;
    c.len = 3;
    size = sizeof(pkt.data);
    c.dev = 1;
    pkt.len1 = len1;
    memcpy(pkt.data, src1, len1);
    pkt.len2 = len2;
    memcpy(pkt.data + len1, src2, len2);
    return sceDbcSendData2(port, c, &size, &pkt);
}
/* merge_units: end func_0026BB28 */
