typedef struct { int* p; } It_1C4000;
typedef struct { int cap; int count; int* data; } Vec_1C4000;
typedef struct { char pad[0xC]; Vec_1C4000* vec; } Obj_1C4000;
extern char D_0049EE88[];
extern void Mem_Free(int pool, void* p, char* file, int line);
extern int* func_001C4180(Vec_1C4000* v);
extern int* func_001C4150(Vec_1C4000* v);
extern void func_001C4170(It_1C4000* out, Vec_1C4000* v, int** src);
extern void Terrain_ResolveIdList(int id);
extern void func_00136DA0(int* g);
extern void func_0012F530(int* g, int f);
extern void func_001C40F0(Vec_1C4000* v, int f);
void Pop_FinalizeTerrainList(Obj_1C4000* o)
{
    It_1C4000 it;
    It_1C4000 end;
    int* tb;
    int* te;
    int g[1];
    Vec_1C4000* v;
    int* p;
    int* e;
    v = o->vec;
    tb = func_001C4180(v);
    func_001C4170(&it, v, &tb);
    v = o->vec;
    p = it.p;
    te = func_001C4150(v);
    func_001C4170(&end, v, &te);
    e = end.p;
    if ((p == *(int* volatile*)&end.p) ^ 1) {
        do {
            Terrain_ResolveIdList(*p++);
        } while ((p == e) ^ 1);
    }
    v = o->vec;
    func_00136DA0(g);
    func_001C40F0(v, -1);
    Mem_Free(0, v, D_0049EE88, 0xAC);
    func_0012F530(g, -1);
}
