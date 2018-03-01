const int sp11= 12;
const int sp12= 11;
const int sp21 =10;
const int sp22= 9;
int command=0;
float voltage,cell1,cell2,cell3,cell4;
float node0,node1,node2,node3,node4,node5,node6,node7,node8;
long previousMillis = 0;
long interval = 10000;
float refrence=4.9;
int pro_begin=0,slected=0;

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
 digitalWrite(sp11, LOW);
digitalWrite(sp12, LOW);
digitalWrite(sp21, LOW);
digitalWrite(sp22, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
unsigned long currentMillis = millis();
  if(currentMillis - previousMillis > interval || pro_begin==0) {
    pro_begin=1;
    previousMillis = currentMillis;   
    clr_screen();
Serial.println("enter number to select one of the 4 options");

Serial.println("Case ""0"" All cell disconnected");
Serial.println("case ""1"" Two in prallel then combined in prallel -->All in prallel");
Serial.println("case ""2"" Two in series then combined in prallel");
Serial.println("case ""3"" Two in series then combined in Series -->ALL in series");
Serial.println("case ""4"" ALL in series for charging");
Serial.println();

command = (int)Serial.read();
Serial.write(command);
Serial.print("A0=");
node0=analogRead(A0)*(refrence/1023)*11;
Serial.println(node0);
Serial.print("A1=");
node1=analogRead(A1)*(refrence/1023)*11;
Serial.println(node1);
Serial.print("A2=");
node2=analogRead(A2)*(refrence/1023)*11;
Serial.println(node2);
Serial.print("A3=");
node3=analogRead(A3)*(refrence/1023)*11;
Serial.println(node3);
Serial.print("A4=");
node4=analogRead(A4)*(refrence/1023)*11;
Serial.println(node4);
Serial.print("A5=");
node5=analogRead(A5)*(refrence/1023)*11;
Serial.println(node5);
Serial.print("A6=");
node6=analogRead(A6)*(refrence/1023)*11;
Serial.println(node6);
Serial.print("A7=");
node7=analogRead(A7)*(refrence/1023)*11;
Serial.println(node7);
Serial.println("");
Serial.println("");
Serial.println("");
cell1=node7-node6;
Serial.print("Cell1=");
Serial.println(cell1);


cell2=node5-node4;
Serial.print("Cell2=");
Serial.println(cell2);



cell3=node3-node2;
Serial.print("Cell3=");
Serial.println(cell3);

cell4=node1-node0;
Serial.print("Cell4=");
Serial.println(cell4);
Serial.print("Final output=");
Serial.println(node7-node0);
selected_option();
  }
  if(command>-1)
  {
command=command-48;
//Serial.println(command);
  }
switch(command)
{
  
case 0: //all off no outputt
      
digitalWrite(sp11, LOW);
digitalWrite(sp12, LOW);
digitalWrite(sp21, LOW);
digitalWrite(sp22, LOW);
digitalWrite(13, HIGH);
Serial.println("All cells disconnected no output ");
slected=0;
pro_begin=0;
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
slected=1;
pro_begin=0;
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
slected=2;
pro_begin=0;
break;
delay(1);

case 3://Two in series combined in series
Serial.println(" case 3 = Two in series then combined in Series");  
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
slected=3;
pro_begin=0;
break;

case 4:
Serial.println(" case 4 = All in series for charging");  
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
slected=4;
pro_begin=0;
break;

default:

break;
}

delay(500);


}

void clr_screen(void)
{
   Serial.write(27);       // ESC command
 // Serial.print("[2J");    // clear screen command
  Serial.write(27);
  Serial.print("[H");     // cursor to home command
}

void selected_option(void)
{
    Serial.write(27);
  Serial.print("[J");     // clear screen from curssor point command
  
  if(slected==0)
  {
    Serial.println("ALL outputs off");
  }


  if(slected==1)
  {
    Serial.println("All in prallel ");
  }

  if(slected==2)
  {
  
    Serial.println("Two in series then cobined in prallel");
  }


  if(slected==3)
  {
    Serial.println("ALL in series    ");
  }

  
  if(slected==4)
  {
    Serial.println("charging");
  }
}



