#include "types.h"
typedef struct { char pad[0x41C]; int refs; } R_5630;
typedef struct { char pad[0xE0]; char xE0[0x40]; char name[0x18]; unsigned char count; char mode; char pad4[2]; R_5630* res; } E_5630;
typedef struct { char pad[0x14]; E_5630* e; } S_5630;
extern char D_0049B238[];
extern char D_0049B240[];
extern char D_0049B248[];
extern int strlen(const char* s);
extern int func_00129C80(char* a, char* b);
extern void func_00128E80(char* a, char* b);
extern void func_00146460(S_5630* self, R_5630* r);
void func_00145630(S_5630* self, int idx, int release)
{
    E_5630* e = &self->e[idx];
    e->count--;
    if (e->count == 0) {
        if (strlen(e->name) && !func_00129C80(e->name, D_0049B238))
            func_00129C80(e->name, D_0049B240);
        func_00128E80(e->xE0, D_0049B248);
        if (e->res) {
            e->res->refs--;
            if (release && e->res->refs <= 0)
                func_00146460(self, e->res);
        }
    }
}