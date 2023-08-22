//BUZZER MUSIC CODES
int Do = 262;
int Re = 294;
int Mi = 330;
int Fa = 349;
int Sol = 392;
int La = 440;
int Si = 494;
int Do_ = 523;

int red_led=2;
int button_red=3;
int green_led=4;
int button_green=5;
int blue_led=6;
int button_blue=7;
int buzzer=8;
int a0_value=0;
int counter_red=0;
int counter_green=0;
int counter_blue=0;

void setup() 
{
  Serial.begin(9600);
  pinMode(red_led,OUTPUT);
  pinMode(green_led,OUTPUT);
  pinMode(blue_led,OUTPUT);
  pinMode(button_red,INPUT);
  pinMode(button_green,INPUT);
  pinMode(button_blue,INPUT);
  pinMode(buzzer,OUTPUT);
}

void loop() 
{
  a0_value =analogRead(A0);
  Serial.println(a0_value);
  
  //BUTTON PART
  if(digitalRead(button_red) == HIGH)
  { 
    counter_red++;

    if(counter_red<5)
    single_note(red_led,Mi);
    
    else if(counter_red==5)
    mixed_up(red_led,Do,Re,Mi,counter_red); 
  }

  if(digitalRead(button_green) == HIGH)
  { 
    counter_green++;

    if(counter_green<5)
    single_note(green_led,Fa);

    else if(counter_green == 5)
    mixed_up(green_led,Mi,Fa,Sol,counter_green);  
  }

  if(digitalRead(button_blue) == HIGH)
  { 
    counter_blue++;

    if(counter_blue<5)
    single_note(blue_led,Sol);

    else if(counter_blue==5)
    mixed_up(blue_led,Sol,La,Si,counter_blue);
  }

  //POTENTIOMETER PART
  if(a0_value ==0)
  noTone(buzzer);

  if(a0_value >0 && a0_value <=250)
  pot(Do,Re);

  if(a0_value >250 && a0_value <=500)
  pot(Mi,Fa);

  if(a0_value >500 && a0_value <=750)
  pot(Sol,La);

  if(a0_value >750 && a0_value <=1000)
  pot(Si,Do_);

  if(a0_value >1000)
  {
  tone(buzzer,Do_);
  delay(2000);
  }
}

//WHEN THE COUNTER IS LESS THAN FIVE
void single_note(int led_name, int note)
{
  digitalWrite(led_name,HIGH);
  tone(buzzer,note);
  delay(200);
  noTone(buzzer);
  delay(10);
  digitalWrite(led_name,LOW);
}

//WHEN THE COUNTER EQUALS FIVE
void mixed_up(int led_name, int note1, int note2, int note3, int counter_name)
{
  digitalWrite(led_name,HIGH);
  delay(100);
  tone(buzzer,note1);
  delay(800);
  tone(buzzer,note2);
  delay(200);
  tone(buzzer,note3);
  delay(400);
  tone(buzzer,note1);
  delay(200);
  noTone(buzzer);
  delay(10);
  tone(buzzer,note1);
  delay(200);
  noTone(buzzer);
  delay(10);
  digitalWrite(led_name,LOW);
  delay(100); 
  counter_name=0;
}

//POTENTIOMETER FUNCTION
void pot(int note1, int note2)
{
  tone(buzzer,note1);
  delay(600);
  tone(buzzer,note2);
  delay(200);
  noTone(buzzer);
  delay(10);
}

