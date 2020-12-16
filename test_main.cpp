#include<iostream>
using namespace std;
int main(int argc, char* argv[]){
    cout<<"命令总数"<<argc<<endl;
    for(int i=0; i!=argc;i++){
        cout<<"命名行输入为"<<i<<"："<<(argv[i])<<endl;
    }
    return 1;
}