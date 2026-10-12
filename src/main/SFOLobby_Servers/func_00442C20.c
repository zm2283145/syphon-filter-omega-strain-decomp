#include "types.h"

typedef struct {
    int type;
    int id;
    char data[0x38];
} NetCfg442C20;

extern char D_00583A00[];
extern char D_004C05D0[];
void* memset(void*, int, unsigned int);
char* strncpy(char*, const char*, unsigned int);
int sceLibnetInitialize(void*, int, int, int);
int func_0034B868(void*, void*);
int func_0034AA50(void*, void*, int, void*, int, int, int);
int func_0034AB38(void*, void*, char*, int, void*);
void func_00451B00(char*, int, char*, int);
void func_0034B7E8(void*);

int func_00442C20(char* self, int arg1, char* out) {
    NetCfg442C20 cfg;
    char buf[0x5C0];

    memset(&cfg, 0, sizeof(cfg));
    cfg.type = 1;
    cfg.id = -1;
    if (sceLibnetInitialize(self + 0x2664, 0x800, 0x2000, 0x20) != 0) {
        return 0;
    }
    if (func_0034B868(self + 0x2664, D_00583A00) < 0) {
        return 0;
    }
    if (func_0034AA50(self + 0x2664, D_00583A00, 0, cfg.data, arg1, 0, 0) < 0) {
        func_00451B00(self, 0x2D, D_004C05D0, 0xB3);
        func_0034B7E8(self + 0x2664);
        return 0;
    }
    if (func_0034AB38(self + 0x2664, D_00583A00, buf, 0x80, cfg.data) < 0) {
        func_00451B00(self, 0x2D, D_004C05D0, 0xC0);
        func_0034B7E8(self + 0x2664);
        return 0;
    }
    strncpy(out, buf, 0x1F);
    out[0x1F] = 0;
    func_0034B7E8(self + 0x2664);
    return 1;
}

