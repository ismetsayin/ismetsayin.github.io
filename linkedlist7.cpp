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

// Çift bağlı dairesel liste sınıfı
class DoublyLinkedCircularList
{
public:
    Node *head;

    DoublyLinkedCircularList() : head(NULL) {}

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
            newNode->next = newNode;
            newNode->prev = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = head;
            head->prev = newNode;
        }
    }

    // Silme işlemi yapan fonksiyon
    void deleteNode(int val)
    {
        Node *temp = head;
        if (head->data == val)
        {
            if (head->next == head)
            {
                delete head;
                head = NULL;
            }
            else
            {
                while (temp->next != head)
                {
                    temp = temp->next;
                }
                temp->next = head->next;
                head->next->prev = temp;
                delete head;
                head = temp->next;
            }
        }
        else
        {
            do
            {
                if (temp->data == val)
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    delete temp;
                    break;
                }
                temp = temp->next;
            } while (temp != head);
        }
    }
};

int main()
{
    DoublyLinkedCircularList dllc;
    dllc.addNode(10);
    dllc.addNode(20);
    dllc.addNode(30);
    dllc.addNode(40);
    dllc.addNode(50);

    cout << "Circular linked list after addition: ";
    Node *temp = dllc.head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != dllc.head);
    cout << endl;

    dllc.deleteNode(20);
    dllc.deleteNode(50);

    cout << "Circular linked list after deletion: ";
    temp = dllc.head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != dllc.head);
    cout << endl;

    return 0;
}