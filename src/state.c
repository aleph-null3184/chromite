#include "state.h"

void insert_char(EditorState *editor, char inpCh) {
  if (editor->len >= BUFFER_SIZE - 1) {
    return; 
  }

  editor->buffer[editor->len] = inpCh;
  editor->len++;
  editor->buffer[editor->len] = '\0';
}
