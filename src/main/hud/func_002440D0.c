typedef struct { float v[4]; } Vec4;
typedef struct { char pad[0x10]; float m[4][4]; } Obj;
extern int D_004F7DA0[];
extern Vec4 func_003ECB50(int a, float b);

void func_002440D0(Obj* p)
{
    int i;
    Vec4 v;
    for (i = 0; i < 4; i++) {
        v = func_003ECB50(D_004F7DA0[i], 10.0f);
        p->m[i][0] = v.v[0];
        p->m[i][1] = v.v[1];
        p->m[i][2] = v.v[2];
        p->m[i][3] = v.v[3];
    }
}
