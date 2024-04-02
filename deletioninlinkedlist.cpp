#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(node *&head, int d)
{
    node *temp = new node(d);

    temp->next = head;

    head = temp;
}

void insertAtTail(node *&tail, int d)
{
    node *temp = new node(d);

    tail->next = temp;

    tail = temp;
}

void insertAtPosition(node *&head, int position, int d)
{
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }

    int count = 1;
    node *temp = head;

    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    node *nodeToInsert = new node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void Print(node *&head)
{
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(node *&head)
{
    node *temp = head;

    int count = 0;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void deleteNode(node *&head, int position)
{
    if (position == 1)
    {
        node *temp = head;
        head = head->next;

        temp->next = NULL;
        delete temp;
    }

    else
    {
        node *current = head;
        node *previous = NULL;

        int count = 1;
        while (count < position)
        {
            previous = current;
            current = current->next;
            count++;
        }
        previous->next = current->next;
        current->next = NULL;
        delete current;
    }
}

int main()
{
    node *node1 = new node(5);

    node *head = node1;
    node *tail = node1;

    Print(head);

    insertAtHead(head, 7);
    Print(head);

    insertAtHead(head, 8);
    Print(head);

    insertAtHead(head, 87);
    Print(head);

    insertAtHead(head, 78);
    Print(head);

    insertAtHead(head, 63);
    Print(head);

    insertAtTail(tail, 81);
    Print(head);

    insertAtTail(tail, 729);
    Print(head);

    insertAtTail(tail, 96);
    Print(head);

    insertAtHead(head, 24);
    Print(head);

    insertAtTail(tail, 99);
    Print(head);

    insertAtTail(tail, 48);
    Print(head);

    cout << "The lengtb of the linked list is " << getLength(head) << endl;

    insertAtPosition(head, 7, 18);
    Print(head);

    insertAtPosition(head, 5, 84);
    Print(head);

    insertAtPosition(head, 8, 42);
    Print(head);

    cout << "The length of the linked list is " << getLength(head) << endl;

    deleteNode(head, 2);
    Print(head);

    cout << "The length of the linked list is " << getLength(head) << endl;

    deleteNode(head, 4);
    Print(head);

    cout << "The length of the linked list is " << getLength(head) << endl;

    return 0;
}