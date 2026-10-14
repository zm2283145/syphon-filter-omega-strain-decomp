#pragma cplusplus on
#include "types.h"

extern "C" {

extern char D_004D9060[];
extern char D_0049A890[];
extern char D_0049AB60[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void ListReceiver_Ctor(void* p);
void func_001383B0(void* p);
void func_001391E0(void* p);
void Map_Ctor(void* p, void* a, void* b);
void ScalarCollection_Init(void* p);
void String_Copy(void* s, char* src);
void* func_00260B90(void* p);
void* WaterFx_Construct(void* p);
void* NpcRouteMgr_Construct(void* p);
void* SoundMgr_Construct(void* p);
void* func_0016B340(void* p);
void* ObjMan_Ctor(void* p);
void* HotboxTracker_Construct(void* p, int a);
void* func_0045A7A0(void* p);
void* func_002CC5A0(void* p);
void* func_00147910(void* p);
void func_003CAC40(void* w, void* p);
void func_001396D0(void* p, int n);
}

struct Sub2C_WC { char pad[0xC]; unsigned char bC; };
struct Blk10_WC { int f0; int f4; int f8; unsigned char bC; };
struct Blk14_WC { char pad[0x10]; int f10; };
struct Blk70_WC { char pad[0xC]; int fC; unsigned char b10; };
struct World_WC {
    void* vtbl;
    char pad4[0x10 - 0x4];
    int f10;
    char pad14[0x2C - 0x14];
    Sub2C_WC m2C;
    char pad39[0x3C - 0x39];
    char m3C[0x48 - 0x3C];
    int f48;
    int f4C;
    unsigned char b50;
    unsigned char b51;
    char pad52[2];
    int f54;
    int f58;
    int f5C;
    unsigned char b60;
    unsigned char b61;
    unsigned char b62;
    unsigned char b63;
    unsigned char b64;
    unsigned char b65;
    unsigned char b66;
    unsigned char b67;
    unsigned char b68;
    char pad69[3];
    int f6C;
    char m70[0x80 - 0x70];
    void* f80;
    Blk70_WC* f84;
    Blk14_WC* f88;
    void* f8C;
    void* f90;
    char pad94[4];
    void* f98;
    char m9C[0xAC - 0x9C];
    int fAC;
    int fB0;
    void* fB4;
    int fB8;
    char padBC[0xC4 - 0xBC];
    char mC4[0xD8 - 0xC4];
    unsigned char bD8;
    unsigned char bD9;
    char padDA[2];
    int fDC;
    void* fE0;
    void* fE4;
    Blk10_WC* fE8;
    int fEC;
    char padF0[0x140 - 0xF0];
    char s140[0x1C0 - 0x140];
    int f1C0;
    char pad1C4[4];
    int f1C8;
    int f1CC;
    int f1D0;
    int f1D4;
    int f1D8;
    void* f1DC;
    void* f1E0;
    char pad1E4[4];
    long f1E8;
};

#include "alloc_guard.h"
/* allocation under the scoped allocator lock (each guard keeps a 16-byte frame slot) */
static inline void* WcAlloc(int sz, int line) { AllocGuard g; return Mem_Alloc(0, sz, D_0049A890, line); }
#define WC_ALLOC(p, T, sz, line) p = (T)WcAlloc(sz, line);

/* map member ctor with comparator/allocator temporaries; two inline levels put them below the guards */
static inline void MapInitB(void* m) { int cmp; int alc; Map_Ctor(m, &cmp, &alc); }
static inline void MapInitA(void* m) { MapInitB(m); }

extern "C" World_WC* World_Construct(World_WC* w)
{
    ListReceiver_Ctor(w);
    w->vtbl = D_004D9060;
    {
        Sub2C_WC* m = &w->m2C;
        func_001383B0(m);
        m->bC = 1;
    }
    func_001391E0(w->m3C);
    w->b50 = 0;
    w->b51 = 0;
    w->f54 = 0;
    w->f58 = 0;
    w->f5C = 0;
    w->b60 = 0;
    w->b61 = 0;
    w->b62 = 0;
    w->b63 = 0;
    w->b64 = 0;
    w->b65 = 1;
    MapInitA(w->m70);
    ScalarCollection_Init(w->m9C);
    w->fAC = 0;
    w->fB0 = 0;
    w->fB8 = 0;
    ScalarCollection_Init(w->mC4);
    w->bD9 = 0;
    w->fDC = 0;
    w->fE0 = 0;
    w->fE4 = 0;
    w->fE8 = 0;
    w->fEC = 0;
    w->f1E8 = 0;
    String_Copy(w->s140, D_0049AB60);
    {
        void* p;
        WC_ALLOC(p, void*, 0x200, 0x93);
        if (p) p = func_00260B90(p);
        w->fE0 = p;
    }
    {
        void* p;
        WC_ALLOC(p, void*, 0x460, 0x94);
        if (p) p = WaterFx_Construct(p);
        w->fE4 = p;
    }
    {
        Blk10_WC* p;
        WC_ALLOC(p, Blk10_WC*, 0x10, 0x95);
        if (p) {
            p->f0 = 0;
            p->f4 = 0;
            p->f8 = 0;
            p->bC = 0;
        }
        w->fE8 = p;
    }
    {
        void* p;
        WC_ALLOC(p, void*, 0x7C, 0x97);
        if (p) p = NpcRouteMgr_Construct(p);
        func_003CAC40(w, p);
    }
    {
        void* p;
        WC_ALLOC(p, void*, 0x54C0, 0x98);
        if (p) p = SoundMgr_Construct(p);
        func_003CAC40(w, p);
    }
    {
        void* p;
        WC_ALLOC(p, void*, 0x20, 0x99);
        if (p) p = func_0016B340(p);
        func_003CAC40(w, p);
    }
    {
        void* p;
        WC_ALLOC(p, void*, 0x11B4, 0x9A);
        if (p) p = ObjMan_Ctor(p);
        func_003CAC40(w, p);
    }
    {
        void* p;
        WC_ALLOC(p, void*, 0x34, 0x9C);
        if (p) p = HotboxTracker_Construct(p, 0);
        w->f80 = p;
    }
    {
        Blk14_WC* p;
        WC_ALLOC(p, Blk14_WC*, 0x14, 0x9D);
        if (p) p->f10 = 0;
        w->f88 = p;
    }
    {
        Blk70_WC* p;
        WC_ALLOC(p, Blk70_WC*, 0x70, 0x9E);
        if (p) {
            ScalarCollection_Init(p);
            p->b10 = 0;
            p->fC = 0;
        }
        w->f84 = p;
    }
    w->f8C = 0;
    {
        void* p;
        WC_ALLOC(p, void*, 0x24, 0xA0);
        if (p) p = func_0045A7A0(p);
        w->f1DC = p;
    }
    {
        void* p;
        WC_ALLOC(p, void*, 0x318, 0xA3);
        if (p) p = func_002CC5A0(p);
        w->fB4 = p;
    }
    func_003CAC40(w, w->fB4);
    func_001396D0(&w->m2C, 0x100);
    w->f98 = 0;
    w->f90 = 0;
    w->f10 = 0;
    w->f48 = 0;
    w->f4C = 0;
    {
        void* p;
        WC_ALLOC(p, void*, 0xD8, 0xB2);
        if (p) p = func_00147910(p);
        w->f1E0 = p;
    }
    w->f1C8 = 0;
    w->f1CC = 0;
    w->f1D0 = 0;
    w->f1D4 = 0;
    w->f1C0 = 0;
    w->f1D8 = 0;
    w->b66 = 0;
    w->b67 = 0;
    w->b68 = 0;
    w->f6C = -1;
    return w;
}



