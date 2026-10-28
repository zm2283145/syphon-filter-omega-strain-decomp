/* Monster_LoadLights (004029B0) - manUtils.cc */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

/* lq/sq quadword copies and VU0 math have no C equivalent; the unused xx keeps retail's dead addius */
struct cVector {
    float x, y, z, w;
    cVector() {}
    cVector(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    cVector(const cVector& o) { const cVector* ps = &o; cVector* pd = this; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } }
    cVector& operator=(const cVector& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct cMatrix { float m[4][4];
    cMatrix() {}
    cMatrix(const cVector& a, const cVector& b, const cVector& c, const cVector& d);
    cMatrix& operator=(const cMatrix& o) { __int128 a, b; const cMatrix* p = &o; asm volatile { lq a, 0x0(p); lq b, 0x10(p); sq a, 0x0(this); lq a, 0x20(p); sq b, 0x10(this); lq b, 0x30(p); sq a, 0x20(this); sq b, 0x30(this) } return *this; }
} __attribute__((aligned(16)));
struct cFileMan { char b[0x9C]; };
struct Monster;

extern "C" {
extern char D_004BE790[];
extern char D_004BE7A0[];
extern char D_004BE7E8[];
extern char D_004BE7F0[];
void cFileMan_ctor_charP_cFileIOP_bool(cFileMan* f, char* name, void* io, int b);
int cFileMan_Open(cFileMan* f);
int cFileMan_GetSize(cFileMan* f);
void cFileMan_Read_charPP_int(cFileMan* f, char** p, int size);
void cFileMan_Close(cFileMan* f);
void cFileMan_dtor(cFileMan* f, int del);
int Libc_Strncmp(char* a, char* b, int n);
int Libc_Sscanf(char* s, char* fmt, ...);
int cMemMan_Deallocate(int pool, void* p, char* file, int line);
void cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(cMatrix* m, cVector* a, cVector* b, cVector* c, cVector* d);
}

/* quadword clear loop (sq zero) */
static inline void QZero(void* d0, int n0) { int n = n0; void* d = d0;
    asm {
        .set noreorder
    lp:
        nop
        addi n, n, -1
        sq $zero, 0(d)
        bgtz n, lp
        addiu d, d, 0x10
        .set reorder
    }
}
static inline void Normalize(cVector* v) {
    asm {
        lqc2 vf1, 0x0(v)
        vmul.xyz vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf3, vf0, vf2z
        vrsqrt Q, vf0w, vf3w
        vwaitq
        vmulq.xyz vf1, vf1, Q
        sqc2 vf1, 0x0(v)
    }
}

inline cMatrix::cMatrix(const cVector& a, const cVector& b, const cVector& c, const cVector& d) { cMatrix_Set_cVectorR_cVectorR_cVectorR_cVectorR(this, (cVector*)&a, (cVector*)&b, (cVector*)&c, (cVector*)&d); }
extern "C" void Monster_LoadLights(Monster* self, char* path, cMatrix* theLightColor, cMatrix* theLightMat) {
    cVector lightDir[4];
    cFileMan lightFile;
    int size;
    char* lightData;
    char* data;
    char* end;
    int lightsFound;
    cMatrix m;
    cVector c;
    int aFlag;
    int count;
    char name[256];
    char type[256];
    float intensity;
    int i;

    cFileMan_ctor_charP_cFileIOP_bool(&lightFile, path, 0, 0);
    if (!(unsigned char)cFileMan_Open(&lightFile)) {
        size = cFileMan_GetSize(&lightFile);
        lightData = 0;
        cFileMan_Read_charPP_int(&lightFile, &lightData, size);
        cFileMan_Close(&lightFile);
        data = lightData;
        lightsFound = 0;
        end = data + size;
        *end = '\n';
        QZero(theLightColor, 4);
        while (data < end) {
            if (Libc_Strncmp(data, D_004BE790, 5) == 0) {
                while (*data != '\r' && *data != '\n') data++;
                while (*data == '\r' || *data == '\n') data++;
                while (*data != '\r' && *data != '\n') data++;
                while (*data == '\r' || *data == '\n') data++;
                do {
                    count = Libc_Sscanf(data, D_004BE7A0, name, &aFlag, type,
                        &m.m[0][0], &m.m[0][1], &m.m[0][2],
                        &m.m[1][0], &m.m[1][1], &m.m[1][2],
                        &m.m[2][0], &m.m[2][1], &m.m[2][2],
                        &m.m[3][0], &m.m[3][1], &m.m[3][2],
                        &c.x, &c.y, &c.z, &intensity);
                    if (count == 19 && Libc_Strncmp(type, D_004BE7E8, 6) == 0 && lightsFound < 4) {
                        lightDir[lightsFound].x = m.m[2][0];
                        lightDir[lightsFound].y = m.m[2][1];
                        lightDir[lightsFound].z = m.m[2][2];
                        theLightColor->m[lightsFound][0] = 128.0f * (intensity * c.x);
                        theLightColor->m[lightsFound][1] = 128.0f * (intensity * c.y);
                        theLightColor->m[lightsFound][2] = 128.0f * (intensity * c.z);
                        lightsFound++;
                    }
                    while (*data != '\r' && *data != '\n') data++;
                    while (*data == '\r' || *data == '\n') data++;
                } while (count == 19);
                break;
            }
            while (*data != '\r' && *data != '\n') data++;
            while (*data == '\r' || *data == '\n') data++;
        }
        {
            char* p = lightData;
            AllocGuard g;
            cMemMan_Deallocate(0, p, D_004BE7F0, 2746);
        }
    } else {
        lightDir[0] = cVector(0.0f, 0.5f, -1.5f, 0.0f);
        lightDir[1] = cVector(1.5f, 0.5f, 0.5f, 0.0f);
        lightDir[2] = cVector(-1.5f, 0.5f, 0.5f, 0.0f);
        lightDir[3] = cVector(0.5f, 0.5f, 0.5f, 0.0f);
        *(cVector*)theLightColor->m[0] = cVector(0.2f, 0.2f, 0.2f, 0.0f);
        *(cVector*)theLightColor->m[1] = cVector(0.3f, 0.3f, 0.3f, 0.0f);
        *(cVector*)theLightColor->m[2] = cVector(0.9f, 0.9f, 0.9f, 0.0f);
        *(cVector*)theLightColor->m[3] = cVector(0.0f, 0.0f, 0.0f, 0.0f);
    }
    for (i = 0; i < 4; i++)
        { cVector* xx = &lightDir[i]; Normalize(&lightDir[i]); }
    *theLightMat = cMatrix(lightDir[0], lightDir[1], lightDir[2], lightDir[3]);
    cFileMan_dtor(&lightFile, -1);
}
