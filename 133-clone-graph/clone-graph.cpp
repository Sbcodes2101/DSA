/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*> mp;
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        Node* clone = new Node(node->val);
        queue<Node*> q;
        q.push(node);
        mp[node] = clone;

        while(!q.empty()){
            Node* curr = q.front();
            q.pop();

            for(Node* neighbor:curr->neighbors){
                if(mp.find(neighbor)==mp.end()){
                    Node* newNode = new Node(neighbor->val);
                    mp[neighbor] = newNode;
                    q.push(neighbor);
                }

                mp[curr]->neighbors.push_back(mp[neighbor]);
            }
        }

        return mp[node];
    }
};