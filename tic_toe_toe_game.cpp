#include <iostream>
using namespace std;

char space [3][3]= {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row;
int column;
char token= 'x';
bool tie=false;
string s1="";
string s2="";

void functionOne(){
    


    cout<< "   |     |  "<<endl;
    cout<<" "<<space[0][0]<<" | "<<space[0][1]<<"   | "<<space[0][2]<<" "<<endl;
    cout<< " __|_____|__  "<<endl;
    //cout<<"    |     |  " <<endl;
    cout<<" "<<space[1][0]<<" | "<<space[1][1]<<"   | "<<space[1][2]<<" "<<endl;
    cout<< " __|_____|__  "<<endl;
    cout<< "   |     |  "<<endl;
    cout<<" "<<space[2][0]<<" | "<<space[2][1]<<"   | "<<space[2][2]<<" "<<endl;
    cout<<"   |     |  "<<endl;

}
void functionTwo(){

    int digit;
    if(token=='x'){
        cout<<s1<<" please enter ";
        cin>>digit;
    }
    if(token=='0'){
        cout<<s2<<" please enter ";
        cin>>digit;
    }
    if(digit==1){
        row=0;
        column=0;
    }
    if(digit==2){
        row=0;
        column=1;
    }
    if(digit==3){
        row=0;
        column=2;
    }
    if(digit==4){
        row=1;
        column=0;
    }
    if(digit==5){
        row=1;
        column=1;
    }
    if(digit==6){
        row=1;
        column=2;
    }
    if(digit==7){
        row=2;
        column=0;
    }
    if(digit==8){
        row=2;
        column=1;
    }
    if(digit==9){
        row=2;
        column=2;
    }
    else if(digit<1 || digit>9){
        cout<<"Invalid !!!"<<endl;
    }
    if(token=='x' && space[row][column]!='x' && space[row][column] !='0'){
        space[row][column]='x';
        token='0';    
    }
    else if(token=='0' && space[row][column]!='x' && space[row][column] !='0'){
        space[row][column]='0';
        token='x';    
    }
    else{
        cout<<"There is no empty space!"<<endl;
        functionTwo();
    }
    functionOne();


}
bool functionThree(){
    for(int i=0; i<3; i++){
        if((space[i][0]==space[i][1] && space[i][0]== space[i][2]) || (space[0][i]==space[1][i] && space[0][i]== space[2][i])){
            return true;
        }
    }
    if((space[0][0]==space[1][1] && space[1][1]== space[2][2]) || (space[0][2]==space[1][1] && space[1][1]==space[2][0])){
        return true;

    }

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(space[i][j]!='x' && space[i][j]!='0'){
                return false;
            }
        }
    }
    tie=true;
    return false;

}
int main(){

    cout<<"-----* TIC-TAC-TOE=GAME *-----"<<endl;
    cout<<"______________________________"<<endl;
    cout<<" "<<endl;
    cout<<"Enter the name of first player : "<<endl;
    getline(cin, s1);
    cout<<"Enter the name of second player : "<<endl;
    getline(cin, s2);
    cout<<s1<<" is player1 so he/she will play first "<<endl;
    cout<<s2<<" is player2 so he/she will play second "<<endl;
    while(!functionThree()){
        functionOne();
        if((space[0][0]=='x'||space[0][0]=='0')&&(space[0][1]=='x'||space[0][1]=='0')&&(space[0][2]=='x'||space[0][2]=='0')&&(space[1][0]=='x'||space[1][0]=='0')&&(space[1][1]=='x'||space[1][1]=='0')&&(space[1][2]=='x'||space[1][2]=='0')&&(space[2][0]=='x'||space[2][0]=='0')&&(space[2][1]=='x'||space[2][1]=='0')&&(space[2][2]=='x'||space[2][2]=='0'))

        {cout<<"It's a draw!"<<endl<<" Game Over "<<" To Play more plz restart the game "<<endl;}
        functionTwo();
        functionThree();
    }

    if(token =='x' && tie == false ){
        cout<<s2<<" Wins!"<<endl;
    }

    else if(token =='0' && tie ==false){
        cout<<s1<<" Wins!"<<endl;
    }

    else{
        if((space[0][0]=='x'||space[0][0]=='0')&&(space[0][1]=='x'||space[0][1]=='0')&&(space[0][2]=='x'||space[0][2]=='0')&&(space[1][0]=='x'||space[1][0]=='0')&&(space[1][1]=='x'||space[1][1]=='0')&&(space[1][2]=='x'||space[1][2]=='0')&&(space[2][0]=='x'||space[2][0]=='0')&&(space[2][1]=='x'||space[2][1]=='0')&&(space[2][2]=='x'||space[2][2]=='0'))

        {cout<<"It's a draw!"<<endl<<" Game Over "<<" To Play more plz restart the game "<<endl;}

    }
}