#pragma cplusplus on
#include "types.h"
struct MRec {
    int p;
    unsigned short h;
    unsigned char b6;
    unsigned char b7;
    int f8;
    int fC;
    MRec& operator=(const MRec& o) { p = o.p; h = o.h; b6 = o.b6; b7 = o.b7; f8 = o.f8; fC = o.fC; return *this; }
};
typedef struct {
    char pad0[0x2C10];
    __int128 keys[0x300];
    MRec recs[1][2];
} MCache;
typedef struct {
    char pad[0x44];
    void* f44;
} TEnt;
typedef struct {
    int pad[2];
    TEnt** entries;
    char padC[0x440 - 0xC];
    char def[1];
} TMgr;
typedef struct {
    char pad0[0x60];
    __int128 key;
    char pad70[0x1EC0 - 0x70];
    MRec part[2][32];
    short cur[32], prev[32];
    char pad2340[0x80];
    unsigned short count;
    char pad23C2[0x2BDB - 0x23C2];
    signed char missing;
    unsigned char b2BDC;
} SkMdl;
extern "C" {
extern MCache D_0055DDA0;
extern TMgr* D_00539248;
int MeshCache_FindSlot(MCache* c, __int128 key);
void Model_HardMeshAttachPoints(SkMdl* m);
}
extern "C" signed char ActorModel_StreamWait(SkMdl* m)
{
    unsigned long n = m->count;
    int lod;
    m->missing = 0;
    int s = MeshCache_FindSlot(&D_0055DDA0, m->key);
    if (s != -1 && !D_0055DDA0.recs[s][0].p) {
        m->missing++;
    }
    for (lod = 0; lod < 2; lod++) {
        MRec* e = m->part[lod];
        unsigned int i;
        for (i = 0; i < n; e++, i++) {
            if (!e->p) {
                unsigned short h = e->h;
                if (h) {
                    if (D_0055DDA0.recs[e->h][lod].p) {
                        m->part[lod][i].p = D_0055DDA0.recs[h][lod].p;
                        m->part[lod][i].h = D_0055DDA0.recs[h][lod].h;
                        m->part[lod][i].b6 = D_0055DDA0.recs[h][lod].b6;
                        m->part[lod][i].b7 = D_0055DDA0.recs[h][lod].b7;
                        m->part[lod][i].f8 = D_0055DDA0.recs[h][lod].f8;
                        m->part[lod][i].fC = D_0055DDA0.recs[h][lod].fC;
                        m->part[lod ^ 1][i].p = D_0055DDA0.recs[h][lod ^ 1].p;
                        m->part[lod ^ 1][i].h = D_0055DDA0.recs[h][lod ^ 1].h;
                        m->part[lod ^ 1][i].b6 = D_0055DDA0.recs[h][lod ^ 1].b6;
                        m->part[lod ^ 1][i].b7 = D_0055DDA0.recs[h][lod ^ 1].b7;
                        m->part[lod ^ 1][i].f8 = D_0055DDA0.recs[h][lod ^ 1].f8;
                        m->part[lod ^ 1][i].fC = D_0055DDA0.recs[h][lod ^ 1].fC;
                    } else {
                        m->missing++;
                    }
                }
            }
        }
    }
    {
        TMgr* mgr = D_00539248;
        unsigned int i;
        for (i = 0; i < n; i++) {
            m->missing += mgr->entries[m->cur[i]]->f44 == mgr->def;
            m->missing += mgr->entries[m->prev[i]]->f44 == mgr->def;
        }
    }
    if (!m->missing) {
        m->b2BDC = 0;
        Model_HardMeshAttachPoints(m);
    }
    return m->missing;
}







