typedef struct { int state; int x4; int x8; int pad[5]; int x20; int x24; } CtxC960;
extern CtxC960 D_0051ECC0;
extern int Libc_Strncmp(const char *, const char *, int);
extern int create_mc2_socket(int);
extern int sceMc2GetInfo(int, int);
extern int sceMc2GetDir(int, int, int, int, int *, int *);
extern void delete_mc2_socket(void);
int my_open(const char *name, int a1, int a2, int a3, int *out)
{
    int buf[16];
    int n;
    int r;
    if (create_mc2_socket(Libc_Strncmp(name, "mc1", 3) == 0 ? 3 : 2) < 0) return -1;
    r = sceMc2GetInfo(D_0051ECC0.x20, 0);
    if (r < 0 && (r & 0xFFFF) != 0x9003) {
        delete_mc2_socket();
        return -1;
    }
    if (sceMc2GetDir(D_0051ECC0.x20, a1, 0, 1, buf, &n) < 0) {
        delete_mc2_socket();
        return -1;
    }
    *out = 0;
    if (n == 1) *out = buf[4];
    return D_0051ECC0.x24;
}