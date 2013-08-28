stealth
=======

`stealth` is a [Loadable Kernel Module](http://en.wikipedia.org/wiki/Loadable_kernel_module) targetted at the Linux Kernel, versions 3.0 and up. Its goal is to hide processes, amongst other stealthy things. It comes with a companion `libstealth` to which you can link and enables a program to talk to `stealth` through an API.

Note: `libstealth` is not done yet.

FAQ
===

Why?
----

I wanted to learn more about LKMs and this sounded like a fun project to work on.

Is it production-ready?
-----------------------

No. This is a personal research project whose primary focus is technological amusement. 

Is it easily detectable?
------------------------

At this point in time, it's trivial to detect `stealth`'s presence. This is something that I intend to change, and it should not be easy to detect the module even as root. (Defending against another kernel module is not within the scope of this project)

Demo
====

Here is a short [demo](http://showterm.io/0d7897816b2372a5043d3) of what `stealth` can do.
