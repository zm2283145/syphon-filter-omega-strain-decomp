#include "types.h"

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
extern int func_0040E5D0(MCP* p);
extern void Resource_Construct(Res* r);
extern void String_Copy(char* d, const char* s);
extern void Libc_Strcat(char* d, const char* s);
extern void func_0036E140(Res* r, char* name, int a, int b);
extern int FileMan_FindMember(Res* r);
extern int FileMan_GetSize(Res* r);
extern void Alloc_Lock(int id);
extern void Alloc_Unlock(int id);
extern void* Mem_Alloc(int heap, int size, const char* file, int line);
extern void Mem_Free(int heap, void* p, const char* file, int line);
extern void FileMan_LoadMemberSync(Res* r, void** out, int z);
extern void func_0036DEC0(Res* r);
extern int MemCardWrap_Write(MC* c, const char* name, void* data, int size, int flag);
extern int sprintf(char* buf, const char* fmt, ...);
extern void FileMan_Release(Res* r, int flags);

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
int MemCardWrap_MakeDirectory(MC* c)
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
        c->busy = func_0040E5D0(c->p) != 0;
        if (((c->busy != 0) ^ 1) != 0)
            c->state = 0;
        if (c->cb)
            c->cb();
    } while (!((c->busy != 0) ^ 1) || !c->p->done);
    if (!c->p->failed) {
        Resource_Construct(&r);
        String_Copy(path, D_004BED20);
        Libc_Strcat(path, D_00494008);
        func_0036E140(&r, path, 0, 0);
        if (!(unsigned char)FileMan_FindMember(&r)) {
            size = FileMan_GetSize(&r);
            if (g_ProfileLockEnabled) Alloc_Lock(9);
            g_ProfileLockDepth++;
            m = Mem_Alloc(0, size, D_004BED38, 990);
            if (g_ProfileLockEnabled) Alloc_Unlock(9);
            g_ProfileLockDepth--;
            buf = m;
            ClearMem(buf, size);
            FileMan_LoadMemberSync(&r, &buf, 0);
            func_0036DEC0(&r);
            ok = MemCardWrap_Write(c, D_00494008, buf, size, 1) != 0;
            {
                void* q = buf;
                if (g_ProfileLockEnabled) Alloc_Lock(9);
                g_ProfileLockDepth++;
                Mem_Free(0, q, D_004BED38, 996);
                if (g_ProfileLockEnabled) Alloc_Unlock(9);
                g_ProfileLockDepth--;
            }
            if (ok && (unsigned char)(MemCardWrap_Write(c, D_00494010, icon, 32, 1) != 0)
                   && (unsigned char)(MemCardWrap_Write(c, D_004BED48, D_00493C40, 964, 1) != 0)) {
                sprintf(id, D_004BED58, (g_TickCounter64 + (unsigned int)(int)((float)(unsigned int)(*(volatile int*)0x10000800 + g_TimerAccum) / 5.76f)) & 0xFFFFFFFF);
                id[32] = 0;
                ok = MemCardWrap_Write(c, id, sys, 32, 1);
                FileMan_Release(&r, -1);
                return ok;
            }
        }
        FileMan_Release(&r, -1);
    }
    return 0;
}
#pragma pop
