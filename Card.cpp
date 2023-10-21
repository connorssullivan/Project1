#include "Card.h"

////////////////////////////////////////////////////////////////////////////////////////////////
                            //Constructor //
////////////////////////////////////////////////////////////////////////////////////////////////
Card::Card(){
    nextCard = 0;
    for(int suit = SPADE; suit <= DIAMOND; suit++){
        for(int rank = ACE; rank <= KING; rank++){
            //Update next card
            ++nextCard;

            //Create new card
            Acard newCard;
            deck.push_back(newCard);

            //Set card Rank
            newCard.num = rank;

            //Switch to set card suite
            switch(suit) {
                //Set pic as spade
                case SPADE:
                    strcpy(newCard.pic, spade);
                    break;
                
                //Set pic as club
                case CLUB:
                    strcpy(newCard.pic, club);
                    break;

                //Set pic to heart
                case HEART:
                    strcpy(newCard.pic, heart);
                    break;

                //Set pic to diamond
                case DIAMOND: 
                    strcpy(newCard.pic, diamond);
                    break;

            }

            
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////
                            //DeConstructor //
////////////////////////////////////////////////////////////////////////////////////////////////
Card::~Card(){
    Node* curr;
    Node* nx;

    //Go through the heads array
    for(int i = 0; i < heads.size();i++){
        curr = heads[i];

        //Delete each node
        while(curr){
            nx = curr->next;
            delete curr;
            curr = nx;
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////
                            //Get card Function //
////////////////////////////////////////////////////////////////////////////////////////////////
void Card::getCardFunc(Acard card,int row){
    int num = card.num;
    
    switch (num)
    {
    case ACE:
        cardAce(card.pic, row);
        break;
    case TWO:
        cardTwo(card.pic, row);
        break;
    case THREE: 
        cardThree(card.pic, row);
        break;
    case FOUR:
        cardFour(card.pic, row);
        break;
    case FIVE:
        cardFive(card.pic, row);
        break;
    case SIX:
        cardSix(card.pic, row);
        break;
    case SEVAN:
        cardSeven(card.pic, row);
        break;
    case EIGHT:
        cardEight(card.pic, row);
        break;
    case NINE:
        cardNine(card.pic, row);
        break;
    case TEN:
        cardTen(card.pic, row);
        break;
    case JACK:
        cardJack(card.pic, row);
        break;
    case QUEEN:
        cardQueen(card.pic, row);
        break;
    case KING:
        cardKing(card.pic, row);
        break;

    default:
        cardAce(card.pic, row);
        break;
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////
                            //Print Cards //
////////////////////////////////////////////////////////////////////////////////////////////////
void Card::printCards(int cols, int max, vector<Acard> dk){
    
    
}

//Card 9x7 middle at  5,3
//‾‾‾‾‾‾‾

////////////////////////////////////////////////////////////////////////////////////////////////
                            //Print Deck Part 1 Test//
////////////////////////////////////////////////////////////////////////////////////////////////
void Card::printDeckPart1Test(){
    //Allocate all lines for printing
    for(int size = 2; size < 6; size++){
        createHeads(size, size);//
    
    }

    //Put all lines in correct list
    int rowLength = 2;//For the row length
    for(int i = 0; i < heads.size(); i+=11){

            //If deck is out of cards
            if(nextCard < 0)
                break;
            for(int j = rowLength; j > 0;j--){

                //If deck is out of cards
                if(nextCard < 0)
                    break;
                getCardFunc(deck[nextCard-1], i);//get correct card function
                nextCard--;//Iterate through cards

            }
            ++rowLength;//update row length
        }

    //Print cards
    Node* curr;
    for(int i = 0; i < heads.size(); i++){
        curr = heads[i];
        while(curr){
            cout << curr->str;
            curr = curr->next;
        }
    }


    
}


////////////////////////////////////////////////////////////////////////////////////////////////
                            //Get Pic //
////////////////////////////////////////////////////////////////////////////////////////////////
char* Card::getPic(Acard* card){
    char* pic = card->pic;
    return pic;
}

////////////////////////////////////////////////////////////////////////////////////////////////
                            //Shuffle Cards //
////////////////////////////////////////////////////////////////////////////////////////////////
void Card::shuffleCard(){
    //Set up randon generator
    int r;
    srand((unsigned) time(NULL));
    //Go through cards
    for(int i = nextCard-1; i > 0;i--){

        //Generate random number between 0 and i
        r = rand() %(i+1);

        //Swap cards
        Acard* temp = &deck[r];
        deck[r] = deck[i];
        deck[i] = *temp;

    }
}

////////////////////////////////////////////////////////////////////////////////////////////////
                            //Create heads //
////////////////////////////////////////////////////////////////////////////////////////////////
void Card::createHeads(int numberOfCards, int cols){
    int numberOfRows = (numberOfCards/cols)*11; //Get the number of rows
    //Make the heads of each line
    for(int i = 0; i < numberOfRows; i++){
        //cout << "Head #" << i << endl;
        //Make new head
        Node* head = new Node;
        head->next = NULL;
        strcpy(head->str, "\n");

        //Push back head 
        heads.push_back(head);

        //If enough space is allocated
        if(i*cols >= numberOfCards*11)
            break;


    }
    
}

////////////////////////////////////////////////////////////////////////////////////////////////
                            //Start Of Card Functions //
////////////////////////////////////////////////////////////////////////////////////////////////
void Card::cardAce(const char card[], int row) {
    Node* curr;
    Node* line;
    
    // Loop through each line 
    for (int i = 0; i < 11; i++) {
        curr = heads[row + i];
        line = new Node;
        line->next = nullptr;

        //Top of card
        if (i == 0) {
            strcpy(line->str, " _____ ");
        } 
        else if (i == 1) {
            strcpy(line->str, "|A    |");
        } 
        
        //Middle of card
        else if (i == 6) {
            strcpy(line->str, "|  ");
            strcat(line->str, card);
            strcat(line->str, "  |");
        } 
        
        //Bottom of card
        else if (i == 10) {
            strcpy(line->str, " ‾‾‾‾‾ ");
        } 

        
        //Bottom of card
        else if (i == 9) {
            strcpy(line->str, "|    A|");
        } 

        //Body of card
        else {
            strcpy(line->str, "|     |");
        }

        //Update the list
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = line;
    }
}

void Card::cardTwo(const char card[], int row) {
    Node* curr;
    Node* line;
    
    // Loop through each line 
    for (int i = 0; i < 11; i++) {
        curr = heads[row + i];
        line = new Node;
        line->next = nullptr;

        //Top of card
        if (i == 0) {
            strcpy(line->str, " _____ ");
        } 
        else if (i == 1) {
            strcpy(line->str, "|2    |");
        } 
        
        //Middle of card
        else if (i == 2 || i == 6) {
            strcpy(line->str, "|  ");
            strcat(line->str, card);
            strcat(line->str, "  |");
        } 
        
        //Bottom of card
        else if (i == 9) {
            strcpy(line->str, "|    2|");
        } 
        else if (i == 10) {
            strcpy(line->str, " ‾‾‾‾‾ ");
        } 

        //Body of card
        else {
            strcpy(line->str, "|     |");
        }

        while (curr->next) {
            curr = curr->next;
        }
        curr->next = line;
    }
}


void Card::cardThree(const char card[], int row) {
    Node* curr;
    Node* line;
    
    // Loop through each line 
    for (int i = 0; i < 11; i++) {
        curr = heads[row + i];
        line = new Node;
        line->next = nullptr;

        //Top of card
        if (i == 0) {
            strcpy(line->str, " _____ ");
        } 
        else if (i == 1) {
            strcpy(line->str, "|3    |");
        } 
        
        //Middle of card
        else if (i == 3 || i == 5 || i == 7) {
            strcpy(line->str, "|  ");
            strcat(line->str, card);
            strcat(line->str, "  |");
        } 

        
        //Bottom of card
        else if (i == 9) {
            strcpy(line->str, "|    3|");
        } 
        else if (i == 10) {
            strcpy(line->str, " ‾‾‾‾‾ ");
        } 

        //Body of card
        else {
            strcpy(line->str, "|     |");
        }

        while (curr->next) {
            curr = curr->next;
        }
        curr->next = line;
    }
}


void Card::cardFour(const char card[], int row) {
    Node* curr;
    Node* line;
    
    // Loop through each line 
    for (int i = 0; i < 11; i++) {
        curr = heads[row + i];
        line = new Node;
        line->next = nullptr;

        //Top of card
        if (i == 0) {
            strcpy(line->str, " _____ ");
        } 
        else if (i == 1) {
            strcpy(line->str, "|4    |");
        } 
        
        //Middle of card
        else if (i == 2 || i == 8) {
            strcpy(line->str, "| ");
            strcat(line->str, card);
            strcat(line->str, " ");
            strcat(line->str, card);
            strcat(line->str, " |");
        } 
        
        //Bottom of card
        else if (i == 9) {
            strcpy(line->str, "|    4|");
        } 
        else if (i == 10) {
            strcpy(line->str, " ‾‾‾‾‾ ");
        } 

        //Body of card
        else {
            strcpy(line->str, "|     |");
        }

        while (curr->next) {
            curr = curr->next;
        }
        curr->next = line;
    }
}


void Card::cardFive(const char card[], int row) {
    Node* curr;
    Node* line;
    
    // Loop through each line 
    for (int i = 0; i < 11; i++) {
        curr = heads[row + i];
        line = new Node;
        line->next = nullptr;

        //Top of card
        if (i == 0) {
            strcpy(line->str, " _____ ");
        } 
        else if (i == 1) {
            strcpy(line->str, "|5    |");
        } 
        

        //Middle
        else if (i == 2 || i == 8) {
            strcpy(line->str, "| ");
            strcat(line->str, card);
            strcat(line->str, " ");
            strcat(line->str, card);
            strcat(line->str, " |");
        } 
        else if (i == 5) {
            strcpy(line->str, "|  ");
            strcat(line->str, card);
            strcat(line->str, "  |");
        } 
        else if (i == 10) {
            strcpy(line->str, " ‾‾‾‾‾ ");
        } 

        //Body of card
        else {
            strcpy(line->str, "|     |");
        }

        while (curr->next) {
            curr = curr->next;
        }
        curr->next = line;
    }
}


void Card::cardSix(const char card[], int row) {
    Node* curr;
    Node* line;
    
    // Loop through each line 
    for (int i = 0; i < 11; i++) {
        curr = heads[row + i];
        line = new Node;
        line->next = nullptr;

        //Top of card
        if (i == 0) {
            strcpy(line->str, " _____ ");
        } 
        else if (i == 1) {
            strcpy(line->str, "|6    |");
        } 
        
        else if (i == 2 || i == 5 ||  i == 8) {
            strcpy(line->str, "| ");
            strcat(line->str, card);
            strcat(line->str, " ");
            strcat(line->str, card);
            strcat(line->str, " |");
        } 
        
        //Bottom of card
        else if (i == 9) {
            strcpy(line->str, "|    6|");
        } 
        else if (i == 10) {
            strcpy(line->str, " ‾‾‾‾‾ ");
        } 

        //Body of card
        else {
            strcpy(line->str, "|     |");
        }

        while (curr->next) {
            curr = curr->next;
        }
        curr->next = line;
    }
}


void Card::cardSeven(const char card[], int row) {
    Node* curr;
    Node* line;
    
    // Loop through each line 
    for (int i = 0; i < 11; i++) {
        curr = heads[row + i];
        line = new Node;
        line->next = nullptr;

        //Top of card
        if (i == 0) {
            strcpy(line->str, " _____ ");
        } 
        else if (i == 1) {
            strcpy(line->str, "|7    |");
        } 
        
        //Middle of card
        else if (i == 2 || i == 5 ||  i == 8) {
            strcpy(line->str, "| ");
            strcat(line->str, card);
            strcat(line->str, " ");
            strcat(line->str, card);
            strcat(line->str, " |");
        } 
        else if (i == 3) {
            strcpy(line->str, "|  ");
            strcat(line->str, card);
            strcat(line->str, "  |");
        } 
        
        //Bottom of card
        else if (i == 9) {
            strcpy(line->str, "|    7|");
        } 
        else if (i == 10) {
            strcpy(line->str, " ‾‾‾‾‾ ");
        } 

        //Body of card
        else {
            strcpy(line->str, "|     |");
        }

        while (curr->next) {
            curr = curr->next;
        }
        curr->next = line;
    }
}


void Card::cardEight(const char card[], int row) {
    Node* curr;
    Node* line;
    
    // Loop through each line 
    for (int i = 0; i < 11; i++) {
        curr = heads[row + i];
        line = new Node;
        line->next = nullptr;

        //Top of card
        if (i == 0) {
            strcpy(line->str, " _____ ");
        } 
        else if (i == 1) {
            strcpy(line->str, "|8    |");
        } 
        
        //Middle of card
        else if (i == 2 || i == 5 ||  i == 8) {
            strcpy(line->str, "| ");
            strcat(line->str, card);
            strcat(line->str, " ");
            strcat(line->str, card);
            strcat(line->str, " |");
        } 
        else if (i == 3 || i == 7) {
            strcpy(line->str, "|  ");
            strcat(line->str, card);
            strcat(line->str, "  |");
        } 
        
        
        //Bottom of card
        else if (i == 9) {
            strcpy(line->str, "|    8|");
        } 
        else if (i == 10) {
            strcpy(line->str, " ‾‾‾‾‾ ");
        } 

        //Body of card
        else {
            strcpy(line->str, "|     |");
        }

        while (curr->next) {
            curr = curr->next;
        }
        curr->next = line;
    }
}


void Card::cardNine(const char card[], int row) {
    Node* curr;
    Node* line;
    
    // Loop through each line 
    for (int i = 0; i < 11; i++) {
        curr = heads[row + i];
        line = new Node;
        line->next = nullptr;

        //Top of card
        if (i == 0) {
            strcpy(line->str, " _____ ");
        } 
        else if (i == 1) {
            strcpy(line->str, "|9    |");
        } 
        
        //Middle of card
        else if (i == 2 || i == 4 || i == 6 || i == 8) {
            strcpy(line->str, "| ");
            strcat(line->str, card);
            strcat(line->str, " ");
            strcat(line->str, card);
            strcat(line->str, " |");
        } 
        else if (i == 3) {
            strcpy(line->str, "|  ");
            strcat(line->str, card);
            strcat(line->str, "  |");
        } 
        
        
        //Bottom of card
        else if (i == 9) {
            strcpy(line->str, "|    9|");
        } 
        else if (i == 10) {
            strcpy(line->str, " ‾‾‾‾‾ ");
        } 

        //Body of card
        else {
            strcpy(line->str, "|     |");
        }

        while (curr->next) {
            curr = curr->next;
        }
        curr->next = line;
    }
}


void Card::cardTen(const char card[], int row) {
    Node* curr;
    Node* line;
    
    // Loop through each line 
    for (int i = 0; i < 11; i++) {
        curr = heads[row + i];
        line = new Node;
        line->next = nullptr;

        //Top of card
        if (i == 0) {
            strcpy(line->str, " _____ ");
        } 
        else if (i == 1) {
            strcpy(line->str, "|10   |");
        } 
        
        //Middle of card
        else if (i == 2 || i == 4 || i == 6 || i == 8) {
            strcpy(line->str, "| ");
            strcat(line->str, card);
            strcat(line->str, " ");
            strcat(line->str, card);
            strcat(line->str, " |");
        } 
        else if (i == 3 || i == 7) {
            strcpy(line->str, "|  ");
            strcat(line->str, card);
            strcat(line->str, "  |");
        } 
        
        //Bottom of card
        else if (i == 9) {
            strcpy(line->str, "|   10|");
        } 
        else if (i == 10) {
            strcpy(line->str, " ‾‾‾‾‾ ");
        } 

        //Body of card
        else {
            strcpy(line->str, "|     |");
        }

        while (curr->next) {
            curr = curr->next;
        }
        curr->next = line;
    }
}


void Card::cardJack(const char card[], int row) {
    Node* curr;
    Node* line;
    
    // Loop through each line 
    for (int i = 0; i < 11; i++) {
        curr = heads[row + i];
        line = new Node;
        line->next = nullptr;

        //Top of card
        if (i == 0) {
            strcpy(line->str, " _____ ");
        } 
        else if (i == 1) {
            strcpy(line->str, "|J    |");
        } 
        
        //Middle of card
        else if (i == 5) {
            strcpy(line->str, "|  ");
            strcat(line->str, card);
            strcat(line->str, "  |");
        } 
        
        //Bottom of card
        else if (i == 9) {
            strcpy(line->str, "|    J|");
        } 
        else if (i == 10) {
            strcpy(line->str, " ‾‾‾‾‾ ");
        } 

        //Body of card
        else {
            strcpy(line->str, "|     |");
        }

        while (curr->next) {
            curr = curr->next;
        }
        curr->next = line;
    }
}


void Card::cardQueen(const char card[], int row) {
    Node* curr;
    Node* line;
    
    // Loop through each line 
    for (int i = 0; i < 11; i++) {
        curr = heads[row + i];
        line = new Node;
        line->next = nullptr;

        //Top of card
        if (i == 0) {
            strcpy(line->str, " _____ ");
        } 
        else if (i == 1) {
            strcpy(line->str, "|Q    |");
        } 
        
        //Middle of card
        else if (i == 5) {
            strcpy(line->str, "|  ");
            strcat(line->str, card);
            strcat(line->str, "  |");
        } 
        
        //Bottom of card
        else if (i == 9) {
            strcpy(line->str, "|    Q|");
        } 
        else if (i == 10) {
            strcpy(line->str, " ‾‾‾‾‾ ");
        } 

        //Body of card
        else {
            strcpy(line->str, "|     |");
        }

        while (curr->next) {
            curr = curr->next;
        }
        curr->next = line;
    }
}


void Card::cardKing(const char card[], int row) {
    Node* curr;
    Node* line;
    
    // Loop through each line 
    for (int i = 0; i < 11; i++) {
        curr = heads[row + i];
        line = new Node;
        line->next = nullptr;

        //Top of card
        if (i == 0) {
            strcpy(line->str, " _____ ");
        } 
        else if (i == 1) {
            strcpy(line->str, "|K    |");
        } 
        
        //Middle of card
        else if (i ==5) {
            strcpy(line->str, "|  ");
            strcat(line->str, card);
            strcat(line->str, "  |");
        } 
        
        //Bottom of card
        else if (i == 9) {
            strcpy(line->str, "|    K|");
        } 
        else if (i == 10) {
            strcpy(line->str, " ‾‾‾‾‾ ");
        } 

        //Body of card
        else {
            strcpy(line->str, "|     |");
        }

        while (curr->next) {
            curr = curr->next;
        }
        curr->next = line;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////
                            //End Of Card Functions //
////////////////////////////////////////////////////////////////////////////////////////////////





//Saved code
/*
void Card::cardAce(const char card[]){
    //print firat half of card
    cout << " _______";
    cout <<"\n|A      |";
    for(int i = 0;i< 3; i++)
        cout <<"\n|       |";
    //See if its a spade
    if(strcmp(card,spade)){
        //Print the spade
        cout << "\n|   " << spade <<"   |";
    }
    //Club
    else if(strcmp(card,club)){
        //Print the Club
        cout << "\n|   " << club <<"   |";
    }

    //Heart
    else if(strcmp(card,heart)){
        //Print the Heart
        cout << "\n|   " << heart <<"   |";
    }

    //Diamond
    else if(strcmp(card,spade)){
        //Print theDiamond
        cout << "\n|   " << diamond <<"   |";
    }

    else{
        
        cout << "\n|   " << " " <<"   |";
    }

    //Print bottom portion of card
    for(int i = 0;i< 3; i++)
        cout <<"\n|       |";
    cout <<"\n|      A|";
    cout << "\n ‾‾‾‾‾‾‾";
    cout << endl;

}



void Card::cardTwo(const char card[]){
    //print firat half of card
    cout << " _______";
    cout <<"\n|2      |";
    for(int i = 0;i< 3; i++)
        cout <<"\n|       |";
    //See if its a spade
    if(strcmp(card,spade)){
        //Print the spade
        cout << "\n|   " << spade <<"   |";
    }
    //Club
    else if(strcmp(card,club)){
        //Print the Club
        cout << "\n|   " << club <<"   |";
    }

    //Heart
    else if(strcmp(card,heart)){
        //Print the Heart
        cout << "\n|   " << heart <<"   |";
    }

    //Diamond
    else if(strcmp(card,spade)){
        //Print theDiamond
        cout << "\n|   " << diamond <<"   |";
    }

    else{
        
        cout << "\n|   " << " " <<"   |";
    }

    //Print bottom portion of card
    for(int i = 0;i< 3; i++)
        cout <<"\n|       |";
    cout <<"\n|      2|";
    cout << "\n ‾‾‾‾‾‾‾";
    cout << endl;
}


void Card::cardThree(const char card[]){
    //print firat half of card
    cout << " _______";
    cout <<"\n|3      |";
    for(int i = 0;i< 3; i++)
        cout <<"\n|       |";
    //See if its a spade
    if(strcmp(card,spade)){
        //Print the spade
        cout << "\n|   " << spade <<"   |";
    }
    //Club
    else if(strcmp(card,club)){
        //Print the Club
        cout << "\n|   " << club <<"   |";
    }

    //Heart
    else if(strcmp(card,heart)){
        //Print the Heart
        cout << "\n|   " << heart <<"   |";
    }

    //Diamond
    else if(strcmp(card,spade)){
        //Print theDiamond
        cout << "\n|   " << diamond <<"   |";
    }

    else{
        
        cout << "\n|   " << " " <<"   |";
    }

    //Print bottom portion of card
    for(int i = 0;i< 3; i++)
        cout <<"\n|       |";
    cout <<"\n|      3|";
    cout << "\n ‾‾‾‾‾‾‾";
    cout << endl;
}


void Card::cardFour(const char card[]){
    //print firat half of card
    cout << " _______";
    cout <<"\n|4      |";
    for(int i = 0;i< 3; i++)
        cout <<"\n|       |";
    //See if its a spade
    if(strcmp(card,spade)){
        //Print the spade
        cout << "\n|   " << spade <<"   |";
    }
    //Club
    else if(strcmp(card,club)){
        //Print the Club
        cout << "\n|   " << club <<"   |";
    }

    //Heart
    else if(strcmp(card,heart)){
        //Print the Heart
        cout << "\n|   " << heart <<"   |";
    }

    //Diamond
    else if(strcmp(card,spade)){
        //Print theDiamond
        cout << "\n|   " << diamond <<"   |";
    }

    else{
        
        cout << "\n|   " << " " <<"   |";
    }

    //Print bottom portion of card
    for(int i = 0;i< 3; i++)
        cout <<"\n|       |";
    cout <<"\n|      4|";
    cout << "\n ‾‾‾‾‾‾‾";
    cout << endl;
}


void Card::cardFive(const char card[]){
    //print firat half of card
    cout << " _______";
    cout <<"\n|5      |";
    for(int i = 0;i< 3; i++)
        cout <<"\n|       |";
    //See if its a spade
    if(strcmp(card,spade)){
        //Print the spade
        cout << "\n|   " << spade <<"   |";
    }
    //Club
    else if(strcmp(card,club)){
        //Print the Club
        cout << "\n|   " << club <<"   |";
    }

    //Heart
    else if(strcmp(card,heart)){
        //Print the Heart
        cout << "\n|   " << heart <<"   |";
    }

    //Diamond
    else if(strcmp(card,spade)){
        //Print theDiamond
        cout << "\n|   " << diamond <<"   |";
    }

    else{
        
        cout << "\n|   " << " " <<"   |";
    }

    //Print bottom portion of card
    for(int i = 0;i< 3; i++)
        cout <<"\n|       |";
    cout <<"\n|      5|";
    cout << "\n ‾‾‾‾‾‾‾";
    cout << endl;
}


void Card::cardSix(const char card[]){
    //print firat half of card
    cout << " _______";
    cout <<"\n|6      |";
    for(int i = 0;i< 3; i++)
        cout <<"\n|       |";
    //See if its a spade
    if(strcmp(card,spade)){
        //Print the spade
        cout << "\n|   " << spade <<"   |";
    }
    //Club
    else if(strcmp(card,club)){
        //Print the Club
        cout << "\n|   " << club <<"   |";
    }

    //Heart
    else if(strcmp(card,heart)){
        //Print the Heart
        cout << "\n|   " << heart <<"   |";
    }

    //Diamond
    else if(strcmp(card,spade)){
        //Print theDiamond
        cout << "\n|   " << diamond <<"   |";
    }

    else{
        
        cout << "\n|   " << " " <<"   |";
    }

    //Print bottom portion of card
    for(int i = 0;i< 3; i++)
        cout <<"\n|       |";
    cout <<"\n|      6|";
    cout << "\n ‾‾‾‾‾‾‾";
    cout << endl;
}


void Card::cardSeven(const char card[]){
    //print firat half of card
    cout << " _______";
    cout <<"\n|7      |";
    for(int i = 0;i< 3; i++)
        cout <<"\n|       |";
    //See if its a spade
    if(strcmp(card,spade)){
        //Print the spade
        cout << "\n|   " << spade <<"   |";
    }
    //Club
    else if(strcmp(card,club)){
        //Print the Club
        cout << "\n|   " << club <<"   |";
    }

    //Heart
    else if(strcmp(card,heart)){
        //Print the Heart
        cout << "\n|   " << heart <<"   |";
    }

    //Diamond
    else if(strcmp(card,spade)){
        //Print theDiamond
        cout << "\n|   " << diamond <<"   |";
    }

    else{
        
        cout << "\n|   " << " " <<"   |";
    }

    //Print bottom portion of card
    for(int i = 0;i< 3; i++)
        cout <<"\n|       |";
    cout <<"\n|      7|";
    cout << "\n ‾‾‾‾‾‾‾";
    cout << endl;
}


void Card::cardEight(const char card[]){
    //print firat half of card
    cout << " _______";
    cout <<"\n|8      |";
    for(int i = 0;i< 3; i++)
        cout <<"\n|       |";
    //See if its a spade
    if(strcmp(card,spade)){
        //Print the spade
        cout << "\n|   " << spade <<"   |";
    }
    //Club
    else if(strcmp(card,club)){
        //Print the Club
        cout << "\n|   " << club <<"   |";
    }

    //Heart
    else if(strcmp(card,heart)){
        //Print the Heart
        cout << "\n|   " << heart <<"   |";
    }

    //Diamond
    else if(strcmp(card,spade)){
        //Print theDiamond
        cout << "\n|   " << diamond <<"   |";
    }

    else{
        
        cout << "\n|   " << " " <<"   |";
    }

    //Print bottom portion of card
    for(int i = 0;i< 3; i++)
        cout <<"\n|       |";
    cout <<"\n|      8|";
    cout << "\n ‾‾‾‾‾‾‾";
    cout << endl;
}


void Card::cardNine(const char card[]){
    //print firat half of card
    cout << " _______";
    cout <<"\n|9      |";
    for(int i = 0;i< 3; i++)
        cout <<"\n|       |";
    //See if its a spade
    if(strcmp(card,spade)){
        //Print the spade
        cout << "\n|   " << spade <<"   |";
    }
    //Club
    else if(strcmp(card,club)){
        //Print the Club
        cout << "\n|   " << club <<"   |";
    }

    //Heart
    else if(strcmp(card,heart)){
        //Print the Heart
        cout << "\n|   " << heart <<"   |";
    }

    //Diamond
    else if(strcmp(card,spade)){
        //Print theDiamond
        cout << "\n|   " << diamond <<"   |";
    }

    else{
        
        cout << "\n|   " << " " <<"   |";
    }

    //Print bottom portion of card
    for(int i = 0;i< 3; i++)
        cout <<"\n|       |";
    cout <<"\n|      9|";
    cout << "\n ‾‾‾‾‾‾‾";
    cout << endl;
}


void Card::cardTen(const char card[]){
    //print firat half of card
    cout << " _______";
    cout <<"\n|10     |";
    for(int i = 0;i< 3; i++)
        cout <<"\n|       |";
    //See if its a spade
    if(strcmp(card,spade)){
        //Print the spade
        cout << "\n|   " << spade <<"   |";
    }
    //Club
    else if(strcmp(card,club)){
        //Print the Club
        cout << "\n|   " << club <<"   |";
    }

    //Heart
    else if(strcmp(card,heart)){
        //Print the Heart
        cout << "\n|   " << heart <<"   |";
    }

    //Diamond
    else if(strcmp(card,spade)){
        //Print theDiamond
        cout << "\n|   " << diamond <<"   |";
    }

    else{
        
        cout << "\n|   " << " " <<"   |";
    }

    //Print bottom portion of card
    for(int i = 0;i< 3; i++)
        cout <<"\n|       |";
    cout <<"\n|     10|";
    cout << "\n ‾‾‾‾‾‾‾";
    cout << endl;
}


void Card::cardJack(const char card[]){
    //print firat half of card
    cout << " _______";
    cout <<"\n|J      |";
    for(int i = 0;i< 3; i++)
        cout <<"\n|       |";
    //See if its a spade
    if(strcmp(card,spade)){
        //Print the spade
        cout << "\n|   " << spade <<"   |";
    }
    //Club
    else if(strcmp(card,club)){
        //Print the Club
        cout << "\n|   " << club <<"   |";
    }

    //Heart
    else if(strcmp(card,heart)){
        //Print the Heart
        cout << "\n|   " << heart <<"   |";
    }

    //Diamond
    else if(strcmp(card,spade)){
        //Print theDiamond
        cout << "\n|   " << diamond <<"   |";
    }

    else{
        
        cout << "\n|   " << " " <<"   |";
    }

    //Print bottom portion of card
    for(int i = 0;i< 3; i++)
        cout <<"\n|       |";
    cout <<"\n|      J|";
    cout << "\n ‾‾‾‾‾‾‾";
    cout << endl;
}


void Card::cardQueen(const char card[]){
    //print firat half of card
    cout << " _______";
    cout <<"\n|Q      |";
    for(int i = 0;i< 3; i++)
        cout <<"\n|       |";
    //See if its a spade
    if(strcmp(card,spade)){
        //Print the spade
        cout << "\n|   " << spade <<"   |";
    }
    //Club
    else if(strcmp(card,club)){
        //Print the Club
        cout << "\n|   " << club <<"   |";
    }

    //Heart
    else if(strcmp(card,heart)){
        //Print the Heart
        cout << "\n|   " << heart <<"   |";
    }

    //Diamond
    else if(strcmp(card,spade)){
        //Print theDiamond
        cout << "\n|   " << diamond <<"   |";
    }

    else{
        
        cout << "\n|   " << " " <<"   |";
    }

    //Print bottom portion of card
    for(int i = 0;i< 3; i++)
        cout <<"\n|       |";
    cout <<"\n|      Q|";
    cout << "\n ‾‾‾‾‾‾‾";
    cout << endl;
}


void Card::cardKing(const char card[]){
    //print firat half of card
    cout << " _______";
    cout <<"\n|K      |";
    for(int i = 0;i< 3; i++)
        cout <<"\n|       |";
    //See if its a spade
    if(strcmp(card,spade)){
        //Print the spade
        cout << "\n|   " << spade <<"   |";
    }
    //Club
    else if(strcmp(card,club)){
        //Print the Club
        cout << "\n|   " << club <<"   |";
    }

    //Heart
    else if(strcmp(card,heart)){
        //Print the Heart
        cout << "\n|   " << heart <<"   |";
    }

    //Diamond
    else if(strcmp(card,spade)){
        //Print theDiamond
        cout << "\n|   " << diamond <<"   |";
    }

    else{
        
        cout << "\n|   " << " " <<"   |";
    }

    //Print bottom portion of card
    for(int i = 0;i< 3; i++)
        cout <<"\n|       |";
    cout <<"\n|      K|";
    cout << "\n ‾‾‾‾‾‾‾";
    cout << endl;
}




void Card::printCard(Acard* card){
    //Get card rank and suite
    int num = card->num;
    char* suite = card->pic;

    //Determine which card it is
    switch(num){
        case ACE:
            cardAce(suite);
            break;
        case TWO:
            cardTwo(suite);
            break;
        case THREE:
            cardThree(suite);
            break;
        case FOUR:
            cardFour(suite);
            break;
        case FIVE:
            cardFive(suite);
            break;
        case SIX:
            cardSix(suite);
            break;
        case SEVAN:
            cardSeven(suite);
            break;
        case EIGHT:
            cardEight(suite);
            break;
        case NINE:
            cardNine(suite);
            break;
        case TEN:
            cardTen(suite);
            break;
        case JACK:
            cardJack(suite);
            break;
        case QUEEN:
            cardQueen(suite);
            break;
        case KING: 
            cardKing(suite);
            break;

    }

}
*/
