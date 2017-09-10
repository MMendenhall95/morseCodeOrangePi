
#include <iostream>
#include <string>
#include <cstdlib>
#include <wiringPi.h>
using namespace std;
void morse(char **argv, int argc);

int main(int argc, char **argv)
{

    morse(argv, argc);
    return 0;
}

void morse(char **argv, int argc){
int numtmp;
wiringPiSetup ();
pinMode(0, OUTPUT);

string temp;
string morsecode[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
for (unsigned int i = 1; i < argc ; i++)
{
    temp = argv[i];
    for(unsigned int j = 0; j <= temp.size() - 1; j++){
        numtmp = int(toupper(temp[j])) - 65;

    for(int k = 0; k <= morsecode[numtmp].size() -1; k++){
        if(morsecode[numtmp][k] == '.'){
          cout << ".";     //put the beep code here
           digitalWrite (0, HIGH); delay(75);
	   digitalWrite (0, LOW); delay(75); 
        }else{
           cout << "-";      //put the boop code here (2x longer than beep)
            digitalWrite (0, HIGH); delay (150);
	    digitalWrite (0, LOW); delay(150);
	}
    }
	delay(150);
       // cout << endl;
        //cout << morsecode[]
    }
}

}
