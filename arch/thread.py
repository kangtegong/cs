import threading
import time

def task1():
	for _ in range(5):
		print("Task 1 is running")
		time.sleep(1)

def task2():
	for _ in range(5):
		print("Task 2 is running")
		time.sleep(1)

def task3():
	for _ in range(5):
		print("Task 3 is running")
		time.sleep(1)

thread1 = threading.Thread(target=task1)
thread2 = threading.Thread(target=task2)
thread3 = threading.Thread(target=task3)

thread1.start()
thread2.start()
thread3.start()

thread1.join()
thread2.join()
thread3.join()
print("All tasks are done.")
