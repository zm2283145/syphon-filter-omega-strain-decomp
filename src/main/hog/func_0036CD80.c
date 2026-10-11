#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct S36CD80 { char pad[0x80]; char m80[0xC8]; void* p148; unsigned char b14C; char pad14D[0xB]; void* p158; int x15C; int x160; int pool; };
extern "C" {
extern char D_004BBF88[];
void func_003695C0(void* p);
void Mem_Free(int pool, void* p, char* file, int line);
}
static inline void Rel36CD80(void* p, int pool, int line)
{
    AllocGuard g;
    Mem_Free(pool, p, D_004BBF88, line);
}
extern "C" int func_0036CD80(S36CD80* s)
{
    if (!s->b14C)
        return 0;
    func_003695C0(s->m80);
    if (s->p158) {
        Rel36CD80(s->p158, s->pool, 0x122);
        s->p158 = 0;
    }
    if (s->b14C == 2) {
        Rel36CD80(s->p148, s->pool, 0x128);
    }
    s->p148 = 0;
    s->x15C = 0;
    s->x160 = 0;
    s->pool = 0;
    s->b14C = 0;
    return 0;
}