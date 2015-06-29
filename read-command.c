// UCLA CS 111 Lab 1 command reading

#include "command.h"
#include "command-internals.h"
#include "alloc.h"

#include <ctype.h>  //For isalpha() and isdigit() functions
#include <stdlib.h>
#include <stdio.h>  //For EOF
#include <error.h>
#include <string.h>
#define STACK_MAX 100


struct Stack
{
  command_t data[STACK_MAX];
  int size;
};


void Stack_Init(struct Stack *S)
{
  S->size = 0;
}


command_t Stack_Top(struct Stack *S)
{
  if (S->size == 0) {
    fprintf(stderr, "Error: stack empty\n");
    exit(0);
  } 

  return S->data[S->size-1];
}


void Stack_Push(struct Stack *S, command_t c)
{
  if (S->size < STACK_MAX){
    S->data[S->size] = c;
    S->size++;
  }
        
  else
    fprintf(stderr, "Error: stack full\n");
}


void Stack_Pop(struct Stack *S)
{
  if (S->size == 0)
    fprintf(stderr, "Error: stack empty\n");
  else
    S->size--;
}

/* FIXME: You may need to add #include directives, macro definitions,
   static function definitions, etc.  */

/* FIXME: Define the type 'struct command_stream' here.  This should
   complete the incomplete type declaration in command.h.  */

command_stream_t
make_command_stream (int (*get_next_byte) (void *),
		     void *get_next_byte_argument)
{
  /* FIXME: Replace this with your implementation.  You may need to
     add auxiliary functions and otherwise modify the source code.
     You can also use external functions defined in the GNU C Library.  */
  error (1, 0, "command reading not yet implemented");
  return 0;
}


command_t
read_command_stream (command_stream_t s)
{
  if(s != NULL && s->read == 0){
    command_t tree;
    tree = s->root;
    s->read++;
    return tree;
  }

  else if(s != NULL && s->next != NULL){
    return read_command_stream(s->next);
  }

  else{
    return NULL;
  }
}
