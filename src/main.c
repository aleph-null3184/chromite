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
    int inpCh = getch(); 
    if (inpCh == 'q') { 
      running = false;  
    }
    clear();
    printw("Chromite - Text Editor");
    printw("Press q to exit");
    refresh();
  }

  clear(); 
  endwin(); 

  return 0;
}
