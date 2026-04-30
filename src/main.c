#include <ncurses.h>
#include <stdbool.h>

// this whole function initializes the terminal
void init_terminal(void) {
  initscr(); /* Initializes ncurses */
  cbreak();  /* Disables line buffering (instant input) */
  noecho();  /* Disable automatic echoing of characters */
  keypad(stdscr, TRUE); /* Enables special keys (e.g. arrow keys, home key, end key, etc.) */
}

int main(void) {
  init_terminal(); 

  // a bool to check if the editor is running or not
  bool running = true; 

  while (running) {
    int inpCh = getch(); // whatever char you enter is stored here
    if (inpCh == 'q') { // if the char you entered is 'q'
      running = false;  // then change running from true to false (hence, exiting)
    } else {            // if not q
      clear();          // clear screen
      printw("Wrong command!"); // print this
      refresh(); // then refresh
    }
  }

  clear(); // clear screen
  endwin(); // endwin()

  return 0;
}
