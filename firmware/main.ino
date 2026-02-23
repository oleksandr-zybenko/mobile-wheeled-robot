Код програми управління
#define PIN_ECHO_1 0
#define PIN_TRIG_1 1
#define PIN_ECHO_2 2
#define PIN_TRIG_2 3
#define PIN_ECHO_3 4
#define PIN_TRIG_3 5
#define INT_1ZP 6
#define INT_2ZP 7
#define INT_3ZL 8
#define INT_4ZL 9
#define INT_1PL 10
#define INT_2PL 11
#define INT_3PP 12
#define INT_4PP 13
long duration_1,duration_2, duration_3;
int cm_1, cm_2, cm_3;

void setup() {

 //Определяем вводы и выводы
 pinMode(PIN_TRIG_1, OUTPUT);
 pinMode(PIN_ECHO_1, INPUT);
 pinMode(PIN_TRIG_2, OUTPUT);
 pinMode(PIN_ECHO_2, INPUT);
 pinMode(PIN_TRIG_3, OUTPUT);
 pinMode(PIN_ECHO_3, INPUT);
 pinMode(INT_1PL, OUTPUT);
 pinMode(INT_2PL, OUTPUT);
 pinMode(INT_3PP, OUTPUT);
 pinMode(INT_4PP, OUTPUT);
 pinMode(INT_1ZP, OUTPUT);
 pinMode(INT_2ZP, OUTPUT);
 pinMode(INT_3ZL, OUTPUT);
 pinMode(INT_4ZL, OUTPUT);
}

void loop()
{
 f_1();
 f_2();
 f_3();
 Vpered();

 if(cm_1 < 15)
 {
 Nazad();
 delay (300);
 Povorot_P();
 delay(200);
 }
 if(cm_2 < 22)
 {
 Povorot_L();
 delay (100);
 }
 if(cm_3 < 20)
 {
 Povorot_P();
 delay (100);
 }
 if(cm_3 < 24 && cm_2 < 26)
 {
 Povorot_P();
 delay (500);
 }
}
long f_1()
{
 digitalWrite(PIN_TRIG_1, LOW);
 delayMicroseconds(5);
 digitalWrite(PIN_TRIG_1, HIGH);


 delayMicroseconds(10);
 digitalWrite(PIN_TRIG_1, LOW);
 duration_1 = pulseIn(PIN_ECHO_1, HIGH);
 cm_1 = (duration_1 / 2) / 29.1;
 return cm_1;
}
long f_2()
{
 digitalWrite(PIN_TRIG_2, LOW);
 delayMicroseconds(5);
 digitalWrite(PIN_TRIG_2, HIGH);


 delayMicroseconds(10);
 digitalWrite(PIN_TRIG_2, LOW);
 duration_2 = pulseIn(PIN_ECHO_2, HIGH);
 cm_2 = (duration_2 / 2) / 29.1;
 return cm_2;
}
long f_3()
{
 digitalWrite(PIN_TRIG_3, LOW);
 delayMicroseconds(5);
 digitalWrite(PIN_TRIG_3, HIGH);


 delayMicroseconds(10);
 digitalWrite(PIN_TRIG_3, LOW);
 duration_3 = pulseIn(PIN_ECHO_3, HIGH);
 cm_3 = (duration_3 / 2) / 29.1;
 return cm_3;
}
void Vpered()
{
 digitalWrite (INT_1PL, HIGH);
 digitalWrite (INT_2PL, LOW);
 digitalWrite (INT_3ZL, HIGH);
 digitalWrite (INT_4ZL, LOW);

 digitalWrite (INT_1ZP, LOW);
 digitalWrite (INT_2ZP, HIGH);
 digitalWrite (INT_3PP, LOW);
 digitalWrite (INT_4PP, HIGH);
}
void Povorot_P()
{
 digitalWrite (INT_1PL, HIGH);
 digitalWrite (INT_2PL, LOW);
 digitalWrite (INT_3ZL, HIGH);
 digitalWrite (INT_4ZL, LOW);

 digitalWrite (INT_1ZP, HIGH);
 digitalWrite (INT_2ZP, LOW);
 digitalWrite (INT_3PP, HIGH);
 digitalWrite (INT_4PP, LOW);
 }
void Povorot_L()
{
 digitalWrite (INT_1PL, LOW);
 digitalWrite (INT_2PL, HIGH);
 digitalWrite (INT_3ZL, LOW);
 digitalWrite (INT_4ZL, HIGH);

 digitalWrite (INT_1ZP, LOW);
 digitalWrite (INT_2ZP, HIGH);
 digitalWrite (INT_3PP, LOW);
 digitalWrite (INT_4PP, HIGH);
}
void Nazad()
{
 digitalWrite (INT_1PL, LOW);
 digitalWrite (INT_2PL, HIGH);
 digitalWrite (INT_3ZL, LOW);
 digitalWrite (INT_4ZL, HIGH);

 digitalWrite (INT_1ZP, HIGH);
 digitalWrite (INT_2ZP, LOW);
 digitalWrite (INT_3PP, HIGH);
 digitalWrite (INT_4PP, LOW);
} 
