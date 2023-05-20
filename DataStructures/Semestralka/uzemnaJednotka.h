#include <string>
using namespace std;

class UzemnaJednotka
{
public:
	UzemnaJednotka(int sortNumber, string code, string officialTitle, string mediumTitle, string shortTitle, string note);
	~UzemnaJednotka();
	

private:
	int sortNum = 0;
	string code = "";
	string officialTitle = "";
	string mediumTitle = "";
	string shortTitle = "";
	string note = "";
	void setCode(string code) { this->code = code; };
	void setSortNum(int sortNum) { this->sortNum = sortNum; };
	void setOfficialTitle(string officialTitle) { this->officialTitle = officialTitle; };
	void setMediumTitle(string mediumTitle) { this->mediumTitle = mediumTitle; };
	void setShortTitle(string shortTitle) { this->shortTitle = shortTitle; };
	void setNote(string note) { this->note = note; };
	string toString() { return to_string(sortNum) + " " + code + " " + officialTitle + " " + mediumTitle + " " + shortTitle + " " + note + "\n"; }
};

UzemnaJednotka::UzemnaJednotka(int sortNumber, string code, string officialTitle, string mediumTitle, string shortTitle, string note)
	: sortNum(sortNumber), code(code), officialTitle(officialTitle), mediumTitle(mediumTitle), shortTitle(shortTitle), note(note)
{
}

UzemnaJednotka::~UzemnaJednotka()
{
}