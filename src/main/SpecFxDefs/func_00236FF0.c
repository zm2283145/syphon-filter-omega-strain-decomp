#include "types.h"

typedef struct { int handle; unsigned char loaded; } EffSlot;
typedef struct { int d[0x28]; } HogEnt;
extern char D_004A6E60[];
extern char* D_0048ACD0[];
extern char* D_0048AD40[];
extern EffSlot D_004F7A50[];
extern char D_0053B540[];
extern void* D_00539248;
extern int sprintf(char*, const char*, ...);
extern void* func_0036E5D0(void*);
extern void* FileMan_Release(void*, int);
extern int Hog_Register(void*, const char*, int, int);
extern int Archive_Open(int, char*, int, int);
extern void ParticleLib_Request(void*, char*, EffSlot*);
extern int TexMan_FindOrLoad(void*, void*);
extern int TexCache_LoadErrorTexture(void*);

void EffectTable_Load(int a0, int arc)
{
    char buf[0x80];
    HogEnt e;
    int i;
    int j;

    sprintf(buf, D_004A6E60, a0);
    func_0036E5D0(&e);
    for (i = 0; i < 26; i++) {
        ParticleLib_Request(D_0053B540, D_0048ACD0[i], &D_004F7A50[i]);
        D_004F7A50[i].loaded = 1;
    }
    for (j = 0; j < 15; j++) {
        Hog_Register(&e, D_0048AD40[j], Archive_Open(arc, buf, 0, 0), 0);
        {
        int h = TexMan_FindOrLoad(D_00539248, &e);
        D_004F7A50[j + 26].handle = h;
        D_004F7A50[j + 26].loaded = h > -1;
        }
        if (!D_004F7A50[j + 26].loaded) {
            D_004F7A50[j + 26].handle = TexCache_LoadErrorTexture(D_00539248);
            D_004F7A50[j + 26].loaded = 1;
        }
    }
    FileMan_Release(&e, -1);
}
