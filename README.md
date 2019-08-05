# DebouncedRotaryEncoder
A library for the Arduino & Teensy for using a rotary encoder as an input with embeeded debounce to avoid noise.

Based in the idea and work of David Johnson-Davies - www.technoblogy.com 

Complete description of his idea can be found in his web: http://www.technoblogy.com/show?1YHJ

I was searching a library for using a rotary encoder for my latest project and I found a lot of information on this topic but none of the existing libraries eliminate (without false negatives and positives) the effects of contact bounce. So I finally found that David Johnson-Davies idea that I turned into a library. I am using cheap and noisy, chinese mechanical encoders. With this lib, if I manually rotate them as quickly as I can, no steps are lost. The David Johnson-Davies approach ensure the consistency of the rotate direction checking if a clock transition is new (process it) or repeat (noise - ignore).

How to use:
1. Include the library (obviuosly!)
2. Setup an encoder: 
  DebouncedEncoder myEnc(pin1, pin2, max, min, cycle); 
  
  pin1 & pin2: encoder pins; 
  max: maximun value for the encoder count; 
  min: minimum value for the encoder count; 
  cycle: if TRUE, when the encoder reaches the max value the next value is the min. If FALSE, hold the max value. 
  
3. Get the encoder position
  myEnc.getPosition()
  It works better if attached to interrupt pin.
  
4. Optional: you can set the encoder value this way: 
  myEnc.setPosition(value)

To do:
Sure that this code can be optimized, but it works!
