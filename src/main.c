#include <ncurses.h>
#include <stdbool.h>

bool running = true;

void init_terminal(void) {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
}

int main(void) {
  init_terminal();

  while (running) {
    int inpCh = getch();
    if (inpCh == 'q') {
      running = false; 
    } else {
      printw("Wrong command!");
      refresh();
    }
  }

  clear();
  endwin();

  return 0;
}
