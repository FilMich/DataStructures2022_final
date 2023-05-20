#include "libds/amt/implicit_sequence.h"
#include "libds/heap_monitor.h"
template<typename J>
class Filter
{
public:
	Filter();
	~Filter();

	template<typename Iterator, typename Out>
	void filterData(Iterator begin, Iterator end, std::function<bool(UzemnaJednotka*&)> predicate, Out& out) {
		for (auto it = begin; it != end; ++it)
		{
			if (predicate(*it))
			{
				out->insertLast().data_ = *it;
			}
		}
	}

	void processPreOrder(J* node, std::function<void(J*)> operation) {
		if (node != nullptr)
		{
			operation(node);
			size_t degree = node->getPodr()->size();
			for (size_t i = 0; i < degree; ++i)
			{
				J* son = node->getPodr()->access(i)->data_;
				if (son != nullptr)
				{
					this->processPreOrder(son, operation);
				}
				else
				{
					++degree;
				}
			}
		}
	}
};

template<typename J>
Filter<J>::Filter()
{
}

template<typename J>
Filter<J>::~Filter()
{
}

//parameter &

//template<typename J, typename Iterator>
//inline void Filter<J>::filterData(Iterator begin, Iterator end, std::function<bool(UzemnaJednotka&)> predicate)
//{
//	ds::amt::ImplicitSequence<J> pom;
//	for (auto it = begin; it != end; ++it)
//	{
//		if (predicate(*it))
//		{
//			pom.insertLast().data_ = (*it);
//		}
//	}
//
//	for (auto a : pom) {
//		std::cout << a.getShortTitle() << std::endl;   //opytat sa na vracanie IS
//	}
//}