#include <iostream>
#include <vector>
using namespace std;

class myQueue {
private:
    vector<string> items;

public:
    void enqueue(string item) {
        items.push_back(item);
    }

    string dequeue() {
        if (is_empty()) {
            return "";
        }
        string item = items.front();
        items.erase(items.begin());
        return item;
    }

    bool is_empty() {
        return items.empty();
    }
};

int main() {
    myQueue q;
    q.enqueue("a");
    q.enqueue("b");
    q.enqueue("c");

    cout << q.dequeue() << endl;  // a
    cout << q.dequeue() << endl;  // b
    cout << q.dequeue() << endl;  // c

    return 0;
}
