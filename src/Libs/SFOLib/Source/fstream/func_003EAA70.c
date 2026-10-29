#pragma inline_depth(16)
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

/* The request state is a one-byte enum; testing it through an enum-typed local
   gives retail's registers (byte in a0, request pointer kept in v1). */
#pragma enumsalwaysint off
enum eReqState { RS_0, RS_1, RS_2, RS_3, RS_4, RS_5, RS_MAX = 0x7F };
struct ReqAA { int frame; eReqState state; char pad5[3]; char* file; void* cb; int user; };
struct LdrAA { char pad[0xC]; ReqAA* cur; };
struct CmpAA {};
struct PredAA { CmpAA cmp; ReqAA** pp; PredAA(const CmpAA& c, ReqAA** p) : cmp(c), pp(p) {} };

extern "C" {
extern char D_004BE010;
extern int g_FrameCounter;
void cMemMan_Deallocate(int a, void* p, char* file, int line);
void std_list_imp_voidPtr_remove_if(LdrAA*, PredAA);
int cFSData_FreeStream(ReqAA* r, int release);
ReqAA* cFileStreamMan_FindStreamData(LdrAA* l, char* name, int kind);
bool cFileStreamMan_StreamRequestFlush_cFileManR_voidPcFSHandlePvoidPbool_voidP_eStreamMode(LdrAA* ldr, char* name, void* cb, int user, unsigned char mode);
}

static inline PredAA MakePredAA(ReqAA** p) { CmpAA c; return PredAA(c, p); }
static inline void MarkAA(ReqAA* r)
{
    r->state = RS_5;
    r->frame = g_FrameCounter;
}
static inline void SetupAA(ReqAA* r, char* name, void* cb, int user)
{
    r->file = name;
    if (cb) r->cb = cb;
    if (user) r->user = user;
}

extern "C" bool cFileStreamMan_StreamRequestFlush_cFileManR_voidPcFSHandlePvoidPbool_voidP_eStreamMode(LdrAA* ldr, char* name, void* cb, int user, unsigned char mode)
{
    bool now = mode == 1;
    ReqAA* r2 = 0;
    ReqAA* req;
    bool ret = true;

    req = cFileStreamMan_FindStreamData(ldr, name, 3);
    if (!req) {
        req = cFileStreamMan_FindStreamData(ldr, name, 0);
        if (req)
            now = true;
    }
    if (!req)
        req = cFileStreamMan_FindStreamData(ldr, name, 5);
    if (!req) {
        req = cFileStreamMan_FindStreamData(ldr, name, 1);
        if (req)
            req->state = RS_2;
    }
    if (req) {
        eReqState s = req->state;
        if (s != RS_2) {
            if (cb)
                SetupAA(req, name, cb, user);
            MarkAA(req);
            if (now) {
                cFSData_FreeStream(req, 1);
                std_list_imp_voidPtr_remove_if(ldr, MakePredAA(&req));
                {
                    ReqAA* p = req;
                    AllocGuard g;
                    cMemMan_Deallocate(0, p, &D_004BE010, 0x2AF);
                }
            }
        }
        r2 = req;
        while (r2) {
            r2 = cFileStreamMan_FindStreamData(ldr, name, 3);
            if (r2) {
                std_list_imp_voidPtr_remove_if(ldr, MakePredAA(&r2));
                {
                    ReqAA* p = r2;
                    AllocGuard g;
                    cMemMan_Deallocate(0, p, &D_004BE010, 0x2C2);
                }
            }
        }
        r2 = req;
        while (r2) {
            r2 = cFileStreamMan_FindStreamData(ldr, name, 0);
            if (r2) {
                std_list_imp_voidPtr_remove_if(ldr, MakePredAA(&r2));
                {
                    ReqAA* p = r2;
                    AllocGuard g;
                    cMemMan_Deallocate(0, p, &D_004BE010, 0x2D5);
                }
            }
        }
        r2 = cFileStreamMan_FindStreamData(ldr, name, 1);
        if (r2)
            r2->state = RS_2;
    } else {
        ret = false;
    }
    return ret;
}
