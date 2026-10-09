#ifndef MAIN_TYPES_H
#define MAIN_TYPES_H

/*
 * Provisional types used by matched functions. Field names are placeholders
 * (unkXX / padding) until the real layouts are recovered.
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

#endif
