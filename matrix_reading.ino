int ir[6],er[6],res[6],preErr[6];
int enR=7 ,enL=10,in1L=16,in2L=17,in1R=14,in2R=15;
int A,B,C,D,num;
node_det=0;

void setup() 
{
    Serial.begin(9600);
  pinMode(in1L,OUTPUT);
  pinMode(in1R,OUTPUT);
  pinMode(in2L,OUTPUT);
  pinMode(in2R,OUTPUT);
  pinMode(enR,OUTPUT);
  pinMode(enL,OUTPUT);
  forward();
}

void loop() {
    ir [0] = analogRead(A2);
    ir [1] = analogRead(A0);
    ir [2] = analogRead(A1);
    ir [3] = analogRead(A8);
    ir [4] = analogRead(A12);
    ir [5] = analogRead(A6);
    
    for (int i=0; i<6; ++i)
    {
      if(ir[i]>200)
        ir[i]=1;
       else
        ir[i]=0;
    } 

    if((ir[0]==ir[1] && ir[1]==ir[2] ) || (ir[3]==ir[4] && ir[4]==ir[5] )
    {
      node_det=1;
    }

   if(node_det==1)
   {
    
     // case1 :all white
     if(ir[0]==1 && ir[1]==1 && ir[2]==1 && ir[3]==1 && ir[4]==1 && ir[5]==1)
     {
      forward();
      C=0;
      D=0;
      node=node+1;
      //num=bin_dec(A,B,C,D);
      //func(node,num);
      delay(10);

         if(ir[0]==1 && ir[1]==1 && ir[2]==1 && ir[3]==1 && ir[4]==1 && ir[5]==1)
           {
            A=0;
            B=0;
            //node=1;
            num=bin_dec(A,B,C,D);
            func(node,num);
             delay(10);
           }
     }

    //case 2:one black rest white
      //subcase1
     else if(ir[0]==0 && ir[1]==0 && ir[2]==0 && ir[3]==1 && ir[4]==1 && ir[5]==1)
     {forward();
      C=1;
      D=0;
      node=node+1;
      //num=bin_dec(A,B,C,D);
      //func(node,num);
      delay(10);

         if(ir[0]==1 && ir[1]==1 && ir[2]==1 && ir[3]==1 && ir[4]==1 && ir[5]==1)
           {
            A=0;
            B=0;
            //node=1;
            num=bin_dec(A,B,C,D);
            func(node,num);
             delay(10);
           }
     }

      //subcase2
      else if(ir[0]==1 && ir[1]==1 && ir[2]==1 && ir[3]==0 && ir[4]==0 && ir[5]==0)
     {forward();
      C=0;
      D=1;
      node=node+1;
      //num=bin_dec(A,B,C,D);
      //func(node,num);
      delay(10);

         if(ir[0]==1 && ir[1]==1 && ir[2]==1 && ir[3]==1 && ir[4]==1 && ir[5]==1)
           {
            A=0;
            B=0;
            //node=1;
            num=bin_dec(A,B,C,D);
            func(node,num);
             delay(10);
           }
     }

      //subcase3
      else if(ir[0]==1 && ir[1]==1 && ir[2]==1 && ir[3]==1 && ir[4]==1 && ir[5]==1)
     {forward();
      C=0;
      D=0;
      node=node+1;
      //num=bin_dec(A,B,C,D);
      //func(node,num);
      delay(10);

         if(ir[0]==0 && ir[1]==0 && ir[2]==0 && ir[3]==1 && ir[4]==1 && ir[5]==1)
           {
            A=1;
            B=0;
            //node=1;
            num=bin_dec(A,B,C,D);
            func(node,num);
             delay(10);
           }
     }

      //subcase4
       else if(ir[0]==1 && ir[1]==1 && ir[2]==1 && ir[3]==1 && ir[4]==1 && ir[5]==1)
     {forward();
      C=0;
      D=0;
      node=node+1;
      //num=bin_dec(A,B,C,D);
      //func(node,num);
      delay(10);

         if(ir[0]==1 && ir[1]==1 && ir[2]==1 && ir[3]==0 && ir[4]==0 && ir[5]==0)
           {
            A=0;
            B=1;
            //node=1;
            num=bin_dec(A,B,C,D);
            func(node,num);
             delay(10);
           }
     }

   //case3:two white and two black
     //subcase1
      else if(ir[0]==0 && ir[1]==0 && ir[2]==0 && ir[3]==0 && ir[4]==0 && ir[5]==0)
     {forward();
      C=1;
      D=1;
      node=node+1;
      //num=bin_dec(A,B,C,D);
      //func(node,num);
      delay(10);

         if(ir[0]==1 && ir[1]==1 && ir[2]==1 && ir[3]==1 && ir[4]==1 && ir[5]==1)
           {
            A=0;
            B=0;
            //node=1;
            num=bin_dec(A,B,C,D);
            func(node,num);
             delay(10);
           }
     }

     //subcase2
       else if(ir[0]==0 && ir[1]==0 && ir[2]==0 && ir[3]==1 && ir[4]==1 && ir[5]==1)
     {forward();
      C=1;
      D=0;
      node=node+1;
      //num=bin_dec(A,B,C,D);
      //func(node,num);
      delay(10);

         if(ir[0]==0 && ir[1]==0 && ir[2]==0 && ir[3]==1 && ir[4]==1 && ir[5]==1)
           {
            A=1;
            B=0;
            //node=1;
            num=bin_dec(A,B,C,D);
            func(node,num);
             delay(10);
           }
     }

     //subcase3
      else if(ir[0]==0 && ir[1]==0 && ir[2]==0 && ir[3]==1 && ir[4]==1 && ir[5]==1)
     {forward();
      C=1;
      D=0;
      node=node+1;
      //num=bin_dec(A,B,C,D);
      //func(node,num);
      delay(10);

         if(ir[0]==1 && ir[1]==1 && ir[2]==1 && ir[3]==0 && ir[4]==0 && ir[5]==0)
           {
            A=0;
            B=1;
            //node=1;
            num=bin_dec(A,B,C,D);
            func(node,num);
             delay(10);
           }
     }

     //subcase4
      else if(ir[0]==1 && ir[1]==1 && ir[2]==1 && ir[3]==0 && ir[4]==0 && ir[5]==0)
     {forward();
      C=0;
      D=1;
      node=node+1;
      //num=bin_dec(A,B,C,D);
      //func(node,num);
      delay(10);

         if(ir[0]==0 && ir[1]==0 && ir[2]==0 && ir[3]==1 && ir[4]==1 && ir[5]==1)
           {
            A=1;
            B=0;
            //node=1;
            num=bin_dec(A,B,C,D);
            func(node,num);
             delay(10);
           }
     }

     //subcase5
      else if(ir[0]==1 && ir[1]==1 && ir[2]==1 && ir[3]==0 && ir[4]==0 && ir[5]==0)
     {forward();
      C=0;
      D=1;
      node=node+1;
      //num=bin_dec(A,B,C,D);
      //func(node,num);
      delay(10);

         if(ir[0]==1 && ir[1]==1 && ir[2]==1 && ir[3]==0 && ir[4]==0 && ir[5]==0)
           {
            A=0;
            B=1;
            //node=1;
            num=bin_dec(A,B,C,D);
            func(node,num);
             delay(10);
           }
     }

     //subcase6
       else if(ir[0]==1 && ir[1]==1 && ir[2]==1 && ir[3]==1 && ir[4]==1 && ir[5]==1)
     {forward();
      C=0;
      D=0;
      node=node+1;
      //num=bin_dec(A,B,C,D);
      //func(node,num);
      delay(10);

         if(ir[0]==0 && ir[1]==0 && ir[2]==0 && ir[3]==0 && ir[4]==0 && ir[5]==0)
           {
            A=1;
            B=1;
            //node=1;
            num=bin_dec(A,B,C,D);
            func(node,num);
             delay(10);
           }
     }

   //case3:three black one white
     //subcase1
      else if(ir[0]==0 && ir[1]==0 && ir[2]==0 && ir[3]==0 && ir[4]==0 && ir[5]==0)
     {forward();
      C=1;
      D=1;
      node=node+1;
      //num=bin_dec(A,B,C,D);
      //func(node,num);
      delay(10);

         if(ir[0]==0 && ir[1]==0 && ir[2]==0 && ir[3]==1 && ir[4]==1 && ir[5]==1)
           {
            A=1;
            B=0;
            //node=1;
            num=bin_dec(A,B,C,D);
            func(node,num);
             delay(10);
           }
     }

     //subcase2
     else if(ir[0]==0 && ir[1]==0 && ir[2]==0 && ir[3]==0 && ir[4]==0 && ir[5]==0)
     {forward();
      C=1;
      D=1;
      node=node+1;
      //num=bin_dec(A,B,C,D);
      //func(node,num);
      delay(10);

         if(ir[0]==1 && ir[1]==1 && ir[2]==1 && ir[3]==0 && ir[4]==0 && ir[5]==0)
           {
            A=0;
            B=1;
            //node=1;
            num=bin_dec(A,B,C,D);
            func(node,num);
             delay(10);
           }
     }

     //subcase3
     else if(ir[0]==0 && ir[1]==0 && ir[2]==0 && ir[3]==1 && ir[4]==1 && ir[5]==1)
     {forward();
      C=1;
      D=0;
      node=node+1;
      //num=bin_dec(A,B,C,D);
      //func(node,num);
      delay(10);

         if(ir[0]==0 && ir[1]==0 && ir[2]==0 && ir[3]==0 && ir[4]==0 && ir[5]==0)
           {
            A=1;
            B=1;
            //node=1;
            num=bin_dec(A,B,C,D);
            func(node,num);
             delay(10);
           }
     }

     //subcase4
     else if(ir[0]==1 && ir[1]==1 && ir[2]==1 && ir[3]==0 && ir[4]==0 && ir[5]==0)
     {forward();
      C=0;
      D=1;
      node=node+1;
      //num=bin_dec(A,B,C,D);
      //func(node,num);
      delay(10);

         if(ir[0]==0 && ir[1]==0 && ir[2]==0 && ir[3]==0 && ir[4]==0 && ir[5]==0)
           {
            A=1;
            B=1;
            //node=1;
            num=bin_dec(A,B,C,D);
            func(node,num);
             delay(10);
           }
     }

   //case4:all black
     else if(ir[0]==0 && ir[1]==0 && ir[2]==0 && ir[3]==0 && ir[4]==0 && ir[5]==0)
     {forward();
      C=1;
      D=1;
      node=node+1;
      //num=bin_dec(A,B,C,D);
      //func(node,num);
      delay(10);

         if(ir[0]==0 && ir[1]==0 && ir[2]==0 && ir[3]==0 && ir[4]==0 && ir[5]==0)
           {
            A=1;
            B=1;
            //node=1;
            num=bin_dec(A,B,C,D);
            func(node,num);
             delay(10);
           }
     }
     //nod_det=0;
   }//main if ends

   else
   {
    if(ir[5]==0 && ir[3]==1 && ir[0]==1)
    left();
    if(ir[5]==1 && ir[3]==0 && ir[0]==1)
    forward();
    if(ir[5]==1 && ir[3]==1 && ir[0]==0)
    right();
    if(ir[5]==0 && ir[3]==0 && ir[0]==0)
    forward();
    

    for(int i=0;i<6;i++)
    {
      Serial.print(ir[i]);
      Serial.print(" ");
    }
    Serial.println();
   }
}

int bin_dec(A,B,C,D)
{
  num=8*A + 4*B +2*C +D;
  return num;
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

void Stop(){
  digitalWrite(in1L, LOW);
  digitalWrite(in2L, LOW);
  digitalWrite(in2R, LOW);
  digitalWrite(in1R, LOW);
Serial.println("Stop");
}

 
