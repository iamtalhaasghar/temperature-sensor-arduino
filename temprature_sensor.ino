
int ThermistorPin = 5;
int Vo;
float R1 = 2252;
float logR2, R2, T;
float A = 1.484778004e-03, B = 2.348962910e-04, C = 1.006037158e-07;  // Steinhart-Hart and Hart Coefficients


void setup() {
  
Serial.begin(9600);

}

void loop() {

Vo = analogRead(ThermistorPin);
R2 = R1* (1023.0 / (float)Vo - 1.0);
logR2 = log(R2);
T = (1.0 / (A + B*logR2 + C*logR2*logR2*logR2));  // Steinhart and Hart Equation. T  = 1 / {A + B[ln(R)] + C[ln(R)]^3}
T =  T - 273.15;
Serial.print("TEMP = ");
Serial.print(T);
Serial.println(" C");

delay(400);     // Time delay 10 Milliseconds

}
