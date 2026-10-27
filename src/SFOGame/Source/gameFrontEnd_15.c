/*
 * SFOGame/Source/gameFrontEnd: 4 files, 002CAE30-002CB3D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002CAE30 */
#pragma push /* merge_units */
#include "types.h"

#pragma exceptions off
#pragma cplusplus on

class Mgr {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22();
    virtual void Add(void* p, int t);
};

struct Str;
extern "C" {
Mgr* Gui_Canvas(void);
void* func_002CAC70(void* p);
void* func_002CAC60(void* p);
void func_002CAC50(void** it, void* n);
int std_basic_string_char_char_traits_char_c_str(Str* p);
void GuiMessageBox_SetInfo(void* o, int a, int b, int c, int d, int e);
void cString_ctor_void(Str* s);
void std_basic_string_char_char_traits_char_ctor_charP(Str* s, const char* c);
void std_basic_string_char_char_traits_char_assign_basicstringR(Str* d, Str* s);
void String_Dtor(Str* s, int f);
void std_list_deleter_MessageBoxEntry_insert(void* ret, void* list, void** it, void* ent);
void GuiWidget_SendMessage(Mgr* a, Mgr* b, int c, int d, int e);
extern char D_004ACFE0[];
}

#pragma define_section DROPDTOR ".dtors_drop" far_absolute RX

struct Str {
    int w;
    int l;
    char* d;
    Str() { cString_ctor_void(this); }
    Str(const char* s) { Str* p = this; std_basic_string_char_char_traits_char_ctor_charP(p, s ? s : D_004ACFE0); }
    __declspec(weak) __declspec(DROPDTOR) ~Str() { String_Dtor(this, 0); }
    Str& operator=(const Str& o) { std_basic_string_char_char_traits_char_assign_basicstringR(this, (Str*)&o); return *this; }
};

struct Ent {
    int id;
    int a4;
    Str s8;
    Str s14;
    int a20;
    int a24;
    __declspec(weak) __declspec(DROPDTOR) ~Ent() {}
};

struct Node_002CAE30 {
    int pad0;
    Node_002CAE30* next;
    int pad8;
    int state;
};

struct Obj258 {
    char pad[0x10];
    int id;
    unsigned short flags;
};

struct SelfCAE30 {
    char pad[0x258];
    Obj258* obj;
    char pad2[0x2FC - 0x25C];
    int list;
    int list300;
    Node_002CAE30* head;
    int counter;
};

extern "C" int cGameFrontEnd_PushMessageBox(SelfCAE30* self, int a4, const char* n1, const char* n2, int a20, int a24)
{
    if (!self->obj)
        return -1;
    {
        Ent e;
        bool first;
        char ret[4];
        void* end;
        char ret2[4];
        void* tmp2;
        void* tmp;
        e.id = self->counter++;
        e.a4 = a4;
        e.s8 = Str(n1);
        e.s14 = Str(n2);
        e.a20 = a20;
        e.a24 = a24;
        first = 1;
        if (self->list) {
            Node_002CAE30* n = (Node_002CAE30*)((Node_002CAE30*)func_002CAC70(&self->list300))->next;
            for (;;) {
                func_002CAC50(&end, func_002CAC60(&self->list));
                if (n == end || n->state != 1) {
                    tmp = n;
                    std_list_deleter_MessageBoxEntry_insert(ret, &self->list, &tmp, &e);
                    break;
                }
                n = n->next;
                first = 0;
            }
        } else {
            tmp2 = self->head;
            std_list_deleter_MessageBoxEntry_insert(ret2, &self->list, &tmp2, &e);
        }
        if (first) {
            int c = std_basic_string_char_char_traits_char_c_str(&e.s14);
            GuiMessageBox_SetInfo(self->obj, e.a4, std_basic_string_char_char_traits_char_c_str(&e.s8), c, e.a20, e.a24);
            self->obj->id = e.id;
            {
                Obj258* o = self->obj;
                if (!(o->flags & 8)) {
                    Gui_Canvas()->Add(o, 1000);
                    GuiWidget_SendMessage(Gui_Canvas(), Gui_Canvas(), 0x10, 2, 0);
                }
            }
        }
        return e.id;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002CAE30(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002CAE30 */

/* merge_units: begin func_002CB0E0 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
void operator_delete(void* p);
#if 0 /* merge_units */
void String_Dtor(void* m, int flags);
#endif /* merge_units */
#define String_Dtor(a0, a1) (String_Dtor((Str *)(a0), (a1))) /* merge_units */


}
extern "C" void* cGameFrontEnd_MessageBoxEntry_dtor(void* self, short deleteFlag)
{
    if (self) {
        void* m;
        m = (char*)self + 0x14;
        if (m) String_Dtor(m, 0);
        m = (char*)self + 0x8;
        if (m) String_Dtor(m, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002CB0E0(void) {}
#undef String_Dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002CB0E0 */

/* merge_units: begin func_002CB160 */
#pragma push /* merge_units */
#pragma cplusplus on
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
static inline void merge_flush_func_002CB160(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002CB160 */

/* merge_units: begin func_002CB3D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_propagation off
#include "vslot_pad.h"
struct Msg3D0 { void* vt; char pad4[0x2C]; };
struct PStr3D0 { unsigned char len; char s[0x80]; };
class Scr3D0 {
public:
    VPAD16(a) VPAD4(b) virtual int IsA(void* t);
};
class Stk3D0 {
public:
    VPAD16(a) VPAD4(b) VPAD2(c) VPAD1(d) virtual void Push(Scr3D0* s, int f);
    char p4[0x4D];
    unsigned char b51;
    char p52[0x16];
    int x68;
};
struct Slot3D0 {
    char pad[0x1F0];
    float v[4];
    char pad200[0x2F5 - 0x200];
    char f2F5;
    char f2F6;
};
struct Self3D0 {
    char p0[0x20];
    long long x20;
    unsigned char b28;
    char p29[3];
    unsigned char b2C;
    char p2D[3];
    unsigned char b30;
    char p31;
    unsigned char b32;
    char p33[2];
    unsigned char b35;
    unsigned char b36;
    unsigned char b37;
    char p38[0x258 - 0x38];
    Scr3D0* p258;
    char p25C[0x30C - 0x25C];
    int x30C;
};
struct W3D0 { char pad[0x278]; unsigned char b278; };
extern "C" {
extern char D_004ACFE8[];
extern char D_004ACFF8[];
extern char D_004AD1F8[];
extern char D_004AD000[];
extern char D_004AD010[];
extern char D_004AD020[];
extern char D_004AD038[];
extern int D_00538C60;
extern float D_00539170[4];
extern char D_004F5370[];
extern char D_004F5378[];
extern char D_004DE220[];
extern char D_004DE200[];
void cGameFrontEnd_Restore(Self3D0* self);
void FrontEnd_CreateCanvas(Self3D0* self, unsigned char flag);
#if 0 /* merge_units */
Stk3D0* Gui_Canvas(void);
#endif /* merge_units */
#define Gui_Canvas() ((Stk3D0 *)Gui_Canvas()) /* merge_units */

int Gui_Manager(void);
void GuiCanvas_Activate(Stk3D0* s, int x);
Scr3D0* GuiManager_ConstructGui(int l, char* a, char* b);
Scr3D0* GuiManager_OpenGui(int l, char* a, char* b);
#if 0 /* merge_units */
int cDME_GetLobby(void);
#endif /* merge_units */
#define cDME_GetLobby() ((int)cDME_GetLobby()) /* merge_units */

void SFOLobby_InitLists(int g);
void cDME_StartUpdateThread(void);
long long cTimer_GetMillisecondTime(void);
void FrontEnd_SetLoadingScreen(Self3D0* self, int a, int b, int c);
void cMessage_ctor_cMessageNameR(void* m, void* type);
void QueueMessage_cMessageR_cSystemP_int(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
#if 0 /* merge_units */
void GuiWidget_SendMessage(Stk3D0* a, Stk3D0* b, int c, int d, int e);
#endif /* merge_units */
#define GuiWidget_SendMessage(a0, a1, a2, a3, a4) (GuiWidget_SendMessage((Mgr *)(a0), (Mgr *)(a1), (a2), (a3), (a4))) /* merge_units */

void FrontEnd_GetCharacterData(Self3D0* self);
void cGameFrontEnd_OpenZeusHog(Self3D0* self);
void cWeaponDB_OpenWeaponsHog(int a);
void cDME_StopUpdateThread(void);
void func_002CA6F0(Self3D0* self);
void cDME_ActivateLobby(int a);
void FrontEnd_FlushMessages(Self3D0* self);
void SFOLobby_Reset(int g, int a);
#if 0 /* merge_units */
W3D0* GetMachine(void);
#endif /* merge_units */
#define GetMachine() ((W3D0 *)GetMachine()) /* merge_units */

void cUSBKeybd_SetKeyMode(void* p);
}
extern "C" void cGameFrontEnd_InitGui(Self3D0* self, unsigned char flag)
{
    Scr3D0* scr;
    if (self->b28) return;
    if (self->b37) {
        cGameFrontEnd_Restore(self);
        return;
    }
    FrontEnd_CreateCanvas(self, flag);
    { Stk3D0* st = Gui_Canvas(); st->b51 = !flag; }
    GuiCanvas_Activate(Gui_Canvas(), 0);
    GuiCanvas_Activate(Gui_Canvas(), 1);
    Gui_Canvas()->x68 = 0;
    if (!flag) Gui_Canvas()->x68 |= 0xF000;
    scr = GuiManager_ConstructGui(Gui_Manager(), D_004ACFE8, D_004ACFF8);
    scr = (scr && scr->IsA(D_004AD1F8)) ? scr : 0;
    self->p258 = scr;
    if (!flag) {
        unsigned char had;
        unsigned char go;
        Scr3D0* next;
        void* svc;
        PStr3D0 buf;
        Msg3D0 m1;
        Msg3D0 m2;
        {
            Slot3D0* s = (Slot3D0*)(g_Video + D_00538C60 * 0x110);
            float* v = D_00539170;
            s->v[0] = v[0];
            s->v[1] = v[1];
            s->v[2] = v[2];
            s->v[3] = v[3];
            s->f2F5 = 1;
            s->f2F6 = 1;
        }
        had = 0;
        if (cDME_GetLobby()) {
            SFOLobby_InitLists(cDME_GetLobby());
            cDME_StartUpdateThread();
            had = 1;
        }
        self->x20 = cTimer_GetMillisecondTime();
        go = 0;
        FrontEnd_SetLoadingScreen(self, 1, 0, 0);
        self->x30C = -1;
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
        svc = cSystemContainer_GetSystem(g_Game, D_004F2CC0);
        cMessage_ctor_cMessageNameR(&m1, D_004F5370);
        m1.vt = D_004DE220;
        QueueMessage_cMessageR_cSystemP_int(&m1, svc, 1);
        m1.vt = D_004DE220;
        cMessage_dtor(&m1, 0);
        cMessage_ctor_cMessageNameR(&m2, D_004F5378);
        m2.vt = D_004DE200;
        QueueMessage_cMessageR_cSystemP_int(&m2, svc, 1);
        m2.vt = D_004DE200;
        cMessage_dtor(&m2, 0);
        strncpy(g_LevelDirName, buf.s, 0x80);
        {
            Stk3D0* a = Gui_Canvas();
            GuiWidget_SendMessage(a, Gui_Canvas(), 0x10, 5, 0);
        }
        if (self->b2C) {
            GuiManager_OpenGui(Gui_Manager(), D_004AD000, D_004AD010);
            GuiManager_OpenGui(Gui_Manager(), D_004AD020, D_004AD038);
            FrontEnd_GetCharacterData(self);
        }
        if (self->b35) {
            self->b35 = 0;
            next = GuiManager_OpenGui(Gui_Manager(), D_004AD020, D_004AD038);
            if (self->b30 && !self->b32) go = 1;
        } else {
            next = GuiManager_OpenGui(Gui_Manager(), D_004AD000, D_004AD010);
        }
        cGameFrontEnd_OpenZeusHog(self);
        cWeaponDB_OpenWeaponsHog(g_WeaponDatabase);
        FrontEnd_SetLoadingScreen(self, 0, 0, 0);
        if (had) cDME_StopUpdateThread();
        Gui_Canvas()->Push(next, 0);
        if (go && !cDME_GetLobby()) {
            func_002CA6F0(self);
            cDME_ActivateLobby(1);
            if (cDME_GetLobby()) {
                FrontEnd_FlushMessages(self);
                SFOLobby_Reset(cDME_GetLobby(), 1);
                cDME_ActivateLobby(0);
            }
        }
    }
    GetMachine()->b278 = flag;
    if (!flag) cUSBKeybd_SetKeyMode(D_0055A700);
    self->b28 = 1;
    self->b36 = flag;
}
#undef Gui_Canvas /* merge_units */
#undef cDME_GetLobby /* merge_units */
#undef GuiWidget_SendMessage /* merge_units */
#undef GetMachine /* merge_units */
static inline void merge_flush_func_002CB3D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002CB3D0 */
