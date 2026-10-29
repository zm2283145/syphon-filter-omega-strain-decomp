#pragma cplusplus on
#include "types.h"
#include "targetManager_types.h"

struct LIt_D3C0 { void* p; LIt_D3C0() {} LIt_D3C0(void* q) : p(q) {} };
struct LList_D3C0 { int alloc; void* prev; void* next; };

extern "C" {
LIt_D3C0 std_list_deleter_LosReqElem_erase(LList_D3C0* l, const LIt_D3C0& first, const LIt_D3C0& last);
LIt_D3C0 std_list_deleter_cSafePtr_cGOBJ_erase_listdeleter_listdeleter(LList_D3C0* l, const LIt_D3C0& first, const LIt_D3C0& last);
}

struct TM_D3C0 {
    char p0[0x20];
    struct LosElem* rows[30];
    void* sparseGobjs[30];
    LList_D3C0 pending;
    LList_D3C0 gobjs;
};

/* memset(p, 0, n) expansion (16-byte sq loop or byte loop) as an inline asm macro */
static inline void MemClear_D3C0(void* d0, int n0) { int n = n0; void* dst = d0;
    __asm__ volatile(
        ".set noreorder\n"
        "blez %1, mc_done\n"
        "nop\n"
        "andi $a0, %0, 0xF\n"
        "andi $v1, %1, 0xF\n"
        "or $a0, $a0, $v1\n"
        "nop\n"
        "bgtz $a0, mc_bytes\n"
        "srl $v1, %1, 4\n"
        "nop\n"
        "blez $v1, mc_bytes\n"
        "nop\n"
        "nop\n"
        "mc_quads:\n"
        "addi $v1, $v1, -1\n"
        "sq $zero, 0(%0)\n"
        "bgtz $v1, mc_quads\n"
        "addiu %0, %0, 0x10\n"
        "b mc_done\n"
        "nop\n"
        "mc_bytes:\n"
        "addi %1, %1, -1\n"
        "sb $zero, 0(%0)\n"
        "bgtz %1, mc_bytes\n"
        "addiu %0, %0, 1\n"
        "mc_done:\n"
        ".set reorder\n"
        : "+r"(dst), "+r"(n) : : "a0", "v1", "memory");
}
static inline LIt_D3C0 Begin_D3C0(LList_D3C0* l) { return LIt_D3C0(l->next); }
static inline LIt_D3C0 End_D3C0(LList_D3C0* l) { return LIt_D3C0(&l->prev); }

struct LosElem { int expirationFrame; int lastLosFrame; void* blockingGobj; unsigned char hasLos; unsigned char pending;
  void Init() { lastLosFrame = 0; expirationFrame = 0; hasLos = 0; pending = 0; }
};

extern "C" void cTargetManager_Reset(TM_D3C0* self) {
    int i;
    int j;
    MemClear_D3C0(self->sparseGobjs, 0x78);
    std_list_deleter_LosReqElem_erase(&self->pending, Begin_D3C0(&self->pending), End_D3C0(&self->pending));
    std_list_deleter_cSafePtr_cGOBJ_erase_listdeleter_listdeleter(&self->gobjs, Begin_D3C0(&self->gobjs), End_D3C0(&self->gobjs));
    for (i = 0; i < 29; i++) {
        for (j = 0; j < 29 - i; j++) {
            self->rows[i][j].Init();
        }
    }
}
