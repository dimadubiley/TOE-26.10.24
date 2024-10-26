#include <iostream>
#include "Forwardlist.h"

using namespace std;

Queue::Queue(int initial_capacity)
    : data(new int[initial_capacity]), capacity(initial_capacity), size(0), front(0), rear(0) {}

Queue::~Queue() {
    delete[] data;
}

void Queue::resize(int new_capacity) {
    int* new_data = new int[new_capacity];
    int j = 0;
    for (int i = front; i < front + size; ++i) {
        new_data[j++] = data[i % capacity];
    }
    delete[] data;
    data = new_data;
    capacity = new_capacity;
    front = 0;
    rear = size;
}

void Queue::enqueue(int value) {
    if (size == capacity) {
        resize(capacity * 2);
    }
    data[rear] = value;
    rear = (rear + 1) % capacity;
    ++size;
}

int Queue::dequeue() {
    if (size == 0) {
        throw runtime_error("Queue is empty");
    }
    int value = data[front];
    front = (front + 1) % capacity;
    --size;
    return value;
}

bool Queue::is_empty() const {
    return size == 0;
}

int Queue::get_size() const {
    return size;
}
