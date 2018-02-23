const int sp11= 12;
const int sp12= 11;
const int sp21 =10;
const int sp22= 9;
int command=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sp11, OUTPUT);
  pinMode(sp12, OUTPUT);
  pinMode(sp21, OUTPUT);
  pinMode(sp22, OUTPUT);
digitalWrite(sp11, LOW);
digitalWrite(sp12, LOW);
digitalWrite(sp21, LOW);
digitalWrite(sp22, LOW);
 pinMode(13, OUTPUT);

Serial.println("enter number to select one of the 3 options");

Serial.println("Case ""0"" All cell disconnected");
Serial.println("case ""1"" Two in prallel then combined in prallel -->All in prallel");
Serial.println("case ""2"" Two in series then combined in prallel");
Serial.println("case ""3"" Two in series then combined in Series -->ALL in series");
Serial.println();
 
}

void loop() {
  // put your main code here, to run repeatedly:
command = (int)Serial.read();
//Serial.write(command);
Serial.print("A0=");
Serial.println(analogRead(A0));
Serial.print("A1=");
Serial.println(analogRead(A1));
Serial.print("A2=");
Serial.println(analogRead(A2));
Serial.print("A3=");
Serial.println(analogRead(A3));
Serial.print("A4=");
Serial.println(analogRead(A4));
Serial.print("A5=");
Serial.println(analogRead(A5));
Serial.print("A6=");
Serial.println(analogRead(A6));
Serial.print("A7=");
Serial.println(analogRead(A7));
command=command-48;

switch(command)
{
  
case 0: //all off no outputt
      
digitalWrite(sp11, LOW);
digitalWrite(sp12, LOW);
digitalWrite(sp21, LOW);
digitalWrite(sp22, LOW);
digitalWrite(13, HIGH);
Serial.println("All cells disconnected no output ");
 break;

case 1:// Two in prallel  combined in prallel
Serial.println("case 1 = Two in prallel  combined in prallel");
digitalWrite(sp11, LOW);
digitalWrite(sp12, LOW);
digitalWrite(sp21, LOW);
digitalWrite(sp22, LOW);

delay(3);
digitalWrite(sp12, LOW);
digitalWrite(sp11, HIGH);
digitalWrite(sp21, LOW);
digitalWrite(sp22, HIGH);
delay(1);
 break;
case 2:// Two in series then cobined in prallel

Serial.println("Case 2 = Two in series then cobined in prallel");
digitalWrite(sp11, LOW);
digitalWrite(sp12, LOW);
digitalWrite(sp21, LOW);
digitalWrite(sp22, LOW);

delay(3);

digitalWrite(sp11, LOW);
digitalWrite(sp12, HIGH);
digitalWrite(sp21, LOW);
digitalWrite(sp22, HIGH);
break;
delay(1);
case 3://Two in series combined in series
Serial.println(" case 3 = Two in series then cobined in Series");  
digitalWrite(sp11, LOW);
digitalWrite(sp12, LOW);
digitalWrite(sp21, LOW);
digitalWrite(sp22, LOW);

delay(3);
digitalWrite(sp11, LOW);
digitalWrite(sp12, HIGH);
digitalWrite(sp22, LOW);
digitalWrite(sp21, HIGH);

delay(1);

digitalWrite(sp11, LOW);
digitalWrite(sp12, HIGH);
digitalWrite(sp21, LOW);
digitalWrite(sp22, HIGH);
delay(1);
break;

case 4: //same as case 1
Serial.println("All in prallel");
digitalWrite(sp11, LOW);
digitalWrite(sp12, LOW);
digitalWrite(sp21, LOW);
digitalWrite(sp22, LOW);
delay(3);
digitalWrite(sp11, HIGH);
digitalWrite(sp12, LOW);
digitalWrite(sp21, LOW);
digitalWrite(sp22, HIGH);
break;

default:

//digitalWrite(sp11, LOW);
//digitalWrite(sp12, LOW);
//digitalWrite(sp21, LOW);
//digitalWrite(sp22, LOW);
break;
}
delay(5000);

// all parallel
/*
digitalWrite(sp11, HIGH);
digitalWrite(sp12, LOW);
digitalWrite(sp21, LOW);
digitalWrite(sp22, HIGH);

delay(5000);
//all off
/*
 
digitalWrite(sp11, LOW);
digitalWrite(sp12, LOW);
digitalWrite(sp21, LOW);
digitalWrite(sp22, LOW);

delay(1000);
//two in series and then cobined in prallel
digitalWrite(sp11, LOW);
digitalWrite(sp12, HIGH);
digitalWrite(sp21, LOW);
digitalWrite(sp22, HIGH);
while(1);
delay(5000);
//all off

digitalWrite(sp11, LOW);
digitalWrite(sp12, LOW);
digitalWrite(sp21, LOW);
digitalWrite(sp22, LOW);

delay(3000);

 */ 
}
