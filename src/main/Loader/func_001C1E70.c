#pragma cplusplus on
#include "types.h"
#include "pop_reader.h"
#include "fileman_entry.h"
#include "alloc_guard.h"

struct NpcObj {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void SetActive(int on);
    char pad04[0x8];
    unsigned int flagsC;
    char pad10[0xC];
    void* reg;
    char pad20[0x38];
    int actorId;
    char pad5C[0x4];
    char sub60[0x40];
    char appearance[0x10];
};
struct NpcColor { char data[0x440]; };
struct BodyTbl { char pad[0xF8]; int tbl[1][4]; };
struct NetState { char pad[0x250]; unsigned char b250; };

extern "C" {
extern char D_0049EE88[];
extern char D_0049F050[], D_0049F070[], D_0049F090[], D_0049F0A8[], D_0049F0B8[];
extern char D_0048B2F8[];
extern char D_0057124C[], D_005711B0[];
extern char D_004FFB50[];
extern NetState* D_004FFC04;
extern unsigned char D_004FFBB2;
extern signed char D_00493A60;
extern NpcColor D_0055D510[];
extern int D_0055DE94;
extern BodyTbl D_0055DDA0;
extern void* D_004FFD44;
void* Mem_Alloc(int pool, int size, char* file, int line);
void func_00165E60(void* a, char* name, int x);
void* func_001698C0(void);
int sprintf(char* buf, const char* fmt, ...);
int Archive_Open(void* a, char* name, int b, int c);
void Hog_Register(void* hog, char* name, int h, int b);
void TexCache_AddThermalTextures(void* hog);
void Expression_Init(void);
NpcObj* Npc_Construct(void* p, PopReader* r, int kind, NpcColor* color, int x);
void World_RegisterActor(void* w, int id);
void Player_SetLocal(NpcObj* o);
int Appearance_GetBodyKind(void* a);
void func_00391020(void* a, int b);
void ObjRegistry_AppendRecursive(void* reg, NpcObj* o);
void func_00403FC0(void* a);
}

static inline void SkipStr(PopReader* r)
{
    while (*r->cur++)
        ;
}

static inline void Align(PopReader* r)
{
    int mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
    if (mis)
        r->cur += 4 - mis;
}

/* new cNPC(r, 1, &colors[D_00493A60]): the color index is read after the allocation */
static inline NpcObj* NewPlayer(PopReader* r)
{
    NpcObj* p;
    {
        AllocGuard g;
        p = (NpcObj*)Mem_Alloc(0, 0x35A0, D_0049EE88, 0x32A);
    }
    if (p)
        p = Npc_Construct(p, r, 1, &D_0055D510[D_00493A60], 0);
    return p;
}

extern "C" void Pop_LoadNPC(void* unused, PopReader* r, void* arc)
{
    char thermal[128];
    char name[128];
    FileManEntry e;
    func_0036E5D0(&e);
    func_00165E60(func_001698C0(), D_0049F050, 0);
    sprintf(thermal, D_0049F070, D_0048B2F8);
    sprintf(name, D_0049F090, D_0048B2F8);
    Hog_Register(D_0057124C, D_0049F0A8, Archive_Open(arc, name, 1, 0), 1);
    Hog_Register(D_005711B0, D_0049F0B8, Archive_Open(arc, thermal, 1, 0), 1);
    TexCache_AddThermalTextures(D_005711B0);
    Expression_Init();
    if (!(unsigned char)Pop_FindTag(r, 0x3A43504E)) {
        func_0036E220(&e, -1);
        return;
    }
    {
        int n;
        NpcObj* p;
        int i;
        n = *(int*)r->cur;
        r->cur += 4;
        for (i = 0; i < n; i++) {
            if (i == 0) {
                unsigned char local = D_004FFC04->b250;
                if (D_004FFBB2 == 0)
                    local = 1;
                if (!local) {
                    if (D_00493A60 == -1)
                        D_00493A60 = 0;
                    p = NewPlayer(r);
                } else {
                    {
                        AllocGuard g;
                        p = (NpcObj*)Mem_Alloc(0, 0x35A0, D_0049EE88, 0x32E);
                    }
                    if (p)
                        p = Npc_Construct(p, r, 1, 0, 0);
                }
                World_RegisterActor(D_004FFB50, p->actorId);
                p->SetActive(1);
                Player_SetLocal(p);
                if (D_0055DE94) {
                    int kind = Appearance_GetBodyKind(p->appearance);
                    int idx = ((p->flagsC & 0x7F000000) >> 24) - 1;
                    if (idx < 0)
                        idx = 0;
                    int v = D_0055DDA0.tbl[kind][idx];
                    if (v)
                        func_00391020(p->sub60, v);
                }
            } else {
                {
                    AllocGuard g;
                    p = (NpcObj*)Mem_Alloc(0, 0x35A0, D_0049EE88, 0x347);
                }
                if (p)
                    p = Npc_Construct(p, r, 2, 0, 0);
            }
            void* reg = D_004FFD44;
            p->reg = reg;
            ObjRegistry_AppendRecursive(reg, p);
        }
    }
    if (!(unsigned char)Pop_FindTag(r, 0x3A4E4547)) {
        func_0036E220(&e, -1);
        return;
    }
    {
        int n = *(int*)r->cur;
        r->cur += 4;
        for (int i = 0; i < n; i++) {
            r->cur += 8;
            SkipStr(r);
            Align(r);
            r->cur += 0x34;
            r->cur += 4;
            r->cur += 4;
            int cnt = *(int*)r->cur;
            r->cur += 4;
            r->cur += cnt / 2 * 8 + 0xC;
            if (r->unk0 >= 0x3E) {
                r->cur += 1;
                Align(r);
            }
            r->cur += 1;
            Align(r);
            if (r->unk0 >= 0x32)
                r->cur += 4;
            SkipStr(r);
            Align(r);
        }
    }
    func_00403FC0(&D_0055DDA0);
    func_0036E220(&e, -1);
}

