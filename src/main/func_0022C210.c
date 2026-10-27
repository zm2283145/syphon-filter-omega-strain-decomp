#pragma cplusplus on

struct Ctl {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12();
    virtual int Active(); /* 0x54 */
};
struct Tgt {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E();
    virtual unsigned char Kind(); /* 0xC4 */
    int pad4[2];
    int id;
    char p10[0x2C - 0x10];
    bool x2C; bool x2D; bool x2E; char p2F;
    char p30[0x58 - 0x30];
    Ctl* x58;
    bool Alive() { return x2D && x2C && !x2E; }
};
struct Hnd { Tgt* p; int id; };
static inline Tgt* HGet2(Hnd* h) {
    bool ok = !h->p || h->p->id == h->id;
    return ok ? h->p : 0;
}
static inline bool IdEq(Tgt* p, Hnd* h) { return p->id == h->id; }
static inline Tgt* HGet(Hnd* h) {
    bool ok = !h->p || IdEq(h->p, h);
    return ok ? h->p : 0;
}
struct WNode { WNode* prev; WNode* next; Hnd h; };
struct Player { char p[0xC8]; Hnd lock; };
struct World { char p[0x90]; char markers[1]; };
struct WL { int x0; int list; };

extern "C" {
extern World* g_Hud;
extern char D_004F78DC[];
WNode* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_2(void* l);
int cHudTargetManager_Add(void* mgr, int* key, int f);
void cPlayerControls_Untarget(Player* p, Tgt* t);
int cHudTargetManager_Remove(void* mgr, int* key, int f);
}

extern "C" void SeedPlayerLos(Tgt* self, Player* pl)
{
    void* mgr;
    WL* wl = (WL*)D_004F78DC;
    WNode* it = details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_2(&wl->list)->next;
    WNode* end = details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_2(&wl->list);
    mgr = g_Hud->markers;
    for (; it != end; it = it->next) {
        Hnd* h = &it->h;
        Tgt* t = HGet(h);
        if (!t || t == self) continue;
        bool active = false;
        if (t->x58 && t->x58->Active()) active = true;
        if (active) {
            cHudTargetManager_Add(mgr, &t->id, 0);
        } else if (HGet2(&pl->lock) == t || t->Kind() == 2) {
            if (t->Alive()) {
                cHudTargetManager_Add(mgr, &t->id, 0);
            } else {
                cPlayerControls_Untarget(pl, t);
                cHudTargetManager_Remove(mgr, &t->id, 0);
            }
        } else if ((unsigned char)t->Kind() == 0) {
            cPlayerControls_Untarget(pl, t);
            cHudTargetManager_Remove(mgr, &t->id, 0);
        }
    }
}



