#include <stdio.h>

using namespace std;

// Veri türü olarak int kullanılacak
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};

// Çift bağlı liste sınıfı
class DoublyLinkedList
{
public:
    Node *head;

    DoublyLinkedList() : head(NULL) {}

    // Ekleme işlemi yapan fonksiyon
    void addNode(int val)
    {
        Node *newNode = new Node();
        newNode->data = val;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // Silme işlemi yapan fonksiyon
    void deleteNode(int val)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == val)
            {
                if (temp->prev != NULL)
                {
                    temp->prev->next = temp->next;
                }
                if (temp->next != NULL)
                {
                    temp->next->prev = temp->prev;
                }
                delete temp;
                break;
            }
            temp = temp->next;
        }
    }
};

int main()
{
    DoublyLinkedList dll;
    dll.addNode(10);
    dll.addNode(20);
    dll.addNode(30);
    dll.addNode(40);
    dll.addNode(50);

    cout << "Linked list after addition: ";
    Node *temp = dll.head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    dll.deleteNode(20);
    dll.deleteNode(50);

    cout << "Linked list after deletion: ";
    temp = dll.head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}