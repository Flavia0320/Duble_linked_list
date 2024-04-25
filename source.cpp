#include <iostream>
#include <conio.h>


struct Nod {
	int information;
	Nod* prev = nullptr;
	Nod* next = nullptr;
	int id = 0;
};

struct List {
	Nod* first = nullptr;
	Nod* last = nullptr;


	void push_front(int value) {
		Nod* new_nod = new Nod;
		new_nod->information = value;
		new_nod->next = first;
		if (first != nullptr) {
			first->prev = new_nod;
		}
		first = new_nod;
		if (last == nullptr) {
			last = new_nod;
		}
		new_nod->id = last->id + 1;
	}

	void push_back(int value) {
		Nod* new_nod = new Nod;
		new_nod->information = value;
		if (last != nullptr) {
			new_nod->prev = last;
			last->next = new_nod;
			last = new_nod;
			new_nod->id = last->prev->id + 1;
		}
		else {
			first = last = new_nod;
			new_nod->id = 1;
		}
	}

	void pop_back() {
		Nod* node = new Nod;
		if (last != nullptr) {
			node = last;
			last = node->prev;
			if (last == nullptr)
				first = nullptr;
			else last->next = nullptr;
			delete node;
		}
	}
	void pop_front() {
		Nod* node = new Nod;
		if (first != nullptr) {
			node = first;
			first = first->next;
			if (first == nullptr) {
				last = nullptr;
			}
			delete node;
		}
	}
	void print(Nod* left, Nod* right) {
		for (Nod* element = left; element != right; element = element->next)
			std::cout << "ID: " << element->id << " Information: " << element->information << "\n";
		std::cout << "\n";
	}

	Nod* find(int key) {
		Nod* it = first;
		while (it != nullptr) {
			if (it->id == key) {
				return it;
			}
			it = it->next;
		}
		return nullptr;
	}
	int erase(Nod* nod_to_delete) {
		if (nod_to_delete == nullptr) {
			return -1;
		}
		if (nod_to_delete == first) {
			first = first->next;
			if (first != nullptr) {
				first->prev = nullptr;
			}
			else {
				last = nullptr;
			}
		}
		else if (nod_to_delete == last) {
			last = last->prev;
			if (last != nullptr) {
				last->next = nullptr;
			}
			else {
				first = nullptr;
			}
		}
		else {
			nod_to_delete->prev->next = nod_to_delete->next;
			nod_to_delete->next->prev = nod_to_delete->prev;
		}
		delete nod_to_delete;
		return 0;
	}
	void remove(int key) {
		if (find(key) == nullptr) {
			std::cout << "Nu exista elementul cu astfel de cheie" << '\n';
			return;
		}
		else {
			while (find(key) != nullptr) {
				erase(find(key));
			}
			std::cout << "Stergerea a avut succes." << "\n";
		}
	}
	void insert(Nod* nod, int value, int info) {
		if (nod == nullptr) {
			std::cout << "Imposibil. Lista vida" << '\n';
			return;
		}
		Nod* current = find(nod->id);
		if (current == nullptr) {
			std::cout << "Imposibil. Nodul specificat nu exista" << '\n';
			return;
		}
		Nod* new_node = new Nod;
		new_node->id = value;
		new_node->information = info;
		new_node->prev = current->prev;
		new_node->next = current;
		if (current == first) {
			first = new_node;
		}
		else {
			current->prev->next = new_node;
		}
		current->prev = new_node;
	}
	bool empty() {
		return first == nullptr && last == nullptr;
	}
	void clear() {
		while (first != nullptr) {
			pop_back();
		}
	}
	int size() {
		int size = 0;
		Nod* current = first;
		while (current != nullptr) {
			size++;
			current = current->next;
		}
		return size;
	}
};


bool palindrom(List L) {
	if (L.first == nullptr && L.last == nullptr)
		return true;
	Nod* start = L.first;
	Nod* end = L.last;
	while (start != end && start->prev != end) {
		if (start->information != end->information)
			return false;
		start = start->next;
		end = end->prev;
	}
	return true;
}

int compare(List list1, List list2) {
	Nod* start1 = list1.first;
	Nod* end1 = list1.last;
	Nod* start2 = list2.first;
	Nod* end2 = list2.last;
	if (list1.size() != list2.size())
		return 0;
	else {
		while (start1 != end1->next && start2 != end2->next) {
			if (start1 != start2) return 0;
			start1 = start1->next;
			start2 = start2->next;
		}
	}
	return 1;
}



int main() {
	List list1, list2;

	int option;
	do {
		std::cout << "Meniu:\n";
		std::cout << "1. Adaugare element la inceputul liste 1\n";
		std::cout << "2. Adaugare element la sfarsitul listei 1\n";
		std::cout << "3. Eliminare element de la inceputul listei 1\n";
		std::cout << "4. Eliminare element de la sfarsitul listei 1\n";
		std::cout << "5. Cautare element cu o anumita cheie din lista 1\n";
		std::cout << "6. Stergerea unui anumit element din lista 1\n";
		std::cout << "7. Stergerea tuturor aparitiilor unui element cu o anumita cheie din lista 1\n";
		std::cout << "8. Inserarea unui anumit element inaintea unui element anume din lista 1\n";
		std::cout << "9. Verificare daca lista 1 este goala\n";
		std::cout << "10. Golire lista 1\n";
		std::cout << "11. Afisare elemente din lista 1\n";
		std::cout << "12. Afisare marime lista 1\n";
		std::cout << "13. Verificare daca lista 1 este palindrom\n";
		std::cout << "14. Adaugare element la inceputul liste 2\n";
		std::cout << "15. Adaugare element la sfarsitul listei 2\n";
		std::cout << "16. Eliminare element de la inceputul listei 2\n";
		std::cout << "17. Eliminare element de la sfarsitul listei 2\n";
		std::cout << "18. Cautare element cu o anumita cheie din lista 2\n";
		std::cout << "19. Stergerea unui anumit element din lista 2\n";
		std::cout << "20. Stergerea tuturor aparitiilor unui element cu o anumita cheie din lista 2\n";
		std::cout << "21. Inserarea unui anumit element inaintea unui element anume din lista 2\n";
		std::cout << "22. Verificare daca lista 2 este goala\n";
		std::cout << "23. Golire lista 2\n";
		std::cout << "24. Afisare elemente din lista 2\n";
		std::cout << "25. Afisare marime lista 2\n";
		std::cout << "26. Verificare daca lista 2 este palindrom\n";
		std::cout << "27. Comparare liste\n";
		std::cout << "28. EXIT\n";
		std::cout << "Alegeti o optiune:";
		std::cin >> option;

		switch (option) {
		case 1:
			int nrValori1, value1;
			std::cout << "Introduceti cate valori doriti sa adaugati:\n";
			std::cin >> nrValori1;
			for (int i = 0; i < nrValori1; i++) {
				std::cin >> value1;
				list1.push_front(value1);
			}
			std::cout << "Press any key to continue...";
			_getch();
			break;
		case 2:
			int nrValori2, value2;
			std::cout << "Introduceti cate valori doriti sa adaugati:\n";
			std::cin >> nrValori2;
			for (int i = 0; i < nrValori2; i++) {
				std::cin >> value2;
				list1.push_back(value2);
			}
			std::cout << "Press any key to continue...";
			_getch();
			break;
		case 3:
			int nrValori3;
			std::cout << "Introduceti cate valori doriti sa eliminati:\n";
			std::cin >> nrValori3;
			for (int i = 0; i < nrValori3; i++) {
				list1.pop_front();
			}
			std::cout << "Press any key to continue...";
			_getch();
			break;
		case 4:
			int nrValori4;
			std::cout << "Introduceti cate valori doriti sa eliminati:\n";
			std::cin >> nrValori4;
			for (int i = 0; i < nrValori4; i++) {
				list1.pop_back();
			}
			std::cout << "Press any key to continue...";
			_getch();
			break;
		case 5:
			int key;
			std::cout << "Introduceti cheie pentru cautare:\n";
			std::cin >> key;
			Nod* nod_cautat1;
			nod_cautat1 = list1.find(key);
			if (nod_cautat1 == nullptr)
				std::cout << "Invalid.\n";
			else
				std::cout << "Id: " << nod_cautat1->id << " Informatie:" << nod_cautat1->information << '\n';
			std::cout << "Press any key to continue...";
			_getch();
			break;
		case 6:
			int key1;
			std::cout << "Introdu care cheie element de sters\n";
			std::cin >> key1;
			if (list1.erase(list1.find(key1)) == -1)
				std::cout << "Invalid\n";
			else
				std::cout << "Stergere cu succes.\n";
			std::cout << "Press any key to continue...";
			_getch();
			break;
		case 7:
			int key2;
			std::cout << "Introdu care cheie element de sters\n";
			std::cin >> key2;
			list1.remove(key2);
			std::cout << "Press any key to continue...";
			_getch();
			break;
		case 8:
			int id_current1, key3, value3;
			std::cout << "Introdu unde vrei sa inserezi, cheia si valoarea acestuia\n";
			std::cin >> id_current1 >> key3 >> value3;
			list1.insert(list1.find(id_current1), key3, value3);
			std::cout << "Press any key to continue...";
			_getch();
			break;
		case 9:
			if (list1.empty())
				std::cout << "Lista este vida." << '\n';
			else
				std::cout << "Lista nu este vida. \n";
			std::cout << "Press any key to continue...";
			_getch();
			break;
		case 10:
			list1.clear();
			std::cout << "Press any key to continue...";
			_getch();
			break;
		case 11:
			if (list1.last == nullptr)std::cout << "Lista este vida.";
			else list1.print(list1.first, list1.last->next);
			
			std::cout << "Press any key to continue...";
			_getch();
			break;
		case 12:
			std::cout << "Lista are dimensiunea de: " << list1.size() << "\n";
			std::cout << "Press any key to continue...";
			_getch();
			break;
		case 13:
			if (palindrom(list1))
				std::cout << "Lista este palindrom\n";
			else
				std::cout << "Lista nu este palindrom\n";
			std::cout << "Press any key to continue...";
			_getch();
			break;
		case 14:
			int nrValori5, value5;
			std::cout << "Introduceti cate valori doriti sa adaugati:\n";
			std::cin >> nrValori5;
			for (int i = 0; i < nrValori5; i++) {
				std::cin >> value5;
				list2.push_front(value5);
			}
			std::cout << "Press any key to continue...";
			_getch();
			break;
		case 15:
			int nrValori6, value6;
			std::cout << "Introduceti cate valori doriti sa adaugati:\n";
			std::cin >> nrValori6;
			for (int i = 0; i < nrValori6; i++) {
				std::cin >> value6;
				list2.push_back(value6);
			}
			std::cout << "Press any key to continue...";
			_getch();
			break;
		case 16:
			int nrValori7;
			std::cout << "Introduceti cate valori doriti sa eliminati:\n";
			std::cin >> nrValori7;
			for (int i = 0; i < nrValori7; i++) {
				list2.pop_front();
			}
			std::cout << "Press any key to continue...";
			_getch();
			break;
		case 17:
			int nrValori8;
			std::cout << "Introduceti cate valori doriti sa eliminati:\n";
			std::cin >> nrValori8;
			for (int i = 0; i < nrValori8; i++) {
				list2.pop_back();
			}
			std::cout << "Press any key to continue...";
			_getch();
			break;
		case 18:
			int key4;
			std::cout << "Introduceti cheie pentru cautare:\n";
			std::cin >> key4;
			Nod* nod_cautat2;
			nod_cautat2 = list2.find(key4);
			if (nod_cautat2 == nullptr)
				std::cout << "Invalid.\n";
			else
				std::cout << "Id: " << nod_cautat2->id << " Informatie:" << nod_cautat2->information << '\n';
			std::cout << "Press any key to continue...";
			_getch();
			break;
		case 19:
			int key5;
			std::cout << "Introdu care cheie element de sters\n";
			std::cin >> key5;
			if (list2.erase(list2.find(key5)) == -1)
				std::cout << "Invalid\n";
			else
				std::cout << "Stergere cu succes.\n";
			std::cout << "Press any key to continue...";
			_getch();
			break;
		case 20:
			int key6;
			std::cout << "Introdu care cheie element de sters\n";
			std::cin >> key6;
			list2.remove(key6);
			std::cout << "Press any key to continue...";
			_getch();
			break;
		case 21:
			int id_current7, key7, value7;
			std::cout << "Introdu unde vrei sa inserezi, cheia si valoarea acestuia\n";
			std::cin >> id_current7 >> key7 >> value7;
			list2.insert(list2.find(id_current7), key7, value7);
			std::cout << "Press any key to continue...";
			_getch();
			break;
		case 22:
			if (list2.empty())
				std::cout << "Lista este vida." << '\n';
			else
				std::cout << "Lista nu este vida. \n";
			std::cout << "Press any key to continue...";
			_getch();
			break;
		case 23:
			list2.clear();
			std::cout << "Press any key to continue...";
			_getch();
			break;
		case 24:
			list2.print(list2.first, list2.last->next);
			std::cout << "Press any key to continue...";
			_getch();
			break;
		case 25:
			std::cout << "Lista are dimensiunea de: " << list2.size() << "\n";
			std::cout << "Press any key to continue...";
			_getch();
			break;
		case 26:
			if (palindrom(list2))
				std::cout << "Lista este palindrom\n";
			else
				std::cout << "Lista nu este palindrom\n";
			std::cout << "Press any key to continue...";
			_getch();
			break;
		case 27:
			if (compare(list1, list2) == 0)
				std::cout << "Listele nu sunt egale\n";
			else
				std::cout << "Listele sunt egale.\n";
			std::cout << "Press any key to continue...";
			_getch();
			break;
		case 28:
			std::cout << "Iesire din program...\n";
			std::cout << "Press any key to continue...";
			_getch();
			break;
		default:
			std::cout << "Optiune invalida\n";
			std::cout << "Press any key to continue...";
			_getch();
			break;

		}
	} while (option != 28);

	return 0;
}