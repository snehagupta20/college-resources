class EdgeChasingDeadlockDetector:
    def __init__(self, num_processes):
        self.num_processes = num_processes
        self.wait_for_graph = [[False] * num_processes for _ in range(num_processes)]

    def request_resource(self, requesting_process, resource_owner):
        self.wait_for_graph[requesting_process][resource_owner] = True
        self.detect_deadlocks()

    def release_resource(self, requesting_process, resource_owner):
        self.wait_for_graph[requesting_process][resource_owner] = False

    def detect_deadlocks(self):
        for process in range(self.num_processes):
            visited = [False] * self.num_processes
            cycle_detected = self._dfs(process, visited, process)
            if cycle_detected:
                print(f"Deadlock detected involving process {process}")
                return

    def _dfs(self, start, visited, current):
        if visited[current]:
            return True

        visited[current] = True
        for neighbor in range(self.num_processes):
            if self.wait_for_graph[current][neighbor]:
                if self._dfs(start, visited, neighbor):
                    return True

        visited[current] = False
        return False

# Example usage
if __name__ == "__main__":
    num_processes = 4
    detector = EdgeChasingDeadlockDetector(num_processes)

    # Simulating requests and releases
    detector.request_resource(0, 1)
    detector.request_resource(1, 2)
    detector.request_resource(2, 3)
    detector.request_resource(3, 0)

    # Uncommenting the next line will trigger a deadlock
    # detector.request_resource(0, 3)
    
    detector.release_resource(0, 1)
    detector.release_resource(1, 2)
    detector.release_resource(2, 3)
    detector.release_resource(3, 0)
