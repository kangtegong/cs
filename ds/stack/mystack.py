class myStack:
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if self.is_empty():
            return None
        item = self.items[-1]
        del self.items[-1]
        return item

    def is_empty(self):
        return len(self.items) == 0

s = myStack()
s.push('a')
s.push('b')
s.push('c')

print(s.pop())  # c
print(s.pop())  # b
print(s.pop())  # a

