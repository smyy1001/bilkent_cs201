// Author: Sumeyye ACAR
// ID: 22103640
// File: node2.cpp

#include "Student.cpp"
#ifndef NODE_

class node2 {

    private:
        // Value of the node
        Student value;

        // Pointers to the next and previous nodes
        node2* previousNode;
        node2* nextNode;

    public:
    
        // Constructors 
        node2() : nextNode( nullptr ) {}
        ~node2() { nextNode = nullptr; previousNode = nullptr; }
        node2( Student& val) : value( val ), nextNode( nullptr ), previousNode( nullptr ) {}
        node2( node2& other) : value( other.getValue() ), nextNode( other.getNextNode() ), previousNode( other.getPreviousNode() ) {}
        node2( Student& val, node2* previous, node2* next) : value( val ), previousNode( previous ), nextNode( next ) {}

        // Sey Methods
        void setValue( Student& val) {
            value = val;
        }
        void setPreviousNode(node2* previous) {
            previousNode = previous;
        }
        void setNextNode(node2* next) {
            nextNode = next;
        }

        // Get Methods
        Student& getValue()  {
            return value;
        }
        node2* getPreviousNode()  {
            return previousNode;
        }
        node2* getNextNode()  {
            return nextNode;
        }
    
};

#endif