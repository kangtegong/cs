a8 = '한'.encode('utf-8')
b8 = '글'.encode('utf-8')
print('utf-8 한:', a8.hex())
print('utf-8 글:', b8.hex())

a16 = '한'.encode('utf-16')
b16 = '글'.encode('utf-16')
print('utf-16 한:', a16.hex())
print('utf-16 글:', b16.hex())

a32 = '한'.encode('utf-32')
b32 = '글'.encode('utf-32')
print('utf-32 한:', a32.hex())
print('utf-32 글:', b32.hex())
