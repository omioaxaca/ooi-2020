#include<bits/stdc++.h>

using namespace std;
int n;
int m;
int d;
char mat[2000][2000];
struct nodo
{
    int x;
    int y;
    int pas;
};


vector<int> vecx= {-1, 0, 1, 0};
vector<int> vecy= { 0, 1, 0, -1};

void tiempo(nodo ini ){
    queue <nodo> cola;
    cola.push(ini);

    while( !cola.empty()){
        nodo actual= cola.front();
        cola.pop();
        mat[actual.x][actual.y]= '*';

        if( actual.pas== d){
            while( !cola.empty()){
                nodo actual= cola.front();
                cola.pop();
                mat[actual.x][actual.y]= '*';
            }
            return;
        }

        for(int i=0; i<4; i++){
            nodo sig;
            sig.x= actual.x+ vecx[i];
            sig.y= actual.y+ vecy[i];
            sig.pas= actual.pas+1;

            if(sig.x<0 || sig.x>=n || sig.y<0 || sig.y>=m ){
                continue;
            }

            if( mat[sig.x][sig.y]== '#' || mat[sig.x][sig.y]== '*'){
                continue;
            }
            cola.push( sig);

        }



    }


}



int main(){
    cin>> n>> m>>d;
    nodo z;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>> mat[i][j];
            if( mat[i][j]== '$'){
                z.x= i;
                z.y= j;
                z.pas=0;
            }
        }
    }

    tiempo(z);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if( i== z.x && j== z.y){
                cout<<'$';
            }else{
                cout<< mat[i][j];
            }
            
        }
        cout<<"\n";
    }
    


    return 0;
}