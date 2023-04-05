#include "hash_table.h"
#include <iostream>

HashTable::HashTable() {

}

HashTable::HashTable(int mode) {
    this->mode = mode;
    this->table = new std::vector<std::vector<int>> {{0}};
    this->elements = 0;
    this->table_size = 1;
    this->collisions = 0;
}

HashTable::~HashTable() {

}

void HashTable::resize() {
    std::vector<std::vector<int>> *temp_table = this->table;
    int temp_elements = this->elements;
    int temp_size = this->table_size;
    this->table = new std::vector<std::vector<int>>[2 * this->table_size];
    this->table_size = 2 * this->table_size;
    this->elements = 0;

    // Reinsert value into the new table
    for(int i = 0; i < temp_size; i++) {
        if ((*temp_table)[i][0] != 0) {
            insert((*temp_table)[i][0]);
        }
    }
}

// Continue down the table until an empty spot is found.
int HashTable::linear_probing(int data) {
    int key = data % this->table_size;
    int current_insert_collisions = 0;
    for (int i = 0; i < this->table_size; i++) {
        if ((this->table)[key][0][0] == 0) {

        }
    }

    std::cout << "Error: no insert location found for: " << data << std::endl;

    return current_insert_collisions;
}

// Use a second hash function based on how many collisions occur
int HashTable::double_hashing(int data){

}

// Append values into a list at the location of the collision
int HashTable::seperate_chaining(int data){

}

int HashTable::get_num_collisions() {
    return this->collisions;
}

void HashTable::insert(int data) {
    if (this->mode == 0) {
        this->collisions+= linear_probing(data);
    } else if (this->mode == 1) {
        this->collisions+= double_hashing(data);
    } else if (this->mode == 2) {
        this->collisions+= seperate_chaining(data);
    } else {
        std::cout << "Error, invalid mode.\nValid modes: 0, 1, 2\n";
    }
}

void HashTable::print_table() {

}