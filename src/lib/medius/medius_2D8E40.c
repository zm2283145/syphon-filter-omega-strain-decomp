typedef struct Node {
    char pad0[0x34];
    int id;
} Node;
typedef struct Obj {
    char pad0[0x5C];
    int x5C;
    char pad60[4];
    int x64;
    char pad68[4];
    Node *x6C;
    int x70;
    char pad74[0x8C - 0x74];
    int x8C;
    char pad90[0xA4 - 0x90];
    int xA4;
    int xA8;
    int xAC;
    int xB0;
    int xB4;
    int xB8;
} Obj;
extern int GridGetPrev(int);
extern int RemoveGrid(Obj *, int);
extern void DestroyGrid(int);
extern void RemovePlayer(Obj *, int);
extern void DestroyResourceManager(int);
extern void rt_udp_destroy(int);
extern void DestroyColorArray(int);
extern void rt_memory_free(Obj **);
void CleanupAudio(Obj *o)
{
    if (o == 0)
        return;
    while (o->x64 != 0)
        DestroyGrid(RemoveGrid(o, GridGetPrev(o->x64)));
    while (o->x6C != 0)
        RemovePlayer(o, o->x6C->id);
    if (o->x5C != 0) {
        DestroyResourceManager(o->x5C);
        o->x5C = 0;
    }
    if (o->x8C != 0) {
        rt_udp_destroy(o->x8C);
        o->x8C = 0;
    }
    if (o->xA4 != 0) {
        DestroyColorArray(o->xA4);
        o->xA4 = 0;
    }
    if (o->xA8 != 0) {
        DestroyColorArray(o->xA8);
        o->xA8 = 0;
    }
    if (o->xAC != 0) {
        DestroyColorArray(o->xAC);
        o->xAC = 0;
    }
    if (o->xB0 != 0) {
        DestroyColorArray(o->xB0);
        o->xB0 = 0;
    }
    if (o->xB4 != 0) {
        DestroyColorArray(o->xB4);
        o->xB4 = 0;
    }
    if (o->xB8 != 0) {
        DestroyColorArray(o->xB8);
        o->xB8 = 0;
    }
    o->x70 = 0;
    rt_memory_free(&o);
}
