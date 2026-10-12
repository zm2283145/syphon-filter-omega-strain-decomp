#include "types.h"
#pragma cplusplus on
#include "alloc_guard.h"

typedef struct {
    char pad00[0x40];
    unsigned char mode;  /* 0x40 */
    char pad41[3];
    int lang;            /* 0x44 */
    char pad48[0x20];
    int f68;             /* 0x68 */
} Subs410C20;

extern "C" {
extern char D_004BEE90[];
int func_0036DEF0(void* file);
int FileMan_GetSize(void* file);
void func_0036D990(void* file, char** out, int z);
void func_0036DEC0(void* file);
void* Mem_Alloc(int pool, unsigned int size, char* file, int line);
void Mem_Free(int pool, void* allocation, char* file, int line);
void func_0040FBC0(Subs410C20* self, const char* s, const char* end);
}

static inline void MemClear_410C20(void* d0, int n0) { int n = n0; void* dst = d0;
    asm {
        .set noreorder
        blez n, done
        nop
        andi $v1, dst, 0xF
        andi $v0, n, 0xF
        or $v1, $v1, $v0
        nop
        bgtz $v1, bytes
        srl $v0, n, 4
        nop
        blez $v0, bytes
        nop
        nop
    quads:
        addi $v0, $v0, -1
        sq $zero, 0(dst)
        bgtz $v0, quads
        addiu dst, dst, 0x10
        b done
        nop
    bytes:
        addi n, n, -1
        sb $zero, 0(dst)
        bgtz n, bytes
        addiu dst, dst, 1
    done:
        .set reorder
    }
}

static inline char* Alloc_410C20(int size)
{
    AllocGuard g;
    return (char*)Mem_Alloc(0, size, D_004BEE90, 0x2A9);
}

static inline void Free_410C20(void* p)
{
    AllocGuard g;
    Mem_Free(0, p, D_004BEE90, 0x2C6);
}

#pragma opt_propagation off
extern "C" void func_00410C20(Subs410C20* self, void* file, int lang)
{
    int size;
    char* volatile buf;
    char* s;
    char* e;
    self->lang = lang;
    self->mode = 0;
    if ((unsigned char)func_0036DEF0(file)) return;
    size = FileMan_GetSize(file);
    buf = Alloc_410C20(size);
    MemClear_410C20(buf, size);
    func_0036D990(file, (char**)&buf, 0);
    func_0036DEC0(file);
    {
    unsigned char* u = (unsigned char*)buf;
    if (u == 0) return;
    if (size > 3 && u[0] == 0xEF && u[1] == 0xBB && u[2] == 0xBF) {
        s = (char*)u + 3;
        e = (char*)u + size - 3;
    } else {
        s = buf;
        e = s + size;
    }
    }
    func_0040FBC0(self, s, e);
    Free_410C20(buf);
    self->f68 = 0;
}







