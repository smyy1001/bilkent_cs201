// Author: Sumeyye ACAR
// ID: 22103640
// File: DoublyLinkedList.cpp

#ifndef LINKED_LIST
#include "node2.cpp"

class DoublyLinkedList {
    private:
        node2* head;
        int size;
        
    public:
        DoublyLinkedList() : head ( nullptr ), size( 0 ) {}

        // Methods
        int length() {
            return size;
        }

        Student& getValue( int pos ) {
            node2* current(head);
            int currentIndex = 0;

            while (current != nullptr && currentIndex < pos) {
                current = current->getNextNode();
                currentIndex++;
            }
            return current->getValue();
        }

        void insert( Student val ) {
            node2* newNode = new node2(val);

            if (head == nullptr) {
                head = newNode;
            } else if (val < head->getValue()) {
                newNode->setNextNode(head);
                head->setPreviousNode(newNode);
                head = newNode;
            } else {
                node2* currentNode = head;

                while (currentNode->getNextNode() != nullptr && currentNode->getNextNode()->getValue() < val) {
                    currentNode = currentNode->getNextNode();
                }

                newNode->setPreviousNode(currentNode);
                newNode->setNextNode(currentNode->getNextNode());

                if (currentNode->getNextNode() != nullptr) {
                    currentNode->getNextNode()->setPreviousNode(newNode);
                }
                
                currentNode->setNextNode(newNode);
            }
            size++;
        }

        void remove( Student val) {
            if (head == nullptr) {
                size = 0;
                return;
            }

            if (head->getValue() == val) {
                node2* temp = head;
                head = head->getNextNode();
                if (head != nullptr) {
                    head->setPreviousNode(nullptr);
                }
                delete temp;
                size--;
                return;
            }

            node2* currentNode = head;

            while (currentNode != nullptr && !(currentNode->getValue() == val)) {
                currentNode = currentNode->getNextNode();
            }

            if (currentNode != nullptr) {
                node2* prevNode = currentNode->getPreviousNode();
                node2* nextNode = currentNode->getNextNode();

                if (prevNode != nullptr) {
                    prevNode->setNextNode(nextNode);
                }

                if (nextNode != nullptr) {
                    nextNode->setPreviousNode(prevNode);
                }

                delete currentNode;
                size--;
            }
        }
};
#endif