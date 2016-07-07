int greenLED = 2;
int yellowLED = 4;
int redLED = 7;
int balance = 0;
int redThreshhold = 100;
int yellowThreshhold = 200;
int displayMs = 5000;

void setup() {
  // put your setup code here, to run once:
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);  
  Serial.begin(9600);
  Serial.println("Enter your EZ Pass balance");
}

// Turn all LED's off
void allOff()
{
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  allOff();  // Turn all LED's off
  if (Serial.available()) {
    balance = Serial.parseInt(); // Convert input to integer
    Serial.print("Your balance is: ");
    Serial.println(balance);
    if (balance <= redThreshhold) {
      digitalWrite(redLED, HIGH);
      Serial.println("Please refill your account immediately!");
    }
    else if (balance <= yellowThreshhold) {
      digitalWrite(yellowLED, HIGH);
      Serial.println("Warning your account is getting low!");
    }
    else {
      digitalWrite(greenLED, HIGH);
      Serial.println("Your account is in good standing.");
    }
    
    delay (displayMs);
    Serial.println("Thank you for checking your EZ Pass account.");
    Serial.println("Enter your EZ Pass balance");
  }
  

}
