#pragma cplusplus on
#include "types.h"

/* Monster_FreePart: drop one reference to cached part i; on the last release of a part above the
 * static range, release its two loaded streams ("<name><suffix>1", "<name><suffix>0"), clear their
 * slots and the part's key. */

struct Res { char c[0xA0]; };
struct Slot { int a; int b; int stream; int d; };
struct Cache {
    char pad0[0xC8];
    unsigned int nStatic;
    char padCC[0x210 - 0xCC];
    short refs[0x1500];
    __int128 names[0x300];
    Slot slots[0x100][2];
};

extern "C" {
extern char D_004BE830[];
extern __int128 D_005716E0;
void cFileMan_ctor_void(Res* r);
void Libc_Strcpy(char* d, const char* s);
void Libc_Strcat(char* d, const char* s);
void cFileMan_EncodeFilename_charP_cFileIOP_bool(Res* r, char* name, int a, int b);
void* GetFileStreamMan(void);
void cFileStreamMan_StreamRequestFlush_cFileManR_eStreamMode(void* l, Res* r, int f);
void cFileMan_dtor(Res* r, int flags);
void Monster_FreePart(Cache* c, unsigned int i);
}

/* quad/byte clear loop with addi counters and hand-placed nops (retail shape); no C equivalent */
static inline void MemClear(void* d0, int n0)
{
    int n = n0;
    void* dst = d0;
    asm volatile {
        .set noreorder
        blez n, done
        nop
        andi $a0, dst, 0xF
        andi $v1, n, 0xF
        or $a0, $a0, $v1
        nop
        bgtz $a0, bytes
        srl $v1, n, 4
        nop
        blez $v1, bytes
        nop
        nop
    quads:
        addi $v1, $v1, -1
        sq $zero, 0(dst)
        bgtz $v1, quads
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


void Monster_FreePart(Cache* c, unsigned int i)
{
    c->refs[i]--;
    if (i < c->nStatic) return;
    if (c->refs[i]) return;
    {
        Res r;
        char name[0x20];
        int k;
        cFileMan_ctor_void(&r);
        Libc_Strcpy(name, (char*)&c->names[i]);
        Libc_Strcat(name, D_004BE830);
        for (k = 1; k > 0; k--) {
            if (c->slots[i][k].stream != c->slots[i][k - 1].stream && c->slots[i][k].stream) {
                name[0xE] = '0' + k;
                cFileMan_EncodeFilename_charP_cFileIOP_bool(&r, name, 0, 0);
                cFileStreamMan_StreamRequestFlush_cFileManR_eStreamMode(GetFileStreamMan(), &r, 1);
            }
            MemClear(&c->slots[i][k], 16);
        }
        if (c->slots[i][0].stream) {
            name[0xE] = '0';
            cFileMan_EncodeFilename_charP_cFileIOP_bool(&r, name, 0, 0);
            cFileStreamMan_StreamRequestFlush_cFileManR_eStreamMode(GetFileStreamMan(), &r, 1);
        }
        MemClear(&c->slots[i][0], 16);
        c->names[i] = D_005716E0;
        cFileMan_dtor(&r, -1);
    }
}
