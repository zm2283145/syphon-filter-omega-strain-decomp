#pragma inline_depth(16)
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

struct SubA6 { int n0; int n4; int n8; unsigned char bC; };
struct ReqA6 { int frame; unsigned char state; char pad5[3]; char* file; };
struct LdrA6 { char pad[0xC]; ReqA6* cur; };
struct NodeA6 { NodeA6* prev; NodeA6* next; ReqA6* data; };
struct RawA6 { NodeA6* p; };
struct CmpA6 {};
struct PredA6 { CmpA6 cmp; ReqA6** pp; PredA6(const CmpA6& c, ReqA6** p) : cmp(c), pp(p) {} };

extern "C" {
extern char D_004BE010;
extern int g_FrameCounter;
void Mem_Free(int a, void* p, char* file, int line);
void List_Begin(RawA6*, LdrA6*);
void func_003EA900(RawA6*, RawA6*);
void func_003EA8F0(RawA6*, LdrA6*);
void func_003EA8E0(RawA6*, RawA6*);
void ActiveList_EraseMatching(LdrA6*, PredA6);
int Fstream_StartRequest(ReqA6* r, int release);
}

static inline SubA6* ReqSubA6(ReqA6* r) { return r->file ? (SubA6*)(r->file + 0x88) : 0; }
static inline SubA6* ReqSub2A6(ReqA6* r) { SubA6* s = 0; if (r->file) s = (SubA6*)(r->file + 0x88); return s; }
static inline int SubN4A6(ReqA6* r) { return ReqSubA6(r) ? ReqSub2A6(r)->n4 : 0; }

static inline void BeginA6(RawA6* p, LdrA6* l) { RawA6 t; List_Begin(&t, l); func_003EA900(p, &t); }
static inline void EndA6(RawA6* p, LdrA6* l) { RawA6 t; func_003EA8F0(&t, l); func_003EA8E0(p, &t); }
static inline PredA6 MakePredA6(ReqA6** p) { CmpA6 c; return PredA6(c, p); }
static inline void Begin2A6(RawA6* p, LdrA6* l) { BeginA6(p, l); }
static inline void End2A6(RawA6* p, LdrA6* l) { EndA6(p, l); }
extern "C" void Fstream_PurgeRequests(LdrA6* ldr, int force)
{
    ReqA6* r;
    RawA6 end;
    RawA6 it;
    NodeA6* n;
    Begin2A6(&it, ldr);
    n = it.p;
    while (End2A6(&end, ldr), n != end.p) {
        bool done;
        r = n->data;
        done = false;
        if ((ReqSubA6(r) ? ReqSubA6(r)->n4 : 0) && r->state == 5 && (force || (!force && g_FrameCounter - r->frame > 2))) {
            if (!ldr->cur || (ldr->cur && ReqSubA6(ldr->cur) != ReqSubA6(r)))
                Fstream_StartRequest(r, 1);
            done = true;
        }
        n = n->next;
        if (done) {
            ActiveList_EraseMatching(ldr, MakePredA6(&r));
            {
                ReqA6* p = r;
                AllocGuard g;
                Mem_Free(0, p, &D_004BE010, 0x374);
            }
        }
    }
}








