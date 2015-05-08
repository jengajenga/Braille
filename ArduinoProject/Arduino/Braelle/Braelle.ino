/*   
          0   1
      -------------         <---- Example of what braille looks like.
      0|  1   0             <---- This is the letter A
       | ----------         
      1|  0   0
       | ----------
      2|  0   0
*/

// The PWM location values as defined by the grid above
#define G00 3    
#define G01 5   
#define G10 6    
#define G11 9    
#define G20 10  
#define G21 11  

// You can change this for the number of characters in the message
#define MSG_SIZE 1000

// The uppercase letters min and max 
#define A 65
#define Z 90

// The total number of PWM slots we have
#define MAXPWM 6

// A few definitions for on, off and second
#define OFF 0
#define ON 1
#define SEC 1000

// This is for analog write. Change this for the pulse amount
#define PULSE 80

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(G00, OUTPUT);  
  pinMode(G01, OUTPUT);
  pinMode(G10, OUTPUT);
  pinMode(G11, OUTPUT);
  pinMode(G20, OUTPUT);
  pinMode(G21, OUTPUT);
  Serial.begin(9600);
}

// Interpret the message recieved, boolean array representing braille alphabet
void sendPWM(bool PWMloc[]) {
  
  // Array that holds the values of all the PWM values
  int PWMs[MAXPWM] = {G00,G01,
                      G10,G11,
                      G20,G21};
  int i;
  for(i = 0; i < MAXPWM; i++) 
    if(PWMloc[i] == ON)             // If the index has a value of 1 then we match this to the grid that represents the motor
      analogWrite(PWMs[i], PULSE);  // Vibrate
    
  // The pause in between each letter
  delay(SEC);
  
  // Now turn all of the motors off
  for(i = 0; i < MAXPWM; i++) 
    if(PWMloc[i] == ON)             // If the motor is on we need to turn it off for the next letter
      analogWrite(PWMs[i], OFF);    // Turn the motor off
}

// Find out what character we have
void interpretChar(char c) {
  
  // If this isnt a letter in the alphabet a-z quit out
  if(!isalpha(c)) 
    return;
  
  // Essentially this converts an upper case character to a lower case
  if(c >= A && c <= Z) 
    c += 32;             // Increment by this much to reach lower case letters in ascii table
  
  bool PWMloc[MAXPWM];

  if(c == 'I') { // the i sound in "ship" pronounced: eəɪ

    PWMloc[0] = 0;      PWMloc[1] = 1;
    PWMloc[2] = 0;      PWMloc[3] = 0;
    PWMloc[4] = 1;      PWMloc[5] = 0;
  } 

 else if(c == 'i') { //the e sound in "sheep" pronounced eəɪii
    PWMloc[0] = 0;      PWMloc[1] = 1;
    PWMloc[2] = 1;      PWMloc[3] = 0;
    PWMloc[4] = 0;      PWMloc[5] = 0;
  }
  
 else if(c == 'i') { 
    PWMloc[0] = 0;      PWMloc[1] = 0;
    PWMloc[2] = 0;      PWMloc[3] = 0;
    PWMloc[4] = 0;      PWMloc[5] = 0;
  }
  
 else if(c == 'i') { 
    PWMloc[0] = 0;      PWMloc[1] = 0;
    PWMloc[2] = 0;      PWMloc[3] = 0;
    PWMloc[4] = 0;      PWMloc[5] = 0;
  }
    
 else if(c == 'i') { 
    PWMloc[0] = 0;      PWMloc[1] = 0;
    PWMloc[2] = 0;      PWMloc[3] = 0;
    PWMloc[4] = 0;      PWMloc[5] = 0;
  }
    
 else if(c == 'i') { 
    PWMloc[0] = 0;      PWMloc[1] = 0;
    PWMloc[2] = 0;      PWMloc[3] = 0;
    PWMloc[4] = 0;      PWMloc[5] = 0;
  }
    
 else if(c == 'i') { 
    PWMloc[0] = 0;      PWMloc[1] = 0;
    PWMloc[2] = 0;      PWMloc[3] = 0;
    PWMloc[4] = 0;      PWMloc[5] = 0;
  }
    
 else if(c == 'i') { 
    PWMloc[0] = 0;      PWMloc[1] = 0;
    PWMloc[2] = 0;      PWMloc[3] = 0;
    PWMloc[4] = 0;      PWMloc[5] = 0;
  }
    
 else if(c == 'i') { 
    PWMloc[0] = 0;      PWMloc[1] = 0;
    PWMloc[2] = 0;      PWMloc[3] = 0;
    PWMloc[4] = 0;      PWMloc[5] = 0;
  }
    
 else if(c == 'i') { 
    PWMloc[0] = 0;      PWMloc[1] = 0;
    PWMloc[2] = 0;      PWMloc[3] = 0;
    PWMloc[4] = 0;      PWMloc[5] = 0;
  }
    
 else if(c == 'i') { 
    PWMloc[0] = 0;      PWMloc[1] = 0;
    PWMloc[2] = 0;      PWMloc[3] = 0;
    PWMloc[4] = 0;      PWMloc[5] = 0;
  }
    
 else if(c == 'i') { 
    PWMloc[0] = 0;      PWMloc[1] = 0;
    PWMloc[2] = 0;      PWMloc[3] = 0;
    PWMloc[4] = 0;      PWMloc[5] = 0;
  }


  sendPWM(PWMloc);
}

// the loop routine runs over and over again forever:
void loop() {

  // As of right now this will only interpret characters. Any punctuation will be ignored
  // If you want to change how big the message is you need to change message size at the top
  char message[MSG_SIZE] = "";
  
  int length = Serial.available();
  Serial.readBytes(message, length);
  
  int i;
  for(i = 0; i < message[i] != NULL; i++) 
    interpretChar(message[i]);            // Reads one character at a time
    
}
