#include<bits/stdc++.h>
using namespace std ;

#define MAX 100000

unordered_map<string,int> dict(MAX) ;

unordered_map<int , string> dict2(MAX) ;

string getFileName(string file)
{
    string name = "" ;
    int len = file.length() ;
    for(int i=0 ;i<len ;i++){
        if(file[i]=='.' || file[i]=='_')break ;
        name+=file[i] ;
    }
    return name ;
}

string getBinary(int num)
{
    string result = bitset<12>(num).to_string();
    return result;
}

void compress(string file)
{
    int num = 9 ;
    string fileName = getFileName(file) ;
    fileName+="_compressed" ;
    ofstream outFile ;
    outFile.open(fileName+".txt") ;
    ifstream inFile ;
    inFile.open(file) ;

    for(int unsigned i= 0 ;i<256 ;i++){
        dict[string(1,i)] = i ;
    }

    string cr_str ="" ;
    int code , nxtCode=256 ;
    char ch ;
    string line ;
    int x= 0 ;
    while(getline(inFile,line))
    {
        int len = line.length() ;
        for(int i=0 ;i<=len ;i++){
            ch = line[i] ;
            if(i==len)ch='\n' ;
            cr_str +=ch ;
            if(dict.find(cr_str)==dict.end()){
                if(nxtCode<=MAX){
                    dict.insert(make_pair(cr_str,nxtCode++)) ;
                    cr_str.erase(cr_str.size()-1) ;
                    //string bin = getBinary(dict[cr_str]) ;
                    //outFile<<bin<<" " ;
                    outFile<<dict[cr_str]<<" " ;x++ ;
                    cr_str = ch ;
                }
            }
        }
        //
    }
    cout<<x<<endl ;

    dict.clear() ;
    outFile.close() ;
    inFile.close() ;
}


void decompress(string file)
{

    ifstream inFile ;
    inFile.open(file) ;

    string fileName = getFileName(file) ;
    fileName+="_decompressed" ;

    ofstream outFile ;
    outFile.open(fileName+".txt") ;

    for(int unsigned i= 0 ;i<256 ;i++){
        dict2[i] = string(1,i) ;
    }

    string pre_str ;
    unsigned int code ;
    unsigned int nxtCode = 256 ;
    int x= 0 ;

    while(inFile>>code)
    {
        x++ ;
        if(dict2.find(code)==dict2.end()){
            dict2.insert(make_pair(code,pre_str+pre_str[0])) ;
        }

        outFile<<dict2[code] ;
        //string bin = getBinary(dict[cr_str]) ;
        //outFile<<bin<<" " ;
        if(pre_str.length()){
            dict2.insert(make_pair(nxtCode++,pre_str+dict2[code][0])) ;
        }
        pre_str = dict2[code] ;
    }
    cout<<x<<endl ;
    outFile.close() ;
    inFile.close() ;
    dict2.clear() ;
}


int main()
{
    cout<<"enter a txt file to compress::";
    string file ;
    int choice ;

    cout<<"What to do ::\n1. Compress\n2. Decompress"<<endl ;
    cin>>choice ;getchar() ;
    if(choice==1){
        cout<<"inter file name:" ;
        cin>>file;
        compress(file) ;
    }
    if(choice==2){
        cout<<"inter file name:" ;
        cin>>file;
        decompress(file) ;
    }
    else cout<<"Instruction..." ;
    return 0 ;
}
