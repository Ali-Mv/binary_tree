#include <iostream>
#include "CompleteBinaryTree.h"
#include "TreeException.h"

int main() {
    cout << "--- Testing Complete Binary Tree with Integer ---" << endl;
    CompleteBinaryTree<int> intTree;

    intTree.insert(10);
    intTree.insert(20);
    intTree.insert(30);
    intTree.insert(40);
    intTree.insert(50);

    cout << "Tree Size: " << intTree.getSize() << endl;
    cout << "Level-Order Traversal: ";
    intTree.levelOrderTraversal(); 


    cout << "\nRemoving last node..." << endl;
    intTree.removeLast(); 
    cout << "Level-Order Traversal after removal: ";
    intTree.levelOrderTraversal(); 

    
    cout << "\nTesting Copy Constructor (Deep Copy)..." << endl;
    CompleteBinaryTree<int> copiedTree = intTree;

    intTree.insert(99); 
    cout << "Original Tree after inserting 99: ";
    intTree.levelOrderTraversal(); 

    cout << "Copied Tree (should remain unchanged): ";
    copiedTree.levelOrderTraversal(); 

    
    cout << "\n--- Testing Complete Binary Tree with Double ---" << endl;
    CompleteBinaryTree<double> doubleTree;
    doubleTree.insert(1.1);
    doubleTree.insert(2.2);
    cout << "Double Tree: ";
    doubleTree.levelOrderTraversal();


    cout << "\n--- Testing Exception Handling ---" << endl;
    CompleteBinaryTree<char> emptyTree;
    try {
        cout << "Attempting to remove from an empty tree..." << endl;
        emptyTree.removeLast(); 
    } 
    catch (const TreeException& e) {
        cerr << "Caught Expected Exception: " << e.what() << endl;
    }

    cout << "\nProgram finished successfully!" << endl;
    return 0;
}