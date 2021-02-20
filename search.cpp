#include "node.h"
PNode FindF (PNode Head, string NewWord){ // поиск узла по значению
	PNode q = Head;
	while (q && (q->fam.compare(NewWord))){
		q = q->next;
	}
	return q;
}
PNode CreateNFNode (string name, string fam){
	PNode NewNode = new Node;
	NewNode->name = name;
	NewNode->fam = fam;
	NewNode->count = 1;
	NewNode->next = NULL;
	return NewNode;

	}

int search(string input){
	if (input == "cout"s){
		return 0;
	}
	if (input == "search"s){
		return 1;
	}
	if(input == "delete"s){
	return 2;
	}
	if(input == "exit"s){
	return 3;
	}
	cout << "Я не понял, что вы имели ввиду, давайте я объясню еще раз: \n" << "1.введите search, чтобы найти имя человека по фамилии \n" 
	<< "2.введите cout, чтобы вывести весь список \n" 
	<< "3.введите delete, чтобы удалить данные о человеке \n"
	<< "4.введите exit, чтобы закончить работу \n";
	string in;
	cin >> in;
	return search(in);;
}

bool ex(int a, PNode &q){
	string family;
	if(a == 0){
		PNode b = q;
		while(b && b->next){
			cout << b->fam << " " << b->name << "\n";
			b = b->next;
		}
		return true;
	}
	if(a == 1){
		cout << "Введите фамилию, которую вы хотите найти \n";
		cin >> family;
		PNode ans = FindF(q, family);
		if(ans){
			cout << "Нашел, это " << ans->fam << " " << ans->name << "\n";
		}else{
			cout << "Не нашел(\n";
		}
		return true;
	}
	if(a == 2){
		cout << "Введите фамилию, которую вы хотите удалить\n";
		cin >> family;
		PNode oldn = FindF(q, family);
		if(oldn){
			DeleteNode(q,oldn);
			ex(0, q);
		}else{
			cout << "такого человека(или не человека, я не понял особо, что вы написали) уже нет"; 
		}
			return true;
	}
	if(a == 3){
		cout << "Всего доброго! \n";
	}
	return false;
}



