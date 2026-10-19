typedef struct { float re; float im; } Cx;
typedef struct { int nA; Cx *tabA; Cx *tabB; int nC; Cx *ptsA; Cx *ptsB; int nList; int *list; } Tab3191;
typedef struct { int n; Cx *tab; } Pts3191;
typedef struct { int a; int b; } Out3191;

extern Tab3191 D_004B41D8, D_004B4628, D_004B4980, D_004B4C58, D_004B4EE8;
extern float D_004B3B68[], D_004B3B98[];
extern float *D_00491438[], *D_00491450[];
extern Pts3191 *D_004E1D00[];
extern float D_004E1BE0;

extern void func_003196B0(float *vec, int n, float *mat, float *out, int rows);
extern void func_00319910(int *in, Cx *pos, int nA, Cx *tabA, Cx *tabB,
                          int nC, Cx *ptsA, Cx *ptsB, int nList, int *list);
extern float func_00319D08(int idx, Cx *tab, int n, Cx *out);
extern int func_00323250(void);
extern void func_00319718(Out3191 *out, Cx *pos, int n, int nA, Cx *tabA, Cx *tabB,
                          int nC, Cx *ptsA, Cx *ptsB, int nList, int *list);
extern int func_00319CA0(Cx *p, Cx *pts, int n);

void func_003191F8(float *x, Out3191 *out, int n, float g)
{
    struct { float buf[12]; float res[4]; union { Tab3191 *t[4]; char c[16]; } tbl; } w;
    float *base;
    float **pp;

    float *p;
    Pts3191 **qq, **tbl;
    Out3191 *o;
    int mode;
    int i, k, i4;

    mode = func_00323250() ? 1 : 2;
    if (D_004E1BE0 < g) {
        w.tbl.t[0] = &D_004B41D8;
        base = D_004B3B68;
        pp = D_00491438;
    } else {
        w.tbl.t[0] = &D_004B4628;
        base = D_004B3B98;
        pp = D_00491450;
    }
    w.tbl.t[1] = &D_004B4980;
    w.tbl.t[2] = &D_004B4C58;
    w.tbl.t[3] = &D_004B4EE8;
    tbl = (Pts3191 **)D_004E1D00;
    for (i = 0; i < n; i++)
        w.buf[i] = x[i] - base[i];
    for (k = 0, i = 0, o = out, qq = tbl, p = w.buf; i < 6; i++) {
        i4 = i * 4;
        func_003196B0(w.buf, k, pp[i], w.res, 2);

        k += 2;
        p[0] -= w.res[0];
        p[1] -= w.res[1];
        if (i < 4) {
            Tab3191 *t = *(Tab3191 **)&w.tbl.c[i4];
            func_00319718(o, (Cx *)p, mode, t->nA, t->tabA, t->tabB, t->nC, t->ptsA, t->ptsB, t->nList, t->list);
        } else {
            int r = func_00319CA0((Cx *)p, (*qq)->tab, (*qq)->n);
            o->b = 0;
            o->a = r;
            func_00319D08(r, (*qq)->tab, (*qq)->n, (Cx *)p);
        }
        o++;
        qq++;
        *p++ += w.res[0];
        *p++ += w.res[1];
    }
    /* empty asm (no code): keeps the table address live past the loop so it is spilled and rematerialized as retail's same-register la */
    __asm__ __volatile__("" : : "X"(tbl));
    for (i = 0; i < n; i++)
        x[i] = w.buf[i] + base[i];
}

void func_003194A0(Out3191 *in, float *out, int n, float g)
{
    struct { float buf[12]; float res[4]; union { Tab3191 *t[4]; char c[16]; } tbl; } w;
    float *base;
    float **pp, **mats;
    float *p;
    int i, k, i4;

    if (D_004E1BE0 < g) {
        w.tbl.t[0] = &D_004B41D8;
        base = D_004B3B68;
        mats = D_00491438;
    } else {
        w.tbl.t[0] = &D_004B4628;
        base = D_004B3B98;
        mats = D_00491450;
    }
    w.tbl.t[1] = &D_004B4980;
    w.tbl.t[2] = &D_004B4C58;
    w.tbl.t[3] = &D_004B4EE8;
    k = 0;
    pp = mats;
    for (i = 0, i4 = 0, p = w.buf; i < 6; i++, i4 += 4) {
        if (i < 4) {
            Tab3191 *t = *(Tab3191 **)&w.tbl.c[i4];

            func_00319910(&in[i].a, (Cx *)&w.buf[i * 2], t->nA, t->tabA, t->tabB, t->nC, t->ptsA, t->ptsB, t->nList, t->list);
        } else {
            Pts3191 *q = *(Pts3191 **)((char *)D_004E1D00 + i4);
            func_00319D08(in[i].a, q->tab, q->n, (Cx *)&w.buf[i * 2]);
        }
        func_003196B0(w.buf, k, *pp, w.res, 2);
        k += 2;
        pp++;
        *p++ += w.res[0];
        { float *q2 = p; *q2++ += w.res[1]; p = q2; }
    }
    for (i = 0; i < n; i++)
        out[i] = w.buf[i] + base[i];
}
