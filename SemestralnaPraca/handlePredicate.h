#include "libds/amt/implicit_sequence.h"
#include <functional>
#include "libds/heap_monitor.h"
template<typename J>
class HandlePredicate
{
public:
	HandlePredicate();
	~HandlePredicate();
	//pozriet funkcne objekty
	void setStartStr(std::string startStr) { this->startStr = startStr; };
	void setSubStr(std::string subStr) { this->subStr = subStr; };
	void setTyp(Typ typ) { this->typ = typ; };
	
	bool startsWithStr(std::string str) { return str.rfind(startStr, 0) == 0; }
	bool containsStr(std::string str) { return str.find(subStr) != std::string::npos; }
	bool hasType(Typ typ) { return typ == this->typ; }

private:
	std::string startStr;
	std::string subStr;
	Typ typ;
};

template<typename J>
HandlePredicate<J>::HandlePredicate()
{
}

template<typename J>
HandlePredicate<J>::~HandlePredicate()
{
}