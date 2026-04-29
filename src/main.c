#include <ncurses.h>
#include <stdbool.h>

void init_terminal(void) {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
}

int main(void) {
  init_terminal();

  bool running = true; 

  while (running) {
    int inpCh = getch();
    if (inpCh == 'q') {
      running = false; 
    } else {
      clear();
      printw("Wrong command!");
      refresh();
    }
  }

  clear();
  endwin();

  return 0;
}
