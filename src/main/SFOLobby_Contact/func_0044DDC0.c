#pragma opt_propagation off
#pragma cplusplus on
extern "C" {
extern int D_004977B8;
extern int D_004977D0;
extern char D_004C0EE8;
int func_00443E70(void);
void func_0044D860(char* self, int a);
void func_004498C0(char* self);
void func_00451B30(char* self);
void func_00453FA0(char* self, void* list);
void func_0044EBD0(char* self, void* list);
int func_0044F170(void* list);
int* func_0044F290(void* list, int i);
void func_00449800(char* self, int a);
void* memset(void* d, int c, unsigned int n);
int sprintf(char* d, const char* f, ...);
char* strncpy(char* d, const char* s, unsigned int n);
int func_0046A048(void* req, void* cb);
void func_004467D0(void);
}

struct List_44DDC0 {
    int pad0;
    int count;
};

struct Req_44DDC0 {
    char name[0x15];
    char nick[0x13];
    int id;
};

extern "C" void func_0044DDC0(char* me)
{
    char* self;
    int now;
    int last;
    List_44DDC0* list;
    int d;
    Req_44DDC0 req;
    int i;
    int* item;
    self = me;
    if (*(int*)(self + 0x255C) == 6 && !*(unsigned char*)(self + 0x2409)) {
        last = *(int*)(self + 0x257C);
        d = func_00443E70() - last;
        if (!last || d > D_004977B8) {
            func_0044D860(self, 0);
            *(int*)(self + 0x257C) = func_00443E70();
        }
        func_004498C0(self);
        func_00451B30(self);
        func_00453FA0(self, self + 0xE0);
        func_0044EBD0(self, self + 0xE0);
        now = func_00443E70();
        list = (List_44DDC0*)(self + 0xE0);
        if (now - *(int*)(self + 0x2580) > D_004977D0 && !(unsigned char)func_0044F170(list)) {
            *(int*)(self + 0x2580) = now;
            i = 0;
            if (0 < list->count) {
                do {
                item = func_0044F290(list, i);
                if (item[9] != 3) {
                    memset(&req, 0, sizeof(req));
                    sprintf(req.name, &D_004C0EE8, item[0]);
                    strncpy(req.nick, self + 0x2418, 0x11);
                    req.id = item[0];
                    func_0046A048(&req, func_004467D0);
                }
                    i++;
                } while (i < list->count);
            }
        }
        func_00449800(self, 0);
    }
}








