#include <iostream>
#include <list>


class HashTable {
public:
	static const int num_buckets = 10;
	std::list<int> table[num_buckets]; // array of lists

	bool IsEmpty();

	int HashFunction(int key);


	void HashInsert(int index, int key);

	bool HashInsertLinearProbe(int key);
	void HashRemoveLinearProbe(int key);

};

bool HashTable::IsEmpty() {

	for (const auto& bucket : table) {
		if (!bucket.empty()) {
			return false;
		}
	}
	
	return true;
}

int HashTable::HashFunction(int key) {
	return key % num_buckets;
}

void HashTable::HashInsert(int index, int key) {
	this->table[index].push_back(key);
}

bool HashTable::HashInsertLinearProbe(int key) {

	int iBucket = this->HashFunction(key); 	// Find initial bucket index
	int BucketsProbed = 0;

	while (BucketsProbed < num_buckets) {

		if (table[iBucket].empty()) { // If the bucket is empty
			table[iBucket].push_back(key);
			printf("Linear Probe Successful Key: %i, Index: %i\n", key, iBucket);
			return true;
		}

		iBucket = (iBucket + 1) % 10; // Increment index;

		BucketsProbed++;
	}

	printf("Linear Probe Failed Key: %i, Index: %i\n", key, iBucket);
	return false;
}

void HashTable::HashRemoveLinearProbe(int key) {

	int iBucket = this->HashFunction(key);
	int BucketsProbed = 0;

}

int main() {
	
	// Each bucket is a list of integers
	HashTable* Table = new HashTable;

	int key = 6; int key2 = 16;

	printf("Key: %i, Index: %i\n", key, Table->HashFunction(key));
	printf("Key: %i, Index: %i\n", key2, Table->HashFunction(key2));

	Table->HashInsertLinearProbe(key);
	Table->HashInsertLinearProbe(key2);


	system("pause");
	return 0;
}