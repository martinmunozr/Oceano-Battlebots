// nombramos los pines
int motor_A1 = 14;   // pin motor A1
int motor_A2 = 12;   // pin motor A2
int pin_vel_A = 15;  // pin control de velocidad motor A

int motor_B1 = 5;    // pin motor B1
int motor_B2 = 4;    // pin motor B2
int pin_vel_B = 13;  // pin control de velocidad motor A

int SPEED_A = 150;  //velocidades
int SPEED_B = 150;
int SPEED_BOOST = 250;
int SPEED_D = 100;


void motors_setup() {
  // configuramos el motor A como salida (OUTPUT)
  pinMode(motor_A1, OUTPUT);   // motor A1
  pinMode(motor_A2, OUTPUT);   // motor A2
  pinMode(pin_vel_A, OUTPUT);  // control velocidad A

  // configuramos el motor B como salida (OUTPUT)
  pinMode(motor_B1, OUTPUT);   // motor B1
  pinMode(motor_B2, OUTPUT);   // motor B2
  pinMode(pin_vel_B, OUTPUT);  // control velocidad B

  // partimos con el motor A apagado (LOW)
  digitalWrite(motor_A1, LOW);  // motor A1
  digitalWrite(motor_A2, LOW);  // motor A2

  // partimos con el motor B apagado (LOW)
  digitalWrite(motor_B1, LOW);  // motor A1
  digitalWrite(motor_B2, LOW);  // motor A2
}

/** motor Foward Backward
 * @brief Función controla el movimiento hacia adelante o hacia atrás de los motores.
 * @param dir1 es un valor de verdad (true o false) que permite elegir una dirección
 */
void motor_FWBW(bool dir1) {

  if (dir1) {
    digitalWrite(motor_A1, LOW);
    digitalWrite(motor_A2, HIGH);
    analogWrite(pin_vel_A, SPEED_A);
    analogWrite(pin_vel_B, SPEED_B);
    digitalWrite(motor_B1, LOW);
    digitalWrite(motor_B2, HIGH);

  } else {
    digitalWrite(motor_A1, !LOW);
    digitalWrite(motor_A2, !HIGH);
    analogWrite(pin_vel_A, SPEED_A);
    analogWrite(pin_vel_B, SPEED_B);
    digitalWrite(motor_B1, !LOW);
    digitalWrite(motor_B2, !HIGH);

  }
}
/** motor Left Right 
 * @brief Función controla el giro hacia la derecha o izquierda de los motores.
 * @param dir2 es un valor de verdad (true o false) que permite elegir una dirección
 */
void motor_LR(bool dir2) {
  if (dir2) {
    digitalWrite(motor_A1, !LOW);
    digitalWrite(motor_A2, !HIGH);
    analogWrite(pin_vel_A, SPEED_A);
    analogWrite(pin_vel_B, SPEED_B);
    digitalWrite(motor_B1, LOW);
    digitalWrite(motor_B2, HIGH);

  } else {
    digitalWrite(motor_A1, LOW);
    digitalWrite(motor_A2, HIGH);
    analogWrite(pin_vel_A, SPEED_A);
    analogWrite(pin_vel_B, SPEED_B);
    digitalWrite(motor_B1, !LOW);
    digitalWrite(motor_B2, !HIGH);

  }
}

/** Motor Stop
 * @brief Función que detiene los motores
 */
void motor_stop(void) {
  digitalWrite(motor_A1, LOW);
  digitalWrite(motor_A2, LOW);
  analogWrite(pin_vel_A, 0);
  digitalWrite(motor_B1, LOW);
  digitalWrite(motor_B2, LOW);
  analogWrite(pin_vel_B, 0);
}
void motor_boost(void) {

  analogWrite(pin_vel_A, SPEED_BOOST);
  analogWrite(pin_vel_B, SPEED_BOOST);
}

void motor_deboost(void) {
  analogWrite(pin_vel_A, SPEED_A);
  analogWrite(pin_vel_B, SPEED_B);
}

/** motor AvanzarDiagonal AD
 * @brief Función controla el movimiento hacia adelante o hacia atrás de los motores.
 * @param dir4 es un valor de verdad (true o false) que permite elegir una dirección
 */
void motor_AD(bool dir4) {

  if (dir4) {
    digitalWrite(motor_A1, LOW);
    digitalWrite(motor_A2, HIGH);
    analogWrite(pin_vel_A, SPEED_D);
    digitalWrite(motor_B1, LOW);
    digitalWrite(motor_B2, HIGH);
    analogWrite(pin_vel_B, SPEED_B);
  } else {
    digitalWrite(motor_A1, LOW);
    digitalWrite(motor_A2, HIGH);
    analogWrite(pin_vel_A, SPEED_A);
    digitalWrite(motor_B1, LOW);
    digitalWrite(motor_B2, HIGH);
    analogWrite(pin_vel_B, SPEED_D);
  }
}

/** motor RetrocederDiagonal RD
 * @brief Función controla el movimiento hacia adelante o hacia atrás de los motores.
 * @param dir5 es un valor de verdad (true o false) que permite elegir una dirección
 */
void motor_RD(bool dir5) {

  if (dir5) {
    digitalWrite(motor_A1, !LOW);
    digitalWrite(motor_A2, !HIGH);
    analogWrite(pin_vel_A, SPEED_D);
    digitalWrite(motor_B1, !LOW);
    digitalWrite(motor_B2, !HIGH);
    analogWrite(pin_vel_B, SPEED_B);
  } else {
    digitalWrite(motor_A1, !LOW);
    digitalWrite(motor_A2, !HIGH);
    analogWrite(pin_vel_A, SPEED_A);
    digitalWrite(motor_B1, !LOW);
    digitalWrite(motor_B2, !HIGH);
    analogWrite(pin_vel_B, SPEED_D);
  }
}
