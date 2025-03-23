#include <queue>
#include <iostream>
using namespace std;

class MyStack {
private:
    queue<int> q1, q2;

public:
    MyStack() {}

    void push(int x) {
        q1.push(x);
    }

    int pop() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int last = q1.front();
        q1.pop();

        // Swap q1 and q2
        swap(q1, q2);

        return last;
    }

    int top() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int last = q1.front();
        q2.push(last); // Put it back
        q1.pop();

        // Swap q1 and q2
        swap(q1, q2);

        return last;
    }

    bool empty() {
        return q1.empty();
    }
};