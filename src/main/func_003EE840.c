#pragma cplusplus on
#pragma inline_depth(10)
struct Node { char pad[0x6E]; unsigned short count; char p70[0x84 - 0x70]; Node** kids; };
extern "C" {
int String_AssignCStr_1C43A0(void* s, const char* name);
int func_003EEAC0(void* s, const char* name);
int func_003EEAF0(void* s, const char* name);
void* func_003EEB20(void* s);
Node* func_003EE840(Node* n, const char* name);
}
static inline Node* F3(Node* n, const char* name) {
    int i;
    if (func_003EEAC0(func_003EEB20(n), name)) return n;
    for (i = 0; i < n->count; i++) {
        Node* r = func_003EE840(n->kids[i], name);
        if (r) return r;
    }
    return 0;
}
static inline Node* F2(Node* n, const char* name) {
    int i;
    if (func_003EEAF0(func_003EEB20(n), name)) return n;
    for (i = 0; i < n->count; i++) {
        Node* r = F3(n->kids[i], name);
        if (r) return r;
    }
    return 0;
}
static inline Node* F1(Node* n, const char* name) {
    int i;
    if (String_AssignCStr_1C43A0(n, name) == 0) return n;
    for (i = 0; i < n->count; i++) {
        Node* r = F2(n->kids[i], name);
        if (r) return r;
    }
    return 0;
}
extern "C" Node* func_003EE840(Node* n, const char* name) {
    int i;
    if (String_AssignCStr_1C43A0(n, name) == 0) return n;
    for (i = 0; i < n->count; i++) {
        Node* r = F1(n->kids[i], name);
        if (r) return r;
    }
    return 0;
}

