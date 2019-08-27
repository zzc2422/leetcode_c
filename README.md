# leetcode_c
leetcode一些题目的C语言解答

项目由头文件和一系列.c文件组成。
头文件包含include_all.h文件和include文件夹。include_all.h里面#include了大部分常用头文件，所有C文件中也都#include了此头文件。而include文件夹中有些在题目中经常出现的自定义结构，例如list、tree等。
重头戏是这些.c文件，每一个文件对应leetcode中一道题目，文件则直接由题目的名字命名。例如https://leetcode-cn.com/problems/gas-station 这道题，题目名字就叫gas-station（网址的最后一部分），于是此题目的代码也在gas-station.c文件中。
当一道题通过测试且性能达到预期时，将在git中commit，注释为“测试通过，性能达标”。若commit的注释为其它内容，则说明此题目还未完成。
