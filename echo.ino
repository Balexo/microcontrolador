void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0);
  {
    String text= Serial.readStringUntil('\n');

    for( int i=0; i<text.length(); i++){
      char c =text[i];

      if(isUpperCase(c)){
        text[i] = toLowerCase(c);
      }else if(isLowerCase(c)){
        text[i] =toUpperCase(c);
      }
    }
   
   Serial.println(text);
  }
}