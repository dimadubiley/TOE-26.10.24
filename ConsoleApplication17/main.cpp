#include <iostream>
#include "Forwardlist.h"
using namespace std;

int main() {
    Queue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5); 

    while (!queue.is_empty()) {
        cout << queue.dequeue() << " ";
    }
    cout << endl;
}
