#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    // constructor
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void insertAtHead(node *&head, int data)
{
    // empty list
    if (head == NULL)
    {
        head = new node(data);
        return;
    }

    node *n = new node(data);
    n->next = head;
    head = n;
}

void insertInMiddle(node *&head, int data, int pos)
{
    if (pos == 0)
        insertAtHead(head, data);
    else
    {
        node *temp = head;
        // reach previous node
        for (int i = 1; i < pos; i++)
            temp = temp->next;

        node *n = new node(data);
        n->next = temp->next;
        temp->next = n;
    }
}

void printList(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    node *head = NULL;
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    insertAtHead(head, 5);
    insertInMiddle(head, 6, 0);
    insertInMiddle(head, 100, 3);
    printList(head);
}