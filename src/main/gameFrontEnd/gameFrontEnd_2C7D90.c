/*
 * main/gameFrontEnd: range (4 files, 002C7D90-002C81D0)
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
int Mem_Free();

/* merge_units: begin func_002C7D90 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
struct Obj81D0 { char pad[0x310]; unsigned char active; };
extern "C" void FrontEnd_StopSplashThread(Obj81D0* o); /* gsynth: defined below */
#pragma pop
#pragma cplusplus on
class VObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void f64(int h, int n);
    virtual void f68(int h);
};

typedef struct {
    char pad[0xC];
    unsigned char type;
    char padD[0x14 - 0xD];
    int value;
} Prop;

typedef struct {
    char pad[0x29];
    unsigned char f29;
    char pad2A[0x2D - 0x2A];
    unsigned char f2D;
    char pad2E[0x37 - 0x2E];
    unsigned char f37;
} Self7D90;

extern "C" {
extern void func_002C7C40(char* s, int n);
#if 0 /* merge_units */
extern void FrontEnd_StopSplashThread(Self7D90* self);
#endif /* merge_units */
#define FrontEnd_StopSplashThread(a0) (FrontEnd_StopSplashThread((Obj81D0 *)(a0))) /* merge_units */

extern void FrontEnd_StartSplashThread(Self7D90* self);
extern long long Time_GetMilliseconds(unsigned char on);
extern int Gui_GetScreenList(void);
extern VObj* Gui_GetScreenStack(void);
extern int GuiManager_FindOrLoad(int a, char* b, char* c);
extern void GuiManager_Update(int a, float f);
extern int GuiWidget_FindChildByName(int h, char* name);
extern int GuiWidget_SendEvent(VObj* o, int h, int n, int name, int out);
extern char D_004ACEA8[];
extern char D_004ACEB0[];
extern char D_004ACEB8[];
extern char D_004ACEC8[];
extern char D_004ACED8[];
extern unsigned char D_004FFBB2;
extern int D_0051EF78;
extern int D_0051EF80;
extern int D_0051EF88;
extern int D_0051EF90;
extern unsigned char g_GuiSoundGate;
}

extern "C" void FrontEnd_SetLoadingScreen(Self7D90* self, int on, char* a, char* b)
{
    if (self->f37) {
        return;
    }
    if ((unsigned char)on == self->f2D) {
        return;
    }
    if (!self->f29) {
        return;
    }
    if (on) {
        D_0051EF78 = Time_GetMilliseconds((unsigned char)on);
    }
    if (!D_004FFBB2) {
        if (on) {
            func_002C7C40(D_004ACEA8, 3000);
        }
        return;
    }
    if (on) {
        g_GuiSoundGate = 1;
        a = a ? a : D_004ACEB0;
        b = b ? b : D_004ACEB8;
        D_0051EF80 = GuiManager_FindOrLoad(Gui_GetScreenList(), b, a);
        {
            VObj* o = Gui_GetScreenStack();
            o->f64(D_0051EF80, 1000);
        }
        self->f2D = 1;
        D_0051EF90 = 0;
        if (D_0051EF80) {
            D_0051EF88 = GuiWidget_FindChildByName(D_0051EF80, D_004ACEC8);
            {
                int h = D_0051EF88;
                if (h) {
                    Prop* p = 0;
                    if (GuiWidget_SendEvent(Gui_GetScreenStack(), h, 4, (int)D_004ACED8, (int)&p) && p->type == 1) {
                        D_0051EF90 = p->value;
                    }
                }
            }
        }
        FrontEnd_StartSplashThread(self);
    } else {
        FrontEnd_StopSplashThread(self);
        {
            VObj* o = Gui_GetScreenStack();
            o->f68(D_0051EF80);
        }
        GuiManager_Update(Gui_GetScreenList(), 0.0f);
        g_GuiSoundGate = 0;
        D_0051EF80 = 0;
        D_0051EF88 = 0;
        self->f2D = 0;
    }
}
#undef FrontEnd_StopSplashThread /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002C7D90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002C7D90 */

/* merge_units: begin func_002C7FC0 */
#pragma push /* merge_units */
extern char* DME_GetLobby(void);
extern char g_Game[];
extern void* Agent_GetSelected(char* name, int index);
extern int D_0052FE80;
extern void* func_00336E80(void* agent, int i);
extern void LobbyArray_Append(void* list, void* item);
int func_002C7FC0(void)
{
    char* owner = DME_GetLobby();
    void* agent = Agent_GetSelected(g_Game, -1);
    void* list;
    int i;
    if (!owner || !agent)
        return 0;
    list = owner + 0x1C;
    if (!list)
        return 0;
    for (i = 0; i < D_0052FE80; i++)
        LobbyArray_Append(list, func_00336E80(agent, i));
    return 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002C7FC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002C7FC0 */

/* merge_units: begin func_002C8090 */
#pragma push /* merge_units */
typedef struct { int type; } E2C8090;
typedef struct { int a; int count; } L2C8090;
typedef struct { char pad[0xB73]; unsigned char flag; } A2C8090;
#if 0 /* merge_units */
extern A2C8090* Agent_GetSelected(void*, int);
#endif /* merge_units */
#define Agent_GetSelected(a0, a1) ((A2C8090 *)Agent_GetSelected((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern char g_Game;
#endif /* merge_units */
#define g_Game (*(char*)&g_Game) /* merge_units */

#define LobbyArray_At(a0, a1) ((E2C8090 *)LobbyArray_At((a0), (a1))) /* merge_units */
extern void func_00336EC0(A2C8090*, E2C8090*);
int FrontEnd_FlushMessages(void) {
    char* g = DME_GetLobby();
    A2C8090* ag = Agent_GetSelected(&g_Game, -1);
    int i;
    L2C8090* l;
    int n;
    if (!g || !ag) return 0;
    l = (L2C8090*)(g + 0x1C);
    if (!l) return 0;
    if (l->count != 0 || D_0052FE80 != 0) ag->flag = 1;
    D_0052FE80 = 0;
    n = l->count;
    if (n > 0x40) return 0;
    for (i = 0; i < n; i++) {
        E2C8090* e = LobbyArray_At(l, i);
        if (e) {
            switch (e->type) {
            case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 11:
                func_00336EC0(ag, e);
                break;
            }
        }
    }
    return 1;
}
#undef LobbyArray_At /* merge_units */
#undef Agent_GetSelected /* merge_units */
#undef g_Game /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002C8090(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002C8090 */

/* merge_units: begin func_002C81D0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
extern int D_0048C358;
extern int D_0048C350;
extern int D_0048C348;
extern void* g_SplashThreadStack;
void RemoveIntcHandler(int id, int sema);
void TerminateThread(int thread);
void DeleteThread(int thread);
}

extern "C" void FrontEnd_StopSplashThread(Obj81D0* o)
{
    if (o->active) {
        Alloc_Lock(2);
        RemoveIntcHandler(2, D_0048C358);
        D_0048C348 = -1;
        if (D_0048C350 != -1) {
            TerminateThread(D_0048C350);
            DeleteThread(D_0048C350);
            D_0048C350 = -1;
        }
        D_0048C358 = -1;
        {
            void* p = g_SplashThreadStack;
            AllocGuard guard;
            Mem_Free(0, p, "gameFrontEnd.cc", 0x89C);
        }
        g_SplashThreadStack = 0;
        o->active = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002C81D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002C81D0 */
