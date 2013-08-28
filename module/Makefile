stealth-objs := module.o processes.o api.o
obj-m := stealth.o

KERNEL := /lib/modules/$(shell uname -r)/build

all:
	make -C $(KERNEL) M=$(PWD) modules

clean:
	make -C $(KERNEL) M=$(PWD) clean
