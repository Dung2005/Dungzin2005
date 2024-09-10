const int led = 19;
const int led1 = 21;
const int led2 = 18;
unsigned long trcdo = 0;
int currentLed = 0;
const long interval = 1000;  // Khoảng thời gian co dinh giữa các lần nháy (1 giây)
bool nhaymood = false;
void setup(){
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}
String input;
void dieukhien(String input){
  if(input.equals("on led1")){
      digitalWrite(led, HIGH);
      digitalWrite(led1 , LOW);
      digitalWrite(led2 , LOW);
      nhaymood =false;
    }
    else if(input.equals("on led2")){
      digitalWrite(led1, HIGH);
      digitalWrite(led , LOW);
      digitalWrite(led2, LOW);
      nhaymood = false; // tat che do nhay neu dang bat
    }
    else if(input.equals("on led3")){
      digitalWrite(led2, HIGH);
      digitalWrite(led , LOW);
      digitalWrite(led1 ,  LOW);
      nhaymood = false;
    }
    else if(input.equals("nhay")){
      nhaymood = true;//khi nhan dc lenh nhay tu cong serial no se bat 
      // digitalWrite(led , HIGH);
      // delay(1000);
      // digitalWrite(led , LOW);
      // delay(1000);
      // digitalWrite(led1, HIGH);
      // delay(1000);
      // digitalWrite(led1, LOW);
      // delay(1000);
      // digitalWrite(led2, HIGH);
      // delay(1000);
      // digitalWrite(led2, LOW);
      // delay(1000);
    }
    else if(input.equals("off")){
      digitalWrite(led, LOW);
      digitalWrite(led1 , LOW);
      digitalWrite(led2 , LOW);
      nhaymood = false;
      Serial.println("all led off");
    }
    // else if(input.equals("3 den sang xong tat")){

    // }
    else{
      Serial.println("nhap sai cau lenh");
    }
}
void loop(){
  if(Serial.available()){
    input = Serial.readStringUntil('\n');//doc chuoi cho den khi an enter.
    input.trim();//loai bo ki tu trang du thua o cuoi hoac dau chuoi;
    Serial.println(input);
    dieukhien(input);
  }
   if (nhaymood) {
    unsigned long htai = millis();
    //htai luu gtri htai, moi khi ctrinh chay no se lay tgian tai diem do;
    if (htai - trcdo >= interval) {
    // ktra xem bao nhiu tgian troi qu a ke tu luc no thay doi trang thai
      // Đã đủ thời gian để chuyển đèn
      trcdo = htai;

      // Tắt tất cả các đèn trước khi bật đèn kế tiếp
      digitalWrite(led, LOW);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);

      // Chuyển đến đèn kế tiếp
      if (currentLed == 0) {
        digitalWrite(led, HIGH);
        currentLed = 1;
      } else if (currentLed == 1) {
        digitalWrite(led1, HIGH);
        currentLed = 2;
      } else if (currentLed == 2) {
        digitalWrite(led2, HIGH);
        currentLed = 0;
      }
    }
  }
}
