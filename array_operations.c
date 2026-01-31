#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int a[MAX], n = 0, pos, elem;

void create();
void display();
void insert();
void delete();

void main()
{
    int choice;

    while (1)
    {
        printf("\n\n~~~~MENU~~~~");
        printf("\n1. Create an array");
        printf("\n2. Display array");
        printf("\n3. Insert element");
        printf("\n4. Delete element");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: create(); break;
        case 2: display(); break;
        case 3: insert(); break;
        case 4: delete(); break;
        case 5: exit(0);
        default: printf("\nInvalid choice");
        }
    }
}

void create()
{
    int i;
    printf("\nEnter number of elements: ");
    scanf("%d", &n);
    printf("\nEnter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void display()
{
    int i;
    if (n == 0)
    {
        printf("\nNo elements");
        return;
    }
    printf("\nArray elements: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}

void insert()
{
    int i;
    if (n == MAX)
    {
        printf("\nArray full");
        return;
    }
    printf("\nEnter position: ");
    scanf("%d", &pos);
    printf("\nEnter element: ");
    scanf("%d", &elem);

    for (i = n - 1; i >= pos; i--)
        a[i + 1] = a[i];

    a[pos] = elem;
    n++;
    display();
}

void delete()
{
    int i;
    if (n == 0)
    {
        printf("\nArray empty");
        return;
    }
    printf("\nEnter position: ");
    scanf("%d", &pos);

    elem = a[pos];
    for (i = pos; i < n - 1; i++)
        a[i] = a[i + 1];

    n--;
    printf("\nDeleted element: %d", elem);
    display();
}
