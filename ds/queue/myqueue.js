class myQueue {
    constructor() {
        this.items = [];
    }

    enqueue(item) {
        this.items.push(item);
    }

    dequeue() {
        if (this.is_empty()) {
            return null;
        }
        return this.items.shift();
    }

    is_empty() {
        return this.items.length === 0;
    }
}

const q = new myQueue();
q.enqueue('a');
q.enqueue('b');
q.enqueue('c');

console.log(q.dequeue());  // a
console.log(q.dequeue());  // b
console.log(q.dequeue());  // c
