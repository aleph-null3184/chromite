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
    clear();
    printw("Chromite Text Editor - v0.0.0.0.1 (this versioning is a joke)\n");
    printw("Press q to exit");
    refresh();

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
