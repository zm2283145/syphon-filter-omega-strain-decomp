#include "types.h"
typedef union { __int128 q; char s[16]; struct { char stem[14]; char lod; char end; } f; } H2Name;
typedef struct { short a; short b; } H2Tex;
typedef struct {
    char pad0[0xCC];
    unsigned int count;
    unsigned int loaded;
    char pad1[0x1410 - 0xD4];
    H2Tex tex[0x2A00];
    H2Name names[1];
} H2State;
typedef struct { char pad[0x148]; int* dir; } H2Hog;
typedef struct { __int128 x[10]; } H2Reg;
extern int D_00539248;
extern void func_0036E5D0(H2Reg* r);
extern void func_0036E220(H2Reg* r, int del);
extern char* Archive_GetMemberName(H2Hog* h, int i);
extern int Hog_Register(H2Reg* r, char* name, H2Hog* h, int opt);
extern void Appearance_RegistryKey(char* dst, int n, char* src);
extern short func_00380D40(int lib, __int128 name, H2Reg* r);
extern short TexCache_LoadErrorTexture(int lib);
static inline int h2eq(__int128 a, __int128 b) {
    long long r;
    asm {
        pceqw a, a, b
        ppach r, a, a
    }
    return r == -1;
}
static inline unsigned int h2find(H2State* st, __int128 key) {
    unsigned int i;
    for (i = 0; i < st->count; i++) {
        if (h2eq(st->names[i].q, key))
            return i;
    }
    return i;
}
/* Registers a texture HOG and loads each member texture into the state's texture table. */
void TexCache_RegisterNpcTex(H2State* st, H2Hog* hog) {
    H2Reg reg;
    int k;
    int total;
    func_0036E5D0(&reg);
    Hog_Register(&reg, Archive_GetMemberName(hog, 0), hog, 0);
    total = hog->dir[1];
    for (k = 0; k < total; k++) {
        char* e = Archive_GetMemberName(hog, k);
        int lod = 0;
        __int128 key;
        unsigned int i;
        if (e[14] != '0')
            lod = 1;
        Appearance_RegistryKey(st->names[st->count].s, 15, e);
        st->names[st->count].s[14] = '0';
        key = st->names[st->count].q;
        i = h2find(st, key);
        if (i == st->count) {
            st->tex[st->count].a = -1;
            st->tex[st->count].b = -1;
            st->count++;
        }
        if (lod == 0) {
            st->tex[i].a = func_00380D40(D_00539248, st->names[i].q, &reg);
            if (st->tex[i].a == -1)
                st->tex[i].a = TexCache_LoadErrorTexture(D_00539248);
            if (st->tex[i].b == -1)
                st->tex[i].b = st->tex[i].a;
        } else {
            H2State* sb;
            short* pb;
            short* pa;
            H2Name* nm;
            nm = (H2Name*)((char*)st + i * 16 + 0xBC10);
            sb = (H2State*)((char*)st + i * 4);
            nm->f.lod = '1';
            pb = &sb->tex[0].b;
            *pb = func_00380D40(D_00539248, st->names[i].q, &reg);
            if (*pb == -1)
                *pb = TexCache_LoadErrorTexture(D_00539248);
            pa = &sb->tex[0].a;
            if (*pa == -1)
                *pa = *pb;
            nm->f.lod = '0';
        }
    }
    st->loaded = st->count;
    func_0036E220(&reg, -1);
}