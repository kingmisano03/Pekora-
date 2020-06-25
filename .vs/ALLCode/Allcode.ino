const int waterSens = A0;                                   //ตัวรับนํ้าคือA0
const int speaker = 8;                                     //ตัวพูดคือ 8
int SensorValue;                                          
#include <IRremote.h>
int RECV_PIN = 11;                                        //รีโมตเซ็ตไว้11
const int relay1 = 6;                                    // มอเตอร์A1 ซ้าย
const int relay2 = 7;                                   // มอเตอร์A1  ขวา
const int relay3 = 9;                                  // มอเตอร์A2   ซ้าย
const int relay4 = 10;                                // มอเตอร์A2    ขวา
#define code1  1286666973                            // หน้า
#define code2  1286666974                           // ซ้าย
#define code3  1286666975                          // ขวา  
#define code4  1236334117                         // หลัง  
IRrecv irrecv(RECV_PIN);
decode_results results;
void setup()
{
  pinMode(speaker, OUTPUT);                                //ตัวออกเสียง
  pinMode(waterSens, INPUT);                              //ตัวรับนํ้า
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();                                     // Start the receiver
  
}
void loop() {
    int sensorValue = analogRead(waterSens);              //read the water sensor value
    
    if(sensorValue <= 50)
    {
        Serial.println("waterINcome  1");
    }
    if (sensorValue >= 50) 
    {
        tone(speaker, 800, 800);
        delay(200);
        tone(speaker, 600, 800);
        delay(200);
    } 
    if (irrecv.decode(&results)) {        //เดินหน้า
     if (results.value == code1) {        
       digitalWrite(relay1, HIGH);
       digitalWrite(relay2, LOW);
       digitalWrite(relay3, LOW);
       digitalWrite(relay4, HIGH);
    }
     if (results.value == code2) {       //ซ้าย
       digitalWrite(relay1, LOW);
       digitalWrite(relay2, LOW);
       digitalWrite(relay3, HIGH);
       digitalWrite(relay4, HIGH);
    }
     if (results.value == code3) {       //ขวา
       digitalWrite(relay1, HIGH);
       digitalWrite(relay2, HIGH);
       digitalWrite(relay3, LOW);
       digitalWrite(relay4, LOW);
    }
     if (results.value == code4) {      //ถอยหลัง
       digitalWrite(relay1, HIGH);
       digitalWrite(relay2, LOW);
       digitalWrite(relay3, HIGH);
       digitalWrite(relay4, LOW);
    }
    irrecv.resume(); // Receive the next value
  }
}