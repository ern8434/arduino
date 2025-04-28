
// Arduino IDE library: IRremote by Armin Joachimsmeyer  
// Version: 4.4.1
// örnek kaynak: https://github.com/Arduino-IRremote/Arduino-IRremote/blob/master/examples/SimpleReceiver/SimpleReceiver.ino

#include <IRremote.hpp> // include the library

#define IR_RECEIVE_PIN      11

// kumanda tanımları (LG tv kumandası)
#define buton_yukari 64
#define buton_asagi  65
#define buton_sol  7
#define buton_sag  6
#define buton_ok  68

void setup() {
  Serial.begin(9600);// IR kodlarını almak için
  
  // Just to know which program is running on my Arduino
  Serial.println(F("START " __FILE__ " from " __DATE__ "\r\nUsing library version " VERSION_IRREMOTE));

  // Start the receiver and if not 3. parameter specified, take LED_BUILTIN pin from the internal boards definition as default feedback LED
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);

  Serial.print(F("Ready to receive IR signals of protocols: "));
  printActiveIRProtocols(&Serial);
  Serial.println( IR_RECEIVE_PIN );
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  //pinMode(ENA, OUTPUT);
  //pinMode(ENB, OUTPUT);
}
 
void loop() {
  analogWrite(ENA, EN);
  analogWrite(ENB, EN);
  
  /*
   * Check if received data is available and if yes, try to decode it.
   * Decoded result is in the IrReceiver.decodedIRData structure.
   *
   * E.g. command is in IrReceiver.decodedIRData.command
   * address is in command is in IrReceiver.decodedIRData.address
   * and up to 32 bit raw data in IrReceiver.decodedIRData.decodedRawData
   */
  if (IrReceiver.decode()) {
      /*
       * Print a summary of received data
       */
      if (IrReceiver.decodedIRData.protocol == UNKNOWN) {
          Serial.println(F("Received noise or an unknown (or not yet enabled) protocol"));
          // We have an unknown protocol here, print extended info
          IrReceiver.printIRResultRawFormatted(&Serial, true);

          IrReceiver.resume(); // Do it here, to preserve raw data for printing with printIRResultRawFormatted()
      } else {
          IrReceiver.resume(); // Early enable receiving of the next IR frame

          IrReceiver.printIRResultShort(&Serial);
          IrReceiver.printIRSendUsage(&Serial);
      }
      Serial.println();

      /*
       * Finally, check the received data and perform actions according to the received command
       */
      if (IrReceiver.decodedIRData.flags & IRDATA_FLAGS_IS_REPEAT) {
          Serial.println(F("Repeat received. Here you can repeat the same action as before."));
      } else {
          switch(IrReceiver.decodedIRData.command){
            case buton_yukari:
              Serial.println("YUKARI");
              yon_ileri();
            break;
            case buton_asagi:
              Serial.println("ASAGI");
              yon_geri();
            break;
            case buton_sol:
              Serial.println("SOL");
            break;
            case buton_sag:
              Serial.println("SAG");
            break;
            default:
              Serial.println(IrReceiver.decodedIRData.command);  
          }
          
      }
  }
  
}