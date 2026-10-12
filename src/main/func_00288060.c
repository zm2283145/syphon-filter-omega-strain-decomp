#pragma cplusplus on
#include "types.h"

class VObj288060 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual int v17(void* who, int flag);
};

typedef struct {
    char pad[0x14];
    unsigned short x14;
    char pad16[0xE];
    VObj288060* x24;
} Ent288060;

typedef struct {
    char pad[0x48];
    unsigned char x48;
    char pad49[3];
    float x4C;
} Self288060;

typedef struct {
    char pad[8];
    Self288060* x8;
} Cam288060;

typedef struct {
    char pad[0x20];
    Ent288060* x20;
    char pad24[8];
    Cam288060* x2C;
} Game288060;

typedef struct {
    char pad[0x59D];
    unsigned char x59D;
} Cfg288060;

typedef struct {
    char pad[0x39];
    char name[0x103];
    int x13C;
} Ui288060;

extern "C" int D_0048B3F0;
extern "C" Cfg288060* D_0055A830;
extern "C" unsigned char D_004FFBB8;
extern "C" unsigned char D_004FFBB1;
extern "C" Ui288060* D_004FFC04;
extern "C" char D_004A95E8[];
extern "C" signed char D_004FFBA0;
extern "C" signed char D_004FFBA1;

extern "C" Ent288060* func_0041DB80(Self288060* self, int id);
extern "C" unsigned char func_00288510(void);
extern "C" Game288060* func_004147A0(void);
extern "C" void func_00414B30(Game288060* g, int v);
extern "C" int func_003698B0(void);
extern "C" float func_001002D0(int t);
extern "C" void String_Copy(char* dst, const char* src);
extern "C" void func_0041E3B0(Self288060* self, float dt);

extern "C" void func_00288060(Self288060* self, float dt)
{
    Ent288060* e = func_0041DB80(self, D_0048B3F0);
    unsigned char flag = D_0055A830->x59D != 0;
    if (e) {
        unsigned char s = func_00288510();
        if (!s && func_004147A0()->x20 == e) {
            func_00414B30(func_004147A0(), e->x24->v17(e, 1));
        }
        if (s) {
            e->x14 |= 4;
        } else {
            e->x14 &= ~4;
        }
    }
    D_004FFBB8 = flag;
    if (self->x48) {
        if (func_004147A0()->x2C->x8 != self) {
            self->x4C = func_001002D0(func_003698B0()) / 1000.0f;
        } else {
            float t = func_001002D0(func_003698B0()) / 1000.0f;
            if (D_004FFBB1 && t - self->x4C > 30.0f) {
                D_004FFC04->x13C = 1;
                String_Copy(D_004FFC04->name, D_004A95E8);
                D_004FFBA1 = D_004FFBA0;
                D_004FFBA0 = 4;
            }
        }
    }
    func_0041E3B0(self, dt);
}
