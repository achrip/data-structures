#pragma once 

#define _DS_ALGORITHMS_H
#include <stdbool.h>
#include <stddef.h> 

struct Node {
    // str will be dynamically allocated
    char *str;  
    int val; 
    struct Node *next, *prev; 
}; 

// default constructor for struct Node
struct Node *node_create(const char *s, int val); 

void push_single_head(struct Node *const n);
void push_double_head(struct Node *const n);

void push_single_tail(struct Node *const n);
void push_double_tail(struct Node *const n);

void push_single_mid(struct Node *const n); 
void push_double_mid(struct Node *const n); 

void print_list(); 
bool search_list(int value);

struct Node *pop_single_head(); 
struct Node *pop_double_head(); 

struct Node *pop_single_tail(); 
struct Node *pop_double_tail(); 

struct Node *pop_single_mid(const char *s); 
struct Node *pop_double_mid(const char *s); 
