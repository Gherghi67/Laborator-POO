
#include "pch.h"
#include <iostream>
using namespace std;
class Nod {
private:
	int info;
	Nod* next;
public:
	Nod(int info, Nod* next);
	Nod();
	~Nod();
	void setInfo(int x);
	int getInfo();
	void setNext(Nod* x);
	Nod* getNext();
};
Nod::Nod(int info, Nod* next) {
	this->info = info;
	this->next = next;
}
Nod::Nod() {

}
void Nod::setInfo(int x) {
	info = x;
}
int Nod::getInfo() {
	return info;
}
void Nod::setNext(Nod* x) {
	next = x;
}
Nod* Nod::getNext() {
	return next;
}
Nod::~Nod() {

}
class Lista {
private:
	Nod* start;
	Nod* end;
	unsigned int size = 0;
public:
	Lista(int x);
	Lista(int x, int y);
	Lista(Lista &l);
	~Lista();
	void insert(int x);
	void insertAt(int x, int i);
	int get(int i);
	int length();
	void remove(int i);
	Nod* getStart();
	Nod* getEnd();
	Lista reverse();
	void removeFirst();
	void removeLast();
	bool hasDuplicates();
	bool has(int x);
	bool isEmpty();
};
Nod* Lista::getStart() {
	return start;
}
Nod* Lista::getEnd() {
	return end;
}
Lista::Lista(int x) {
	start = end = new Nod(x, NULL);
	size = 1;
}
Lista::Lista(int x, int y) {
	int i;
	Nod* p = new Nod(y, NULL);
	start = p;
	end = p;
	for (i = 2; i <= x; i++) {
		Nod* q = new Nod(y, NULL);
		p->setNext(q);
		if (i == 2)
			start->setNext(q);
		end = q;
		p = q;
	}
	size = x;
}
Lista::Lista(Lista &l) {
	int i;
	start = end = new Nod(l.get(1), NULL);
	for (i = 2; i <= l.length(); i++)
		insert(l.get(i));
	size = l.length();
}
Lista::~Lista() {
	//cout << "Obiectul a fost distrus\n";
}
void Lista::insert(int x) {
	Nod* p = new Nod(x, NULL);
	end->setNext(p);
	end = p;
	size++;
}
void Lista::insertAt(int x, int i) {
	if (i > size) {
		insert(x);
		return;
	}
	if (i == 1) {
		Nod* p = new Nod(x, start);
		start = p;
	}
	else {
		int j = 2;
		Nod* prev = new Nod();
		Nod* curr = new Nod();
		Nod* p = new Nod(x, NULL);
		curr = start;
		while (curr->getNext() != NULL && j != i + 1) {
			prev = curr;
			curr = curr->getNext();
			j++;
		}
		prev->setNext(p);
		p->setNext(curr);
	}
	size++;
}
int Lista::get(int i) {
	Nod* p = start;
	int j;
	for (j = 1; j <= size; j++) {
		if (j == i) {
			return p->getInfo();
		}
		p = p->getNext();
	}
}
int Lista::length() {
	return size;
}
void Lista::remove(int i) {
	int j = 1;
	Nod* p = start;
	Nod* last = NULL;
	while (j != i) {
		last = p;
		p = p->getNext();
		j++;
	}
	if (p == start) {
		start = start->getNext();
		if (end == p)
			end = NULL;
		delete p;
	}
	else if (p == end) {
		last->setNext(NULL);
		end = last;
		delete p;
	}
	else {
		last->setNext(p->getNext());
		delete p;
	}
	size--;
}
Lista Lista::reverse() {
	Lista l(get(size));
	int i;
	for (i = size - 1; i >= 1; i--) {
		l.insert(get(i));
	}
	return l;
}
void Lista::removeFirst() {
	if (start == NULL)
		return;
	Nod* p = start;
	start = start->getNext();
	delete p;
	size--;
}
void Lista::removeLast() {
	Nod* p;
	Nod* q;
	if (start == NULL)
		return;
	if (start->getNext() == NULL) {
		p = start;
		start = NULL;
		delete p;
	}
	else {
		p = start;
		q = start->getNext();
		while (q->getNext() != NULL) {
			q = q->getNext();
			p = p->getNext();
		}
		p->setNext(NULL);
		delete q;
	}
	size--;
}
bool Lista::hasDuplicates() {
	int i;
	int j;
	for (i = 1; i < size; i++) {
		for (j = i + 1; j <= size; j++) {
			if (get(i) == get(j))
				return true;
		}
	}
	return false;
}
bool Lista::has(int x) {
	int i;
	for (i = 1; i <= size; i++) {
		if (get(i) == x)
			return true;
	}
	return false;
}
bool Lista::isEmpty() {
	if (!size)
		return true;
	return false;
}
void f(Lista l, int x) {
	l.insert(x);
	int i;
	for (i = 1; i <= l.length(); i++)
		cout << l.get(i) << " ";
	cout << "\n";
}
void Afisare(Lista &l) {
	int i;
	for (i = 1; i <= l.length(); i++)
		cout << l.get(i) << " ";
	cout << "\n";
}
int main()
{
	Lista l(5);
	l.insert(3);
	l.insert(2);
	l.insert(1);
	cout << l.isEmpty();
	return 0;
}


