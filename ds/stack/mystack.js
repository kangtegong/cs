class myStack {
    constructor() {
        this.items = [];
    }

    push(item) {
        this.items.push(item);
    }

    pop() {
        if (this.is_empty()) {
            return null;
        }
        return this.items.pop();
    }

    is_empty() {
        return this.items.length === 0;
    }
}

const s = new myStack();
s.push('a');
s.push('b');
s.push('c');

console.log(s.pop());  // c
console.log(s.pop());  // b
console.log(s.pop());  // a
