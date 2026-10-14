typedef struct G4Node { int a; struct G4Node* next; int b, c; int id; } G4Node;
typedef struct { G4Node* head; int x, y; } G4List;
extern G4List D_004908D8;G4Node* func_002F7D68(int id)
{
    G4Node* p = D_004908D8.head;
    if (p != 0 && p->id != id) {
        G4Node* head = p;
        p = p->next;
        while (1) {
            if (p == head) p = 0;
            if (p == 0 || p->id == id) break;
            p = p->next;
        }
    }
    return p;
}