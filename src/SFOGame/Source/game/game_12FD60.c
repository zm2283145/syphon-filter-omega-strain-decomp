/*
 * main/game: range (5 files, 0012FD60-001302F0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
#include "SFOLobby_helpers.h"
int cMemMan_Deallocate();
int sprintf(void *, const void *, ...);

/* merge_units: begin func_0012FD60 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
float cGameSystem_UpdateTimeStep(void);
int cMoviePlayer_NextFrame(void*, float);
void cMoviePlayer_dtor(void*, int);
void cMemMan_ReleaseBin(int);
void* cSystemContainer_GetSystem(void*, void*);
void cGameSound_SetMasterVolume(void*, int, int);
void GameFlow_StartMovie(void*, void*, int);
extern char D_0049A890;
extern char D_004F2CC0[];
extern int D_004EA048;
}
class Q_12FD60 {
public:
    char e[0x10][0x80];
    int cur;
    int count;
    bool AtEnd() { return cur == count; }
    char* Next() {
        char* r = 0;
        int i;
        cur++;
        i = cur;
        if (i <= count) r = e[i - 1];
        return r;
    }
};
typedef struct {
    char pad[0xAC];
    Q_12FD60* q;
    void* b0;
} S_12FD60;

#pragma opt_common_subs off
extern "C" void cGameSystem_UpdateMovie(S_12FD60* self)
{
    if (self->b0) {
        bool done = !cMoviePlayer_NextFrame(self->b0, cGameSystem_UpdateTimeStep());
        if (done) {
            void* p = self->b0;
            {
                AllocGuard g;
                cMoviePlayer_dtor(p, -1);
                cMemMan_Deallocate(0, p, &D_0049A890, 0xAE2);
            }
            self->b0 = 0;
            cMemMan_ReleaseBin(1);
            cGameSound_SetMasterVolume(cSystemContainer_GetSystem(self, D_004F2CC0), 2, D_004EA048);
        }
    }
    if (!self->b0) {
        Q_12FD60* q = self->q;
        if (q) {
            if (!q->AtEnd()) {
                GameFlow_StartMovie(self, q->Next(), 1);
            } else {
                {
                    AllocGuard g;
                    cMemMan_Deallocate(0, q, &D_0049A890, 0xAF7);
                }
                self->q = 0;
            }
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0012FD60(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0012FD60 */

/* merge_units: begin func_0012FF50 */
#pragma push /* merge_units */
void cGameSystem_EndMovie(int a0) {
    int v1;
    int cond;

    a0 = *(int*)((char*)a0 + 176);
    cond = a0 == 0;
    if (cond) goto L0012FF70;
    v1 = *(unsigned char*)((char*)a0 + 561);
    cond = v1 != 0;
    v1 = 0 + 1;
    if (cond) goto L0012FF70;
    *(char*)((char*)a0 + 565) = v1;
L0012FF70:;
    goto ret;
ret:;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0012FF50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0012FF50 */

/* merge_units: begin func_0012FF80 */
#pragma push /* merge_units */
int Game_PickAttractMovie(void* o, char* out); /* gsynth: defined below */
typedef struct Sub12FF80 {
    char pad0[0xC4];
    int id;
} Sub12FF80;

typedef struct Ent12FF80 {
    char x0;
    char name[0x1F];
} Ent12FF80;

typedef struct Info12FF80 {
    char pad0[0x38];
    Ent12FF80 ents[1];
    char pad58[0xE4];
    int count;
    char pad140[0x48];
    Sub12FF80 sub;
} Info12FF80;

typedef struct Obj12FF80 {
    char pad0[0x50];
    unsigned char state;
    signed char prev;
    char pad52[0xF];
    unsigned char x61;
    char pad62[0x52];
    Info12FF80 * volatile info;
    char padB8[0x88];
    char name[0x20];
} Obj12FF80;

extern void *cGameSystem_GetAgentData(void *, int);
extern int String_CompareNoCase(const char *, const char *);
#if 0 /* merge_units */
extern int Game_PickAttractMovie(Obj12FF80 *, char *);
#endif /* merge_units */
#define Game_PickAttractMovie(a0, a1) (Game_PickAttractMovie((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void GameFlow_StartMovie(Obj12FF80 *, char *, int);
#endif /* merge_units */
#define GameFlow_StartMovie(a0, a1, a2) (GameFlow_StartMovie((void *)(a0), (void *)(a1), (a2))) /* merge_units */

extern void cGameSystem_QueueMovie(Obj12FF80 *, char *);
extern void cGameFrontEnd_BuildFinalMovie(void *);
extern void cAgentData_UnlockZeus(void *, int, int, int);
extern void cAgentData_SetZeusItemSeen(void *, int, int, int, int);
extern void *D_004FFC04;
extern signed char g_GameState;
extern signed char g_PrevGameState;

void cGameSystem_PlayMovie_void(Obj12FF80 *o)
{
    char out[0x80];
    char sel[0x90];
    char buf[0x100];
    const char *a;
    const char *b;
    int i;

    if (o->x61 == 0)
        return;
    if (o->state != 8) {
        sel[0] = 0;
        switch (o->state) {
        case 7:
            a = "";
            b = "INTRO";
            if (Game_PickAttractMovie(o, sel) != 0)
                b = &sel[1];
            break;
        case 9:
            a = "";
            b = "INTRO";
            break;
        case 11:
            a = o->name;
            b = "_SOL";
            break;
        case 12: {
            int id;
            Sub12FF80 *sub;
            Info12FF80 *in;
            a = o->name;
            in = o->info;
            id = in->sub.id;
            sub = &in->sub;
            if (id != -1 && id != 0x11) {
                cAgentData_UnlockZeus(cGameSystem_GetAgentData(o, -1), id + 1, 6, 2);
                cAgentData_SetZeusItemSeen(cGameSystem_GetAgentData(o, -1), sub->id + 1, 5, 1, 1);
            }
            if (String_CompareNoCase(a, "UKRAINE") == 0) {
                cGameFrontEnd_BuildFinalMovie(o->info);
                o->prev = *(signed char *)&o->state;
                o->state = 8;
                cGameSystem_PlayMovie_void(o);
                return;
            }
            cGameFrontEnd_BuildFinalMovie(D_004FFC04);
            b = "_EOL";
            g_PrevGameState = g_GameState;
            g_GameState = 8;
            break;
        }
        default:
            return;
        }
        sprintf(out, "%s%s.PSS", a, b);
        GameFlow_StartMovie(o, out, 1);
    } else {
        for (i = 0; i < o->info->count; i++) {
            sprintf(buf, "%s.PSS", o->info->ents[i].name);
            cGameSystem_QueueMovie(o, buf);
        }
    }
}
#undef Game_PickAttractMovie /* merge_units */
#undef GameFlow_StartMovie /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0012FF80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0012FF80 */

/* merge_units: begin func_001301D0 */
#pragma push /* merge_units */
int Game_CountAttractMovies(int arg0); /* gsynth: defined below */
#if 0 /* merge_units */
extern int Game_CountAttractMovies(void *);
#endif /* merge_units */
#define Game_CountAttractMovies(a0) (Game_CountAttractMovies((int)(a0))) /* merge_units */

extern char D_0049A908[];
extern int D_004EA050;
extern int g_TimerAccum;

int Game_PickAttractMovie(void *o, char *out)
{
    char buf[0x20];
    int count;
    int r;
    char *d;
    char *s;
    char c;
    int n;

    count = Game_CountAttractMovies(o);
    r = (*(volatile int *)0x10000800 + g_TimerAccum) % count;
    if (r == D_004EA050 && count > 1) {
        r = (r == count - 1) ? 0 : r + 1;
    }
    D_004EA050 = r;
    if (r == 0)
        Libc_Strcpy(buf, D_0049A908);
    else
        sprintf(buf, "DEMO%2.2d", r);
    d = out + 1;
    s = buf;
    n = 0;
    while ((*d++ = *s++) != 0) {
        if (++n >= 0x7E) {
            n++;
            d[0] = '\n';
            d[1] = 0;
            break;
        }
    }
    out[0] = n;
    return 1;
}
#undef Game_CountAttractMovies /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001301D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001301D0 */

/* merge_units: begin func_001302F0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
char * cHogList_Open(int, char *, int, int);                 
int cHogFile_GetBlockIndex();                  
int cHogList_Close();                       
extern int D_00489BE0;

int Game_CountAttractMovies(int arg0) {
    int sp50[32];
    int sp30[8];
    char * temp_v0;

    if (D_00489BE0 != -1) {
        return D_00489BE0;
    }
    sprintf(sp50, "ZMEDIA\\ZMOVIES.HOG");
    temp_v0 = (char *)(cHogList_Open(arg0 + 0x3C, sp50, 1, 0));
    if (F_(temp_v0, 0x14C, unsigned char) != 0) {
        D_00489BE0 = 0;
loop_5:
        sprintf(sp30, "DEMO%2.2d.PSS", D_00489BE0 + 1);
        if (cHogFile_GetBlockIndex(temp_v0, sp30, 1) != -1) {
            D_00489BE0 += 1;
            goto loop_5;
        }
    }
    cHogList_Close(arg0 + 0x3C, temp_v0);
    D_00489BE0 += 1;
    return D_00489BE0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001302F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001302F0 */
