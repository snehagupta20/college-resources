import threading
import time

class LamportClock:
    def __init__(self):
        self.time = 0
        self.lock = threading.Lock()

    def increment(self):
        with self.lock:
            self.time += 1
            return self.time

    def update(self, received_time):
        with self.lock:
            self.time = max(self.time, received_time) + 1
            return self.time

def process(clock, process_id):
    for _ in range(5):
        time.sleep(1)  # Simulate some processing time
        local_time = clock.increment()
        print(f"Process {process_id} at time {local_time}")

if __name__ == "__main__":
    clock = LamportClock()

    threads = []
    for i in range(3):
        thread = threading.Thread(target=process, args=(clock, i))
        threads.append(thread)
        thread.start()

    for thread in threads:
        thread.join()
