import threading

class NonTokenMutex:

    # acquire and release methods are used to lock and unlock the semaphore, ensuring that only one thread can enter the critical section at a time.
    def __init__(self):
        self.semaphore = threading.Semaphore(1)  # Initialize semaphore with one permit

    def acquire(self):
        self.semaphore.acquire()  # Acquire the semaphore permit

    def release(self):
        self.semaphore.release()  # Release the semaphore permit

# Shared counter
counter = 0

# Function to increment the counter
def increment_counter(mutex):
    global counter
    for _ in range(1000000):
        mutex.acquire()
        counter += 1
        mutex.release()

# Create a non-token mutual exclusion object
mutex = NonTokenMutex()

# Create two threads to increment the counter
thread1 = threading.Thread(target=increment_counter, args=(mutex,))
thread2 = threading.Thread(target=increment_counter, args=(mutex,))

# Start the threads
thread1.start()
thread2.start()

# Wait for both threads to finish
thread1.join()
thread2.join()

# Print the final value of the counter
print("Final counter value:", counter)
