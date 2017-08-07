#include<iostream>
#include<string.h>
#include<fstream>
#include<cstdlib>
#include<vector>
#include "tree.h"
#include"Functions.h"
using namespace std;



tree readFromFile(string fileName);
tree  wordsFromFile(string fileName);





/*int main(int argc, char *argv[])
{
    vector<tree> fileList;
    for(int i=0;i<argc;i++){

    fileList.push_back(readFromFile(argv[i]));

    }

   AdjacencyMatrix(fileList);

    return 0;
}*/


// read file


tree readFromFile(string fileName) {

	try
    {
       ifstream file;
       file.open(fileName.c_str());
       if(file.fail())
       {
        	throw 404;
       }
       else
       {
        return wordsFromFile(fileName);
       }

    }
    catch(int e)
    {

        cout<< "\t"<<e <<endl;
        cout<<"!!! File is NOT found!!!"<<endl<<"---------SORRY---------"<<endl;

    }
}

tree wordsFromFile(string fileName) {

	ifstream file;
    file.open(fileName.c_str());

  	int i=0;
    string f;

    tree t;

    while(getline(file,f))
    {
        char *copy,*split;
        copy=strdup(f.c_str());
        split=strtok(copy," ,.:;?-_(){}[]=+*&$#@!/%^&1234567890");

        while (split != NULL)
        {
            while(split[i])
            {
              split[i]=tolower(split[i]);
              i++;
            }
            i=0;
            t.insert(split);
            split=strtok(NULL," ,.:;?-_(){}[]=+*&$#@!/%^&1234567890");
        }
	}

  cout<<"Okay"<<endl;
  cout<<""<< endl;
  return t;

}







int main()
{
    string fileName;
    int n;
    vector<tree> fileList;
    cout << "Enter number of file:";
    cin>>n;
    cout<<""<<endl;

    for(int i=0;i<n;i++){

	cout << "Enter your file name:";

	cin >> fileName;

    fileList.push_back(readFromFile(fileName));

    }

   AdjacencyMatrix(fileList);

    return 0;
 }
