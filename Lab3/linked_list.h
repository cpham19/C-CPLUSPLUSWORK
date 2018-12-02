#ifndef LINKED_LIST_H
#define LINKED_LIST_H

void print_list(struct Node *current_node);

void insert_after(struct Node *current_node);

void insert_before(struct Node *current_node);

void search(struct Node *current_node);

void delete(struct Node *current_node);

void delete_front_of_list(struct Node *current_node);

void delete_end_of_list(struct Node *current_node);

void insert_before_list(struct Node **current_node);

void insert_after_list(struct Node *current_node);

struct monster * get_user_input(void);

#endif

