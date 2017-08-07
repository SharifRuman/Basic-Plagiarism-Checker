#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
#include<vector>
#include<set>
#include "linklist.h"

using namespace std;


class tree
{

	struct bTree
	{
		char* word;
		linklist index;
		bTree* left;
		bTree* right;
	};

	private:
		bTree* root;
		int count;



	public:

		tree();
		void insert(char* word);
		void insertItem(char* word,bTree*& tree);
		void display();
		void displayItem(bTree* tree);
		float wordFrequencyInFile(char* word,bTree* tree);
		set<char*> ListToVector();
		set<char*> transferListToVector(bTree* tree);
		float FrequencyInFile(char* word);
        set<char*> wordSet;
        bool wordInFile(char* word,bTree*& tree);

};

#endif // TREE_H_INCLUDED
