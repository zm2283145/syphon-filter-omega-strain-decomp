/*
 * Libs/SFOLib/Source/particle: 2 files, 003A5890-003A58E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003A5890 */
#pragma push /* merge_units */
#include "types.h"
#define FLT_MAX 3.4028235e38f
typedef struct { void* vt; char pad[0x88C]; float mn[4]; float mx[4]; } BoundsObj;
extern char D_004DFAA0[];
/* Constructor: sets vtable and empty bounds. */
BoundsObj* cParticleDefinition_ctor(BoundsObj* o)
{
    o->vt = D_004DFAA0;
    o->mn[0] = FLT_MAX; o->mn[1] = FLT_MAX; o->mn[2] = FLT_MAX; o->mn[3] = 1.0f;
    o->mx[0] = -FLT_MAX; o->mx[1] = -FLT_MAX; o->mx[2] = -FLT_MAX; o->mx[3] = 1.0f;
    return o;
}
static inline void merge_flush_func_003A5890(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A5890 */

/* merge_units: begin func_003A58E0 */
#pragma push /* merge_units */
#pragma cplusplus on

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
int cParticleSystem_GetEffectID(Lib* lib, char* name);
int cFileMan_Open(Res* r);
char* cFileMan_Read_void(Res* r);
void cFileMan_Close(Res* r);
Def* cParticleSystem_Load_charP_charP_cParticleDefinitionP(Lib* lib, char* str, char* tex, Def* obj);
void cFileMan_ctor_charP_cFileManR(Res* r, char* name, Res* parent);
int cTexMan_AddTextureFromFile_cFileManR(void* mgr, Res* r);
void cFileMan_dtor(Res* r, int f);
void std_list_cParticleDefinitionPtr_push_back(void* list, Def** v);
char* strncpy(void* d, const void* s, int n);
void Libc_Strcat(char* d, const char* s);
void cFileMan_ctor_void(Res* r);
void cFileMan_EncodeFilename_charP_cFileManR(Res* r, char* name, Res* parent);
bool cParticleSystem_Load_cFileManR(Lib* lib, Res* res);
}

/* Loads a .par particle definition (and, recursively, its sub-definitions): parse, bind the
 * texture, fill the GS register block (TEX0/ALPHA/...) and register it in the library. */
extern "C" bool cParticleSystem_Load_cFileManR(Lib* lib, Res* res)
{
    bool ok = true;
    if (cParticleSystem_GetEffectID(lib, res->name) == -1 && !(unsigned char)cFileMan_Open(res)) {
        char* data = cFileMan_Read_void(res);
        cFileMan_Close(res);
        if (data) {
            Def* def;
            char texName[0x8C];
            int k;
            def = cParticleSystem_Load_charP_charP_cParticleDefinitionP(lib, data, texName, 0);
            if (def) {
                Res tex;
                int i;
                if (!texName[0]) return 0;
                cFileMan_ctor_charP_cFileManR(&tex, texName, res);
                def->tex = cTexMan_AddTextureFromFile_cFileManR(g_TextureMgr, &tex);
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
                    cFileMan_dtor(&tex, -1);
                    return ok;
                }
                std_list_cParticleDefinitionPtr_push_back(lib->list, &def);
                cFileMan_dtor(&tex, -1);
            }
            for (k = 0; k < def->nSub; k++) {
                char name[0x20];
                Res sub;
                strncpy(name, def->subs[k], 16);
                name[16] = 0;
                Libc_Strcat(name, D_004BC640);
                cFileMan_ctor_void(&sub);
                cFileMan_EncodeFilename_charP_cFileManR(&sub, name, res);
                cParticleSystem_Load_cFileManR(lib, &sub);
                cFileMan_dtor(&sub, -1);
            }
        }
    }
    return ok;
}
static inline void merge_flush_func_003A58E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003A58E0 */
