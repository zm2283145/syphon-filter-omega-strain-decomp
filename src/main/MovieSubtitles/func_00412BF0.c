extern void func_00100740(void* allocation);

/* Empty deleting destructor; the object's concrete type is not yet known. */
void* func_00412BF0(void* self, short deleteFlag) {
    if (self != 0 && deleteFlag > 0) {
        func_00100740(self);
    }
    return self;
}
