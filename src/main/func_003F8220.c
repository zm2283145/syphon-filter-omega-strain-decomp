#pragma cplusplus on
typedef struct Sys3F82 {
    char pad00[0x30];
    int f30;
    char pad34[0x24];
    char part58[0x1D9];
    bool f231;
    char pad232[2];
    bool f234;
    bool done;
    bool f236;
} Sys3F82;

extern char D_00571CF0[];
extern char D_0055C480[];
extern char D_0055C540[];
extern "C" {
extern void func_00411DB0(void* p);
extern int func_003F5CE0(void* p);
extern void func_003F8000(Sys3F82* s, void* r, int a, void* b);
extern bool func_003F5AE0(void* p);
extern bool func_003F5A80(void* p);
extern void func_0010D010(int n);
extern void func_003F6F90(void);
extern void func_003F6CD0(void* p);
extern void func_003F8390(Sys3F82* s);
extern void func_003F8450(Sys3F82* s);
bool func_003F8220(Sys3F82* s);
}

bool func_003F8220(Sys3F82* s)
{
    func_00411DB0(D_00571CF0);
    if (!s->done) {
        if (s->f234) {
            s->done = 1;
        }
        if (func_003F5CE0(D_0055C480) != 3) {
            func_003F8000(s, D_0055C480, s->f30, s->part58);
        } else if (!s->f231) {
            s->done = 1;
        }
        if (s->done) {
            while (!func_003F5AE0(D_0055C480)) {
                func_0010D010(5);
            }
            while (!func_003F5A80(D_0055C480) && func_003F5CE0(D_0055C480) != 3) {
                func_0010D010(5);
            }
            func_003F6F90();
            if (s->f236) {
                func_003F6CD0(D_0055C540);
            }
        }
        if (s->f234) {
            func_003F8390(s);
            func_003F8450(s);
            s->f234 = 0;
            s->done = 0;
        }
    }
    return !s->done;
}
