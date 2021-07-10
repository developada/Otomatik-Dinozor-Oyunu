#include <Servo.h> //Servo motoru kullanabilmek için ilgili kütüphaneyi dahil ettik.

const int LDR = A0;

const int maxIsik = 70;    //Tepki vermesi gereken ışık düzeyini ayarladık.
const int basmaAcisi = 63; //Servo, butona bastığında kaç derecelik açıda olacağını belirttik.
const int geriCekme = 70;  //Servo, butona basmazken kaç derecelik açıda duracağını belirttik.
const int bekleme = 50;    //Servo, butona bastıktan kaç milisaniye sonra geri çekileceğini belirttik.

Servo servo;      //Servo motorumuza "servo" ismini verdik.

void setup() {
  servo.attach(9);   //"servo" adlı motoru 9. pine bağladığımızı belirttik.
}

void loop() {
  if (analogRead(LDR) > maxIsik) { //LDR'nin okuduğu ışık değeri bizim belirlediğimiz değerden yüksek ise çalışacak.
    servo.write(basmaAcisi);          //Servo belirlediğimiz basma açısına gelecek.
    delay(bekleme);               //Belirlediğimiz bekleme süresi kadar bekleyecek.
    servo.write(geriCekme);          //Servo belirlediğimiz geri çekme açısına gelecek.

  }
}
