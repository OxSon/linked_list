#include <stdlib.h>
#include <stdio.h>

struct node {
    struct node *pnext;
    int item;
};

/*
void setItem(struct node *node, int item) {
    node->item = item;
}
*/

/*
void addNext(struct node *current, struct node next) {
    if(current->pnext != NULL) {
        current->pnext = &next;
    } else {
        //This doesn't behave how I expected it to
        #warning attempting to add 'next' to a node that already has next
    }
}
*/

int main() {
    //TODO get data from user
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}, i = 0;
    //will this work
    //struct node *head = malloc(sizeof(struct node)), *current = head;
    //or do we need this
    struct node *head = (struct node *) malloc(sizeof(struct node)),
                *current = head;

    int data_length = sizeof(data) / sizeof(data[0]);

    //set up our list
    while(i < data_length) {
        current->item = data[i]; //set data for current node
        //make a new node and point to it
        current->pnext = malloc(sizeof(struct node));
        //point current to that new node
        current = current->pnext;
        i++;
    }

    current = head;
    //print it
    while(current->pnext != NULL) {
        printf("(%d)\n", current->item);
        current = current->pnext;
    }
    printf("\n");//blank line for formatting

    //remove twice
    for(int i = 0; i < 2; i++) {
        struct node *old_head = head;
        head = head->pnext;
        free(old_head);
    }

    //print again
    current = head;
    while(current->pnext != NULL) {
        printf("(%d)\n", current->item);
        current = current->pnext;
    }

    return 0;
}
