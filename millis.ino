int ctr1 =0; 
int ctr2 =0;
int initialMillis =0;
int decimoSegundo = 100;
int dosSegundos= 2000;
int previousMillisCtr1 =0;
int previousMillisCtr2 =0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  int currentMillis = millis();
 
  if(currentMillis - previousMillisCtr1 >= decimoSegundo){
    previousMillisCtr1 = currentMillis;
    Serial.print("C1 : ");
    ctr1++;
    Serial.print(ctr1);
    Serial.print(" C2 : ");
    Serial.println(ctr2);
  }
    
  if(currentMillis - previousMillisCtr2 >= dosSegundos){
    previousMillisCtr2 = currentMillis;
  ctr2++;
  ctr1 -= ctr2;
  Serial.println("2 segundos");
  Serial.print("C1 : ");
  Serial.print(ctr1);
  Serial.print(" C2 : ");
  Serial.println(ctr2);
  }
}