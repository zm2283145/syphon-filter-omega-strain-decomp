typedef struct { float x, y, z, w; } V4_4D5670;
typedef struct {
    char pad0[0xD0];
    int xD0;
    char padD4[0xE0 - 0xD4];
    char qE0[0x10];
    V4_4D5670 vF0;
    int x100;
    char pad104[0x110 - 0x104];
    char x110[0x40];
    char x150[0x10];
    int x160;
    int x164;
} O_4D5670;
extern int D_004BCD60;
extern float D_004BCD68;
extern char D_005429F0[];
extern int D_00542AC0;
extern char D_005429E0[];
extern char D_004BCF50[];
extern char D_004BCF70[];
extern void* D_00542B60;
extern void* D_00542B68;
extern void __register_global_object(void* obj, void* dtor, void* link);
extern char func_00396340[];
void func_003BA210(void* p);
void func_0017F820(void* p);
void func_00132800(void* d, void* s);
V4_4D5670* Vec4_GetZero(void);
void Vec4_Assign(V4_4D5670* d, V4_4D5670* s);
void func_003BA1B0(void* d, V4_4D5670* s);
void func_00132840(void* p);

static inline float Sqrt_4D5670(float x)
{
    float r;
    asm { sqrt.s r, x }
    return r;
}

void func_004D5670(void)
{
    char tmp[16];
    O_4D5670* p;
    D_004BCD60 = -1;
    D_004BCD68 = Sqrt_4D5670(Sqrt_4D5670(1.17549435e-38f));
    p = (O_4D5670*)D_005429F0;
    func_003BA210(p);
    D_00542AC0 = 0;
    func_0017F820(tmp);
    func_00132800(p->qE0, tmp);
    Vec4_Assign(&p->vF0, Vec4_GetZero());
    p->x100 = 0;
    func_003BA1B0(p->x110, Vec4_GetZero());
    func_00132840(p->x150);
    p->x160 = 0;
    p->x164 = 0;
    __register_global_object(p, func_00396340, D_005429E0);
    D_00542B60 = D_004BCF50;
    D_00542B68 = D_004BCF70;
}



