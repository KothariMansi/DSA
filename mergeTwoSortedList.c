#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void helper(struct ListNode* list1, struct ListNode* list2, struct ListNode* output) {
    if (list1 == NULL && list2 == NULL) return;
    if (list1 == NULL){
        output->next = list2;
        return;
    };
    if (list2 == NULL) {
        output->next = list1;
        return;
    };
    if (list1->val < list2->val) {
        output->next = list1;
        helper(list1->next, list2, output->next);
    } else {
        output->next = list2;
        helper(list1, list2->next, output->next);
    }
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL && list2 == NULL) return NULL;
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;
    struct ListNode* output;
    if (list1->val < list2->val) {
        output = list1; 
        helper(list1->next, list2, output);
    } 
    else {
        output = list2; 
        helper(list1, list2->next, output);
    }
    return output;
}

void makeList(struct ListNode** list, int val) {
    if (val > 10)
    {
        *list = NULL;
        return;
    }
    *list =  malloc(sizeof(struct ListNode));
    (*list)->val = val;
    makeList(&(*list)->next, val+2);
    return;
}

void display(struct ListNode* list) {
    if (list == NULL) return;
    printf("%d ", list->val);
    display(list->next);
}


int main() {
    struct ListNode* list1 = malloc(sizeof(struct ListNode));
    struct ListNode* list2 = malloc(sizeof(struct ListNode));
    makeList(&list1, 1);
    display(list1);
    printf("\n");
    makeList(&list2, 2);
    display(list2);
    printf("\n");
    struct ListNode* result = mergeTwoLists(list1, list2);
    display(result);
}