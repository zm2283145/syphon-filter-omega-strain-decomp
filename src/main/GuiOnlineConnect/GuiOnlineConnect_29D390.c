/*
 * main/GuiOnlineConnect: 3 files, 0029D390-0029DAF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0029D390 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_common_subs off
#include "types.h"
struct Stack_D390 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void Show(void* w, int ms); virtual void Hide(void* w); };
typedef struct { int a; int b; int c; int d; } Str_D390;
typedef struct { void* data; int count; char pad8[0x18]; } List_D390;
typedef struct { char pad0[0x2A]; unsigned char b2A; char pad2B[0x265 - 0x2B]; unsigned char b265; char pad266[2]; int x268; } Fe_D390;
typedef struct { char pad0[0x88]; int x88; char pad8c[0x94 - 0x8C]; unsigned char b94; char pad95[0xD0 - 0x95]; List_D390 lst; char padE8[0x108 - 0xD0 - 0x20]; void* x108; char pad10c[0x11C - 0x10C]; int x11C; int x120; } O_D390;
typedef struct { char pad0[0x8DC]; char sub[0xC4]; int key; } Agent_D390;
typedef struct { int key; char name[4]; } Ent_D390;
extern "C" {
extern Fe_D390* D_004FFC04;
extern char g_Game[];
extern char D_004AABF0[];
extern char D_004AABF8[];
extern char D_004AAC08[];
int cGameFrontEnd_LobbyCallback(void);
int cDME_GetLobby(void);
void cGameFrontEnd_PopMessageBox(Fe_D390* fe, int id);
int cGameFrontEnd_PushMessageBox(Fe_D390* fe, int kind, char* title, char* text, O_D390* owner, int flags);
Stack_D390* Gui_Canvas(void);
char* GuiLobbyScreen_GetLobbyString(O_D390* o, int id, int a, int b, int c, int d);
void GuiOnlineConnect_Back(O_D390* o, int a);
void GuiOnlineConnect_Advance(O_D390* o);
void GuiLobbyScreen_PushLobbyScreen(O_D390* o, int a);
void SFOLobby_ConfigScreenExit(int n);
void SFOLobbyList_ctor(List_D390* l);
void SFOLobbyList_dtor(List_D390* l, int flags);
void* SFOLobbyList_GetSlot(List_D390* l, int i);
int SFOLobby_ServerScreenStart(int n, int (*cb)(void), List_D390* l);
char* cSFOini_GetKeyValue(char* key);
int String_CompareNoCase(char* a, char* b);
char* func_002CA0E0(Fe_D390* fe);
void func_002CA100(Fe_D390* fe, char* s);
void cGameFrontEnd_LobbyStartAccountScreen(Fe_D390* fe);
int SFOLobby_ConnectUniverse(int n, int i);
void SFOLobby_ServerScreenExit(int n);
int SFOLobby_RegionSelect(int n, int i);
int SFOLobby_ServerSelect(int n);
void SFOLobby_GetAnnouncements(int n);
int SFOLobby_GetUsagePolicy(int n);
void SFOLobby_GetPrivacyPolicy(int n);
Agent_D390* cGameSystem_GetAgentData(char* a, int b);
void std_basic_string_char_char_traits_char_ctor_charP(Str_D390* s, char* text);
char* std_basic_string_char_char_traits_char_c_str(Str_D390* s);
void String_Dtor(Str_D390* s, int flags);
}
static inline bool Start_D390(O_D390* o)
{
    int n;
    Fe_D390* fe;
    int p;
    int old;
    n = cDME_GetLobby();
    if (!n) {
        GuiOnlineConnect_Back(o, 1);
        return false;
    }
    fe = D_004FFC04;
    p = cGameFrontEnd_PushMessageBox(fe, 0, D_004AABF0, GuiLobbyScreen_GetLobbyString(o, 0xD, 0, 0, 0, 0), 0, 0);
    old = o->x120;
    if (old != -1) cGameFrontEnd_PopMessageBox(D_004FFC04, old);
    cGameFrontEnd_LobbyStartAccountScreen(D_004FFC04);
    SFOLobby_GetAnnouncements(n);
    if (SFOLobby_GetUsagePolicy(n)) SFOLobby_GetPrivacyPolicy(n);
    cGameFrontEnd_PopMessageBox(D_004FFC04, p);
    return true;
}
static inline char* Prof_D390(Agent_D390* a) { return a->sub; }
static inline unsigned char Find_D390(int n, List_D390* l, bool any)
{
    unsigned char ok = 0;
    if (any) {
        Agent_D390* a = cGameSystem_GetAgentData(g_Game, -1);
        char* pr = Prof_D390(a);
        int key = *(int*)(pr + 0xC4);
        int j;
        char* name = pr + 0x80;
        for (j = 0; j < l->count; j++) {
            Ent_D390* e = (Ent_D390*)SFOLobbyList_GetSlot(l, j);
            if (e && e->key == key && String_CompareNoCase(e->name, name) == 0) {
                if (SFOLobby_RegionSelect(n, j)) ok = 1;
                break;
            }
        }
    }
    return ok;
}
extern "C" void GuiOnlineConnect_DnasRetry(O_D390* o)
{
    Str_D390 s2;
    Str_D390 t2;
    Str_D390 s1;
    Str_D390 t1;
    List_D390 lst;
    int n;
    void* w;
    Fe_D390* fe;
    unsigned char fail;
    n = cDME_GetLobby();
    if (!n) {
        cGameFrontEnd_PopMessageBox(D_004FFC04, o->x11C);
        GuiOnlineConnect_Back(o, 1);
        return;
    }
    w = o->x108;
    if (w) Gui_Canvas()->Hide(w);
    fe = D_004FFC04;
    o->x120 = cGameFrontEnd_PushMessageBox(fe, 0, D_004AABF0, GuiLobbyScreen_GetLobbyString(o, 0xF, 0, 0, 0, 0), 0, 0);
    cGameFrontEnd_PopMessageBox(D_004FFC04, o->x11C);
    SFOLobby_ConfigScreenExit(n);
    o->b94 = 0;
    D_004FFC04->b2A = 1;
    SFOLobbyList_ctor(&lst);
    fail = 0;
    if (SFOLobby_ServerScreenStart(n, cGameFrontEnd_LobbyCallback, &lst)) {
        char* cur;
        int found;
        int i;
        char* e;
        bool any;
        int ok;
        any = String_CompareNoCase(cSFOini_GetKeyValue(D_004AABF8), D_004AAC08) == 0;
        cur = func_002CA0E0(D_004FFC04);
        found = -1;
        for (i = 0; i < o->lst.count; i++) {
            e = (char*)SFOLobbyList_GetSlot(&o->lst, i);
            if (e && (String_CompareNoCase(e, cur) == 0 || any)) {
                func_002CA100(D_004FFC04, e + 0x104);
                found = i;
                break;
            }
        }
        if (found == -1) {
            char* txt;
            o->x88 = 4;
            std_basic_string_char_char_traits_char_ctor_charP(&s2, GuiLobbyScreen_GetLobbyString(o, 2, 0, 0, 0, 0));
            std_basic_string_char_char_traits_char_ctor_charP(&t2, GuiLobbyScreen_GetLobbyString(o, 0x84, 0, 0, 0, 0));
            txt = std_basic_string_char_char_traits_char_c_str(&t2);
            cGameFrontEnd_PushMessageBox(D_004FFC04, 2, std_basic_string_char_char_traits_char_c_str(&s2), txt, o, 0);
            cGameFrontEnd_PopMessageBox(D_004FFC04, o->x120);
            String_Dtor(&t2, 0);
            String_Dtor(&s2, 0);
            SFOLobbyList_dtor(&lst, -1);
            return;
        }
        if (!SFOLobby_ConnectUniverse(n, found)) {
            char* txt;
            o->x88 = 4;
            std_basic_string_char_char_traits_char_ctor_charP(&s1, GuiLobbyScreen_GetLobbyString(o, 3, 0, 0, 0, 0));
            std_basic_string_char_char_traits_char_ctor_charP(&t1, GuiLobbyScreen_GetLobbyString(o, 0x84, 0, 0, 0, 0));
            txt = std_basic_string_char_char_traits_char_c_str(&t1);
            cGameFrontEnd_PushMessageBox(D_004FFC04, 2, std_basic_string_char_char_traits_char_c_str(&s1), txt, o, 0);
            cGameFrontEnd_PopMessageBox(D_004FFC04, o->x120);
            SFOLobby_ServerScreenExit(n);
            String_Dtor(&t1, 0);
            String_Dtor(&s1, 0);
            SFOLobbyList_dtor(&lst, -1);
            return;
        }
        ok = Find_D390(n, &lst, any);
        if (!ok && !SFOLobby_ServerSelect(n)) fail = 1;
        SFOLobby_ServerScreenExit(n);
    } else {
        cGameFrontEnd_PopMessageBox(D_004FFC04, o->x120);
        GuiOnlineConnect_Back(o, 1);
        SFOLobbyList_dtor(&lst, -1);
        return;
    }
    if (D_004FFC04->b265 || fail) {
        o->x88 = 6;
        D_004FFC04->x268 = 0;
        GuiLobbyScreen_PushLobbyScreen(o, 5);
    } else {
        o->x88 = 7;
        if (Start_D390(o)) GuiOnlineConnect_Advance(o);
    }
    cGameFrontEnd_PopMessageBox(D_004FFC04, o->x120);
    SFOLobbyList_dtor(&lst, -1);
}
#pragma pop /* merge_units */
/* merge_units: end func_0029D390 */

/* merge_units: begin func_0029D980 */
#pragma push /* merge_units */
typedef struct { int a[4]; } Str_D980;
typedef struct { char pad[0x88]; int x88; char pad8c[0x11C - 0x8C]; int x11C; } O_D980;
#if 0 /* merge_units */
extern int D_004FFC04;
#endif /* merge_units */
#define D_004FFC04 (*(int*)&D_004FFC04) /* merge_units */

extern char D_004AAC10[];
extern void GetDNASErrorStrings(void*, char*, char*, char*);
#if 0 /* merge_units */
extern void std_basic_string_char_char_traits_char_ctor_charP(Str_D980*, char*);
#endif /* merge_units */
#define std_basic_string_char_char_traits_char_ctor_charP(a0, a1) (std_basic_string_char_char_traits_char_ctor_charP((Str_D390 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern char* std_basic_string_char_char_traits_char_c_str(Str_D980*);
#endif /* merge_units */
#define std_basic_string_char_char_traits_char_c_str(a0) (std_basic_string_char_char_traits_char_c_str((Str_D390 *)(a0))) /* merge_units */

extern void std_basic_string_char_char_traits_char_append_basicstringR(Str_D980*, Str_D980*);
#if 0 /* merge_units */
extern void String_Dtor(Str_D980*, int);
#endif /* merge_units */
#define String_Dtor(a0, a1) (String_Dtor((Str_D390 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void cGameFrontEnd_PushMessageBox(int, int, char*, char*, O_D980*, int);
#endif /* merge_units */
#define cGameFrontEnd_PushMessageBox(a0, a1, a2, a3, a4, a5) ((void)cGameFrontEnd_PushMessageBox((Fe_D390 *)(a0), (a1), (a2), (a3), (O_D390 *)(a4), (a5))) /* merge_units */

#if 0 /* merge_units */
extern void cGameFrontEnd_PopMessageBox(int, int);
#endif /* merge_units */
#define cGameFrontEnd_PopMessageBox(a0, a1) (cGameFrontEnd_PopMessageBox((Fe_D390 *)(a0), (a1))) /* merge_units */


static inline void Zero(char* q, int n)
{
    if (q) {
        do {
            *q++ = 0;
        } while (--n);
    }
}

#pragma opt_propagation off
#pragma optimize_for_size on
void GuiOnlineConnect_DisplayDNASError(O_D980* o, void* src) {
    Str_D980 s;
    Str_D980 t;
    Str_D980 u;
    char title[0x80];
    char body[0x100];
    char extra[0x80];
    int flags;
    Zero(title, 0x80);
    Zero(body, 0x100);
    Zero(extra, 0x80);
    GetDNASErrorStrings(src, title, body, extra);
    std_basic_string_char_char_traits_char_ctor_charP(&s, body);
    if (extra[0]) {
        std_basic_string_char_char_traits_char_ctor_charP(&t, D_004AAC10);
        std_basic_string_char_char_traits_char_append_basicstringR(&s, &t);
        String_Dtor(&t, 0);
        std_basic_string_char_char_traits_char_ctor_charP(&u, extra);
        std_basic_string_char_char_traits_char_append_basicstringR(&s, &u);
        String_Dtor(&u, 0);
    }
    flags = 0;
    if (o->x88 != 4) flags = 0x20;
    cGameFrontEnd_PushMessageBox(D_004FFC04, 2, title, std_basic_string_char_char_traits_char_c_str(&s), o, flags);
    cGameFrontEnd_PopMessageBox(D_004FFC04, o->x11C);
    String_Dtor(&s, 0);
}
#undef D_004FFC04 /* merge_units */
#undef std_basic_string_char_char_traits_char_ctor_charP /* merge_units */
#undef std_basic_string_char_char_traits_char_c_str /* merge_units */
#undef String_Dtor /* merge_units */
#undef cGameFrontEnd_PushMessageBox /* merge_units */
#undef cGameFrontEnd_PopMessageBox /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0029D980 */

/* merge_units: begin func_0029DAF0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Stack_DAF0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void Show(void* w, int ms); virtual void Hide(void* w); };
typedef struct { char pad[0x14]; unsigned short flags; } W_DAF0;
typedef struct { char pad[0x88]; int x88; char pad8c[0x95 - 0x8C]; unsigned char b95; char pad96[0x108 - 0x96]; void* x108; char pad10c[0x11C - 0x10C]; int x11C; } O_DAF0;
typedef struct { int a; int b; int c; int d; } Str_DAF0;
extern "C" {
#if 0 /* merge_units */
extern int D_004FFC04;
#endif /* merge_units */
#define D_004FFC04 (*(int*)&D_004FFC04) /* merge_units */

extern unsigned char g_GuiSoundGate;
extern char D_004AAC18[];
extern char D_004AAC28[];
#if 0 /* merge_units */
void* cDME_GetLobby(void);
#endif /* merge_units */
#define cDME_GetLobby() ((void *)cDME_GetLobby()) /* merge_units */

void GuiOnlineConnect_ShowGroup(O_DAF0*, int);
#if 0 /* merge_units */
char* GuiLobbyScreen_GetLobbyString(O_DAF0*, int, int, int, int, int);
#endif /* merge_units */
#define GuiLobbyScreen_GetLobbyString(a0, a1, a2, a3, a4, a5) (GuiLobbyScreen_GetLobbyString((O_D390 *)(a0), (a1), (a2), (a3), (a4), (a5))) /* merge_units */

#if 0 /* merge_units */
int cGameFrontEnd_PushMessageBox(int, int, char*, char*, O_DAF0*, int);
#endif /* merge_units */
#define cGameFrontEnd_PushMessageBox(a0, a1, a2, a3, a4, a5) (cGameFrontEnd_PushMessageBox((Fe_D390 *)(a0), (a1), (a2), (a3), (O_D390 *)(a4), (a5))) /* merge_units */

#if 0 /* merge_units */
void cGameFrontEnd_PopMessageBox(int, int);
#endif /* merge_units */
#define cGameFrontEnd_PopMessageBox(a0, a1) (cGameFrontEnd_PopMessageBox((Fe_D390 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
Stack_DAF0* Gui_Canvas(void);
#endif /* merge_units */
#define Gui_Canvas() ((Stack_DAF0 *)Gui_Canvas()) /* merge_units */

W_DAF0* GuiWidget_FindChild_charP(void*, char*);
void FrontEnd_StopMusic(int);
void cGameFrontEnd_PlayMusic(int, int);
int SFOLobby_StartNetwork(void*, void*, int);
void* SFOLobby_GetDNASError(void*);
int SFOLobby_GetErrorDetails(void*, char*);
#if 0 /* merge_units */
void GuiOnlineConnect_DisplayDNASError(O_DAF0*, void*);
#endif /* merge_units */
#define GuiOnlineConnect_DisplayDNASError(a0, a1) (GuiOnlineConnect_DisplayDNASError((O_D980 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void GuiOnlineConnect_DnasRetry(O_DAF0*);
#endif /* merge_units */
#define GuiOnlineConnect_DnasRetry(a0) ((void)GuiOnlineConnect_DnasRetry((O_D390 *)(a0))) /* merge_units */

#if 0 /* merge_units */
void std_basic_string_char_char_traits_char_ctor_charP(Str_DAF0*, char*);
#endif /* merge_units */
#define std_basic_string_char_char_traits_char_ctor_charP(a0, a1) (std_basic_string_char_char_traits_char_ctor_charP((Str_D390 *)(a0), (a1))) /* merge_units */

void std_basic_string_char_char_traits_char_assign_basicstringR(Str_DAF0*, Str_DAF0*);
#if 0 /* merge_units */
void String_Dtor(Str_DAF0*, int);
#endif /* merge_units */
#define String_Dtor(a0, a1) (String_Dtor((Str_D390 *)(a0), (a1))) /* merge_units */

int cString_Length(Str_DAF0*);
#if 0 /* merge_units */
char* std_basic_string_char_char_traits_char_c_str(Str_DAF0*);
#endif /* merge_units */
#define std_basic_string_char_char_traits_char_c_str(a0) (std_basic_string_char_char_traits_char_c_str((Str_D390 *)(a0))) /* merge_units */

}

static inline void StrInit(Str_DAF0* s) { int i; int* p = &s->a; for (i = 0; i < 3; i++) *p++ = 0; }

extern "C" void GuiOnlineConnect_Connect(O_DAF0* o, void* arg) {
    Str_DAF0 msg;
    Str_DAF0 title;
    Str_DAF0 t1;
    Str_DAF0 t2;
    Str_DAF0 t3;
    char buf[0x100];
    void* net;
    unsigned char ok;
    void* w;
    int fe;
    net = cDME_GetLobby();
    if (!net) return;
    GuiOnlineConnect_ShowGroup(o, 4);
    fe = D_004FFC04;
    o->x11C = cGameFrontEnd_PushMessageBox(fe, 0, D_004AABF0, GuiLobbyScreen_GetLobbyString(o, 9, 0, 0, 0, 0), 0, 0);
    o->b95 = 0;
    w = o->x108;
    if (w) {
        W_DAF0* p;
        Gui_Canvas()->Show(w, 2000);
        p = GuiWidget_FindChild_charP(o->x108, D_004AAC18);
        if (p) p->flags |= 2;
        p = GuiWidget_FindChild_charP(o->x108, D_004AAC28);
        if (p) p->flags &= ~2;
    }
    g_GuiSoundGate = 1;
    FrontEnd_StopMusic(D_004FFC04);
    ok = SFOLobby_StartNetwork(net, arg, 1);
    g_GuiSoundGate = 0;
    cGameFrontEnd_PlayMusic(D_004FFC04, 0);
    w = o->x108;
    if (w) Gui_Canvas()->Hide(w);
    if (ok) {
        if (o->b95) {
            GuiOnlineConnect_DisplayDNASError(o, SFOLobby_GetDNASError(net));
            return;
        }
        GuiOnlineConnect_DnasRetry(o);
        return;
    }
    o->x88 = 4;
    StrInit(&msg);
    StrInit(&title);
    switch ((unsigned char)SFOLobby_GetErrorDetails(net, buf)) {
    case 6:
        GuiOnlineConnect_DisplayDNASError(o, SFOLobby_GetDNASError(net));
        break;
    case 0x3E:
        std_basic_string_char_char_traits_char_ctor_charP(&t1, GuiLobbyScreen_GetLobbyString(o, 0xC, 0, 0, 0, 0));
        std_basic_string_char_char_traits_char_assign_basicstringR(&msg, &t1);
        String_Dtor(&t1, 0);
        break;
    default:
        std_basic_string_char_char_traits_char_ctor_charP(&t2, GuiLobbyScreen_GetLobbyString(o, 0xB, 0, 0, 0, 0));
        std_basic_string_char_char_traits_char_assign_basicstringR(&title, &t2);
        String_Dtor(&t2, 0);
        std_basic_string_char_char_traits_char_ctor_charP(&t3, GuiLobbyScreen_GetLobbyString(o, 0x84, 0, 0, 0, 0));
        std_basic_string_char_char_traits_char_assign_basicstringR(&msg, &t3);
        String_Dtor(&t3, 0);
        break;
    }
    if (cString_Length(&msg)) {
        char* m = std_basic_string_char_char_traits_char_c_str(&msg);
        cGameFrontEnd_PushMessageBox(D_004FFC04, 2, std_basic_string_char_char_traits_char_c_str(&title), m, o, 0);
    }
    cGameFrontEnd_PopMessageBox(D_004FFC04, o->x11C);
    String_Dtor(&title, 0);
    String_Dtor(&msg, 0);
}
#undef D_004FFC04 /* merge_units */
#undef cDME_GetLobby /* merge_units */
#undef GuiLobbyScreen_GetLobbyString /* merge_units */
#undef cGameFrontEnd_PushMessageBox /* merge_units */
#undef cGameFrontEnd_PopMessageBox /* merge_units */
#undef Gui_Canvas /* merge_units */
#undef GuiOnlineConnect_DisplayDNASError /* merge_units */
#undef GuiOnlineConnect_DnasRetry /* merge_units */
#undef std_basic_string_char_char_traits_char_ctor_charP /* merge_units */
#undef String_Dtor /* merge_units */
#undef std_basic_string_char_char_traits_char_c_str /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0029DAF0 */
