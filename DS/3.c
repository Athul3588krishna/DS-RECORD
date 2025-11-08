#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;

void insertEnd(int x) {
    struct node *t = (struct node*)malloc(sizeof(struct node));
    t->data = x;
    t->next = NULL;
    if(head == NULL)
        head = t;
    else {
        struct node *p = head;
        while(p->next != NULL)
            p = p->next;
        p->next = t;
    }
    printf("%d inserted\n", x);
}

void deleteVal(int x) {
    if(head == NULL) {
        printf("List empty\n");
        return;
    }
    struct node *p = head, *prev = NULL;
    while(p != NULL && p->data != x) {
        prev = p;
        p = p->next;
    }
    if(p == NULL) {
        printf("Value not found\n");
        return;
    }
    if(prev == NULL)
        head = p->next;
    else
        prev->next = p->next;
    free(p);
    printf("%d deleted\n", x);
}

void display() {
    struct node *p = head;
    if(p == NULL) {
        printf("List empty\n");
        return;
    }
    printf("List: ");
    while(p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    int ch, x;
    while(1) {
        printf("\n1.Insert 2.Delete 3.Display 4.Exit: ");
        scanf("%d", &ch);
        if(ch == 1) {
            printf("Value: ");
            scanf("%d", &x);
            insertEnd(x);
        } else if(ch == 2) {
            printf("Delete value: ");
            scanf("%d", &x);
            deleteVal(x);
        } else if(ch == 3)
            display();
        else if(ch == 4)
            break;
        else
            printf("Invalid choice\n");
    }
    return 0;
}
