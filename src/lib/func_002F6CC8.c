typedef struct { int type; int x4; unsigned char b8; } SockCfg;
typedef struct { long long x0; int x8; int xC; int x10[4]; int x20; int pad[9]; } SockDesc;
typedef struct { int pad[8]; unsigned short port; short pad22; int rest[10]; } SockInfo;
extern unsigned char D_004908A0[];
extern char D_00525600[];
extern char D_00525640[];
extern void *memset(void *, int, unsigned int);
extern int func_0034AA50(char *, char *, int, int *, char *, int, int);
extern int func_0034BE80(char *, char *, int *, SockDesc *);
extern int func_0034BFA8(char *, char *, int, int);
extern int func_0034C168(char *, char *, int, int);
extern int func_0034C690(char *, char *, int, int, void *, int);

int Socket_Construct(int *out, char *host, unsigned short *port, SockCfg *cfg, unsigned char *flag)
{
    SockDesc p;
    SockInfo info;
    int sock = 0;
    int one;
    int timeout;
    int t;
    int r;

    if (!out) return 2;
    *out = 0;
    if (D_004908A0[0] != 1) return 5;
    if (!cfg) return 2;
    if (!flag) return 2;
    *flag = 0;
    if (cfg->type == 0 && !host) return 2;
    if (cfg->type != 3 && *port == 0) return 2;
    memset(&p, 0, sizeof(p));
    t = cfg->type;
    if (t == 0) {
        if (!host) return 2;
        p.xC = -1;
        p.x20 = *port;
        p.x8 = 1;
        if (func_0034AA50(D_00525600, D_00525640, 0, p.x10, host, 0, 0) < 0) return 1;
        timeout = cfg->b8 != 1 ? 10000 : 0;
    } else if (t == 1) {
        if (host) return 2;
        if (cfg->x4 <= 0) return 2;
        if (*port == 0)
            p.xC = -1;
        else
            p.xC = *port;
        p.x0 = cfg->x4;
        timeout = 10000;
        p.x20 = 0;
        p.x8 = 0;
    } else if (t == 3) {
        if (host) return 2;
        p.xC = 1;
        p.x8 = t;
        timeout = 10000;
        p.x20 = 0;
        if (func_0034AA50(D_00525600, D_00525640, 0, p.x10, 0, 0, 0) < 0) return 1;
    } else if (t == 2) {
        if (host) return 2;
        p.xC = *port;
        timeout = 0;
        p.x8 = t;
        p.x20 = 0;
        if (func_0034AA50(D_00525600, D_00525640, 0, p.x10, 0, 0, 0) < 0) return 1;
    } else
        return 3;
    if (func_0034BE80(D_00525600, D_00525640, &sock, &p) != 0) return 1;
    r = func_0034BFA8(D_00525600, D_00525640, sock, timeout);
    if (r != 0) {
        if (r != -500 || cfg->type != 2) {
            func_0034C168(D_00525600, D_00525640, sock, 500);
            return 1;
        }
    }
    if (cfg->type == 0 || cfg->type == 2) {
        one = 1;
        if (func_0034C690(D_00525600, D_00525640, sock, 3, &one, 4) != 0) return 1;
    }
    if (cfg->type == 1 && *port == 0) {
        memset(&info, 0, sizeof(info));
        if (func_0034C690(D_00525600, D_00525640, sock, 1, &info, sizeof(info)) != 0) return 1;
        *port = info.port;
    }
    if (cfg->type == 0 && cfg->b8 == 1)
        *flag = 0;
    else
        *flag = 1;
    *out = sock;
    return 0;
}
