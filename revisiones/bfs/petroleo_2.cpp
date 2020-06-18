#include <bits/stdc++.h>
#define TAM 2000

using namespace std;
int m,n,D;

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
    if (mapa[act.x][act.y]=='*')
    {
        return false;
    }
    if (mapa[act.x][act.y]=='$')
    {
        return false;
    }  
    if (act.pasos>D)
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
            
            if (mapa[i][k]=='$')
            {
                cord guard;
                guard.x=i;
                guard.y=k;
                guard.pasos=0;
                for (int t = 0; t < 4; t++)
                {
                    cord sig;
                    sig.x=guard.x+mov_x[t];
                    sig.y=guard.y+mov_y[t];
                    if (valido(sig))
                    {
                        Q.push(sig);
                    }
                }
                
                break;
            }
            
        }
        
    }    
    while (!Q.empty())
    {
        cord actual= Q.front();
        Q.pop();
        
        mapa[actual.x][actual.y]='*';
        
        
       
        for (int i = 0; i < 4; i++)
        {
            cord sig;
            sig.x = actual.x + mov_x[i];
            sig.y = actual.y + mov_y[i];
            sig.pasos = actual.pasos + 1; 
            if (valido(sig))
            {
                               
                Q.push(sig);
                
            }
            
        }
    }
    
    return;
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>m>>n>>D;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>mapa[i][j];
        }
        
    }

    sustos(0);    
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<mapa[i][j];
        }
        cout<<"\n";
    }
    
}