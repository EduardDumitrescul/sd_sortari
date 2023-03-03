//
// Created by eduarddumitrescul on 3/3/23.
//

#include <algorithm>
#include "RandomizedMinHeap.h"

RandomizedMinHeap::RandomizedMinHeap() {
    this->root = nullptr;
}

RandomizedMinHeap::RandomizedMinHeap(long long int value) {
    this->root = new Tree();
    this->root->value = value;
    this->root->left = nullptr;
    this->root->right = nullptr;
}

void RandomizedMinHeap::addValue(const long long int value) {
    Tree *temp = new Tree();
    temp->value = value;
    temp->left = nullptr;
    temp->right = nullptr;
    this->root = RandomizedMinHeap::merge(this->root, temp);
}

long long RandomizedMinHeap::removeMinValue() {
    long long result = this->root->value;
    this->root = RandomizedMinHeap::merge(this->root->left, this->root->right);
    return result;

}

RandomizedMinHeap::Tree *
RandomizedMinHeap::merge(RandomizedMinHeap::Tree *leftTree, RandomizedMinHeap::Tree *rightTree) {
    if(leftTree == nullptr)
        return rightTree;
    else if(rightTree == nullptr)
        return leftTree;

    if(leftTree->value > rightTree->value) {
        std::swap(leftTree, rightTree);
    }
    if(rand() & 1) {
        std::swap(leftTree->left, leftTree->right);
    }
    leftTree->left = RandomizedMinHeap::merge(leftTree->left, rightTree);
    return leftTree;
}

bool RandomizedMinHeap::isEmpty() const {
    return this->root == nullptr;
}
