mount 的使用
find 的使用

### Makefile
sort：对一列单词进行排序
realpath: 返回指定路径的绝对路径名
wildcard：返回匹配的文件名列表
basename：返回文件名的基本部分，去掉后缀
notdir：返回指定文件名的非目录部分
filter：从列表中选择符合条件的单词
subst：替换字符串中的子字符串
word：返回指定位置的单词
join：将两个单词序列合并成一个
flavor：返回变量的类型(simple, recursive, append)
findstring：
abspath: 返回指定路径的绝对路径名

MAKECMDGOALS: 指定target
.DEFAULT_GOAL： 指定默认target

export 代表什么
override 代表什么

### Get Pid:
pidof
pgrep

pkill

### gcc:
如何在编译时添加宏
gcc -DDEV

gcc -MMD 生成 .d 文件

如何读取节的内容
objdump -D 

内核栈和用户栈的区别:

异步和同步的区别

一个可执行文件执行的流程

gdb:
  start
  starti
  l
  x/16x $rsp
