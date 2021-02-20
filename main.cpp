#include "node.h"
int main(){ 
	PNode Head = NULL, p;
	int cc = 0, max = 0;
	ifstream in;
	ofstream out;
	string word;
	in.open("input.txt"); // открываем
	while (true) {
		if (!in) break;
		in >> word;
		prov(word);
		p = Find (Head, word); // ищем слово в списке
		if (p != NULL){ // если нашли слово,
			p->count++; // увеличить счетчик
			if(p->count >= max){
				max = p->count;
			}
		}else{
			p = CreateNode(word); // создаем новый узел
			AddLast (Head, p);

		}
	}
	in.close();
	p = Head;
	out.open("output.txt");
	for(int i = max; i > 0; i--){
		p = Head;
		if (cc >= 100){
			break;
		}
		while(p){
			if(cc <= 100){
				if(p->count == i){
					out << p->word << " - " << p->count << "\n"; 
					cc++;
				}
			}else{
				break;
			}
		p = p->next;

		}
	}
	out.close();
}
