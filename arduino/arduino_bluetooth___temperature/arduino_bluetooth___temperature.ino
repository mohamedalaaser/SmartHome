#include "DHT.h"
DHT dht;

char junk;
String inputString="";
char inChar;


void setup()                    // run once, when the sketch starts
{
 Serial.begin(9600);            // set the baud rate to 9600, same should be of your Serial Monitor

 pinMode(9, OUTPUT);
 pinMode(8, OUTPUT);
 pinMode(10, OUTPUT);
 
 pinMode(3, INPUT);
 
  dht.setup(2);   /* set pin for data communication */
}

void loop()
{

if(digitalRead(3)==LOW){
  
if(Serial.available()){
  while(Serial.available())
    {
       inChar = (char)Serial.read(); //read the input
      inputString += inChar;        //make a string of the characters coming on serial
    }
    
    Serial.println(inputString);
    while (Serial.available() > 0)  
    { junk = Serial.read() ; }      // clear the serial buffer
    
    if(inputString.charAt(0) == '1'){         //in case of '1' turn the LED on
      digitalWrite(9, HIGH);  
    }else if(inputString.charAt(0) == '0'){   //incase of '0' turn the LED off
      digitalWrite(9, LOW);
    }
    else if(inputString =="2"){ // turn buzzer on
      digitalWrite(8,LOW);
    }
    else if(inputString == "3"){  //turn buzzer off
      digitalWrite(8,HIGH);
    }
     else if(inputString.charAt(0) =='4'){ // open door
      digitalWrite(10,HIGH);
    }
    else if(inputString.charAt(0) == '5'){  //close door
      digitalWrite(10,LOW);
    }
    inputString = "";
  }

}
else{
  
  delay(dht.getMinimumSamplingPeriod());  /* Delay of amount equal to sampling period */  
  float humidity = dht.getHumidity();     /* Get humidity value */
  float temperature = dht.getTemperature(); /* Get temperature value */

  Serial.print(dht.getStatusString());      /* Print status of communication */
  Serial.print("\t\t");
  Serial.println(temperature, 1);

  if(temperature>23.5){
     digitalWrite(8,LOW);
  }
  else{
     digitalWrite(8,HIGH);
  }


}
}
