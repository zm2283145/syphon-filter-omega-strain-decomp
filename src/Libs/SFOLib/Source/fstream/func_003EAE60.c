#pragma inline_depth(16)
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

struct Sub_EAE60 {
    int n0;
    int n4;
    int n8;
    unsigned char bC;
};
struct Req_EAE60 {
    int frame;
    unsigned char state;
    char pad5[3];
    char* file;
    void (*cb)(Sub_EAE60*, int, int);
    int user;
    unsigned char owned;
};
struct Loader_EAE60 {
    char pad[0xC];
    Req_EAE60* cur;
};

extern "C" {
extern unsigned char D_00493990;
extern char D_004BE010;
void* cMemMan_Allocate(int a, int size, char* file, int line);
int cFileMan_IsReadDone(char* f);
void cFileStreamMan_FlushAllStreamData(Loader_EAE60* l, int a);
Req_EAE60* cFileStreamMan_FindStreamData(Loader_EAE60* l, char* name, int kind);
void std_list_cFSDataPtr_push_back(Loader_EAE60* l, Req_EAE60** r);
char* cFileMan_ctor_void(void* p);
void cFileMan_EncodeFilename_charP_cFileManR(char* f, char* a, char* b);
void cFileMan_Open(char* f);
int cFileMan_GetSize(char* f);
int cFSHandle_AllocateMem(Sub_EAE60* s, int size);
void cFileMan_Read_charPP_int(char* f, int* buf, int size);
}

static inline bool ReqCheck_EAE60(Req_EAE60* r)
{
    unsigned char s = r->state;
    if (s == 3 || s == 6) return true;
    if (r->file) {
        int v = cFileMan_IsReadDone(r->file);
        if (v) {
            if (v == -1) r->state = 4;
            else if (r->state != 2) r->state = 3;
            return true;
        }
    }
    return false;
}

static inline bool ReqReady_EAE60(Req_EAE60* r)
{
    bool b = D_00493990 == 1;
    if (b) b = ReqCheck_EAE60(r);
    return b;
}

static inline bool LoaderIdle_EAE60(Req_EAE60* r)
{
    bool b = r == 0;
    if (b) b = D_00493990 == 1;
    if (b) return true;
    return ReqReady_EAE60(r);
}

static inline Sub_EAE60* ReqSub_EAE60(Req_EAE60* r)
{
    return r->file ? (Sub_EAE60*)(r->file + 0x88) : 0;
}

static inline int SubData_EAE60(Sub_EAE60* s)
{
    return s->n8 ? s->n8 : s->n0;
}

extern "C" int cFileStreamMan_StreamRequest(Loader_EAE60* ldr, char* name, void (*cb)(Sub_EAE60*, int, int), int user,
                                     unsigned char mode, int stream, int noReuse)
{
    bool force = false;
    Req_EAE60* req = 0;

    if (mode == 1) {
        if (ldr->cur) {
            while (!LoaderIdle_EAE60(ldr->cur)) {
            }
            ldr->cur = 0;
            D_00493990 = 0;
        }
        cFileStreamMan_FlushAllStreamData(ldr, 1);
    }
    if (!noReuse) {
        req = cFileStreamMan_FindStreamData(ldr, name, 0);
        if (req) return 0;
    }
    req = cFileStreamMan_FindStreamData(ldr, name, 5);
    if (!req) {
        req = cFileStreamMan_FindStreamData(ldr, name, 3);
    } else if (ReqSub_EAE60(req)->bC) {
        force = true;
    }
    if (!req) {
        Req_EAE60* n;
        if (g_ProfileLockEnabled) Alloc_Lock(9);
        g_ProfileLockDepth++;
        n = (Req_EAE60*)cMemMan_Allocate(0, 0x18, &D_004BE010, 0x24D);
        if (g_ProfileLockEnabled) EnableIntc(9);
        g_ProfileLockDepth--;
        if (n) {
            n->cb = 0;
            n->user = 0;
            n->frame = 0;
            n->file = 0;
            n->state = 6;
            n->owned = 0;
            n->state = 0;
        }
        req = n;
        std_list_cFSDataPtr_push_back(ldr, &req);
    }
    {
        Req_EAE60* r = req;
        if (stream) {
            char* f;
            { AllocGuard g; f = (char*)cMemMan_Allocate(0, 0x9C, &D_004BE010, 0x89); }
            if (f) f = cFileMan_ctor_void(f);
            r->file = f;
            cFileMan_EncodeFilename_charP_cFileManR(r->file, name + 4, name);
            r->owned = 1;
        } else {
            r->file = name;
        }
        if (cb) r->cb = cb;
        if (user) r->user = user;
    }
    req->state = 0;
    if (mode == 1 || force) {
        Req_EAE60* q = req;
        Sub_EAE60* s = ReqSub_EAE60(q);
        int buf;
        int size;
        cFileMan_Open(q->file);
        buf = 0;
        size = cFileMan_GetSize(q->file);
        if (cFSHandle_AllocateMem(s, size)) {
            q->state = 1;
            if (!s->bC) {
                buf = SubData_EAE60(s);
                cFileMan_Read_charPP_int(q->file, &buf, size);
            }
            if (q->state == 1 || q->state == 3) {
                Sub_EAE60* t = ReqSub_EAE60(q);
                if (SubData_EAE60(t)) {
                    t->bC = 1;
                    q->state = 3;
                    q->cb(t, q->user, 1);
                }
            }
        }
    }
    return 1;
}





