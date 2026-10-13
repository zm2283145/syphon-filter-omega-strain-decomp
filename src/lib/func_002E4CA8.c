#define F(p,T,o) (*(T *)((char *)(p) + (o)))
typedef struct { unsigned int slot; int a, b, c; int d; } R2E4CA8;
extern void (*D_0048C470)(R2E4CA8 *);
extern int D_0048C474;
extern unsigned char D_0048C4AC;
extern int D_0048C4B0;
extern unsigned char D_0048C4B4;
extern char D_00522758[];
extern int D_0058D17C;
extern char D_0058DF80[];
extern void *memset(void *, int, unsigned int);
extern int func_002E51B8(unsigned int, void **);
extern int func_002E52D8(unsigned int, unsigned int, void **);
extern int func_00314CB0(unsigned int);
/* callees return int (value ignored): keeps $v0 busy after each call, as in retail */
extern int func_00314A98(unsigned int);
extern int func_00303598(int);
extern int func_00303688(int);
extern int func_003060C0(void *);
extern int func_003060F0(void *, unsigned int *);
extern int func_002DCD00(unsigned int);
extern int func_002FBA98(int);
int func_002E4CA8(unsigned int slot)
{
    R2E4CA8 r;
    void *p = 0;
    unsigned int t;
    void *q = 0;
    unsigned int i;
    int ret;
    if (slot >= 4) return 0x17;
    ret = func_002E51B8(slot, &p);
    if (ret != 0) return ret;
    if (p != 0) {
        memset(&r, 0, sizeof r);
        r.slot = slot;
        r.d = D_0048C474;
        r.a = 0;
        r.b = 0;
        r.c = 0;
        if (func_00314CB0(slot) == 1) func_00314A98(slot);
        if (F(p, int, 0x438) - 1U < 3) {
            if (D_0048C4AC && slot == 0) {
                func_00303598(D_0048C4B0);
                if (D_0048C470 == 0) {
                    func_003060C0(D_00522758);
                    do {
                        func_00303688(D_0048C4B0);
                        func_003060F0(D_00522758, &t);
                    } while (t < 500);
                } else {
                    func_003060C0(D_00522758);
                    D_0048C4B4 = 1;
                }
            }
            if (slot != 0) {
                func_002FBA98(func_002DCD00(slot));
                if (D_0048C470) D_0048C470(&r);
            }
        }
        for (i = 0; i < 0x100; i++) {
            func_002E52D8(slot, i, &q);
            if (q) memset(q, 0, 0x2C);
        }
        {
            char *s = p;
            F(s, int, 0x400) = 0x100;
            F(s, int, 0x404) = 0x100;
            F(s, int, 0x428) = 0;
            F(s, int, 0x42C) = 0;
            F(s, int, 0x430) = 0;
            F(s, int, 0x434) = 0;
            F(s, int, 0x43C) = -1;
            F(s, int, 0x440) = 0;
            F(s, int, 0x438) = 0;
        }
        memset(D_0058DF80, 0, 4);
        D_0058D17C = 0;
        return 0;
    }
    return ret;
}