#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
    node *prev;
};

struct node *head = NULL;

void insert_first(int value)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = head;
    new_node->prev = NULL;
    if (head != NULL)
        head->prev = new_node;
    head = new_node;
}
void insert_last(int value)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;
    if (head == NULL) // ekta value hole sudhu
    {
        new_node->prev = NULL;
        head = new_node;
        return;
    }
    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_node;
    new_node->prev = temp;
}
void insert_between_two_positions(int pos1, int pos2)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = 100;
    struct node *temp = head;
    for (int i = 1; i < pos1; i++)
        temp = temp->next;
    new_node->next = temp->next;
    new_node->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = new_node;
    temp->next = new_node;
}
void insert_between_two_values(int value1, int value2, int new_value)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = new_value;
    struct node *temp = head;
    while (temp != NULL && temp->data != value1)
        temp = temp->next;
    if (temp == NULL)
        return;
    new_node->next = temp->next;
    new_node->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = new_node;
    temp->next = new_node;
}
void delete_first()
{
    if (head == NULL)
        return;
    struct node *temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(temp);
}
void delete_last()
{
    if (head == NULL)
        return;
    struct node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;
    free(temp);
}
void delete_between_two_positions(int pos1, int pos2)
{
    struct node *temp = head;
    for (int i = 1; i < pos1; i++)
        temp = temp->next;
    struct node *to_delete = temp->next;
    temp->next = to_delete->next;
    if (to_delete->next != NULL)
        to_delete->next->prev = temp;
    free(to_delete);
}
void delete_between_two_values(int value1, int value2, int new_value)
{
    struct node *temp = head;
    while (temp != NULL && temp->data != value1)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL || temp->next->data != value2)
        return;
    struct node *to_delete = temp->next;
    temp->next = to_delete->next;
    if (to_delete->next != NULL)
        to_delete->next->prev = temp;
    free(to_delete);
}
void printF()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void printB()
{
    struct node *temp = head;
    if (temp == NULL)
        return;
    while (temp->next != NULL)
        temp = temp->next;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}
void searching()
{
    int value;
    cout << "Enter value to search: ";
    cin >> value;
    struct node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            cout << "Value found in the linked list." << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Value not found in the linked list." << endl;
}
void last_node()
{
    struct node *temp = head;
    if (temp == NULL)
    {
        cout << "The linked list is empty." << endl;
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    cout << "Last node value: " << temp->data << endl;
}
void previous_of_last_node()
{
    struct node *temp = head;
    if (temp == NULL || temp->next == NULL)
    {
        cout << "There is no previous node of the last node." << endl;
        return;
    }
    while (temp->next->next != NULL)
        temp = temp->next;
    cout << "Previous of last node value: " << temp->data << endl;
}
void list_size()
{
    int count = 0;
    struct node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    cout << "Size of the linked list: " << count << endl;
}
void reversePrint()
{
    struct node *temp = head;
    if (temp == NULL)
        return;
    while (temp->next != NULL)
        temp = temp->next;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main()
{
    insert_first(67);
    insert_last(34);
    insert_between_two_positions(4, 5);
    insert_between_two_values(67, 34, 100);
    delete_first();
    delete_last();
    delete_between_two_positions(4, 5);
    delete_between_two_values(67, 34, 100);
    printF();
    printB();
    searching();             // function to search a value in the linked list
    last_node();             // function to print the value of the last node
    previous_of_last_node(); // function to print the value of the previous node of last node
    list_size();             // function to print the size of the linked list
    reversePrint();          // function to print the linked list in reverse order
}
/* Output
100 
100 
Enter value to search: 34
Value not found in the linked list.
Last node value: 100
There is no previous node of the last node.
Size of the linked list: 1
100*/