#include <ncurses.h>
#include <stdbool.h>
#include <locale.h>
#include "state.h"
#include "keys.h"

EditorState editor = {0};

// this whole function initializes the terminal
void init_terminal(void) {
  setlocale(LC_ALL, "");
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
    } else if (inpCh == BACKSPACE || inpCh == BACKSPACE_1 || inpCh == KEY_BACKSPACE) {
      remove_char_before_cursor(&editor);
    } else if (inpCh >= SPACE && inpCh <= TILDE) {
      insert_char_at_cursor(&editor, inpCh);
    } else if (inpCh == ENTER) {
      insert_char(&editor, '\n');
    } else if (inpCh == KEY_LEFT) {
      move_cursor_left(&editor);
    } else if (inpCh == KEY_RIGHT) {
      move_cursor_right(&editor);
    }
    
    clear();
    printw("%s", editor.buffer);
    refresh();
  }
  clear(); 
  endwin();

  return 0;
}
