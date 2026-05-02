#ifndef STATE_H
#define STATE_H

#define BUFFER_SIZE 1024

typedef struct {
  char buffer[BUFFER_SIZE];
  int len;

  int cursor;
} EditorState;

// insert a character
void insert_char(EditorState *editor, char inpCh);

// delete char before cursor (backspace)
void remove_char_before_cursor(EditorState *editor);

// insert a char at cursor position
void insert_char_at_cursor(EditorState *editor, char inpCh);

// move cursor to the left
void move_cursor_left(EditorState *editor);

// move cursor to the right
void move_cursor_right(EditorState *editor);

// move cursor up (THIS WILL BE IMPLEMENTED LATER)
// void move_cursor_up(EditorState *editor);

// move cursor down (THIS WILL ALSO BE IMPLEMENTED LATER)
// void move_cursor_down(EditorState *editor);


#endif 
