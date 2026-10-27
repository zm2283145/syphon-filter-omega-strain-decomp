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
void Gui_Destroy(void);
void cInterfaceManager_Reset(void* p);
void FrontEnd_StopSplashThread(Self_002CB160* self);
void XLib_NextFrame(void* p);
void cMemMan_Deallocate(int heap, void* p, char* file, int line);
W_002CB160* GetMachine(void);
void cUSBKeybd_SetAsciiMode(void* p);
void cGameFrontEnd_CloseZeusHog(Self_002CB160* self);
void cWeaponDB_CloseWeaponsHog(int a);
void cGameFrontEnd_CloseCharacter(Self_002CB160* self, int a);
void* cSystemContainer_GetSystem(void* a, void* b);
char* strncpy(char* d, const char* s, int n);
void cGameSound_Unload(void* svc);
void* cDME_GetLobby(void);
void SFOLobby_FreeLists(void* g);
void Renderer_Teardown(void* p);
void std_list_deleter_MessageBoxEntry_erase_listdeleter_listdeleter(Node_002CB160** out, int* list, Node_002CB160** first, Node_002CB160** last);
}
extern "C" void cGameFrontEnd_DestroyGui(Self_002CB160* self)
{
    if (self->b28) {
        Gui_Destroy();
        cInterfaceManager_Reset(D_00571DC0);
        if (self->b310)
            FrontEnd_StopSplashThread(self);
        if (!self->b36) {
            int i;
            Obj_002CB160* p;
            void* svc;
            for (i = 0; i < 3; i++)
                XLib_NextFrame(g_Video);
            p = self->p260;
            if (p) {
                AllocGuard g;
                p->Destroy(-1);
                cMemMan_Deallocate(0, p, D_004ACF10, 0x465);
            }
            self->p260 = 0;
            { W_002CB160* w = GetMachine(); w->b278 = 1; }
            cUSBKeybd_SetAsciiMode(D_0055A700);
            cGameFrontEnd_CloseZeusHog(self);
            cWeaponDB_CloseWeaponsHog(g_WeaponDatabase);
            cGameFrontEnd_CloseCharacter(self, 1);
            svc = cSystemContainer_GetSystem(g_Game, D_004F2CC0);
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
                cGameSound_Unload(svc);
                strncpy(g_LevelDirName, buf.s, 0x80);
            }
            if (cDME_GetLobby())
                SFOLobby_FreeLists(cDME_GetLobby());
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
            std_list_deleter_MessageBoxEntry_erase_listdeleter_listdeleter(&res, &self->list, &first, &last);
        }
    }
}