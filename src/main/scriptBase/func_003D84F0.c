typedef char* va_list;
#define va_start(__AP, __LASTARG) (__AP = ((char*) __builtin_next_arg (__LASTARG) - (__builtin_args_info (2) >= 8 ? 0 : (8 - __builtin_args_info (2)) * 8)))
#define va_arg(__AP, __type) (*(__type *) (void *) ((__AP += 8) - 8))

extern unsigned char D_00533880;
extern int D_00533888;
extern char D_004BD3B0[];
typedef struct { char pad[8]; char** tab; } ScrMgr;
extern ScrMgr* D_00554F28;
void Alloc_Lock(int id);
void Alloc_Unlock(int id);
void* Mem_Alloc(int a, int size, char* file, int line);
void* func_003D7380(void* p, int a3, int a1, int a2, int count, int* args);
void func_003D8720(char* list, void** item);
void func_003D76D0(int a3, int a1, int a2, int count, int* args, int flag);

int Script_RegisterNative(int id, int a1, int a2, int a3, int count, ...)
{
    char* o;
    void* item;
    int args[20];
    void* p;
    va_list ap;
    int i;

    { int k = id - 0x64; o = D_00554F28->tab[k]; }
    va_start(ap, count);
    for (i = 0; i < count; i++) {
        args[i] = va_arg(ap, int);
    }
    if (D_00533880) Alloc_Lock(9);
    D_00533888++;
    p = Mem_Alloc(0, 0x1C, D_004BD3B0, 0xCA);
    if (D_00533880) Alloc_Unlock(9);
    D_00533888--;
    if (p) p = func_003D7380(p, a3, a1, a2, count, args);
    item = p;
    func_003D8720(o + 0x14, &item);
    func_003D76D0(a3, a1, a2, count, args, 1);
    return 0;
}



