#include "types.h"

typedef struct { int value; } Key;
typedef struct { int a; int b; } KeyPair;
typedef struct { int a; int b; int c; } Entry12;
typedef struct { int value; } InsertResult;

extern void func_003CE730(Entry12* out, Key* key, KeyPair* pair);
extern void FrameTree_Find(InsertResult* out, void* self, Entry12* entry);

/* Builds an entry from copies of key and pair and inserts a copy of it into self. */
void func_003CE6C0(void* self, Key* key, KeyPair* pair)
{
    KeyPair pairCopy;
    Entry12 entry;
    Entry12 entryCopy;
    Key keyCopy;
    InsertResult result;
    pairCopy.a = pair->a;
    pairCopy.b = pair->b;
    keyCopy.value = key->value;
    func_003CE730(&entry, &keyCopy, &pairCopy);
    entryCopy.a = entry.a;
    entryCopy.b = entry.b;
    entryCopy.c = entry.c;
    FrameTree_Find(&result, self, &entryCopy);
}
