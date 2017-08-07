#include <iostream>
#include<math.h>
#include<vector>
#include<set>
#include<algorithm>
#include "tree.h"
#include"matrix.h"

   vector<char*> combinedList(vector<tree> v1,vector<tree> v2);
   vector<char*>unionofarray(vector<char*> v1,vector<char*> v2);
   vector<float> frequencyVector(vector<char*>,tree v);
   float EuclideanDistance(vector<float> v1,vector<float> v2);
   vector< vector<float> > AdjacencyMatrixs(vector<tree> fileList);




vector<char*> combinedList(tree v1,tree v2){
    set<char*> s1;
    set<char*> s2;

    s1=v1.ListToVector();
    s2=v2.ListToVector();

   vector<char*> list1(s1.size());
   vector<char*> list2(s2.size());

   copy(s1.begin(),s1.end(),list1.begin());
   copy(s2.begin(),s2.end(),list2.begin());


    sort(list1.begin(),list1.end());
    sort(list2.begin(),list2.end());


   /*vector<char*> list3(list1.size()+list2.size());
   vector<char*>::iterator it= set_union(list1.begin(),list1.end(),list2.begin(),list2.end(),list3.begin());*/

   vector<char*> list3;
   list3 = unionofarray(list1,list2);


   //list3.resize(it-list3.begin());

   return list3;

   }


vector<char*> unionofarray(vector<char*> v1,vector<char*> v2)
{
     vector<char*>::const_iterator i = v1.begin();
     vector<char*>::const_iterator j = v2.begin();
     vector<char*> v;

     while(i < v1.end() && j < v2.end())
     {
        if(*i<*j){
        //cout<<*(i++)<<" ";
        v.push_back(*i++);
        }
        else if(*i>*j){
        //cout<<*(j++)<<" " ;
        v.push_back(*j++);}
     else
     {
        //cout<<*(i++)<<" ";
        v.push_back(*i++);
        j++;}

     }
     while(i<v1.end()){
     //cout<<*(i++)<<" ";
     v.push_back(*i++);}
     while(j<v2.end()){
     //cout<<*(j++)<<" ";
     v.push_back(*j++);}

     return v;
}


vector<float> frequencyVector(vector<char*> word,tree v){
    vector<float> freq;

    for(vector<char*>::iterator i = word.begin(); i != word.end(); ++i)
    {
        freq.push_back(v.FrequencyInFile(*i));
    }

    return freq;

    }



    float EuclideanDistance(vector<float> v1,vector<float> v2){
    float s;
    float dis=0;


    for(int i=0;i<v1.size();i++)
    {
        s= v1[i]-v2[i];
        //cout<<v1[i]<<"-"<<v2[i]<<"="<<s<<endl;
        dis=dis+pow(s,2);

    }

    return sqrt(dis);

}

vector< vector<float> > AdjacencyMatrixs(vector<tree> fileList){

     int n = fileList.size();
     Graph a(n);

     vector< vector<float> > distance;

     for(vector<tree>::const_iterator i = fileList.begin(); i != (fileList.end()-1); ++i){
     vector<float> d;
     d.push_back(0.000);

     for(int j=1;j<n;j++){

     vector<char*> cList;
     cList=(combinedList(*i,*(i+j)));

     vector<float> v1;
     v1= frequencyVector(cList,*i);
     vector<float> v2;
     v2= frequencyVector(cList,*(i+j));

     float dis = EuclideanDistance(v1,v2)/cList.size();
     //cout<<dis<<" ";
     d.push_back(dis);
     }

     distance.push_back(d);
     n--;
     }
     n = fileList.size();

     int k=0;
     for(vector< vector<float> >::const_iterator j = distance.begin(); j != distance.end(); ++j){
     int l=0+k;
     for(vector<float>::const_iterator i = (*j).begin(); i != (*j).end(); ++i){
     a.addEdge(*i,k,l);
     l++;
     }
     k++;
     }

     a.print();
     return distance;
}
