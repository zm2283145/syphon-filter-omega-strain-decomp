extern void operator_delete(void* allocation);

/* Empty deleting destructor; the object's concrete type is not yet known. */
void* func_00412BF0(void* self, short deleteFlag) {
    if (self != 0 && deleteFlag > 0) {
        operator_delete(self);
    }
    return self;
}
