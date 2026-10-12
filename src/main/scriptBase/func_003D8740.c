typedef char* va_list;
#define va_start(__AP, __LASTARG) (__AP = ((char*) __builtin_next_arg (__LASTARG) - (__builtin_args_info (2) >= 8 ? 0 : (8 - __builtin_args_info (2)) * 8)))
#define va_arg(__AP, __type) (*(__type *) (void *) ((__AP += 8) - 8))

extern void func_003D7E90(void);
extern char* strrchr(const char*, int);
extern int sprintf(char*, const char*, ...);
extern int func_003D9280(const char*);
extern void func_003D76D0(char*, int, int, int, int*, int);
extern char D_004BD3C8[];

int Script_RegisterNative_2(int a0, int a1, const char* name, int count, ...)
{
    int args[20];
    char buf[0x100];
    va_list ap;
    char* p;
    int i;

    va_start(ap, count);
    func_003D7E90();
    p = strrchr(name, ':');
    name = p ? p + 1 : name;
    sprintf(buf, D_004BD3C8, func_003D9280(name));
    for (i = 0; i < count; i++) {
        args[i] = va_arg(ap, int);
    }
    func_003D76D0(buf, a0, a1, count, args, 0);
    return 0;
}



