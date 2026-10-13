typedef struct Req444 {
    char kind[0x15];
    char name[0x40];
    char data[0x18];
    char pad6D[0x155 - 0x6D];
    char str[0x178 - 0x155];
    int a;          /* 0x178 */
    int b;          /* 0x17C */
    int c;          /* 0x180 */
    int d;          /* 0x184 */
    int e;          /* 0x188 */
    int f;          /* 0x18C */
    int g;          /* 0x190 */
    int h;          /* 0x194 */
    int i;          /* 0x198 */
    int j;          /* 0x19C */
    char pad1A0[0x1D0 - 0x1A0];
    int one;        /* 0x1D0 */
} Req444;
extern void* memset(void* d, int c, unsigned int n);
extern void* memcpy(void* d, const void* s, unsigned int n);
extern void String_Copy(char* d, const char* s);
extern int func_002D0A38(Req444* r, void* cb);
extern void func_002EBC48(int* t);
extern int func_004446E0(int x);
extern void func_00452F70(int h, int a, int b);
extern void func_004446A0(void);
extern char D_004C0B38[];
extern char D_00584398[];
extern char D_005843B4[];
extern int D_0058423C;
extern int D_005844F4;
extern int D_005844F8;
extern int D_005844FC;
extern int D_00584528;
extern int D_00585E60;
static inline unsigned char Poll444(void) {
    int now = 0;
    func_002EBC48(&now);
    if (now - D_00584528 > 30000) return 0;
    func_00452F70(D_00585E60, 0, 0);
    return 1;
}
int func_00444460(const char* name, const void* data, const char* str, int a, int b, int c, int d, int e,
                  int f, int g, int h, int i, int j) {
    Req444 req;
    memset(&req, 0, sizeof(req));
    String_Copy(req.kind, D_004C0B38);
    String_Copy(req.name, name);
    memcpy(req.data, data, 0x18);
    String_Copy(req.str, str);
    req.one = 1;
    req.f = f;
    req.a = a;
    req.g = g;
    req.h = h;
    req.i = i;
    req.j = j;
    req.e = e;
    req.b = b;
    req.c = c;
    req.d = d;
    memset(D_00584398, 0, 0x180);
    D_005844F4 = c;
    D_005844F8 = b;
    D_005844FC = d;
    String_Copy(D_005843B4, name);
    D_0058423C = 0;
    if (func_002D0A38(&req, func_004446A0)) return 0;
    D_00584528 = 0;
    func_002EBC48(&D_00584528);
    func_00452F70(D_00585E60, 2, 1);
    while (!D_0058423C) {
        if (!Poll444()) return 0;
        if (func_004446E0(0)) return 0;
    }
    return D_0058423C == 1;
}


