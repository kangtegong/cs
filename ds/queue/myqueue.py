class myQueue:
    def __init__(self):
        self.items = []

    def enqueue(self, item):
        self.items.append(item)

    def dequeue(self):
        if self.is_empty():
            return None
        item = self.items[0]
        del self.items[0]
        return item

    def is_empty(self):
        return len(self.items) == 0

q = myQueue()
q.enqueue('a')
q.enqueue('b')
q.enqueue('c')

print(q.dequeue())  # a
print(q.dequeue())  # b
print(q.dequeue())  # c

