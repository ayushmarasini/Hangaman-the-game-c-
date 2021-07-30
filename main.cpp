//total tries = 5

#include <iostream>
#include <string.h>
#include <cstring>
#include <charconv>
using namespace std;

class display{
public:
        int tries,i;
        bool front;
    string hangMan;
    void allign(string h){
        hangMan=h;
            front=true;
            for (i=hangMan.size();i<32;i++){
                if (front==true ){
                    hangMan=" "+ hangMan;
                }
                else{
                    hangMan=hangMan+" ";
                }
                front=!front;
                
            }
            cout<<hangMan.c_str()<<endl;
        }
    
        
        void displayHangman(int a){
            tries=a;
                if (tries>=0){
                    allign("|");
                }
           
                if (tries>=1){
                    allign("|");
                    }
            if (tries>=2){
                allign("O");
                               }
            if (tries>=3){
                allign("/ | /");
            }
            if (tries>=4){
                allign("|");
            }
            if (tries>=5){
                allign("/ | /");
            }
        }
};// displayHangMan class



class wordGuess:public display{
public:
    int t=0;
    string question;
    char guessWord[50];// 50 word is the limit
    char answer[50];
    bool endGame=false;
    int j=0;
    int i=0;
    int k=0;
    bool rightGuess=false;

    void displayLetters(char in){
   
        cout<<"avilable letters are"<<endl;
          for (int i=97;i <= 107;i++){// ASCII code from a to k
            if (char(in)!=i){
               cout<<char(i)<<"  ";
            }
        }
        cout<<endl;
        for (int i=108;i <= 118;i++){// ASCII code from l to v
            if (char(in)!=i){
               cout<<char(i)<<"  ";
            }
        }
        cout<<endl;
        for (int i=119;i <= 122;i++){// ASCII code from w to z
            if (char(in)!=i){
               cout<<char(i)<<"  ";
            }
        }
        cout<<endl;
    }

    void getWord()
    {
        cout<<"enter a word to player 2"<<endl;
        cin>>question;
    }
    void getBlank()
    {
        for (int i=0;i<question.size();i++)
        {
        cout<<"_ ";
        }
    }
    void game()
    {
        while (endGame==false){
               for (j=0;j<question.size();j++){
                   displayHangman(t);
                   cout<<"enter a letter"<<endl;
                    displayLetters(guessWord[j]);
                    cin>>guessWord[j];
                for(i=0;i<question.size();i++){

                        if (guessWord[j]==question.at(i)){
                            cout<<"correct geuss"<<endl;
                            answer[j]=guessWord[j];
                            rightGuess=true;
                            
                    }
                }
                   if (rightGuess==false){
                       t=t+1;
                   }
                   
                   rightGuess=false;
                   if (t>=5){
                       j=question.size();
                       i=question.size();
                       endGame=true;
                   }
                }
            for(int i=0;i<question.size();i++){
                if (answer[i]==question.at(i)){
                    k+=1;
                    
                }
            }
            if (k==question.size()){
                cout<<"you won ";
                endGame=true;
            }
            else{
                cout<<"you loose";
            }
           
        }
    }
};



int main(){
    wordGuess g;
    g.getWord();
    g.getBlank();
    g.game();
    


}



