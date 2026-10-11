#include "types.h"
typedef struct { char pad[5]; unsigned char v; } Cfg_1470;
typedef struct { char pad[0x67]; unsigned char on; char pad68[0x1DC - 0x68]; Cfg_1470* cfg; } S_1470;
typedef struct { char pad[0xC]; unsigned char flag; } G_1470;
extern unsigned char D_005721C8;
extern G_1470* D_004FFC38;
void func_0026BD60(void);
void func_0026BE70(unsigned char v);
void func_00131470(S_1470* self, unsigned char on)
{
    if (!D_005721C8)
        self->on = on;
    if (self->on) {
        func_0026BD60();
        func_0026BE70(0);
        D_004FFC38->flag = 1;
    } else {
        func_0026BE70(self->cfg->v);
        D_004FFC38->flag = 0;
    }
}