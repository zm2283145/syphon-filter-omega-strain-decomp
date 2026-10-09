#ifndef MAIN_TYPES_H
#define MAIN_TYPES_H

/*
 * Provisional types used by matched functions. Field names are placeholders
 * (unkXX / padding) until the real layouts are recovered; see research/ at the
 * repository root for what is known about each structure.
 */

typedef struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16))) Vec4;

typedef struct PtrVec {
    int unk0;
    int count;
    int* data;
} PtrVec;

typedef struct Iter {
    int* p;
} Iter;

typedef struct Iter16 {
    char* p;
} Iter16;

typedef struct List {
    int count;
    void* first;
    void* last;
} List;

typedef struct Tri {
    char pad[10];
    unsigned char b10;
} Tri;

typedef struct G18 {
    char pad[0x18];
    int v;
} G18;

typedef struct G14 {
    char pad[0x14];
    int v;
} G14;

typedef struct Node {
    char pad[0xC];
    int count;
} Node;

typedef struct Rec {
    char pad[0xC];
    int v;
} Rec;

typedef struct Mover {
    char pad[0xD0];
    int* path;
    float speed;
    char pad2[4];
    unsigned char stopped;
} Mover;

typedef struct Args {
    Mover* obj;
    int arg1;
} Args;

typedef struct TexHdr {
    char pad[0x10];
    unsigned short pal;
    char pad2[0x22];
    unsigned short h34;
    unsigned short h36;
} TexHdr;

typedef struct PtrStack {
    int count;
    void* items[1];
} PtrStack;

typedef struct Tree {
    int unk0;
    int header;
    int unk8;
    int* leftmost;
} Tree;

typedef struct FStack {
    int count;
    float vals[1];
} FStack;

typedef struct Rel {
    int a, b, c;
} Rel;

typedef struct Leaf {
    char pad[0x10];
    int limit;
} Leaf;

typedef struct Word {
    int value;
} Word;

typedef struct IndexedList {
    int unk0;
    int count;
    int* base;
} IndexedList;

typedef struct Mtx44 {
    float m[4][4];
} Mtx44;

typedef struct Map {
    int count;
    int head;
    unsigned char cmp;
    void* hp;
} Map;

typedef struct Quad {
    int a, b, c, d;
} Quad;

/* Functions that are still assembly, called from matched C. */
extern void func_00139200(IndexedList* list, int* end, int n, void* arg);

#endif
