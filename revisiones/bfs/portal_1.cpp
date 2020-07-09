#include<bits/stdc++.h>

using namespace std;

int mini= 300000; // Este limite es muy bajo. Siempre es mejor utilizar limites muy grandes, por ejemplo 2^31 -1 = 2,147,483,647
                  // Pero de preferencia incluye la libreria <climits> y usa INT_MAX
int n,m;
int k, l;
char mat[2000][2000];
bool ya[2000][2000]= {};

struct nodo{
    int x;
    int y;
    int pas;

};

nodo pre;

vector<int> vecx= {-1, 0, 1, 0};
vector<int> vecy= { 0, 1, 0, -1};

void portal(nodo ini){
    queue<nodo> cola;
    cola.push(ini);

    while(!cola.empty()){
        nodo actual;
        actual= cola.front();
        cola.pop();

        // Aqui debes revisar si la respuesta ya fue encontrada.


        for(int i=0; i<4; i++){
            nodo sig;
            sig.x= actual.x+ vecx[i];
            sig.y= actual.y+ vecy[i];
            sig.pas= actual.pas+1;

            if(sig.x<0 || sig.x>=n || sig.y<0 || sig.y>=m ){
                continue;
            }
            if(ya[sig.x][sig.y]== true){
                continue;
            }
            

            if( mat[sig.x][sig.y]== '#' ){
                pre = actual;
                pre.pas++; // Sumar 1 porque necesitas un paso para atravesar el portal.if(mat[pre.x][pre.y]=='X'){
                
                // Esta comprobacion la debes hacer al principio de la busqueda.

                // if(mat[pre.x][pre.y]=='X'){
                // if( pre.pas<= mini){ 
                //     mini= pre.pas;
                // }
            
                // }
                while( mat[pre.x][pre.y] != '#'){
                    pre.x--;
                }
                pre.x++;
                if(ya[pre.x][pre.y] != true ){
                    ya[pre.x][pre.y]= true;
                    cola.push(pre);
                }
                

                pre = actual;
                pre.pas++; // Sumar 1 porque necesitas un paso para atravesar el portal.
                while( mat[pre.x][pre.y] != '#'){
                    pre.y--;
                }
                pre.y++;
                if(ya[pre.x][pre.y] != true ){
                    ya[pre.x][pre.y]= true;
                    cola.push(pre);
                }

                pre = actual;
                pre.pas++; // Sumar 1 porque necesitas un paso para atravesar el portal.
                while( mat[pre.x][pre.y] != '#'){
                    pre.x++;
                }
                pre.x--;
                if(ya[pre.x][pre.y] != true ){
                    ya[pre.x][pre.y]= true;
                    cola.push(pre);
                }

                pre = actual;
                pre.pas++; // Sumar 1 porque necesitas un paso para atravesar el portal.
                while( mat[pre.x][pre.y] != '#'){
                    pre.y++;
                }
                pre.y--;
                if(ya[pre.x][pre.y] != true ){
                    ya[pre.x][pre.y]= true;
                    cola.push(pre);
                }
            }

            if(mat[sig.x][sig.y]== '#'){
                continue;
            }

            
            // Esta comprobacion deberia estar al principio de la busqueda.
            if(mat[sig.x][sig.y]=='X'){
                if( sig.pas<= mini){
                    mini= sig.pas;
                    return; // En BFS una vez que encuentras el resultado debes terminar la busqueda.
                }
            
            }
            ya[sig.x][sig.y]= true;
            cola.push(sig);

            

        }



    }



}


int main(){
    cin>> n>> m;
    nodo z;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>> mat[i][j];
            if(mat[i][j] == 'O'){
                z.x= i;
                z.y= j;
                z.pas=0;
            }
            
        }
    }

    portal(z);

    cout<< mini; // Trata de evitar sumar o restar al resultado para que te de el valor esperado
                 // Por lo general, si el valor no es exacto aqui significa que hay un error en las operaciones de la busqueda.



    return 0;
}