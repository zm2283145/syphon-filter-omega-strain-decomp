#ifndef POPULATION_H
#define POPULATION_H

/*
 * Population (population.cc): a level's .pop data blob.
 * Population_Load reads "<name>.pop" (falling back to the loose
 * "<root>\<name>\DATA.POP" file, which it then owns), stores the
 * leading int as `count`, and leaves `cursor` just past it.
 * Population_Dtor frees `data` when `ownsData` is set.
 */
typedef struct Population {
    int count;               /* 0x00: first word of the file */
    int size;                /* 0x04: file size in bytes */
    void* data;              /* 0x08: file contents */
    void* cursor;            /* 0x0C: data + 4 after load */
    unsigned char ownsData;  /* 0x10: data was Mem_Alloc'd here */
} Population;

#endif /* POPULATION_H */