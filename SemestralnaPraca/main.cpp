#include <codecvt>
#include "libds/heap_monitor.h"
#include <iostream>
//#include "handleInput.h"
#include "ConsoleApp.h"
//#include "libds/amt/implicit_sequence.h"
//#include "libds/adt/list.h"
//#include "libds/adt/table.h"

#include <Windows.h>

//#include "Header.h"

//#include "handlePredicate.h"

//#include "filter.h"


int main() {
	initHeapMonitor();
	SetConsoleOutputCP(1250);
	SetConsoleCP(1250);
	setlocale(LC_ALL, "slovak");

	ConsoleApp* console = new ConsoleApp();
	console->start();
	delete console;
}


//int main() {
//	initHeapMonitor();
//	SetConsoleOutputCP(1250);
//	SetConsoleCP(1250);
//	setlocale(LC_ALL, "slovak");
//	HandleInplut<UzemnaJednotka>* input = new HandleInplut<UzemnaJednotka>();
//	HandlePredicate<UzemnaJednotka>* predicate = new HandlePredicate<UzemnaJednotka>();
//	Filter<UzemnaJednotka>* filter = new Filter<UzemnaJednotka>();
//	input->loadFromFileObce();
//	input->loadFromFileOkresy();
//	input->loadFromFileKraje();
//
//	///////////////////////////////cin nahradit getline() !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//
//	bool loop = true;
//	bool t = true;
//	int i = 0; //input from console
//	int ii = 0; //input from console
//	int iii = 0; //input from console
//	int iiii = 0; //input from console
//	std::string subStr = "";
//	std::string startStr = "";
//	auto iter = HandleInplut<UzemnaJednotka>::UzemnaJednotkaHierarchyIterator(input->getStat());
//
//	ds::adt::ImplicitList<UzemnaJednotka*>* list = new ds::adt::ImplicitList<UzemnaJednotka*>();
//
//	std::string key = "";
//
//	//ds::adt::ImplicitList<UzemnaJednotka*>* ghgh = new ds::adt::ImplicitList<UzemnaJednotka*>();
//
//	//ds::adt::Treap<std::string, UzemnaJednotka*>* treap = new ds::adt::Treap<std::string, UzemnaJednotka*>();
//
//	//UzemnaJednotka* a = new UzemnaJednotka(Typ::STAT, 1, "SK", "Slovenko", "Slovenko", "Slovenko0", "SK");
//	//UzemnaJednotka* b = new UzemnaJednotka(Typ::STAT, 1, "SK", "Slovenko", "Slovenko", "Slovenko1", "SK");
//	//UzemnaJednotka* c = new UzemnaJednotka(Typ::STAT, 1, "SK", "Slovenko", "Slovenko", "Slovenko2", "SK");
//
//	//ghgh->insertLast(a);
//	//ghgh->insertLast(b);
//	//ghgh->insertLast(c);
//
//	//treap->insert("yo0", a);
//	//treap->insert("yo1", b);
//	//treap->insert("yo2", c);
//	//treap->insertDupp("yo0", a);
//	//treap->insertDupp("yo0", b);
//	//treap->insertDupp("yo0", c);
//	//treap->insertDupp("yo0", a);
//	//treap->insertDupp("yo0", a);
//	//treap->insertDupp("yo1", a);
//	//treap->insertDupp("yo1", b);
//	//treap->insertDupp("yo1", c);
//	//treap->insertDupp("yo1", a);
//	//treap->insertDupp("yo1", a);
//	//treap->insertDupp("yo2", a);
//	//treap->insertDupp("yo2", b);
//	//treap->insertDupp("yo2", c);
//	//treap->insertDupp("yo2", a);
//	//treap->insertDupp("yo2", a);
//
//	//std::cout << treap->size() << std::endl;
//
//	//system("pause");
//
//	//if (treap->tryFindDupp("yo0", list)) {
//	//	for (auto a : *list) {
//	//		std::cout << a->getShortTitle() << std::endl;
//	//	}
//	//}
//
//	//system("pause");
//
//	//if (treap->tryFindDupp("yo1", list)) {
//	//	for (auto a : *list) {
//	//		std::cout << a->getShortTitle() << std::endl;
//	//	}
//	//}
//
//	//system("pause");
//
//	//if (treap->tryFindDupp("yo2", list)) {
//	//	for (auto a : *list) {
//	//		std::cout << a->getShortTitle() << std::endl;
//	//	}
//	//}
//
//	//system("pause");
//
//	//for (auto a : *input->getTObce()) {
//	//	for (auto aa : *a.list_) {
//	//		std::cout << aa->getShortTitle() << std::endl;
//	//	}
//	//	
//	//}
//
//	//for (auto ah : *ghgh) { std::cout << ah->toString() << std::endl; }
//
//	//input->printKraje();
//
//	//system("pause");
//
//	//delete ghgh;
//	//delete a;
//	//delete b;
//	//delete c;
//
//
//	while (loop)
//	{
//		system("cls"); //clear console 
//		ds::amt::ImplicitSequence<UzemnaJednotka*>* out = new ds::amt::ImplicitSequence<UzemnaJednotka*>();
//		std::cout << "Menu : " << std::endl;
//
//		std::cout << "1. Filter Obce" << std::endl;
//		std::cout << "2. Filter Okresy" << std::endl;
//		std::cout << "3. Filter Kraje" << std::endl;
//		std::cout << "4. Pohyb po hierarchii" << std::endl;
//
//		std::cout << "5. Search in table Obce" << std::endl;
//		std::cout << "6. Search in table Okresy" << std::endl;
//		std::cout << "7. Search in table Kraje" << std::endl;
//
//		std::cout << "8. Exit" << std::endl;
//
//		std::cout << "Enter number to choose from options : ";
//		std::cin >> i;
//
//		switch (i)
//		{
//		case 1:
//			std::cout << "Filter Obce menu : " << std::endl;
//
//			std::cout << "1. contains string" << std::endl;
//			std::cout << "2. starts with string" << std::endl;
//			std::cout << "3. print without filter" << std::endl;
//
//			std::cout << "Enter number to choose from options : ";
//			std::cin >> ii;
//
//			switch (ii)
//			{
//			case 1:
//				std::cout << "Enter string : " << std::endl;
//				std::cin >> subStr;
//
//				transform(subStr.begin(), subStr.end(), subStr.begin(), ::tolower);
//				//cout << "11" << endl;
//				predicate->setSubStr(subStr);
//				filter->filterData(input->getISObce()->begin(), input->getISObce()->end(),
//					[&](UzemnaJednotka*& uj) { std::string s = ""; s.assign(uj->getShortTitle()); std::transform(s.begin(), s.end(), s.begin(), ::tolower); ; return predicate->containsStr(s); }, out);
//				for(auto a : *out) {
//					std::cout << a->getShortTitle() << std::endl;   //opytat sa na vracanie IS
//				}
//				system("pause");
//				//delete out;
//				out->clear();
//				break;
//			case 2:
//				std::cout << "Enter string : " << std::endl;
//				std::cin >> startStr;
//
//				if (!isupper(startStr[0])) {
//					startStr[0] = toupper(startStr[0]);
//				}
//				//cout << "12" << endl;
//				predicate->setStartStr(startStr);
//				filter->filterData(input->getISObce()->begin(), input->getISObce()->end(),
//					[&](UzemnaJednotka*& uj) { return predicate->startsWithStr(uj->getShortTitle()); }, out);
//				for (auto a : *out) {
//					std::cout << a->getShortTitle() << std::endl;   //opytat sa na vracanie IS
//				}
//				system("pause");
//				//delete out;
//				out->clear();
//				break;
//			case 3:
//				input->printObce();
//				system("pause");
//				//delete out;
//				out->clear();
//				break;
//			default:
//				std::cout << "invalid input" << std::endl;
//				system("pause");
//				//delete out;
//				out->clear();
//				break;
//			}
//
//			break;
//		case 2:
//			std::cout << "Filter Okresy menu : " << std::endl;
//
//			std::cout << "1. contains string" << std::endl;
//			std::cout << "2. starts with string" << std::endl;
//			std::cout << "3. print without filter" << std::endl;
//
//			std::cout << "Enter number to choose from options : ";
//			std::cin >> ii;
//
//			switch (ii)
//			{
//			case 1:
//				std::cout << "Enter string : " << std::endl;
//				std::cin >> subStr;
//
//				transform(subStr.begin(), subStr.end(), subStr.begin(), ::tolower);
//				//cout << subStr + "21" << endl;
//				predicate->setSubStr(subStr);
//				filter->filterData(input->getISOkresy()->begin(), input->getISOkresy()->end(),
//					[&](UzemnaJednotka*& uj) {std::string s = ""; s.assign(uj->getShortTitle()); std::transform(s.begin(), s.end(), s.begin(), ::tolower); ; return predicate->containsStr(s); }, out);
//				for (auto a : *out) {
//					std::cout << a->getShortTitle() << std::endl;   //opytat sa na vracanie IS
//				}
//				system("pause");
//				//delete out;
//				out->clear();
//				break;
//			case 2:
//				std::cout << "Enter string : " << std::endl;
//				std::cin >> startStr;
//
//				if (!isupper(startStr[0])) {
//					startStr[0] = toupper(startStr[0]);
//				}
//				//cout << "22" << endl;
//				predicate->setStartStr(startStr);
//				filter->filterData(input->getISOkresy()->begin(), input->getISOkresy()->end(),
//					[&](UzemnaJednotka*& uj) { return predicate->startsWithStr(uj->getShortTitle()); }, out);
//				for (auto a : *out) {
//					std::cout << a->getShortTitle() << std::endl;   //opytat sa na vracanie IS
//				}
//				system("pause");
//				//delete out;
//				out->clear();
//				break;
//			case 3:
//				input->printOkresy();
//				system("pause");
//				//delete out;
//				out->clear();
//				break;
//			default:
//				std::cout << "invalid input" << std::endl;
//				system("pause");
//				//delete out;
//				out->clear();
//				break;
//			}
//
//			break;
//		case 3:
//			std::cout << "Filter Kraje menu : " << std::endl;
//
//			std::cout << "1. contains string" << std::endl;
//			std::cout << "2. starts with string" << std::endl;
//			std::cout << "3. print without filter" << std::endl;
//
//			std::cout << "Enter number to choose from options : ";
//			std::cin >> ii;
//
//			switch (ii)
//			{
//			case 1:
//				std::cout << "Enter string : " << std::endl;
//				std::cin >> subStr;
//
//				transform(subStr.begin(), subStr.end(), subStr.begin(), ::tolower);
//				//cout << "31" << endl;
//				predicate->setSubStr(subStr);
//				filter->filterData(input->getISObce()->begin(), input->getISObce()->end(),
//					[&](UzemnaJednotka*& uj) { std::string s = ""; s.assign(uj->getShortTitle()); std::transform(s.begin(), s.end(), s.begin(), ::tolower); ; return predicate->containsStr(s); },out);
//				for (auto a : *out) {
//					std::cout << a->getShortTitle() << std::endl;   //opytat sa na vracanie IS
//				}
//				system("pause");
//				//delete out;
//				out->clear();
//				break;
//			case 2:
//				std::cout << "Enter string : " << std::endl;
//				std::cin >> startStr;
//
//				if (!isupper(startStr[0])) {
//					startStr[0] = toupper(startStr[0]);
//				}
//
//				//cout << "32" << endl;
//				predicate->setStartStr(startStr);
//				filter->filterData(input->getISKraje()->begin(), input->getISKraje()->end(),
//					[&](UzemnaJednotka*& uj) { return predicate->startsWithStr(uj->getShortTitle()); }, out);
//				for (auto a : *out) {
//					std::cout << a->getShortTitle() << std::endl;   //opytat sa na vracanie IS
//				}
//				system("pause");
//				//delete out;
//				out->clear();
//				break;
//			case 3:
//				input->printKraje();
//				system("pause");
//				//delete out;
//				out->clear();
//				break;
//			default:
//				std::cout << "invalid input" << std::endl;
//				system("pause");
//				//delete out;
//				out->clear();
//				break;
//			}
//
//			break;
//		case 4:
//			
//			while (t)
//			{
//				std::cout << "nachadzate sa na uzemnej jednotke " << iter.operator*().getShortTitle() << std::endl << std::endl;
//				std::cout << "1. Presunut sa na podradenu Uzemnu Jednotku" << std::endl;
//				std::cout << "2. Presunut sa na nadradenu Uzemnu Jednotku" << std::endl;
//				std::cout << "3. Vykonaj operaciu contains nad U. J." << std::endl;
//				std::cout << "4. Exit" << std::endl;
//
//				std::cin >> iii;
//
//				switch (iii)
//				{
//				case 1:
//					iter.operator*().printPodr();
//					int s;
//					std::cout << "zadajte cislo kraju pre ktory chcete vykonat operaciu " << std::endl;
//					std::cin >> s;
//
//					iter.goToSon(s - 1);
//					break;
//
//				case 2:
//					std::cout << iter.operator*().getNadr()->getShortTitle() << std::endl;
//					iter.goToParent();
//					break;
//
//				case 3:
//
//					std::cout << "Vykonaj operaciu contains nad "<< iter.operator*().getShortTitle() << std::endl;
//					std::cout << "1. ContainsString" << std::endl;
//					std::cout << "2. StartsWithString" << std::endl;
//					std::cout << "3. HasType" << std::endl;
//
//					std::cin >> iiii;
//
//					switch (iiii) {
//						case 1:
//							std::cout << "ContainsString" << std::endl << std::endl;
//							std::cout << "zadajte string" << std::endl;
//							std::cin >> subStr;
//							predicate->setSubStr(subStr);
//							filter->processPreOrder(&(iter.operator*()),
//								[&](UzemnaJednotka* node) { filter->filterData(node->getPodr()->begin(), node->getPodr()->end(),
//									[&](UzemnaJednotka*& uj) { return predicate->containsStr(uj->getShortTitle()); }, out); });
//
//
//							for (auto a : *out) {
//								std::cout << a->getShortTitle() << std::endl;   //opytat sa na vracanie IS
//							}
//
//							system("pause");
//							//delete out;
//							out->clear();
//							break;
//						case 2:
//							std::cout << "StartsWithString" << std::endl << std::endl;
//							std::cout << "zadajte string" << std::endl;
//							std::cin >> startStr;
//							predicate->setStartStr(startStr);
//							filter->processPreOrder(&(iter.operator*()),
//								[&](UzemnaJednotka* node) { filter->filterData(node->getPodr()->begin(), node->getPodr()->end(),
//									[&](UzemnaJednotka*& uj) { return predicate->startsWithStr(uj->getShortTitle()); }, out); });
//
//
//							for (auto a : *out) {
//								std::cout << a->getShortTitle() << std::endl;   //opytat sa na vracanie IS
//							}
//
//							system("pause");
//							//delete out;
//							out->clear();
//							break;
//						case 3:
//							int typ;
//							std::cout << "Has Type " << std::endl;
//							std::cout << "1. Obec " << std::endl;
//							std::cout << "2. Okres " << std::endl;
//							std::cout << "3. Kraj " << std::endl;
//							//std::cin >> startStr;
//							std::cin >> typ;
//
//							switch (typ)
//							{
//							case 1:
//								/*std::cout << "zadajte cislo kraju pre ktory chcete vykonat operaciu " << std::endl;
//								std::cin >> subStr;*/
//								predicate->setTyp(Typ::OBEC);
//								filter->processPreOrder(&(iter.operator*()),
//									[&](UzemnaJednotka* node) { filter->filterData(node->getPodr()->begin(), node->getPodr()->end(),
//										[&](UzemnaJednotka*& uj) { return predicate->hasType(uj->getTyp()); }, out); });
//
//
//								for (auto a : *out) {
//									std::cout << a->getShortTitle() << std::endl;   //opytat sa na vracanie IS
//								}
//
//								system("pause");
//								//delete out;
//								out->clear();
//								break;
//							case 2:
//								//std::cout << "zadajte cislo kraju pre ktory chcete vykonat operaciu " << std::endl;
//								//std::cin >> subStr;
//								predicate->setTyp(Typ::OKRES);
//								filter->processPreOrder(&(iter.operator*()),
//									[&](UzemnaJednotka* node) { filter->filterData(node->getPodr()->begin(), node->getPodr()->end(),
//										[&](UzemnaJednotka*& uj) { return predicate->hasType(uj->getTyp()); }, out); });
//
//
//								for (auto a : *out) {
//									std::cout << a->getShortTitle() << std::endl;   //opytat sa na vracanie IS
//								}
//
//								system("pause");
//								//delete out;
//								out->clear();
//								break;
//							case 3:
//								//std::cout << "zadajte cislo kraju pre ktory chcete vykonat operaciu " << std::endl;
//								//std::cin >> subStr;
//								predicate->setTyp(Typ::KRAJ);
//								filter->processPreOrder(&(iter.operator*()),
//									[&](UzemnaJednotka* node) { filter->filterData(node->getPodr()->begin(), node->getPodr()->end(),
//										[&](UzemnaJednotka*& uj) { return predicate->hasType(uj->getTyp()); }, out); });
//
//
//								for (auto a : *out) {
//									std::cout << a->getShortTitle() << std::endl;   //opytat sa na vracanie IS
//								}
//
//								system("pause");
//								//delete out;
//								out->clear();
//								break;
//							default:
//								delete out;
//								break;
//							}
//							break;
//						default:
//							delete out;
//							break;
//					}
//					break;
//					delete out;
//				case 4:
//					t = false;
//					system("pause");
//					delete out;
//					break;
//
//				default:
//					delete out;
//					//out->clear();
//					break;
//				}
//			}
//			
//
//			//system("pause");
//			break;
//
//			/*input->printOkresy();
//
//			int s;
//			cout << "zadajte cislo Okresu pre vypisanie obci v danom okrese : " << endl;
//			cin >> s;
//			cout << input->getOkresy()->access(s - 1)->data_->toString() << endl;
//			input->getOkresy()->access(s - 1)->data_->printPodr();
//			delete out;
//			system("pause");
//			break;*/
//			
//		case 5:
//
//			/*for (auto var : *input->getTObce()) {
//				std::cout << var.data_->getShortTitle() << std::endl;
//			}
//			system("pause");*/
//			std::cout << "Enter key : " << std::endl;
//			std::cin >> key;
//			if (input->getTObce()->tryFindDupp(key, list))
//			{
//
//				std::cout << "Key found!" << std::endl;
//				std::cout << std::to_string(list->size()) << std::endl;
//				system("pause");
//
//				for (auto var : *list) {
//					std::cout << var->toString() << std::endl;
//				}
//				system("pause");
//			}
//			else
//			{
//				std::cout << "Key not found!" << std::endl;
//				system("pause");
//			}
//			
//			delete out;
//			break;
//
//		case 6:
//
//			std::cout << "Enter key : " << std::endl;
//			std::cin >> key;
//			if (input->getTOkresy()->tryFindDupp(key, list))
//			{
//
//				std::cout << "Key found!" << std::endl;
//				std::cout << std::to_string(list->size()) << std::endl;
//				system("pause");
//
//				for (auto var : *list) {
//					std::cout << var->toString() << std::endl;
//				}
//				system("pause");
//			}
//			else
//			{
//				std::cout << "Key not found!" << std::endl;
//				system("pause");
//			}
//
//			delete out;
//			break;
//
//			//for (auto var : *input->getTOkresy()) {
//			//	std::cout << var.data_->getShortTitle() << std::endl;
//			//}
//			//system("pause");
//
//			//std::cout << "Enter key : " << std::endl;
//			//std::cin >> key;
//			//if (input->getTOkresy()->tryFindDup(key, list))
//			//{
//
//			//	std::cout << "Key found!" << std::endl;
//			//	std::cout << std::to_string(list->size()) << std::endl;
//			//	system("pause");
//
//			//	for (auto var : *list) {
//			//		std::cout << var->toString() << std::endl;
//			//	}
//			//	system("pause");
//			//}
//			//else
//			//{
//			//	std::cout << "Key not found!" << std::endl;
//			//	system("pause");
//			//}
//			//delete list;
//			//delete out;
//			//break;
//
//		case 7:
//
//			std::cout << "Enter key : " << std::endl;
//			std::cin >> key;
//			if (input->getTKraje()->tryFindDupp(key, list))
//			{
//
//				std::cout << "Key found!" << std::endl;
//				std::cout << std::to_string(list->size()) << std::endl;
//				system("pause");
//
//				for (auto var : *list) {
//					std::cout << var->toString() << std::endl;
//				}
//				system("pause");
//			}
//			else
//			{
//				std::cout << "Key not found!" << std::endl;
//				system("pause");
//			}
//
//			delete out;
//			break;
//
//		case 8:					  //////////////
//			loop = false;         //////////////prehodit vzdy posledne
//			delete out;
//			break;
//
//		default:
//			std::cout << "invalid input" << std::endl;
//			system("pause");
//			delete out;
//			break;
//		}
//	}
//
//	delete list;
//	delete predicate;
//	delete input;
//	delete filter;
//
//}