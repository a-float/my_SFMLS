#include<iostream>
using namespace std;

const int N = 8;
int order[N][N];

struct Pos{
    int x;
    int y;
    Pos(int x_, int y_){
        x = x_;
        y = y_;
    }
    Pos(){}
};

struct Tile{
    Pos moves[8];
    int msize;
    int x;
    int y;
    Tile(){}
    Tile(int x_, int y_){
        x=x_;
        y=y_;          //pozycje zgodnie ze wskazowkami zegara
        int mx = 0;
        if(y>=2 && x<=6){moves[mx]=Pos(x+1,y-2);mx++;}
        if(y>=1 && x<=5){moves[mx]=Pos(x+2,y-1);mx++;}
        if(y<=6 && x<=5){moves[mx]=Pos(x+2,y+1);mx++;}
        if(y<=5 && x<=6){moves[mx]=Pos(x+1,y+2);mx++;}
        if(y<=5 && x>=1){moves[mx]=Pos(x-1,y+2);mx++;}
        if(y<=6 && x>=2){moves[mx]=Pos(x-2,y+1);mx++;}
        if(y>=1 && x>=2){moves[mx]=Pos(x-2,y-1);mx++;}
        if(y>=2 && x>=1){moves[mx]=Pos(x-1,y-2);mx++;}
        msize = mx;
    }

    Pos get_next_pos(int i){
        if(i < msize)return moves[i];
        else return Pos(-1,-1);
    }
};


void show(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout<<order[i][j]<<" ";
        }
        cout<<endl;
    }
}


bool skoczek(Tile tiles[N][N], int history[N][N], Tile tile, int moves_so_far){
    if(moves_so_far == 65){
        return true;
    }
    for(int i = 0; i < tile.msize; i++){
        Pos next_pos = tile.get_next_pos(i);
        //cout<<"checking "<<moves_so_far<<" ("<<next_pos.x<<" "<<next_pos.y<<")"<<endl;
        //show();
        if(history[next_pos.y][next_pos.x] != 0)continue;

        int pos_x = next_pos.x;
        int pos_y = next_pos.y;
        //cout<<pos_x<<" "<<pos_y<<endl;

        if(pos_x == -1)continue;

        Tile next_tile = tiles[pos_y][pos_x];
        history[pos_y][pos_x] = moves_so_far;
        if(skoczek(tiles, history, next_tile, moves_so_far+1))return true;
        history[pos_y][pos_x] = 0;
    }
    return false;
}

int main(){
    Tile arr[N][N];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            arr[i][j] = Tile(j,i);
            order[i][j] = 0;
        }
    }
    Tile currTile = arr[0][0];
    order[0][0] = 1;
    skoczek(arr, order, currTile, 2);
    show();

return 0;
}
