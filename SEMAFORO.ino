//Declaramos como constantes los números los puertos que usaremos
const int LED_RED = 4;
const int LED_YELLOW = 3;
const int LED_GREEN = 2;

void setup() {
  // Inicializamos el puerto Serial1 en el cual está conectado el módulo bluetooth 
  // a una frecuencia de 38400 (este numero varia dependiendo del módulo bluetooth):
  Serial1.begin(38400);
  Serial
  // Declaramos los puertos que usarán los leds como puertos de salida
  pinMode(LED_RED,OUTPUT);
  pinMode(LED_YELLOW,OUTPUT);
  pinMode(LED_GREEN,OUTPUT);
}

void loop() {
  // Evaluamos si el puerto del bluetooth recibe alguna señal
  if(Serial1.available()) {
    //Guardamos en una variable el valor recibido del puerto serial 
    int command = Serial1.read();
    //Usando un 'swith' evaluamos qué valor fue mandado desde android
    switch(command) {
      //Android mando el valor 4
      case LED_RED:
      //Encendemos el Led rojo y apagamos los demas.
      digitalWrite(LED_RED, HIGH);
      digitalWrite(LED_YELLOW, LOW);
      digitalWrite(LED_GREEN, LOW);
      break;
      
      //Android mando el valor 3
      case LED_YELLOW:
      //Encendemos el Led amarillo y apagamos los demas.
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_YELLOW, HIGH);
      digitalWrite(LED_GREEN, LOW);
      break;

      //Android mando el valor 2
      case LED_GREEN:
      //Encendemos el Led verde y apagamos los demás.
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_YELLOW, LOW);
      digitalWrite(LED_GREEN, HIGH);
      break;
    }
  }
}
