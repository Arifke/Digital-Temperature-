int LM35=A2;
int segment[10][7]={{1,1,1,1,1,1,0},
                   {0,1,1,0,0,0,0},
                   {1,1,0,1,1,0,1},
                   {1,1,1,1,0,0,1},
                   {0,1,1,0,0,1,1},
                   {1,0,1,1,0,1,1},
                   {1,0,1,1,1,1,1},
                   {1,1,1,0,0,0,0},
                   {1,1,1,1,1,1,1},
                   {1,1,1,1,0,1,1}};

void setup(){
  for(int i=2;i<16;i++){
    pinMode(i,OUTPUT); 
  }
  Serial.begin(9600);
}


void loop(){
  float value=analogRead(LM35);
  int voltage=(value/1024)*5000;
  int temp=voltage/10;

  Serial.println(temp);
  delay(200);
  int a=(temp/10);
  int b=(temp-((temp/10)*10));
  segment1(a);
  segment2(b);
  
  
}

void segment1(int a){

  for(int pin=2;pin<9;pin++){
    digitalWrite(pin,segment[a][pin-2]);
  }
}

void segment2(int b){
  for(int pin=9;pin<16;pin++){
    digitalWrite(pin,segment[b][pin-9]);
  }
}
