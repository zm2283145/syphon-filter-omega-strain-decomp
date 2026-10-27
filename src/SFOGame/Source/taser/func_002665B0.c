#pragma cplusplus on
extern "C" void operator_delete(void* allocation);
struct TreeNode2;
struct TreeHolder { int head; int header; TreeNode2* first; };
extern "C" void std_list_deleter_TaserPulse_erase_listdeleter_listdeleter(TreeNode2** result, TreeHolder* self, TreeNode2** first, TreeNode2** last);
extern "C" TreeHolder* std_list_TaserPulse_dtor(TreeHolder* self, short deleteFlag) {
    if (self) {
        if (self) {
            if (self) {
                TreeNode2* result;
                TreeNode2* first;
                TreeNode2* last;
                last = (TreeNode2*)&self->header;
                first = self->first;
                std_list_deleter_TaserPulse_erase_listdeleter_listdeleter(&result, self, &first, &last);
            }
        }
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}