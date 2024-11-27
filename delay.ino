int i =0; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
 
  Serial.println("Contador");
  Serial.println(i);
  i++;
  delay(1000);

}