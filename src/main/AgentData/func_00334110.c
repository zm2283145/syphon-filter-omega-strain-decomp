/* AgentData_Save 00334110 - mw38 MATCH (c62lg) */
#pragma cplusplus on
#include "types.h"
struct Cfg4110 { char pad[0x59D]; unsigned char b59D; };
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
    char padB69[0xB72 - 0xB69];
    unsigned char bB72;
    unsigned char bB73;
};
extern "C" {
extern char *D_0052FDF0;
extern int D_0052AFD0[];
extern int g_TimerAccum;
extern void *D_004FFC04;
extern Mc4110 g_MemCard;
extern int D_0052FE80;
extern Ent4110 D_0052FE90[];
extern char *D_004926D0;
extern char D_005329A0[];
extern char D_004B92B0[];
void *memcpy(void *d, const void *s, unsigned int n);
int strlen(const char *s);
void FrontEnd_FlushMessages(void *p);
int func_00334780(void);
int AgentFile_EncodeName(const char *in, char *out, int digit, unsigned int max);
int MemCardWrap_Write(Mc4110 *mc, char *name, void *buf, int size, int flag);
}
static inline bool Idle4110(Mc4110 *m) { return !m->busy; }
static inline void WInt4110(int v) { *(int *)D_0052FDF0 = v; D_0052FDF0 += 4; }
static inline void WBuf4110(const void *p, int n) { memcpy(D_0052FDF0, p, n); D_0052FDF0 += n; }
extern "C" int AgentData_Save(A4110 *self)
{
    int a;
    int b;
    int q;
    Ent4110 *e;
    char *start;
    Mc4110 *mc;
    int r;
    Ent4110 blank;
    int n;
    int len;
    int sum;
    int y;
    char *buf;
    int j;
    char k;
    char step;
    int i;
    r = 0;
    if (self->name8AC[0] != 0) {
        FrontEnd_FlushMessages(D_004FFC04);
        mc = &g_MemCard;
        if (Idle4110(mc) && mc->cfg->b59D) {
            D_0052FDF0 = (char *)D_0052AFD0;
            start = D_0052FDF0;
            WInt4110(0x11);
            { int t = *(int *)0x10000800 + g_TimerAccum; t += t << 16; WInt4110(t ^ 0xFFFF); }
            WBuf4110(self->stats, 0x38);
            for (a = 0; a < func_00334780(); a++) WInt4110(self->objectiveBits[a]);
            WBuf4110(self->name8AC, 0x10);
            WBuf4110(self->b8CC, 0x10);
            WBuf4110(self->b8BC, 0x10);
            WBuf4110(self->b8DC, 0x40);
            WBuf4110(self->b91C, 0x80);
            WInt4110(self->i99C);
            WBuf4110(self->b95C, 0x40);
            WInt4110(self->i9A0);
            WBuf4110(self->p9A4, 0x440);
            WBuf4110(self->b9A8, 0x100);
            WInt4110(self->iD8);
            WBuf4110(self->bufDC, 0x7D0);
            for (i = 0; i < self->nLevels; i++) WBuf4110(&self->recs[(unsigned int)i], 0x20);
            memcpy(D_0052FDF0, &self->bB68, 1);
            D_0052FDF0 += 4;
            WInt4110(D_0052FE80);
            for (q = 0, e = D_0052FE90; q < 0x40; q++, e++) {
                if (q < D_0052FE80) WBuf4110(e, sizeof(Ent4110));
                else WBuf4110(&blank, sizeof(Ent4110));
            }
            sum = 0;
            n = (int *)D_0052FDF0 - D_0052AFD0;
            for (j = 0; j < n; j++) sum ^= (D_0052AFD0)[j];
            WInt4110(sum);
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
            n = ((int *)D_0052FDF0 - D_0052AFD0) * 4;
            r = MemCardWrap_Write(mc, AgentFile_EncodeName(self->name8AC, D_005329A0, self->i4, 0x20) ? D_005329A0 : D_004B92B0,
                                  start, n, 1) != 0;
            self->bB72 = 0;
            self->bB73 = 0;
        }
    }
    return r;
}







