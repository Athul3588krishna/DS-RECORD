#include <stdio.h>
#define MAX 5

int cq[MAX];
int front = -1, rear = -1;

int isFull() {
    return (front == (rear + 1) % MAX);
}

int isEmpty() {
    return (front == -1);
}

void enqueue(int x) {
    if(isFull()) {
        printf("Queue is FULL!\n");
        return;
    }
    if(isEmpty())
        front = rear = 0;
    else
        rear = (rear + 1) % MAX;
    cq[rear] = x;
    printf("%d inserted\n", x);
}

void dequeue() {
    if(isEmpty()) {
        printf("Queue is EMPTY!\n");
        return;
    }
    printf("%d deleted\n", cq[front]);
    if(front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

void display() {
    if(isEmpty()) {
        printf("Queue is EMPTY!\n");
        return;
    }
    int i = front;
    printf("Queue elements: ");
    while(1) {
        printf("%d ", cq[i]);
        if(i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int ch, x;
    while(1) {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit: ");
        scanf("%d", &ch);
        if(ch == 1) {
            printf("Enter value: ");
            scanf("%d", &x);
            enqueue(x);
        } else if(ch == 2)
            dequeue();
        else if(ch == 3)
            display();
        else if(ch == 4)
            break;
        else
            printf("Invalid choice!\n");
    }
    return 0;
}
