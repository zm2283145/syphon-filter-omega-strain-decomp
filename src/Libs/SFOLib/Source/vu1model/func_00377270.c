/* cVU1Model::PatchMeshes (vu1model.cc). Retail reloads g_TextureMgr after each 64-bit store (union with u64);
   tids index through (unsigned)p is not strength-reduced; inline SetM loads both mscal pointers first. */
#pragma cplusplus on
typedef unsigned long u64x;
struct tDrawContext { char pad[0x40]; u64x tex0; u64x tex0Reg; char pad50[0x10]; };
struct tFirstPassC {
    u64x dmaCtxt0[2];
    tDrawContext ctxt0;
    unsigned int dmaVerts0[4];
    u64x dmaCtxt1[2];
    tDrawContext ctxt1;
    unsigned int dmaVerts1[4];
};
struct tMultiPass {
    unsigned int pad0;
    unsigned int unpack0;
    tDrawContext ctxt0;
    unsigned int mscal0;
    unsigned int unpack1;
    tDrawContext ctxt1;
    unsigned int mscal1;
    unsigned int pad1;
};
struct tVUMMaterial { char idString[4]; unsigned int flags; unsigned int iparms[12]; int tids[4]; int rids[4]; int numPasses; };
struct tVUMStripPair {
    unsigned int flags;
    tFirstPassC* stripPairC;
    int numCols0;
    char* cols0;
    unsigned int* mscal0;
    int numCols1;
    char* cols1;
    unsigned int* mscal1;
};
struct tVUMMesh { char idString[4]; int numStripPairs; tVUMStripPair* stripPairs; int matId; };
struct tVUMHeader { char pad0[0x10]; int numMeshes; char pad14[0x3C]; tVUMMaterial* materials; tVUMMesh* meshes; };
struct tTexture { char pad[0x50]; u64x tex0; };
struct cTextureMgr { char pad[8]; tTexture** textures; };
union TMU { cTextureMgr* p; u64x q; };
extern TMU g_TextureMgr;
extern unsigned int D_00538080[];

#define FIX(f, T) ((f) = (T)((int)self->memHead + (int)(f)))

struct tFP { int a; char* p; };
class cVU1Model {
public:
    char* memHead;
    tVUMHeader* vumFile;
    short* txtrIDs;
};

inline void SetM(unsigned int* a, unsigned int* b, unsigned int v) { *a = v; *b = v; }
extern "C" void cVU1Model_PatchMeshes(cVU1Model* self)
{
    int i;
    for (i = 0; i < self->vumFile->numMeshes; i++) {
        tVUMMesh& mesh = self->vumFile->meshes[i];
        FIX(mesh.stripPairs, tVUMStripPair*);
        tVUMMaterial& mat = self->vumFile->materials[mesh.matId];
        int j;
        for (j = 0; j < mesh.numStripPairs; j++) {
            tVUMStripPair& sp = mesh.stripPairs[j];
            tFirstPassC* fpc;
            char* mpc;
            int p;
            FIX(sp.cols0, char*);
            FIX(sp.cols1, char*);
            mpc = 0;
            if (mat.numPasses == 1 && j > 0) {
                FIX(sp.stripPairC, tFirstPassC*);
                ((tFP*)sp.stripPairC)->p = ((tFP*)sp.stripPairC)->p + (int)self->memHead;
            } else {
                FIX(sp.stripPairC, tFirstPassC*);
                fpc = sp.stripPairC;
                mpc = (char*)(fpc + 1);
                mpc += 8;
                fpc->ctxt0.tex0 = g_TextureMgr.p->textures[self->txtrIDs[mat.tids[0]]]->tex0;
                fpc->ctxt0.tex0Reg = 6;
                fpc->ctxt1.tex0 = g_TextureMgr.p->textures[self->txtrIDs[mat.tids[0]]]->tex0;
                fpc->ctxt1.tex0Reg = 6;
                fpc->dmaVerts0[1] = fpc->dmaVerts0[1] + (int)self->memHead;
                fpc->dmaVerts1[1] = fpc->dmaVerts1[1] + (int)self->memHead;
            }
            for (p = 1; p < mat.numPasses; p++) {
                ((tMultiPass*)mpc)->ctxt0.tex0 = g_TextureMgr.p->textures[self->txtrIDs[mat.tids[(unsigned)p]]]->tex0;
                ((tMultiPass*)mpc)->ctxt0.tex0Reg = 6;
                ((tMultiPass*)mpc)->ctxt1.tex0 = g_TextureMgr.p->textures[self->txtrIDs[mat.tids[(unsigned)p]]]->tex0;
                ((tMultiPass*)mpc)->ctxt1.tex0Reg = 6;
                ((tMultiPass*)mpc)->mscal1 = ((tMultiPass*)mpc)->mscal0 = D_00538080[mat.rids[p]] | 0x14000000;
                mpc += sizeof(tMultiPass);
            }
            FIX(sp.mscal0, unsigned int*);
            FIX(sp.mscal1, unsigned int*);
            SetM(sp.mscal0, sp.mscal1, D_00538080[mat.rids[0]] | 0x14000000);
        }
    }
}