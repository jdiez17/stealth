#ifndef API_H
#define API_H

#include <linux/seq_file.h>

#include "module.h"

ssize_t stealth_api_write(struct file*, const char __user*, size_t, loff_t*);

int stealth_api_open(struct inode*, struct file*);
int stealth_api_init(void);
int stealth_api_deinit(void);

#endif 
