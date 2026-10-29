#pragma enumsalwaysint off
enum RS_B3 { RS0, RS1, RS2, RS3, RS4, RS5, RS6, RSMAX = 0x7F };
#pragma inline_depth(16)
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

struct SubB3 { int n0; int n4; int n8; unsigned char bC; };
struct ReqB3 {
    int frame;
    RS_B3 state;
    char pad5[3];
    char* file;
    void (*cb)(SubB3*, int, int);
    int user;
};
struct LdrB3 { char pad[0xC]; ReqB3* cur; char pad10[4]; unsigned char b14; };
struct NodeB3 { NodeB3* prev; NodeB3* next; ReqB3* data; };
struct RawB3 { NodeB3* p; };
struct CmpB3 {};
struct PredB3 { CmpB3 cmp; ReqB3** pp; PredB3(const CmpB3& c, ReqB3** p) : cmp(c), pp(p) {} };

extern "C" {
extern char D_004BE010;
extern int D_00534CDC;
extern unsigned char D_00493990;
extern int g_FrameCounter;
void cMemMan_Deallocate(int a, void* p, char* file, int line);
void std_list_deleter_voidPtr_begin_void(RawB3*, LdrB3*);
void std_list_cFSDataPtr_generic_iterator_ctor(RawB3*, RawB3*);
void std_list_cFSDataPtr_end(RawB3*, LdrB3*);
void cLListIterator_cFSDataPtr_ctor(RawB3*, RawB3*);
void std_list_imp_voidPtr_remove_if(LdrB3*, PredB3);
void cFileStreamMan_FlushAllStreamData(LdrB3* ldr, int force);
int cFSData_StartStream(ReqB3* r);
int cFileMan_IsReadDone(char* f);
void std_list_cFSDataPtr_push_back(LdrB3* l, ReqB3** r);
}

static inline bool ReqCheckB3(ReqB3* r)
{
    unsigned char s = r->state;
    if (s == 3 || s == 6) return true;
    if (r->file) {
        int v = cFileMan_IsReadDone(r->file);
        if (v) {
            if (v == -1) r->state = RS4;
            else if (r->state != RS2) r->state = RS3;
            return true;
        }
    }
    return false;
}

static inline bool ReqReadyB3(ReqB3* r)
{
    bool b = D_00493990 == 1;
    if (b) b = ReqCheckB3(r);
    return b;
}

static inline bool LoaderIdleB3(ReqB3* r)
{
    bool b = r == 0;
    if (b) b = D_00493990 == 1;
    if (b) return true;
    return ReqReadyB3(r);
}

static inline SubB3* ReqSubB3(ReqB3* r) { return r->file ? (SubB3*)(r->file + 0x88) : 0; }
static inline int SubDataB3(SubB3* s) { return s->n8 ? s->n8 : s->n0; }

static inline void SubFreeB3(SubB3* s)
{
    void* p = (void*)s->n0;
    if (p) {
        {
            AllocGuard g;
            cMemMan_Deallocate(1, p, &D_004BE010, 0x56);
        }
        s->n0 = 0;
        s->n8 = 0;
        s->n4 = 0;
        s->bC = 0;
    }
}

static inline void BeginB3(RawB3* p, LdrB3* l) { RawB3 t; std_list_deleter_voidPtr_begin_void(&t, l); std_list_cFSDataPtr_generic_iterator_ctor(p, &t); }
static inline void EndB3(RawB3* p, LdrB3* l) { RawB3 t; std_list_cFSDataPtr_end(&t, l); cLListIterator_cFSDataPtr_ctor(p, &t); }
static inline void Begin2B3(RawB3* p, LdrB3* l) { BeginB3(p, l); }
static inline void End2B3(RawB3* p, LdrB3* l) { EndB3(p, l); }
static inline PredB3 MakePredB3(ReqB3** p) { CmpB3 c; return PredB3(c, p); }

extern "C" int cFileStreamMan_Process(LdrB3* ldr)
{
    RS_B3 st;
    RawB3 end;
    RawB3 end2;
    RawB3 it;
    RawB3 it2;
    ReqB3* r;
    NodeB3* n;
    if (!ldr->b14) ldr->b14 = 1;
    if (D_00534CDC == -1) return 0;
    cFileStreamMan_FlushAllStreamData(ldr, 0);
    if (!ldr->cur) {
        Begin2B3(&it, ldr);
        n = it.p;
        while (End2B3(&end, ldr), n != end.p) {
            r = n->data;
            if (!r->state && cFSData_StartStream(r)) {
                ldr->cur = r;
                D_00493990 = 1;
                break;
            }
            n = n->next;
        }
    } else if (LoaderIdleB3(ldr->cur)) {
        ReqB3* c = ldr->cur;
        st = c->state;
        if (st == RS2) {
            c->state = RS5;
            c->frame = g_FrameCounter;
        } else if (st == RS4) {
            c->state = RS0;
            SubFreeB3(ReqSubB3(c));
            std_list_imp_voidPtr_remove_if(ldr, MakePredB3(&ldr->cur));
            std_list_cFSDataPtr_push_back(ldr, &ldr->cur);
        } else if (st == RS1 || st == RS3) {
            SubB3* t = ReqSubB3(c);
            if (SubDataB3(t)) {
                t->bC = 1;
                c->state = RS3;
                c->cb(t, c->user, 1);
            }
        }
        ldr->cur = 0;
        D_00493990 = 0;
    }
    {
        int cnt = 0;
        Begin2B3(&it2, ldr);
        n = it2.p;
        while (End2B3(&end2, ldr), n != end2.p) {
            if (!n->data->state) cnt++;
            n = n->next;
        }
        return cnt;
    }
}

