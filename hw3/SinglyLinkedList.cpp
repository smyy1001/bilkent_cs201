// Author: Sumeyye ACAR
// ID: 22103640
// File: SinglyLinkedList.cpp

#ifndef LINKED_LIST
#include "node.cpp"

class SinglyLinkedList {
    
    private:
        node* head;
        int size;
    public:
        SinglyLinkedList() : head( nullptr ), size( 0 ) {}

        // Methods
        int length() {
            return size;
        }

        Course getValue( int pos) {
            node* current(head);
            int currentIndex = 0;

            while (current != nullptr && currentIndex < pos) {
                current = current->getNextNode();
                currentIndex++;
            }
            return current->getValue();
        }


        void insert( Course val ) {
            node* newNode = new node(val);
 
            if (head == nullptr || val < head->getValue()) {
                newNode->setNextNode( head );
                head = newNode;
            }
            else {
                node* currentNode = head;
                while (currentNode->getNextNode() != nullptr && currentNode->getNextNode()->getValue() < val) {
                    currentNode = currentNode->getNextNode();
                }

                newNode->setNextNode(currentNode->getNextNode());
                currentNode->setNextNode(newNode);
            }
            size++;
        }


        void remove( Course val ) {
            if (head == nullptr) {
                size = 0;
                return;
            }

            if (head->getValue() == val) {
                node* temp = head;
                head = head->getNextNode();
                delete temp;
                size--;
                return;
            }

            node* currentNode = head;

            while (currentNode->getNextNode() != nullptr && !(currentNode->getNextNode()->getValue() == val)) {
                currentNode = currentNode->getNextNode();
            }

            if (currentNode->getNextNode() != nullptr) {
                node* temp = currentNode->getNextNode();
                currentNode->setNextNode( currentNode->getNextNode()->getNextNode());
                delete temp;
                size--;
            }
        }
};

#endif