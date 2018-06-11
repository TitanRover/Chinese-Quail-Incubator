#include <DHT.h>

int Com1= 2;  //afkoel fan
int humlow= 3;
int humreg= 5;
int humhigh= 6;
int Com2= 7;  //sirkulasie fan
int Com3= 8;  //lig
int i= 2;

#include "DHT.h"
#define DHTPIN 4     // sensor pin
#define DHTTYPE DHT11   // DHT 11 
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
    Serial.begin(9600); 
    dht.begin();

}

void loop()
{
        
  float h = dht.readHumidity();
  float temp = dht.readTemperature(); //kry temperatuur  
    
 /* Serial.print("#S|TEMPHUMI|[");
  Serial.print("  Tempertuur");  //om te sien wat die lesing is
  Serial.print(temp);
  Serial.print(" *C    ");
  Serial.print("Humiditeit: ");
  Serial.print(h);  //om te sien wat die lesing is
  Serial.print(" %/t    ");
  Serial.println("]#");  // hierdie is die code wat ek hardloop om die data vanaf die temp en humiditeid sensor 
  te log in i text file deur gobetwino...
*/
  
  Serial.print("Tempertuur: ");  //om te sien wat die temp lesing is
  Serial.print(temp);
  Serial.print(" *C    ");
  Serial.print("Humiditeit: ");
  Serial.print(h);  //om te sien wat die humi lesing is
  Serial.print(" %/t    ");
  Serial.println();

  
  
  Light();
  Humid();
  pinMode(Com1,OUTPUT);  //afkoel fan 
  pinMode(Com2,OUTPUT);  //sirkulasie fan
  pinMode(Com3,OUTPUT);  //lig
  pinMode(humlow,OUTPUT);  //led blou
  pinMode(humreg,OUTPUT);  //led wit
  pinMode(humhigh,OUTPUT);  //led rooi
}

void Light()
{
  float h = dht.readHumidity();  // kry humi en stoor as h
  float temp = dht.readTemperature(); //kry temperatuur en stoor as temp

  
  if (i=2)
  {
    digitalWrite(Com1, HIGH); //altyd aan vir sirkulasie
  }

  if (temp < 37) 
  {
    digitalWrite(Com3, HIGH);  //lig aan
    //digitalWrite(Com1, LOW);  //afkoel fan af
  }
  else if(temp > 38) {
    digitalWrite(Com3, LOW);  //lig af
 }
}
//  else if (temp > 39)
//    digitalWrite(Com1, HIGH);  //afkoel fan aan  
//  }


void Humid() {
 
  float h = dht.readHumidity();  // hierdie is om met die drie led's die relatiewe humi aan te dui.
 
  if (h < 50)
  {
    digitalWrite(humlow,LOW);
    digitalWrite(humreg,HIGH);
    digitalWrite(humhigh,HIGH);
  }
  else if (h < 60)
  {
    digitalWrite(humlow,HIGH);
    digitalWrite(humreg,LOW);
    digitalWrite(humhigh,HIGH);
  }
else if (h > 60)
{
  digitalWrite(humlow,HIGH);
  digitalWrite(humreg,HIGH);
  digitalWrite(humhigh,LOW);
}
}
