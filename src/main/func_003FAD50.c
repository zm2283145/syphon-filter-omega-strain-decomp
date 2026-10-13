extern int Net_SendLocked(char type, int session, int target, int flags, int a, int b, void *c);
extern void printf(const char *fmt, ...);
extern int DME_Update(void);
extern int func_0042B1A0(int);
extern char *strncpy(char *d, const char *s, unsigned int n);

extern unsigned char D_005721D0;
extern unsigned char D_0055C9E0;
extern int D_0055C9D8;
extern int D_0055C9A0;
extern int D_0055C9A4[4];
extern int D_0055C9A8;
extern int D_0055C9AC;
extern int D_0055C9B0;
extern unsigned char D_0055C780[];
extern int D_005721A8;
extern char D_005723B0;
extern char D_005721D8;
extern char D_005721E0[];
extern char D_005721F0;
extern char D_004BE2B0[];
extern char D_004BE2E0[];
extern char D_004BE320[];
extern char D_004BE330[];

unsigned char NetObj_SendMessage(int a, int b, void *c, int target, int type)
{
    unsigned char ok;
    int r;
    int r2;
    unsigned char st;

    ok = 0;
    if (D_005721D0) {
        if (D_0055C9E0 || D_0055C9D8 + 1000 < func_0042B1A0(1)) {
            D_0055C9D8 = func_0042B1A0(1);
            D_0055C9A0 = 0;
            D_0055C9A4[0] = 0;
            D_0055C9A8 = 0;
            D_0055C9AC = 0;
            D_0055C9B0 = 0;
            D_0055C9E0 = 0;
        }
        if (target > -1) {
            st = D_0055C780[target];
            if (st != 1 && st != 2) {
                return 0;
            }
        }
        r = Net_SendLocked(type, D_005721A8, target == -1 ? -1 : target, 2, a, b, c);
        if (r == 0) {
            ok = 1;
        } else {
            if (!DME_Update() && type != 0x40) {
                r2 = Net_SendLocked(type, D_005721A8, target == -1 ? -1 : target, 2, a, b, c);
                if (r2 == 0) {
                    ok = 1;
                } else {
                    printf(D_004BE2B0, r2);
                }
            }
            if (r == 0x25 || r == 0x23) {
                if (target == -1) {
                    D_0055C9A0++;
                    if (D_0055C9A0 > 25) {
                        printf(D_004BE2E0);
                        D_005723B0 = 0;
                        D_005721D8 = 1;
                        strncpy(D_005721E0, D_004BE320, 0x10);
                        D_005721F0 = 0;
                    }
                } else {
                    D_0055C9A4[target]++;
                    if (D_0055C9A4[target] > 25) {
                        printf(D_004BE330);
                        D_005723B0 = 0;
                        D_005721D8 = 1;
                        strncpy(D_005721E0, D_004BE320, 0x10);
                        D_005721F0 = 0;
                    }
                }
            }
        }
    }
    return ok;
}
