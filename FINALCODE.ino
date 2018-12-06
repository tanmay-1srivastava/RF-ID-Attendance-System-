
int count =0;
// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
#include <Wire.h>
#include <SPI.h>
#include <MFRC522.h>
#include "RTClib.h"
#include<LiquidCrystal.h>
RTC_DS1307 rtc;
LiquidCrystal lcd(7,6,5,4,3,2);
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
int serInLen = 25;
char serInString[25];
int pId =0;
int result;

void setup () {
pinMode(A0,OUTPUT);
pinMode(A1,OUTPUT);
pinMode(A2,OUTPUT);

  while (!Serial); // for Leonardo/Micro/Zero
lcd.begin(16,2);
  Serial.begin(9600);
      SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
    
                        
  

  }

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
     rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
     rtc.adjust(DateTime(2017, 4, 30, 2, 55 ,0 ));
  }
  
}

void loop () {
    DateTime now = rtc.now();
    
    Serial.print(now.day(), DEC);
    lcd.print(now.day(), DEC);
    Serial.print('/');
    lcd.print('/');
    Serial.print(now.month(), DEC);
    lcd.print(now.month(), DEC);
    Serial.print('/');
    lcd.print('/');
    Serial.print(now.year(), DEC);
    lcd.print(now.year(), DEC);
    Serial.print(" (");
    lcd.setCursor(8,0);
    lcd.print("");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(") ");
    lcd.print(" ");
    lcd.setCursor(0,1);
    Serial.print(now.hour(), DEC);
    lcd.print(now.hour(), DEC);
    Serial.print(':');
    lcd.print(':');
    Serial.print(now.minute(), DEC);
    lcd.print(now.minute(), DEC);
    Serial.print(':');
    lcd.print(':');
    Serial.print(now.second(), DEC);
    lcd.print(now.second(), DEC);
    Serial.println();
    
    
   
       
    Serial.println();
    
   
    delay(1000);
    lcd.clear();

 if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    
  lcd.clear();
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  
  Serial.print("UID tag :");
 
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     lcd.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
      lcd.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  
 
  content.toUpperCase();
  
 
  if (content.substring(1) == "72 8C 2A D5") //change here the UID of the card/cards that you want to give access
  {digitalWrite(A0,HIGH);
 delay(750);
 digitalWrite(A0,LOW);

    
    Serial.println("S1 PRESENT");
    lcd.setCursor(0,1);
lcd.print("VIKAS PRESENT");

char buffer[5];

char nam[]="VIKAS";
char st[]="P";
char id[]="01";
   Serial.print("#S|LOGTEST|[");//roll1 is 01 for student 1 with uid 72 8c 2a d5

Serial.print(id);
     Serial.print("               ");
     Serial.print(nam);
       Serial.print("                        ");

   Serial.print(st);

   Serial.println("]#");

Serial.println();
    delay(1500);
  }
 else if (content.substring(1) == "6B 91 F1 66") //change here the UID of the card/cards that you want to give access
  {digitalWrite(A0,HIGH);
delay(750);
 digitalWrite(A0,LOW);

    
    Serial.println("S1 PRESENT");
    lcd.setCursor(0,1);
lcd.print("VINAYAK PRESENT");

char buffer[5];

char nam[]="VINAYAK";
char st[]="P";
char id[]="02";
   Serial.print("#S|LOGTEST|[");//roll1 is 01 for student 1 with uid 72 8c 2a d5

Serial.print(id);
     Serial.print("               ");
     Serial.print(nam);
       Serial.print("                      ");
 
   Serial.print(st);



   Serial.println("]#");

Serial.println();
    delay(1500);
  }

 else if (content.substring(1) == "76 25 24 07") //change here the UID of the card/cards that you want to give access
  {digitalWrite(A0,HIGH);
  delay(750);
 digitalWrite(A0,LOW);

    
    Serial.println("S1 PRESENT");
    lcd.setCursor(0,1);
lcd.print("SUMIT PRESENT");

char buffer[5];

char nam[]="SUMIT";
char st[]="P";
char id[]="03";
   Serial.print("#S|LOGTEST|[");//roll1 is 01 for student 1 with uid 72 8c 2a d5

Serial.print(id);
     Serial.print("               ");
     Serial.print(nam);
       Serial.print("                        ");
   
   Serial.print(st);

   Serial.println("]#");

Serial.println();
    delay(1500);
  }



 
 else if(content.substring(1) == "8B 2B 08 99" )   {

digitalWrite(A0,HIGH);
delay(750);
 digitalWrite(A0,LOW);
char nam[]="DEEPAK";
char st[]="P";
char id[]="04";
char buffer[5];
    Serial.println("S2 PRESENT");
       lcd.setCursor(0,1);
    lcd.print("DEEPAK PRESENT");
     Serial.print("#S|LOGTEST|[");


  Serial.print(id);
     Serial.print("               ");
     Serial.print(nam);
       Serial.print("                       ");

   Serial.print(st);

   Serial.println("]#");

    delay(1500);
    
 }  


}





