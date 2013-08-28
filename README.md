stealth
=======

`stealth` is a [Loadable Kernel Module](http://en.wikipedia.org/wiki/Loadable_kernel_module) targetted at the Linux Kernel, versions 3.0 and up. Its goal is to hide processes, amongst other stealthy things. It comes with a companion `libstealth` to which you can link and enables a program to talk to `stealth` programatically.

Note: `libstealth` is not done yet.

FAQ
===

1. Why?

I wanted to learn more about LKMs and this sounded like a fun project to work on.

2. Is it production-ready?

No. This is a personal research project whose primary focus is technological amusement. 

3. Is it easily detectable? 

At this point in time, it's trivial to detect `stealth`'s presence. This is something that I intend to change, and it should not be easy to detect the module even as root. (Defending against another kernel module is not within the scope of this project)
