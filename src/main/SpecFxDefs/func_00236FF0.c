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
extern void* Resource_Construct(void*);
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
    Resource_Construct(&e);
    for (i = 0; i < 26; i++) {
        ParticleLib_Request(D_0053B540, D_0048ACD0[i], &SpecFxTable[i]);
        SpecFxTable[i].loaded = 1;
    }
    for (j = 0; j < 15; j++) {
        Hog_Register(&e, D_0048AD40[j], Archive_Open(arc, buf, 0, 0), 0);
        {
        int h = TexMan_FindOrLoad(g_TextureMgr, &e);
        SpecFxTable[j + 26].handle = h;
        SpecFxTable[j + 26].loaded = h > -1;
        }
        if (!SpecFxTable[j + 26].loaded) {
            SpecFxTable[j + 26].handle = TexCache_LoadErrorTexture(g_TextureMgr);
            SpecFxTable[j + 26].loaded = 1;
        }
    }
    FileMan_Release(&e, -1);
}
