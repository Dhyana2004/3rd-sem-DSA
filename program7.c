#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *link;
    char name[25], usn[15], programme[10];
    int sem, ph_no;
} *head = NULL, *tail = NULL;

void create() {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter Name, USN, Programme, Sem, Phone Number:");
    scanf("%s %s %s %d %d", newnode->name, newnode->usn, newnode->programme, &newnode->sem, &newnode->ph_no);
    newnode->link = NULL;
    if (head == NULL) {
        head = tail = newnode;
    } else {
        tail->link = newnode;
        tail = newnode;
    }
}

void display() {
    struct node *temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("\nName: %s, USN: %s, Programme: %s, Sem: %d, Phone Number: %d\n",
               temp->name, temp->usn, temp->programme, temp->sem, temp->ph_no);
        temp = temp->link;
    }
}

int main() {
    int ch;
    while (1) {
        printf("\nSingle linked list for Student details\n");
        printf("1. Create\n2. Display\n3. Exit\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                exit(0);
            default:
                printf("\nInvalid choice\n");
                break;
        }
    }
    return 0;
}
