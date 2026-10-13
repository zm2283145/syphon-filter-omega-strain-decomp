typedef struct {
    char name[0x18];
    int code;
    char user[0x14];
    int f30;
    int f34;
} Msg_00446560;
typedef struct { char pad[8]; int f8; } Arg_00446560;
extern void* memset(void* p, int c, int n);
extern char* String_Copy(char* dst, const char* src);
extern char* strncpy(char* dst, const char* src, int n);
extern int func_0046A690(Msg_00446560* m);
extern void func_00451B00(char* self, int err, const char* file, int line);

int func_00446560(char* self, Arg_00446560* arg, int ok)
{
    Msg_00446560 m;
    memset(&m, 0, sizeof(m));
    String_Copy(m.name, "1");
    strncpy(m.user, self + 0x2418, 0x11);
    m.f30 = arg->f8;
    m.f34 = 1;
    m.code = ok ? 2 : -985;
    if (func_0046A690(&m)) {
        func_00451B00(self, 1, "SFOLobby_Callback.cc", 2084);
        return 0;
    }
    func_00451B00(self, 0, "SFOLobby_Callback.cc", 2088);
    return 1;
}
