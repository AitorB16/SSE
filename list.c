#include "list.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/*
 * Initializes a generic list.
 * @input l: Pointer to a struct list_t.
 * @input t_size: Siseof of the data to be stored.
 */
void list_initialize(list_t *l)
{
    l->length = 0;
    l->head = NULL;
    l->tail = NULL;
}

/*
 * Remove all the elements of l.
 * @input l: Pointer to a struct list_t. 
 * List l can be reused without reinitialize.
 */
void list_destroy(list_t *l)
{
    node_list *curr;

    while(l->head != NULL) {
        curr = l->head;
        l->head = curr->next;
        free(curr->data);
        free(curr);
    }
    l->length = 0;
    l->tail = NULL;
}

/*
 * Insert an element at the end of the list.
 * @input l: Pointer to a struct list_t.
 * @input elem: Pointer to the data to be stored.
 */
void list_append(list_t *l, struct pcb *elem)
{
    node_list *node = malloc(sizeof(node_list));
    //node->data = malloc(l->t_size);
    node->data = elem;
    node->next = NULL;
    node->prev = NULL;

    //memcpy(node->data, elem, l->t_size);
    if(l->length == 0) {
        l->head = node;
    } 
    else {
        node->prev = l->tail; 
        l->tail->next = node;
    }
    l->tail = node;
    l->length++;
}

/*
 * Insert an element at the start of the list.
 * @input l: Pointer to a struct list_t.
 * @input elem: Pointer to the data to be stored.
 */
node_list *list_insert(list_t *l, struct pcb *elem)
{
    node_list *node = malloc(sizeof(node_list));
    node->data = elem;
    //node->data = malloc(l->t_size);
    node->next = NULL;
    node->prev = NULL;

    //memcpy(node->data, elem, l->t_size);

    if(l->length == 0) {
        l->tail = node;
    }
    else{
        node->next = l->head;
        l->head->prev = node;
    }
    l->head = node;
    l->length++;
    return(node);
}

/*
 * Return the first element of the list.
 * @input l: Pointer to a struct list_t.
 * @elem: Pointer where the element will be stored
 */
void list_head(list_t *l, struct pcb **elem)
{
    if(l->length > 0){
        *elem = l->head->data;
    }
    else{
        elem = NULL;
    }
}

/*
 * Return the last element of the list.
 * @input l: Pointer to a struct list_t.
 * @elem: Pointer where the element will be stored
 */
void list_tail(list_t *l, void **elem)
{
    if(l->length > 0){
        *elem = l->tail->data;
    }
    else{
        elem = NULL;
    }
}

/*
 * Remove the first element from the list.
 */
void list_rem_head_data(list_t *l)
{
    node_list *node;

    node = l->head;
    if(l->length == 1){
        l->head = NULL;
        l->tail = NULL;
    }
    else{
        l->head = l->head->next;
        l->head->prev = NULL;
    }
    l->length--;
    free(node->data);
    free(node);
}

/*
 * Remove the last element from the list.
 */
void list_rem_tail_data(list_t *l)
{
    node_list *node;

    node = l->tail;
    if(l->length == 1){
        l->head = NULL;
        l->tail = NULL;
    }
    else{
        l->tail = l->tail->prev;     
        l->tail->next = NULL;
    }
    l->length--;
    free(node);
}


/*
 * Remove the first element from the list.
 */
void list_rem_head(list_t *l)
{
    node_list *node;

    node = l->head;
    if(l->length == 1){
        l->head = NULL;
        l->tail = NULL;
    }
    else{
        l->head = l->head->next;
        l->head->prev = NULL;
    }
    l->length--;
    free(node);
}

/*
 * Remove the last element from the list.
 */
void list_rem_tail(list_t *l)
{
    node_list *node;

    node = l->tail;
    if(l->length == 1){
        l->head = NULL;
        l->tail = NULL;
    }
    else{
        l->tail = l->tail->prev;     
        l->tail->next = NULL;
    }
    l->length--;
    free(node->data);
    free(node);
}

/*  
 * @return: 0 if l is empty, 1 otherwise.  
 */ 
long list_empty(list_t *l){     

    long empty = 0;     

    if(l->length == 0){         
        empty = 1;     
    }     
   
    return(empty); 
}

/*  
 * @return l: Number of elements of the list.  
 */ 
long list_length(list_t *l) {     

    return l->length; 
}

void list_rem_elem(list_t *l, struct pcb *elem)
{
    struct node_list *node;
    node = l->head;

    if(l->length == 1){
        l->head = NULL;
        l->tail = NULL;
    }
    else
    while (node->next!= NULL){
        if(node->data==elem){
          if(l->head == node){
              l->head = node->next;
              l->head->prev = NULL;
          }
          else if(l->tail == node){
              l->tail = node->prev;
              l->tail->next = NULL;
          }
          else{
              node->prev->next = node->next;
              node->next->prev = node->prev;
          }
          break;
        }
        else{node=node->next;}
    }
    l->length--;
    free(node->data);
    free(node);
}

