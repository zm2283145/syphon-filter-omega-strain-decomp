// AddExtraBullets(cBullet*, cBulletInit&). cMatrix copy ctor = 2-temp volatile lq/sq asm (keeps binit in s1); cEulerAngle ctor gives retail's ang store/reload;
// Euler temps declared cycz,cysz,sycz,sysz; RandRange(-D,D) inline (no RandPM); MulM(d,m,p) w/ locals pp,mm fixes addr regs.
#pragma cplusplus on
#include "types.h"
#pragma fp_contract off
#pragma opt_strength_reduction off
#pragma opt_propagation off
#pragma opt_rotateloops off
#pragma opt_loop_invariants off

struct cMatrix { float m[4][4]; cMatrix() {} cMatrix(const cMatrix& o) { cMatrix* d = this; const cMatrix* s = &o; __int128 a, b; __asm__ volatile("lq %0, 0x0(%2); lq %1, 0x10(%2); sq %0, 0x0(%3); lq %0, 0x20(%2); sq %1, 0x10(%3); lq %1, 0x30(%2); sq %0, 0x20(%3); sq %1, 0x30(%3)" : "=&r"(a), "=&r"(b) : "r"(s), "r"(d) : "memory"); } } __attribute__((aligned(16)));
struct cEulerAngle_T { float x; float y; float z; unsigned int pad; cEulerAngle_T(float ax, float ay, float az) { x = ax; y = ay; z = az; } };
struct cBullet;
struct cBulletInit {
    cMatrix mat;
    float speed;
    char pad44[0xD6 - 0x44];
    unsigned char drawTracer;
};

extern "C" {
int Libc_Rand(void);
float COS(float);
float SIN(float);
void cMatrix_Set_ColumnMajorForm(cMatrix* m, float a, float b, float c, float d, float e, float f, float g, float h, float i);
cBullet* cBulletManager_AddBullet(cBulletInit& binit);
void cBullet_AddBlastSibling(cBullet* a, cBullet* b);
extern float D_00489C38;
extern float D_00489C40;
extern float D_00489C48;
extern int D_00489DB0[4];
extern int D_00489DC0[4];
}

static inline float RandF() { float m = 2147483648.0f; return (float)Libc_Rand() / (1.0f + m); }
static inline float RandRange(float lo, float hi) { float l = lo; float h = hi; return l + (h - l) * RandF(); }

static inline float RandPM(float s) { return RandRange(-s, s); }

static inline void EulerToMatrix(cMatrix* m, const cEulerAngle_T& a)
{
    float az = a.z; float ax = a.x; float ay = a.y;
    float cz = COS(az); float sz = SIN(az);
    float cx = COS(ax); float sx = SIN(ax);
    float cy = COS(ay); float sy = SIN(ay);
    float cycz = cy * cz; float cysz = cy * sz; float sycz = sy * cz; float sysz = sy * sz;
    cMatrix_Set_ColumnMajorForm(m,
        cycz + sysz * sx, -cysz + sycz * sx, sy * cx,
        cx * sz, cx * cz, -sx,
        -sycz + cysz * sx, sysz + cycz * sx, cy * cx);
}

static inline void MulM(void* d, void* m, void* p) {
    void* pp = p; void* mm = m;
    asm {
        lqc2 vf4, 0x0(mm)
        lqc2 vf5, 0x10(mm)
        lqc2 vf6, 0x20(mm)
        lqc2 vf8, 0x0(pp)
        lqc2 vf9, 0x10(pp)
        lqc2 vf10, 0x20(pp)
        lqc2 vf11, 0x30(pp)
        vmulax.xyz ACC, vf4, vf8x
        vmadday.xyz ACC, vf5, vf8y
        vmaddz.xyz vf8, vf6, vf8z
        vmulax.xyz ACC, vf4, vf9x
        vmadday.xyz ACC, vf5, vf9y
        vmaddz.xyz vf9, vf6, vf9z
        vmulax.xyz ACC, vf4, vf10x
        vmadday.xyz ACC, vf5, vf10y
        vmaddz.xyz vf10, vf6, vf10z
        vmulax.xyz ACC, vf4, vf11x
        vmadday.xyz ACC, vf5, vf11y
        vmaddz.xyz vf11, vf6, vf11z
        sqc2 vf8, 0x0(d)
        sqc2 vf9, 0x10(d)
        sqc2 vf10, 0x20(d)
        sqc2 vf11, 0x30(d)
    }
}

extern "C" void AddExtraBullets(cBullet* bullet, cBulletInit& binit)
{
    cMatrix oldMat = binit.mat;
    float oldSpeed = binit.speed;
    binit.drawTracer = 0;
    float baseYang = 6.28f * RandF();
    cBullet* bullets[5];
    bullets[0] = bullet;
    int i;
    for (i = 0; i < 4; i++) {
        float yang = baseYang + RandRange(-D_00489C40, D_00489C40);
        cEulerAngle_T ang(D_00489C38 * D_00489DB0[i], yang, D_00489C38 * D_00489DC0[i]);
        cMatrix offset;
        EulerToMatrix(&offset, ang);
        MulM(&offset, &oldMat, &offset);
        binit.mat.m[0][0] = offset.m[0][0];
        binit.mat.m[0][1] = offset.m[0][1];
        binit.mat.m[0][2] = offset.m[0][2];
        binit.mat.m[1][0] = offset.m[1][0];
        binit.mat.m[1][1] = offset.m[1][1];
        binit.mat.m[1][2] = offset.m[1][2];
        binit.mat.m[2][0] = offset.m[2][0];
        binit.mat.m[2][1] = offset.m[2][1];
        binit.mat.m[2][2] = offset.m[2][2];
        binit.mat.m[0][3] = offset.m[0][3];
        binit.mat.m[1][3] = offset.m[1][3];
        binit.mat.m[2][3] = offset.m[2][3];
        binit.speed = oldSpeed + RandRange(-D_00489C48, D_00489C48);
        bullets[i + 1] = cBulletManager_AddBullet(binit);
    }
    for (int i2 = 0; i2 < 5; i2++) {
        int j;
        for (j = 0; j < 5; j++) {
            if (i2 != j)
                cBullet_AddBlastSibling(bullets[i2], bullets[j]);
        }
    }
}
