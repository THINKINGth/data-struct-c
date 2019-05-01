#include <stdio.h>
#include <malloc.h>
#include "test.h"
#include "list.h"
#define NAME_LEN 20
#define REMEMBER "Remember who are you, Do not write stupid code."
struct Node *new_node;
int main(){
    printf("%s\n", REMEMBER);
    struct Node *head = NULL;
    add_last_elem(&head, 3);
    head = add_elem(head, 2);
    head = add_elem(head, 1);
    add_last_elem(&head, 4);
    prints(head);
    head = add_elem(head, 5);
    prints(head);
    head = delete_last_node(head);
    prints(head);
    head = delete_first_node(head);
    prints(head);
    head = delete_from_list(head, 1);
    prints(head);
    head = delete_from_list(head, 2);
    prints(head);
    head = delete_from_list(head, 0);
    prints(head);
    printf("%d\n", count_elem(head));
    return 0;

}

