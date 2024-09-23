#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

class Node {
public:
    int id;
    std::vector<Node*> outgoing_edges;
    std::vector<Node*> incoming_edges;

    Node(int id) : id(id) {}
};

void dfs(Node* current_node, std::unordered_set<Node*>& visited, std::vector<Node*>& path) {
    visited.insert(current_node);
    path.push_back(current_node);

    for (Node* neighbor : current_node->outgoing_edges) {
        if (visited.find(neighbor) == visited.end()) {
            dfs(neighbor, visited, path);
        } else {
            auto it = std::find(path.begin(), path.end(), neighbor);
            if (it != path.end()) {
                std::cout << "Deadlock detected! Path:";
                for (; it != path.end(); ++it) {
                    std::cout << " " << (*it)->id;
                }
                std::cout << std::endl;
            }
        }
    }

    path.pop_back();
}

int main() {
    Node node1(1);
    Node node2(2);
    Node node3(3);

    node1.outgoing_edges = {&node2};
    node2.outgoing_edges = {&node3};
    node3.outgoing_edges = {&node1};

    std::unordered_set<Node*> visited;
    std::vector<Node*> temp_path; // Temporary vector for dfs

    dfs(&node1, visited, temp_path);
    dfs(&node2, visited, temp_path);
    dfs(&node3, visited, temp_path);

    return 0;
}
