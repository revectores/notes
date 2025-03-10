from multiprocessing import Process
import os

def info(title):
	print(title)
	print('module name:', __name__)
	print('ppid:', os.getppid())
	print('pid: ', os.getpid())
	print()

def f(name):
	info('function f')
	print('hello', name)

if __name__ == '__main__':
	info('main line')
	p = Process(target=f, args=('Robert',))
	p.start()
	p.join()
