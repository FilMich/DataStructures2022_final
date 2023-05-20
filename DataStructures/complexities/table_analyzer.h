#pragma once
#include <libds/adt/list.h>
#include <complexities/complexity_analyzer.h>
#include <random>
#include <libds/adt/table.h>

namespace ds::utils
{
    template<class Table>
    class TableAnalyzer : public ComplexityAnalyzer<Table>
    {
    public:
        explicit TableAnalyzer(const std::string& name);

    protected:
        void beforeOperation(Table& table) override;
        void afterReplication(Table& table) override;
        void executeOperation(Table& table) override;

    private:
        void insertNElements(Table& table, size_t n);

    private:
        ds::adt::ImplicitList<int> list_;
        std::default_random_engine indexRnd_;
        std::default_random_engine keyRnd_;
        std::default_random_engine keyRndNonDup_;

        int key_;
    };

    class TablesAnalyzer : public CompositeAnalyzer
    {
    public:
        TablesAnalyzer() :
            CompositeAnalyzer("Tables")
        {
            //this->addAnalyzer(std::make_unique<TableAnalyzer<ds::adt::UnsortedESTab<int, int>>>("uest-contains"));
            //this->addAnalyzer(std::make_unique<TableAnalyzer<ds::adt::UnsortedISTab<int, int>>>("uist-contains"));
            //this->addAnalyzer(std::make_unique<TableAnalyzer<ds::adt::SortedSequenceTable<int, int>>>("sst-contains"));

            //this->addAnalyzer(std::make_unique<TableAnalyzer<ds::adt::Treap<int, int>>>("Treap-insertDupp"));
            this->addAnalyzer(std::make_unique<TableAnalyzer<ds::adt::Treap<int, int>>>("Treap-tryFindDupp"));
        }
    };

    

    template<class Table>
    inline TableAnalyzer<Table>::TableAnalyzer(const std::string& name) :
        ComplexityAnalyzer<Table>(name, [&](Table& table, size_t n)
        {
            this->insertNElements(table, n);
        }),
        list_(),
        indexRnd_(std::random_device()()),
        keyRnd_(std::random_device()()),
        key_(0)
    {
    }
    template<class Table>
    inline void TableAnalyzer<Table>::beforeOperation(Table& table)
    {
        //std::uniform_int_distribution<size_t> indexDist(0, this->list_.size() - 1);

        //this->key_ = this->list_.access(indexDist(indexRnd_));

        std::uniform_int_distribution<size_t> indexDist(this->list_.size() - 1, INT_MAX);

        this->key_ = indexDist(this->keyRndNonDup_);
    }
    template<class Table>
    inline void TableAnalyzer<Table>::afterReplication(Table& table)
    {
        this->list_.clear();
    }
    template<class Table>
    inline void TableAnalyzer<Table>::executeOperation(Table& table)
    {
        table.insert(this->key_, this->key_);
        //table.find(this->key_);
        //int* i = nullptr;
        //table.tryFind(this->key_, i);
        //table.contains(this->key_);
        //table.tryFindDupp(this->key_, out_);
    }
    template<class Table>
    inline void TableAnalyzer<Table>::insertNElements(Table& table, size_t n)
    {
        
        std::uniform_int_distribution<int> keyDist(INT_MIN, INT_MAX);

        for (size_t i = 0; i < n; i++)
        {   
            int key = keyDist(this->keyRnd_);

            int data = key;

            try
            {
                table.insert(key, data);
                //table.insertDupp(key, data);
                this->list_.insertLast(key);
            }
            catch (...)
            {
                i--;
            }
        }
    }
}