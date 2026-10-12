#pragma cplusplus on
extern "C" {
extern char D_004C0ED0;
extern char D_004C0EC0;
int func_00443E70(...);
void func_0044D860(char* self, int a);
int func_00450A90(char* list, int id, int a);
int func_00451200(char* self, int id);
int func_00451B00(char* self, int code, char* file, int line);
void* memset(void* d, int c, unsigned int n);
void String_Copy(char* d, char* s);
char* strncpy(char* d, const char* s, unsigned int n);
int func_0046A5F0(void* req, void* cb);
void func_004466B0(void);
}

struct Req_44DB60 {
    char name[0x15];
    char nick[0x13];
    int id;
    int flag;
};

static inline bool Has_44DB60(char* self, int id)
{
    if (func_00450A90(self + 0x150, id, 0)) return true;
    return func_00450A90(self + 0xE0, id, 0) != 0;
}

extern "C" int func_0044DB60(char* self, int id)
{
    Req_44DB60 req;
    bool found;

    if (id < 0) {
        func_00451B00(self, 0x1D, &D_004C0ED0, 0xD0);
        return 0;
    }
    if (id == *(int*)(self + 0x2480)) {
        func_00451B00(self, 0x25, &D_004C0ED0, 0xD6);
        return 0;
    }
    func_00443E70();
    func_0044D860(self, 1);
    *(int*)(self + 0x257C) = func_00443E70();
    found = Has_44DB60(self, id);
    if (found) {
        func_00451B00(self, 0x1E, &D_004C0ED0, 0xDD);
        return 0;
    }
    if (!func_00451200(self, id)) {
        func_00451B00(self, 1, &D_004C0ED0, 0xE5);
        return 0;
    }
    memset(&req, 0, sizeof(req));
    String_Copy(req.name, &D_004C0EC0);
    strncpy(req.nick, self + 0x2418, 0x11);
    req.flag = 1;
    req.id = id;
    *(int*)(self + 0x24C) = func_0046A5F0(&req, func_004466B0);
    if (*(int*)(self + 0x24C)) {
        func_00451B00(self, 1, &D_004C0ED0, 0x104);
        return 0;
    }
    func_00451B00(self, 0, &D_004C0ED0, 0x126);
    return 1;
}

