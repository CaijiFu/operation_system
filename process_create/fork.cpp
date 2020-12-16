#include<iostream>
#include<unistd.h>
using namespace std;
int main(){
    int i=0;
    cout<<"before fork"<<endl;
    pid_t pid=fork();
    cout<<"after fork"<<endl;
    if (pid < 0){
        cout<<"error"<<endl;
        return 1;
    }
    else if (pid == 0){
        cout<<"fork success,this is son process"<<endl;
        while (i<10){
            i += 1;
            cout<<"this is son process,i="<<i<<endl;
            sleep(1);
        }
    }
    else{
        cout<<"fork success,this is father process,son process id is" <<pid<<endl;
        while (i<10){
            i += 2;
            cout<<"this is father process,i="<<i<<endl;
            sleep(2);
        }
    }


    return 1;
}