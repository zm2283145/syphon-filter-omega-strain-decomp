#pragma cplusplus on
#include "types.h"

typedef unsigned long u64_t;
struct V4 {
    float x, y, z, w;
    V4(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V4& operator=(const V4& o) { V4* pd = this; const V4* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } return *this; }
} __attribute__((aligned(16)));
struct IV4 {
    int x, y, z, w;
    IV4(int a, int b, int c, int d) { x = a; y = b; z = c; w = d; }
    IV4& operator=(const IV4& o) { IV4* pd = this; const IV4* ps = &o; __int128 q; asm volatile { lq q, 0(ps); sq q, 0(pd) } return *this; }
} __attribute__((aligned(16)));
struct Res { char pad[4]; char name[0x9C]; };
struct Def {
    char pad0[0x38];
    int blend;              /* 0x38 */
    char pad3C[0x74 - 0x3C];
    int tex;                /* 0x74 */
    char pad78[0x80 - 0x78];
    IV4 q80;                /* 0x80 */
    V4 q90;                 /* 0x90 */
    u64_t tag;              /* 0xA0 */
    u64_t ad;               /* 0xA8 */
    u64_t r0;               /* 0xB0 */
    u64_t r0id;             /* 0xB8 */
    u64_t r1;               /* 0xC0 */
    u64_t r1id;             /* 0xC8 */
    u64_t r2;               /* 0xD0 */
    u64_t r2id;             /* 0xD8 */
    V4 qE0;                 /* 0xE0 */
    V4 qF0;                 /* 0xF0 */
    int mode[12];           /* 0x100 */
    char pad130[0x138 - 0x130];
    u64_t x138;             /* 0x138 */
    char pad140[0x180 - 0x140];
    int nSub;               /* 0x180 */
    char pad184[0x190 - 0x184];
    char subs[1][0xE0];     /* 0x190 */
};
struct Lib { char pad[4]; char list[4]; };

extern "C" {
extern void* g_TextureMgr;
extern u64_t D_0053B680[];
extern char D_004BC640[];
int ParticleLib_FindId(Lib* lib, char* name);
int FileMan_FindMember(Res* r);
char* FileMan_ReadData(Res* r);
void cFileMan_Close(Res* r);
Def* ParticleDef_Parse(Lib* lib, char* str, char* tex, Def* obj);
void cFileMan_ctor_charP_cFileManR(Res* r, char* name, Res* parent);
int TexMan_FindOrLoad(void* mgr, Res* r);
void FileMan_Release(Res* r, int f);
void std_list_cParticleDefinitionPtr_push_back(void* list, Def** v);
char* strncpy(void* d, const void* s, int n);
void Libc_Strcat(char* d, const char* s);
void Resource_Construct(Res* r);
void cFileMan_EncodeFilename_charP_cFileManR(Res* r, char* name, Res* parent);
bool ParticleLib_LoadPar(Lib* lib, Res* res);
}

/* Loads a .par particle definition (and, recursively, its sub-definitions): parse, bind the
 * texture, fill the GS register block (TEX0/ALPHA/...) and register it in the library. */
extern "C" bool ParticleLib_LoadPar(Lib* lib, Res* res)
{
    bool ok = true;
    if (ParticleLib_FindId(lib, res->name) == -1 && !(unsigned char)FileMan_FindMember(res)) {
        char* data = FileMan_ReadData(res);
        cFileMan_Close(res);
        if (data) {
            Def* def;
            char texName[0x8C];
            int k;
            def = ParticleDef_Parse(lib, data, texName, 0);
            if (def) {
                Res tex;
                int i;
                if (!texName[0]) return 0;
                cFileMan_ctor_charP_cFileManR(&tex, texName, res);
                def->tex = TexMan_FindOrLoad(g_TextureMgr, &tex);
                def->q80 = IV4(0, 0, 0, 0);
                def->q90 = V4(0.0f, 0.0f, 0.0f, 0.0f);
                def->tag = 0x1000000000000003UL;
                def->ad = 14;
                def->r0 = 0;
                def->r0id = 20;
                def->r1 = 0;
                def->r1id = 6;
                def->r2 = D_0053B680[def->blend];
                def->r2id = 66;
                def->qE0 = V4(0.0f, 0.0f, 0.0f, 0.0f);
                def->qF0 = V4(0.0f, 0.0f, 0.0f, 0.0f);
                def->x138 = 0x412412;
                for (i = 0; i < 12; i++) def->mode[i] = 2;
                if (def->tex < 0) {
                    ok = false;
                    FileMan_Release(&tex, -1);
                    return ok;
                }
                std_list_cParticleDefinitionPtr_push_back(lib->list, &def);
                FileMan_Release(&tex, -1);
            }
            for (k = 0; k < def->nSub; k++) {
                char name[0x20];
                Res sub;
                strncpy(name, def->subs[k], 16);
                name[16] = 0;
                Libc_Strcat(name, D_004BC640);
                Resource_Construct(&sub);
                cFileMan_EncodeFilename_charP_cFileManR(&sub, name, res);
                ParticleLib_LoadPar(lib, &sub);
                FileMan_Release(&sub, -1);
            }
        }
    }
    return ok;
}
