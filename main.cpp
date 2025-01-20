#include "BST.h"
#include <iostream>
using namespace std;

int main()
{
    BST bst;
    bst.insert(5);
    bst.insert(4);
    bst.insert(7);

    printf("Find 5: %s\n", bst.find(5) ? "true" : "false");
}