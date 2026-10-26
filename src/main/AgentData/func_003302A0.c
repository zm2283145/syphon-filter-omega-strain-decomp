typedef struct { int idx; int hash; } Col;
typedef struct { int a; int count; Col *data; char owns; } ColVec;
typedef struct { char name[16]; int val; } Ent;
typedef struct { int a; int count; Ent *data; } EntVec;
typedef struct { int d[0x2A]; } FEnt;
extern EntVec D_00532B30;
extern char D_004B9280[];
extern void *Resource_Construct(void *);
extern void *FileMan_Release(void *, int);
extern void Hog_Register(void *, const char *, int, int);
extern int FileMan_FindMember(void *);
extern char *FileMan_ReadData(void *);
extern int FileMan_GetSize(void *);
extern ColVec *std_vector_tColumnData_ctor(ColVec *);
extern void func_0033A580(ColVec *);
extern void std_vector_deleter_tColumnData_dtor(ColVec *, int);
extern void std_vector_imp_tColumnData_insert(ColVec *, Col *, int, Col *);
extern void PartsTable_InsertRow(EntVec *, Ent *, int, Ent *);
extern int atoi(const char *);
extern int strlen(const char *);
extern char *strncpy(char *, const char *, int);
#pragma opt_strength_reduction off
void PartsTable_Load(int arg)
{
    Col col;
    FEnt f;
    ColVec v;
    char line[0x200];
    Ent ent;
    unsigned char first;
    char *p;
    int left;
    int len;
    int i;
    int j;
    char *s;
    char *q;
    Resource_Construct(&f);
    Hog_Register(&f, D_004B9280, arg, 0);
    if (!(FileMan_FindMember(&f) & 0xFF)) {
        p = FileMan_ReadData(&f);
        left = FileMan_GetSize(&f);
        first = 1;
        std_vector_tColumnData_ctor(&v);
        v.owns = 1;
        while (left > 0) {
            q = line;
            while (left > 0 && *p != '\r') {
                *q++ = *p++;
                left--;
            }
            *q = 0;
            p += 2;
            left -= 2;
            len = strlen(line);
            if (len == 0) {
                first = 1;
                func_0033A580(&v);
            } else if (first) {
                first = 0;
                {
                int *hp = &col.hash;
                Col **pd = &v.data;
                for (i = 0; i < len; i++) {
                    s = &line[i];
                    if (*s != ' ') {
                        *hp = atoi(s);
                        col.idx = i;
                        std_vector_imp_tColumnData_insert(&v, *pd + v.count, 1, &col);
                        while (i < len && *s != ' ') {
                            s++;
                            i++;
                        }
                    }
                }
                }
            } else {
                for (j = 0; j < v.count; j++) {
                    int c = v.data[j].idx;
                    if (c < len) {
                        char *b = &line[c];
                        char *e = b;
                        if (*b != ' ') {
                            int n;
                            while (*e != ' ' && *e != '\r' && *e != 0) e++;
                            n = e - b;
                            strncpy(ent.name, b, n);
                            ent.name[n] = 0;
                            ent.val = v.data[j].hash;
                            PartsTable_InsertRow(&D_00532B30, D_00532B30.data + D_00532B30.count, 1, &ent);
                        }
                    }
                }
            }
        }

        std_vector_deleter_tColumnData_dtor(&v, 0);
    }
    FileMan_Release(&f, -1);
}



