#pragma once
#include "libds/amt/implicit_sequence.h"
#include "libds/adt/table.h"
#include "libds/heap_monitor.h"
#include "typ.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

template<typename J>
class HandleInplut
{
public:
	HandleInplut();
	~HandleInplut();
	void loadFromFileObce();
	void loadFromFileOkresy();
	void loadFromFileKraje();
	void printObce();
	void printOkresy();
	void printKraje();
	
	//ds::adt::SortedSequenceTable<std::string, J*>* getTObce() { return this->TObce; }
	//ds::adt::SortedSequenceTable<std::string, J*>* getTOkresy() { return this->TOkresy; }
	//ds::adt::SortedSequenceTable<std::string, J*>* getTKraje() { return this->TKraje; }

	ds::adt::Treap<std::string, J*>* getTObce() { return this->TObce; }
	ds::adt::Treap<std::string, J*>* getTOkresy() { return this->TOkresy; }
	ds::adt::Treap<std::string, J*>* getTKraje() { return this->TKraje; }

	ds::amt::ImplicitSequence<J*>* getISObce() { return this->ISObce; }
	ds::amt::ImplicitSequence<J*>* getISOkresy() { return this->ISOkresy; }
	ds::amt::ImplicitSequence<J*>* getISKraje() { return this->ISKraje; }
	J* getStat() { return this->stat; }
	

private:
	//ds::adt::SortedSequenceTable<std::string, J*>* TObce = new ds::adt::SortedSequenceTable<std::string, J*>();
	//ds::adt::SortedSequenceTable<std::string, J*>* TOkresy = new ds::adt::SortedSequenceTable<std::string, J*>();
	//ds::adt::SortedSequenceTable<std::string, J*>* TKraje = new ds::adt::SortedSequenceTable<std::string, J*>();

	ds::adt::Treap<std::string, J*>* TObce = new ds::adt::Treap<std::string, J*>();
	ds::adt::Treap<std::string, J*>* TOkresy = new ds::adt::Treap<std::string, J*>();
	ds::adt::Treap<std::string, J*>* TKraje = new ds::adt::Treap<std::string, J*>();

	ds::amt::ImplicitSequence<J*>* ISObce = new ds::amt::ImplicitSequence<J*>(); // inicializacia
	ds::amt::ImplicitSequence<J*>* ISOkresy = new ds::amt::ImplicitSequence<J*>();
	ds::amt::ImplicitSequence<J*>* ISKraje = new ds::amt::ImplicitSequence<J*>();

	J* stat = new J(Typ::STAT, 1, "SK", "Slovenko", "Slovenko", "Slovenko", "SK");

public:
	class UzemnaJednotkaHierarchyIterator
	{
	public:
		UzemnaJednotkaHierarchyIterator(J* root) : current(root) {};
		~UzemnaJednotkaHierarchyIterator() { /*delete current; current = nullptr;*/ };
		J& operator*() { return *current; };
		void goToParent() { current = current->getNadr(); }
		void goToSon(size_t index) { current = current->getPodr()->access(index)->data_; }

	private:
		J* current;
	};
};

template<typename J>
HandleInplut<J>::HandleInplut()
{
	
}

template<typename J>
HandleInplut<J>::~HandleInplut()
{
	//for (auto i : *this->ISObce) {
	//	delete i;
	//}
	delete this->ISObce;
	//this->ISObce = nullptr;

	//for (auto i : *this->ISOkresy) {
	//	delete i;
	//}
	delete this->ISOkresy;
	//this->ISOkresy = nullptr;

	//for (auto i : *this->ISKraje) {
	//	delete i;
	//}
	delete this->ISKraje;
	//this->ISKraje = nullptr;

	delete this->stat;
	this->stat = nullptr;
	
	for (auto a : *this->TObce) {
		for (auto l : *a.list_) {
			delete l;
		}
		delete a.list_;
	}

	delete this->TObce;


	//delete this->TOkresy;
	//delete this->TKraje;


	//delete this->TObce;
	//for (auto a : *this->TObce) {
	//	delete a.list_;
	//	delete a.data_;
	//}
	//delete this->TObce;

	for (auto a : *this->TOkresy) {
		delete a.list_;
		delete a.data_;
	}
	delete this->TOkresy;

	for (auto a : *this->TKraje) {
		delete a.list_;
		delete a.data_;
	}
	delete this->TKraje;


	//for (auto i : *this->TObce) {
	//	delete i.data_;
	//}
	//delete this->TObce;
	//this->TObce = nullptr;

	//for (auto i : *this->TOkresy) {
	//	delete i.data_;
	//}
	//delete this->TOkresy;
	//this->TOkresy = nullptr;

	//for (auto i : *this->TKraje) {
	//	delete i.data_;
	//}
	//delete this->TKraje;
	//this->TKraje = nullptr;
}

template<typename J>
inline void HandleInplut<J>::loadFromFileObce()
{
	int sortNum = 0;
	std::string code = "";
	std::string officialTitle = "";
	std::string mediumTitle = "";
	std::string shortTitle = "";
	std::string note = "";

	int c = 0;

	std::ifstream input("C:\\Users\\Filip\\Desktop\\skola\\6. semester\\AUS\\AUS-VS2022\\DataStructures\\SemestralnaPraca\\obce.csv");
	std::string item;
	std::string line;
	std::getline(input, item);
	while (std::getline(input, line))
	{
		if (line.find("Zahranièie") == std::string::npos)
		{
			c = 0;
			std::istringstream in(line);
			while (std::getline(in, item, ';'))
			{
				switch (c)
				{
				case 0:
					sortNum = stoi(item);
					break;
				case 1:
					code = item;

					break;
				case 2:
					officialTitle = item;
					break;
				case 3:
					mediumTitle = item;
					break;
				case 4:
					shortTitle = item;
					break;
				case 5:
					note = item;
					c = 0;
					break;
				}
				c++;
			}
			
			//std::cout << std::to_string(sortNum) << " " << code << " " << officialTitle << " " << mediumTitle << " " << shortTitle << " " << note << " " << std::endl;
			J* uj = new J(Typ::OBEC, sortNum, code, officialTitle, mediumTitle, shortTitle, note);

			this->ISObce->insertLast().data_ = uj;
			
			this->TObce->insertDupp(shortTitle, uj);

			//this->ISObce->insertLast().data_ = new J(Typ::OBEC, sortNum, code, officialTitle, mediumTitle, shortTitle, note);
			
			//this->TObce->insertDupp(shortTitle, new J(Typ::OBEC, sortNum, code, officialTitle, mediumTitle, shortTitle, note));
			
		}
	}
	/*for (auto var : *this->TObce)
	{
		std::cout << var.data_->toString() << std::endl;
	}*/
}

template<typename J>
inline void HandleInplut<J>::loadFromFileOkresy()
{
	int sortNum = 0;
	std::string code = "";
	std::string officialTitle = "";
	std::string mediumTitle = "";
	std::string shortTitle = "";
	std::string note = "";

	int c = 0;

	std::ifstream input("C:\\Users\\Filip\\Desktop\\skola\\6. semester\\AUS\\AUS-VS2022\\DataStructures\\SemestralnaPraca\\okresy.csv");
	std::string item;
	std::string line;
	std::getline(input, item);
	while (std::getline(input, line))
	{
		if (line.find("Zahranièie") == std::string::npos)
		{
			c = 0;
			std::istringstream in(line);
			while (std::getline(in, item, ';'))
			{
				switch (c)
				{
				case 0:
					sortNum = stoi(item);
					break;
				case 1:
					code = item;
					break;
				case 2:
					officialTitle = item;
					break;
				case 3:
					mediumTitle = item;
					break;
				case 4:
					shortTitle = item;
					break;
				case 5:
					note = item;
					c = 0;
					break;
				}
				c++;
			}
			//std::cout << std::to_string(sortNum) << " " << code << " " << officialTitle << " " << mediumTitle << " " << shortTitle << " " << note << " " << std::endl;
			
			J* uj = new J(Typ::OKRES, sortNum, code, officialTitle, mediumTitle, shortTitle, note);

			this->ISOkresy->insertLast().data_ = uj;

			this->TOkresy->insertDupp(shortTitle, uj);

			//this->ISOkresy->insertLast().data_ = new J(Typ::OKRES, sortNum, code, officialTitle, mediumTitle, shortTitle, note);
		
			//this->TOkresy->insertDupp(shortTitle, new J(Typ::OKRES, sortNum, code, officialTitle, mediumTitle, shortTitle, note));

		}
	}
	/*for (auto var : *this->ISObce)
	{
		std::cout << var.toString() << std::endl;
	}*/
}

template<typename J>
inline void HandleInplut<J>::loadFromFileKraje()
{
	int sortNum = 0;
	std::string code = "";
	std::string officialTitle = "";
	std::string mediumTitle = "";
	std::string shortTitle = "";
	std::string note = "";

	int c = 0;

	std::ifstream input("C:\\Users\\Filip\\Desktop\\skola\\6. semester\\AUS\\AUS-VS2022\\DataStructures\\SemestralnaPraca\\kraje.csv");
	std::string item;
	std::string line;
	std::getline(input, item);
	while (std::getline(input, line))
	{
		if (line.find("Zahranièie") == std::string::npos)
		{
			c = 0;
			std::istringstream in(line);
			while (std::getline(in, item, ';'))
			{
				switch (c)
				{
				case 0:
					sortNum = stoi(item);
					break;
				case 1:
					code = item;
					break;
				case 2:
					officialTitle = item;
					break;
				case 3:
					mediumTitle = item;
					break;
				case 4:
					shortTitle = item;
					break;
				case 5:
					note = item.substr(5);
					c = 0;
					break;
				}
				c++;
			}
			//std::cout << std::to_string(sortNum) << " " << code << " " << officialTitle << " " << mediumTitle << " " << shortTitle << " " << note << " " << std::endl;
			
			J* uj = new J(Typ::KRAJ, sortNum, code, officialTitle, mediumTitle, shortTitle, note);

			this->ISKraje->insertLast().data_ = uj;

			this->TKraje->insertDupp(shortTitle, uj);

			//this->ISKraje->insertLast().data_ = new J(Typ::KRAJ, sortNum, code, officialTitle, mediumTitle, shortTitle, note);
			
			//this->TKraje->insertDupp(shortTitle, new J(Typ::KRAJ, sortNum, code, officialTitle, mediumTitle, shortTitle, note));
		}
	}

	for (auto obec : *this->ISObce) {
		for (auto okres : *this->ISOkresy) {
			if (obec->getCode().find(okres->getCode()) == 0){
				okres->addPodr(obec);
				obec->setNadr(okres);
			}
		}
	}

	for (auto okres : *this->ISOkresy) {
		for (auto kraj : *this->ISKraje) {
			if (okres->getCode().find(kraj->getNote()) == 0) {
				kraj->addPodr(okres);
				okres->setNadr(kraj);
			}
		}
	}

	for (auto kraj : *this->ISKraje) {
		stat->addPodr(kraj);
		kraj->setNadr(stat);
	}

	/*for (auto var : *this->ISObce)
	{
		std::cout << var.toString() << std::endl;
	}*/
}

template<typename J>
inline void HandleInplut<J>::printObce()
{
	int i = 1;
	for (auto a : *ISObce)
	{
		std::cout << i++ << " " << a->getShortTitle() << std::endl;
	}
}

template<typename J>
inline void HandleInplut<J>::printOkresy()
{
	int i = 1;
	for (auto a : *ISOkresy)
	{
		std::cout << i++ << " " << a->getShortTitle() << std::endl;
	}
}

template<typename J>
inline void HandleInplut<J>::printKraje()
{
	//std::cout << " " << TOkresy->size() << std::endl;
	int i = 1;
	for (auto a : *TKraje)
	{
		for (auto aa : *a.list_) {
			std::cout << i++ << " " << aa->getShortTitle() << std::endl;
		}
		
	}
}