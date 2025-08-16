#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;




struct Node
{
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}

};

class LinkedList
{
    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}


    // Method to insert a node at the beginning
    void insertAtBegining(int val)
    {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Method to insert a node at the end
    void insertAtEnd(int val)
    {
        Node* newNode = new Node(val);
        if(head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }

        tail->next = newNode;
        tail = newNode;

    }

    void reverseList()
    {
        Node* prev = nullptr;
        Node* current = head;
        Node* next_node = nullptr;

        while(current != nullptr)
        {
            next_node = current->next;
            current->next = prev;
            prev = current;
            current= next_node;
        }
        // After the loop, the 'prev' pointer will be at the new head of the list
        head = prev;
        tail = nullptr; // Reset tail as it's no longer accurate after a reversal
    }

    // Method to print the linked list
    void printList()
    {
        Node* current = head;
        while(current != nullptr)
        {
            cout<<current->data << "->";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
};

int main()
{
    LinkedList ls;
    ls.insertAtEnd(50);
    ls.insertAtEnd(70);
    ls.insertAtEnd(90);
    ls.reverseList();
    ls.printList();


}



