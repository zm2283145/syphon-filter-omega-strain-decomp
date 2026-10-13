#pragma cplusplus on
typedef struct { char pad[0x9C]; } FileMan;
typedef struct { char pad[0xE4]; int count; __int128* buf; } Obj37F0;
extern "C" {
extern unsigned char D_00533880;
extern int D_00533888;
void Alloc_Lock(int id);
void Alloc_Unlock(int id);
extern char D_004BE7F0[];
extern void func_0036E4B0(FileMan* f, char* name, int a, int b);
extern int func_0036DEF0(FileMan* f);
extern int FileMan_GetSize(FileMan* f);
extern void* Mem_Alloc(int pool, int size, char* file, int line);
extern int func_0036D990(FileMan* f, __int128** out, int size);
extern void func_0036DEC0(FileMan* f);
extern void func_0036E220(FileMan* f, int a);
void func_004037F0(Obj37F0* s, char* name);
}
static inline long long iszero(__int128 a) {
    __int128 t;
    long long r;
    asm {
        pceqw t, zero, a
        ppach r, t, t
    }
    return r;
}
void func_004037F0(Obj37F0* s, char* name)
{
    FileMan fm;
    int size;
    __int128* end;
    __int128* p;
    void* mem;
    func_0036E4B0(&fm, name, 0, 0);
    if (!(unsigned char)func_0036DEF0(&fm)) {
        size = FileMan_GetSize(&fm);
        if (D_00533880) Alloc_Lock(9);
        D_00533888++;
        mem = Mem_Alloc(0, size, D_004BE7F0, 0x9B5);
        if (D_00533880) Alloc_Unlock(9);
        D_00533888--;
        s->buf = (__int128*)mem;
        func_0036D990(&fm, &s->buf, size);
        func_0036DEC0(&fm);
        p = s->buf;
        if (p) {
            end = (__int128*)((char*)p + size);
            while (iszero(*p) != -1 && p < end) {
                s->count++;
                p += 8;
            }
        }
    }
    func_0036E220(&fm, -1);
}


