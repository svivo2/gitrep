#include <MinHeap.hpp>

Node::Node(int key, int vertex) {

    this->key = key;
    this->vertex = vertex;
}

MinHeap::MinHeap() {
    this->heap.clear();
}

MinHeap::~MinHeap() {
    this->heap.clear();
}

void MinHeap::push(int key, int vertex) {
    /*
     * Insert key and vertex into the binary heap
     */

    // YOUR CODE HERE
}

void MinHeap::pop() {
    /*
     * Remove the top node in the heap
     */

    // YOUR CODE HERE

}

Node MinHeap::top() {
    /*
     * Return the top node of the heap (we assume that this function is only called when the heap is not empty)
     */

    // YOUR CODE HERE
}

/*
 * This code below is used to communicate with Python
 * You do not need to modify these codes
 */

void* createMinHeap() {
    return new(std::nothrow) MinHeap();
}

void push(void* tree, int vertex, int distance) {
    MinHeap* tree_ = reinterpret_cast<MinHeap*>(tree);
    tree_->push(distance, vertex);

}

void pop(void* tree) {
    MinHeap* tree_ = reinterpret_cast<MinHeap*>(tree);
    tree_->pop();
}

int getMinDistance(void* tree) {
    MinHeap* tree_ = reinterpret_cast<MinHeap*>(tree);
    return tree_->top().key;
}

int getMinVertex(void* tree) {
    MinHeap* tree_ = reinterpret_cast<MinHeap*>(tree);
    return tree_->top().vertex;
}

void releaseMinHeap(void* tree) {
   delete tree;
}
