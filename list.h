//
// Created by Rongqin on 2019/4/22.
//

#ifndef UNTITLED41_LIST_H
#define UNTITLED41_LIST_H
#include "list.c"
struct Node;
struct Node *add_elem(struct Node *head, int n);
int count_elem(struct Node *head);
void add_last_elem(struct Node **head, int n);
void prints(struct Node *head);
struct Node *delete_first_node(struct Node *head);
struct Node *delete_last_node(struct Node *head);
struct Node *delete_from_list(struct Node *head, int n);
#endif //UNTITLED41_LIST_H
