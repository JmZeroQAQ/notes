fc-match -s xxx
查看字体匹配是什么

fdisk -l
查看系统分区信息

fdisk 也是很好用的分区工具

df -h
查看已挂载设备

U盘速度测试
W:
dd if=/dev/zero of=./test.iso bs=1024M count=1 conv=fdatasync
R:
dd if=./test.iso of=/dev/null bs=1024M count=1 iflag=direct

查看块设备
lsblk
