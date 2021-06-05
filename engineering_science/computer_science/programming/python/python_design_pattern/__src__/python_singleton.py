"""
>>> test_thread_safe_singleton(100)
1
"""

import time
import threading

class Singleton(object):
    _instance_lock = threading.Lock()

    def __init__(self):
        pass

    def __new__(cls, *args, **kwargs):
        if not hasattr(Singleton, "_instance"):
            with Singleton._instance_lock:
                if not hasattr(Singleton, "_instance"):
                    Singleton._instance = object.__new__(cls)
        return Singleton._instance


def test_thread_safe_singleton(thread_cnt):
    instances = set()

    def task():
        instance = Singleton()
        instances.add(instance)

    threads = [threading.Thread(target=task, args=[]) for _ in range(thread_cnt)]

    for thread in threads:
        thread.start()

    for thread in threads:
        thread.join()

    return len(instances)


if __name__ == '__main__':
    import doctest
    doctest.testmod()
