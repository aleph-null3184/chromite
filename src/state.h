#ifndef STATE_H
#define STATE_H

#define BUFFER_SIZE 1024

typedef struct {
  char buffer[BUFFER_SIZE];
  int len;
} EditorState;

void insert_char(EditorState *editor, char inpCh);

#endif 
