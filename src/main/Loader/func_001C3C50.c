#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
/* load a file member into a fresh buffer and hand it to the owner's buffer list (creating the list on first use) */
struct Buf_3C50 { char* p; };
typedef struct { int a; char name[1]; } File_3C50;
struct List_3C50 { char pad[0xC]; unsigned char owned; };
typedef struct { char pad[0x10]; List_3C50* list; } Self_3C50;
extern "C" {
int cFileMan_Open(File_3C50* f);
int cFileMan_GetSize(File_3C50* f);
int cFileMan_Read_charPP_int(File_3C50* f, char** buf, int size);
void cFileMan_Close(File_3C50* f);
void* cMemMan_Allocate(int a, int size, char* file, int line);
void std_vector_charPtr_ctor_void(List_3C50* l);
void std_vector_charPtr_push_back_charPR(List_3C50* list, Buf_3C50* buf);
extern char D_0049EE88;
char* cLoader_AllocateAndFillAnimationBuffer(Self_3C50* self, File_3C50* f);
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
char* cLoader_AllocateAndFillAnimationBuffer(Self_3C50* self, File_3C50* f)
{
    Buf_3C50 buf;
    Buf_3C50 tmp;
    int size;
    int r;
    r = cFileMan_Open(f);
    if (!(r & 0xFF)) {
        size = cFileMan_GetSize(f);
        { char* p; { AllocGuard g; p = (char*)cMemMan_Allocate(0, size, &D_0049EE88, 0xDB); } buf.p = p; }
        if (buf.p) {
            tmp = buf;
            r = cFileMan_Read_charPP_int(f, &tmp.p, size);
            cFileMan_Close(f);
            if (!(r & 0xFF)) {
                { char* dst; char* src = tmp.p; dst = buf.p; if (src != dst) MemCopy_3C50(dst, src, size); }
                if (!self->list) {
                    List_3C50* l;
                    { AllocGuard g; l = (List_3C50*)cMemMan_Allocate(0, 0x10, &D_0049EE88, 0xF1); }
                    if (l) { std_vector_charPtr_ctor_void(l); l->owned = 1; }
                    self->list = l;
                }
                std_vector_charPtr_push_back_charPR(self->list, &buf);
            }
        }
    }
    if (r & 0xFF) buf.p = 0;
    return buf.p;
}
