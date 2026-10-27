#include "types.h"

typedef struct { int handle; unsigned char loaded; } EffSlot;
typedef struct { int d[0x28]; } HogEnt;
extern char D_004A6E60[];
extern char* D_0048ACD0[];
extern char* D_0048AD40[];
extern EffSlot SpecFxTable[];
extern char D_0053B540[];
extern void* g_TextureMgr;
extern int sprintf(char*, const char*, ...);
extern void* cFileMan_ctor_void(void*);
extern void* cFileMan_dtor(void*, int);
extern int cFileMan_EncodeFilename_charP_cHogFileR_bool(void*, const char*, int, int);
extern int cHogList_Open(int, char*, int, int);
extern void cParticleSystem_RequestEffectLoad(void*, char*, EffSlot*);
extern int cTexMan_AddTextureFromFile_cFileManR(void*, void*);
extern int cTexMan_UseMrYuckTexture(void*);

void nSfxLoader_LoadEffects(int a0, int arc)
{
    char buf[0x80];
    HogEnt e;
    int i;
    int j;

    sprintf(buf, D_004A6E60, a0);
    cFileMan_ctor_void(&e);
    for (i = 0; i < 26; i++) {
        cParticleSystem_RequestEffectLoad(D_0053B540, D_0048ACD0[i], &SpecFxTable[i]);
        SpecFxTable[i].loaded = 1;
    }
    for (j = 0; j < 15; j++) {
        cFileMan_EncodeFilename_charP_cHogFileR_bool(&e, D_0048AD40[j], cHogList_Open(arc, buf, 0, 0), 0);
        {
        int h = cTexMan_AddTextureFromFile_cFileManR(g_TextureMgr, &e);
        SpecFxTable[j + 26].handle = h;
        SpecFxTable[j + 26].loaded = h > -1;
        }
        if (!SpecFxTable[j + 26].loaded) {
            SpecFxTable[j + 26].handle = cTexMan_UseMrYuckTexture(g_TextureMgr);
            SpecFxTable[j + 26].loaded = 1;
        }
    }
    cFileMan_dtor(&e, -1);
}
