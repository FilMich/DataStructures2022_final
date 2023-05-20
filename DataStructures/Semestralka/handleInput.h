#include "libds/amt/implicit_sequence.h"
#include "Semestralka/uzemnaJednotka.h"

namespace ds::libds
{
	template<typename J>
	class HandleInplut
	{
	public:
		HandleInplut();
		~HandleInplut();
		void loadFromFile();

	private:
		amt::ImplicitSequence<J>()* pole;
	};

	template<typename J>
	HandleInplut<J>::HandleInplut()
	{
	}

	template<typename J>
	HandleInplut<J>::~HandleInplut()
	{
	}

	template<typename J>
	inline void ds::libds::HandleInplut<J>::loadFromFile()
	{
		//UzemnaJednotka* uj = new UzemnaJednotka();
		cout << "Žilina ¾šèžýáíé";
	}

}
