#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <time.h>
using namespace std; 
// global variables.........................................................
int car_y_position= 26;  
int car_x_position= 22;
int enemy_bottom = 5 ;
int enemy_top = 0 ;
int enemy_bottom1 = 15 ;
int enemy_top1 = 0 ;
int score=0;
int countcollision=0;
int count = 0;
// end of global variables...................................................
char maze[28][52]= {{"|#|                                            |#|"},
                    {"|#|                                            |#|"},
                    {"|#|                                            |#|"},
                    {"|#|                                            |#|"},
                    {"|#|                                            |#|"},
                    {"|#|                                            |#|"},
                    {"|#|                                            |#|"},
                    {"|#|                                            |#|"},
                    {"|#|                                            |#|"},
                    {"|#|                                            |#|"},
                    {"|#|                                            |#|"},
                    {"|#|                                            |#|"},
                    {"|#|                                            |#|"},
                    {"|#|                                            |#|"},
                    {"|#|                                            |#|"},
                    {"|#|                                            |#|"},
                    {"|#|                                            |#|"},
                    {"|#|                                            |#|"},
                    {"|#|                                            |#|"},
                    {"|#|                                            |#|"},
                    {"|#|                                            |#|"},
                    {"|#|                                            |#|"},
                    {"|#|                                            |#|"},
                    {"|#|                                            |#|"},
                    {"|#|                    ***                     |#|"},
                    {"|#|                   * * *                    |#|"},
                    {"|#|                   * * *                    |#|"},
                    {"&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"}};

                    

//functions used in this game...........................................
string menu();
void printmaze();
void random_cars();
void random_cars1();
void lives();
void score1();
void collision();
void enemy_cars();
void enemy_cars1 ();
void car_left_movement();
void car_right_movement();
void car_up_movement();
void car_down_movement();
void mazeread();
//end of functions...............................................
//gotoxy function to avoid flickering............................
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
//end of gotoxy function............................................
bool gamerunning=false;
// start of main menu...............................................
main(){
    //mazeread();
    string choice;
    choice ="1";
    while(choice < "4"){
        choice = menu();
    if (choice == "1"){
        system("cls");
         
    
    gamerunning=true;
    
    printmaze();
    while(gamerunning){
      count++;
      enemy_cars ();
      enemy_cars1 ();
      collision();
      Sleep(60);
 // to move the car in different directions.............
      if (GetAsyncKeyState(VK_LEFT))
        {
            car_left_movement();
        }
    
     if (GetAsyncKeyState(VK_RIGHT))
        {
            car_right_movement();
        }
        if (GetAsyncKeyState(VK_UP))
        {
            car_up_movement();
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            car_down_movement();
        } 
        if (GetAsyncKeyState(VK_ESCAPE)) {
          gamerunning = false;  
        }  
  //end..................................................     
    }
}
         if (choice == "2"){
             cout << "PRESS LEFT KEY TO MOVE CAR IN LEFT DIRECTION." <<endl;
             cout << "PRESS RIGHT KEY TO MOVE CAR IN RIGHT DIRECTION." <<endl;
             cout << "PRESS UP KEY TO MOVE CAR IN UP DIRECTION." <<endl;
             cout << "PRESS DOWN KEY TO MOVE CAR IN DOWN DIRECTION." <<endl;
             cout << "PRESS ESCAPE TO EXIT THE GAME." <<endl;
             cout << "press any key to continue."<<endl;
             getch();
             system("cls");
         }

         if (choice == "3"){
             cout << "THANKS FOR PLAYING GAME" << endl;
             break;
         }
}
while( choice != "1" && choice != "2" && choice != "3" ){
      cout << "YOU SELECTED WRONG OPTION." << endl;
       
      cout <<"press any key to continue"<< endl;
      getch();
      choice = menu();
      system("cls");
      if (choice == "1" || choice == "2" || choice == "3" )
      {
      continue;
      } 
       break;  
      }


}
//definitions of functions................................
// to print maze.........................................     
      void printmaze(){
       SetConsoleTextAttribute(h, 2);
    
      for(int row = 0 ; row < 28 ; row++){
        for(int col = 0 ; col < 52 ; col++){
         //   gotoxy(col,row);
            cout<<maze[row][col];
           
        }
        cout<<endl;
    }
  // for coloring.........................................  
     SetConsoleTextAttribute(h, 2);
}
// to move car in left direction..........................
void car_left_movement(){
    if(car_x_position>3){
    car_x_position=car_x_position-1;
    maze[car_y_position][car_x_position]='*';
    gotoxy(car_x_position,car_y_position);
        cout<<'*';
    maze[car_y_position][car_x_position+1]=' ';
    gotoxy(car_x_position+1,car_y_position);
        cout<<' ';
    maze[car_y_position][car_x_position+2]='*';
    gotoxy(car_x_position+2,car_y_position);
        cout<<'*';
    maze[car_y_position][car_x_position+3]=' ';
     gotoxy(car_x_position+3,car_y_position);
        cout<<' ';
    maze[car_y_position][car_x_position+4]='*';
    gotoxy(car_x_position+4,car_y_position);
        cout<<'*';
    maze[car_y_position][car_x_position+5]=' ';
    
    gotoxy(car_x_position+5,car_y_position);
        cout<<' ';

    maze[car_y_position-1][car_x_position]='*';
    gotoxy(car_x_position,car_y_position-1);
        cout<<'*';
    maze[car_y_position-1][car_x_position+1]=' ';
     gotoxy(car_x_position+1,car_y_position-1);
        cout<<' ';
    maze[car_y_position-1][car_x_position+2]='*';
     gotoxy(car_x_position+2,car_y_position-1);
        cout<<'*';
    maze[car_y_position-1][car_x_position+3]=' ';
    gotoxy(car_x_position+3,car_y_position-1);
        cout<<' ';
    maze[car_y_position-1][car_x_position+4]='*';
    gotoxy(car_x_position+4,car_y_position-1);
        cout<<'*';
    maze[car_y_position-1][car_x_position+5]=' ';
    
    gotoxy(car_x_position+5,car_y_position-1);
        cout<<' ';

    maze[car_y_position-2][car_x_position+1]='*';
    gotoxy(car_x_position+1,car_y_position-2);
        cout<<'*';
    maze[car_y_position-2][car_x_position+2]='*';
    gotoxy(car_x_position+2,car_y_position-2);
        cout<<'*';
    maze[car_y_position-2][car_x_position+3]='*';
    gotoxy(car_x_position+3,car_y_position-2);
        cout<<'*';
    maze[car_y_position-2][car_x_position+4]=' ';
    gotoxy(car_x_position+4,car_y_position-2);
        cout<<' ';

}
}
// to move car in right direction..........................
void car_right_movement(){
    if(car_x_position<42){
    car_x_position=car_x_position+1;
    maze[car_y_position][car_x_position]='*';
    gotoxy(car_x_position,car_y_position);
        cout<<'*';
    maze[car_y_position][car_x_position+1]=' ';
    gotoxy(car_x_position+1,car_y_position);
        cout<<' ';
    maze[car_y_position][car_x_position+2]='*';
    gotoxy(car_x_position+2,car_y_position);
        cout<<'*';
    maze[car_y_position][car_x_position+3]=' ';
    gotoxy(car_x_position+3,car_y_position);
        cout<<' ';
    maze[car_y_position][car_x_position+4]='*';
    gotoxy(car_x_position+4,car_y_position);
        cout<<'*';
    maze[car_y_position][car_x_position-1]=' ';
    gotoxy(car_x_position-1,car_y_position);
        cout<<' ';

    maze[car_y_position-1][car_x_position]='*';
    gotoxy(car_x_position,car_y_position-1);
        cout<<'*';
    maze[car_y_position-1][car_x_position+1]=' ';
    gotoxy(car_x_position+1,car_y_position-1);
        cout<<' ';
    maze[car_y_position-1][car_x_position+2]='*';
    gotoxy(car_x_position+2,car_y_position-1);
        cout<<'*';
    maze[car_y_position-1][car_x_position+3]=' ';
    gotoxy(car_x_position+3,car_y_position-1);
        cout<<' ';
    maze[car_y_position-1][car_x_position+4]='*';
    gotoxy(car_x_position+4,car_y_position-1);
        cout<<'*';
    maze[car_y_position-1][car_x_position-1]=' ';
    gotoxy(car_x_position-1,car_y_position-1);
        cout<<' ';

    maze[car_y_position-2][car_x_position+1]='*';
    gotoxy(car_x_position+1,car_y_position-2);
        cout<<'*';
    maze[car_y_position-2][car_x_position+2]='*';
     gotoxy(car_x_position+2,car_y_position-2);
        cout<<'*';
    maze[car_y_position-2][car_x_position+3]='*';
     gotoxy(car_x_position+3,car_y_position-2);
        cout<<'*';
    maze[car_y_position-2][car_x_position]=' ';
     gotoxy(car_x_position,car_y_position-2);
        cout<<' ';
    }
}
// to move car in up direction..........................
void car_up_movement(){
    if(car_y_position>3){
    car_y_position=car_y_position-1;
    maze[car_y_position+1][car_x_position]=' ';
     gotoxy(car_x_position,car_y_position+1);
        cout<<' ';
    maze[car_y_position][car_x_position]='*';
    gotoxy(car_x_position,car_y_position);
        cout<<'*';
    maze[car_y_position-1][car_x_position]='*';
    gotoxy(car_x_position,car_y_position-1);
        cout<<'*';
    maze[car_y_position-2][car_x_position]=' ';
    gotoxy(car_x_position,car_y_position-2);
        cout<<' ';

    maze[car_y_position+1][car_x_position+1]=' ';
    gotoxy(car_x_position+1,car_y_position+1);
        cout<<' ';
    maze[car_y_position][car_x_position+1]=' ';
    gotoxy(car_x_position+1,car_y_position);
        cout<<' ';
    maze[car_y_position-1][car_x_position+1]=' ';
    gotoxy(car_x_position+1,car_y_position-1);
        cout<<' ';
    maze[car_y_position-2][car_x_position+1]='*';
    gotoxy(car_x_position+1,car_y_position-2);
        cout<<'*';

    maze[car_y_position+1][car_x_position+2]=' ';
    gotoxy(car_x_position+2,car_y_position+1);
        cout<<' ';
    maze[car_y_position][car_x_position+2]='*';
    gotoxy(car_x_position+2,car_y_position);
        cout<<'*';
    maze[car_y_position-1][car_x_position+2]='*';
    gotoxy(car_x_position+2,car_y_position-1);
        cout<<'*';
    maze[car_y_position-2][car_x_position+2]='*';
    gotoxy(car_x_position+2,car_y_position-2);
        cout<<'*';

    maze[car_y_position+1][car_x_position+3]=' ';
    gotoxy(car_x_position+3,car_y_position+1);
        cout<<' ';
    maze[car_y_position][car_x_position+3]=' ';
    gotoxy(car_x_position+3,car_y_position);
        cout<<' ';
    maze[car_y_position-1][car_x_position+3]=' ';
    gotoxy(car_x_position+3,car_y_position-1);
        cout<<' ';
    maze[car_y_position-2][car_x_position+3]='*';
    gotoxy(car_x_position+3,car_y_position-2);
        cout<<'*';
 
    maze[car_y_position+1][car_x_position+4]=' ';
    gotoxy(car_x_position+4,car_y_position+1);
        cout<<' ';
    maze[car_y_position][car_x_position+4]='*';
    gotoxy(car_x_position+4,car_y_position);
        cout<<'*';
    maze[car_y_position-1][car_x_position+4]='*';
    gotoxy(car_x_position+4,car_y_position-1);
        cout<<'*';
    maze[car_y_position-2][car_x_position+4]=' ';
    gotoxy(car_x_position+4,car_y_position-2);
        cout<<' ';
    }
  
}
// to move car in down  direction..........................
void car_down_movement(){
    if(car_y_position<26){
    car_y_position=car_y_position+1;
    maze[car_y_position-3][car_x_position]=' ';
    gotoxy(car_x_position,car_y_position-3);
        cout<<' ';
    maze[car_y_position][car_x_position]='*';
    gotoxy(car_x_position,car_y_position);
        cout<<'*';
    maze[car_y_position-1][car_x_position]='*';
    gotoxy(car_x_position,car_y_position-1);
        cout<<'*';
    maze[car_y_position-2][car_x_position]=' ';
    gotoxy(car_x_position,car_y_position-2);
        cout<<' ';

    maze[car_y_position-3][car_x_position+1]=' ';
    gotoxy(car_x_position+1,car_y_position-3);
        cout<<' ';
    maze[car_y_position][car_x_position+1]=' ';
    gotoxy(car_x_position+1,car_y_position);
        cout<<' ';
    maze[car_y_position-1][car_x_position+1]=' ';
    gotoxy(car_x_position+1,car_y_position-1);
        cout<<' ';
    maze[car_y_position-2][car_x_position+1]='*';
    gotoxy(car_x_position+1,car_y_position-2);
        cout<<'*';

    maze[car_y_position-3][car_x_position+2]=' ';
    gotoxy(car_x_position+2,car_y_position-3);
        cout<<' ';
    maze[car_y_position][car_x_position+2]='*';
    gotoxy(car_x_position+2,car_y_position);
        cout<<'*';
    maze[car_y_position-1][car_x_position+2]='*';
    gotoxy(car_x_position+2,car_y_position-1);
        cout<<'*';
    maze[car_y_position-2][car_x_position+2]='*';
    gotoxy(car_x_position+2,car_y_position-2);
        cout<<'*';

    maze[car_y_position-3][car_x_position+3]=' ';
    gotoxy(car_x_position+3,car_y_position-3);
        cout<<' ';
    maze[car_y_position][car_x_position+3]=' ';
    gotoxy(car_x_position+3,car_y_position);     
        cout<<' ';
    maze[car_y_position-1][car_x_position+3]=' ';
    gotoxy(car_x_position+3,car_y_position-1);
        cout<<' ';
    maze[car_y_position-2][car_x_position+3]='*';
    gotoxy(car_x_position+3,car_y_position-2);
        cout<<'*';
 
    maze[car_y_position-3][car_x_position+4]=' ';
    gotoxy(car_x_position+4,car_y_position-3);
        cout<<' ';
    maze[car_y_position][car_x_position+4]='*';
    gotoxy(car_x_position+4,car_y_position);
        cout<<'*';
    maze[car_y_position-1][car_x_position+4]='*';
    gotoxy(car_x_position+4,car_y_position-1);
        cout<<'*';
    maze[car_y_position-2][car_x_position+4]=' ';
    gotoxy(car_x_position+4,car_y_position-2);
        cout<<' ';
    }
  
}
// for enemy cars..................................
void enemy_cars (){
 // count of enemy cars............................     
    if (count % 1== 0)
    {
    if (enemy_top < 25)
    {   
        maze[enemy_top][enemy_bottom] = '@' ;
        gotoxy(enemy_bottom , enemy_top);
        cout<<'@';
        maze[enemy_top][enemy_bottom+1] = ' ' ;
        gotoxy(enemy_bottom+1 , enemy_top);
        cout<<' ';
        maze[enemy_top][enemy_bottom+2] = '@' ;
        gotoxy(enemy_bottom+2 , enemy_top);
        cout<<'@';
        maze[enemy_top+1][enemy_bottom] = '@' ;
        gotoxy(enemy_bottom , enemy_top+1);
        cout<<'@';
        maze[enemy_top+1][enemy_bottom+1] = ' ' ;
        gotoxy(enemy_bottom+1 , enemy_top+1);
        cout<<' ';
        maze[enemy_top+1][enemy_bottom+2] = '@' ;
        gotoxy(enemy_bottom+2 , enemy_top+1);
        cout<<'@';
        maze[enemy_top+2][enemy_bottom] = ' ' ;
        gotoxy(enemy_bottom , enemy_top+2);
        cout<<' ';
        maze[enemy_top+2][enemy_bottom+1] = '@' ;
        gotoxy(enemy_bottom+1 , enemy_top+2);
        cout<<'@';
        maze[enemy_top+2][enemy_bottom+2] = ' ' ;
        gotoxy(enemy_bottom+2 , enemy_top+2);
        cout<<' ';   
           
        
        enemy_top++ ;
        if(enemy_top>1){
        maze[enemy_top-2][enemy_bottom] = ' ' ;
        gotoxy(enemy_bottom , enemy_top-2);
        cout<<' ';
        maze[enemy_top-2][enemy_bottom+1] = ' ' ;
        gotoxy(enemy_bottom+1 , enemy_top-2);
        cout<<' ';
        maze[enemy_top-2][enemy_bottom+2] = ' ' ;
        gotoxy(enemy_bottom+2 , enemy_top-2);
        cout<<' ';
        }

        if(enemy_top==25){
        
        maze[enemy_top][enemy_bottom] = ' ' ;
        gotoxy(enemy_bottom , enemy_top);
        cout<<' ';
        maze[enemy_top][enemy_bottom+1] = ' ' ;
        gotoxy(enemy_bottom+1 , enemy_top);
        cout<<' ';
        maze[enemy_top][enemy_bottom+2] = ' ' ;
        gotoxy(enemy_bottom+2 , enemy_top);
        cout<<' ';
        maze[enemy_top-1][enemy_bottom] = ' ' ;
        gotoxy(enemy_bottom , enemy_top-1);
        cout<<' ';
        maze[enemy_top-1][enemy_bottom+1] = ' ' ;
        gotoxy(enemy_bottom+1 , enemy_top-1);
        cout<<' ';
        maze[enemy_top-1][enemy_bottom+2] = ' ' ;
        gotoxy(enemy_bottom+2 , enemy_top-1);
        cout<<' ';
        maze[enemy_top+1][enemy_bottom] = ' ' ;
        gotoxy(enemy_bottom , enemy_top+1);
        cout<<' ';
        maze[enemy_top+1][enemy_bottom+1] = ' ' ;
        gotoxy(enemy_bottom+1 , enemy_top+1);
        cout<<' ';
        maze[enemy_top+1][+2] = ' ' ;
        gotoxy(enemy_bottom+2 , enemy_top+1);
        cout<<' ';
         score1();
         lives();
        }
         random_cars(); 
        } 
    }
 }
 // for other enemy cars
 void enemy_cars1 (){
      
  
      if (count % 1== 0)
    {
    if (enemy_top1 < 25)
    {   
        maze[enemy_top1][enemy_bottom1] = '@' ;
        gotoxy(enemy_bottom1 , enemy_top1);
        cout<<'@';
        maze[enemy_top1][enemy_bottom1+1] = ' ' ;
        gotoxy(enemy_bottom1+1 , enemy_top1);
        cout<<' ';
        maze[enemy_top1][enemy_bottom1+2] = '@' ;
        gotoxy(enemy_bottom1+2 , enemy_top1);
        cout<<'@';
        maze[enemy_top1+1][enemy_bottom1] = '@' ;
        gotoxy(enemy_bottom1 , enemy_top1+1);
        cout<<'@';
        maze[enemy_top1+1][enemy_bottom1+1] = ' ' ;
        gotoxy(enemy_bottom1+1 , enemy_top1+1);
        cout<<' ';
        maze[enemy_top1+1][enemy_bottom1+2] = '@' ;
        gotoxy(enemy_bottom1+2 , enemy_top1+1);
        cout<<'@';
        maze[enemy_top1+2][enemy_bottom1] = ' ' ;
        gotoxy(enemy_bottom1 , enemy_top1+2);
        cout<<' ';
        maze[enemy_top1+2][enemy_bottom1+1] = '@' ;
        gotoxy(enemy_bottom1+1 , enemy_top1+2);
        cout<<'@';
        maze[enemy_top1+2][enemy_bottom1+2] = ' ' ;
        gotoxy(enemy_bottom1+2 , enemy_top1+2);
        cout<<' ';   
           
        
        enemy_top1 ++ ;
        if(enemy_top1 > 1){
        maze[enemy_top1-2][enemy_bottom1] = ' ' ;
        gotoxy(enemy_bottom1 , enemy_top1-2);
        cout<<' ';
        maze[enemy_top1-2][enemy_bottom1+1] = ' ' ;
        gotoxy(enemy_bottom1+1 , enemy_top1-2);
        cout<<' ';
        maze[enemy_top1-2][enemy_bottom1+2] = ' ' ;
        gotoxy(enemy_bottom1+2 , enemy_top1-2);
        cout<<' ';
        } 

        if(enemy_top1==25){
        
        maze[enemy_top1][enemy_bottom1] = ' ' ;
        gotoxy(enemy_bottom1 , enemy_top1);
        cout<<' ';
        maze[enemy_top1][enemy_bottom1+1] = ' ' ;
        gotoxy(enemy_bottom1+1 , enemy_top1);
        cout<<' ';
        maze[enemy_top1][enemy_bottom1+2] = ' ' ;
        gotoxy(enemy_bottom1+2 , enemy_top1);
        cout<<' ';
        maze[enemy_top1-1][enemy_bottom1] = ' ' ;
        gotoxy(enemy_bottom1 , enemy_top1-1);
        cout<<' ';
        maze[enemy_top1-1][enemy_bottom1+1] = ' ' ;
        gotoxy(enemy_bottom1+1 , enemy_top1-1);
        cout<<' ';
        maze[enemy_top1-1][enemy_bottom1+2] = ' ' ;
        gotoxy(enemy_bottom1+2 , enemy_top1-1);
        cout<<' ';
        maze[enemy_top1+1][enemy_bottom1] = ' ' ;
        gotoxy(enemy_bottom1 , enemy_top1+1);
        cout<<' ';
        maze[enemy_top1+1][enemy_bottom1+1] = ' ' ;
        gotoxy(enemy_bottom1+1 , enemy_top1+1);
        cout<<' ';
        maze[enemy_top1+1][enemy_bottom1+2] = ' ' ;
        gotoxy(enemy_bottom1+2 , enemy_top1+1);
        cout<<' ';
         score1();
         lives();
        }
         random_cars1();  
        }  
    }
 }
 // for random movement of cars.......................     
void random_cars(){
     int flag =0 ;
        for (int z = 0 ; z < 26 ; z++){
            for (int y = 5 ; y < 49 ; y++){
                if (maze[z][y] == '@'){
                    flag = 1 ;
                    break;
                }
            }
        }
if(flag == 0){
    enemy_top = 0 ;
    enemy_bottom = 5;
    enemy_top = rand()%33;
    for(int i = 0 ; i < 5 ; i++){
    while(enemy_bottom == 19 || enemy_bottom == 24 || enemy_bottom == 23 
          || enemy_bottom == 20 || enemy_bottom == 22 ){
        enemy_bottom = 5;
        enemy_top =  rand()%33;
                }
             }
         }
    }
    void random_cars1(){
     int flag =0 ;
        for (int z = 0 ; z < 26 ; z++){
            for (int y = 5 ; y < 49 ; y++){
                if (maze[z][y] == '@'){
                    flag = 1 ;
                    break;
                }
            }
        }
        if(flag == 0){
        enemy_top1 = 0 ;
        enemy_bottom1 = 0;
        enemy_bottom1= rand()%45;
        for(int i = 0 ; i < 5 ; i++){
                    
    while(enemy_bottom1 == 19 || enemy_bottom1 == 24 || enemy_bottom1 == 23 
        || enemy_bottom1 == 20 || enemy_bottom1 == 22 || enemy_bottom1 == 30){
                
        enemy_bottom1 = 0;
        enemy_bottom1= rand()%45;
                }
             }
         }
    }
void collision(){
    for(int i = 0 ; i < 28 ; i++){
        for(int j = 0 ; j < 52 ; j++){
    if(maze[i][j]=='*' && maze[i][j-1]=='*' && maze[i][j+1]=='*'){
    if(maze[i-1][j] !=' ' || maze[i-1][j+1] !=' ' || maze[i-1][j-1] !=' ' ){
                    
    countcollision++;
    break;
                }
            }   
        }
        if(countcollision==3){
        gamerunning=false;
        }
    }
}
// for counting the scores...........................
void score1(){
    enemy_bottom=5;
    enemy_top=0;
    SetConsoleTextAttribute(h, 11);
    score=score+3;
    gotoxy(enemy_top+75,enemy_bottom+9);
    cout<<"      "<<endl;
    gotoxy(enemy_top+75,enemy_bottom+10);
    cout<<"*  score : "<<score<<"                            *"<<endl;
     SetConsoleTextAttribute(h, 7);
}
// for lives...............................................
void lives(){
     SetConsoleTextAttribute(h, 11);
     gotoxy(enemy_top+75 , enemy_bottom+9);
     cout<<"*****************************************";
      gotoxy(enemy_top+75 , enemy_bottom+13);
     cout<<"*****************************************";
// if there is one collision...............................
    if(countcollision==1){
        gotoxy( enemy_top +75, enemy_bottom +11);
         cout<<"      "<<endl;
         gotoxy( enemy_top+75,enemy_bottom+12);
         cout<<"*  lives : 02                          *"<<endl;
        
    }
// if there is two collision...............................
    if(countcollision==2){
        
         gotoxy(enemy_top+75,enemy_bottom+11);
         cout<<"      "<<endl;
         gotoxy(enemy_top+75,enemy_bottom+12);
         cout<<"*  lives : 01                           *"<<endl;
          
    }
// if there is three collision...............................
    if(countcollision==3){
       
         gotoxy(enemy_top+75,enemy_bottom+11);
         cout<<"      "<<endl;
         gotoxy(enemy_top+75,enemy_bottom+12);
         cout<<"|  lives : 00                           |"<<endl;
        
         
    }
//// if there is no collision...............................
    if(countcollision==0){
       
        gotoxy(enemy_top+75,enemy_bottom+11);
        cout<<"      "<<endl;
         gotoxy(enemy_top+75,enemy_bottom+12);
         cout<<"|  lives : 03                           |"<<endl;
          
    }
     SetConsoleTextAttribute(h, 5);
}

// for main menu..............................................

string menu(){
    string option;
    cout <<"1.START GAME" << endl;
    cout <<"2.INSTRUCTIONS OF GAME" << endl;
    cout <<"3.EXIT GAME" << endl;
    cout <<"Enter your option............"<< endl;
    cin >> option;
    return option;
}
//file handling................................
/*void mazeread(){
    string line;
    fstream file;
    file.open("maze.txt" , ios:: in);
    for(int i=0 ; i<28 ; i++){
        getline(file,line);
        for(int j=0 ; j<52 ; j++){
         maze[i][j]=line[j];  
        }
    }
  file.close();
}   */ 