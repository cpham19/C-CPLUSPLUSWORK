#ifndef LINKED_SORT_DEMO_H
#define LINKED_SORT_DEMO_H

void printList(struct Node *current_node) {
    while (current_node != NULL) {
        printf("Monster #%d %s\n", current_node->id, current_node-> name);
        current_node = current_node->next;
    }

    printf("\n");
}

#endif


