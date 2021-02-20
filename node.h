#ifndef node_H
#define node_H
#include <bits/stdc++.h>
using namespace std;
// односвязный список:
struct Node {
	string word;
	string name;
	string fam;
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
//фунуции для klass.cpp
int search(string input);
bool ex(int a, PNode &q);
PNode CreateNFNode (string name, string fam);
PNode FindF (PNode Head, string NewWord);
#endif
