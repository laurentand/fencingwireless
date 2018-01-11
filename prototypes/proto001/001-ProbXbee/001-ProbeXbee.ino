// XBee-Arduino library - Version: Latest 
#include <Printers.h>

/*
1 Xbee is regularly sending IO samples throug API message. 
This code loops to check for available message and log them to Serial. 

Note: On DFRobot Leonardo with Xbee, https://www.dfrobot.com/wiki/index.php/DFRobot_Leonardo_with_Xbee_R3(SKU:DFR0221)
we must use Serial1 to talk to the S2C

1st attempt withtout Xbee library (despite include) 

*/
int val;
unsigned long lasttime;
unsigned long now;

void setup() {
  Serial1.begin(9600);  // Xbee socket
  Serial.begin(9600); // Arduino 
  lasttime = millis();
    
}

void loop() {
  // 
  if (Serial1.available()>=21)
  {
    val =Serial1.read();
    if (val== 0x7E)
    {
      now = millis();
      Serial.print("Time : ");
      Serial.println((now-lasttime)/1000.0);
      lasttime = now;
    Serial.println();
    Serial.print("Message : ");
    
    Serial.print(val,HEX);
    Serial.print(" ");
    while(Serial1.available()>0)
    {
      val = Serial1.read();
      //Serial.print(val, HEX);
     //  PrintHex8(&val,1);
     MyPrintHex8(val);
      Serial.print(" ");
    }
    Serial.println();
    }
  }
  else
   {
   Serial.write(".");
   }
  delay(1000);
  
    
}


// Fancy formatting to quickly copy / paste the log into XCTU Frame decoder tool 
// Serial.print(x,HEX) don't put leading zeros and copy/paste is not correctly decoded by XCTU.

void MyPrintHex8(uint8_t value)
{

  
  byte lsb = value & 0x0F;
  byte msb = (value & 0xF0) >> 4;
  
  Serial.print(msb,HEX);
  Serial.print(lsb,HEX);
  
}

