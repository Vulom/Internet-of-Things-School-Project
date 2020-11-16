#include <SPI.h>                          
#include <MFRC522.h>                     


int RST_PIN = 9;                          
int SS_PIN = 10;                          
byte kart1[4] = {214, 100, 117, 213};
byte kart2[4] = {85, 38, 214, 59};
byte kart3[4] = {45, 207, 122, 176};
int k1 = 0;
int k2 = 0;
int k3 = 0;
int counter = 0;
MFRC522 rfid(SS_PIN, RST_PIN);            


void setup() { 
  Serial.println(k1);
  Serial.println(k2);
  Serial.println(k3);
  
  Serial.begin(9600);                     
  SPI.begin();                            
  rfid.PCD_Init();                        
}
 
void loop() {

  if ( ! rfid.PICC_IsNewCardPresent())    
    return;

  if ( ! rfid.PICC_ReadCardSerial())      
    return;

  if (rfid.uid.uidByte[0] == kart1[0] &&     
    rfid.uid.uidByte[1] == kart1[1] && 
    rfid.uid.uidByte[2] == kart1[2] && 
    rfid.uid.uidByte[3] == kart1[3] ) 
    {
      if (k1==1) 
      {
        k1--;
       Serial.println ("Kart 1 çıkış yaptı");
       counter--;
       delay(3000);
      } 
      else if (k1==0) {
        k1++;
        Serial.println ("Kart 1 giriş yaptı");
        counter++;
        delay(3000);
      }
    
    }
    if (rfid.uid.uidByte[0] == kart2[0] &&     
    rfid.uid.uidByte[1] == kart2[1] && 
    rfid.uid.uidByte[2] == kart2[2] && 
    rfid.uid.uidByte[3] == kart2[3] ) 
    {
      if (k2==1) 
      {
       k2--;
       Serial.println ("Kart 2 çıkış yaptı");
       counter--;
       delay(3000);
      } 
      else if(k2==0) {
        k2++;
        Serial.println ("Kart 2 giriş yaptı");
        counter++;
        delay(3000);
      }
    }
  if (rfid.uid.uidByte[0] == kart3[0] &&     
    rfid.uid.uidByte[1] == kart3[1] && 
    rfid.uid.uidByte[2] == kart3[2] && 
    rfid.uid.uidByte[3] == kart3[3] )
    {
      if (k3==1) 
      {
        k3--;
       Serial.println ("Kart 3 çıkış yaptı");
       counter--;
       delay(3000);
      } 
      else if(k3==0) {
        k3++;
        Serial.println ("Kart 3 giriş yaptı");
        counter++;
        delay(3000);
    }
   }
if (counter == 3) {
 pinMode(2, OUTPUT); 
 pinMode(4, OUTPUT); 
 pinMode(3, OUTPUT);
} 
else {
 pinMode(2, INPUT); 
 pinMode(4, INPUT); 
 pinMode(3, INPUT);
}
Serial.print ("Kişi sayısı: ");
Serial.println (counter);
delay(1000);

}
