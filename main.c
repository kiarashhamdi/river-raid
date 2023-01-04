#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <math.h>



void air_plane(int x , int y);
void second_air_plane(int y , int x);
void main_window(WINDOW *win);
void start();
void controller(int c , int x , int y ,WINDOW *win ,int k, int i,int j, int e, int o , int p , int l);
void second_controller(int c , int x , int y ,WINDOW *win, int k, int i,int j,int e,int o , int p , int l);
void shooting(int y ,int x);
void random_rock(int k ,int i);
void setting(int y, int x);
void wellcome(int y , int x);
void clear_wellcome(int y , int x);
void geme_over(int y , int x);
void design();
void explotion(int y , int x);
int high_score = 0;

int main(){                                  //main Function
    int y = 10;
    int x = 45;
    int z = 70;
    initscr();
                               
    curs_set(0);
    endwin();
    wellcome(y , x);
    getch();
    clear_wellcome(y ,x);
    char MENU;
    while(1){                                //starting menu
    while(1)
    {
        clear();
        
        mvprintw(y+5, z,"\\_________________1)Start Game__________________/");
        mvprintw(y+6, z," \\________________2)Settings___________________/");
        mvprintw(y+7, z,"  \\_______________3)Exit Game_________________/");
        MENU=getch();
        if(MENU=='1')
            break;
        else if(MENU=='2')
                setting(y , x);
        else if(MENU=='3')
       return 0;
    }
    refresh();
    getch();
    start();
    getch();
    
    }
    endwin();
    return 0;

}
void wellcome(int y , int x){           //printing welcome
mvprintw(y   , x,"               _                            _               _                           _     _ ");
mvprintw(y+1 , x,"              | |                          | |             (_)                         (_)   | |");
mvprintw(y+2 , x," __      _____| | ___ ___  _ __ ___   ___  | |_ ___    _ __ ___   _____ _ __   _ __ ___ _  __| |");
mvprintw(y+3 , x," \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ | __/ _ \\  | '__| \\ \\ / / _ \\ '__| | '__/ _ \\ |/ _` |");
mvprintw(y+3 , x,"  \\ V  V /  __/ | (_| (_) | | | | | |  __/ | || (_) | | |  | |\\ V /  __/ |    | | |  __/ | (_| |");
mvprintw(y+4 , x,"   \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|  \\__\\___/  |_|  |_| \\_/ \\___|_|    |_|  \\___|_|\\__,_|");
mvprintw(y+5 , x,"");
mvprintw(y+6 , x,"                        \\ /                                          \\   /");
mvprintw(y+7 , x,"                       --o--           `\\\\             //'      .____-/.\\-____.");
mvprintw(y+8 , x,"                                         \\\\           //             ~`-'~");
mvprintw(y+9 , x,"                                          \\\\. __-__ .//");
mvprintw(y+10, x,"                                ___/-_.-.__`/~     ~\'__.-._-\\___              ");      
mvprintw(y+11, x,"         .|.       ___________.'__/__ ~-[ \\.\'-----'/./ ]-~ __\\__`.___________       .|.");
mvprintw(y+12, x,"         ~o~~~~~~~--------______-~~~~~-_/_/ |   .   | \\_\\_-~~~~~-______--------~~~~~~~o~");
mvprintw(y+13, x,"         ' `               + + +  (X)(X)  ~--\\__ __/--~  (X)(X)  + + +               ' `");
mvprintw(y+14, x,"                                      (X) `/.\' ~ `/.\' (X)  ");
mvprintw(y+15, x,"                                          \\_/     \\_/");
}
void design(){        //design for the second window during playing
mvprintw(33   , 125,"       _                        ");
mvprintw(34   , 125,"      (_)                       ");
mvprintw(35   , 125," _ __  _ __   __  ___  _ __     ");
mvprintw(36   , 125,"| '__|| |\\ \\ / / / _ \\| '__| ");
mvprintw(37   , 125,"| |   | | \\ V / |  __/| |      ");
mvprintw(38   , 125,"|_|   |_|  \\_/   \\___||_|     ");
mvprintw(39   , 125,"                                ");
mvprintw(40   , 125,"             _      _           ");
mvprintw(41   , 125,"            (_)    | |          ");
mvprintw(42   , 125," _ __   ___  _   __| |          ");
mvprintw(43   , 125,"| '__| / _ \\| | / _` |         ");
mvprintw(44   , 125,"| |   |  __/| || (_| |          ");
mvprintw(45   , 125,"|_|    \\___||_| \\__,_|        "); 
}

void clear_wellcome(int y , int x){  //clear objects
mvprintw(y   , x,"                                                                                                                ");
mvprintw(y+1 , x,"                                                                                                                ");
mvprintw(y+2 , x,"                                                                                                                ");
mvprintw(y+3 , x,"                                                                                                                ");
mvprintw(y+3 , x,"                                                                                                                ");
mvprintw(y+4 , x,"                                                                                                                ");
mvprintw(y+5 , x,"                                                                                                                ");
mvprintw(y+6 , x,"                                                                                                                ");
mvprintw(y+7 , x,"                                                                                                                ");
mvprintw(y+8 , x,"                                                                                                                ");
mvprintw(y+9 , x,"                                                                                                                ");
mvprintw(y+10, x,"                                                                                                                ");
mvprintw(y+11, x,"                                                                                                                ");
mvprintw(y+12, x,"                                                                                                                ");
mvprintw(y+13, x,"                                                                                                                ");
mvprintw(y+14, x,"                                                                                                                ");
mvprintw(y+15, x,"                                                                                                                ");
mvprintw(y+16, x,"                                                                                                                ");
}


void air_plane(int y , int x){    //printing the airplane
    mvprintw(y   , x , "     |    ");
    mvprintw(y+1 , x , "    |||   ");
    mvprintw(y+2 , x , " |||||||||");
    mvprintw(y+3 , x , "    |||   ");
}
void second_air_plane(int y , int x){
mvprintw(y     , x ,"   /^\\    ");
mvprintw(y+1   , x ,"/**|||**\\ ");
mvprintw(y+2   , x ,"  **|**    ");
mvprintw(y+3   , x ,"    |      ");
}

void explotion(int y , int x){    //print an explosion ascii when lose
mvprintw(y     , x,"     _ ._  _ , _ ._            ");  
mvprintw(y+1   , x,"   (_ ' ( `  )_  .__)            ");  
mvprintw(y+2   , x," ( (  (    )   `)  ) _)            ");  
mvprintw(y+3   , x,"(__ (_   (_ . _) _) ,__)            ");  
mvprintw(y+4   , x,"    `~~`\\ ' . /`~~`           ");  
mvprintw(y+5   , x,"         ;   ;        ");  
mvprintw(y+6   , x,"         /   \\            ");  
mvprintw(y+7   , x,"      __/_ __ \\___            ");  
timeout(3000);
}

void shooting(int y ,int x){            //shoting mode

    for(y=y-1 ; y >0 ;y--){
        mvprintw(y +1   , x , "     |    ");
    }
}

void geme_over(int y , int x){          //printing game over when lose
mvprintw(y   , x,"       __ _  __ _ _ __ ___   ___    _____   _ _ __                                                              ");    
mvprintw(y+1  , x,"  / _` |/ _` | '_ ` _ \\ / _ \\  / _ \\ \\ / / _ \\ '__|                                                       ");
mvprintw(y+2  , x," | (_| | (_| | | | | | |  __/ | (_) \\ V /  __/ |                                                              ");
mvprintw(y+3  , x,"  \\__, |\\__,_|_| |_| |_|\\___|  \\___/ \\_/ \\___|_|                                                         ");
mvprintw(y+4  , x,"   __/ |                                                                                                       ");
mvprintw(y+5  , x,"  |___/                                                                                                        ");
timeout(5000);

}
void setting(int y, int x){                  //setting menu
    int c;
    y = 25;
    x =70;
}
void main_window(WINDOW *win){    //make window
    win = newwin(55 , 120 , 0 , 0);
    refresh();
    box(win , 0, 0);
    wrefresh(win);
}


void controller(int c , int x , int y ,WINDOW *win, int k, int i,int j,int e,int o , int p , int l){ 
p = 160;

    while(1){                 //first condition for printing rock and push it down
        main_window(win);
        air_plane(y , x);
        i++;

        if (y==0){             //condition for if the air plane located 0 print it on the end of window

            y=50;

        }else if (y==50){

            y=50;

        }

        mvprintw(i      , k, "*******");        //printing first rock
        mvprintw(i-1    , k, "*******");
        mvprintw(i-2    , k, "*******");
        mvprintw(i-3    , k, "*******");
        refresh();
        if (i==53){

            i=-2;                             // giving first random number 
            srand(time(0));
            int a = 0 , b = 100;
            k = rand()%(b-a+1)+a;

        }
        e++;
        mvprintw(e      , o, "*******");     //second rock
        mvprintw(e-1    , o, "*******");
        mvprintw(e-2    , o, "*******");
        mvprintw(e-3    , o, "*******");
        refresh();
        if (e==53){

            e=-20;
            srand(time(0));                  // giving second random number
            int a = 0 , b = 100;
            o = rand()%(b-a+1)+a-5;

        }

        j++;
        mvprintw(1 , 1 , "your score is %d", j);                //printing scores
        mvprintw(10, 130,"%d is high score", j);

        if(i == y   || i==y+1 || i==y+2 || i==y+3 ||i==y+4 ||i==y+5){         //condition for crashing first rock with air plane

            if (k==x || k==x+7 || k==x-7 || k==x-2 || k==x-1 || k==x+1 || k==x+2 || k==x+3 || k==x-3 || k==x+4 || k==x-4 || k==x+5 || k==x+6 || k==x+7 || k==x+8 || k==x+9){

               WINDOW *win;
                win = newwin(55 , 120 , 0 , 40);
                wrefresh(win);
                explotion(y , x);
                getch();
                clear();
                
                geme_over(y , x);
                getch();
                clear_wellcome(y , x);
                refresh();
                mvprintw(25 , 90 , "your score is %d", j);
                if(high_score<=j){
                    high_score = j;
                }
                mvprintw(10,130 , "high score is %d" , high_score);
                break;

            }

        }

        if(e == y  || e==y+1 || e==y+2 || e==y+3 ||e==y+4 ||e==y+5){         //condition for crashing second rock with air plane 

            if (o==x || o==x+7 || o==x-7 || o==x-2 || o==x-1 || o==x+1 || o==x+2 || o==x+3 || o==x-3 || o==x+4 || o==x-4 || o==x+5 || o==x-5 || o==x+6 || o==x+7 || o==x+8 || o==x+9){


                WINDOW *win;
                win = newwin(55 , 120 , 0 , 40);
                wrefresh(win);
                explotion(y , x);
                getch();
                clear();
                geme_over(y , x);
                getch();
                clear_wellcome(y , x);
                refresh();
                mvprintw(25 , 90 , "your score is %d", j);
                getch();
                if(high_score<=j){
                    high_score = j;
                }
                mvprintw(10,130 , "high score is %d" , high_score);
                break;

            }

        }
        
        timeout(p);             // time for the rock push down     
        if( j == 100){
            p =  120;
        }
        else if( j == 200){
            p =  90;
        }               
        else if( j == 400){
            p =  60;
        }               
        else if( j == 700){
            p =  40;
        }               
        else if( j ==1100 ){
            p =  20;
        }               
        else if( j == 2000){
            p =  10;
        }                              
        wrefresh(win);
        c = getch();                        //taking char for move
        switch(c){

            case'a':
            case'A':
            main_window(win);
            x -= 3;
            air_plane(y , x);
            break;

        }

        switch(c){

            case'd':
            case'D':
            main_window(win);
            x += 3;
            air_plane(y , x);
            break;

        }

        switch(c){

            case's':
            case'S':
            main_window(win);
            y += 2;
            air_plane(y , x);
            break;

        }

        switch(c){

            case'w':
            case'W':
            main_window(win);
            y -= 2;
            air_plane(y , x);
            break;

        }

        switch(c){

            case'q':
            case'Q':
            endwin();
            WINDOW *win;
            win = newwin(55 , 120 , 0 , 40);
            wrefresh(win);
            printw("Finished !!!");
            break;

        }

        switch(c){          //shoting mode

            case'f':
            case'F':
            main_window(win);
            air_plane(y , x);
            shooting(y,x);
            mvprintw(y-1    , x , "          ");
            refresh();
            break;

        }
    }
}
void second_controller(int c , int x , int y ,WINDOW *win, int k, int i,int j,int e,int o , int p , int l){ 
p = 160;

    while(1){                 //first condition for printing rock and push it down
        main_window(win);
        second_air_plane(y , x);
        i++;
        if (y==0){             //condition for if the air plane located 0 print it on the end of window

            y=50;

        }else if (y==50){

            y=50;

        }

        mvprintw(i      , k, "*******");        //printing first rock
        mvprintw(i-1    , k, "*******");
        mvprintw(i-2    , k, "*******");
        mvprintw(i-3    , k, "*******");
        refresh();
        if (i==53){

            i=-2;                             // giving first random number 
            srand(time(0));
            int a = 0 , b = 100;
            k = rand()%(b-a+1)+a;

        }
        e++;
        mvprintw(e      , o, "*******");     //second rock
        mvprintw(e-1    , o, "*******");
        mvprintw(e-2    , o, "*******");
        mvprintw(e-3    , o, "*******");
        refresh();
        if (e==53){

            e=-20;
            srand(time(0));                  // giving second random number
            int a = 0 , b = 100;
            o = rand()%(b-a+1)+a-5;

        }

        j++;
        mvprintw(1 , 1 , "your score is %d", j);                //printing scores
        mvprintw(10, 130,"%d is high score", j);

        if(i == y   || i==y+1 || i==y+2 || i==y+3 ||i==y+4 ||i==y+5){         //condition for crashing first rock with air plane

            if (k==x || k==x+7 || k==x-7 || k==x-2 || k==x-1 || k==x+1 || k==x+2 || k==x+3 || k==x-3 || k==x+4 || k==x-4 || k==x+5 || k==x+6 || k==x+7 || k==x+8 || k==x+9){

               WINDOW *win;
                win = newwin(55 , 120 , 0 , 40);
                wrefresh(win);
                explotion(y , x);
                getch();
                clear();
                
                geme_over(y , x);
                getch();
                clear_wellcome(y , x);
                refresh();
                mvprintw(25 , 90 , "your score is %d", j);
                break;

            }

        }

        if(e == y  || e==y+1 || e==y+2 || e==y+3 ||e==y+4 ||e==y+5){         //condition for crashing second rock with air plane 

            if (o==x || o==x+7 || o==x-7 || o==x-2 || o==x-1 || o==x+1 || o==x+2 || o==x+3 || o==x-3 || o==x+4 || o==x-4 || o==x+5 || o==x-5 || o==x+6 || o==x+7 || o==x+8 || o==x+9){


                WINDOW *win;
                win = newwin(55 , 120 , 0 , 40);
                wrefresh(win);
                explotion(y , x);
                getch();
                clear();
                geme_over(y , x);
                getch();
                clear_wellcome(y , x);
                refresh();
                mvprintw(25 , 90 , "your score is %d", j);
                break;

            }

        }
        
        timeout(p);             // time for the rock push down     
        if( j == 100){
            p =  120;
        }
        else if( j == 200){
            p =  90;
        }               
        else if( j == 400){
            p =  60;
        }               
        else if( j == 700){
            p =  40;
        }               
        else if( j ==1100 ){
            p =  20;
        }               
        else if( j == 2000){
            p =  10;
        }                              
        wrefresh(win);
        c = getch();                        //taking char for move
        switch(c){

            case'a':
            case'A':
            main_window(win);
            x -= 3;
            second_air_plane(y , x);
            break;

        }

        switch(c){

            case'd':
            case'D':
            main_window(win);
            x += 3;
            second_air_plane(y , x);
            break;

        }

        switch(c){

            case's':
            case'S':
            main_window(win);
            y += 2;
            second_air_plane(y , x);
            break;

        }

        switch(c){

            case'w':
            case'W':
            main_window(win);
            y -= 2;
            second_air_plane(y , x);
            break;

        }

        switch(c){

            case'q':
            case'Q':
            endwin();
            WINDOW *win;
            win = newwin(55 , 120 , 0 , 40);
            wrefresh(win);
            printw("Finished !!!");
            break;

        }

        switch(c){          //shoting mode

            case'f':
            case'F':
            main_window(win);
            second_air_plane(y , x);
            shooting(y,x);
            mvprintw(y-1    , x , "          ");
            refresh();
            break;

        }
    }
}

void start(){
    char name[100];
    int j = 0;
    int l = 1;
    int e =-15;
    int y = 50;
    int x = 50;
    int p = 160;
    srand(time(0));
    int a = 0 , b = 100;
    int k=rand()%(b-a+1)+a;
    int o=rand()%(b-a+1)+a-5;
    int c;
    int i=-2;
    clear();
    mvprintw(10, x+30, "please enter your name:");
    scanw("%s", name );
    refresh();
    
    WINDOW *  win;
    win = newwin(55 , 120 , 0 , 0);
    wrefresh(win);
    move(4,5);
    box(win , 0 , 0);
    refresh();

    win = newwin(55 , 40 , 0 , 120);
    move(4,5);
    box(win , 0 , 0);
    refresh();
    design();
    wrefresh(win);
    mvprintw(5  , 130 ,"%s is playing", name);
    mvprintw(20 , 127 ,"press CTRL + S for pause ");
    mvprintw(22 , 127 ,"press CTRL + Z for start ");
    getch();
    mvprintw(20 , 40 ," Please choose your air plane    ");
    air_plane(25 , 50);
    second_air_plane(40 , 50);
    c = getch();
    switch(c){
            case'1':
            controller(c , y , x ,win, k , i , j, e, o, p, l);
            getch();
    }
   switch(c){
        case'2':
         second_controller(c , y , x ,win, k , i , j, e, o, p, l);
         getch();
    }

    
    
}
