#ifndef node_H
#define node_H
#include <bits/stdc++.h>
using namespace std;

struct Node {
	string word;
	int count;
	Node *next; 
};
typedef Node *PNode; // тип меняем на указатель, я не понимаю, как это работает
PNode CreateNode (string nword);
void prov(string &a);
void AddFirst (PNode &Head, PNode NewNode);
void AddAfter (PNode p, PNode NewNode);
void AddBefore(PNode &Head, PNode p, PNode NewNode);
void AddLast(PNode &Head, PNode NewNode);
PNode Find (PNode Head, string NewWord);
PNode FindPlace (PNode Head, string NewWord);
void DeleteNode(PNode &Head, PNode OldNode);

#endif
