#pragma once

#include <libds/amt/abstract_memory_type.h>
#include <libds/amt/sequence.h>

namespace ds::amt {

	template<typename DataType>
	class ImplicitSequence :
		public Sequence<MemoryBlock<DataType>>,				//sekvencia ktora spravuva v kt budu nejake bloky
		public ImplicitAMS<DataType>
	{
	public:
		using BlockType = MemoryBlock<DataType>;

		ImplicitSequence();
		ImplicitSequence(size_t capacity, bool initBlocks);
		ImplicitSequence(const ImplicitSequence<DataType>& other);
		~ImplicitSequence() override;

		size_t calculateIndex(BlockType& block) override;

		BlockType* accessFirst() const override;
		BlockType* accessLast() const override;
		BlockType* access(size_t index) const override;
		BlockType* accessNext(const BlockType& block) const override;
		BlockType* accessPrevious(const BlockType& block) const override;

		BlockType& insertFirst() override;
		BlockType& insertLast() override;
		BlockType& insert(size_t index) override;
		BlockType& insertAfter(BlockType& block) override;
		BlockType& insertBefore(BlockType& block) override;

		void removeFirst() override;
		void removeLast() override;
		void remove(size_t index) override;
		void removeNext(const BlockType& block) override;
		void removePrevious(const BlockType& block) override;

		void reserveCapacity(size_t capacity);

		virtual size_t indexOfNext(size_t currentIndex) const;
		virtual size_t indexOfPrevious(size_t currentIndex) const;

	public:
		class ImplicitSequenceIterator
		{
		public:
			ImplicitSequenceIterator(ImplicitSequence<DataType>* sequence, size_t index);
			ImplicitSequenceIterator(const ImplicitSequenceIterator& other);
			ImplicitSequenceIterator& operator++();
			ImplicitSequenceIterator operator++(int);
			bool operator==(const ImplicitSequenceIterator& other) const;
			bool operator!=(const ImplicitSequenceIterator& other) const;
			DataType& operator*();

		private:
			ImplicitSequence<DataType>* sequence_;
			size_t position_;
		};

		ImplicitSequenceIterator begin();
		ImplicitSequenceIterator end();

		using IteratorType = ImplicitSequenceIterator;
	};

	template<typename DataType>
	using IS = ImplicitSequence<DataType>;

	//----------

	template<typename DataType>
	class CyclicImplicitSequence : public IS<DataType>
	{
	public:
		CyclicImplicitSequence();
		CyclicImplicitSequence(size_t initSize, bool initBlocks);

		size_t indexOfNext(size_t currentIndex) const override;
		size_t indexOfPrevious(size_t currentIndex) const override;
	};

	template<typename DataType>
	using CIS = CyclicImplicitSequence<DataType>;

	//----------

	template<typename DataType>
	ImplicitSequence<DataType>::ImplicitSequence()
	{
	}

	template<typename DataType>
	ImplicitSequence<DataType>::ImplicitSequence(size_t initialSize, bool initBlocks) :
		ImplicitAMS<DataType>(initialSize, initBlocks)
	{
	}

	template<typename DataType>
	ImplicitSequence<DataType>::ImplicitSequence(const ImplicitSequence<DataType>& other) :
		ImplicitAMS<DataType>::ImplicitAbstractMemoryStructure(other)
	{
	}

	template<typename DataType>
	ImplicitSequence<DataType>::~ImplicitSequence()
	{
	}

	template<typename DataType>
	size_t ImplicitSequence<DataType>::calculateIndex(BlockType& block)
	{
		return this->getMemoryManager()->calculateIndex(block);
	}

	template<typename DataType>
	auto ImplicitSequence<DataType>::accessFirst() const -> BlockType*
	{
		return this->size() > 0 ? & this->getMemoryManager()->getBlockAt(0) : nullptr;
	}

	template<typename DataType>
	auto ImplicitSequence<DataType>::accessLast() const -> BlockType*
	{
		size_t size = this->size();
		return size > 0 ? &this->getMemoryManager()->getBlockAt(size -1 ) : nullptr;	//POSLEDNY BLOK JE size -1
	}

	template<typename DataType>
	auto ImplicitSequence<DataType>::access(size_t index) const -> BlockType*
	{
		/*if (index < this->size()) {
			return &this->getMemoryManager()->getBlockAt(index);

		}
		else {
			return nullptr;
		}*/

		return index < this->size() ? &this->getMemoryManager()->getBlockAt(index) : nullptr;
		
	}

	template<typename DataType>
	auto ImplicitSequence<DataType>::accessNext(const BlockType& block) const -> BlockType*
	{
		/*size_t index = this->getMemoryManager()->calculateIndex(block);
		size_t nextIndex = this->indexOfNext(index);

		if (nextIndex != INVALID_INDEX) {
			return &this->getMemoryManager()->getBlockAt(nextIndex);
		}
		else {
			return nullptr;
		}*/

		typename ImplicitAMS<DataType>::MemoryManagerType* memManager = this->getMemoryManager();
		const size_t index = indexOfNext(memManager->calculateIndex(block));
		return index < this->size() ? &memManager->getBlockAt(index) : nullptr;

	}

	template<typename DataType>
	auto ImplicitSequence<DataType>::accessPrevious(const BlockType& block) const -> BlockType*
	{
		/*size_t index = this->getMemoryManager()->calculateIndex(block);
		size_t nextIndex = this->indexOfPrevious(index);

		if (nextIndex != INVALID_INDEX) {
			return &this->getMemoryManager()->getBlockAt(nextIndex);
		}
		else {
			return nullptr;
		}*/

		typename ImplicitAMS<DataType>::MemoryManagerType* memManager = this->getMemoryManager();
		const size_t index = indexOfPrevious(memManager->calculateIndex(block));
		return index != INVALID_INDEX ? &memManager->getBlockAt(index) : nullptr;

	}

	template<typename DataType>
	auto ImplicitSequence<DataType>::insertFirst() -> BlockType&
	{
		return *this->getMemoryManager()->allocateMemoryAt(0);
		//return this->insert(0);
	}

	template<typename DataType>
	auto ImplicitSequence<DataType>::insertLast() -> BlockType&
	{
		
		//return this->insert(this->size());
		return *this->getMemoryManager()->allocateMemory();

	}

	template<typename DataType>
	auto ImplicitSequence<DataType>::insert(size_t index) -> BlockType&			// BlockType& sa vlozi do auto
	{
		/*if (index <= this->size()) {
			return *(this->getMemoryManager()->allocateMemoryAt(index));
		}
		else {
			throw std::out_of_range("ImplicitSequence<DataType>::insert(size_t index)");
		}*/
		
		return *this->getMemoryManager()->allocateMemoryAt(index);

	}

	template<typename DataType>
	auto ImplicitSequence<DataType>::insertAfter(BlockType& block) -> BlockType&
	{
		
		//size_t index = this->getMemoryManager()->calculateIndex(block);
		//if (index != INVALID_INDEX) {
		//	size_t nextIndex = this->indexOfNext(index);		//moze mi vratit invalud index  VRATIT SA 
		//	if (nextIndex != INVALID_INDEX)
		//	{
		//		return this->insert(nextIndex);
		//	}
		//	else
		//	{
		//		this->insertLast();
		//	}
		//	
		//}
		//else {
		//	throw std::out_of_range("auto ImplicitSequence<DataType>::insertAfter(const BlockType& block) -> BlockType&");
		//}

		typename ImplicitAMS<DataType>::MemoryManagerType* memManager = this->getMemoryManager();
		return *memManager->allocateMemoryAt(memManager->calculateIndex(block) + 1);

	}

	template<typename DataType>
	auto ImplicitSequence<DataType>::insertBefore(BlockType& block) -> BlockType&
	{
		//check range - ale ved ->calculateIndex(block) robi kontrolu?

		return *this->getMemoryManager()->allocateMemoryAt(this->getMemoryManager()->calculateIndex(block));

	}

	template<typename DataType>
	void ImplicitSequence<DataType>::removeFirst()
	{
		/*if (this->size() > 0) {
			this->getMemoryManager()->releaseMemoryAt(0);
		}*/

		this->getMemoryManager()->releaseMemoryAt(0);

	}

	template<typename DataType>
	void ImplicitSequence<DataType>::removeLast()
	{
		this->getMemoryManager()->releaseMemory();
		
	}

	template<typename DataType>
	void ImplicitSequence<DataType>::remove(size_t index)
	{
		if (this->size() > 0 && index < this->size()) {
			this->getMemoryManager()->releaseMemoryAt(index);
		}
	}

	template<typename DataType>
	void ImplicitSequence<DataType>::removeNext(const BlockType& block)
	{
		/*if (this->size() > 0) {
			this->getMemoryManager()->releaseMemoryAt((this->getMemoryManager()->calculateIndex(block))+1);
		}*/

		this->getMemoryManager()->releaseMemoryAt(indexOfNext(this->getMemoryManager()->calculateIndex(block)));

	}

	template<typename DataType>
	void ImplicitSequence<DataType>::removePrevious(const BlockType& block)
	{
		if (this->size() > 0) {
			this->getMemoryManager()->releaseMemoryAt((this->getMemoryManager()->calculateIndex(block)) - 1);
		}
	}

	template<typename DataType>
	void ImplicitSequence<DataType>::reserveCapacity(size_t capacity)
	{
		this->getMemoryManager()->changeCapacity(capacity);
	}

	template<typename DataType>
	size_t ImplicitSequence<DataType>::indexOfNext(size_t currentIndex) const
	{


		//if (currentIndex + 1 < this->size() - 1) { //+1 lebooo size_t = 0  kebyze -1 tak by ho preklopilo na vysoke cislo
		//	return currentIndex + 1;
		//}
		//else {
		//	return INVALID_INDEX; //NIE -1 lebo size_t nepozna zaporne cisla
		//}
		return currentIndex >= this->size() - 1 ? INVALID_INDEX : currentIndex + 1;

	}

	template<typename DataType>
	size_t ImplicitSequence<DataType>::indexOfPrevious(size_t currentIndex) const
	{
		if (currentIndex > 0) {	
			return currentIndex  -1;				
		}
		else {
			return INVALID_INDEX; //NIE -1 lebo size_t nepozna zaporne cisla
		}


	}

	template <typename DataType>
	ImplicitSequence<DataType>::ImplicitSequenceIterator::ImplicitSequenceIterator
	(ImplicitSequence<DataType>* sequence, size_t index) :
		sequence_(sequence),
		position_(index)
	{
	}

	template <typename DataType>
	ImplicitSequence<DataType>::ImplicitSequenceIterator::ImplicitSequenceIterator
	(const ImplicitSequenceIterator& other) :
		sequence_(other.sequence_),
		position_(other.position_)
	{
	}

	template <typename DataType>
	auto ImplicitSequence<DataType>::ImplicitSequenceIterator::operator++() -> ImplicitSequenceIterator&
	{
		++this->position_;
		return *this;
	}

	template <typename DataType>
	auto ImplicitSequence<DataType>::ImplicitSequenceIterator::operator++(int) -> ImplicitSequenceIterator
	{
		ImplicitSequenceIterator tmp(*this);
		operator++();
		return tmp;
	}

	template <typename DataType>
	bool ImplicitSequence<DataType>::ImplicitSequenceIterator::operator==(const ImplicitSequenceIterator& other) const
	{
		return this->sequence_ == other.sequence_ && this->position_ == other.position_;
	}

	template <typename DataType>
	bool ImplicitSequence<DataType>::ImplicitSequenceIterator::operator!=(const ImplicitSequenceIterator& other) const
	{
		return !(*this == other);
	}

	template <typename DataType>
	DataType& ImplicitSequence<DataType>::ImplicitSequenceIterator::operator*()
	{
		return this->sequence_->access(this->position_)->data_;
	}

	template <typename DataType>
	auto ImplicitSequence<DataType>::begin() -> ImplicitSequenceIterator
	{
		return ImplicitSequenceIterator(this, 0);
	}

	template <typename DataType>
	auto ImplicitSequence<DataType>::end() -> ImplicitSequenceIterator
	{
		return ImplicitSequenceIterator(this, ImplicitAbstractMemoryStructure<DataType>::size());
	}

	template<typename DataType>
	CyclicImplicitSequence<DataType>::CyclicImplicitSequence() :
		IS<DataType>()
	{
	}

	template<typename DataType>
	CyclicImplicitSequence<DataType>::CyclicImplicitSequence(size_t initCapacity, bool initBlocks) :
		IS<DataType>(initCapacity, initBlocks)
	{
	}

	template<typename DataType>
	size_t CyclicImplicitSequence<DataType>::indexOfNext(size_t currentIndex) const
	{
		/*if (this->size() > 0)
		{
			return (currentIndex + 1) % this->size();
		}
		else
		{
			return INVALID_INDEX;
		}*/
		size_t size = this->size();
		return size != 0 ? currentIndex >= size - 1 ? 0 : currentIndex + 1 : INVALID_INDEX;
	}

	template<typename DataType>
	size_t CyclicImplicitSequence<DataType>::indexOfPrevious(size_t currentIndex) const
	{
		/*if (this->size() > 0)
		{
			return currentIndex > 0 ? currentIndex - 1 : this->size() - 1;
		}
		else
		{
			return INVALID_INDEX;
		}*/
		size_t size = this->size();
		return size != 0 ? currentIndex <= 0 ? size - 1 : currentIndex - 1 : INVALID_INDEX;
	}

}