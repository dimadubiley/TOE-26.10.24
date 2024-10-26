#pragma once


class Queue {
private:
    int* data;
    int capacity;
    int size;
    int front;
    int rear;

    void resize(int new_capacity);

public:
    Queue(int initial_capacity = 4);
    ~Queue();

    void enqueue(int value);
    int dequeue();
    bool is_empty() const;
    int get_size() const;
};
