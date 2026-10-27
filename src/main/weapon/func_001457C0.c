#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#include "pop_reader.h"
/* cWeaponDB_LoadLevelSpecific: upper-case the agent model names, load the level's morph/sort data,
   collect the weapon ids the population uses and preload them, build the agent models, then
   resolve every weapon entry's skeleton, model and particle names. */
struct Arc_1457C0;
struct Db_1457C0;
struct Model_1457C0;
struct Vec_1457C0;
extern "C" {
extern char* D_00489CC0[];
extern char D_0048B2F8[];
extern char D_0049B1D0[];
extern char D_0049B210[];
extern char D_0049B228[];
extern char D_0049B238[];
extern char D_0049B240[];
extern char D_0049B248[];
extern char D_0053B540[];
extern char g_AgentPartCache[];
extern char g_LevelDirName[];
void* GetMachine(void);
void cMachine_ShowLoadingScreen(void* app, const char* msg, int z);
int sprintf(char* buf, const char* fmt, ...);
Arc_1457C0* cHogList_Open(void* list, char* name, int a, int b);
void Monster_LoadFaceHog(void* cache, Arc_1457C0* arc);
void Monster_ReadSortTable(void* cache, char* name);
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void std_vector_charPtr_ctor_void(void* p);
void SKLHog_LoadIdentities(char* a, char* b);
void WeaponDb_LoadShellsArchive(Db_1457C0* self, Arc_1457C0* arc);
void cFileMan_EncodeFilename_charP_cHogFileR_bool(void* hog, char* name, Arc_1457C0* arc, int z);
void Monster_LoadTexHog(void* cache, Arc_1457C0* arc);
void Monster_LoadParts(void* cache, Arc_1457C0* arc);
void cWeaponDB_LoadWeapon(Db_1457C0* self, int idx, char mode);
void gunList_LoadGunInit(Model_1457C0* m, char* name, int idx, int a, int b, int c, int d, int e);
int String_CompareNoCase(char* a, char* b);
void std_vector_charPtr_push_back_charPR(Vec_1457C0* v, char** s);
int strlen(const char* s);
char* strstr(char* a, char* b);
void cWeaponDB_LoadGun(Db_1457C0* self, char* name, void** out, int idx, int z, int cc, int x108);
void cParticleSystem_RequestEffectLoad(char* lib, char* name, int* out);
void cWeaponDB_LoadLevelSpecific(Db_1457C0* self, PopReader* r, void* list);
}
struct Arc_1457C0 { char pad[0x14C]; unsigned char loaded; };
struct Vec_1457C0 { int cap; int n; char** data; };
struct Skl_1457C0 { char pad[0xC]; unsigned char ready; };
struct Part_1457C0 { char d[32]; Part_1457C0() {} };
struct Model_1457C0 {
    char pad0[0x140];
    Part_1457C0 parts[12];
    char pad2C0[0x3E0 - 0x2C0];
    float mn[4];
    float mx[4];
    char pad400[0x41C - 0x400];
    int refs;
    static void* operator new(unsigned int sz) { AllocGuard g; return cMemMan_Allocate(0, sz, D_0049B1D0, 848); }
    Model_1457C0() {
        *(int*)&mn[0] = 0x7F7FFFFF;
        *(int*)&mn[1] = 0x7F7FFFFF;
        *(int*)&mn[2] = 0x7F7FFFFF;
        mn[3] = 1.0f;
        *(int*)&mx[0] = 0xFF7FFFFF;
        *(int*)&mx[1] = 0xFF7FFFFF;
        *(int*)&mx[2] = 0xFF7FFFFF;
        mx[3] = 1.0f;
    }
};

struct Ent_1457C0 {
    char pad0[0x90];
    char skl[0x48];     /* 0x90 */
    int particle;       /* 0xD8 */
    char padDC[0xE0 - 0xDC];
    char fx[0x3C];      /* 0xE0 */
    void* model;        /* 0x11C */
    char mdl[0x10];     /* 0x120 */
    int sklIdx;         /* 0x130 */
    int fx2;            /* 0x134 */
    char pad138[0x140 - 0x138];
};
struct Info_1457C0 { int a; int n; };
struct Db_1457C0 {
    int x0;
    Info_1457C0* info;   /* 0x4 */
    char pad8[0x14 - 0x8];
    Ent_1457C0* e;       /* 0x14 */
    char pad18[0x1C - 0x18];
    char hog[0x9C];      /* 0x1C */
    Model_1457C0* models[7]; /* 0xB8 */
    Vec_1457C0* skl;     /* 0xD4 */
};

void cWeaponDB_LoadLevelSpecific(Db_1457C0* self, PopReader* r, void* list)
{
    char* nm;
    char buf[0x80];
    char buf2[0x80];
    char buf4[0x80];
    char buf3[0x80];
    int ids[128];
    int n;
    int cnt;
    int i;
    int a;
    int m;
    int b;
    Arc_1457C0* arc;
    int li;
    Ent_1457C0* e;
    int lk;
    int mi;
    int id;
    int pl;
    bool found;
    Model_1457C0* mdl;
    int c;
    n = 0;
    cnt = 0;
    cMachine_ShowLoadingScreen(GetMachine(), "Loading Level Specific Weapon Data...", 0);
    for (i = 0; i < 7; i++) {
        char* p = D_00489CC0[i];
        while (*p) {
            if (*p >= 'a' && *p <= 'z')
                *p -= 32;
            p++;
        }
        self->models[i] = 0;
    }
    sprintf(buf, "%s\\COMMON\\MORPH.HOG", D_0048B2F8);
    arc = cHogList_Open(list, buf, 0, 0);
    if (arc->loaded)
        Monster_LoadFaceHog(g_AgentPartCache, arc);
    sprintf(buf, "%s\\FRONTEND\\MANSORT2.TXT", D_0048B2F8);
    Monster_ReadSortTable(g_AgentPartCache, buf);
    {
        Skl_1457C0* s;
        { AllocGuard g; s = (Skl_1457C0*)cMemMan_Allocate(0, 16, D_0049B1D0, 736); }
        if (s) {
            std_vector_charPtr_ctor_void(s);
            s->ready = 1;
        }
        self->skl = (Vec_1457C0*)s;
    }
    SKLHog_LoadIdentities(D_0048B2F8, g_LevelDirName);
    ids[cnt++] = 103;
    if (r) {
        int mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
        if (mis)
            r->cur += 4 - mis;
        if ((unsigned char)cPopulation_SeekBlock(r, 0x3A4E5057)) {
            n = *(int*)r->cur;
            r->cur += 4;
        }
        for (a = 0; a < n; a++) {
            m = *(int*)r->cur;
            r->cur += 4;
            for (b = 0; b < m; b++) {
                id = *(int*)r->cur;
                found = false;
                r->cur += 4;
                for (c = 0; c < cnt; c++) {
                    if (ids[c] == id) {
                        found = true;
                        break;
                    }
                }
                if (!found)
                    ids[cnt++] = id;
            }
        }
        if (cnt) {
            sprintf(buf2, "%s\\%s\\WPN.HOG", D_0048B2F8, g_LevelDirName);
            arc = cHogList_Open(list, buf2, 0, 0);
            if (arc->loaded)
                WeaponDb_LoadShellsArchive(self, arc);
            sprintf(buf2, D_0049B210, D_0048B2F8);
            cFileMan_EncodeFilename_charP_cHogFileR_bool(self->hog, D_0049B228, cHogList_Open(list, buf2, 1, 0), 0);
            sprintf(buf3, "%s\\%s\\NPCTEX.HOG", D_0048B2F8, g_LevelDirName);
            arc = cHogList_Open(list, buf3, 0, 0);
            if (arc->loaded)
                Monster_LoadTexHog(g_AgentPartCache, arc);
            sprintf(buf4, "%s\\%s\\NPCSKM.HOG", D_0048B2F8, g_LevelDirName);
            arc = cHogList_Open(list, buf4, 0, 0);
            if (arc->loaded)
                Monster_LoadParts(g_AgentPartCache, arc);
            for (pl = 0; pl < cnt; pl++)
                cWeaponDB_LoadWeapon(self, ids[pl], 1);
            for (mi = 0; mi < 7; mi++) {
                if (!self->models[mi]) {
                    mdl = new Model_1457C0;
                    self->models[mi] = mdl;
                    gunList_LoadGunInit(self->models[mi], D_00489CC0[mi], mi, 0, 0, 0, 0, -1);
                    self->models[mi]->refs++;
                }
            }
        }
    }
    for (li = 0; li < self->info->n; li++) {
        e = &self->e[li];
        if (e->skl[0] && self->skl) {
            for (lk = 0; lk < self->skl->n; lk++) {
                /* (unsigned) index: retail re-indexes data[lk] every pass instead of walking a pointer */
                if (!String_CompareNoCase(e->skl, self->skl->data[(unsigned)lk]))
                    break;
            }
            e->sklIdx = lk;
            if (lk >= self->skl->n) {
                nm = e->skl;
                std_vector_charPtr_push_back_charPR(self->skl, &nm);
            }
        } else {
            e->sklIdx = -1;
        }
        if (strlen(e->mdl)) {
            if (strstr(e->mdl, D_0049B238) || strstr(e->mdl, D_0049B240)) {
                if (!e->model)
                    cWeaponDB_LoadGun(self, e->mdl, &e->model, li, 1, -1, -1);
            } else {
                cParticleSystem_RequestEffectLoad(D_0053B540, e->mdl, &e->fx2);
            }
        }
        if (!String_CompareNoCase(e->fx, D_0049B248))
            e->particle = -1;
        else
            cParticleSystem_RequestEffectLoad(D_0053B540, e->fx, &e->particle);
    }
}
