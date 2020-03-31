// ----- API -----

void log(String message) {
    Serial.print("log " + message + "\n");
}

int mazeWidth() {
    return getInteger("mazeWidth");
}

int mazeHeight() {
    return getInteger("mazeHeight");
}

bool wallFront() {
    return getBoolean("wallFront");
}

bool wallRight() {
    return getBoolean("wallRight");
}

bool wallLeft() {
    return getBoolean("wallLeft");
}

bool moveForward() {
    return getAck("moveForward");
}

void turnRight() {
    getAck("turnRight");
}

void turnLeft() {
    getAck("turnLeft");
}

void setWall(int x, int y, char direction) {
    Serial.print(
        "setWall "
        + String(x) + " "
        + String(y) + " "
        + String(direction) + "\n"
    );
}

void clearWall(int x, int y, char direction) {
    Serial.print(
        "clearWall "
        + String(x) + " "
        + String(y) + " "
        + String(direction) + "\n"
    );
}

void setColor(int x, int y, char color) {
    Serial.print(
        "setColor "
        + String(x) + " "
        + String(y) + " "
        + String(color) + "\n"
    );
}

void clearColor(int x, int y) {
    Serial.print(
        "clearColor "
        + String(x) + " "
        + String(y) + "\n"
    );
}

void clearAllColor() {
    Serial.print("clearAllColor\n");
}

void setText(int x, int y, String text) {
    Serial.print(
        "setText "
        + String(x) + " "
        + String(y) + " "
        + text + "\n"
    );
}

void clearText(int x, int y) {
    Serial.print(
        "clearText "
        + String(x) + " "
        + String(y) + "\n"
    );
}

void clearAllText() {
    Serial.print("clearAllText\n");
}

bool wasReset() {
    return getBoolean("wasReset");
}

void ackReset() {
    getAck("ackReset");
}

// ----- Helpers -----

String readline() {
    String response = "";
    while (response == "") {
        response = Serial.readStringUntil('\n');
    }
    return response;
}

String communicate(String command) {
    Serial.print(command + "\n");
    return readline();
}

bool getAck(String command) {
    String response = communicate(command);
    return response == "ack";
}

bool getBoolean(String command) {
    String response = communicate(command);
    return response == "true";
}

int getInteger(String command) {
    String response = communicate(command);
    return response.toInt();
}
