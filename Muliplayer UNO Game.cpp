/*
-----------------------------------------------------------------------------------------------
Card Structure in UNO

Total number of cards = 108 [(10 x 4) + (9 x 4) + (6 x 4) + 4 + 4]
Cards in 1 suit = 25
No of 0 in each suit = 1
Numbers in each suit = 19 [(0 to 9) + (1 to 9)]
Powers in each suit = 3 x 2
No of suits = 4
No of Wild = 4
No of Wild draw 4 = 4
------------------------------------------------------------------------------------------------
Card Structure to computer

Colors
Identified by rows number
0 or 4 = red
1 or 5 = yellow
2 or 6 = green
3 or 7 = blue

Numbers and powers
Identified by column number
0 to 9 = same as column numbers
10 = skip
11 = reverse
12 = draw 2
13 = {row number 0 to 3 = normal wild,
      row number 4 to 7 = draw 4 wild}
-------------------------------------------------------------------------------------------------
Card Structure to user

Colors
Identified by first letter of string
R = red
Y = yellow
G = green
B = blue

Numbers and powers
Identified by second letter of string
0 to 9 = the number itself
S = skip
R = reverse
T = draw two

Wilds
WC = normal wild
WF = wild draw four
-------------------------------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class start //starting designing of the program
{
    public:
void slow() //slow function so that the design & related content appears slowly on the output window
{
    for(int i=0; i<=100000000; i++);
}
void uno_d() //design of the UNO logo
{
cout<<"\n\n";
cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@####@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";slow();
cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#########################*      @@@@@@@@@@@\n";slow();
cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@##########################  @@.  ...   @@  @@@@@@\n";slow();
cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@###########################  @ ............... @  @@@\n";slow();
cout<<"@@@@@@@@@@@@@@@@@@@@@@@####################   &@@@ . @@ .....  @@@@@ ...... @ @@\n";slow();
cout<<"@@@@@@@@@@@@@@@@@@@@#################### @@@.....# @@@ .... @@@@@@@@##@ .....@ &\n";slow();
cout<<"@@@@@@@@@@@@@@@@@@###########(     ### @####@.....@@@ .... @ ###  @####@ .... @ \n";slow();
cout<<"@@@@@@@@@@@@@@@########   @@@  ... @,   @##@#@.....@@ .... @ ###### @@##@.....@ \n";slow();
cout<<"@@@@@@@@@@@@@#####  @@  .. @@........  @ @##@@/.....@@.....// ###### @@@@.....@ \n";slow();
cout<<"@@@@@@@@@@   ### &@##@ .... @@........... @@@@@ .....@ ..... @  ###, @@@..... @ \n";slow();
cout<<"@@@@  @@@  @  ##  @##@@ .... @@....., ....... @@ .... @@ ...... #@@@  ...... @ @\n";slow();
cout<<"@  @@@,.....@ /##  @%#@@ .... @@.....@@@& ....... .... @@@ ............... @ @@@\n";slow();
cout<<"@ @@@@@ .....@ ###  @@@@@..... @@.....@@@@@@ .......... @@@@@@   ...  *@@@  @@@@\n";slow();
cout<<"@@ @@@@@ .....@ ### #@@@@@..... @......@@@@@@@@@ ....... @@@@@@@@@@@@@@  @@@@@@@\n";slow();
cout<<"@@@ @@@@@ .... @ ### @@@@@@.....@@ .....@ @@@@@@@@@@ .  @@@          @@@@@@@@@@@\n";slow();
cout<<"@@@@ @###@ .... @ ### @@@@@ .... @@ .....@ #  @@@@@@@@@@  ########%@@@@@@@@@@@@@\n";slow();
cout<<"@@@@@ @#@@@ .....@& ## @@@ .....@@@@ .... @ ####  #   ##########@@@@@@@@@@@@@@@@\n";slow();
cout<<"@@@@@  @#@@@ ......    ........@@@@@@@@@@@ ###################@@@@@@@@@@@@@@@@@@\n";slow();
cout<<"@@@@@@  @@@@@@ ............. @   @@@@   ,##################@@@@@@@@@@@@@@@@@@@@@\n";slow();
cout<<"@@@@@@@@ @@@@@@@@@     @@@@@  ### ######################@@@@@@@@@@@@@@@@@@@@@@@@\n";slow();
cout<<"@@@@@@@@@@  @@@@@@@@@@@@%  ########################&@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";slow();
cout<<"@@@@@@@@@@@@@@       (########################@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";slow();
cout<<"@@@@@@@@@@@@@@@@@@@@@#################%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";slow();
cout<<"\n\nUNO - Multiplayer card game presented by:\n";slow();
cout<<"ANANDITA"<<endl;slow();
cout<<"SHIVANG"<<endl;slow();
cout<<"AASTHA"<<endl;slow();
cout<<"PIYUSH"<<endl;slow();
slow();
slow();
slow();
slow();
slow();
slow();
slow();
slow();
slow();
slow();
}
};

//Card Info
typedef struct CardId //structure of card consisting of a row number and a column number
{
    int rowNo;
    int colNo;
}Id;
vector<int> col{0,1,2,3,4,5,6,7,8,9,10,11,12,13}; //vector to store available columns
vector<int> row{0,1,2,3,4,5,6,7};   //vector to store available rows
int cnup = 0;  //count the number of drawn cards and is used to check empty rows and columns, becomes 0 again after checking for empty rows and columns
int cnf = 0;   //count the number of drawn cards and is used to check whether deck is empty

int Deck[8][14]= {{0,0,0,0,0,0,0,0,0,0,0,0,0,0},    //Deck of the cards, arranged in the form of a 2D matrix. 0 and 1 here denotes the availability of cards
                  {0,0,0,0,0,0,0,0,0,0,0,0,0,0},    //0 means card is available and 1 means the space is empty
                  {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                  {1,0,0,0,0,0,0,0,0,0,0,0,0,0},
                  {1,0,0,0,0,0,0,0,0,0,0,0,0,0},
                  {1,0,0,0,0,0,0,0,0,0,0,0,0,0},
                  {1,0,0,0,0,0,0,0,0,0,0,0,0,0}};

void updateRow()  //after drawing cards from deck, it is possible that a row in the deck is completely empty. This function will delete those empty rows.
{
    for(int i=0; i<row.size(); i++)  //for loop navigating the rows
    {
        int flag=0;
        for(int j = 0; j<col.size(); j++)   //for loop navigating the columns
        {
            if(Deck[i][j]==0)   //if a card is available at any column in that particular row, break the loop
            {
                flag=1;
                break;
            }
        }
        if(flag==0) //flag will remain 0 if no card is available at that row, so delete that row
        {
            for(int k=0; k<row.size(); k++) //navigate through all the rows again
            {
                if(row[k]==i)   //make the row with all column empty, the last row
                {
                    int temp= row[k];
                    row[k]= row[row.size()-1];
                    row[row.size()-1]= temp;
                }
            }
            row.pop_back(); //pop the last row
        }
    }
}
void updateColumn()  //after drawing cards from deck, it is possible that a column in the deck is completely empty. This function will delete those empty columns.
{
    for(int i=0; i<col.size(); i++) //for loop navigating the columns
    {
        int flag=0;
        for(int j = 0; j<row.size(); j++)   //for loop navigating the rows
        {
            if(Deck[j][i]==0)   //if a card is available at any row in that particular column, break the loop
            {
                flag=1;
                break;
            }
        }
        if(flag==0) //flag will remain 0 if no card is available at that column, so delete that column
        {
            for(int k=0; k<col.size(); k++) //navigate through all the columns again
            {
                if(col[k]==i)   //make the column with all column empty, the last column
                {
                    int temp= col[k];
                    col[k]= col[col.size()-1];
                    col[col.size()-1]= temp;
                }
            }
            col.pop_back(); //pop the last row
        }
    }
}
void checkdeck()    //to check whether the deck is empty or not.
{
    if(cnf == 108)  //deck will become empty if we have drawn 108 cards from it
    {
        cout<<"The deck is empty. It's a draw."<<endl;
        exit(0);
    }
}
Id random()   //generates a random row and column number for the card and also keeps updating the deck's rows and columns accordingly
{
    srand(time(0)); //gives random function a starting point, by giving the time in second, makes sure that the random function does not produce the same sequence of cards everytime it's run
    Id card;    //creates a variable card of struct type ID
    cnup++;
    if(cnup>7) //7 is the number of rows, so it is the least number at which a column will get empty
    {
        updateRow();
        updateColumn();
        cnup=0;
    }
    int r = rand()%row.size();  //draws a row number
    int c = rand()%col.size();  //draws a column number
    card.rowNo= row[r];
    card.colNo= col[c];
    return card;
}

Id getCard()  //get a random card by using the random function. It will be used at the time of dealing and drawing cards. It also makes sure that it never gets an already drawn card
{
    Id card=random();   //calls random function

    while(Deck[card.rowNo][card.colNo]) //checks whether an empty card is drawn or not, if yes, then draws another card from the deck
    {
        card=random();
    }
    cnf++;
    checkdeck();    //checks if the deck is empty or not
    Deck[card.rowNo][card.colNo]=1; //assigns the drawn card value as 1 in the deck, which means that it is an empty space in the deck

    return card;
}


//Player Info
//For cards in the player's hands we have used a linked list structure

class hand   //Linked List structure of cards in player's hands
{
public:
    int rowNo;
    int colNo;
    hand* next;
};


class Player : public hand   //Hand class is inherited in Player so that it can share it's attributes
{
public:
    string name;    //stores name of the player
    hand* head=NULL;
public:
    void addCard()   //Used to add cards into the players hands
    {

        Id newCard = getCard();   //Id is the structure of the card which contains a row and a column number
        hand* newC=new hand();

        newC->rowNo=newCard.rowNo;
        newC->colNo=newCard.colNo;
        newC->next=NULL;
        if(head==NULL)
        {
            head=newC;
            return;
        }
        hand* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newC;

    }
    void delCard(int rno, int cno)        //Used to delete cards from the player's hands
    {
        hand* temp=head;
        hand* previous_chance=new hand();
        while(temp!=NULL)
        {
            if(cno==13) //checks if the card you want to play is a wild
            {
                if((temp->rowNo==rno||temp->rowNo==(rno+1)||temp->rowNo==(rno+2)||temp->rowNo==(rno+3)) && temp->colNo==cno)    //checks if you have a wild card in your hand
                {
                    if(temp==head)  //if it is the first card, make the second card the first card
                    {
                        head = head->next;
                    }
                    if(temp->next==NULL)    //if  it is the last card, make the previous card the last card
                    {
                        previous_chance->next=NULL;
                    }
                    previous_chance->next=temp->next;  //point the previous cards to the card that temp was pointing
                    break;
                }
            }
            else
            {
                if((temp->rowNo==rno||temp->rowNo==(rno+4)) && temp->colNo==cno)    //checks if the card in your hand matches the card you played
                {
                    if(temp==head)  //if it is the first card, make the second card the first card
                    {
                        head = head->next;
                    }
                    if(temp->next==NULL)    //if  it is the last card, make the previous card the last card
                    {
                        previous_chance->next=NULL;
                    }
                    previous_chance->next=temp->next;  //point the previous card to the card that temp was pointing
                    break;
                }
            }
            previous_chance=temp;  //make previous as temp
            temp=temp->next;    //upgrade temp
        }

    }
    int inlinked(int rno, int cno)  //to check if a card is present in the linked list
    {
        hand* temp = head;
        while(temp!= NULL)
        {
            if((temp->rowNo==rno||temp->rowNo==(rno+4)) && temp->colNo == cno)
            {
                return 1;
            }
            if(cno == 13 && (temp->rowNo==rno||temp->rowNo==(rno+1)||temp->rowNo==(rno+2)||temp->rowNo==(rno+3)) && temp->colNo==cno)
            {
                return 1;
            }
            temp = temp->next;
        }
        return 0;
    }
};

// Some major functions used in main

void displayCard(int r, int c)     //display card in the form of a string that is understandable by the user
{
     if(c==13)
    {
        cout<<"W";
        if(r<=3)
            cout<<"C";
        else
            cout<<"F";
        cout<<"\t";
        return;
    }
    if(r==0||r==4)
        cout<<"R";
    if(r==1||r==5)
        cout<<"Y";
    if(r==2||r==6)
        cout<<"G";
    if(r==3||r==7)
        cout<<"B";
    if(c<=9)
        cout<<c;
    if(c==10)
        cout<<"S";
    if(c==11)
        cout<<"R";
    if(c==12)
        cout<<"T";
    cout<<"\t";
}
int getRow(string card)      //returns an integer value according to the row name of the card, used in checking whether u have a particular card & whether that card can be played or not
{
    char ch=card[0];
    if(ch=='R')
        return 0;
    if(ch=='Y')
        return 1;
    if(ch=='G')
        return 2;
    if(ch=='B')
        return 3;
    if(ch=='W')
    {
        if(card[1]=='C')
            return 0;
        if(card[1]=='F')
            return 4;
    }
    return -1;
}
int getCol(string card)      //returns an integer value according to the column name of the card, used in checking whether u have a particular card & whether that card can be played or not
{
    char ch=card[1];
    if(ch=='S')
        return 10;
    if(ch=='R')
        return 11;
    if(ch=='T')
        return 12;
    if(ch=='F'||ch=='C')
        return 13;
    int num= (int)ch-48;
    return num;
}
bool checkCard(int r, int c, string s)  //checks if the card entered is playable of not, in order for a card to be playable, it either has to have
{
    int r1=getRow(s);                       //a) at least one matching attribute with the previous card played
    int c1=getCol(s);                       //b) be a wild card
    if(c1==13)  //checks if it is a wild card
    {
        return true;
    }
    else
    {
        if((r==r1||r==(r1+4)) || c==c1) //checks if it has at least one matching attribute with the previous card
        {
            return true;
        }
        else
        {
            return false;
        }
    }

}
void displayHand(hand* head1)   //displays all the cards in a player's hands
{
    hand* temp;
    temp=head1;
    do
    {
        displayCard(temp->rowNo,temp->colNo);
        temp=temp->next;
    }
    while(temp!=NULL);
    return;
}

int main()
{
    cout<<"UNO - Multiplayer Card Game"<<endl;
    start u;    //object for class start
    u.uno_d();
    system("cls");  //clears the output screen
    cout<<"UNO - Multiplayer Card Game"<<endl;
    int n;
    do{             //function will keep repatedly asking you to enter players unless you enter valid number of players
    cout<<"Enter number of players between 2 to 4"<<endl;
    cin>>n;
    if(n<=1 || n>=5)
        cout<<"Invalid number of players.\nEnter number of players again.\n";
    }
    while(n<=1 || n>=5);
    string p[n+1];  //array to store the name of the players
    for(int i=1; i<=n; i++)
    {
        cout<<"Enter name of Player: "<<i<<endl;
        cin>>p[i];
    }
    cout<<"Its time for some UNO!!"<<endl;
    cout<<"Loading..."<<endl;
    Player* players = new Player[n+1];  //creates n+1 objects of the class players
    for(int i=1; i<=n; i++)
    {
        cout<<p[i]<<"'s cards generating..."<<endl;
        players[i].name = p[i];

        for(int j=1; j<=7; j++)
        {
            players[i].addCard();
        }

    }
    int curr=1;       //Specifies which player is playing
    cout<<"Game Loaded"<<endl;
    Id TopCard = getCard(); //Gets the first card
    while(TopCard.colNo==13)    //checking whether it is not a wild card
    {
        Deck[TopCard.rowNo][TopCard.colNo]=0;   //if it is wild, put it back down
        TopCard = getCard();
    }
    string colour;   //to store color after wild card is played
    int previous_chance;      //to store previous value of curr, value of curr before it is updated
    int fla;    //flag for validity of a card
    string cardPlayed;  //to store card entered by user
    while(curr>=(-n) || curr<=n)   //condition is like this because reverse will turn curr into negative for reverse play of chances
    {
        previous_chance=curr;
        cout<<"\n\n\n"<<p[abs(curr)]<<"'s chance"<<endl; //absolute value of curr is taken because curr can have a negative value, on which no player would be availabke

        //Last played Card
        cout<<"Last Played card is : ";
        displayCard(TopCard.rowNo,TopCard.colNo);
        if(!colour.empty()) //for wild card
        {
            cout<<endl<<"Color switched to "<<colour;
            TopCard.rowNo=getRow(colour);
            colour="";
        }
        cout<<endl<<"Your hand is :\n";


        //Hand of the player

        displayHand(players[abs(curr)].head);


        //Card played by the player
        char choice;
        choose_move:    //will keep asking to enter a valid choice
        cout<<endl<<"What you wanna do \nDraw Card(enter D)/Play Card(P)"<<endl;
        fflush(stdin);
        cin>>choice;
            fflush(stdin);
            if(choice=='P')
            {
                    cout<<"Enter your card:"<<endl;

                    cin>>cardPlayed;
                    if(players[abs(curr)].inlinked(getRow(cardPlayed),getCol(cardPlayed)))   //checks if the card is present in your hand or not
                    {
                            if(checkCard(TopCard.rowNo,TopCard.colNo,cardPlayed))   //checks validity of card
                            {
                                TopCard.rowNo=getRow(cardPlayed);
                                TopCard.colNo=getCol(cardPlayed);
                                players[abs(curr)].delCard(getRow(cardPlayed),getCol(cardPlayed));   //delete that card from player's hand
                            }
                            else
                            {
                                cout<<endl<<"Invalid Card. Play again.\n";
                                goto choose_move;
                            }
                    }
                    else
                    {
                            cout<<"You don't have this card. Choose again.\n";
                            goto choose_move;
                    }
                }   //will repeatedly ask you to enter a valid card
            else if(choice=='D')
            {
                players[abs(curr)].addCard();
                cout<<"One Card added"<<endl;
                displayHand(players[abs(curr)].head);
            }
            else
            {
                cout<<endl<<"Invalid choice. Choose again.";
                goto choose_move;
            }

        if(players[abs(curr)].head==NULL)    //if there is no card in the player's linked list, they win
        {
            cout<<"Good Game!"<<players[abs(curr)].name<<" wins!!"<<endl;
            cout<<"Game Ended.";
            break;
        }
        //Updation of curr

        if(cardPlayed.compare("WF")==0 && choice != 'D')    //if the card played is draw 4
        {
            if(curr==n)       //if the person who played the card is the last person, make the first person draw cards
            {
                players[1].addCard();
                players[1].addCard();
                players[1].addCard();
                players[1].addCard();
            }
            else if(curr==-1)    // //if the person who played the card is the first person, but the order is reverse, make the last person draw cards
            {
                players[n].addCard();
                players[n].addCard();
                players[n].addCard();
                players[n].addCard();
            }
            else                                //otherwise make the next person draw cards
            {
                players[abs(curr+1)].addCard();
                players[abs(curr+1)].addCard();
                players[abs(curr+1)].addCard();
                players[abs(curr+1)].addCard();
            }
            cout<<"Which color do you want to be played - R,Y,G,B ?"<<endl;     //change colour
            cin>>colour;
            curr+=2;                                                             //upgrade curr
        }
        else if(cardPlayed.compare("WC")==0 && choice != 'D')       //if the card played is wild, change colour
        {
            cout<<"Which color do you want to be played - R,Y,G,B?"<<endl;
            cin>>colour;
            curr++;
        }
        else if(cardPlayed[1]=='T' && choice != 'D')    //if the card played is draw 2
        {
            if(curr==n)     //if the person who played the card is the last person, make the first person draw cards
            {
                players[1].addCard();
                players[1].addCard();
            }
            else if(curr==-1)    // //if the person who played the card is the first person, but the order is reverse, make the last person draw cards
            {
                players[n].addCard();
                players[n].addCard();
            }
            else                                //otherwise make the next person draw cards
            {
                players[abs(curr+1)].addCard();
                players[abs(curr+1)].addCard();
            }
            curr+=2;     //change rotation
        }
        else if(cardPlayed[1]=='S' && choice != 'D')    //if the card played is skip
        {
            curr+=2;
        }
        else if(cardPlayed[1]=='R' && choice != 'D')    //if the card played is reverese
        {
            curr=-curr;   //reverse the rotation
            curr++;
        }
        else
        {
            curr++;
        }
        if(previous_chance<0)      //if curr before upgradation was negative
        {
            if(curr==0)  //if curr after upgradation becomes 0, update it to -n (first player in reverse)
            {
                curr=-n;
            }
            if(curr==1)  //if curr after upgradation becomes 1, update it to -n+1, (second player in reverse)
            {
                curr=-n+1;
            }
        }
        else if(previous_chance>0) //if curr before upgradation was positive
        {
            if(curr==n+1)    //if curr after upgradation becomes n+1, update it to 1 (first player)
                curr=1;
            if(curr==n+2)    //if curr after upgradation becomes 1+2, update it to 2 (second player)
                curr=2;
            if(curr==0)  //if curr after upgradation becomes 0, update it to -n (first player in reverse order)
                curr=-n;
        }
    }
    return 0;
}
//Thank You
