//this code is used to relay information between EMG sensors and a microcontroller (arduino)
//when the user places electrodes on the forearm, a flexing of the muscle will signal create a 
//signal that is then  
 
 //initial variables
//x is used as a counter
//M1dirpin is used to determine direction of motor
//Mlsteppin is used to determine speed (PWM)

int  x = 5;
int M1dirpin = 4;
int M1steppin = 5;

int led = 13;
void setup() {
  
  pinMode(M1dirpin,OUTPUT);
  pinMode(M1steppin,OUTPUT);
 
  // initialize serial communication at 9600 bits per second:
  pinMode(led, OUTPUT);
  Serial.begin(9600); }


// the loop routine runs over and over again forever:
void loop() {

  
 // read the input on analog pin 0, which in this case is the filtered and
rectified EMG data:
 int EMGValue = analogRead(A0);

 
// This loop says that when the threshold value read from the EMG is over 980 AND the counter (x is counter variable) is even
//the motor will spin clockwise
//in order to change the speed of the motor change the delayMicroseconds command
//in order to change the amount of rotation of the motor change the length of for loop (y range)
//in order to change the direction of the motor change the Mldirpin from low to high or vise versa
//motor is spun by PWM to pin M1steppin
//in order to ensure that motor does not receive command to go other direction too quickly change end delay
// total time of end delay and range of y should be 500

 if (EMGValue > 980 & (x%2)==0)
 {
  x=x+1;
  digitalWrite(M1dirpin,LOW); // clockwise spin
  
  for (int y = 0; y < 150; y++){
    
  digitalWrite(M1steppin,LOW);
  delayMicroseconds(300);
  digitalWrite(M1steppin,HIGH);
  delay(1);
  }
delay(400);

}

// This loop says that when the threshold value read from the EMG is over 980 AND the counter (x is counter variable) is odd
//the motor will spin counter-clockwise
//in order to change the speed of the motor change the delayMicroseconds command
//in order to change the amount of rotation of the motor change the length offor loop (y range)
//motor is spun by PWM to pin M1steppin
//in order to ensure that motor does not receive command to go other direction too quickly change end delay
// total time of end delay and range of y should be 500

  else if (EMGValue > 980 & (x%2)!=0)
  {
  x=x+1;
  digitalWrite(M1dirpin,HIGH); // clockwise spin
  
   for (int a = 0; a < 150; a++){
  digitalWrite(M1steppin,LOW);
  delayMicroseconds(300);
  digitalWrite(M1steppin,HIGH);
  delay(1);
  }
  delay(400);
  }
  
 // This loop says that when the threshold value read from the EMG is not
over 980 the motor will not spin at all
  else {
 digitalWrite(M1steppin,LOW);
}



 // print out the value you read from analog A0 (EMG value)
Serial.println(EMGValue);
 delay(1);    // delay in between reads for stability
}
