#include<iostream>
#include<string.h>
#include<fstream>
#include<cstdlib>
#include<vector>
#include "tree.h"
#include "Functions.h"
using namespace std;



tree readFromFile(string fileName);
tree  wordsFromFile(string fileName);
vector< vector<float> > AdjacencyMatrixs(vector<tree> fileList);



/*int main(int argc, char *argv[])
{
    int n=argc;
    string a[n];
    vector<tree> fileList;
    for(int i=1;i<argc;i++){

    fileList.push_back(readFromFile(argv[i]));
    a[i-1]=argv[i];

    }
vector< vector<float> > distance;
distance= AdjacencyMatrixs(fileList);

ofstream myfile;
myfile.open ("a.html");


myfile<<"<!doctype html>"<<endl;
myfile<<"<html>"<<endl;
myfile<<"<head>"<<endl;
myfile<<"<title>Visual Rendering of the Graph</title>\n<script type = ";
myfile<<'"';
myfile<<"text/javascript";
myfile<<'"';
myfile<<"src = ";
myfile<<'"';
myfile<<"http://visjs.org/dist/vis.js";
myfile<<'"';
myfile<<"></script>\n<link href = ";
myfile<<'"';
myfile<<"http://visjs.org/dist/vis-network.min.css";
myfile<<'"';
myfile<<" rel = ";
myfile<<'"';
myfile<<"stylesheet";
myfile<<'"';
myfile<<" type = ";
myfile<<'"';
myfile<<"text/css";
myfile<<'"'<<"/>"<<endl;
myfile<<"<style type = ";
myfile<<'"';
myfile<<"text/css";
myfile<<'"'<<">"<<endl;
myfile<<"#mynetwork{"<<endl;
myfile<<"width: 600px;"<<endl;
myfile<<"height: 400px;"<<endl;
myfile<<"border: 1px solid lightgray;"<<endl;
myfile<<"}"<<endl;
myfile<<"</style>"<<endl;
myfile<<"</head>"<<endl;
myfile<<"<body>"<<endl;
myfile<<"<p>"<<endl<<"A simple network with file nodes and their distances."<<endl<<"</p>"<<endl;
myfile<<"<div id = ";
myfile<<'"';
myfile<<"mynetwork";
myfile<<'"'<<"></div>"<<endl;
myfile<<"<script type = "<<'"'<<"text/javascript"<<'"'<<">"<<endl;
myfile<<"var nodes = new vis.DataSet(["<<endl;

for(int i=0;i<n-1;i++){
myfile<<"{id: "<<i+1<<", label : "<<"'"<<a[i]<<"'"<<" },"<<endl;
}




myfile<<"]);"<<endl;
myfile<<"var edges = new vis.DataSet(["<<endl;


int k=0;
     for(vector< vector<float> >::const_iterator j = distance.begin(); j != distance.end(); ++j){
     int l=0+k;
     for(vector<float>::const_iterator i = (*j).begin(); i != (*j).end(); ++i){
     myfile<< "{from : " << k+1 << ", label : " << (*i) << ", to : " << l+1 << "}," <<endl;
     l++;
     }
     k++;
     }


myfile<<"]);"<<endl;
myfile<<"var container = document.getElementById('mynetwork');"<<endl;
myfile<<"var data = {"<<endl;
myfile<<"nodes: nodes,"<<endl;
myfile<<"edges : edges"<<endl;
myfile<<"};"<<endl;
myfile<<"var options = {};"<<endl;
myfile<<"var network = new vis.Network(container, data, options);"<<endl;
myfile<<"</script>"<<endl;
myfile<<"</body>"<<endl;
myfile<<"</html>"<<endl;




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
    string a[n];

    for(int i=0;i<n;i++){

	cout << "Enter your file name:";

	cin >> fileName;
	a[i]=fileName;

    fileList.push_back(readFromFile(fileName));

    }

vector< vector<float> > distance;
distance= AdjacencyMatrixs(fileList);

ofstream myfile;
myfile.open ("a.html");


myfile<<"<!doctype html>"<<endl;
myfile<<"<html>"<<endl;
myfile<<"<head>"<<endl;
myfile<<"<title>Visual Rendering of the Graph</title>\n<script type = ";
myfile<<'"';
myfile<<"text/javascript";
myfile<<'"';
myfile<<"src = ";
myfile<<'"';
myfile<<"http://visjs.org/dist/vis.js";
myfile<<'"';
myfile<<"></script>\n<link href = ";
myfile<<'"';
myfile<<"http://visjs.org/dist/vis-network.min.css";
myfile<<'"';
myfile<<" rel = ";
myfile<<'"';
myfile<<"stylesheet";
myfile<<'"';
myfile<<" type = ";
myfile<<'"';
myfile<<"text/css";
myfile<<'"'<<"/>"<<endl;
myfile<<"<style type = ";
myfile<<'"';
myfile<<"text/css";
myfile<<'"'<<">"<<endl;
myfile<<"#mynetwork{"<<endl;
myfile<<"width: 600px;"<<endl;
myfile<<"height: 400px;"<<endl;
myfile<<"border: 1px solid lightgray;"<<endl;
myfile<<"}"<<endl;
myfile<<"</style>"<<endl;
myfile<<"</head>"<<endl;
myfile<<"<body>"<<endl;
myfile<<"<p>"<<endl<<"A simple network with file nodes and their distances."<<endl<<"</p>"<<endl;
myfile<<"<div id = ";
myfile<<'"';
myfile<<"mynetwork";
myfile<<'"'<<"></div>"<<endl;
myfile<<"<script type = "<<'"'<<"text/javascript"<<'"'<<">"<<endl;
myfile<<"var nodes = new vis.DataSet(["<<endl;
for(int i=0;i<n;i++){
myfile<<"{id: "<<i+1<<", label : "<<"'"<<a[i]<<"'"<<" },"<<endl;
}

myfile<<"]);"<<endl;
myfile<<"var edges = new vis.DataSet(["<<endl;


int k=0;
     for(vector< vector<float> >::const_iterator j = distance.begin(); j != distance.end(); ++j){
     int l=0+k;
     for(vector<float>::const_iterator i = (*j).begin(); i != (*j).end(); ++i){
     myfile<< "{from : " << k+1 << ", label : " << (*i) << ", to : " << l+1 << "}," <<endl;
     l++;
     }
     k++;
     }


myfile<<"]);"<<endl;
myfile<<"var container = document.getElementById('mynetwork');"<<endl;
myfile<<"var data = {"<<endl;
myfile<<"nodes: nodes,"<<endl;
myfile<<"edges : edges"<<endl;
myfile<<"};"<<endl;
myfile<<"var options = {};"<<endl;
myfile<<"var network = new vis.Network(container, data, options);"<<endl;
myfile<<"</script>"<<endl;
myfile<<"</body>"<<endl;
myfile<<"</html>"<<endl;




    return 0;
 }
