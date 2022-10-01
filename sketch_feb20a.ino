#include<string.h>
#pragma GCC diagnostic ignored "-Wwrite-strings"
#include<SoftwareSerial.h>
SoftwareSerial mySerial(2,3);
void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);
  delay(100);
  pinMode(7,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(4,OUTPUT);
  mySerial.print("AT+CMGF=1\r");
  delay(1000);
  mySerial.print("AT+CNMI=2,2,0,0,0\r");
  delay(1000);
  Serial.println("DEL ALL");
  delay(1000);
}

void loop() {
  int i=0;
  char ch;
  char data[200]={};
  while(mySerial.available()<=0);
  while(mySerial.available()>0)
  {
    ch=mySerial.read();
    Serial.print(ch);
    if(ch=="#")
    break;
    data[i]=ch;
    i++;
    delay(50);
  }
  Serial.println("");
  delay(1000);
//1
  if(strstr(data,"light1on"))
  {
    Serial.println("Light1 ON");
    digitalWrite(7,HIGH);
  }
  if(strstr(data,"light1off"))
  {
    Serial.println("Light1 OFF");
    digitalWrite(7,LOW);
  }
  //2
  if(strstr(data,"light2on"))
  {
    Serial.println("Light2 ON");
    digitalWrite(9,HIGH);
  }
  if(strstr(data,"light2off"))
  {
    Serial.println("Light2 OFF");
    digitalWrite(9,LOW);
  }
  //3
  if(strstr(data,"light3on"))
  {
    Serial.println("Light3 ON");
    digitalWrite(10,HIGH);
  }
  if(strstr(data,"light3off"))
  {
    Serial.println("Light3 OFF");
    digitalWrite(10,LOW);
  }
  //4
  if(strstr(data,"fanon"))
  {
    Serial.println("fan ON");
    digitalWrite(4,HIGH);
  }
  if(strstr(data,"fanoff"))
  {
    Serial.println("fan OFF");
    digitalWrite(4,LOW);
  }

}
