#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "ds_algorithms.h"

struct Node *head = NULL, *tail = NULL; 

int main(void) {
    push_single_mid(node_create("ashraf", 21));
    push_single_mid(node_create("alif", 25));
    push_single_mid(node_create("adillah", 17));
    push_single_mid(node_create("acrip", 20));

    print_list(); 
    return 0; 
}

struct Node *node_create(const char *str, int val) {
    struct Node *n = (struct Node *)malloc(sizeof(struct Node)); 

    int len = sizeof(str) + 1; 
    n->str = calloc(len + 1, sizeof(char)); 
    strcpy(n->str, str); 
    assert(strcmp(n->str, str) == 0);
    n->val = val; 
    n->next = n->prev = NULL; 

    return n; 
}

void push_single_head(struct Node *const n) {
    if (!head) head = tail = n; 
    else {
        n->next = head; 
        head = n; 
    }
}

void push_single_tail(struct Node *const n) {
    if (!head) head = tail = n; 
    else {
        tail->next = n; 
        tail = n; 
    } 
}

void push_single_mid(struct Node *const n) {
    if (!head) head = tail = n; 
    else if (n->val > head->val) push_single_head(n); 
    else if (n->val < tail->val) push_single_tail(n); 
    else {
        struct Node *no = head->next; 
        while(no->next && no->next->val > n->val) no = no->next; 

        assert(no); 
        n->next = no->next; 
        no->next = n; 
    }
}

void push_double_head(struct Node *const n) {
    if (!head) head = tail = n; 
    else {
        head->prev = n; 
        n->next = head; 
        head = n; 
    }
}

void push_double_tail(struct Node *const n) {
    if (!head) head = tail = n; 
    else {
        tail->next = n; 
        n->prev = tail; 
        tail = n; 
    }
}

void push_double_mid(struct Node *const n) {
    if (!head) head = tail = n; 
    else if (n->val > head->val) push_double_head(n); 
    else if (n->val < tail->val) push_double_tail(n); 
    else {
        struct Node *no = head->next; 
        while (no->next && no->next->val > n->val) no = no->next; 

        assert(no); 
        n->next = no->next; 
        n->prev = no; 
        no->next->prev = n; 
        no->next = n; 
    } 
}

struct Node *pop_single_head() {
    if (!head) return NULL; 

    struct Node *const n = head; 
    if (n == tail) { // there exists one data inside the list
        free(head); 
        return (struct Node *)n; 
    }
    else {
        head = n->next; 
        n->next = NULL; 
        return (struct Node *)n; 
    }
}

struct Node *pop_single_tail() {
    if (!head) return NULL; 

    struct Node const *n = tail; 
    if (n == head) { // there exists one data inside the list
        free(tail); 
        return (struct Node *)n; 
    }
    else {
        n = (struct Node const *)head; 
        while (n && n->next != tail) 
            n = n->next; 

        assert(n->next == tail); 
        tail = (struct Node *)n; 
        tail->next->next = NULL; 
        return tail->next;  
    }
}

struct Node *pop_single_mid(const char *str) {
    if (!head) return NULL; 

    if (strcmp(head->str, str) == 0) return pop_single_head();
    else if (strcmp(tail->str, str) == 0) return pop_single_tail();
    else {
        struct Node *n = head;  
        while (n && strcmp(n->next->str, str) != 0)
            n = n->next; 

        assert(strcmp(n->next->str, str)); 
        struct Node *no = n->next; 
        n->next = no->next; 
        no->next = NULL; 
        return no;
    }
}


struct Node *pop_double_head() {
    if (!head) return NULL; 

    struct Node *const n = head; 
    if (n == tail) { // there exists one data inside the list
        free(head); 
        return (struct Node *)n; 
    }
    else {
        head = n->next; 
        n->next = n->prev = NULL; 
        return (struct Node *)n; 
    }
}

struct Node *pop_double_tail() {
    if (!head) return NULL; 

    struct Node *const n = tail; 
    if (n == head) { // there exists one data inside the list
        free(tail); 
        return (struct Node *)n; 
    }
    else {
       tail = n->prev; 
       tail->next = NULL; 
       n->prev = n->next = NULL; 
       return (struct Node *)n; 
    }
}

struct Node *pop_double_mid(const char *str) {
    if (!head) return NULL; 

    if (strcmp(head->str, str) == 0) return pop_double_head();
    else if (strcmp(tail->str, str) == 0) return pop_double_tail();
    else {
        struct Node *n = head->next; 
        while (n->next && strcmp(n->str, str) != 0)
            n = n->next; 

        assert(strcmp(n->str, str)); 
        n->prev->next = n->next; 
        n->next->prev = n->prev; 
        n->next = n->prev = NULL; 

        return n; 
    }
}

void print_list() {
    if (!head) return; 

    struct Node const *n = head; 
    while (n && n->next) {
        printf("str: %-6s | val: %-3d\n", n->str, n->val); 
        printf("%10c\n", '|'); 
        printf("%10c\n", 'v'); 
        n = n->next; 
    }
    printf("%12s\n", "(null)"); 
}

bool search_list(int val) {
    if (!head) return false; 

    struct Node const *n = head; 
    while (n && n->next) {
        if (n->val == val)
            return true; 
        n = n->next; 
    }
    return false; 
}
