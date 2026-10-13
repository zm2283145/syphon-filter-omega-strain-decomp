#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct S2CA160 { char pad[0x2EC]; unsigned char b2EC; char pad2ED[3]; void* p2F0; void* p2F4; void* p2F8; };
extern "C" {
extern char D_004ACF10[];
void* DME_GetLobby(void);
void func_00445DC0(void* p);
void func_0044F970(void* p, int f);
void Mem_Free(int pool, void* p, char* file, int line);
}
static inline void Del2CA160(void* p, int line)
{
    AllocGuard g;
    func_0044F970(p, -1);
    Mem_Free(0, p, D_004ACF10, line);
}
extern "C" int func_002CA160(S2CA160* s)
{
    if (!s->b2EC)
        return 0;
    if (DME_GetLobby())
        func_00445DC0(DME_GetLobby());
    Del2CA160(s->p2F0, 0x5F5);
    Del2CA160(s->p2F4, 0x5F6);
    Del2CA160(s->p2F8, 0x5F7);
    s->p2F0 = 0;
    s->p2F4 = 0;
    s->p2F8 = 0;
    s->b2EC = 0;
    return 1;
}