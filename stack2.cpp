#include <iostream>

struct Node
{
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;

public:
    Stack() : top(nullptr) {}

    void push(int data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        if (top == nullptr)
        {
            std::cout << "Stack is empty" << std::endl;
            return;
        }

        Node *temp = top;
        top = top->next;
        delete temp;
    }

    int peek()
    {
        if (top == nullptr)
        {
            std::cout << "Stack is empty" << std::endl;
            return -1;
        }

        return top->data;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "Peek: " << s.peek() << std::endl;
    s.pop();
    std::cout << "Peek after pop: " << s.peek() << std::endl;

    return 0;
}