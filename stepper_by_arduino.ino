/*
* Steppercontroller program for running a stepperdriver that only needs two lines
  * A pulse line and a direction line. For example like the 'easydriver' stepper motor controllers
   
 */

 //the number of steppermotors connected to arduino
 #define nrOfSteppers 2
 //the pins of the steppers that control the direction
 const int stepperDirectionPin[nrOfSteppers] = {8,4};/* use these for direction attach them to CCW/CW*/
 //the pins of the steppers that control the pulse
 const int stepperPulsePin[nrOfSteppers] = {10,2};/*use these for pulse attach them to CLK*/

 void setup() {                 

   //set the output pins right and set them LOW
   for(int s=0; s<nrOfSteppers; s++){
     pinMode(stepperDirectionPin[s], OUTPUT);   
     digitalWrite(stepperDirectionPin[s], LOW);
     pinMode(stepperPulsePin[s], OUTPUT);
     digitalWrite(stepperPulsePin[s], LOW);
   }  

 Serial.begin(9600);   
 }

 void loop(){
    
 // just moving 2 stepper motors back and forth
   //stepper(number of the motor to control, amount of steps, the direction(0 or 1));
   stepper(0,3200,1);
   stepper(0,3200,1);
 stepper(0,3200,0);

 stepper(1,3200,1);
 stepper(1,1600,1);
 stepper(1,1600,0);
Serial.println("---");

 }

 void stepper(int motor, int steps, boolean stepDirection){
   //first check the direction, if it's not the current direction change it.
     int currentDirection = digitalRead(stepperDirectionPin[motor]);
     if(stepDirection != currentDirection){
      digitalWrite(stepperDirectionPin[motor], stepDirection);  
      //this delay makes the motor stop for a while when changing direction.
       delay(100);
     }
   //a for loop to create the pulse
   for(int s=0; s<steps; s++){
     //the LOW, then HIGH creates the pulse the driver is waiting for, no delay needed.
     digitalWrite(stepperPulsePin[motor],LOW);   
     digitalWrite(stepperPulsePin[motor], HIGH);
     //this delay creates the pulse, the lower the number the faster the pulse.
     //play around with it to get your desired speed
     delayMicroseconds(500);
   }
 }



