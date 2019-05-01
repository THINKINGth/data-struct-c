//
// 
//
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#define FAIL "Memory allocation failed."
#define DELETE_FAIL "Delete node failed.\n"
struct Node{
    int value;
    struct Node *next;
};

struct Node *add_elem(struct Node *head, int n){
    struct Node *new_node;
    new_node = malloc(sizeof(struct Node));
    if(new_node == NULL){
        printf("%s\n", FAIL);
        exit(0);
    }
    new_node->next = head;
    new_node->value = n;
    return new_node;
}

int count_elem(struct Node *head){
    int count = 0;
    for(; head != NULL; head = head -> next)
        count += 1;
    return count;
}

void prints(struct Node *head){
    struct Node *p = head;
    for(; head != NULL; head = head -> next)
        printf("%d ", head -> value);
    printf("\n");
}

void add_last_elem(struct Node **head, int n){
    struct Node *new_node =  NULL;
    struct Node *p = NULL;
    new_node = malloc(sizeof(struct Node));
    if((new_node == NULL) && (p == NULL)){
        printf("%s\n", FAIL);
    }
    new_node -> value = n;
    new_node -> next = NULL;

    p = *head;
    // *head 的副作用时间
    if(*head == NULL){
        *head = new_node;
        return;
    }
    while(p ->next != NULL){
        p = p -> next;
    }
    p -> next = new_node;
}

bool is_empty(struct Node *head){
    if(head == NULL){
        return true;
    }
    return false;
}

struct Node *delete_last_node(struct Node *head){
    if(is_empty(head)){
        printf("%s", DELETE_FAIL);
        return head;
    }
    if(head -> next == NULL) {
        free(head);
        return NULL;
    }
    struct Node *p = NULL;
    p = head;
    for(; p -> next -> next != NULL; p = p -> next)
        ;
    free(p -> next);
    p -> next = NULL;
    return head;
}

struct Node *delete_first_node(struct Node *head){
    struct Node *p = NULL;
    p = head;
    if(is_empty(head)){
        printf("%s", DELETE_FAIL);
        return head;
    }
    head = head -> next;
    free(p);
    return head;
}

struct Node *delete_from_list(struct Node *head, int n){
    if(is_empty(head)){
        printf("%s", DELETE_FAIL);
        return head;
    }
    struct Node *prev = NULL;
    struct Node *aim = NULL;
    aim = head;
    for(; (aim -> next != NULL) && (aim -> value != n); aim = aim -> next){
        prev = aim;
        // aim = aim -> next;
    }

     // 搜索的元素在表头
    if((prev == NULL) && (aim -> value == n)){
        head = head -> next;
        free(aim);
        return head;
    }
    // 没有搜索到元素
    if(aim -> value != n){
        return head;
    }
    //
    else{
        prev -> next = aim -> next;
        free(aim);
    }
    return head;
}
