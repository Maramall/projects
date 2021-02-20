#include "node.h"

PNode CreateNode (string nword){
	PNode NewNode = new Node;
	NewNode->word = nword;
	NewNode->count = 1;
	NewNode->next = NULL;
	return NewNode;
}
void prov(string &a){
	int l = a.length();
	for (int i = 0; i < l; ++i){
		if(a[i] == '.'){ 
			a.erase(i,1);
		}
		if(a[i] == ','){ 
			a.erase(i,1);
		}
		if(a[i] == '?'){ 
			a.erase(i,1);
		}
		if(a[i] == '!'){ 
			a.erase(i,1);
		}
		if(a[i] == '"'){ 
			a.erase(i,1);
		}
		if(a[i] == '('){ 
			a.erase(i,1);
		}
		if(a[i] == ')'){ 
			a.erase(i,1);
	
		}
	}
}
void AddFirst (PNode &Head, PNode NewNode){ // добавление в начало списка
	NewNode->next = Head;
	Head = NewNode;
}
void AddAfter (PNode p, PNode NewNode) // добавление узла после заданного
{
	NewNode->next = p->next;
	p->next = NewNode;
}
void AddBefore(PNode &Head, PNode p, PNode NewNode) // добавление узла перед заданным
{
	PNode q = Head;
	if (Head == p) {
		AddFirst(Head, NewNode); // вставка перед первым узлом
		return;
	}
	while (q && q->next != p){ // ищем узел, за которым следует p
		q = q->next;
	}
	if (q){ // если нашли такой узел,
		AddAfter(q, NewNode); // добавить новый после него
	}
}
void AddLast(PNode &Head, PNode NewNode) // добавление узла в конец списка
{
	PNode q = Head;
	if (Head == NULL) { // если список пуст,
		AddFirst(Head, NewNode); // вставляем первый элемент
		return;
	}
	while (q->next) q = q->next; // ищем последний элемент
		AddAfter(q, NewNode);
}
PNode Find (PNode Head, string NewWord){ // поиск узла по значению
	PNode q = Head;
	while (q && q->word.compare(NewWord)){
		q = q->next;
	}
	return q;
}
PNode FindPlace (PNode Head, string NewWord)
{
	PNode q = Head;
	while (q && (q->word.compare(NewWord) > 0)){
		q = q->next;
	}
	return q;
}
void DeleteNode(PNode &Head, PNode OldNode){
	PNode q = Head;
	if(Head == OldNode){
		Head = OldNode->next;
	}else{
		while(q && q->next != OldNode){
			q = q->next;
		}
		if(q == NULL) return;
		q->next = OldNode->next;
		}
	delete OldNode;
	
}
