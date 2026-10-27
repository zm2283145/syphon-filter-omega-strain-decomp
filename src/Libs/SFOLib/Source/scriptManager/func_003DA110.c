/* cScriptInterpreter_SymbolTable_loadScript 003DA110 draft (mw38, C++). cdiff: 1329 '**' lines of ~1992; prelude+early return match modulo frame (0x360 vs 0x390), slti v0 vs at; mid-body register allocation swaps (s0/s1/s2, fp vs stack temp). */
#pragma cplusplus on
#pragma inline_depth(12)
#include "types.h"
#include "alloc_guard.h"
typedef unsigned char u8;

extern "C" {
extern char D_004BD4C0[];
extern char D_004BDC18[];
extern char D_004BDC28[];
extern char D_004BDC68[];
extern int D_004938F0;
extern int D_004938F8;
void* cMemMan_Allocate(int heap, int size, char* file, int line);
void cMemMan_Deallocate(int heap, void* p, char* file, int line);
char* cScriptBase_myStrdup(char* s);
void Libc_Strcpy(char* d, void* s);
int String_CompareNoCase(char* a, char* b);
void* memcpy(void* d, const void* s, unsigned int n);
void cFileMan_ctor_void(void* h);
void cFileMan_Close(void* h);
void cFileMan_dtor(void* h, int f);
void cFileIO_dtor(void* p, int f);
int* cFileMan_Read_void(void* h);
int cFileMan_GetSize(void* h);
void std_vector_pod_int_resize(void* v, int n, void* const& fill);
void** cArray_VarDefPtr_opIndex(void* s, int id);
void std_vector_SubScriptPtr_push_back(void* v, void* p);
void** std_vector_SubScriptPtr_opIndex(void* v, int i);
void** std_vector_intPtr_opIndex(void* v, int i);
void std_vector_charPtr_push_back_charPR(void* v, void* p);
struct TypeRec* cScriptBase_getClass(int id);
int cScriptInterpreter_SymbolTable_remapType(void* s, int t);
void* SubScript_ctor(void* p, int id, char* name);
void cScriptInterpreter_SymbolTable_addClass(void* s, char* name, u8 b, char* name2, int n, char** strs, int* ints, int idx);
void cScriptInterpreter_SymbolTable_addEnum(void* s, char* name, int idx, void* recs, int n);
void cScriptInterpreter_SymbolTable_addFunc(void* s, void* rec, int idx);
void cScriptInterpreter_SymbolTable_addVar(void* s, char* name, int a, int* p, int* arr, u8 reload, int idx);
}

struct Vec { int cap; int count; void** data; int pad; void*& operator[](unsigned int i) { return data[i]; } };

struct TypeRec { int x0; Vec fields; char pad14[0x28]; u8 x3C; };

struct SubScript { char pad[0x60]; int id; char pad64[4]; char* name; };

struct ScriptRec {
    char* name;      /* 0x00 */
    int x4;
    int count;       /* 0x08 */
    int xC;
    int pad10;
    int x14;
    u8 x18;
    u8 x19;
    char pad1A[2];
    int arr[20];     /* 0x1C */
    SubScript* sub;  /* 0x6C */
    void* x70;
    void* x74;
    int* x78;
};

struct Script {
    Vec v00;
    Vec v10;
    Vec v20;
    Vec v30;
    Vec v40;
    Vec v50;
    Vec v60;
    Vec v70;
    char* name;      /* 0x80 */
    int* x84;
    int* x88;
    int version;     /* 0x8C */
};

static inline void* New_3DA110(int size, char* f, int line) { AllocGuard g; return cMemMan_Allocate(0, size, f, line); }
static inline void Del_3DA110(void* p, char* f, int line) { if (p) { AllocGuard g; cMemMan_Deallocate(0, p, f, line); } }
static inline void DelG_3DA110(int* p, char* f, int line) { AllocGuard g; cFileIO_dtor(p, -1); cMemMan_Deallocate(0, p, f, line); }
static inline void DelU_3DA110(void* p, char* f, int line) { AllocGuard g; cMemMan_Deallocate(0, p, f, line); }

struct ScriptFile {
    int* file;
    int size;
    char hog[0x9C];
    void* buf;
    int* cur;
    int* data;
    int b0;
    int len;
    u8 ok;

    ScriptFile(char* name, int sz) { cFileMan_ctor_void(hog); file = 0; size = sz; Open(name, 0); }
    void Open(char* name, int mode);
    __declspec(weak) __declspec(ALLOC_GUARD_DTOR) ~ScriptFile() {
        cFileMan_Close(hog);
        if (file) {
            DelG_3DA110(file, D_004BDC28, 0x45);
            file = 0;
        }
        size = 0;
        Del_3DA110(buf, D_004BDC18, 0x4B);
        cur = 0;
        buf = 0;
        data = 0;
        ok = 0;
        cFileMan_dtor(hog, -1);
    }
    int ReadInt() { int* p = cur; cur = p + 1; return *p; }
    bool ReadBool() { return ReadInt() != 0; }
    bool ReadBool2() { int v = ReadInt(); return v != 0; }
    u8 ReadU8() { return ReadInt() != 0; }
    char* ReadString() {
        int n = ReadInt();
        char* s = n ? (char*)New_3DA110(n, D_004BDC68, 0xF9) : 0;
        if (s) {
            Libc_Strcpy(s, cur);
            cur += (unsigned)(n + 3) >> 2;
        }
        return s;
    }
};

extern "C" void ScriptFileBuff_open(ScriptFile* s, char* name, int mode);
inline void ScriptFile::Open(char* name, int mode) { ScriptFileBuff_open(this, name, mode); }

static inline TypeRec* GetType(void* p) { return cScriptBase_getClass((int)p); }

extern "C" u8 cScriptInterpreter_SymbolTable_loadScript(Script* s, int size, char* name)
{
    u8 reload = 0;
    u8 result;
    int i;

    if (name) {
        s->name = cScriptBase_myStrdup(name);
    } else {
        int n;
        reload = 1;
        n = s->v10.count;
        i = 0;
        if (0 < n) do {
            char* v = (char*)s->v10[i];
            if (v && *(Script**)(v + 0x20) == s) {
                *(u8*)(v + 0x34) = 0;
                *(Script**)(v + 0x20) = 0;
            }
        } while (++i < n);
    }
    {
        ScriptFile sf(s->name, size);
        ScriptFile* f = &sf;
        result = 0;
        if (sf.ok) {
            int n, nTypes;
            u8* flags;
            int* oldGlobals;
            int nSubs, nGlobals, nRecs;
            result = 1;
            f->data = cFileMan_Read_void(f->hog);
            f->len = cFileMan_GetSize(f->hog);
            f->cur = f->data;
            f->buf = 0;
            s->version = f->ReadInt();
            if (s->version > 9) {
                return 0;
            }

            n = f->ReadInt();
            Del_3DA110(s->x84, D_004BD4C0, 0xBD8);
            s->x84 = n ? (int*)New_3DA110(n * 4, D_004BD4C0, 0xBDA) : 0;
            memcpy(s->x84, f->cur, n * sizeof(int));
            f->cur += n;

            int n1 = f->ReadInt();
            std_vector_pod_int_resize(&s->v60, n1, (void*)0);
            { int i = 0; if (0 < n1) do {
                char* str = f->ReadString();
                s->v60[i] = str;
            } while (++i < n1); }

            n = s->v20.count;
            i = 0; if (0 < n) do {
                if (s->v20[i]) {
                    DelU_3DA110(*std_vector_intPtr_opIndex(&s->v20, i), D_004BD4C0, 0xBED);
                }
            } while (++i < n);

            nTypes = f->ReadInt();
            std_vector_pod_int_resize(&s->v30, nTypes, *(void**)&D_004938F0);
            std_vector_pod_int_resize(&s->v20, nTypes, (void*)0);
            flags = nTypes ? (u8*)New_3DA110(nTypes, D_004BD4C0, 0xBF3) : 0;
            i = 0; if (0 < nTypes) do {
                char* tname = f->ReadString();
                u8 b = f->ReadU8();
                char* tname2;
                int cnt, j;
                char** strs;
                int* ints;
                flags[i] = b;
                tname2 = f->ReadString();
                cnt = f->ReadInt();
                strs = cnt ? (char**)New_3DA110(cnt * 4, D_004BD4C0, 0xBFE) : 0;
                ints = cnt ? (int*)New_3DA110(cnt * 4, D_004BD4C0, 0xBFF) : 0;
                j = 0; if (0 < cnt) do {
                    strs[j] = f->ReadString();
                    ints[j] = f->ReadInt();
                } while (++j < cnt);
                cScriptInterpreter_SymbolTable_addClass(s, tname, b, tname2, cnt, strs, ints, i);
                j = 0; if (0 < cnt) do {
                    DelU_3DA110(strs[j], D_004BD4C0, 0xC0A);
                } while (++j < cnt);
                Del_3DA110(strs, D_004BD4C0, 0xC0D);
                Del_3DA110(ints, D_004BD4C0, 0xC10);
                Del_3DA110(tname2, D_004BD4C0, 0xC13);
                DelU_3DA110(tname, D_004BD4C0, 0xC15);
            } while (++i < nTypes);

            n = f->ReadInt();
            std_vector_pod_int_resize(&s->v40, n, *(void**)&D_004938F8);
            i = 0; if (0 < n) do {
                char* fname = f->ReadString();
                if (f->ReadInt() == 0) {
                    int cnt = f->ReadInt();
                    int j;
                    int* recs = cnt ? (int*)New_3DA110(cnt * 12, D_004BD4C0, 0xC24) : 0;
                                        j = 0; if (0 < cnt) do {
                        char* str = f->ReadString();
                        recs[j * 3 + 1] = (int)str;
                        std_vector_charPtr_push_back_charPR(&s->v70, &str);
                        recs[j * 3] = f->ReadInt();
                    } while (++j < cnt);
                    cScriptInterpreter_SymbolTable_addEnum(s, fname, i, recs, cnt);
                    DelU_3DA110(recs, D_004BD4C0, 0xC2E);
                } else {
                    cScriptInterpreter_SymbolTable_addEnum(s, fname, i, 0, 0);
                }
                DelU_3DA110(fname, D_004BD4C0, 0xC33);
            } while (++i < n);

            i = 0; if (0 < nTypes) do {
                TypeRec* rec = GetType(s->v30[i]);
                if (!flags[i] && rec->x3C) {
                    int cnt = rec->fields.count;
                    int j;
                    j = 0; if (0 < cnt) do {
                        int& t = ((int*)rec->fields[j])[2];
                        t = cScriptInterpreter_SymbolTable_remapType(s, t);
                    } while (++j < cnt);
                }
            } while (++i < nTypes);
            DelU_3DA110(flags, D_004BD4C0, 0xC46);

            nSubs = f->ReadInt();
            i = 0; if (0 < nSubs) do {
                int id = f->ReadInt();
                char* sname = f->ReadString();
                SubScript* sub = 0;
                if (reload) {
                    int cnt = s->v50.count;
                    int j;
                    for (j = 0; !sub && j < cnt; j++) {
                        if (String_CompareNoCase((*(SubScript**)std_vector_SubScriptPtr_opIndex(&s->v50, j))->name, sname) == 0) {
                            sub = (SubScript*)s->v50[j];
                            sub->id = id;
                            DelU_3DA110(sname, D_004BD4C0, 0xC5B);
                        }
                    }
                }
                if (!sub) {
                    void* p = New_3DA110(0x6C, D_004BD4C0, 0xC61);
                    if (p) p = SubScript_ctor(p, id, sname);
                    sub = (SubScript*)p;
                    std_vector_SubScriptPtr_push_back(&s->v50, &sub);
                }
            } while (++i < nSubs);

            n = s->v00.count;
            i = 0; if (0 < n) do {
                char* v = (char*)s->v00[i];
                if (v) (*(int*)(v + 0x10))--;
            } while (++i < n);

            nGlobals = f->ReadInt();
            oldGlobals = s->x88;
            std_vector_pod_int_resize(&s->v00, nGlobals, (void*)0);
            s->x88 = nGlobals ? (int*)New_3DA110(nGlobals * 4, D_004BD4C0, 0xC71) : 0;
            i = 0; if (0 < nGlobals) do {
                char* gname = f->ReadString();
                int a = f->ReadInt();
                u8 isNull; isNull = f->ReadU8();
                int idx = f->ReadInt();
                int cnt = f->ReadInt();
                int* arr = 0;
                if (cnt) {
                    arr = (int*)New_3DA110(cnt * sizeof(int), D_004BD4C0, 0xC80);
                    memcpy(arr, f->cur, cnt * sizeof(int));
                    f->cur += cnt;
                }
                cScriptInterpreter_SymbolTable_addVar(s, gname, a, isNull ? 0 : &s->x88[idx], arr, reload, i);
                DelU_3DA110(gname, D_004BD4C0, 0xC85);
            } while (++i < nGlobals);
            Del_3DA110(oldGlobals, D_004BD4C0, 0xC8A);

            { int i = 0; if (0 < nSubs) do {
                void** p = cArray_VarDefPtr_opIndex(s, ((SubScript*)s->v50[i])->id);
                **(void***)((char*)*p + 0xC) = s->v50[i];
            } while (++i < nSubs); }

            n = s->v10.count;
            i = 0; if (0 < n) do {
                char* v = (char*)s->v10[i];
                if (v) (*(int*)(v + 0x38))--;
            } while (++i < n);

            nRecs = f->ReadInt();
            std_vector_pod_int_resize(&s->v10, nRecs, (void*)0);
            i = 0; if (0 < nRecs) do {
                ScriptRec rec;
                u8 isNull;
                int idx, subId, a, b, j;
                rec.name = f->ReadString();
                rec.x4 = f->ReadInt();
                isNull = f->ReadU8();
                f->ReadInt();
                rec.x14 = s->version > 1 ? f->ReadInt() : 0;
                idx = f->ReadInt();
                subId = f->ReadInt();
                rec.xC = f->ReadInt();
                a = f->ReadInt();
                b = s->version > 1 ? f->ReadInt() : -1;
                rec.x18 = s->version > 4 ? f->ReadInt() != 0 : false;
                rec.x19 = s->version >= 9 ? f->ReadInt() != 0 : true;
                rec.sub = 0;
                if (subId >= 0) {
                    for (j = s->v50.count - 1; j >= 0; j--) {
                        if (subId == ((SubScript*)s->v50[j])->id) {
                            rec.sub = (SubScript*)s->v50[j];
                            break;
                        }
                    }
                }
                rec.count = f->ReadInt();
                { int cnt = rec.count;
                memcpy(rec.arr, f->cur, cnt * sizeof(int));
                f->cur += cnt; }
                rec.x70 = 0;
                rec.x74 = 0;
                if (a > -1) {
                    rec.x70 = (char*)s->v00[a] + 0xC;
                } else if (b > -1) {
                    rec.x74 = (char*)s->v00[b] + 0xC;
                }
                rec.x78 = isNull ? 0 : &s->x84[idx];
                if (rec.count < 2 || !rec.x78) rec.x19 = 0;
                cScriptInterpreter_SymbolTable_addFunc(s, &rec, i);
                DelU_3DA110(rec.name, D_004BD4C0, 0xCDF);
            } while (++i < nRecs);
        }
    }
    return result;
}














