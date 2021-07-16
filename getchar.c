/*@File    :  getchar.c
  @Desc    :  Linux 下 getchar 的一个使用和部分输出结果，取消 system
              的注释可以不用回车
  @@Author :  Kearney
  @Contact :  191615342@qq.com
  @version :  0.0.0
  @Time    :	2021/07/15 15:07:24
  @License :  MIT
  @Encoding:  UTF-8  */
#include <stdio.h>
#include <stdlib.h>

int main() {
  char option;
  printf("please input keyboard num\n");
  // system("stty -icanon"); //关闭缓冲区，输入字符无需按回车键
  while (1) {
    option = getchar();
    printf("You input is: %c <-> %d\n", option, option);
  }
  // system("stty icanon"); // 恢复规范输入
  return 0;
}

/*
please input keyboard num
0
You input is: 0 <-> 48
You input is:
 <-> 10
1
You input is: 1 <-> 49
You input is:
 <-> 10
8
You input is: 8 <-> 56
You input is:
 <-> 10
9
You input is: 9 <-> 57
You input is:
 <-> 10
a
You input is: a <-> 97
You input is:
 <-> 10
b
You input is: b <-> 98
You input is:
 <-> 10
y
You input is: y <-> 121
You input is:
 <-> 10
z
You input is: z <-> 122
You input is:
 <-> 10
 A
You input is: A <-> 65
You input is:
 <-> 10
B
You input is: B <-> 66
You input is:
 <-> 10
C
You input is: C <-> 67
You input is:
 <-> 10
D
You input is: D <-> 68
You input is:
 <-> 10
//  上，显示为 ^[[A
^[[A
You input is: -> 27
You input is: [ <-> 91
You input is: A <-> 65
You input is:
 <-> 10
//  下，显示为 ^[[B
^[[B
You input is: -> 27
You input is: [ <-> 91
You input is: B <-> 66
You input is:
 <-> 10
//  左，显示为 ^[[D
^[[D
You input is: -> 27
You input is: [ <-> 91
You input is: D <-> 68
You input is:
 <-> 10
//  右，显示为 ^[[C
^[[C
You input is: -> 27
You input is: [ <-> 91
You input is: C <-> 67
You input is:
 <-> 10
// 回车，啥也没显示

You input is:
 <-> 10
// Esc 退出，显示为  ^[
^[
You input is: -> 27
You input is:
 <-> 10
 */