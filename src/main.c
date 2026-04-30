#include <ncurses.h>
#include <stdbool.h>
#include "state.h"

EditorState editor = {0};

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
      continue;
    }

    if (inpCh >= 32 && inpCh <= 126) {
      insert_char(&editor, inpCh);
    }
    
    clear();
    printw("%s", editor.buffer);
    refresh();
  }
  clear(); 
  endwin();

  return 0;
}
