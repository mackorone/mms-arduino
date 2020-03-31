void setup() {
    Serial.begin(19200);
}

void loop() {
    log("Running...");
    setColor(0, 0, 'G');
    setText(0, 0, "abc");
    while (true) {
        if (!wallLeft()) {
            turnLeft();
        }
        while (wallFront()) {
            turnRight();
        }
        moveForward();
    }
}
