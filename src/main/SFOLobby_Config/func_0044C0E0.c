typedef struct {
    int type;
    int status;
    char a[32];
    char b[32];
    char c[32];
} CombEnt;
typedef struct {
    int count;
    int sel;
    int ids[10];
    CombEnt ent[10];
} CombList;
typedef struct {
    unsigned char isDefault;
    int dev;
    int id;
    int type;
    int status;
    char a[32];
    char b[32];
    char c[32];
    char pad74[0xC];
    char prop[0x1340];
} NetCfgInfo;
typedef struct {
    char pad[0x23D8];
    struct { int pad; int count; }* list;
} NetCfg;
extern char* D_00497720[];
extern char D_004C0D70[];
extern CombList D_00584580;
extern char D_005849C0[];
void func_00452F70(NetCfg*, int, int);
void func_0044F7E0(void*);
void func_0010D3E0(int);
int ezNetCnfGetCombinationList(char*, int, CombList*);
int ezNetCnfGetProperties(char*, char*, void*);
void func_00451B00(NetCfg*, int, char*, int);
void func_0044F470(void*, NetCfgInfo*);
void* memset(void*, int, unsigned int);
void* memcpy(void*, const void*, unsigned int);

int func_0044C0E0(NetCfg* self, int which)
{
    int dev;
    int n;
    int i;
    NetCfgInfo info;

    func_00452F70(self, 2, 1);
    func_0044F7E0(self->list);
    for (dev = 0; dev < 2; dev++) {
        if (which >= 0 && which != dev) continue;
        func_0010D3E0(0);
        n = ezNetCnfGetCombinationList(D_00497720[dev], 1, &D_00584580);
        func_0010D3E0(0);
        if (n <= 0) {
            switch (n) {
            case 0:
                func_00451B00(self, 0x2F, D_004C0D70, 0xC2);
                break;
            case -15:
                func_00451B00(self, 0x30, D_004C0D70, 0xC6);
                break;
            default:
                func_00451B00(self, 0x2F, D_004C0D70, 0xCB);
                break;
            }
            return 0;
        }
        for (i = 0; i < D_00584580.count; i++) {
            memset(&info, 0, sizeof(info));
            info.isDefault = D_00584580.sel == i + 1;
            info.dev = dev;
            info.id = D_00584580.ids[i];
            info.type = D_00584580.ent[i].type;
            info.status = D_00584580.ent[i].status;
            memcpy(info.a, D_00584580.ent[i].a, 32);
            memcpy(info.b, D_00584580.ent[i].b, 32);
            memcpy(info.c, D_00584580.ent[i].c, 32);
            if (info.type >= 0) {
                func_0010D3E0(0);
                if (ezNetCnfGetProperties(D_00497720[info.dev], info.a, D_005849C0) == 0) {
                    func_0010D3E0(0);
                    memcpy(info.prop, D_005849C0, sizeof(info.prop));
                    func_0044F470(self->list, &info);
                }
            }
        }
        if (self->list->count == 0) {
            func_00451B00(self, 0x2F, D_004C0D70, 0x10A);
            return 0;
        }
    }
    return 1;
}

