#ifndef NPC_INFO_PURGE_H
#define NPC_INFO_PURGE_H
/* NPCInfoObject list purge: walk a std::list of owned entries, and for each
   entry whose f10 matches key: set the local player's flag (a6[id]) of the
   matching record in arr[29], delete the entry and erase its node.
   C++ only; include alloc_guard.h, net_local_id.h and npc_info_rec.h first.
   Local declaration order sets retail's register assignment. */
typedef struct { int key; char pad[0xC]; int f10; } NpcPurgeEnt;
typedef struct NpcPurgeNode { struct NpcPurgeNode* prev; struct NpcPurgeNode* next; NpcPurgeEnt* data; } NpcPurgeNode;
struct NpcPurgeIt { NpcPurgeNode* node; NpcPurgeIt() {} };
extern "C" {
extern char D_004BFCA0[];
void Mem_Free(int pool, void* p, char* file, int line);
NpcPurgeIt List_Begin(void* list);
void func_00432740(NpcPurgeIt* r, const NpcPurgeIt& s);
NpcPurgeIt func_00432730(void* list);
void func_00432720(NpcPurgeIt* r, const NpcPurgeIt& s);
void func_0015AF40(NpcPurgeIt* r, NpcPurgeNode** n);
void List_Erase(NpcPurgeIt* r, void* list, NpcPurgeIt* pos);
}
#define DEFINE_NPC_INFO_PURGE(name, list, flagval, line)                        \
    extern "C" { extern char list[]; }                                          \
    extern "C" void name(void* self, NpcInfoRec* arr, int key)                  \
    {                                                                           \
        NpcPurgeIt end; NpcPurgeIt it; NpcPurgeEnt* e; NpcInfoRec* found;       \
        NpcPurgeNode* n; NpcPurgeNode* cur;                                     \
        func_00432740(&it, List_Begin(list));                                \
        n = it.node;                                                            \
        while (func_00432720(&end, func_00432730(list)), n != end.node) {       \
            cur = n; e = cur->data; n = n->next;                                \
            found = 0;                                                          \
            if (key == e->f10) {                                                \
                int i;                                                          \
                for (i = 0; i != 29; i++) {                                     \
                    if (e->key == arr[i].key) { found = &arr[i]; break; }       \
                }                                                               \
                if (found) found->a6[NetLocalId()] = (flagval);                 \
                {                                                               \
                    AllocGuard g;                                               \
                    Mem_Free(0, e, D_004BFCA0, (line));                         \
                }                                                               \
                {                                                               \
                    NpcPurgeNode* c = cur; NpcPurgeIt b; NpcPurgeIt a;          \
                    func_0015AF40(&a, &c);                                      \
                    List_Erase(&b, list, &a);                                \
                }                                                               \
            }                                                                   \
        }                                                                       \
    }
#endif