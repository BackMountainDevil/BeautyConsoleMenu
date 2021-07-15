/*@File    :  v2-1.c
  @Desc    :  一个可以使用 w/s 进行上下选择、回车确认的菜单
  @@Author :  Kearney
  @Contact :  191615342@qq.com
  @version :  0.0.0
  @Time    :	2021/07/15 15:40:57
  @License :  MIT
  @Encoding:  UTF-8  */
#include <stdio.h>
#include <stdlib.h>

int main() {
  char command;
  int index = 1; // 默认选项

  system("stty -icanon"); //关闭缓冲区，输入字符无需按回车键直接接受
  while (1) {
    system("clear"); // 清空控制台

    // 输出菜单项供用户参考
    printf("|   MENU SELECTION DEMO    |\n");
    printf("| Options:                 |\n");
    if (index == 1) {
      printf("|    --> 1. Option 1       |\n");
    } else {
      printf("|        1. Option 1       |\n");
    }
    if (index == 2) {
      printf("|    --> 2. Option 2       |\n");
    } else {
      printf("|        2. Option 2       |\n");
    }
    if (index == 3) {
      printf("|    --> 3. Option 3       |\n");
    } else {
      printf("|        3. Option 3       |\n");
    }
    if (index == 4) {
      printf("|    --> 4. Exit           |\n");
    } else {
      printf("|        4. Exit           |\n");
    }
    // 让用户进行选择
    command = getchar();
    if (command == 10) { //  enter 10
      break;
    } else if (command == 119) { //  w 119
      if (index > 1) {
        index--;
      }
    } else if (command == 115) { // s 115
      if (index < 4) {
        index++;
      }
    }
  }
  printf("You option is: %d\n", index);
  return 0;
}