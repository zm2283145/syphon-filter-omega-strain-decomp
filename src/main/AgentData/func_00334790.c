/* AgentData_Load 00334790 - mw38 MATCH (c62lg) */
#pragma cplusplus on
#include "types.h"
struct Cfg4110 { char pad[0x59D]; unsigned char b59D; unsigned char b59E; char pad59F[0x5A8-0x59F]; int i5A8; };
struct Mc4110 { Cfg4110 *cfg; unsigned char busy; };
struct Ent4110 { int a, b, c; char s1[0x20]; char s2[0x80]; };
struct Rec4110 { int v[8]; };
struct A4110 {
    char pad00[4];
    int i4;
    char stats[0x38];
    char pad40[0x84 - 0x40];
    int objectiveBits[8];
    char padA4[0xC8 - 0xA4];
    int nLevels;
    Rec4110 *recs;
    char padD0[0xD8 - 0xD0];
    int iD8;
    char bufDC[0x7D0];
    char name8AC[0x10];
    char b8BC[0x10];
    char b8CC[0x10];
    char b8DC[0x40];
    char b91C[0x40];
    char b95C[0x40];
    int i99C;
    int i9A0;
    void *p9A4;
    char b9A8[0x100];
    char padAA8[0xB68 - 0xAA8];
    unsigned char bB68;
    char padB69[0xB70 - 0xB69];
    unsigned char bB70;
    char padB71;
    unsigned char bB72;
    unsigned char bB73;
};
extern "C" {
extern char *D_0052FDF0;
extern int D_0052AFD0[];
extern int D_00533870;
extern void *D_004FFC04;
extern Mc4110 D_0055A830;
extern int D_0052FE80;
extern Ent4110 D_0052FE90[];
extern char *D_004926D0;
extern char D_005329A0[];
extern char D_004B92B0[];
void *memcpy(void *d, const void *s, unsigned int n);
int strlen(const char *s);
void func_002C8090(void *p);
int func_00334780(void);
int AgentFile_EncodeName(const char *in, char *out, int digit, unsigned int max);
int MemCardWrap_Write(Mc4110 *mc, char *name, void *buf, int size, int flag);
int MemCardWrap_Read(Mc4110 *mc, char *name, void *buf, int size);
void String_Copy(char *d, const char *s);
void *memset(void *d, int c, unsigned int n);
void AgentData_Reset(void *self);
void awards_SetAwardsAndBonuses(void *self, int a, int b);
extern char D_0052FE00[];
extern int D_004FFBBC;
}
static inline bool Idle4110(Mc4110 *m) { return !m->busy; }
static inline void WInt4110(int v) { *(int *)D_0052FDF0 = v; D_0052FDF0 += 4; }
static inline void WBuf4110(const void *p, int n) { memcpy(D_0052FDF0, p, n); D_0052FDF0 += n; }
static inline bool Ready4110(Mc4110 *m) { return m->cfg->b59D && m->cfg->b59E; }
static inline int RInt4110(void) { int v = *(int *)D_0052FDF0; D_0052FDF0 += 4; return v; }
static inline void RBuf4110(void *p, int n) { memcpy(p, D_0052FDF0, n); D_0052FDF0 += n; }
static inline void RStr4110(char *dst) { int n = RInt4110(); memcpy(D_0052FE00, D_0052FDF0, n); D_0052FDF0 = (char *)((int *)D_0052FDF0 + ((unsigned int)(n + 3) >> 2)); String_Copy(dst, D_0052FE00); }
extern "C" int AgentData_Load(A4110 *self, char *name, int digit)
{
    char tmp[0x80];
    Ent4110 blank;
    bool ok;
    int r;
    Mc4110 *mc;
    int cnt;
    int a;
    char *fn;
    int q;
    int d;
    Ent4110 *e;
    int n;
    int len;
    int sum;
    int y;
    int *end;
    char *buf;
    int j;
    char k;
    char step;
    int i;
    d = digit;
    if (name == 0) name = self->name8AC;
    if (d < 0) d = self->i4;
    if (AgentFile_EncodeName(name, D_005329A0, d, 0x20)) fn = D_005329A0;
    else fn = D_004B92B0;
    r = 1;
    AgentData_Reset(self);
    mc = &D_0055A830;
    if (Idle4110(mc) && Ready4110(mc)) {
        D_0052FDF0 = (char *)D_0052AFD0;
        ok = MemCardWrap_Read(mc, fn, D_0052FDF0, 0x4E20) != 0;
        if (ok) {
            D_004FFBBC = mc->cfg->i5A8;
            *(int *)self->pad00 = RInt4110();
            if (*(int *)self->pad00 >= 0xC) {
                D_0052FDF0 += 4;
                len = strlen(D_004926D0);
                y = 0;
                buf = (char *)D_0052AFD0;
                k = buf[4];
                step = buf[5];
                for (i = 8; i < 20000; i++) {
                    buf[i] ^= (char)(k + D_004926D0[y]);
                    y++;
                    if (y >= len) {
                        y = 0;
                        k += step;
                    }
                }
            }
            if (*(int *)self->pad00 >= 0xB) RBuf4110(self->stats, 0x38);
            else RBuf4110(self->stats, 0x1C);
            for (a = 0; a < func_00334780(); a++) self->objectiveBits[a] = RInt4110();
            RBuf4110(self->name8AC, 0x10);
            RBuf4110(self->b8CC, 0x10);
            RBuf4110(self->b8BC, 0x10);
            if (*(int *)self->pad00 >= 0x10) {
                RBuf4110(tmp, 0x40);
                String_Copy(self->b8DC, tmp);
                RBuf4110(tmp, 0x80);
                String_Copy(self->b91C, tmp);
                self->i99C = RInt4110();
                RBuf4110(tmp, 0x40);
                String_Copy(self->b95C, tmp);
                self->i9A0 = RInt4110();
            } else {
                RStr4110(self->b8DC);
                RStr4110(self->b91C);
                self->i99C = RInt4110();
                RStr4110(self->b95C);
                self->i9A0 = RInt4110();
            }
            if (*(int *)self->pad00 >= 4) RBuf4110(self->p9A4, 0x440);
            if (*(int *)self->pad00 >= 0xA) RBuf4110(self->b9A8, 0x100);
            if (*(int *)self->pad00 >= 6) self->iD8 = RInt4110();
            else self->iD8 = 0;
            if (*(int *)self->pad00 >= 5) RBuf4110(self->bufDC, 0x7D0);
            else memset(self->bufDC, 0, 0x7D0);
            if (*(int *)self->pad00 >= 8) {
                for (i = 0; i < self->nLevels; i++) RBuf4110(&self->recs[(unsigned int)i], 0x20);
            }
            if (*(int *)self->pad00 >= 0xD) {
                memcpy(&self->bB68, D_0052FDF0, 1);
                D_0052FDF0 += 4;
            }
            if (*(int *)self->pad00 >= 0xE) {
                cnt = RInt4110();
                if (cnt > 0x40) return 2;
                D_0052FE80 = cnt;
                for (q = 0, e = D_0052FE90; q < 0x40; q++, e++) {
                    if (q < cnt) RBuf4110(e, sizeof(Ent4110));
                    else RBuf4110(&blank, sizeof(Ent4110));
                }
            }
            if (*(int *)self->pad00 >= 0x11) {
                sum = 0;
                end = (int *)D_0052FDF0;
                n = end - D_0052AFD0;
                for (j = 0; j < n; j++) sum ^= (D_0052AFD0)[j];
                if (sum != RInt4110()) return 2;
            }
            self->i4 = digit;
            if (*(int *)self->pad00 >= 3) awards_SetAwardsAndBonuses(self, 0, 1);
            self->bB72 = 0;
            self->bB73 = 0;
            self->bB70 = 1;
            r = 0;
        }
    }
    return r;
}


