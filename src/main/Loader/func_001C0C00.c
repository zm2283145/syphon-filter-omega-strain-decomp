#include "types.h"
typedef struct Pop_001C0C00 { int version; int size; unsigned int base; char* cur; } Pop_001C0C00;
extern unsigned char D_00533880;
extern int D_00533888;
extern char D_0049EF30[];
extern char D_0049EE88[];
extern char D_004EE688[];
void Alloc_Lock(int id);
void Alloc_Unlock(int id);
void* Mem_Alloc(int heap, int size, char* file, int line);
int func_001698C0(void);
void func_00165E60(int a, char* b, int c);
int Pop_FindTag(Pop_001C0C00* r, int tag);
void* TriggerZone_ctor(void* p, Pop_001C0C00* r);
void* cHotbox_ctor(void* p, Pop_001C0C00* r, int type);
void func_00171020(void* vec, void** val);
void Object_Register(void* p);
static inline void Align_001C0C00(Pop_001C0C00* r)
{
    int mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
    if (mis)
        r->cur += 4 - mis;
}
static inline int ReadInt_001C0C00(Pop_001C0C00* r)
{
    int v = *(int*)r->cur;
    r->cur += 4;
    return v;
}
static inline void* Alloc_001C0C00(int size, int line)
{
    void* p;
    if (D_00533880) Alloc_Lock(9);
    D_00533888++;
    p = Mem_Alloc(0, size, D_0049EE88, line);
    if (D_00533880) Alloc_Unlock(9);
    D_00533888--;
    return p;
}
void Loader_InitHotboxes(void* self, Pop_001C0C00* r)
{
    if (r->cur) {
        func_00165E60(func_001698C0(), D_0049EF30, 0);
        Align_001C0C00(r);
        if ((unsigned char)Pop_FindTag(r, 0x3A584F42)) {
            int n = ReadInt_001C0C00(r);
            void* p;
            int i;
            for (i = 0; i < n; i++) {
                void* tmp[4];
                if (r->version > 0x35) {
                    int type = ReadInt_001C0C00(r);
                    switch (type) {
                    case 0xC:
                        {
                            void* t = Alloc_001C0C00(0xB0, 0x576);
                            if (t)
                                t = TriggerZone_ctor(t, r);
                            p = t;
                        }
                        break;
                    default:
                        {
                            void* t = Alloc_001C0C00(0xB0, 0x57A);
                            if (t)
                                t = cHotbox_ctor(t, r, type);
                            p = t;
                        }
                        break;
                    }
                } else {
                    {
                        void* t = Alloc_001C0C00(0xB0, 0x57F);
                        if (t)
                            t = cHotbox_ctor(t, r, -1);
                        p = t;
                    }
                }
                tmp[0] = p;
                func_00171020(D_004EE688, tmp);
                Object_Register(p);
            }
        }
    }
}