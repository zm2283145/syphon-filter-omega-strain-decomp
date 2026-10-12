#define F(p,o,T) (*(T *)((char *)(p)+(o)))
typedef struct { int w[16]; } Blob;
extern int func_00358678(void);
extern void *func_00357D50(int);
extern void func_00357D88(void *);
extern void *memset(void *, int, unsigned int);
extern void func_003581C0(void);
extern int func_00358158(void);
extern int func_00358578(int);
extern int func_0034ACC8(void *, int, void *);
extern int func_0034AD40(void *, int, int, int);

int func_003590C0(void *ctx, void *s)
{
    int r = func_00358678();
    void *n = func_00357D50(0x6C);
    void *t;
    if (n == 0) return 0xC;
    memset(n, 0, 0x6C);
    F(n,8,int) = r;
    F(n,16,Blob) = F(s,16,Blob);
    F(n,0x60,int) = -1;
    F(n,0x64,int) = -1;
    F(n,0x68,int) = -1;
    t = F(s,0x54,void *);
    F(n,4,void *) = t;
    if (t) F(t,0,void *) = n;
    else F(s,0x50,void *) = n;
    F(n,0,void *) = 0;
    F(s,0x54,void *) = n;
    func_003581C0();
    r = func_0034ACC8((char *)ctx + 0x14, F(ctx,0x54,int), (char *)n + 0x10);
    if (func_00358158() < 0) return -1;
    if (r <= 0) {
        if (F(n,0,void *)) F(F(n,0,void *),4,void *) = F(n,4,void *);
        else F(s,0x54,void *) = F(n,4,void *);
        if (F(n,4,void *)) F(F(n,4,void *),0,void *) = F(n,0,void *);
        else F(s,0x50,void *) = F(n,0,void *);
        func_00357D88(n);
        goto err;
    }
    F(n,0xC,int) = r;
    func_003581C0();
    r = func_0034AD40((char *)ctx + 0x14, F(ctx,0x54,int), F(n,0xC,int), 0);
    if (func_00358158() < 0) return -1;
    if (r < 0 && r != -500) {
    err:
        return func_00358578(r);
    }
    return 0;
}


