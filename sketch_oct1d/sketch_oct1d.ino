int pin[4] = {2, 4, 6, 0};
int B = 8;
bool BS = 0;
int add = 0 ;
bool Press = 0;
long PerS = 0, Interval = 1000;
void setup() {
  // put your setup code here, to run once:
  for(int i=0;i<3;i++){
    pinMode(pin[i], OUTPUT);
  }
  pinMode(B, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {

  for(int i=0;i<=2;i+=1){
     digitalWrite(pin[i], 1);
  }

  unsigned long CurS = millis();

  if(CurS - PerS >= Interval){
    PerS = CurS;
    if(BS){
      add++;
      if(add > 3){
        add = 0;
      }
    }
    else
    {
      add--;
      if(add < 0){
        add = 3;
      }
    }
  }
  
  if(!digitalRead(B) && !Press){
    Press = 1;
    BS = !BS;
  }
  else if(digitalRead(B) && Press)
  {
    Press = 0;
  }

  if(add != 3){
     digitalWrite(pin[add], 0);
  }
  else
  {
    for(int i=0;i<=2;i+=1){
      digitalWrite(pin[i], 0);
    }
  }
  
}