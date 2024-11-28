int ctr1 =0; 
int ctr2 =0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
 
  ctr1++;
  Serial.print("C1 : ");
  Serial.print(ctr1);
  Serial.print(" C2 : ");
  Serial.println(ctr2);

  delay(100);

 if(ctr1%20==0){
    ctr2++;
    ctr1 -= ctr2;

    Serial.println("2 segundos");
    Serial.print("C1 : ");
    Serial.print(ctr1);
    Serial.print(" C2 : ");
    Serial.println(ctr2);
  }
}