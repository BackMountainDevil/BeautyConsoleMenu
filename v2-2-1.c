/*@File    :  v2-2-1.c
  @Desc    :  对 v2-2.c 进行函数封装
  @@Author :  Kearney
  @Contact :  191615342@qq.com
  @version :  0.0.0
  @Time    :	2021/07/16 07:43:08
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
bckgcolor：背景色，数值参考 VT控制码 的颜色问题
fregcolor：前景色
tilcolor：标题颜色
indexcolor：被选中的菜单项的颜色
menu 从零开始计数,无标题的话 index 和 i 上界都要要减一，但我这里默认有标题*/
void ShowMenu(const char **menu, unsigned int size, unsigned int index,
              unsigned int bckgcolor, unsigned int fregcolor,
              unsigned int tilcolor, unsigned int indexcolor) {
  system("clear"); // 清空控制台
  for (unsigned int i = 0; i <= size; i++) {
    if (i == index) { // 被选中的菜单子项
      printf("\033[%d;%dm", bckgcolor, indexcolor);
      printf("\t->%s\n", menu[i]);
      printf("\033[%d;%dm", bckgcolor, fregcolor);
    } else if (i == 0) { // 菜单标题
      printf("\033[%d;%dm", bckgcolor, tilcolor);
      printf("\t  %s\n", menu[i]);
      printf("\033[%d;%dm", bckgcolor, fregcolor);
    } else { // 未选中的菜单子项
      printf("\t  %s\n", menu[i]);
    }
  }
}

/* 初始化背景色和前景色。
设置主要是为了刚开始全终端都是背景色，不设置的话只有一小块是背景色很突兀，
虽然这突兀的情况在用户输入一次后就会消失
bckgcolor：背景色，数值参考 VT控制码 的颜色问题
fregcolor：前景色
 */
void SetColor(unsigned int bckgcolor, unsigned int fregcolor) {
  printf("\033[%d;%dm", bckgcolor, fregcolor);
  printf("\033[2J"); // 清空控制台，和 system("clear"); 效果还是有点区别的
}

/*  取消前面的 VT 控制码设置 */
void ResetColor() { printf("\033[0m"); }

int main() {
  unsigned int index = 1; // 默认选项
  SetColor(47, 30); // 背景色 47-白色，前景色（字体颜色） 30-黑色
  while (1) {
    ShowMenu(menu, 4, index, 47, 30, 32, 34);
    if (GetInput(&index, 1, 4) == ENTER) {
      break;
    }
  }
  ResetColor();
  printf("You option is: %d\n", index);
  return 0;
}