#include<iostream>
using namespace std;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char current_marker;
char current_player;
void draw_board()
{
    cout<<"  "<<board[0][0]<<"|"<<"  "<<board[0][1]<<"|"<< "  "<<board[0][2]<<endl;
    cout<<"---------------\n";
    cout<<"  "<<board[1][0]<<"|"<<"  "<<board[1][1]<<"|"<<"  "<<board[1][2]<<endl;
    cout<<"---------------\n";
    cout<<"  "<<board[2][0]<<"|"<<"  "<<board[2][1]<<"|"<<"  "<<board[2][2]<<endl;
}
bool position(int slot)
{
    int row,col;
    row=slot/3;
    if(slot%3==0)
    {
        row=row-1;
        col=2;
    }
    else
    {
        col=(slot%3)-1;
    }
 //  cout<<row<<","<<col;
    if(board[row][col]!='X'&&board[row][col]!='O')
   {
        board[row][col]=current_marker;
        return true;
   }
   else
   {
          return false;
   }
}
int  winner()
{
    for(int i=0;i<3;i++)
    {
        if(board[i][0]==board[i][1]&&board[i][1]==board[i][2])
        {
            return current_player;
        }
        if(board[0][i]==board[1][i]&&board[1][i]==board[2][i])
        {
            return current_player;
        }
    }
    if(board[0][0]==board[1][1]&&board[1][1]==board[2][2])
    {
        return current_player;
    }
    if(board[0][2]==board[1][1]&&board[1][1]==board[2][0])
    {
        return current_player;
    }
    return 0;
}
void change_player_marker()
{
    if(current_marker=='X')
    {
        current_marker='O';
    }
    else
    {
        current_marker='X';
    }

    if(current_player=='1')
    {
        current_player='2';
    }
    else
    {
        current_player='1';
    }
}
void play_game()
{
    cout<<"Player one,Please choose your marker:";
    char marker_P1;
    cin>>marker_P1;
    current_player='1';
    current_marker=marker_P1;
    draw_board();
    int player_won;
    for(int i=0;i<9;i++)
    {
        cout<<"It's chance of player"<<current_player<<" 's turn.Enter your slot:";
        int slot;
        cin>>slot;
        if(slot<1||slot>9)
        {
            cout<<"Invalid slot! Try once again";
            i--;
            continue;
        }
        if(!position(slot))
        {
            cout<<"Slot is occupied! Try once again";
            i--;
            continue;
        }
        draw_board();
        player_won=winner();
        if(player_won=='1')
        {
            cout<<"Congratulations! Player One won!!";
            break;
        }
        if(player_won=='2')
        {
             cout<<"Congratulations! Player Two won!!";
            break;
        }
        change_player_marker();

    }
    if(player_won==0)
    {
        cout<<"It's a tie!";
    }
}
int main()
{

   play_game();
   return 0;
}
