#ifndef _list
#define _list

#include "proc.h"

typedef struct node_list {
  struct pcb *data;
  struct node_list *next;
  struct node_list *prev;
} node_list;

typedef struct list_t {
  long length;
  struct node_list *head;
  struct node_list *tail;
} list_t;

void list_initialize(list_t *list);

void list_destroy(list_t *list);

node_list *list_insert(list_t *list, struct pcb *elem);

void list_append(list_t *list, struct pcb *elem);

long list_length(list_t *list);

long list_empty(list_t *l);

void list_head(list_t *list, struct pcb **elem);

void list_tail(list_t *list, void **elem);

void list_rem_head(list_t *l);

void list_rem_tail(list_t *l);

void list_rem_head_data(list_t *l);

void list_rem_tail_data(list_t *l);

void list_rem_elem(list_t *l, struct pcb *elem);


#endif
