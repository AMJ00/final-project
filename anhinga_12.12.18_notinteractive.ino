#include <Servo.h>

Servo servo1;  // create servo object to control a servo
Servo servo2;  // create servo object to control a servo
Servo servo3;  // create servo object to control a servo

//int sharp1 = A0; //analog pin 0
//int sharp2 = A1; //analog pin 1
//int sharp3 = A2; //analog pin 2
//int sharp4 = A3; //analog pin 3

void setup(){
  
Serial.begin(9600);

servo1.attach(9);  // attaches servo1 on pin 9 to the servo object
servo2.attach(10);  // attaches servo2 on pin 10 to the servo object

}

void loop(){

// the code below generates random numbers and saves them as values that 
// will be used below to drive the servo motors.  it also prints them 
// to the serial monitor in four columns, for troubleshooting purposes.
// The ultimate intention of the project is for these different values to be
// readings from four different sharp proximity sensors, but generating the 
// random numbers at least serves to demonstrate that these values effectively 
// control the motion of head and wings.  

int zone1 = random(1, 600);
Serial.print(zone1);
Serial.print("     ");
int zone2 = random(1, 600);
Serial.print(zone2);
Serial.print("     ");
int zone3 = random(1, 600);
Serial.print(zone3); 
Serial.print("     ");
int zone4 = random(1, 600);
Serial.println(zone4);
 
//  code below makes head turn towards the quadrant being read by the sensor that produces the 
//  highest value, or, in other words, makes the head turn towards a proximate object.
//  i think i migt need additional code that ignores values when they drop below a certain range,
//  and also ignores very small differences in value.  not sure about this second part - maybe it's
//  funny if the bird jerks its head back and forth, not sure where to turn, if it's getting near-equal
//  input from two sensors?

if (zone1 > zone2 && zone1 > zone3 && zone1 > zone4){ 
  servo1.write(0);        //set servo1 position to zone1;
}
else if (zone2 > zone1 && zone2 > zone3 && zone2 > zone4){ 
  servo1.write(60);        //set servo1 position to zone2;
}
else if (zone3 > zone1 && zone3 > zone2 && zone3 > zone4){ 
  servo1.write(120);        //set servo1 position to zone3;
}
else if (zone4 > zone1 && zone4 > zone3 && zone4 > zone2){ 
  servo1.write(180);        //set servo1 position to zone4;
}

// code below makes wings flap faster when object is more proximate.  might need to break this
// up into small steps, and intersperse with repeated blocks of the head-turn code, so that the head
// continues to respond even as wings are moving.

if (zone1 > 400 || zone2 > 400 || zone3 > 400 || zone4 > 400){ 
  servo2.write(180);        
  delay(10);
  servo2.write(0); 
  delay(50);
}
else if (zone1 > 200 || zone2 > 200 || zone3 > 200 || zone4 > 200){ 
  servo2.write(180);        
  delay(10);
  servo2.write(0); 
  delay(100);
}
else { 
  servo2.write(0);        //fixed position for servo2, holding wings still, if no signal from sensors
}
  

delay(1000);                         // slow down to read printout, for troubleshooting purposes

}
