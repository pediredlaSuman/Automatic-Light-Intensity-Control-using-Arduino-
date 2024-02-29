int IR1 = 12;
int IR2 = 3;
int IR3 = 4;
int LED1 = 5;
int LED2 = 6;
int LED3 = 7;
int LDR = A3;
int LDRValue;

void setup() 
{
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3,OUTPUT);

  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3,INPUT);
  pinMode(LDR, INPUT);
  
  LDRValue = 0;
  
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3,LOW);
}

void loop() {

  LDRValue = analogRead(LDR);
  Serial.print("sensor = ");
  Serial.print(LDRValue);
  delay (500);

  if (LDRValue >= 600)
  {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3,LOW);
    Serial.println("It's Bright Outside; Lights status: OFF");
  }
  if (LDRValue < 600)
  {
    Serial.println("It's Dark Outside; Lights status: OFF");
  }
  if ((LDRValue < 600) && (digitalRead(IR1) == LOW)) 
    {
      digitalWrite(LED1, HIGH);
      Serial.println("It's Dark Outside; LED1 Lights status: ON");
      delay(600);
    }
  
  if ((LDRValue < 600) && (digitalRead(IR2) == LOW)) 
    {
      digitalWrite(LED2, HIGH);
      Serial.println("It's Dark Outside; LED2 Lights status: ON");
      delay(200);
    }  
    if ((LDRValue < 600) && (digitalRead(IR3) == LOW)) 
    {
      digitalWrite(LED3, HIGH);
      Serial.println("It's Dark Outside; LED3 Lights status: ON");
      delay(200);
    }
    if ((digitalRead(IR1) == HIGH)) 
    {
      digitalWrite(LED1, LOW);
    }
    if ((digitalRead(IR2) == HIGH)) 
    {
      digitalWrite(LED2, LOW);
    }
    if ((digitalRead(IR3) == HIGH)) 
    {
      digitalWrite(LED3, LOW);
    }
}
