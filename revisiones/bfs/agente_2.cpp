#include <bits/stdc++.h>
#define TAM 2003

using namespace std;
int m,n;
char mapa[TAM][TAM];
int pas[TAM][TAM];
int mayor=0;

vector<int> mov_x = {-1, 0, 1,  0};
vector<int> mov_y = { 0, 1, 0, -1};

struct cord
{
    int x;
    int y;
    int pasos;
};

bool valido(cord act){
    if (act.x<0||act.x>=m||act.y<0||act.y>=n)
    {
        return false;
    }
    if (mapa[act.x][act.y]=='#')
    {
        return false;
    }
    if (mapa[act.x][act.y]=='G')
    {
        return false;
    }
    
    if (pas[act.x][act.y]!=0)
    {
        return false;
    }
      
    return true;
}
void sustos(int no){
    queue <cord> Q;
    
    for (int i = 0; i < m; i++)
    {
        for (int k = 0; k < n; k++)
        {
            
            if (mapa[i][k]=='G')
            {
                cord guard;
                guard.x=i;
                guard.y=k;
                guard.pasos=0;
                Q.push(guard);
            }
            
        }
        
    }    
    while (!Q.empty())
    {
        cord actual= Q.front();
        Q.pop();

        

        if (mayor<actual.pasos)
        {
            mayor=actual.pasos;
        }
        
        for (int i = 0; i < 4; i++)
        {
            cord sig;
            sig.x = actual.x + mov_x[i];
            sig.y = actual.y + mov_y[i];
            sig.pasos = actual.pasos + 1;
            
            if (valido(sig))
            {
                pas[sig.x][sig.y]=actual.pasos+1;
                Q.push(sig);
                
            }
            
        }
    }
    
    return;
}
int main(){
  	cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>m>>n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>mapa[i][j];
        }
        
    }
    sustos(0);
    
    
    
    cout<<mayor<<"\n";
}