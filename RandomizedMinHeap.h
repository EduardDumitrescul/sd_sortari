//
// Created by eduarddumitrescul on 3/3/23.
//

#ifndef SD_SORTARI_RANDOMIZEDMINHEAP_H
#define SD_SORTARI_RANDOMIZEDMINHEAP_H


class RandomizedMinHeap {
public:
    struct Tree {
        Tree *left = nullptr;
        Tree *right = nullptr;
        long long value = 0;
    }*root = nullptr;

    static Tree* merge(Tree* leftTree, Tree* rightTree);

    RandomizedMinHeap();

    explicit RandomizedMinHeap(long long value);

    void addValue(long long value);

    long long removeMinValue();

    bool isEmpty() const;
};


#endif //SD_SORTARI_RANDOMIZEDMINHEAP_H
