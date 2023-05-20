//#include <string>
//#include "libds/amt/implicit_sequence.h"
//#include "typ.h"
//
//class UzemnaJednotka
//{
//public:
//	UzemnaJednotka();
//	UzemnaJednotka(Typ typ, int sortNumber, std::string code, std::string officialTitle, std::string mediumTitle, std::string shortTitle, std::string note);
//	~UzemnaJednotka();
//	void setCode(std::string code);
//	void setSortNum(int sortNum);
//	void setOfficialTitle(std::string officialTitle);
//	void setMediumTitle(std::string mediumTitle);
//	void setShortTitle(std::string shortTitle);
//	std::string getShortTitle();
//	std::string getCode();
//	std::string getNote();
//	UzemnaJednotka* getNadr();
//	ds::amt::ImplicitSequence<UzemnaJednotka*>* getPodr();
//	void setNote(std::string note);
//	std::string toString();
//	void addPodr(UzemnaJednotka* uj);
//	void setNadr(UzemnaJednotka* uj);
//	/*void setDegree(int i) { this->degree = i; };*/
//	void printPodr();
//
//private:
//	Typ typ;
//	int sortNum = 0;
//	std::string code = "";
//	std::string officialTitle = "";
//	std::string mediumTitle = "";
//	std::string shortTitle = "";
//	std::string note = "";
//	UzemnaJednotka* nadr;
//	ds::amt::ImplicitSequence<UzemnaJednotka*>* podr;
//	int degree = 0;
//	};
//
