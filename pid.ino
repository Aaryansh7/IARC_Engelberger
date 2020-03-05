int ir[6],er[6],res[6],preErr[6]={0,0,0,0,0,0};
int kp=50,kd=10,ki=0,we=500,wm=1,wi=500,tRec=10,leftEr,rightEr;
char sp = ' ';
String nspeed = "New Speed :    ";
int enR=7,enL=10,in1L=16,in2L=17,in1R=14,in2R=15;
void setup() 
{
    Serial.begin(9600);
  pinMode(in1L,OUTPUT);
  pinMode(in1R,OUTPUT);
  pinMode(in2L,OUTPUT);
  pinMode(in2R,OUTPUT);
  pinMode(enR,OUTPUT);
  pinMode(enL,OUTPUT);

}

void loop() {
  int td;
    ir [0] = analogRead(A2);
    ir [1] = analogRead(A0);
    ir [2] = analogRead(A1);
    ir [3] = analogRead(A8);
    ir [4] = analogRead(A12);
    ir [5] = analogRead(A6);
     for(int i=0;i<6; i++)
    {
      Serial.print(ir[i]);
      Serial.print(" ");
    }
    Serial.println();
    for (int i=0; i<6; ++i)
    {
      if(ir[i]>200)
        ir[i]=1;
       else
        ir[i]=0;
    }
   er[0]=(1-ir[0])*we;
   er[1]=(1-ir[1])*wm;
   er[2]=(-ir[2])*wi;
   er[3]=(-ir[3])*wi;
   er[4]=(1-ir[4])*wm;
   er[5]=(1-ir[5])*we; 
   PID();
   leftEr=res[3]+res[4]+res[5];
   rightEr=res[0]+res[1]+res[2];
  
   Serial.print("Left error ");
   Serial.println(leftEr);
   Serial.print("Right error ");
   Serial.println(rightEr);
  
   
   if(leftEr>0)
   {delay(60);
  analogWrite(enR,200);
  analogWrite(enL,120);
  digitalWrite(in2R, HIGH);
  digitalWrite(in1R, LOW);
  digitalWrite(in2L, HIGH);
  digitalWrite(in1L, LOW);
  Serial.println("LEFT");
  if((leftEr+rightEr)>0)
  td=leftEr+rightEr;
  else
  td=leftEr;
  
  
   }
   else if(rightEr>0)
   {delay(60);
  analogWrite(enR,200);
  analogWrite(enL,120);
  digitalWrite(in2R, LOW);
  digitalWrite(in1R, HIGH);
  digitalWrite(in2L, LOW);
  digitalWrite(in1L, HIGH);
  Serial.println("RIGHT");
  if((leftEr+rightEr)>0)
  td=leftEr+rightEr;
  else
  td=rightEr;
   }
   
  tRec=td;
  if(tRec>1000)
  delay(tRec/100);
  else
   delay(tRec/15);
   forward();
}

void PID()
{int i;
  for(i=0;i<6;i++)
  {
    res[i]=kp*er[i]+(kd*(er[i]-preErr[i])/10)+(ki*er[i]*10);
    preErr[i]=er[i];
      
  }
}

void right()
{
  analogWrite(enR,255);
  analogWrite(enL,160);
  digitalWrite(in2R, LOW);
  digitalWrite(in1R, HIGH);
  digitalWrite(in2L, LOW);
  digitalWrite(in1L, HIGH);
  Serial.println("RIGHT");
 
  
  
}


void left()
{
  analogWrite(enR,255);
  analogWrite(enL,160);
  digitalWrite(in2R, HIGH);
  digitalWrite(in1R, LOW);
  digitalWrite(in2L, HIGH);
  digitalWrite(in1L, LOW);
  Serial.println("LEFT");
  
  
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
