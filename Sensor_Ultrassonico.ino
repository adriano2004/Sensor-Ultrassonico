int pinTrigger=3;
int pinEcho=2;
float tempoEcho=0;

int led_vermelho=10;
int led_amarelo=9;
int led_verde=8;


const float velocidadeSom_mporus = 0.000340;

void setup()
{
    pinMode(pinTrigger, OUTPUT);
    digitalWrite( pinTrigger, LOW);
    pinMode(pinEcho, INPUT);
    pinMode(led_verde, OUTPUT);
    pinMode(led_amarelo, OUTPUT);
    pinMode(led_vermelho, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    float distancia;

    DisparaPulsoUltrassonico();
    tempoEcho = pulseIn( pinEcho, HIGH);
    distancia = CalculaDistancia(tempoEcho);

    Serial.print("Distancia em metros: ");
    Serial.println(distancia);
  
    if(distancia > 2.0){
        digitalWrite(led_verde, HIGH);
        digitalWrite(led_amarelo, LOW);
        digitalWrite(led_vermelho, LOW);
    }
    else if(distancia < 2.0 && distancia >1.0){
        digitalWrite(led_verde, LOW);
        digitalWrite(led_amarelo, HIGH);
        digitalWrite(led_vermelho, LOW);    
        }  
    else{
        digitalWrite(led_verde, LOW);
        digitalWrite(led_amarelo, LOW);
        digitalWrite(led_vermelho, HIGH);    
        }  
    Serial.println(distancia);
}

void DisparaPulsoUltrassonico(){
  digitalWrite(pinTrigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(pinTrigger, LOW);
}

float CalculaDistancia (float tempo_us){
    return(( tempo_us * velocidadeSom_mporus)/2);
}
