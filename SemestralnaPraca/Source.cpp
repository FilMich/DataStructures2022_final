#include "Header.h"
#include <iostream>
#include "uzemnaJednotka.h"

inline UzemnaJednotka::UzemnaJednotka()
{
	this->typ = Typ::STAT;
	this->sortNum = 0;
	this->code = "";
	this->officialTitle = "";
	this->mediumTitle = "";
	this->shortTitle = "";
	this->note = "";
	this->nadr = nullptr;
	this->degree = 0;
	this->podr = new ds::amt::ImplicitSequence<UzemnaJednotka*>();
}

UzemnaJednotka::UzemnaJednotka(Typ typ, int sortNumber, std::string code, std::string officialTitle, std::string mediumTitle, std::string shortTitle, std::string note)
	: typ(typ), sortNum(sortNumber), code(code), officialTitle(officialTitle), mediumTitle(mediumTitle), shortTitle(shortTitle), note(note), podr(new ds::amt::ImplicitSequence<UzemnaJednotka*>())
{
	nadr = nullptr;
}

UzemnaJednotka::~UzemnaJednotka()
{
	//nadr = nullptr;
	delete podr;
	podr = nullptr;

}

void UzemnaJednotka::setCode(std::string code)
{
	this->code = code;
}

void UzemnaJednotka::setSortNum(int sortNum)
{
	this->sortNum = sortNum;
}

void UzemnaJednotka::setOfficialTitle(std::string officialTitle)
{
	this->officialTitle = officialTitle;
}

void UzemnaJednotka::setMediumTitle(std::string mediumTitle)
{
	this->mediumTitle = mediumTitle;
}

void UzemnaJednotka::setShortTitle(std::string shortTitle)
{
	this->shortTitle = shortTitle;
}

std::string UzemnaJednotka::getShortTitle()
{
	return this->shortTitle;
}

std::string UzemnaJednotka::getCode()
{
	return this->code;
}

std::string UzemnaJednotka::getNote()
{
	return this->note;
}

UzemnaJednotka* UzemnaJednotka::getNadr()
{
	return this->nadr;
}

ds::amt::ImplicitSequence<UzemnaJednotka*>* UzemnaJednotka::getPodr()
{
	return this->podr;
}

void UzemnaJednotka::setNote(std::string note)
{
	this->note = note;
}

std::string UzemnaJednotka::toString()
{
	return std::to_string(sortNum) + " " + code + " " + officialTitle + " " + mediumTitle + " " + shortTitle + " " + note;
}

void UzemnaJednotka::addPodr(UzemnaJednotka* uj)
{
	this->podr->insertLast().data_ = uj;
}

void UzemnaJednotka::setNadr(UzemnaJednotka* uj)
{
	this->nadr = uj;
}

void UzemnaJednotka::printPodr()
{
	for (auto i : *this->podr) { std::cout << i->getShortTitle() << std::endl; }
}
