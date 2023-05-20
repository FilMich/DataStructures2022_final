//#include <codecvt>
//#include "libds/heap_monitor.h"
//#include <iostream>
//#include "handleInput.h"
//
//#include "libds/amt/implicit_sequence.h"
//
//#include <Windows.h>
//
//#include "Header.h"
//
//#include "handlePredicate.h"
//
//#include "filter.h"
//
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
//	std::string subStr = "";
//	std::string startStr = "";
//	auto iter = HandleInplut<UzemnaJednotka>::UzemnaJednotkaHierarchyIterator(input->getStat());
//
//	ds::amt::ImplicitSequence<UzemnaJednotka*>* out = new ds::amt::ImplicitSequence<UzemnaJednotka*>();
//
//	bool loop = true;
//
//	while (loop)
//	{
//		int i = 0;
//		system("cls"); //clear console 
//
//		std::cout << "Menu uroven 1. : " << std::endl;
//
//		std::cout << "1. Filter Obce" << std::endl;
//		std::cout << "2. Filter Okresy" << std::endl;
//		std::cout << "3. Filter Kraje" << std::endl;
//
//		std::cout << "Menu uroven 2. : " << std::endl;
//
//		std::cout << "4. Enter uroven 2." << std::endl;
//
//		std::cout << "5. Exit" << std::endl;
//
//		std::cout << "Enter number to choose from options : " << std::endl;
//		std::cin >> i;
//
//		switch (i)
//		{
//		case 1:
//			break;
//		case 2:
//			break;
//		case 3:
//			break;
//		case 4:
//			break;
//		default:
//			std::cout << "Invalid input! " << std::endl;
//			system("pause");
//			delete out;
//			break;
//		}
//	}
//}