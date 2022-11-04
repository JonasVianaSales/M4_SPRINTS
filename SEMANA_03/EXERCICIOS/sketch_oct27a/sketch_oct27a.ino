const int button1 = 1;
const int button2 = 2;
const int ledG = 4;
const int ledR = 5;
const int ledB = 6;
const int ledY = 7;
const int BUZZ = 12;
const int LDR = 8;
int k = 0;
int j = 0;
int a = 0;
int save[64];
int pitch[16];

void setup() {
  Serial.begin(9600);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(ledG, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(BUZZ, OUTPUT);  
  pinMode(LDR, INPUT);
}

void loop() {
  // Converte de 4096 à 16 e armazena numa array em binário //
  int binary[4] = {0, 0, 0, 0};
  int ldrStatus = analogRead(LDR);
  int buttonStatus1 = digitalRead(button1);
  int buttonStatus2 = digitalRead(button2);
  int resul = floor(ldrStatus/256);
  int i = 3;
  while (resul > 0) {
    binary[i] = resul % 2;
    resul = resul / 2;
    i--;
  }
  resul = floor(ldrStatus/256);
  if (buttonStatus1 == HIGH){
    digitalWrite(ledG, binary[0]); 
    digitalWrite(ledR, binary[1]);
    digitalWrite(ledB, binary[2]);
    digitalWrite(ledY, binary[3]);
    tone(BUZZ, 1000 + (resul*100));
    delay(150);
    noTone(BUZZ);
    digitalWrite(ledG, LOW); 
    digitalWrite(ledR, LOW);
    digitalWrite(ledB, LOW);
    digitalWrite(ledY, LOW);
    for (k = 0; k < 4; k++){
      save[j] = binary[k];
      j += 1;
    }
    pitch[a] = 1000 + (resul*100);
    a += 1;
  }
  if (buttonStatus2 == HIGH){
    int e = 0;
    for (k = 0; k < a; k++){
      digitalWrite(ledG, save[e++]); 
      digitalWrite(ledR, save[e++]);
      digitalWrite(ledB, save[e++]);
      digitalWrite(ledY, save[e++]);
      tone(BUZZ, pitch[k]);
      delay(150);
      noTone(BUZZ);
    }
    digitalWrite(ledG, LOW); 
    digitalWrite(ledR, LOW);
    digitalWrite(ledB, LOW);
    digitalWrite(ledY, LOW);
    for (k = 0; k < 64; k++){
      save[k] = 0;
    }
    for (k = 0; k < 16; k++){
      pitch[k] = 0;
    }
    a = 0;
    j = 0;
  }
}
