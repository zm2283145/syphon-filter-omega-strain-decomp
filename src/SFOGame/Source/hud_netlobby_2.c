/*
 * SFOGame/Source/hud_netlobby: 2 files, 0027ADA0-0027AEA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0027ADA0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { float r, g, b, a; } Col27AD;
typedef struct { char pad0[4]; void* p4; char pad8[4]; void* pC; char pad10[0x1C]; int count; char pad30[8]; int sel; int mode; } Menu27AD;
extern unsigned char D_00504040;
extern void cHudNetLobby_SetActive(Menu27AD* s);
extern void cInterfaceElement_SetFilterColor(void* o, Col27AD* c);

void cHudNetLobby_UpdateGameAvailable(Menu27AD* s)
{
    if (s->mode == 0 && s->count && D_00504040 && s->sel == 0) {
        s->sel = 1;
        cHudNetLobby_SetActive(s);
    }
    if (s->count == 0) {
        Col27AD a, b;
        a.r = 1.0f; a.g = 1.0f; a.b = 1.0f; a.a = 1.0f;
        cInterfaceElement_SetFilterColor(s->p4, &a);
        b.r = 0.5f; b.g = 0.5f; b.b = 0.5f; b.a = 1.0f;
        cInterfaceElement_SetFilterColor(s->pC, &b);
    } else {
        Col27AD c, d;
        if (D_00504040) {
            c.r = 0.5f; c.g = 0.5f; c.b = 0.5f; c.a = 1.0f;
            cInterfaceElement_SetFilterColor(s->p4, &c);
        }
        d.r = 1.0f; d.g = 1.0f; d.b = 1.0f; d.a = 1.0f;
        cInterfaceElement_SetFilterColor(s->pC, &d);
    }
}
static inline void merge_flush_func_0027ADA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0027ADA0 */

/* merge_units: begin func_0027AEA0 */
#pragma push /* merge_units */
/* 0027AEA0 cHudNetLobby_UpdateGameInfo (cHudNetLobby::UpdateGameInfo); iterator temporaries are named
 * locals declared in the original frame-slot order; lq/sq copies follow the project cVector/cMatrix convention */
#pragma cplusplus on
#include "alloc_guard.h"

struct cVector {
    float x, y, z, w;
    cVector() {}
    cVector(const cVector& o) { __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(&o), "r"(this) : "memory"); }
    cVector(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    cVector& operator=(const cVector& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct cMatrix {
    __int128 r0, r1, r2, r3;
    cMatrix() {}
    cMatrix(const cMatrix& o) {
        cMatrix* d = this; const cMatrix* s = &o; __int128 qa, qb;
        __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory");
    }
};
struct cTextArea;
struct cXform { char pad[0x20]; cMatrix m; };
struct cInterfaceElement { char pad[0x19]; unsigned char b19; char pad2[0x56]; cXform* xf; cTextArea* text; };
struct cInterfaceModel;
struct cInterface { cInterfaceModel* model; };

struct tServer {
    char ServerIpString[16];
    int ServerPort;
    tServer() { ServerPort = 3658; }
};

struct GameInfo {
    tServer mServerInfo;
    cInterfaceElement* mElement;
    unsigned char mValid;
    GameInfo() { mElement = 0; mValid = 0; }
};

struct LNode { LNode* prev; LNode* next; GameInfo* data; };
struct It {
    LNode* n;
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~It() {}
    GameInfo*& operator*() const { return n->data; }
};
struct BA { LNode* n[1]; };
struct GList { int size; LNode* head; int x8; };

struct cHudNetLobby {
    cInterface* mInterface;
    char pad4[0x28];
    GList mGameInfo;
    int mCurrentButton;
    int mCurrentScreen;
    tServer mJoinServer;
    unsigned char mSelectionMade;
    unsigned char mCreateServer;
    unsigned char mPassiveMode;
};

extern "C" {
void std_list_deleter_voidPtr_begin_void(It*, GList*);
void std_list_GameInfoPtr_generic_iterator_ctor(It*, It*);
void std_list_GameInfoPtr_end(It*, GList*);
void cLListIterator_GameInfoPtr_ctor(It*, It*);
void std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(It*, It*);
void std_list_GameInfoPtr_generic_iterator_opCast(It*, It*);
void std_list_deleter_voidPtr_erase_listdeleter(It*, GList*, It*);
void std_list_GameInfoPtr_push_back(GList*, GameInfo* const&);
#if 0 /* merge_units */
void cHudNetLobby_SetActive(cHudNetLobby*);
#endif /* merge_units */
#define cHudNetLobby_SetActive(a0) (cHudNetLobby_SetActive((Menu27AD *)(a0))) /* merge_units */

#if 0 /* merge_units */
void cHudNetLobby_UpdateGameAvailable(cHudNetLobby*);
#endif /* merge_units */
#define cHudNetLobby_UpdateGameAvailable(a0) (cHudNetLobby_UpdateGameAvailable((Menu27AD *)(a0))) /* merge_units */

void cDME_CreateServerList(void);
int cDME_GetServerFromList(tServer*);
int String_CompareNoCase(const char*, const char*);
int sprintf(char*, const char*, ...);
void* cMemMan_Allocate(int, int, const char*, int);
void cMemMan_Deallocate(int, void*, const char*, int);
void cInterfaceElement_Destroy(cInterfaceElement*);
cInterfaceElement* nHud_CreateHudElement(cInterfaceModel*, const char*);
void cInterfaceElement_SetText(cInterfaceElement*, const char*);
void cTextArea_SetColor(cTextArea*, const int*);
void cInterfaceElement_Activate(cInterfaceElement*, bool);
void cInterfaceElement_SetLocation(cInterfaceElement*, const cVector&);
extern int D_004A9260[];
extern char D_004A9270[];
extern char D_004A9280[];
extern char D_004A9288[];
extern int D_0048B358;
}

inline void ALock() { if (g_ProfileLockEnabled) Alloc_Lock(9); g_ProfileLockDepth++; }
inline void AUnlock() { if (g_ProfileLockEnabled) EnableIntc(9); g_ProfileLockDepth--; }
inline void* operator new(__typeof__(sizeof(0)) sz, const char* f, int l) { ALock(); void* p = cMemMan_Allocate(0, sz, f, l); AUnlock(); return p; }
#pragma opt_common_subs off
#pragma opt_loop_invariants off
#pragma opt_rotateloops off
#pragma opt_dead_code off
#pragma opt_propagation off
extern "C" void cHudNetLobby_UpdateGameInfo(cHudNetLobby* self)
{
    if (self->mPassiveMode)
        return;
    It itr1;
    It itr2;
    GameInfo* info;
    It itr3;
    It itr4;
    It res1, endL1, res2, endL2, res3, eLIt, endL4;
    It gIt1, ret1, gIt2, ret2, pad18C, gIt3, ret3, gIt4, pad17C, eGIt;
    It eDIt, tmp1, tmp2, tmp3;
    It dIt1, endG1, dIt2, endG2, dIt3, dIt4, eRes, eCast, endG4;

    std_list_deleter_voidPtr_begin_void(&dIt1, &self->mGameInfo);
    std_list_GameInfoPtr_generic_iterator_ctor(&gIt1, &dIt1);
    for (itr1.n = gIt1.n;
         std_list_GameInfoPtr_end(&endG1, &self->mGameInfo), cLListIterator_GameInfoPtr_ctor(&endL1, &endG1), itr1.n != endL1.n;
         tmp1.n = itr1.n, itr1.n = itr1.n->next, ret1.n = tmp1.n, res1.n = ret1.n)
        itr1.n->data->mValid = 0;
    tServer server;
    int lastSize = self->mGameInfo.size;
    cDME_CreateServerList();
    while (cDME_GetServerFromList(&server)) {
        unsigned char newServer = 1;
        std_list_deleter_voidPtr_begin_void(&dIt2, &self->mGameInfo);
        std_list_GameInfoPtr_generic_iterator_ctor(&gIt2, &dIt2);
        for (itr2.n = gIt2.n;
             std_list_GameInfoPtr_end(&endG2, &self->mGameInfo), cLListIterator_GameInfoPtr_ctor(&endL2, &endG2), itr2.n != endL2.n;
             tmp2.n = itr2.n, itr2.n = itr2.n->next, ret2.n = tmp2.n, res2.n = ret2.n) {
            if (String_CompareNoCase(itr2.n->data->mServerInfo.ServerIpString, server.ServerIpString) == 0) {
                newServer = 0;
                itr2.n->data->mValid = 1;
                break;
            }
        }
        if (newServer) {
            info = new (D_004A9270, 0x12E) GameInfo;
            info->mServerInfo = server;
            info->mValid = 1;
            char buttonText[128];
            sprintf(buttonText, D_004A9280, D_0048B358, server.ServerIpString);
            cInterfaceElement* e = nHud_CreateHudElement(self->mInterface->model, D_004A9288);
            if (e)
                cInterfaceElement_SetText(e, buttonText);
            info->mElement = e;
            info->mElement->b19 = 0;
            cTextArea_SetColor(info->mElement->text, D_004A9260);
            cInterfaceElement_Activate(info->mElement, self->mCurrentScreen == 1);
            std_list_GameInfoPtr_push_back(&self->mGameInfo, info);
        }
    }
    unsigned char resetActive = 1;
    int one = 1;
    if (self->mCurrentScreen == one) {
        if (self->mGameInfo.size > self->mCurrentButton) {
            int newCurrentButton = 0;
            GList* gl = &self->mGameInfo;
            std_list_deleter_voidPtr_begin_void(&dIt3, gl);
            std_list_GameInfoPtr_generic_iterator_ctor(&gIt3, &dIt3);
            itr3.n = gIt3.n;
            for (int i = 0; i < self->mCurrentButton; i++, tmp3.n = itr3.n, itr3.n = itr3.n->next, ret3.n = tmp3.n, res3.n = ret3.n) {
                if (itr3.n->data->mValid)
                    newCurrentButton++;
            }
            if (itr3.n->data->mValid) {
                self->mCurrentButton = newCurrentButton;
                resetActive = 0;
            } else {
                self->mCurrentButton = 0;
            }
        } else {
            self->mCurrentButton = 0;
        }
        if (lastSize == 0 && self->mGameInfo.size != 0)
            resetActive = 1;
    } else {
        resetActive = 0;
    }
    std_list_deleter_voidPtr_begin_void(&dIt4, &self->mGameInfo);
    std_list_GameInfoPtr_generic_iterator_ctor(&gIt4, &dIt4);
    int curY = 210;
    for (itr4.n = gIt4.n;
         std_list_GameInfoPtr_end(&endG4, &self->mGameInfo), cLListIterator_GameInfoPtr_ctor(&endL4, &endG4), itr4.n != endL4.n;) {
        GameInfo* info = itr4.n->data;
        if (!info->mValid) {
            {
                ALock();
                if (info) {
                    cInterfaceElement* e = info->mElement;
                    if (e)
                        cInterfaceElement_Destroy(e);
                }
                cMemMan_Deallocate(0, info, D_004A9270, 0x168);
                AUnlock();
            }
            std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(&eDIt, &itr4);
            { It* src = &eDIt; std_list_GameInfoPtr_generic_iterator_opCast(&eCast, src); }
            std_list_deleter_voidPtr_erase_listdeleter(&eRes, &self->mGameInfo, &eCast);
            std_list_GameInfoPtr_generic_iterator_ctor(&eGIt, &eRes);
            eLIt.n = eGIt.n;
            *(BA*)&itr4 = *(BA*)&eLIt;
        } else {
            cMatrix parentView = info->mElement->xf->m;
            cVector parentOffset = *(cVector*)&parentView.r3;
            cVector location(160.0f - parentOffset.x, 0.0f, -parentOffset.z + (float)curY, 1.0f);
            cInterfaceElement_SetLocation((*itr4)->mElement, location);
            curY -= 32;
            itr4.n = itr4.n->next;
        }
    }
    if (resetActive)
        cHudNetLobby_SetActive(self);
    cHudNetLobby_UpdateGameAvailable(self);
}
#undef cHudNetLobby_SetActive /* merge_units */
#undef cHudNetLobby_UpdateGameAvailable /* merge_units */
static inline void merge_flush_func_0027AEA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0027AEA0 */
