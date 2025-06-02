 ### 编写你自己的makefile

对于初次接触编写多个c/cpp源文件的程序员来说，困难的也许不是如何写代码，而是怎么样把编写好的代码编译起来。
有人会说，我直接`gcc -o main *.c`不就行了？这样确实可以，不过代价就是修改一次代码，你需要把所有源文件都给
重新编译一下，对于源文件数量不多的情况我们还可以接受，但是当源文件数量一多，每次编译都会耗费我们大把时间，而
且这么做还有一个问题就是，我们的项目结构不可能只有一层，肯定是多层的，比如:


```
c_project
├── include
│   ├── b.h
│   ├── c.h
│   ├── d.h
│   ├── e.h
│   └── f.h
└── src
    ├── d1
    │   ├── a.c
    │   ├── b.c
    │   └── c.c
    ├── d2
    │   ├── d.c
    │   └── e.c
    ├── d3
    └── d4
        ├── f.c
        └── g.c
```

这个时候`gcc -o main *.c`就无能为力了。那现在我们该怎们办，总不能单个单个编译，然后再链接到一起吧，嗨
，你别说，还真是这样，但是这个过程不是由我们手动完成，而是交给make来完成。make读取Makefile来实现我们的编译
要求，而这个Makefile需要我们自己编写。有些人看到Makefile的第一感觉就是：~~我艹，这确定不是让我学门新语言吗?~~
事实上：~~确实和学习一门新语言有点像~~，不过不要害怕，Makefile的语法很简单，我们看不懂别人写的Makefile只是我
们没有掌握方法，不知道别人的Makefile要做的是什么事情。所以，让我们回到我们使用make的原因：以一种优雅的方式来
编译我们的项目。既然是编译，那Makefile要做的事情无非就是以下3个:


1.找到所有的.c源文件
2.将所有的.c源文件编译成.o可重定向文件
3.将这些可重定向文件链接成可执行文件

```Makefile
## 找到所有.c源文件
NAME := main
SRCS := $(shell find -L ./src/ -name "*.c")

WORK_DIR = $(shell pwd)
DST_DIR  = $(WORK_DIR)/build
$(shell mkdir -p $(DST_DIR))

## 将所有的.c源文件编译成.o可重定向文件
$(DST_DIR)/%.o: %.c
	@mkdir -p $(dir $@) && echo + CC $<
	@gcc -std=gnu11 -c -o $@ $(realpath $<)

## 将这些可重定向文件链接成可执行文件
build: build-dep
	@gcc -o $(DST_DIR)/$(NAME) $(OBJS)
build-dep: $(OBJS)
.PHONY: build build-dep
```