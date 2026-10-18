#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
/* load a file member into a fresh buffer and hand it to the owner's buffer list (creating the list on first use) */
struct Buf_3C50 { char* p; };
typedef struct { int a; char name[1]; } File_3C50;
struct List_3C50 { char pad[0xC]; unsigned char owned; };
typedef struct { char pad[0x10]; List_3C50* list; } Self_3C50;
extern "C" {
int FileMan_FindMember(File_3C50* f);
int FileMan_GetSize(File_3C50* f);
int FileMan_LoadMemberSync(File_3C50* f, char** buf, int size);
void func_0036DEC0(File_3C50* f);
void* Mem_Alloc(int a, int size, char* file, int line);
void func_00146020(List_3C50* l);
void func_00146000(List_3C50* list, Buf_3C50* buf);
extern char D_0049EE88;
char* func_001C3C50(Self_3C50* self, File_3C50* f);
}
static inline void MemCopy_3C50(void* dst, void* src, int n0)
{
    int n = n0;
    int t;
    int m;
    asm {
        .set noreorder
        blez n, done
        andi m, src, 0xF
        andi t, dst, 0xF
        or m, m, t
        andi t, n, 0xF
        or m, m, t
        nop
        bgtz m, bytes
        nop
    quads:
        lq t, 0(src)
        addiu dst, dst, 0x10
        addi n, n, -0x10
        addiu src, src, 0x10
        bgtz n, quads
        sq t, -0x10(dst)
        b done
        nop
    bytes:
        lb t, 0(src)
        addiu dst, dst, 1
        addi n, n, -1
        addiu src, src, 1
        bgtz n, bytes
        sb t, -1(dst)
    done:
        .set reorder
    }
}
char* func_001C3C50(Self_3C50* self, File_3C50* f)
{
    Buf_3C50 buf;
    Buf_3C50 tmp;
    int size;
    int r;
    r = FileMan_FindMember(f);
    if (!(r & 0xFF)) {
        size = FileMan_GetSize(f);
        { char* p; { AllocGuard g; p = (char*)Mem_Alloc(0, size, &D_0049EE88, 0xDB); } buf.p = p; }
        if (buf.p) {
            tmp = buf;
            r = FileMan_LoadMemberSync(f, &tmp.p, size);
            func_0036DEC0(f);
            if (!(r & 0xFF)) {
                { char* dst; char* src = tmp.p; dst = buf.p; if (src != dst) MemCopy_3C50(dst, src, size); }
                if (!self->list) {
                    List_3C50* l;
                    { AllocGuard g; l = (List_3C50*)Mem_Alloc(0, 0x10, &D_0049EE88, 0xF1); }
                    if (l) { func_00146020(l); l->owned = 1; }
                    self->list = l;
                }
                func_00146000(self->list, &buf);
            }
        }
    }
    if (r & 0xFF) buf.p = 0;
    return buf.p;
}
