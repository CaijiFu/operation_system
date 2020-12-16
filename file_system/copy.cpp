#include<fstream>
#include<exception>
#include<string>
#include<iostream>
using namespace std;

int main(int argc, char* argv[]){
    fstream in, out;
    try{
        if(argc!=3) throw invalid_argument("you must enter proper arguments!");
        in.open(argv[1]);
        if(!in) throw runtime_error("file open failed");
        out.open(argv[2], fstream::out);
        if(!out) throw runtime_error("file create failed");
        string buffer;
        in>>buffer;
        out<<buffer;
    }
    catch(invalid_argument err){
        cout<<err.what()<<endl;
        in.close();
    }
    catch(runtime_error err){
        cout<<err.what()<<endl;
        in.close();
        out.close();
    }
    return 1;
}