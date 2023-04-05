#pragma once
#include <vector>

// Max limit of table usage before resize, as a percentage
const int TABLE_LIMIT = 70;

class HashTable{
    private:
        int collisions;
        int mode;
        int table_size;
        int elements;
        std::vector<std::vector<int>> *table;

        void resize();
        

        // Collision resolution methods
        int linear_probing(int data);
        int double_hashing(int data);
        int seperate_chaining(int data);


    public:
        HashTable();
        HashTable(int mode);
        ~HashTable();

        int get_num_collisions();

        void insert(int data);

        void print_table();

        
};