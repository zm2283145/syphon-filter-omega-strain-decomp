/*
 * Libs/SFOLib/Source/MemCard: 3 files, 0040D600-0040D740
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0040D600 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x1C]; char item[0x1C]; } ED600;
typedef struct { ED600 e[(0x560) / 0x38]; char pad[0x560 - (0x560 / 0x38) * 0x38]; int count; } PD600;
typedef struct { PD600* p; } OD600;
typedef struct { int m0; int size; } VD600;
extern void std_vector_charPtr_push_back_charPR_2(VD600* v, void** item);
/* Collects pointers to every entry's item into the vector. */
void cMemCard_GetFilenames(OD600* o, VD600* v) {
    int i;
    v->size = 0;
    for (i = 0; i < o->p->count; i++) {
        void* it = o->p->e[i].item;
        std_vector_charPtr_push_back_charPR_2(v, &it);
    }
}
static inline void merge_flush_func_0040D600(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0040D600 */

/* merge_units: begin func_0040D690 */
#pragma push /* merge_units */
typedef struct { char pad[0x1C]; char item[0x1C]; } ED690;
typedef struct { ED690 e[(0x560) / 0x38]; char pad[0x560 - (0x560 / 0x38) * 0x38]; int count; } PD690;
typedef struct { PD690* p; } OD690;
extern int WildcardCompare(void* key, void* item);
static inline int d690find(PD690* p, void* key) {
    int i;
    for (i = 0; i < p->count; i++) {
        if (!((WildcardCompare(key, p->e[i].item) != 0) ^ 1))
            return i;
    }
    return -1;
}
/* True when some entry's item matches key. */
int cMemCard_FileExists(OD690* o, void* key) {
    return d690find(o->p, key) >= 0;
}
static inline void merge_flush_func_0040D690(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0040D690 */

/* merge_units: begin func_0040D740 */
#pragma push /* merge_units */
typedef struct {
    char pad0[0x540];
    int mode;               /* 0x540 */
    char pad544[0x59C - 0x544];
    unsigned char failed;   /* 0x59C */
    unsigned char pad59D[3];
    unsigned char done;     /* 0x5A0 */
} MCP;
typedef struct { MCP* p; unsigned char busy; char pad[3]; void (*cb)(void); unsigned char state; } MC;
typedef struct { char pad[0xAC]; } Res;

extern unsigned char g_ProfileLockEnabled;
extern int g_ProfileLockDepth;
extern int g_TimerAccum;
extern unsigned long g_TickCounter64;
extern char D_004BED20[], D_004BED38[], D_004BED48[], D_004BED58[];
extern char* D_00494008;
extern char* D_00494010;
extern int D_00493C40[];
extern int MemCard_MemCardMain(MCP* p);
extern void cFileMan_ctor_void(Res* r);
extern void Libc_Strcpy(char* d, const char* s);
extern void Libc_Strcat(char* d, const char* s);
extern void cFileMan_EncodeFilename_charP_cFileIOP_bool(Res* r, char* name, int a, int b);
extern int cFileMan_Open(Res* r);
extern int cFileMan_GetSize(Res* r);
extern void Alloc_Lock(int id);
extern void EnableIntc(int id);
extern void* cMemMan_Allocate(int heap, int size, const char* file, int line);
extern void cMemMan_Deallocate(int heap, void* p, const char* file, int line);
extern void cFileMan_Read_charPP_int(Res* r, void** out, int z);
extern void cFileMan_Close(Res* r);
extern int cMemCard_SaveFile(MC* c, const char* name, void* data, int size, int flag);
extern int sprintf(char* buf, const char* fmt, ...);
extern void cFileMan_dtor(Res* r, int flags);

/* the original clears the buffer with this hand-written asm loop (quadwords when both the
 * address and the size are 16-byte aligned, else bytes) */
static inline void ClearMem(void* dd, int nn)
{
    void* d; int n; int mis; int qn;
    d = dd;
    n = nn;
    asm {
        .set noreorder
        blez n, done
        nop
        andi mis, d, 0xf
        andi qn, n, 0xf
        or mis, mis, qn
        nop
        bgtz mis, bytes
        srl qn, n, 4
        nop
        blez qn, bytes
        nop
        nop
    quads:
        addi qn, qn, -1
        sq zero, 0(d)
        bgtz qn, quads
        addiu d, d, 16
        b done
        nop
    bytes:
        addi n, n, -1
        sb zero, 0(d)
        bgtz n, bytes
        addiu d, d, 1
    done:
        .set reorder
    }
}

#pragma push
/* propagation off: retail's asm clear reads the copied size/buffer registers (and buf from memory) */
#pragma opt_propagation off
/* Creates the save directory: waits for the card command, then writes the directory
 * file (loaded from GAMEDATA\\COMMON), icon.sys and a timestamp id. */
int cMemCard_MakeGameDir(MC* c)
{
    Res r;
    char path[0x80];
    char icon[0x20];
    char sys[0x20];
    char id[0x40];
    void* m;
    void* buf;
    int size;
    int ok;
    MCP* p = c->p;
    p->mode = 2;
    p->done = 0;
    c->state = 6;
    do {
        c->busy = MemCard_MemCardMain(c->p) != 0;
        if (((c->busy != 0) ^ 1) != 0)
            c->state = 0;
        if (c->cb)
            c->cb();
    } while (!((c->busy != 0) ^ 1) || !c->p->done);
    if (!c->p->failed) {
        cFileMan_ctor_void(&r);
        Libc_Strcpy(path, D_004BED20);
        Libc_Strcat(path, D_00494008);
        cFileMan_EncodeFilename_charP_cFileIOP_bool(&r, path, 0, 0);
        if (!(unsigned char)cFileMan_Open(&r)) {
            size = cFileMan_GetSize(&r);
            if (g_ProfileLockEnabled) Alloc_Lock(9);
            g_ProfileLockDepth++;
            m = cMemMan_Allocate(0, size, D_004BED38, 990);
            if (g_ProfileLockEnabled) EnableIntc(9);
            g_ProfileLockDepth--;
            buf = m;
            ClearMem(buf, size);
            cFileMan_Read_charPP_int(&r, &buf, 0);
            cFileMan_Close(&r);
            ok = cMemCard_SaveFile(c, D_00494008, buf, size, 1) != 0;
            {
                void* q = buf;
                if (g_ProfileLockEnabled) Alloc_Lock(9);
                g_ProfileLockDepth++;
                cMemMan_Deallocate(0, q, D_004BED38, 996);
                if (g_ProfileLockEnabled) EnableIntc(9);
                g_ProfileLockDepth--;
            }
            if (ok && (unsigned char)(cMemCard_SaveFile(c, D_00494010, icon, 32, 1) != 0)
                   && (unsigned char)(cMemCard_SaveFile(c, D_004BED48, D_00493C40, 964, 1) != 0)) {
                sprintf(id, D_004BED58, (g_TickCounter64 + (unsigned int)(int)((float)(unsigned int)(*(volatile int*)0x10000800 + g_TimerAccum) / 5.76f)) & 0xFFFFFFFF);
                id[32] = 0;
                ok = cMemCard_SaveFile(c, id, sys, 32, 1);
                cFileMan_dtor(&r, -1);
                return ok;
            }
        }
        cFileMan_dtor(&r, -1);
    }
    return 0;
}
#pragma pop
static inline void merge_flush_func_0040D740(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0040D740 */
