# Make TO Xbee S2C communicate

using XCTU, set 1 xbee as a coordinator and 1 as a Router. 
- Set API Mode on Both. 

On the router, set
- one pin to ADC reading. 
- the time between read (each time the S2C sends a API)

Plug the Coordinator on the Arduino. 
Plug the route to whatever you want (i use small board with xbee adapter from Sparkfun)
https://www.sparkfun.com/products/11697
you can also use breakout board and solder pins on it to plus this on a breadboard. (remember to read the minimum requirement of the Xbee S2C in the XBee documentation )


Upload the sketch to the Arduino
Mine is a DFRobot Leonardo with Xbee socket . Xbee is on Serial1 

