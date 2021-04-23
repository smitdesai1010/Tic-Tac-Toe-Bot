#include <iostream>
#include <iomanip>

using namespace::std;

char grid[3][3],winner='\0';

void human_turn(char);
void computer_turn(char,int,char);
bool condition();
void intialize();
void show();
void menu();
void HvH();
void HvC();
void CvC();
int minimax(char,char,bool,int,int,int,bool);
void best_move(char);
bool defend(char);
bool win(char);
bool attack(char);
int just_play(char);
void how_to_play();



int main()
{
  cout<<"\n\n\n\n\n\n\n\n\n\n\n"<<setw(48)<<""<<"Welcome to tic-tac-toe Game\n";
  cout<<setw(48)<<""<<" Press Enter to continue";
  cin.get();

  how_to_play();

  menu();

  return 0;
}


void how_to_play()
 {
  system("CLS");
  int a=1;

  cout<<"\n";

  for (int i=0; i<3; i++)
   {
    for (int j=0; j<3; j++)
     cout<<a++<<" ";

    cout<<endl;
   }

  cout<<"\n\nEnter values in such way to put your marker at corresponding values";
  cin.get();
 }


void menu()
 {   int choice=0;
   system("CLS");

   cout<<"\n 1) Human vs Human ";
   cout<<"\n 2) Human vs Computer";
   cout<<"\n 3) Computer vs Computer ";

   cout<<"\n\n\n Enter Your Choice: ";cin>>choice;
   system("CLS");

   switch(choice)
    {
      case 1:HvH();break;
      case 2:HvC();break;
      case 3:CvC();break;
      default: cout<<"\n Invalid Choice. Enter again";cin.get();cin.get();menu();break;
    }
 }


void HvH()
 {
   int i;

  intialize();

   for (i=1; i<10; i++)
    {
        show();

        if ((i-1)%2==0)
         human_turn('X');

        else
         human_turn('O');


          if (condition())
           {
             system("CLS");
             show();
             cout<<"\nGame Over";
             cout<<"\n"<<winner<<" wins";
             cin.get();
             exit (0);
           }

         cin.get();
         system("CLS");
   }

   show();
   cout<<"\nGame Over";
   cin.get();
   exit (0);

 }


 void HvC()
  {
    int i,a;
    char d;
    bool exit_condition=true;

     cout<<"\nDifficulty\nN for Normal\nH for Hard\nI for Impossible";
   do
    {
     cout<<"\n\n\nEnter Your choice: ";cin>>d;

     if ( d!='n' &&  d!='N' && d!='h' && d!='H' && d!='i' && d!='I')
      {
        cout<<"\n Invalid choice...Enter again";
        exit_condition=false;
      }

     else
      exit_condition=true;

    }
    while (!exit_condition);

    system("CLS");



    cout<<"\nDo You want to go first or the Computer";
    cout<<"\n\nEnter 0 for You to go first\nEnter 1 for the Computer to go first\n";

    do
     {
      cin>>a;

      if (a!=0 && a!=1)
       {
         cout<<"\n Invalid choice...Enter again ";
         exit_condition=false;
       }

      else
       exit_condition=true;
     }
    while (!exit_condition);


    system("CLS");

   intialize();

    for (i=1; i<10; i++)
     {
         show();

         if (((i-1)+a)%2==0)
          human_turn('X');

         else
          computer_turn('O',i,d);


           if (condition())
            {
              system("CLS");
              show();
              cout<<"\nGame Over";
              cout<<"\n"<<winner<<" wins";
              cin.get();
              exit (0);
            }

          cin.get();
          system("CLS");
  }

  show();
  cout<<"\nGame Over";
  cin.get();
  exit (0);

}

  void CvC()
  {
    int i;
    char d1,d2;

   intialize();

   cout<<"\nDifficulty\nN for Normal\nH for Hard\nI for Impossible";
   cout<<"\n\n\nEnter Your choice for player 1(X): ";cin>>d1;
   cout<<"\n\n\nEnter Your choice for player 2(O): ";cin>>d2;
   system("CLS");


    for (i=1; i<10; i++)
     {
         show();

         if ((i-1)%2==0)
          computer_turn('X',i,d1);

         else
          computer_turn('O',i,d2);


           if (condition())
            {
              system("CLS");
              show();
              cout<<"\nGame Over";
              cout<<"\n"<<winner<<" wins";
              cin.get();
              exit (0);
            }


          cin.get();
          system("CLS");
   }

     show();
     cout<<"\nGame Over";
     cin.get();
     exit (0);

 }


void human_turn(char XO)
 {
    int position,i,j,a=0;
    cout<<"\n"<<XO<<" Turn";
    again:
    cout<<"\n\nEnter Position: ";cin>>position;

    i=(position-1)/3;
    j=(position-1)%3;


    if (grid[i][j]!='_')
     {
       cout<<"\n Invalid Move ";
       goto again;
     }

     if (a==0)
     grid[i][j]=XO;
 }



void computer_turn(char XO,int a,char d)
 {
   int position=0,i,j;
    cout<<"\nComputer Turn "<<XO;



    if (d=='n' || d=='N')
     {
       if (a==1 || a==2)
        {
          again:
          srand((unsigned)time(0));
          position=(rand()%9)+1;

          i=(position-1)/3;
          j=(position-1)%3;

          if (grid[i][j]!='_')
           goto again;

          else
          grid[i][j]=XO;
        }

       else
         {
            if (a>4 && win(XO));

            else if (defend(XO));

            else if (attack(XO));

            else
              just_play(XO);
         }

     }



    else if (d=='h' || d=='H')
     {
       if (grid[1][1]=='_')
        grid[1][1]=XO;

       else
         {
            if (a>4 && win(XO));

            else if (defend(XO));

            else if (attack(XO));

            else
              just_play(XO);
         }



     }


    else if (d=='i' || d=='I')
      best_move(XO);

 }



bool condition()
 {
   for (int i=0; i<3; i++)
    if (grid[i][0]==grid[i][1] && grid[i][0]==grid[i][2] && grid[i][0]!='_')
     { winner=grid[i][0]; ;return true;}

    for (int i=0; i<3; i++)
     if (grid[0][i]==grid[1][i] && grid[0][i]==grid[2][i] && grid[0][i]!='_')
     { winner=grid[0][i]; ;return true;}

    if (grid[0][0]==grid[1][1] && grid[0][0]==grid[2][2] && grid[0][0]!='_')
       { winner=grid[0][0]; ;return true;}

    if (grid[0][2]==grid[1][1] && grid[0][2]==grid[2][0] && grid[2][0]!='_')
       { winner=grid[1][1]; ;return true;}

    return false;
}



void intialize()
 {
   for (int i=0; i<3; i++)
    for (int j=0; j<3; j++)
     {
       grid[i][j]='_';
     }
 }



 void show()
  {

    for (int i=0; i<3; i++)
     {
      for (int j=0; j<3; j++)
       cout<<grid[i][j]<<" ";

        cout<<endl;
     }

  }




 int minimax(char XO,char _XO,bool ismax,int depth,int alpha,int beta,bool optimised_condition)
  {
    int i,j;
    int output,minimax_score;
    int blank_spaces=0;

    for (i=0; i<3; i++)
     for (j=0; j<3; j++)
      if (grid[i][j]=='_')
       blank_spaces++;


    if (condition())
    {
     if (winner==XO)
      return 10-depth;

     else if (winner==_XO)
      return -10+depth;
    }


    if (blank_spaces==0)
     return 0;

 if (!optimised_condition)
 {
   if (ismax)
   {
     int minimax_score=-100;

     for (i=0; i<3; i++)
     {
      for (j=0; j<3; j++)
       {

         if (grid[i][j]=='_')
          {
              grid[i][j]=XO;
              minimax_score=max(minimax_score,minimax(XO,_XO,!ismax,depth+1,alpha,beta,optimised_condition));
              alpha=max(minimax_score,alpha);

              if (beta<=alpha)
              optimised_condition=true;


              grid[i][j]='_';

            }
        }
      }
      return minimax_score;
   }


   else
   {
     int minimax_score=100;

     for (i=0; i<3; i++)
     {
      for (j=0; j<3; j++)
       {

         if (grid[i][j]=='_')
          {
               grid[i][j]=_XO;
               minimax_score=min(minimax_score,minimax(XO,_XO,!ismax,depth+1,alpha,beta,optimised_condition));
               beta=min(minimax_score,beta);

               if (beta<=alpha)
                optimised_condition=true;

               grid[i][j]='_';
             }
          }
        }

       return minimax_score;
    }
  }

  return 0;
}


 void best_move(char XO)
 {
  int largest_score=-100,score,k=0;
  int x=-1,y=-1;
  char _XO;
  int depth=0;
  bool ismax=false;

      if (XO=='X')
       _XO='0';

      else
       _XO='X';

   for (int i=0; i<3; i++)
    for (int j=0; j<3; j++)
     {

       if (grid[i][j]=='_')
        {
          grid[i][j]=XO;
          score=minimax(XO,_XO,ismax,depth+1,-1000,1000,false);
          grid[i][j]='_';


          if (score>largest_score)
           {
             largest_score=score;
             x=i;
             y=j;
           }
        }

     }

    grid[x][y]=XO;
    cin.get();

 }





 bool defend(char XO)
   {
       char XO1;

       if (XO=='X')
        XO1='O';

       else
        XO1='X';



      for (int i=0; i<3; i++)
        if (grid[i][0]==XO1 && grid[i][1]==XO1  && grid[i][2]=='_')
        {
          grid[i][2]=XO;
          return true;
        }

      for (int i=0; i<3; i++)
        if (grid[i][0]==XO1 && grid[i][2]==XO1  && grid[i][1]=='_')
        {
          grid[i][1]=XO;
          return true;
        }

      for (int i=0; i<3; i++)
        if (grid[i][1]==XO1 && grid[i][2]==XO1  && grid[i][0]=='_')
        {
          grid[i][0]=XO;
          return true;
        }



      for (int i=0; i<3; i++)
        if (grid[0][i]==XO1 && grid[1][i]==XO1  && grid[2][i]=='_')
         {
          grid[2][i]=XO;
          return true;
         }


     for (int i=0; i<3; i++)
        if (grid[0][i]==XO1 && grid[2][i]==XO1  && grid[1][i]=='_')
        {
          grid[1][i]=XO;
          return true;
        }


      for (int i=0; i<3; i++)
        if (grid[1][i]==XO1 && grid[2][i]==XO1  && grid[0][i]=='_')
        {
          grid[0][i]=XO;
          return true;
        }




      if (grid[0][0]==XO1 && grid[1][1]==XO1 && grid[2][2]=='_')
        {
          grid[2][2]=XO;
          return true;
        }

      if (grid[1][1]==XO1 && grid[2][2]==XO1 && grid[0][0]=='_')
       {
        grid[0][0]=XO;
        return true;
       }


      if (grid[0][0]==XO1 && grid[2][2]==XO1 && grid[1][1]=='_')
       {
        grid[1][1]=XO;
        return true;
       }





      if (grid[0][2]==XO1 && grid[1][1]==XO1 && grid[2][0]=='_')
       {
        grid[2][0]=XO;
        return true;
       }

      if (grid[0][2]==XO1 && grid[2][0]==XO1 && grid[1][1]=='_')
       {
        grid[1][1]=XO;
        return true;
       }

      if (grid[1][1]==XO1 && grid[2][0]==XO1 && grid[0][2]=='_')
       {
        grid[0][2]=XO;
        return true;
       }

       return false;
    }


    bool win(char XO)
     {
       for (int i=0; i<3; i++)
         if (grid[i][0]==XO && grid[i][1]==XO  && grid[i][2]=='_')
         {
           grid[i][2]=XO;
           return true;
         }

       for (int i=0; i<3; i++)
         if (grid[i][0]==XO && grid[i][2]==XO  && grid[i][1]=='_')
          {
            grid[i][1]=XO;
            return true;
          }

       for (int i=0; i<3; i++)
         if (grid[i][1]==XO && grid[i][2]==XO  && grid[i][0]=='_')
         {
           grid[i][0]=XO;
           return true;
         }



       for (int i=0; i<3; i++)
        if (grid[0][i]==XO && grid[1][i]==XO  && grid[2][i]=='_')
          {
           grid[2][i]=XO;
           return true;
          }

       for (int i=0; i<3; i++)
        if (grid[0][i]==XO && grid[2][i]==XO  && grid[1][i]=='_')
          {
           grid[1][i]=XO;
           return true;
          }

       for (int i=0; i<3; i++)
         if (grid[1][i]==XO && grid[2][i]==XO  && grid[0][i]=='_')
         {
           grid[0][i]=XO;
           return true;
         }




       if (grid[0][0]==XO && grid[1][1]==XO && grid[2][2]=='_')
         {
           grid[2][2]=XO;
           return true;
         }

       if (grid[1][1]==XO && grid[2][2]==XO && grid[0][0]=='_')
        {
         grid[0][0]=XO;
         return true;
        }


        if (grid[0][0]==XO && grid[2][2]==XO && grid[1][1]=='_')
         {
          grid[1][1]=XO;
          return true;
         }




       if (grid[0][2]==XO && grid[1][1]==XO && grid[2][0]=='_')
        {
         grid[2][0]=XO;
         return true;
        }

       if (grid[0][2]==XO && grid[2][0]==XO && grid[0][1]=='_')
        {
         grid[1][1]=XO;
         return true;
        }

       if (grid[1][1]==XO && grid[2][0]==XO && grid[0][2]=='_')
        {
         grid[0][2]=XO;
         return true;
        }



        return false;
     }


   bool attack(char XO)
      {
        for (int i=0; i<3; i++)
         for (int j=0; j<3; j++)
          {
            if (grid[i][j]==XO)
             {
                 if (i+j==2)
                  {
                    if (  (grid[0][2]=='_' || grid[0][2]==XO) && (grid[1][1]=='_' || grid[1][1]==XO) && (grid[2][0]=='_' || grid[2][0]==XO) )
                     {
                        for (int k=0; k<2; k++)
                          if (grid[k][k]=='_')
                           { grid[k][k]=XO;  return true; }
                     }
                  }


                 if (i==j)
                  {
                     if ( (grid[0][0]=='_' || grid[0][0]==XO) && (grid[1][1]=='_' || grid[1][1]==XO) && (grid[2][2]=='_' || grid[2][2]==XO) )
                     {
                        for (int k=0,l=2-k; k<2; k++,l++)
                          if (grid[k][l]=='_')
                          { grid[k][l]=XO;  return true; }
                     }
                  }

                  if ( (grid[0][j]=='_' || grid[0][j]==XO) && (grid[1][j]=='_' || grid[1][j]==XO) && (grid[2][j]=='_' || grid[2][j]==XO) )
                  {
                     for (int k=0; k<2; k++)
                       if (grid[k][j]=='_')
                         { grid[k][j]=XO;  return true; }
                  }


                  if ( (grid[i][0]=='_' || grid[i][0]==XO) && (grid[i][1]=='_' || grid[i][1]==XO) && (grid[i][2]=='_' || grid[i][2]==XO) )
                  {
                     for (int k=0; k<2; k++)
                       if (grid[i][k]=='_')
                        { grid[i][k]=XO;  return true; }
                  }

              }

          }


          return false;
      }



     int just_play(char XO)
      {
        int k=0;
        int position[5][2];

        for (int i=0; i<3; i++)
         {
          for (int j=0; j<3; j++)
           {
              if (grid[i][j]=='_')
               {
                 position[k][0]=i;
                 position[k][1]=j;
                 k++;
               }
           }

         }

         srand((unsigned)time(0));
         unsigned int random=(rand()%(k));
         int m,n;

        m=position[random][0];
        n=position[random][1];

        grid[m][n]=XO;

        return 0;
      }