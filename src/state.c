#include "state.h"

void insert_char(EditorState *editor, char inpCh) {
  if (editor->len >= BUFFER_SIZE - 1) {
    return; 
  }

  editor->buffer[editor->len] = inpCh;
  editor->len++;
  editor->buffer[editor->len] = '\0';
}

void remove_char_before_cursor(EditorState *editor) {
  if (editor->cursor == 0) {
    return;  
  }

  for (int i = editor->cursor; i < editor->len; i++) {
    editor->buffer[i - 1] = editor->buffer[i - 1];
  }

  editor->cursor--;
  editor->len--;
  editor->buffer[editor->len] = '\0';
}

void insert_char_at_cursor(EditorState *editor, char inpCh) {
  if (editor->len >= BUFFER_SIZE - 1) {
    return;
  }

  if (editor->cursor < 0 || editor->cursor > editor->len) {
    return; 
  }

  for (int i = editor->len; i > editor->cursor; i--) {
    editor->buffer[i] = editor->buffer[i - 1]; 
  }

  editor->buffer[editor->cursor] = inpCh;
  
  editor->cursor++;
  editor->len++;
  
  editor->buffer[editor->len] = '\0';
}

void move_cursor_left(EditorState *editor) {
  if (editor->cursor > 0) {
    editor->cursor--;
  }
}

void move_cursor_right(EditorState *editor) {
  if (editor->cursor < 0) {
    editor->cursor++;
  }
}
