#define echoPin_r 38
#define echoPin_f 42
#define echoPin_l 40
#define trigPin 36

int enR=7 ,enL=10,in1L=16,in2L=17,in1R=14,in2R=15;

long duration_f;
long distance_f;

long duration_l;
long distance_l;

long duration_r;
long distance_r;

void setup() 
{
    Serial.begin(9600);
  pinMode(in1L,OUTPUT);
  pinMode(in1R,OUTPUT);
  pinMode(in2L,OUTPUT);
  pinMode(in2R,OUTPUT);
  pinMode(enR,OUTPUT);
  pinMode(enL,OUTPUT);
  //forward();

  pinMode(echoPin_f,INPUT);
  pinMode(echoPin_l,INPUT);
  pinMode(echoPin_r,INPUT);
  pinMode(trigPin,OUTPUT);
}

void loop() {
    //ultrasonic setup
    //flag=1;
    digitalWrite(trigPin,LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin,LOW);
    duration_l=pulseIn(echoPin_l,HIGH);
    distance_l=duration_l/58.2;
    Serial.println(distance_l);

    digitalWrite(trigPin,LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin,LOW);
    duration_r=pulseIn(echoPin_r,HIGH);
    distance_r=duration_r/58.2;
    Serial.println(distance_r);


    if(distance_l<10 && distance_l!=0)
    {
      //flag=0;
      right();
      delay(125);
      left();
      //delay(200);
    }

    if(distance_r<10 && distance_r!=0 )
    {
      //flag=0;
      left();
      delay(125);
      right();
      //delay(200);
    }

    if((distance_l>=10 || distance_l==0) && (distance_r>=10 || distance_r==0))
    {
      forward();
    }

    

  

}

void right()
{
  analogWrite(enR,255);
  analogWrite(enL,255);
  digitalWrite(in2R, LOW);
  digitalWrite(in1R, HIGH);
  digitalWrite(in2L, LOW);
  digitalWrite(in1L, HIGH);
  Serial.println("RIGHT");  
  //delay(10);
}

void forward()
{
  analogWrite(enR,255);
  analogWrite(enL,255);
  digitalWrite(in1L, LOW);
  digitalWrite(in2L, HIGH);
  digitalWrite(in2R, LOW);
  digitalWrite(in1R, HIGH);
  Serial.println("forward2");
  
}

void left()
{
  analogWrite(enR,255);
  analogWrite(enL,255);
  digitalWrite(in2R, HIGH);
  digitalWrite(in1R, LOW);
  digitalWrite(in2L, HIGH);
  digitalWrite(in1L, LOW);
  Serial.println("LEFT");
}
