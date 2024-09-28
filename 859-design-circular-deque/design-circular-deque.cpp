class MyCircularDeque {
public:
    vector<int> data;
    int front;
    int back;
    int size;
    int current_count;

    MyCircularDeque(int k) {
        data.resize(k);
        front = 0;
        back = 0;
        size = k;
        current_count = 0;
    }

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        front = (front - 1 + size) % size;
        data[front] = value;
        current_count++;
        return true;
    }

    bool insertLast(int value) {

        if (isFull()) {
            return false;
        }
        data[back] = value;

        back = (back + 1) % size;
        current_count++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty())
            return false;
        front = (front + 1) % size;
        current_count--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty())
            return false;
        back = (back - 1 + size) % size;
        current_count--;
        return true;
    }

    int getFront() {

        if (isEmpty()) {
            return -1;
        }

        return data[front];
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        // Get the last inserted element
        return data[(back - 1 + size) % size];
    }

    bool isEmpty() { return current_count == 0; }

    bool isFull() { return current_count == size; }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */