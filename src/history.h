#ifndef _HISTORY_H
#define _HISTORY_H

typedef struct history_node_s {
  int id;
  char *str;
  struct s_Item *next;
} history_node;

/* Initialize the linked list to keep the history. */
history_node *init_history();

/* Add a history item to the end of the list.
   history_node* list - the linked list
   char* str - the string to store
*/
void add_history(history_node *list, char *str);

/* Retrieve the string stored in the node where Item->id == id.
   history_node* list - the linked list
   int id - the id of the Item to find */
char *get_history(history_node *list, int id);

/* Print the entire contents of the list. */
void print_history(history_node *list);

/* Free the history list and the strings it references. */
void free_history(history_node *list);

#endif
