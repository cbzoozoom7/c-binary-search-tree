//bintree.cpp
//Chris Bowman
//Created 16 Apr 2023
#include "bintree.h"
BinTree::BinTree() {
    root = nullptr;
    count = 0;
    int ids[7] = {60, 20, 70, 40, 10, 50, 30};
    string strings[7] = {"sixty", "twenty", "seventy", "forty", "ten", "fifty", "thirty"};
    root = new DataNode;
    root->left = NULL;
    root->right = NULL;
    root->data.id = ids[0];
    root->data.information = strings[0];

    root->left = new DataNode;
    root->left->left = NULL;
    root->left->right = NULL;
    root->left->data.id = ids[1];
    root->left->data.information = strings[1];

    root->right = new DataNode;
    root->right->left = NULL;
    root->right->right = NULL;
    root->right->data.id = ids[2];
    root->right->data.information = strings[2];

    root->left->right = new DataNode;
    root->left->right->left = NULL;
    root->left->right->right = NULL;
    root->left->right->data.id = ids[3];
    root->left->right->data.information = strings[3];
    
    root->left->left = new DataNode;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->left->left->data.id = ids[4];
    root->left->left->data.information = strings[4];
    
    root->left->right->right = new DataNode;
    root->left->right->right->left = NULL;
    root->left->right->right->right = NULL;
    root->left->right->right->data.id = ids[5];
    root->left->right->right->data.information = strings[5];
    
    root->left->right->left = new DataNode;
    root->left->right->left->left = NULL;
    root->left->right->left->right = NULL;
    root->left->right->left->data.id = ids[6];
    root->left->right->left->data.information = strings[6];
}
void BinTree::displayTree() {
    std::cout << "DISPLAY TREE\n==============================================" << std::endl;
    if (isEmpty()) {
        std::cout << "Tree is empty" << std::endl;
    } else {
        std::cout << "Tree is NOT empty" << std::endl;
    }
    std::cout << "Height " << getHeight() << std::endl;
    std::cout << "Node count: " << getCount() << std::endl;
    std::cout << "\nPre-Order Traversal" << std::endl;
    displayPreOrder();
    std::cout << "\nIn-Order Traversal" << std::endl;
    displayInOrder();
    std::cout << "\nPost-Order Traversal" << std::endl;
    displayPostOrder();
    std::cout << "==============================================\n" <<std::endl;
}
void BinTree::displayPreOrder() {
    displayPreOrder(root);
}
void BinTree::displayPreOrder(DataNode *tempRoot) {
    if (tempRoot) {
        std::cout << tempRoot->data.id << " " << tempRoot->data.information << std::endl;
        if (tempRoot->left) {
            displayPreOrder(tempRoot->left);
        }
        if (tempRoot->right) {
            displayPreOrder(tempRoot->right);
        }
    }
}
void BinTree::displayInOrder() {
    displayInOrder(root);
}
void BinTree::displayInOrder(DataNode *tempRoot) {
    if (tempRoot) {
        if (tempRoot->left) {
            displayInOrder(tempRoot->left);
        }
        std::cout << tempRoot->data.id << " " << tempRoot->data.information << std::endl;
        if (tempRoot->right) {
            displayInOrder(tempRoot->right);
        }
    }
}
void BinTree::displayPostOrder() {
    displayPostOrder(root);
}
void BinTree::displayPostOrder(DataNode *tempRoot) {
    if (tempRoot) {
        if (tempRoot->left) {
            displayPostOrder(tempRoot->left);
        }
        if (tempRoot->right) {
            displayPostOrder(tempRoot->right);
        }
        std::cout << tempRoot->data.id << " " << tempRoot->data.information << std::endl;
    }
}
int BinTree::getHeight() {
    return getHeight(root);
}
int BinTree::getHeight(DataNode *tempRoot) {
    int lh = 0;
    int rh = 0;
    int h = 0;
    if (tempRoot) {
        lh = getHeight(tempRoot->left);
        rh = getHeight(tempRoot->right);
        if (lh > rh) {
            h = lh + 1;
        } else {
            h = rh + 1;
        }
    }
    return h;
}
BinTree::~BinTree() {

}
bool BinTree::isEmpty() {
    return false;
}
int BinTree::getCount() {
    return -1;
}
bool BinTree::getRootData(Data *d) {
    return false;
}
void BinTree::clear() {

}
bool BinTree::addNode(int id, const string *data) {
    return false;
}
bool BinTree::removeNode(int id) {
    return false;
}
bool BinTree::getNode(Data* d, int id) {
    return false;
}
bool BinTree::contains(int id) {
    return false;
}
void BinTree::clear(DataNode *tempRoot) {

}
bool BinTree::addNode(DataNode *data, DataNode **tempRoot) {
    return false;
}
DataNode *BinTree::removeNode(int id, DataNode *tempRoot) {
    return nullptr;
}
bool BinTree::getNode(Data *d, int id, DataNode *tempRoot) {
    return false;
}
bool BinTree::contains(int id, DataNode *tempRoot) {
    return false;
}