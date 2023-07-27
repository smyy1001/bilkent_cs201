// Author: Sumeyye ACAR
// ID: 22103640
// File: node.cpp

#include "Course.cpp"
#ifndef NODE_

class node {
    private:
        // Value of the node
        Course value;

        // Pointer to the next node
        node* nextNode;

    public:
        // Constructors 
        node() : nextNode( nullptr ) {}
        ~node() { nextNode = nullptr; }
        node( Course& val) : value( val ), nextNode( nullptr ) {}
        node( node& other) : value( other.getValue() ), nextNode( other.getNextNode() ) {}
        node( Course& val, node* next) : value( val ), nextNode( next ) {}

        // Sey Methods
        void setValue( Course& val) {
            value = val;
        }
        void setNextNode(node* next) {
            nextNode = next;
        }

        // Get Methods
        Course getValue()  {
            return value;
        }
        node* getNextNode()  {
            return nextNode;
        }
    
};

#endif
