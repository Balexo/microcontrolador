int ctr1 =0; 
int unSegundo= 1000;
unsigned long previousMillisCtr1 =0;


 void Print( int ctr1){
    Serial.println(" C1 : " + String(ctr1));
  }

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillisCtr1 >= unSegundo){
    previousMillisCtr1 = currentMillis;
    Print(ctr1);
    ctr1++;
  }  
}