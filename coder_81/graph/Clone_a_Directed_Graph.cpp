#include <queue>
#include <map>
/*
struct Node {
  int data;
  list<Node*> neighbors;
  Node(int d) : data(d) {}
};
*/

Node* clone(Node* root) {
  unordered_map<Node *, Node*> m;
  unordered_set<Node *> visited;
  queue<Node*> q;
  q.push(root);
  m[root] = new Node(root->data);
  while (!q.empty()) {
    Node * cur = q.front();
    q.pop();
    visited.insert(cur);
    
    //iterate through all neighbors of cur
    list<Node*> tempNeighs;
    for (Node * n : cur->neighbors) {
      //if it not visited, enqueue
      if(visited.find(n) == visited.end()) {
        q.push(n);
      }
      //add n's corresponding node to tempNeighbors
      //if the corresponding node does not exist
      if (m.find(n) != m.end()) {
        tempNeighs.push_back(m[n]);
      }
      else{
	//if exist
        Node * t = new Node(n->data);
        m[n] = t;
        tempNeighs.push_back(t);
      }
    }
    
    //store node into hashmap
    //we garantee the every node in the queue has a coresponding node
    Node * temp = m[cur];
    temp->neighbors = tempNeighs;
  }
  
   return m[root];
}
