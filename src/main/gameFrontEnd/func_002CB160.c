#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct PStr_002CB160 { unsigned char len; char s[0x80]; };
struct Obj_002CB160 { virtual void Destroy(int flags); };
struct Node_002CB160 { void* prev; Node_002CB160* next; };
struct Self_002CB160 {
    char pad0[0x28]; unsigned char b28; unsigned char b29; char pad2A[0xC]; unsigned char b36;
    char pad37[0x258 - 0x37]; void* p258; char pad25C[4]; Obj_002CB160* p260;
    char pad264[0x2FC - 0x264]; int list; Node_002CB160 head; char pad308[8]; unsigned char b310;
};
struct W_002CB160 { char pad[0x278]; unsigned char b278; };
extern "C" {
extern char D_00571DC0[];
extern char g_Video[];
extern char D_004ACF10[];
extern char D_0055A700[];
extern int g_WeaponDatabase;
extern char g_Game[];
extern char D_004F2CC0[];
extern char g_LevelDirName[];
extern char D_004ACF48[];
void GuiCanvas_Destroy(void);
void func_004139C0(void* p);
void FrontEnd_StopSplashThread(Self_002CB160* self);
void Video_BeginFrame(void* p);
void Mem_Free(int heap, void* p, char* file, int line);
W_002CB160* App_GetInstance(void);
void func_003D1700(void* p);
void FrontEnd_UnloadZeusHog(Self_002CB160* self);
void WeaponDb_UnloadWpnHog(int a);
void func_002C9C80(Self_002CB160* self, int a);
void* Service_Lookup(void* a, void* b);
char* strncpy(char* d, const char* s, int n);
void SoundMgr_UnloadLevel(void* svc);
void* DME_GetLobby(void);
void func_004538D0(void* g);
void Renderer_Teardown(void* p);
void func_002CDEF0(Node_002CB160** out, int* list, Node_002CB160** first, Node_002CB160** last);
}
extern "C" void FrontEnd_TeardownGui(Self_002CB160* self)
{
    if (self->b28) {
        GuiCanvas_Destroy();
        func_004139C0(D_00571DC0);
        if (self->b310)
            FrontEnd_StopSplashThread(self);
        if (!self->b36) {
            int i;
            Obj_002CB160* p;
            void* svc;
            for (i = 0; i < 3; i++)
                Video_BeginFrame(g_Video);
            p = self->p260;
            if (p) {
                AllocGuard g;
                p->Destroy(-1);
                Mem_Free(0, p, D_004ACF10, 0x465);
            }
            self->p260 = 0;
            { W_002CB160* w = App_GetInstance(); w->b278 = 1; }
            func_003D1700(D_0055A700);
            FrontEnd_UnloadZeusHog(self);
            WeaponDb_UnloadWpnHog(g_WeaponDatabase);
            func_002C9C80(self, 1);
            svc = Service_Lookup(g_Game, D_004F2CC0);
            if (svc) {
                PStr_002CB160 buf;
                {
                    char* d = buf.s;
                    const char* s = g_LevelDirName;
                    int n = 0;
                    while ((*d++ = *s++) != 0) {
                        if (++n >= 0x7E) {
                            n++;
                            *d = '\n';
                            d[1] = 0;
                            break;
                        }
                    }
                    buf.len = n;
                }
                strncpy(g_LevelDirName, D_004ACF48, 0x80);
                SoundMgr_UnloadLevel(svc);
                strncpy(g_LevelDirName, buf.s, 0x80);
            }
            if (DME_GetLobby())
                func_004538D0(DME_GetLobby());
            Renderer_Teardown(g_Video);
        }
        self->b29 = 0;
        self->b28 = 0;
        self->p258 = 0;
        {
            Node_002CB160* res;
            Node_002CB160* first;
            Node_002CB160* last;
            last = &self->head;
            first = self->head.next;
            func_002CDEF0(&res, &self->list, &first, &last);
        }
    }
}