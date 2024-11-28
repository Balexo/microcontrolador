int count=0;
const int FIXEDMODE=1;
bool isRunning=false;
unsigned long initialMillis=0;
bool isFixedMode = true;
int timeInterval=1000;
int fixedValue=0;
int alternativeValue =1;

 void printHelpMenu(){
    Serial.println("H o h (help): muestra este menu de ayuda.");
    Serial.println("START o start: publica cada segundo un valor por el puerto serie");
    Serial.println("STOP o stop: detiene la publicación del valor.");
    Serial.println("T o t (time): El siguiente valor enviado cambiará el periodo de publicación de la señal entre 1 y 10 veces por segundo.");
    Serial.println("M o m (mode): cambia el modo de fijo a alternativo. En modo fijo la señal se emite mantiene siempre el mismo valor siendo el ultimo emitido, por defecto debe ser un 1. Por otra parte, en modo alternativo cada vez que se publica el valor se alterna entre 0 y 1.");
    
  }

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  srand(analogRead(A0));
  printHelpMenu();
}

void loop() {
  if(Serial.available()>0){
  
    String text = Serial.readStringUntil('\n');
    text.toLowerCase();

    if(text=="h"){
      printHelpMenu();
     }
    else if(text=="start"){
      isRunning = true;
      Serial.println("Inicio publicación");
    }
    else if(text=="stop"){
      isRunning = false;
      Serial.println("Final de publicación");
    }
    else if(text=="t"){  
      Serial.println("El número debe estar entre 1 y 10.");
      while(Serial.available()==0);
      long int number = Serial.parseInt();
      if(number<1 || number>10){
       Serial.println("Valor inválido");
      }
      timeInterval = number * 1000;
      Serial.println("Nuevo intervalo de publicación " + String(timeInterval));
    }
    else if(text=="m"){
      isFixedMode = !isFixedMode;
      if(isFixedMode){
        Serial.println("Modo fijo activado");
      }else{
        Serial.println("Modo alternativo activado");
      }
    }
   
  }

if (isRunning){
    unsigned long currentMillis = millis();
   
      if(currentMillis- initialMillis>= timeInterval){
        initialMillis = currentMillis;
      
        if(isFixedMode){
          Serial.println("Valor fijo: " + String(fixedValue));
        }else{
        Serial.println("Valor alternativo: " + String(alternativeValue));
        }
      }
    }
}