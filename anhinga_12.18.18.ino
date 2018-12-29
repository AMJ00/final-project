Order# 113-4182311-8400238


//  see:  https://www.arduino.cc/en/Tutorial/Smoothing
//  see also:  https://www.arduino.cc/reference/en/language/variables/data-types/array/


#include <Servo.h>

Servo servo1;  // create servo object to control a servo
Servo servo2;  // create servo object to control a servo


int sharp1 = A1; //analog pin 1
int sharp2 = A2; //analog pin 2
int sharp3 = A3; //analog pin 3
int sharp4 = A4; //analog pin 4


const int numReadings = 8;   // store eight sensor readings in array


int zone1[numReadings];         // the readings from proximity sensor 1
int zone2[numReadings];         // the readings from proximity sensor 2
int zone3[numReadings];         // the readings from proximity sensor 3
int zone4[numReadings];         // the readings from proximity sensor 4


int zone1total = 0;             // the running total for zone 1
int zone2total = 0;             // the running total for zone 2
int zone3total = 0;             // the running total for zone 3
int zone4total = 0;             // the running total for zone 4


int readIndex = 0;              // the index of the current reading
int average = 0;                // the average


void setup() {

// initialize serial communication with computer
  
  Serial.begin(9600);  

//  attach servos to pins 9 & 10

servo1.attach(9);  // attaches servo1 on pin 9 to the servo object
servo2.attach(10);  // attaches servo2 on pin 10 to the servo object


// I copied the following code from the smoothing code example, but I don't understand why 
// it is included in the setup section rather than the loop section.  
// the comment included in the example code says, "initialize all the readings to 0"

  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    zone1[thisReading] = 0;
    zone2[thisReading] = 0;
    zone3[thisReading] = 0;
    zone4[thisReading] = 0;
  }
}


void loop() {

//  get an average of numReadings readings from proximity sensor 1
  
  zone1total = total - zone1[readIndex];      // subtract the last reading
  zone1[readIndex] = analogRead(sharp1);      // read from the zone1 sensor
  total = total + zone1[readIndex];           // add the zone1 reading to the total
  readIndex = readIndex + 1;                  // advance to the next position in the array

  if (readIndex >= numReadings) {             // if we're at the end of the array...
    readIndex = 0;                            // ...wrap around to the beginning
  }

  zone1average = zone1total / numReadings;    // calculate the average:
  Serial.println(zone1average);               // send it to the computer as ASCII digits
  delay(1);                                   // delay in between reads for stability
}

//  get an average of numReadings readings from proximity sensor 2
  
  zone2total = total - zone2[readIndex];      // subtract the last reading
  zone2[readIndex] = analogRead(sharp2);      // read from the zone2 sensor
  total = total + zone2[readIndex];           // add the zone2 reading to the total
  readIndex = readIndex + 1;                  // advance to the next position in the array

  if (readIndex >= numReadings) {             // if we're at the end of the array...
    readIndex = 0;                            // ...wrap around to the beginning
  }

  zone2average = zone2total / numReadings;    // calculate the average:
  Serial.println(zone2average);               // send it to the computer as ASCII digits
  delay(1);                                   // delay in between reads for stability
}

//  get an average of numReadings readings from proximity sensor 3
  
  zone3total = total - zone3[readIndex];      // subtract the last reading
  zone3[readIndex] = analogRead(sharp3);      // read from the zone3 sensor
  total = total + zone3[readIndex];           // add the zone3 reading to the total
  readIndex = readIndex + 1;                  // advance to the next position in the array

  if (readIndex >= numReadings) {             // if we're at the end of the array...
    readIndex = 0;                            // ...wrap around to the beginning
  }

  zone3average = zone3total / numReadings;    // calculate the average:
  Serial.println(zone3average);               // send it to the computer as ASCII digits
  delay(1);                                   // delay in between reads for stability
}

//  get an average of numReadings readings from proximity sensor 4
  
  zone4total = total - zone4[readIndex];      // subtract the last reading
  zone4[readIndex] = analogRead(sharp4);      // read from the zone4 sensor
  total = total + zone4[readIndex];           // add the zone4 reading to the total
  readIndex = readIndex + 1;                  // advance to the next position in the array

  if (readIndex >= numReadings) {             // if we're at the end of the array...
    readIndex = 0;                            // ...wrap around to the beginning
  }

  zone4average = zone4total / numReadings;    // calculate the average:
  Serial.println(zone4average);               // send it to the computer as ASCII digits
  delay(1);                                   // delay in between reads for stability
}


//  regarding the serial print for the above code, is there a way to get the four values to print in 
//  four neat columns?  If I declare zoneNaverage as a certain type of variable, 
//  will it print with a certain number of characters?


//  code below makes head turn towards the quadrant being read by the sensor that produces the 
//  highest value, or, in other words, makes the head turn towards a proximate object.
//  i think i miggt need additional code that ignores values when they drop below a certain range,
//  and also ignores very small differences in value.  not sure about this second part - maybe it's
//  funny if the bird jerks its head back and forth, not sure where to turn, if it's getting near-equal
//  input from two sensors?


if (zone1average > zone2average && zone1average > zone3average && zone1average > zone4average){ 
  servo1.write(10);        //set servo1 position to zone1 quadrant
}
else if (zone2average > zone1average && zone2average > zone3average && zone2average > zone4average){ 
  servo1.write(70_;        //set servo1 position to zone2 quadrant
}
else if (zone3average > zone1average && zone3average > zone2average && zone3average > zone4average){ 
  servo1.write(110);        //set servo1 position to zone3 quadrant
}
else if (zone4average > zone1average && zone4average > zone3average && zone4average > zone2average){ 
  servo1.write(170);        //set servo1 position to zone4 quadrant
}

// code below makes wings flap faster when object is more proximate.  might need to break this
// up into small steps, and intersperse with repeated blocks of the head-turn code, so that the head
// continues to respond even as wings are moving.

// 12.17.18 - this code below is all wrong still, please ignore!  still need to modify using for loop to smooth out motion.

if (zone1average > 400 || zone2average > 400 || zone3average > 400 || zone4average > 400){ 
  servo2.write;        
  delay(200)
  servo2.write; 
  delay(200)
  servo2.write; 
  delay(200)
  servo2.write; 
  delay(200)
}
else if (zone1average > 200 || zone2average > 200 || zone3average > 200 || zone4average > 200){ 
  servo2.write;        
  delay(500)
  servo2.write; 
  delay(500)
  servo2.write; 
  delay(500)
  servo2.write; 
  delay(500)
}
else { 
  servo2.write;        //fixed position for servo2, holding wings still, if no signal from sensors

  
}
