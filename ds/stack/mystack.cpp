#include <iostream>
#include <vector>
using namespace std;

class myStack {
private:
    vector<string> items;

public:
    void push(string item) {
        items.push_back(item);
    }

    string pop() {
        if (is_empty()) {
            return "";
        }
        string item = items.back();
        items.pop_back();
        return item;
    }

    bool is_empty() {
        return items.size() == 0;
    }
};

int main() {
    myStack s;
    s.push("a");
    s.push("b");
    s.push("c");

    cout << s.pop() << endl;  // c
    cout << s.pop() << endl;  // b
    cout << s.pop() << endl;  // a

    return 0;
}
