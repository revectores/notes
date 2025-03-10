from time import sleep
from threading import Lock, Thread

lock1 = Lock()
lock2 = Lock()

def func1():
	lock1.acquire()
	sleep(500)
	lock2.release()
	print("func1 done!")


def func2():
	lock2.acquire()
	sleep(500)
	lock1.release()
	print("func2 done!")


if __name__ == '__main__':
	thread1 = Thread(target=func1)
	thread2 = Thread(target=func2)
	thread1.start()
	thread2.start()
