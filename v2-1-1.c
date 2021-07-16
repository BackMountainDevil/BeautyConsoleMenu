/*@File    :  v2-1-1.c
  @Desc    :  对 v2-1.c 进行函数封装，使得修改菜单更容易便捷
  @@Author :  Kearney
  @Contact :  191615342@qq.com
  @version :  0.0.0
  @Time    :	2021/07/15 20:40:30
  @License :  MIT
  @Encoding:  UTF-8  */
#include <stdio.h>
#include <stdlib.h>
// 菜单
const char *menu[] = {"MENU SELECTION DEMO", "1. Option 1", "2. Option 2",
                      "3. Option 3", "4. Exit"};

// 可操作的按键
enum {
  UP = 119,   // W
  DOWN = 115, // S
  ENTER = 10, // Enter
};

/* 获取用户输入的 ASCII。
index: 菜单项对应的变量的地址
start：菜单项的最小值
end： 菜单项的最大值 */
int GetInput(unsigned int *index, unsigned int start, unsigned int end) {
  system("stty -icanon"); // 关闭缓冲区，输入字符无需按回车键
  char command;
  command = getchar();
  system("stty icanon"); // 恢复规范输入
  switch (command) {
  case UP:
    if (*index > start)
      *index -= 1;
    break;
  case DOWN:
    if (*index < end)
      *index += 1;
    break;
  case ENTER:
    return ENTER;
  }
  return command;
}

/* 显示用户菜单。
menu：菜单标题和菜单子项
size：菜单子项的数量
index：当前被选中的菜单项
menu 从零开始计数,无标题的话 index 和 i 上界都要要减一，但我这里默认有标题*/
void ShowMenu(const char **menu, unsigned int size, unsigned int index) {
  system("clear"); // 清空控制台
  for (unsigned int i = 0; i <= size; i++) {
    if (i == index) {
      printf("\t->%s\n", menu[i]);
    } else {
      printf("\t  %s\n", menu[i]);
    }
  }
}

int main() {
  unsigned int index = 1; // 默认选项
  while (1) {
    ShowMenu(menu, 4, index);
    if (GetInput(&index, 1, 4) == ENTER) {
      break;
    }
  }
  printf("You option is: %d\n", index);
  return 0;
}