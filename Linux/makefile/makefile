file0.txt:
	echo "foo" > file0.txt

file1.txt: file0.txt
	cat file0.txt > file1.txt
	@cat file0.txt >> file1.txt
	-@echo "hello"

file2.txt file3.txt: file0.txt file1.txt
	touch file2.txt
	touch file3.txt

all: maker process

maker:
	touch ex0.txt ex1.txt

.PHONY: all maker process

ex0.txt ex1.txt: maker

process: file*.txt
	@echo $^ # prerequisites 的列表
	@echo $@ # target 的名字
	@echo $< # 第一个 prerequisite 
	@echo $? # 旧的依赖
	@echo $+ # 全部 依赖 包括副本 duplicate，即 下面process的 prerequisites
	@echo $/

# 使用 make process $^ 会包含ex1.txt
process: ex1.txt file0.txt

# ------------------------------------------------------------
# 模式
# ------------------------------------------------------------

# 告诉 make 如何将一个确切的文件转换成另一种文件
# %.png: %.svg
# 	inkscape --export-png $^

# small/%.png: %.svg
# 	inkscape --export-png -export-dpi 30 $^

# %.png: %.ps
# 	@echo this rule is not chosen if *.svg and *.ps are both present

# 当第一个 rule 可以满足这个target的时候，make会选择第一个pattern

name = Ted
name2 = "Sarah"

echo:
	@echo $(name)
	@echo ${name}
	@echo $name
	@echo $(name3)

name4 ?= Jean

override name5 = David

name4 +=grey

echo_inbuilt:
	echo $(CC)
	echo $(CXX)
	echo $(FC)
	echo ${CFLAGS}
	echo $(CPPFLAGS)
	echo $(CXXFLAGS)
	echo $(LDFLAGS)
	echo $(LDLIBS)

var := hello
var2 ::= $(var) hello

ls: *.c *.txt
	@echo $(filter %.txt, $^)
	@echo $(notdir $^)
	@echo $(dir $^)
	@echo $(join $(dir $^), $(notdir $^))

all_txt:
	@echo $(wildcard *.txt)

substitude: *
	@echo $(patsubst %.txt, %.asd, $* $^)
