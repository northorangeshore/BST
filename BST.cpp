#include "BST.h"

/**
 * Implement the BST constructor
 */
BST::BST() {
    /* YOUR CODE HERE */
    root = nullptr;
    numElements = 0;
}

/**
 * Implement the BST destructor
 */
BST::~BST() {
    /* YOUR CODE HERE */
    clear();
}

/**
 * Implement size() correctly
 */
unsigned int BST::size() const {
    /* YOUR CODE HERE */
    return numElements;
}

/**
 * Implement clear() correctly without memory leaks
 */
void BST::clear() {
    /* YOUR CODE HERE */
    while(root != nullptr)
    {
        Node* current = root;
        while(current->leftChild != nullptr || current->rightChild != nullptr)
        {
            if(current->leftChild != nullptr)
            {
                current = current->leftChild;
            }
            else
            {
                current = current->rightChild;
            }
        }

        if(current->parent != nullptr)
        {
            if(current->parent->leftChild == current)
            {
                current->parent->leftChild = nullptr;
            }
            else
            {
                current->parent->rightChild = nullptr;
            }
        }
        else
        {
            root = nullptr;
        }
        delete current;
    }

    numElements = 0;
}

/**
 * Implement insert() correctly
 */
bool BST::insert(int element) {
    /* YOUR CODE HERE */
    Node* temp = new Node(element);
    Node* parent = nullptr;
    Node* current = root;

    while(current != nullptr)
    {
        parent = current;
        if(element < current->data)
        {
            current = current->leftChild;
        }
        else if(element > current->data)
        {
            current = current->rightChild;
        }
        else
        {
            delete temp;
            return false;
        }
    }

    temp->parent = parent;
    if(parent == nullptr)
    {
        root = temp;
    }
    else if(element < parent->data)
    {
        parent->leftChild = temp;
    }
    else
    {
        parent->rightChild = temp;
    }

    numElements++;
    return true;
}

/**
 * Implement find() correctly
 */
bool BST::find(const int & query) const {
    /* YOUR CODE HERE */
    Node* current = root;
    while(current != nullptr)
    {
        if(query < current->data)
        {
            current = current->leftChild;
        }
        else if(query > current->data)
        {
            current = current->rightChild;
        }
        else
        {
            return true;
        }
    }
    delete current;
    return false;
}

/**
 * Implement the getLeftMostNode() function correctly
 */
BST::Node* BST::getLeftMostNode() {
    /* YOUR CODE HERE */
    if(numElements == 0)
    {
        return nullptr;
    }
    Node* current = root;
    while(current != nullptr && current->leftChild != nullptr)
    {
        current = current->leftChild;
    }
    return current;
}

/**
 * Implement the BST::Node successor function correctly
 */
BST::Node* BST::Node::successor() {
    /* YOUR CODE HERE */
    if(rightChild != nullptr)
    {
        Node* current = rightChild;
        while(current->leftChild != nullptr)
        {
            current = current->leftChild;
        }
        return current;
    }

    Node* current = this;
    Node* parent = this->parent;
    while(parent != nullptr && current == parent->rightChild)
    {
        current = parent;
        parent = parent->parent;
    }
    return parent;
}
