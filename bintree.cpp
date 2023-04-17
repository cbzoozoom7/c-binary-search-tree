//bintree.cpp
//Chris Bowman
//Created 16 Apr 2023
#include "bintree.h"
BinTree::BinTree() {
    root = nullptr;
    count = 0;
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
int BinTree::getCount() {
    return count;
}
bool BinTree::addNode(int id, const string *data) {
    bool added = false;
    if (id > 0 && *data != "") {
        DataNode *newNode = new DataNode;
        newNode->data.id = id;
        newNode->data.information = *data;
        newNode->left = nullptr;
        newNode->right = nullptr;
        added = addNode(newNode, &root);
    }
    return added;
}
bool BinTree::addNode(DataNode *newNode, DataNode **tempRoot) {
    bool added = false;
    if (*tempRoot) {
        if (newNode->data.id > (*tempRoot)->data.id) {
            added = addNode(newNode, &((*tempRoot)->right));
        } else {
            added = addNode(newNode, &((*tempRoot)->left));
        }
    } else {
        *tempRoot = newNode;
        count++;
        added = true;
    }
    return added;
}
bool BinTree::contains(int id) {
    bool found = false;
    if (id > 0) {
        found = contains(id, root);
    }
    return found;
}
bool BinTree::contains(int id, DataNode *tempRoot) {
    return findNode(id);
}
DataNode *BinTree::findNode(int id) {
    return findNode(id, root);
}
DataNode *BinTree::findNode(int id, DataNode *tempRoot) {
    DataNode *found = nullptr;
    if (tempRoot) {
        if (tempRoot->data.id == id) {
            found = tempRoot;
        } else {
            if (id > tempRoot->data.id) {
                found = findNode(id, tempRoot->right);
            } else {
                found = findNode(id, tempRoot->left);
            }
        }
    }
    return found;
}
bool BinTree::getNode(Data* d, int id) {
    return getNode(d, id, root);
}
bool BinTree::getNode(Data *d, int id, DataNode *tempRoot) {
    DataNode *found = findNode(id);
    if (found) {
        d->id = found->data.id;
        d->information = found->data.information;
    }
    return found;
}
BinTree::~BinTree() {

}
bool BinTree::isEmpty() {
    return false;
}
bool BinTree::getRootData(Data *d) {
    return false;
}
void BinTree::clear() {

}
bool BinTree::removeNode(int id) {
    return false;
}
void BinTree::clear(DataNode *tempRoot) {

}
DataNode *BinTree::removeNode(int id, DataNode *tempRoot) {
    return nullptr;
}