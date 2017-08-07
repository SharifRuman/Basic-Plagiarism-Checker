#include <iostream>
#include<string>
#include<cstring>
#include<vector>
#include<stack>
#include "tree.h"



using namespace std;

tree:: tree ()
{
	root= NULL;

	count=1;
}

void tree :: insert(char* word)
{
	insertItem(word,root);
}

void tree :: insertItem(char* word,bTree*& tree)
{
	if (tree == NULL)
	{
		tree=new bTree();
		tree->word=word;
		tree->index.insert(count);
		tree->left=NULL;
		tree->right=NULL;
		count++;
		//cout<<tree->word<<" ";
	}
	else if(strcmp(tree->word,word)==0)
	{
		tree->word=word;
		tree->index.insert(count);
		count++;

	}
	else if(strcmp(tree->word,word)>0)
	{
		insertItem(word,tree->right);
	}
	else
	{
		insertItem(word,tree->left);
	}

}


set<char*>  tree::ListToVector()
{
  return transferListToVector(root);
}

set<char*>  tree ::transferListToVector(bTree* tree)
{

   if(tree!=NULL)
   {
   if(tree->left!=NULL)
   {
   transferListToVector(tree->left);
   }

   wordSet.insert(tree->word);

   if(tree->right!=NULL)
   {
    transferListToVector(tree->right);
   }

   }

   return wordSet;

}




float tree :: FrequencyInFile(char* word)
{
   return wordFrequencyInFile(word,root);
}

float tree :: wordFrequencyInFile(char* word,bTree* tree)
{
   int total=count-1;
   float freq=0;

   if (wordInFile(word,tree))
   {
      while (tree != NULL)
      {
         if (tree->word == word)
            break;

         if (word > tree->word)
         {
            tree = tree->right;
         }
         else if (word < tree->word)
         {
            tree = tree->left;
         }
      }

     freq=(float)(tree->index.LengthIs())/total;
     cout<<freq<<"   ";
     return freq;
   }
   else
    return 0;

}

bool tree :: wordInFile(char* word,bTree*& tree)
{
     while (tree != NULL)
      {
         if (tree->word == word)
            return true;

         if (word > tree->word)
         {
            tree = tree->right;
         }
         else if (word < tree->word)
         {
            tree = tree->left;
         }
     }

     return false;


}



