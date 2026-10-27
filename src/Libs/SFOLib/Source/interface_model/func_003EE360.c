typedef struct { float x, y, z, w; } Vec4;
typedef struct Node {
    char pad00[0x6E];
    unsigned short count;
    char pad70[0x14];
    struct Node** children;
    char pad88[4];
    int hidden;
    char pad90[0x10];
    Vec4 color;
} Node;
int std_list_imp_voidPtr_size(void* obj);
int cInterfaceModel_IsInstanced(Node* self);
int func_003EE5E0(Node* self, Vec4* v);
void cInterfaceModel_FilterChildren(Node* self, Vec4* v)
{
    int i;
    for (i = 0; i < self->count; i++) {
        Node* c = self->children[i];
        if (c->hidden <= 0) {
            int j;
            c->color.x = v->x;
            c->color.y = v->y;
            c->color.z = v->z;
            c->color.w = v->w;
            for (j = 0; j < c->count; j++) {
                if (std_list_imp_voidPtr_size(&c->children[j]->hidden) <= 0) {
                    Node* d = c->children[j];
                    int k;
                    d->color.x = v->x;
                    d->color.y = v->y;
                    d->color.z = v->z;
                    d->color.w = v->w;
                    for (k = 0; k < d->count; k++) {
                        if (cInterfaceModel_IsInstanced(d->children[k]) == 0)
                            func_003EE5E0(d->children[k], v);
                    }
                }
            }
        }
    }
}
