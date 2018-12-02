#ifndef LINKED_LIST_H
#define LINKED_LIST_H

void print_list(struct Node *current_node, void (*fptr)(void *));

void print_monster(void *data);

void insert_front_of_monster_list(struct Node **head);

void insert_front_of_int_list(struct Node **head);

void insert_end_of_int_list(struct Node *head);

void insert_front_of_float_list(struct Node **head);

void insert_end_of_float_list(struct Node *head);

void search_int(struct Node *head);

void search_float(struct Node *head);

void delete_front_of_list(struct Node **head);

void delete_end_of_list(struct Node **head);

void print_int(void *data);

void print_float(void *data);

#endif

