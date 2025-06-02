```makefile
# 像这样在makefile里面使用注释
# 文件名应该为makefile，然后我们可以用 make <target> 这样的命令运行
# 如果名字不为makefile，那我们必须手动指明这个文件 使用 `make -f filename <target>` 指明文件

# 注意: 在makefile文件里面只能使用 TABS 进行缩进，不要使用空格。


#------------------------------------------------------------
# 基本内容
#------------------------------------------------------------

# 创建target的规则(rule)
# target: <prerequisite>
# 这里的 prerequisite 是可选的，可以有多个，也可以一个都没有

# 这个 target 没有 prerequisite，只有当file0.txt不存在时才会执行缩进的内容
file0.txt:
  echo "foo" > file0.txt
  # 缩进内的注释也会被传递给shell
  # 第一个 target 是默认任务，当不给make指明target时会默认执行第一个target
  # 使用 `make file0.txt` 或 `make` 来查看输出

# 只有在file0.txt比file1.txt更新时才会执行这个规则
# This rule will only run if file0.txt is newer the file1.txz
file1.txt: file0.txt
  # 这里和直接在shell里运行一样
  cat file0.txt > file1.txt
  # 加上@可以避免这条命令本身在shell里面被打印出来
  @cat file0.txt >> file1.txt
  # 加上- 表示即使这条命令出了问题make也会继续执行
  -@echo 'hello'
  # 使用 `make file1.txt` 来查看效果

# 一个规则可以有多个targets和prerequisites
file2.txt file3.txt: file0.txt file1.txt
  touch file2.txt
  touch file3.txt
# 对于具有相同target的rule，make在执行时会发出警告，并且会用新的rule会覆盖旧的rule
# 如果另一个rule的recipe是空的，就不会发生覆盖，可以用这种办法为target添加新的prerequisites

#-----------------------------------------------------------------------------------
# Phony Targets
# 伪目标
#-----------------------------------------------------------------------------------

# 任何不是一个文件的target就是伪目标
# 因为不是一个文件，所以每次都会执行他
all: maker process

# target声明的顺序并不重要，比如all依赖的maker，现在才声明
maker:
  touch ex0.txt ex1.txt

# 为防止有文件和伪目标名字相同，我们可以手动使用 .PHONY 来声明一个伪目标
.PHONY: all maker process

# 依赖一个伪目标的规则总是会运行
ex0.txt ex1.txt: maker

# 常见的伪目标有: all make clean install ...

#-----------------------------------------------------------------------------------
# Automatic Variables & Wildcards
# 变量和通配符
#-----------------------------------------------------------------------------------

process: file*.txt # 使用一个通配符来匹配文件名
  @echo $^  # 一个包含prerequisites名字的列表
  @echo $@  # target 名字，如果target有多个，$@代表当前正在执行的那个
  @echo $<  # 列出的第一个prerequisite的名字
  @echo $?  # 需要更新的 prerequisite 的文件列表
  @echo $+  # 所有依赖，包括重复的
  @echo $|

# 即使我们给 process 添加了新的依赖，$^ 也可以找到他们
# ex1.txt会被添加进 $^，file0.txt会被自动去重
process: ex1.txt file0.txt

#-----------------------------------------------------------------------------------
# Patterns
# 模式
#-----------------------------------------------------------------------------------

# 告诉make如何将这种文件转换成其他格式

%.png: %.svg:
  inkscape --export-png $^

# 一旦有需要foo.png 这个rule就会运行，将foo.svg转换成foo.png

当匹配pattern rule时路径一般会忽略，但是如果可以匹配上路径，就会优先选择带有路径的 rule

small/%.png: %.svg
  # 使用 make small/foo.png 会匹配上这个rule，而不是 `%.png: %.svg` 那个
  inkscape --export-png --export-dpi 30 %^

# make会使用最新的 pattern rule，即下面的会覆盖上面的
%.png: %.svg
  @echo this rule is chosen

# 当有多个 pattern rule 可以满足这个target时，会优先选择第一个 pattern rule
%.png: %.ps
  @echo this rule is not chosen if *.svg and *.ps are both present

# make 已经有了一些内置的 pattern rules，比如，他知道该怎么把.c文件转换成.o文件


#-----------------------------------------------------------------------------------
# Variables
# 变量
#-----------------------------------------------------------------------------------
# 实际上是宏

# 变量基本上全是String类型

name = Ted
name2 = "Sarah"

echo:
  @echo $(name)
  @echo ${name2}
  @echo $name # 注意，这里会被看作是 $n 的值，拼接上ame
  @echo $(name3) # 变量不存在，被看成是空字符串

# 有四种办法可以设置变量
# 按优先级从低到高的顺序
# 1: 命令行参数 如`make echo name3=Lucy`
# 2: Makefile
# 3: shell环境变量，make会自动导入
# 4: make内置变量

name4 = Jean
# 如果name4设置过了，就不设置了

override name5 = David
# 阻止命令行参数改变这个变量

name4 +=grey
# 在这个变量后面拼接值(包括空格)

# 在依赖的地方设置变量
echo: name2 = Sara

# 一些make自动设置的变量
echo_inbuilt:
	echo $(CC)
	echo $(CXX)
	echo $(FC)
	echo ${CFLAGS}
	echo $(CPPFLAGS)
	echo $(CXXFLAGS)
	echo $(LDFLAGS)
	echo $(LDLIBS)


#-----------------------------------------------------------------------------------
# Variables 2
# 变量2
#-----------------------------------------------------------------------------------

# 使用等号(=)赋值的变量在每次用到的时候都会进行求值，使用(:=)复制的变量只有在定义的时候会进行一次求值
#  = 声明为 recursively expanded 递归扩展
# := 声明为 Simply expanded variables 即时扩展变量，只在声明的时候扩展一次

var := hello
var2 ::= $(var) hello
# := 和 ::= 等价

# 当引用var3时$(var4)会被认为是空，因为定义var3的时候var4还未声明
var3 ::= $(var4) and good luck
var4 ::= good night

#-----------------------------------------------------------------------------------
# Functions
# 函数
#-----------------------------------------------------------------------------------

# make 提供了大量的函数

# wildcard 会将通配符变成一串文件路径
sourcefiles = $(wildcard *.c */*.c)
# patsubst 可以做替换
objectfiles = $(patsubst %.c,%.o,$(sourcefiles))

# 调用函数的格式为: $(func arg0,arg1,arg2...)

# 一些例子
ls: * src/*
  @echo $(filter %.txt, $^)
  @echo $(notdir $^)
  @echo $(join $(dir $^),$(notdir $^))

#-----------------------------------------------------------------------------------
# Directives
# 指令
#-----------------------------------------------------------------------------------

# 导入其他makefile，对于平台指定代码很有用，指令需要顶格写
include foo.mk

sport = tennis
# 条件编译
report:
ifeq ($(sport),tennis)
  @echo 'game, set, match'
else
  @echo "They think it's all over; it is now"
endif

# 还有 ifneq, ifdef, ifndef 这些指令

foo = true
ifdef $(foo)
bar = 'hello'
endif

```
