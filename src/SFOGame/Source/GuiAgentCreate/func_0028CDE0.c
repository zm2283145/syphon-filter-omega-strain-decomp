#pragma cplusplus on
#include "types.h"
/* GuiAgentCreate_Randomize_2: reset the preview skeleton from the current agent table entry, then for
   each appearance row (2..10) step that row's part (mesh, colour, preset, morph or texture)
   a random 1..4 times in the given direction. */
typedef struct { __int128 a; __int128 b; } Ent_CDE0;
typedef struct {
    char pad0[0x40];
    char app[0x40];             /* +0x40 */
    Ent_CDE0 e[0xF2];           /* +0x80 */
    char x1EC0[0x500];          /* +0x1EC0 */
    unsigned short count;       /* +0x23C0 */
    char pad23C2[0x2C04 - 0x23C2];
    int keep;                   /* +0x2C04 */
    char pad2C08[4];
    unsigned char body;         /* +0x2C0C */
    signed char tone;           /* +0x2C0D */
    char pad2C0E[2];
    signed char preset;         /* +0x2C10 */
    char pad2C11[0x2DF0 - 0x2C11];
} Skel_CDE0;
typedef struct { char pad[0x60]; Skel_CDE0 skel; } Tbl_CDE0;
typedef struct { unsigned char mode; unsigned char slot; short pos; } Tab_CDE0;
typedef struct {
    char pad0[0x70];
    Tbl_CDE0* tbl;          /* +0x70 */
    char pad74[0xDC - 0x74];
    int tone;               /* +0xDC */
    char padE0[8];
    int vE8;                /* +0xE8 */
} S_CDE0;

extern "C" {
extern char g_AgentPartCache[];
extern __int128* D_0048B460;
extern Tab_CDE0 D_0048B500[][11];
extern unsigned int D_00571300;
void srand(unsigned int seed);
int Libc_Rand(void);
signed char SKL_FindRace(void* a);
void cMan_SetBoneSet(Skel_CDE0* s, int preset);
int FindPart__7MonsterF1(char* cache, __int128 name);
int Monster_FindNextPart(void* db, int dir, __int128 key, int cur, int slot, int body, int tone, void* app, void* x);
int Monster_FindNextSamePart(void* db, int dir, __int128 key, int cur, int slot, int body, int tone, void* app, void* x);
int FindNextTexture__7MonsterFi11UiUiUiUiR3SKLR8ManParts(void* db, int dir, __int128 a, __int128 b, unsigned int cur, int slot, unsigned int body, unsigned int tone, void* app, void* x);
int AgentPacking_StepTexture(void* db, int dir, __int128 a, __int128 b, unsigned int cur, int slot, unsigned int body, int tone, void* app, void* x);
int FindTextureNumber__7MonsterF1(void* db, __int128 key);
int cMan_NextFaceShape(Skel_CDE0* s, int dir, int idx, int body);
void GuiAgentCreate_Randomize_2(S_CDE0* self, Skel_CDE0* skel, int dir);
}

/* quadword block copy loop (n quadwords), the retail struct copy */
static inline void QCopy(void* dd, void* ss, int nn) { int n = nn; __int128 q; void* s = ss; void* d = dd;
    __asm__ volatile(".set noreorder; 1: lq %0, 0(%2); addiu %1, %1, 0x10; addi %3, %3, -1; addiu %2, %2, 0x10; bgtz %3, 1b; sq %0, -0x10(%1); .set reorder" : "=&r"(q), "+r"(d), "+r"(s), "+r"(n) : : "memory");
}

static inline Tbl_CDE0* Tbl(S_CDE0* s) { Tbl_CDE0* p = s->tbl; return p; }
void GuiAgentCreate_Randomize_2(S_CDE0* self, Skel_CDE0* skel, int dir)
{
    int item; int partNumber; int texNumber; int bodyPart; int partTexMode; int sex; int found; int count; int j1; int j2; int j3; int bone; int j4; int j5;
    srand(*(unsigned int*)0x10000000);
    {
        Skel_CDE0* src = &Tbl(self)->skel;
        __int128 save = *(__int128*)&skel->app[0x30];
        int keep = skel->keep;
        QCopy(skel, src, 0x2DF0 / 16);
        skel->keep = keep;
        cMan_SetBoneSet(skel, skel->preset);
        *(__int128*)&skel->app[0x30] = save;
    }
    sex = skel->body;
    for (item = 2; item < 11; item++) {
        count = Libc_Rand() & 3;
        count++;
        bodyPart = D_0048B500[sex][item].slot;
        partTexMode = D_0048B500[sex][item].mode;
        self->tone = SKL_FindRace(skel->app);
        skel->tone = self->tone;
        if (partTexMode == 0) {
            partNumber = FindPart__7MonsterF1(g_AgentPartCache, skel->e[bodyPart].a);
            for (j1 = 0; j1 < count; j1++) {
                found = Monster_FindNextPart(g_AgentPartCache, dir, skel->e[bodyPart].a, partNumber, bodyPart, sex, skel->tone, skel->app, skel->x1EC0);
                if (found != -1) {
                    partNumber = found;
                    FindTextureNumber__7MonsterF1(g_AgentPartCache, skel->e[bodyPart].b);
                }
            }
        } else if (partTexMode == 7) {
            partNumber = FindPart__7MonsterF1(g_AgentPartCache, skel->e[bodyPart].a);
            for (j2 = 0; j2 < count; j2++) {
                found = Monster_FindNextSamePart(g_AgentPartCache, dir, skel->e[bodyPart].a, partNumber, bodyPart, sex, skel->tone, skel->app, skel->x1EC0);
                if (found != -1) {
                    partNumber = found;
                    FindTextureNumber__7MonsterF1(g_AgentPartCache, skel->e[bodyPart].b);
                }
            }
        } else if (partTexMode == 1 || partTexMode == 1) {
            texNumber = FindTextureNumber__7MonsterF1(g_AgentPartCache, skel->e[bodyPart].b);
            for (j3 = 0; j3 < count; j3++) {
                if (bodyPart < skel->count)
                    found = FindNextTexture__7MonsterFi11UiUiUiUiR3SKLR8ManParts(g_AgentPartCache, dir, skel->e[bodyPart].a, skel->e[bodyPart].b, texNumber, bodyPart, sex, skel->tone, skel->app, skel->x1EC0);
                else
                    found = FindNextTexture__7MonsterFi11UiUiUiUiR3SKLR8ManParts(g_AgentPartCache, dir, *D_0048B460, skel->e[bodyPart].b, texNumber, bodyPart, sex, skel->tone, skel->app, skel->x1EC0);
                if (found != -1)
                    texNumber = found;
            }
        } else if (partTexMode == 5) {
            bone = skel->preset + count * dir;
            if (bone < 0)
                bone = D_00571300 - bone;
            if (bone < 0)
                bone = 0;
            if ((unsigned int)bone >= D_00571300)
                bone -= D_00571300;
            if ((unsigned int)bone >= D_00571300)
                bone = 0;
            skel->preset = bone;
            cMan_SetBoneSet(skel, bone);
        } else if (partTexMode == 6) {
            for (j4 = 0; j4 < count; j4++)
                self->vE8 = cMan_NextFaceShape(skel, dir, self->vE8, sex);
        } else if (partTexMode == 8) {
            texNumber = FindTextureNumber__7MonsterF1(g_AgentPartCache, skel->e[bodyPart].b);
            for (j5 = 0; j5 < count; j5++) {
                found = AgentPacking_StepTexture(g_AgentPartCache, dir, skel->e[bodyPart].a, skel->e[bodyPart].b, texNumber, bodyPart, sex, skel->tone, skel->app, skel->x1EC0);
                if (found != -1)
                    texNumber = found;
            }
        }
    }
}
