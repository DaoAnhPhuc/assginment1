#include "knight.h"



int const maxEvent = 1000;
int eventList[maxEvent];
string bonusEventList[maxEvent];

int HP, level, remedy, maidenkiss,  phoenixdown,  rescue;

int const maxHP = HP;

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue) {
    cout << "HP=" << HP
        << ", level=" << level
        << ", remedy=" << remedy
        << ", maidenkiss=" << maidenkiss
        << ", phoenixdown=" << phoenixdown
        << ", rescue=" << rescue << endl;
}

void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue) {


    
    
    fileReader( file_input);

    //start quest
  

}

void fileReader (string file_input)  {

    // int maxEvent = 1000;

    fstream inputFile ;

    inputFile.open(file_input, ios::in);

    string knightAndEvent[3];

    string knightInfo = knightAndEvent[0];

    // string eventList = knightAndEvent[1];

    string textData;

    //array of knight stats

    int knight[6];

    // int eventList[maxEvent];


    if (inputFile.is_open())
    {
        int index = 0;
        int bonusIndex = 0;
        
        
        while ( !inputFile.eof())
        {
            if (index == 2)
           {
                while (!inputFile.eof())
                    {
                        getline(inputFile, textData, ' ' );

                        bonusEventList[bonusIndex] = textData;

                        ++bonusIndex;
                    }


           } 

            getline(inputFile,textData);

            knightAndEvent[index] = textData; 

           

            ++index;      
        }
        inputFile.close();
    }

    //convert from text string of integer to string type

    stringstream knightStatConvert(knightAndEvent[0]);

    int knightAttribute = 0, knightStat;

    while (knightStatConvert>>knightStat)
        knight[knightAttribute++] = knightStat;


    stringstream eventCodeConvert(knightAndEvent[1]);

    int eventCodeList = 0, eventCode;

    while (eventCodeConvert >> eventCode)
        eventList[eventCodeList++] = eventCode;
        

    // stringstream  bonusEventConverter(knightAndEvent[2]);

    // int bonusEventIndex = 0;
    // string bonusEvent;

    // while (bonusEventConverter >> bonusEvent)
    //     bonusEvent[bonusEventIndex++] = bonusEvent;


    for (int counter = 0; counter < 10; ++counter)
        cout << eventList[counter] << endl;




    //Knight stats input 
    HP = knight[0];
    level = knight[1];
    remedy = knight[2];
    maidenkiss  = knight[3];
    phoenixdown  = knight[4];
    rescue = knight[6];
}

void startQuest () {

     
    int quest = 0;

    int activeDeBuff = 0;

    int coolDown = 3;

    int temporaryHP = 0;

    int maxHP = HP;

    


      while (eventList[quest] != 0)
    {
        switch (eventList[quest])
        {
            case 0:
                //funtion
                break;

            case 1:
            case 2:
            case 3:
            case 4:
            case 5:

                //function for event 1-5

                break;
            case 6:

            break;

            case 7:

            break;    

        }    




        ++quest;
    }

    //Add event0;
    
}

void eventHandler0 () {
    //End of the journey
    rescue = 1;

    exit(0);
}

void eventHandler1to5 (int eventOrder, int eventCode ) {
    
    int b = eventOrder%10;

    int levelO = (eventOrder > 6?(b > 5?b : 5) : b);

    //knight wins

    ( ((level > levelO) && level < 10) ? ++level : level = level );

    if (level == levelO)
        level = level;


    //Re assisgn HP
    else if (level < levelO)
    {
        double baseDamage = 0;

        int damage = baseDamage*levelO*10;

         HP = HP - damage;

        //base damge chart

        switch (eventCode) {
            case 1: baseDamage = 1;
            break;

            case 2: baseDamage = 1.5;
            break;

            case 3: baseDamage = 4.5;
            break;

            case 4: baseDamage = 7.5;
            break;

            case 5: baseDamage = 9.5;
            break;
        }

         damage = baseDamage*levelO*10;

         HP = HP - damage;
    }


    if (HP <= 0 && phoenixdown == 0){
        rescue = -1;
    }

    if ( HP <= 0 && phoenixdown > 0)
    {
        HP = maxHP;
        phoenixdown -= 1;
    } 

    
}


void eventHandler6 (int eventOrder, int activeDeBuff,int  &cooldown, ) {

    int b = eventOrder%10;

    int levelO = (eventOrder > 6?(b > 5?b : 5) : b);

    int activeDebuff = 0;

    //knight wins

   if (level > levelO)
   {
        level += 2;

        if (level > 10)
            level = 10;
   }

    //knight draws
    else if (level == levelO)
        level = level;

    //knight loses
    else {

        int debuffTimeSet = eventOrder;

         activeDebuff = 1;

         hpDecreaseFor3Turns(activeDebuff, );
    }

}

void hpDecreaseFor3Turns( bool onOff, int &coolDown, int &initialHP){
    if ( onOff == 1)
        {
            HP = initialHP/5;

            if (initialHP < 5)
                HP = 1;

            if (remedy >= 1) 
                {
                    HP = initialHP;
                    --remedy;
                }
        }

    
    
        //multiply HP by 5 after 3 turns, if it's greater than maxHP, assign HP = maxHP
}


void hpRegeneratorAfter3Turns(  int timeWhenKnightGotTiny)
{
    if ()
}
