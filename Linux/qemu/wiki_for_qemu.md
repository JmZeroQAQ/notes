QEMU 是什么:
QEME 可以作为模拟器和虚拟机

当作为模拟器时，可以在一种架构(如x86 PC) 下运行另一种架构(如ARM)下的操作系统和程序。

当作为虚拟机时，QEMU 可以使用其他虚拟机管理程序(如XEN或KVM),来使用CPU扩展(HVM)进行虚拟化，通过在宿主机CPU上执行客户机代码来获得近似于宿主机的性能。

**Hypervisor**，又称虚拟机监控器，虚拟机管理程序(virtual machine monitor，缩写为VMM)。
什么是虚拟机管理程序:
在虚拟机管理程序出现之前，大多数物理计算机一次只能运行一个操作系统，不能充分的利用计算机的所有能力，虚拟机管理程序可以解决这个问题。
它可以使多个操作系统实例同时运行，共享相同的物理计算资源。这些运行的操作系统实例就叫虚拟机。

虚拟机管理程序的作用是什么:
它可以为并行运行的虚拟机进行管理。它将虚拟机在逻辑上相互分离，为每个虚拟机分配独立CPU核心，内存，和磁盘空间(虚拟化)。

虚拟机管理程序分为两类:
第一类虚拟机管理程序直接在底层计算机的物理硬件上运行(裸机虚拟机管理程序)。
第二类虚拟机管理程序不在底层硬件上执行，它是作为操作系统中的应用程序运行。

VMware Workstation 和 VirtualBox 属于第二类虚拟机管理程序

什么是KVM:

KVM 全称是 基于内核的虚拟机(Kernel-based Virtual Machine)
是Linux内核的一个模块，这个模块让Linux内核变成了一个虚拟机管理程序，属于第一类虚拟机管理程序。

如何安装QEMU:
Arch: sudo pacman -S qemu-full

QEMU有两种运行模式分别是：全系统模拟模式(full-system emulation)和用户模式(Usermode emulation)



Keys:
退出Qemu: Ctrl-a x
打开Monitor: Ctrl-a c

参考:
[Arch Wiki](https://wiki.archlinuxcn.org/wiki/QEMU)
[IBM 什么是虚拟机管理程序](https://www.ibm.com/cn-zh/topics/hypervisors)
[维基百科 Hypervisor](https://zh.wikipedia.org/wiki/Hypervisor)
[Keys in the character backend multiplexer](https://www.qemu.org/docs/master/system/mux-chardev.html)
