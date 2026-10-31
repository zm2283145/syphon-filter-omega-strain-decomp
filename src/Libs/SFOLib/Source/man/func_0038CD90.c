#pragma cplusplus on
#include "types.h"
typedef __int128 u_long128;

struct cVector {
    float x, y, z, w;
    cVector() {}
    cVector(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
} __attribute__((aligned(16)));
static inline void QCopy1(void* d, const void* s) { u_long128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }

struct cQuaternion { float x, y, z, w; } __attribute__((aligned(16)));
struct boneOffset { float x, y, z; int parent; };
struct cVector_NoInitHACK { float x, y, z, w; };
struct gunBones {
    cQuaternion orient;
    union U { boneOffset the; cVector_NoInitHACK offset; } u;
};
struct manRefs { unsigned char qwc; unsigned char vertCount; };
struct Parts {
    u_long128* part;
    unsigned short qwc;
    unsigned char type;
    unsigned char patchCount;
    manRefs* Refs;
    unsigned int* blends;
};
struct manAttribs { u_long128 partName; u_long128 texName; };
struct cBox { cVector min; cVector max; };
struct gunList {
    char gunName[32];
    manAttribs gunAttribsTable[8];
    gunBones gunBulletOffset;
    gunBones gunBonesOffsets[12];
    Parts gunParts[2][8];
    short gunTexID[8];
    short gunTexID2[8];
    cBox gunBBox;
    char* gunHog;
    u_long128* casingModelPart;
    unsigned short casingModelqwc;
    short gunWDBIndex;
    unsigned char gunPartCount;
    unsigned char gunHoldType;
    unsigned char gunHoldTypeHand2;
    unsigned char gunAnimType;
    signed char gunHolsterPart;
    signed char gunFlarePart;
    signed char gunLightPart;
    signed char gunStockPartOn;
    signed char gunStockPartOff;
    unsigned char gunGlow;
    signed char gunTransparency;
    signed char gunLoading;
    unsigned char gunMalloc;
    unsigned char gunIsBullet;
    int gunRefCount;
};
struct tHogHeader { unsigned int id; unsigned int numBlocks; unsigned int offsetListOffset; unsigned int nameListOffset; unsigned int bodyOffset; };
struct cHogFile {
    char mHogFname[128];
    char mHogFile[200];
    tHogHeader* mHogHeader;
    char pad14C[0x16C - 0x14C];
};
struct SKL {
    char rawChars[0x40];
    manAttribs manAttribsTable[32];
};
struct cFileMan { char pad[0x9C]; };
struct cTexMan;

extern "C" {
void cHogFile_ctor(cHogFile*);
void cHogFile_dtor(cHogFile*, int);
void cHogFile_Open(cHogFile*, const char*, char*, int);
char* cHogFile_GetBlockName(cHogFile*, int);
char* cHogFile_GetBlock_int(cHogFile*, int);
unsigned int cHogFile_GetBlockSize(cHogFile*, int);
char* strrchr(const char*, int);
int strcmp(const char*, const char*);
int Libc_Strncmp(const char*, const char*, int);
void strCpyPad(char*, int, char*);
void SKL_ConvertSKL(SKL*, char*, int);
void Parts_SetGunData(Parts*, char*, int);
void cFileMan_ctor_void(cFileMan*);
void cFileMan_dtor(cFileMan*, int);
void cFileMan_EncodeFilename_charP_cHogFileR_bool(cFileMan*, const char*, cHogFile*, int);
short cTexMan_AddTextureFromFile_R_cFileMan(cTexMan*, u_long128, cFileMan*);
short cTexMan_UseMrYuckTexture(cTexMan*);
void gunList_GunCalcBBox(gunList*);
extern cTexMan* g_TextureMgr;
extern char D_004BC340[], D_004BC348[], D_004BC350[], D_004BC358[], D_004BC360[], D_004BC368[], D_004BC370[], D_004BC378[], D_004BC380[], D_004BC388[];
}

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
static inline void QMove(void* d0, void* s0, int n) { u_long128 t; void* s; void* d; s = s0; d = d0;
    asm {
        .set noreorder
    lp:
        lq t, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq t, -0x10(d)
        .set reorder
    }
}
static inline long long QEq(u_long128 a, u_long128 b) {
    u_long128 t;
    long long r;
    asm {
        pceqw t, a, b
        ppach r, t, t
    }
    return r;
}

static inline void BoxInit(cBox* b)
{
    cVector t1(3.4028235e38f, 3.4028235e38f, 3.4028235e38f, 1.0f);
    cVector* mn = &b->min;
    QCopy1(mn, &t1);
    void* xx = &b->max;
    cVector t2(-3.4028235e38f, -3.4028235e38f, -3.4028235e38f, 1.0f);
    QCopy1(&b->max, &t2);
}

extern "C" void gunList_LoadGunHog(gunList* self, char* gunHogData)
{
    cHogFile hog_model;
    u_long128 partNames[16];
    Parts parts[16];
    int partCount;
    int sklFound;
    int bonesFound;
    int blocks;
    char* blockName;
    char* ext;
    int j;
    SKL localSKL;
    int part;
    int found;
    u_long128 fullPartName;
    char* fullPartText;
    cFileMan texFile;

    cHogFile_ctor(&hog_model);
    partCount = 0;
    sklFound = 0;
    self->gunHog = gunHogData;
    self->gunLoading = 0;
    BoxInit(&self->gunBBox);
    QZero(self->gunBonesOffsets, 24);
    cHogFile_Open(&hog_model, D_004BC340, gunHogData, 0);
    blocks = hog_model.mHogHeader->numBlocks;
    for (j = 0; j < blocks; j++) {
        blockName = cHogFile_GetBlockName(&hog_model, j);
        ext = strrchr(blockName, '.');
        if (!ext) ext = blockName;
        if (!strcmp(ext, D_004BC348)) {
            SKL_ConvertSKL(&localSKL, cHogFile_GetBlock_int(&hog_model, j), cHogFile_GetBlockSize(&hog_model, j));
            QMove(self->gunAttribsTable, localSKL.manAttribsTable, 16);
            sklFound = 1;
        }
        if (!strcmp(ext, D_004BC350)) {
            if (cHogFile_GetBlockSize(&hog_model, j) < 0x180) {
                QZero(self->gunBonesOffsets, 24);
                QMove(self->gunBonesOffsets, cHogFile_GetBlock_int(&hog_model, j), (int)cHogFile_GetBlockSize(&hog_model, j) >> 4);
            } else {
                QMove(self->gunBonesOffsets, cHogFile_GetBlock_int(&hog_model, j), 24);
            }
        }
        if (!strcmp(ext, D_004BC358)) {
            strCpyPad((char*)&partNames[partCount], 15, blockName);
            Parts_SetGunData(&parts[partCount], cHogFile_GetBlock_int(&hog_model, j), cHogFile_GetBlockSize(&hog_model, j));
            partCount++;
        }
    }
    if (!sklFound) {
        self->gunPartCount = 0;
        self->gunLoading = -2;
        cHogFile_dtor(&hog_model, -1);
        return;
    }
    for (part = 0; (long long)self->gunAttribsTable[part].partName != 0; part++);
    self->gunPartCount = part;
    fullPartText = (char*)&fullPartName;
    for (part = 0; part < self->gunPartCount; part++) {
        found = 0;
        fullPartName = self->gunAttribsTable[part].partName;
        for (j = 0; j < partCount; j++) {
            if (QEq(fullPartName, partNames[j]) == -1) {
                found = 1;
                self->gunParts[0][part] = parts[j];
            }
        }
        if (!found) {
            self->gunParts[0][part].part = 0;
            self->gunParts[0][part].qwc = 0;
        }
        found = 0;
        fullPartText[14] = '1';
        for (j = 0; j < partCount; j++) {
            if (QEq(fullPartName, partNames[j]) == -1) {
                found = 1;
                self->gunParts[1][part] = parts[j];
            }
        }
        if (!found) self->gunParts[1][part] = self->gunParts[0][part];
        if (!Libc_Strncmp(D_004BC360, fullPartText, 5)) self->gunHolsterPart = part;
        if (!Libc_Strncmp(D_004BC368, fullPartText, 5)) self->gunLightPart = part;
        if (!Libc_Strncmp(D_004BC370, fullPartText, 5)) self->gunStockPartOn = part;
        if (!Libc_Strncmp(D_004BC378, fullPartText, 5)) self->gunStockPartOff = part;
        if (!Libc_Strncmp(D_004BC380, fullPartText, 5)) {
            self->gunFlarePart = part;
            if (!Libc_Strncmp(D_004BC388, fullPartText, 14)) {
                self->gunGlow = 1;
                self->gunFlarePart = -1;
            }
        }
    }
    cFileMan_ctor_void(&texFile);
    cFileMan_EncodeFilename_charP_cHogFileR_bool(&texFile, cHogFile_GetBlockName(&hog_model, 0), &hog_model, 0);
    cTexMan& texMan = *g_TextureMgr;
    for (part = 0; part < self->gunPartCount; part++) {
        fullPartName = self->gunAttribsTable[part].texName;
        self->gunTexID[part] = cTexMan_AddTextureFromFile_R_cFileMan(&texMan, fullPartName, &texFile);
        fullPartText[14] = '1';
        self->gunTexID2[part] = cTexMan_AddTextureFromFile_R_cFileMan(&texMan, fullPartName, &texFile);
        if (self->gunTexID[part] == -1) self->gunTexID[part] = cTexMan_UseMrYuckTexture(&texMan);
        if (self->gunTexID2[part] == -1) self->gunTexID2[part] = self->gunTexID[part];
    }
    part = 3;
    { cQuaternion* o = &self->gunBulletOffset.orient; QCopy1(o, &self->gunBonesOffsets[part].orient); }
    self->gunBulletOffset.u = self->gunBonesOffsets[part].u;
    while (part) {
        part = self->gunBulletOffset.u.the.parent;
        self->gunBulletOffset.u.offset.x += self->gunBonesOffsets[part].u.offset.x;
        self->gunBulletOffset.u.offset.y += self->gunBonesOffsets[part].u.offset.y;
        self->gunBulletOffset.u.offset.z += self->gunBonesOffsets[part].u.offset.z;
        self->gunBulletOffset.u.offset.w += self->gunBonesOffsets[part].u.offset.w;
    }
    self->gunBulletOffset.u.offset.w = 1.0f;
    gunList_GunCalcBBox(self);
    cFileMan_dtor(&texFile, -1);
    cHogFile_dtor(&hog_model, -1);
}



