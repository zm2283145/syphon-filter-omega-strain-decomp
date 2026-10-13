#include "types.h"
typedef struct { int w[16]; } Blk_0044C760;
typedef struct {
    char pad0[0x38];
    Blk_0044C760 blk;
    char pad78[0xF0 - 0x78];
    int fF0;
    void* fF4;
    int fF8;
    int fFC;
} Cfg_0044C760;
typedef struct {
    char pad0[0x180]; int f180; int f184; char pad188[0x24C - 0x188]; int f24C;
    char pad250[0x1F3C - 0x250]; Blk_0044C760 blk; char pad1F7C[0x2100 - 0x1F7C]; char name[0x2180 - 0x2100]; int f207C; char pad2184[0x2410 - 0x2184]; int f2410;
} S_0044C760;
extern int D_00497728;
extern int D_00497740;
extern int D_00497890;
extern char D_004C0E80[];
void func_00447220(void);
void func_00452F70(void* a, int b, int c);
int memset(void* d, int c, int n);
void func_0046BA68(Cfg_0044C760* cfg, int a, char* name, int b, int c);
int func_004689F8(Cfg_0044C760* cfg, int* out);
int func_00443E70(void);
int func_004534A0(S_0044C760* self, int a, int b, int c);
void func_00451B00(S_0044C760* self, int code, char* file, int line);
int func_0044C760(S_0044C760* self)
{
    Cfg_0044C760 cfg;
    int out[2];
    int tries;
    func_00452F70(self, 2, 3);
    tries = 0;
    memset(&cfg, 0, 0x100);
    memset(out, 0, 8);
    func_0046BA68(&cfg, 0, self->name, self->f207C, 1);
    cfg.fF0 = D_00497728;
    cfg.fF4 = func_00447220;
    cfg.fF8 = 0;
    cfg.fFC = 0;
    cfg.blk = self->blk; self->f180 = -1;
    while (tries < D_00497740 && self->f180 == -1) {
        func_00452F70(self, 0, 0);
        tries++;
        self->f24C = func_004689F8(&cfg, out);
        if (self->f24C == 0) {
            self->f184 = 0;
            self->f2410 = func_00443E70();
            while (self->f184 == 0) {
                func_00452F70(self, 0, 0);
                if (!func_004534A0(self, self->f2410, D_00497890, 1)) {
                    func_00451B00(self, 2, D_004C0E80, 0x34D);
                    break;
                }
            }
        }
    }
    if (self->f180 == -1) {
        func_00451B00(self, 0xC, D_004C0E80, 0x358);
        return 0;
    }
    return 1;
}


