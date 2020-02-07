int value=0;
const byte sprayheads = 1;             // number of sprayheads
byte Spray[1];                        //an array to store spray solenoid postions
int dist = 0;
boolean newData = false;
boolean showNewDataB = false;
int rowshift = 0;
int temprowshift;

void setup() 
   { 
      Serial.begin(9600); 
      
      pinMode(4, OUTPUT);
      pinMode(5, OUTPUT);
      pinMode(6, OUTPUT);
      pinMode(7, OUTPUT);
      pinMode(8, OUTPUT);
      pinMode(9, OUTPUT);
      pinMode(10, OUTPUT);
      pinMode(11, OUTPUT);
      pinMode(12, OUTPUT);
      pinMode(13, OUTPUT);
      digitalWrite (4, HIGH);
      digitalWrite (5, HIGH);
      digitalWrite (6, HIGH);
      digitalWrite (7, HIGH);
      digitalWrite (8, HIGH);
      digitalWrite (9, HIGH);
      digitalWrite (10, HIGH);
      digitalWrite (11, LOW);
      digitalWrite (12, HIGH);
      digitalWrite (13, HIGH);
      
   }
 
void loop() {
   
      recvWithEndMarker();
      if (showNewDataB == true){
        showNewData();
      }
      if (rowshift >= 1) {
        rowshift = 0;
        digitalWrite(11, LOW);
        showNewDataB = false;
        resetspray();
        }
     
     // delay(1000);

   }

void recvWithEndMarker() {
    static byte ndx = 0;
    char endMarker = '7';
    char rc;
    
    while (Serial.available() > 0 && newData == false) {
        rc = Serial.read();

        if (rc != endMarker) {
            Spray[ndx] = rc;
            ndx++;
            if (ndx >= sprayheads) {
                ndx = sprayheads - 1;
            }
        }
        else {
            Spray[ndx] = '\0'; // terminate the string
            ndx = 0;
            newData = true;
            showNewDataB = true;
            analogWrite(11,100);
        }
    }
}


void showNewData() {

  
  
        if (Spray[0] == '1')
        digitalWrite (4, LOW);
       
     
        else if (Spray[0] == '0')
        digitalWrite (4, HIGH);
        
        
        
        
       
        if (rowshift>= 1);{
        newData = false;}
        
    }
void resetspray() {

    digitalWrite (4, HIGH);
    digitalWrite (5, HIGH);
    digitalWrite (6, HIGH);
    digitalWrite (7, HIGH);
    digitalWrite (8, HIGH);
    digitalWrite (9, HIGH);
    digitalWrite (10, HIGH);

}
